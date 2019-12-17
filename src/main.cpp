#include <iostream>
#include <vector>

#include "Belt.h"
#include "BeltSink.h"
#include "BeltSource.h"
#include "ControlFlow.h"
#include "Item.h"
#include "SimulatedComponent.h"
#include "Splitter.h"

const unsigned NUM_STEPS = 100000;

void attach(std::vector<SimulatedComponent *> &components,
            SimulatedComponent *next) {
    static_cast<Belt *>(components.back())->setNext((Belt *)next);
    components.push_back(next);
}

std::vector<unsigned> range(unsigned len = 0) {
    std::vector<unsigned> res(len);
    for (unsigned i = 0; i < len; ++i) {
        res[i] = i;
    }
    return res;
}

int main() {
    std::cout << "sizeof(size_t): " << sizeof(size_t) << std::endl;
    std::vector<SimulatedComponent *> components;

    components.push_back(new BeltSource());

    compile_for<range(100)>([&](auto i)) { attach(components, new Belt()); }

    if (SINK)
        attach(components, new BeltSink());

    for (auto it : components) {
        std::cout << it->getName() << "'s prev: " << ((Belt *)it)->getPrev()
                  << std::endl;
        std::cout << it->getName() << "'s next: " << ((Belt *)it)->getNext()
                  << std::endl;
    }

    for (unsigned t = 0; t < NUM_STEPS; ++t) {
        for (auto it : components) {
            if (!it->finishedStep(t)) {
                it->step(t);
            }
        }
    }

    const BeltSource *sourceBelt = (BeltSource *)components.front();
    std::cout << (SimulatedComponent *)sourceBelt << " created "
              << sourceBelt->getNumCreated() << " items" << std::endl;

    if (SINK) {
        const BeltSink *sink = (BeltSink *)components.back();
        const auto &consumed = sink->getConsumed();
        std::cout << (SimulatedComponent *)sink
                  << " consumed counts:" << std::endl;

        for (auto &dest : consumed) {
            const auto &destLane = dest.first;
            const auto &sources = dest.second;
            std::cout << "lane " << destLane << ": " << std::endl;
            for (auto &source : sources) {
                const auto &sourceLane = source.first;
                const auto &count = source.second;
                std::cout << "\tfrom " << sourceLane << ": " << count
                          << std::endl;
            }
        }
    }

    std::cout << "=========================" << std::endl << std::endl;

    for (auto it : components)
        delete it;
    return 0;
}
