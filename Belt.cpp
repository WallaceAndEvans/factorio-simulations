#include <climits>
#include <iostream>

#include "Belt.h"

Belt::Belt(): Belt(__func__) {}
Belt::Belt(std::string className): SimulatedComponent(className), prev(nullptr), next(nullptr), lanes{} {}

Belt::~Belt() {
    for (Lane::Type lane = Lane::Type(); lane < Lane::COUNT; lane += 1) {
        for (unsigned pos = 0; pos < LANE_LENGTH; ++pos) {
            if (lanes[lane][pos] != nullptr) {
                delete lanes[lane][pos];
                lanes[lane][pos] = nullptr;
            }
        }
    }
}

bool Belt::willPushItem() const {
    for (unsigned l = Lane::LEFT; l < Lane::COUNT; ++l) {
        if (lanes[l][LANE_LENGTH-1] != nullptr) return true;
    }
    return false;
}

void Belt::push(Item* &src, Item* &dest, Belt *other) {
    if (src == nullptr) return;
    if (dest != nullptr) {
        src->noop();
        return;
    }
    dest = src;
    src = nullptr;
    if (other != nullptr) {
        // moved between belts
        dest->walk(other, 0);
    } else {
        dest->walk();
    }
}

void Belt::pushEndOfLane(Lane::Type lane) {
    if (!next) return;
    push(this->lanes[lane][LANE_LENGTH-1], next->lanes[lane][0], next);
}

void Belt::tick(unsigned time) {
    if (willPushItem()) {
        // can potentially throw if the component graph is cyclical
        // so we will assume the graph is acyclical for now
        if (next) next->step(time);
    }
    for (Lane::Type lane = Lane::Type(); lane < Lane::COUNT; lane += 1) {
        pushEndOfLane(lane);
        for (unsigned pos = LANE_LENGTH - 2; pos != UINT_MAX; --pos) {
            push(lanes[lane][pos], lanes[lane][pos+1]);
        }
    }
}

void Belt::setNext(Belt *next) {
    this->next = next;
    if (next == nullptr) return;
    next->prev = this;
}

void Belt::setPrev(Belt *prev) {
    this->prev = prev;
    if (prev == nullptr) return;
    prev->next = this;
}

Belt *Belt::getNext() const {
    return next;
}

Belt *Belt::getPrev() const {
    return prev;
}

