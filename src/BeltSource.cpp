#include "BeltSource.h"

#include <iostream>

BeltSource::BeltSource() : Belt(__func__), created(0) {}

void BeltSource::populateItems() {
    for (Lane::Type lane = Lane::Type(); lane < Lane::COUNT; lane += 1) {
        if (lanes[lane][LANE_LENGTH - 1] == nullptr) {
            Item *item = new Item(this, lane, LANE_LENGTH - 1);
            lanes[lane][LANE_LENGTH - 1] = item;
            created++;
        }
    }
}

void BeltSource::tick(unsigned time) {
    Belt::tick(time);
    populateItems();
}

unsigned BeltSource::getNumCreated() const { return created; }
