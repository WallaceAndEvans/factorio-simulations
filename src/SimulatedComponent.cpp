#include <climits>
#include <exception>
#include <sstream>

#include "SimulatedComponent.h"

#include <iostream>

Lane::Type operator+=(Lane::Type &l, int r) {
    int newLane = static_cast<int>(l) + r;
    if (newLane < 0 || newLane > Lane::COUNT) {
        std::ostringstream ss;
        ss << "lane " << newLane << " is out of range [0,"
           << static_cast<int>(Lane::COUNT) << ']';
        throw std::out_of_range(ss.str());
    }
    l = static_cast<Lane::Type>(newLane);
    return l;
}

std::ostream &operator<<(std::ostream &out, Lane::Type lane) {
    switch (lane) {
    case Lane::LEFT:
        out << "Left";
        break;
    case Lane::RIGHT:
        out << "Right";
        break;
    default:
        out << "INVALID LANE";
    }
    return out;
}

std::string SimulatedComponent::getUniqueName(const std::string &name) {
    static unsigned id = 0;
    std::ostringstream ss;
    ss << name << ' ' << id++;
    return ss.str();
}

SimulatedComponent::SimulatedComponent(std::string name)
    : name(getUniqueName(name)), simulated(UINT_MAX) {}

SimulatedComponent::~SimulatedComponent() {}

const std::string &SimulatedComponent::getName() const { return name; }

bool SimulatedComponent::finishedStep(unsigned time) {
    if (simulated == UINT_MAX)
        return false;
    return simulated >= time;
}

void SimulatedComponent::step(unsigned time) {
    if (finishedStep(time)) {
        std::ostringstream ss;
        ss << "timestep " << time << " has already been visited for "
           << getName();
        throw std::invalid_argument(ss.str());
    }
    simulated = time;
    tick(time);
}

std::ostream &operator<<(std::ostream &out, SimulatedComponent *component) {
    if (component) {
        out << component->getName();
    } else {
        out << "INVALID COMPONENT";
    }
    return out;
}
