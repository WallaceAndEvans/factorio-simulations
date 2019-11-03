#include <climits>
#include <iostream>

#include "Belt.h"

//#include "hexdump.h"

Belt::Belt(): Belt(__func__) {}
Belt::Belt(std::string className): SimulatedComponent(className), prev(nullptr), next(nullptr), lanes{} {
    //dump(lanes);
    //dump(lanes[0]);
    //dump(lanes[Lane::LEFT]);
    //dump(lanes[0][0]);
    //dump(lanes[Lane::LEFT][0]);
    //std::cout << "typename(lanes): " << typeid(lanes).name() << std::endl;
    //std::cout << "typename(lanes[0]): " << typeid(lanes[0]).name() << std::endl;
    //std::cout << "typename(lanes[0][0]): " << typeid(lanes[0][0]).name() << std::endl;
    //std::cout << "lanes: " << lanes[Lane::LEFT][0]
}

bool Belt::willPushItem() const {
    for (unsigned l = Lane::LEFT; l < Lane::COUNT; ++l) {
        if (lanes[l][LANE_LENGTH-1] != nullptr) return true;
    }
    return false;
}

void Belt::push(Item* &src, Item* &dest, Belt* other) {
    if (src == nullptr) return;
    if (dest != nullptr) {
        src->noop();
        return;
    }
    dest = src;
    src = nullptr;
    if (other) {
        dest->walk(other, 0);
    } else {
        src->walk(this);
    }
}

void Belt::pushEndOfLane(Lane::Type lane) {
    if (!next) return;
    push(this->lanes[lane][LANE_LENGTH-1], next->lanes[lane][0], next);
}

void Belt::tick(unsigned time) {
    SimulatedComponent::tick(time);
    if (willPushItem()) {
        // can potentially throw if the component graph is cyclical
        // so we will assume the graph is acyclical for now
        if (next) next->tick(time);
    }
    for (Lane::Type lane = Lane::Type(); lane < Lane::COUNT; lane += 1) {
        pushEndOfLane(lane);
        for (unsigned pos = LANE_LENGTH - 2; pos != UINT_MAX; --pos) {
            std::cout << "lane: " << lane << "; pos: " << pos << std::endl;
            push(lanes[lane][pos], lanes[lane][pos+1]);
        }
    }
}












