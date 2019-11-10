#include "BeltSink.h"

#include <iostream>

BeltSink::BeltSink(): Belt(__func__), consumed{} {}

BeltSink::~BeltSink() {}

void BeltSink::tick(unsigned time) {
    for (Lane::Type lane = Lane::Type(); lane < Lane::COUNT; lane += 1) {
        Item* &item = lanes[lane][0];
        if (item != nullptr) {
            consumed[lane][item->getSource()]++;
            delete item;
            item = nullptr;
        }
    }
    return;
    time = time;
}

const BeltSink::consumed_t &BeltSink::getConsumed() const {
    return consumed;
}

