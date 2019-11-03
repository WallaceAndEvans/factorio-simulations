#include "Item.h"

//Item::Item() {}

//int Item::getSource() const {
    //return this->source;
//}

void Item::noop() {
    history.push_back(history.back());
}

void Item::move(SimulatedComponent *container, Lane::Type lane, unsigned pos) {
    history.push_back({container, lane, pos});
}

// assumes same lane
void Item::walk(SimulatedComponent *container, unsigned pos) {
    const HistoryEntry& last = history.back();
    move(container, last.lane, pos);
}

// assumes same lane and incremented position
void Item::walk(SimulatedComponent *container) {
    const HistoryEntry& last = history.back();
    move(container, last.lane, last.pos + 1);
}

