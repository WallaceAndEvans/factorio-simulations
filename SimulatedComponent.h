#ifndef __COMPONENT_H
#define __COMPONENT_H

#include <string>
#include <unordered_set>

class SimulatedComponent {
    private:
        std::string name;
        std::unordered_set<int> simulated;

    protected:
        SimulatedComponent(std::string name);

    public:
        std::string getName();
        bool finishedTick(int time);
        virtual void tick(int time);
};

#endif

