#include <stdio.h>
#include <stdlib.h>

/*
struct Item {
    int sourceColumn;
};

struct SimulatedComponentBase {
    void (*tick)(struct SimulatedComponentBase*);
};

struct Belt {
    //void (*tick)(struct Belt*);
    struct SimulatedComponentBase;
    struct Item left[4];
    struct Item right[4];
    struct Belt *prev;
    struct Belt *next;
};

struct Splitter {
    //void (*tick)(struct Splitter*);
    struct SimulatedComponentBase;
    struct Belt left;
    struct Belt right;
};

void tickBelt(struct Belt* this) {
    fprintf(stderr, "this: %p\n", this);
}

void tickSplitter(struct Splitter* this) {
    fprintf(stderr, "this: %p\n", this);
}

void* objects;
int size = 0;
int cap = 0;

void initObjects(int capacity) {
    objects = malloc(sizeof(void*) * capacity);
    cap = capacity;
    fprintf(stderr, "objects size: %lu\n", sizeof(void*) * capacity);
    fprintf(stderr, "objects length: %d\n", size);
    fprintf(stderr, "objects available length: %d\n", cap);
}

void pushBelt(struct Belt *prev) {
    struct Belt* fresh = malloc(sizeof(struct Belt));
    fprintf(stderr, "size of new belt: %lu\n", sizeof(struct Belt));
    fprintf(stderr, "this: %p\n", fresh);
    fresh->prev = prev;
    fprintf(stderr, "new belt prev: %p\n", fresh->prev);
    if (prev) {
        prev->next = fresh;
        fprintf(stderr, "new prev->next (this?): %p\n", prev->next);
    } else {
        fprintf(stderr, "no prev provided\n");
    }
    fresh->tick = &tickBelt;
    if (size == cap) {
        fprintf(stderr, "objects array capacity exceeded (pushBelt)");
        //fprintf(stderr, "num: %d", 1 / 0);
    }
    ((struct Belt **)objects)[size++] = fresh;
}

void pushSplitter(struct Belt *prevLeft, struct Belt *prevRight) {
    struct Splitter* fresh = malloc(sizeof(struct Splitter));
    fprintf(stderr, "size of new splitter: %lu\n", sizeof(struct Belt));
    fprintf(stderr, "this: %p\n", fresh);
    fresh->left.prev = prevLeft;
    if (prevLeft) {
        prevLeft->next = &(fresh->left);
        fprintf(stderr, "new prevLeft->next (this?): %p\n", prevLeft->next);
    } else {
        fprintf(stderr, "no prevLeft provided\n");
    }
    fresh->right.prev = prevRight;
    if (prevRight) {
        prevRight->next = &(fresh->right);
        fprintf(stderr, "new prevRight->next (this?): %p\n", prevRight->next);
    } else {
        fprintf(stderr, "no prevRight provided\n");
    }
    fresh->tick = &tickSplitter;
    if (size == cap) {
        fprintf(stderr, "objects array capacity exceeded (pushSplitter)");
        // fprintf(stderr, "num: %d", 1 / 0);
    }
    ((struct Splitter**)objects)[size++] = fresh;
}

void release() {
    for (int i = 0; i < size; i++) {
        free(((struct Belt**)objects)[i]);
    }
}
*/

int main() {
    /*
    initObjects(100);

    pushBelt(NULL);
    struct Belt *first = ((struct Belt**)objects)[0];
    pushBelt(NULL);
    struct Belt *second = ((struct Belt**)objects)[1];
    pushSplitter(first, second);
    struct Splitter *third = ((struct Splitter**)objects)[2];

    fprintf(stderr, "first: %p\n", first);
    fprintf(stderr, "first tick: %p\n", first->tick);
    fprintf(stderr, "first prev: %p\n", first->prev);
    fprintf(stderr, "first next: %p\n", first->next);
    fprintf(stderr, "second: %p\n", second);
    fprintf(stderr, "second tick: %p\n", second->tick);
    fprintf(stderr, "second prev: %p\n", second->prev);
    fprintf(stderr, "second next: %p\n", second->next);
    fprintf(stderr, "third: %p\n", third);
    fprintf(stderr, "third tick: %p\n", third->tick);
    fprintf(stderr, "third left: %p\n", &(third->left));
    fprintf(stderr, "third left prev: %p\n", third->left.prev);
    fprintf(stderr, "third left next: %p\n", third->left.next);
    fprintf(stderr, "third right: %p\n", &(third->right));
    fprintf(stderr, "third right prev: %p\n", third->right.prev);
    fprintf(stderr, "third right next: %p\n", third->right.next);

    fprintf(stderr, "size after pushes: %d\n", size);
    // assumes objects specified top-down
    for (int i = 0; i < 100000; ++i) {
        fprintf(stderr, "i: %d\n", i);
        for (int j = size - 1; j >= 0; --j) {
            fprintf(stderr, "j: %d\n", j);
            // assumes tick function pointer is first item in struct
            void (**tickFns)(void*) = objects;
            fprintf(stderr, "tickFns: %p\n", tickFns);
            fprintf(stderr, "tickFn address: %p\n", tickFns + j);
            //fprintf(stderr, "tickFn value dereferences: %p\n", *(tickFns[j]));
            //fprintf(stderr, "objects: %p\n", objects);
            //fprintf(stderr, "arg: %p\n", objects + j);
            //fprintf(stderr, "arg, dereferenced: %p\n", ((int**)objects)[j]);

            fprintf(stderr, "objects: %p\n", tickFns);
            fprintf(stderr, "arg: %p\n", tickFns + j);
            fprintf(stderr, "arg, dereferenced: %p\n", tickFns[j]);
            //fprintf(stderr, "arg, double dereferenced: %p\n", tickFns[j]);

            //(tickFns + j)(objects + j);
            (*(tickFns[j]))(tickFns[j]);
        }
    }

    release();
    free(objects);
    */
    printf("hello, world\n");
    return 0;
}

