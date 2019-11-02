#include <exception>
#include <sstream>

#include "SimulatedComponent.h"

#include <iostream>

SimulatedComponent::SimulatedComponent(std::string name) {
    static int id = 0;
    std::ostringstream ss;
    ss << name << ' ' << id++;
    this->name = ss.str();
}

std::string SimulatedComponent::getName() {
    return name;
}

bool SimulatedComponent::finishedTick(int time) {
    return simulated.find(time) != simulated.end();
}

void SimulatedComponent::tick(int time) {
    auto attemptedInsert = simulated.insert(time);
    const bool newlyInserted = attemptedInsert.second;
    if (!newlyInserted) {
        std::ostringstream ss;
        ss << "timestamp " << time << " has already been visited for " << getName();
        throw std::invalid_argument(ss.str());
    }
    std::cout << "you may proceed" << std::endl;
}

