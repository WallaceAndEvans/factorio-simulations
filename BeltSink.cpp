#include "BeltSink.h"

BeltSink::BeltSink(): Belt(__func__), collected{} {};

void BeltSink::tick(unsigned time) {
    Belt::tick(time);
    for (Lane::Type lane = Lane::Type(); lane < Lane::COUNT; lane += 1) {
        if (lanes[lane][0]) {
            collected[lane]++;
            lanes[lane][0] = NULL;
        }
    }
}



