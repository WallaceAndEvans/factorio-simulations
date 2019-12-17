#include <ostream>

#include "Item.h"

#include "hexdump.h"
#include <iostream>

Item::Item(SimulatedComponent *host, Lane::Type lane, unsigned pos) {
    move(host, lane, pos);
}

unsigned Item::getNumTicks() const { return history.size(); }

const Item::HistoryEntry &Item::getCurrentLocation() const {
    return history.back();
}

const Item::HistoryEntry &Item::getSource() const { return history.front(); }

void Item::noop() { history.back().times++; }

void Item::move(SimulatedComponent *host, Lane::Type lane, unsigned pos) {
    history.push_back({host, lane, pos, 1});
}

// assumes same lane
void Item::walk(SimulatedComponent *host, unsigned pos) {
    const HistoryEntry &last = history.back();
    move(host, last.lane, pos);
}

// assumes same host, same lane, and incremented position
void Item::walk() {
    const HistoryEntry &last = history.back();
    move(last.host, last.lane, last.pos + 1);
}

bool Item::HistoryEntry::operator==(const HistoryEntry &other) const {
    return other.host == host && other.lane == lane && other.pos == pos;
}

// hash function
size_t Item::HistoryEntry::operator()(const HistoryEntry &entry) const {
    return (((size_t)entry.host << 16) | ((entry.lane & 0xFF) << 8) |
            (entry.pos & 0xFF)) &
           ~(size_t)0;
}

std::ostream &operator<<(std::ostream &out, const Item::HistoryEntry &entry) {
    out << '"' << entry.host << "\"[" << entry.lane << "][" << entry.pos << ']';
    return out;
}

std::ostream &operator<<(std::ostream &out, const Item *item) {
    if (item == nullptr) {
        out << "INVALID ITEM";
    } else {
        out << "Item located at " << item->getCurrentLocation();
    }
    return out;
}
