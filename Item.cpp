#include <ostream>

#include "Item.h"

#include <iostream>

Item::Item(SimulatedComponent* host, Lane::Type lane, unsigned pos) {

    move(host, lane, pos);
}

unsigned Item::getNumTicks() const {
    return history.size();
}

const Item::HistoryEntry &Item::getCurrentLocation() const {
    return history.back();
}

SimulatedComponent *Item::getSource() const {
    return history.at(0).host;
}

void Item::noop() {
    history.push_back(history.back());
}

void Item::move(SimulatedComponent *host, Lane::Type lane, unsigned pos) {
    /*
    if (history.size() == 0) {
        std::cout << "init -> " << HistoryEntry{host,lane,pos} << std::endl;
    } else {
        std::cout << history.back() << " -> " << HistoryEntry{host,lane,pos} << std::endl;
    }
    // */
    history.push_back({host, lane, pos});
}

// assumes same lane
void Item::walk(SimulatedComponent *host, unsigned pos) {
    const HistoryEntry& last = history.back();
    move(host, last.lane, pos);
}

// assumes same host, same lane, and incremented position
void Item::walk() {
    const HistoryEntry& last = history.back();
    move(last.host, last.lane, last.pos + 1);
}

std::ostream& operator<<(std::ostream& out, const Item::HistoryEntry &entry) {
    //out << '(' << entry.host << ", " << entry.lane << ", " << entry.pos << ')';
    out << '"' << entry.host << "\"[" << entry.lane << "][" << entry.pos << ']';
    return out;
}

std::ostream& operator<<(std::ostream& out, const Item* item) {
    if (item == nullptr) {
        out << "INVALID ITEM";
    } else {
        out << "Item located at " << item->getCurrentLocation();
    }
    return out;
}

