#include <iostream>

#include "Belt.h"

Belt::Belt(): SimulatedComponent(__func__) {}

void Belt::tick(int time) {
    SimulatedComponent::tick(time);
    std::cout << '[' << time  << "] hi from belt" << std::endl;
}

