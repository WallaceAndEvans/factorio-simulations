#include "BeltSink.h"

#include <iostream>

BeltSink::BeltSink(): Belt(__func__), consumed{} {}

BeltSink::~BeltSink() {}

void BeltSink::tick(unsigned time) {
    for (Lane::Type lane = Lane::Type(); lane < Lane::COUNT; lane += 1) {
        //std::cout << getName() << " [" << lane << "][0]: " << lanes[lane][0] << std::endl;
        //std::cout << getName() << " [" << lane << "][1]: " << lanes[lane][1] << std::endl;
        //std::cout << getName() << " [" << lane << "][2]: " << lanes[lane][2] << std::endl;
        //std::cout << getName() << " [" << lane << "][3]: " << lanes[lane][3] << std::endl;
        if (lanes[lane][0] != nullptr) {
            if (consumed.find(lane) == consumed.end()) {
                consumed[lane] = 1;
            } else {
                consumed[lane]++;
            }
            //auto res = consumed.emplace(lane, 0);
            //res.first->second++;
            //std::cout << "res.first->first: " << res.first->first << std::endl;
            //std::cout << "res.first->second: " << res.first->second << std::endl;
            //std::cout << "erasing " << lanes[lane][0] << std::endl;
            lanes[lane][0] = nullptr;
        }
    }
    return;
    time = time;
}

const BeltSink::consumed_t &BeltSink::getConsumed() const {
    return consumed;
}

