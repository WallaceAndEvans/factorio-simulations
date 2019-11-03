#include "BeltSource.h"

std::vector<Item*> BeltSource::ledger;

BeltSource::BeltSource() : Belt(__func__) {}

BeltSource::~BeltSource() {
    for (auto it : ledger) delete it;
}

void BeltSource::tick(unsigned time) {
    Belt::tick(time);
    for (Lane::Type lane = Lane::Type(); lane < Lane::COUNT; lane += 1) {
        if (lanes[lane][LANE_LENGTH-1] == NULL) {
            Item* item = new Item();
            lanes[lane][LANE_LENGTH-1] = item;
            ledger.push_back(item);
        }
    }
}

