#include "BeltSource.h"

#include <iostream>

unsigned BeltSource::referenceCount = 0;
std::vector<Item*> BeltSource::ledger;

BeltSource::BeltSource() : Belt(__func__), created(0) {
    std::cout << "referenceCount (constructor): " << referenceCount << " -> " << referenceCount + 1 << std::endl;
    populateItems();
    referenceCount++;
}

BeltSource::~BeltSource() {
    std::cout << "referenceCount (destructor): " << referenceCount << " -> " << referenceCount - 1 << std::endl;
    if (--referenceCount == 0) {
        std::cout << "(deleting)" << std::endl;
        for (auto it : ledger) delete it;
        ledger.clear();
    }
}

void BeltSource::populateItems() {
    for (Lane::Type lane = Lane::Type(); lane < Lane::COUNT; lane += 1) {
        if (lanes[lane][LANE_LENGTH-1] == nullptr) {
            Item* item = new Item(this, lane, LANE_LENGTH-1);
            lanes[lane][LANE_LENGTH-1] = item;
            ledger.push_back(item);
            created++;
        }
    }
}

void BeltSource::tick(unsigned time) {
    Belt::tick(time);
    populateItems();
}

unsigned BeltSource::getNumCreated() const {
    return created;
}

