#include <iostream>
#include <vector>

#include "Item.h"
#include "Belt.h"
#include "BeltSource.h"
#include "BeltSink.h"
#include "Splitter.h"
#include "SimulatedComponent.h"

#undef SINK
// #define SINK
#define SINK
const unsigned NUM_TICKS = 1000000;

int main() {
    std::vector<SimulatedComponent*> components;

    components.push_back(new BeltSource());
    components.push_back(new Belt());
    ((Belt*)(components[1]))->setPrev((Belt*)(components[0]));
    components.push_back(new Belt());
    ((Belt*)(components[2]))->setPrev((Belt*)(components[1]));
#ifdef SINK
    components.push_back(new BeltSink());
    ((Belt*)(components[3]))->setPrev((Belt*)(components[2]));
#endif

    for (auto it : components) {
        std::cout << it->getName() << "'s prev: " << ((Belt*)it)->getPrev() << std::endl;
        std::cout << it->getName() << "'s next: " << ((Belt*)it)->getNext() << std::endl;
    }
    
    for (unsigned tick = 0; tick < NUM_TICKS; ++tick) {
        for (auto it : components) {
            //std::cout << "doing " << it->getName() << std::endl;
            if (it->finishedTick(tick)) {
                //std::cout << it->getName() << " has already been simulated; skipping..." << std::endl;
                continue;
            }
            it->tick(tick);
        }
        //std::cout << "*** end of tick " << tick << std::endl;
    }

    std::cout << components[0] << " created " << dynamic_cast<BeltSource*>(components[0])->getNumCreated() << " items" << std::endl;
#ifdef SINK
    const auto consumed = dynamic_cast<BeltSink*>(components[3])->getConsumed();
    std::cout << components[3] << " consumed counts:" << std::endl;
    for (auto &it : consumed) {
        std::cout << it.first << ": " << it.second << std::endl;
    }
#endif
    std::cout << "=========================" << std::endl << std::endl;

    for (auto it : components) delete it;
    return 0;
}

