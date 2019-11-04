#include <exception>
#include <sstream>

#include "SimulatedComponent.h"

#include <iostream>

Lane::Type operator+=(Lane::Type& l, int r) {
    int newLane = static_cast<int>(l) + r;
    if (newLane < 0 || newLane > Lane::COUNT) {
        std::ostringstream ss;
        ss << "lane " << newLane << " is out of range [0," << Lane::COUNT << ']';
        throw std::out_of_range(ss.str());
    }
    l = static_cast<Lane::Type>(newLane);
    return l;
}

std::ostream& operator<<(std::ostream& out, Lane::Type lane) {
    switch(lane) {
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

std::string SimulatedComponent::getUniqueName(const std::string& name) {
    static unsigned id = 0;
    std::ostringstream ss;
    ss << name << ' ' << id++;
    const std::string uniqueName = ss.str();
    std::cout << "just made a " << uniqueName << std::endl;
    return uniqueName;
}

SimulatedComponent::SimulatedComponent(std::string name): name(getUniqueName(name)) {}

SimulatedComponent::~SimulatedComponent() {}

const std::string &SimulatedComponent::getName() const {
    return name;
}

template <typename T>
void SimulatedComponent::_log(unsigned time, T msg) const {
    std::cout << '[' << time  << " - " << getName() << "] " << msg << std::endl;
}

void SimulatedComponent::log(unsigned time, unsigned msg) const { _log(time, msg); }
void SimulatedComponent::log(unsigned time, std::string msg) const { _log(time, msg); }

bool SimulatedComponent::finishedTick(unsigned time) {
    return simulated.find(time) != simulated.end();
}

void SimulatedComponent::step(unsigned time) {
    auto res = simulated.insert(time);
    const bool newlyInserted = res.second;
    if (!newlyInserted) {
        log(time, "duplicate tick time!!");
        std::ostringstream ss;
        ss << "timestamp " << time << " has already been visited for " << getName();
        throw std::invalid_argument(ss.str());
    }
    tick(time);
}

std::ostream& operator<<(std::ostream& out, SimulatedComponent* component) {
    if (component) {
        out << component->getName();
    } else {
        out << "INVALID COMPONENT";
    }
    return out;
}

