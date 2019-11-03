#include <iostream>

#include "Item.h"
#include "Belt.h"
#include "BeltSource.h"
#include "BeltSink.h"
#include "Splitter.h"
#include "SimulatedComponent.h"

int main() {
    const int tick = 39;
    BeltSource bsrc = BeltSource();
    BeltSink bsink = BeltSink();
    Belt b0 = Belt();
    Belt b1 = Belt();
    b1.tick(tick);
    std::cout << "Belt b0 finished tick " << tick << "?: " << b0.finishedTick(tick) << std::endl;
    std::cout << "Belt b1 finished tick " << tick << "?: " << b1.finishedTick(tick) << std::endl;

    SimulatedComponent *c0 = &b0;
    SimulatedComponent *c1 = &b1;
    std::cout << "SimulatedComponent c0 finished tick " << tick << "?: " << c0->finishedTick(tick) << std::endl;
    std::cout << "SimulatedComponent c0 tick:" << std::endl;
    c0->tick(tick);
    std::cout << "SimulatedComponent c1 finished tick " << tick << "?: " << c1->finishedTick(tick) << std::endl;
    std::cout << "SimulatedComponent c1 tick:" << std::endl;
    c1->tick(tick);
    for (unsigned tick = 0; tick < 10; ++tick) {

    }
    return 0;
}

