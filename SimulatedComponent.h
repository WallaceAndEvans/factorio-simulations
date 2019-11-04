#ifndef __COMPONENT_H
#define __COMPONENT_H

#include <ostream>
#include <string>
#include <unordered_set>

struct Lane {
    enum Type { LEFT, RIGHT, COUNT };
};

Lane::Type operator+=(Lane::Type& l, int r);
std::ostream& operator<<(std::ostream& out, Lane::Type lane);

const unsigned LANE_LENGTH = 4;

class SimulatedComponent {
    private:
        const std::string name;
        std::unordered_set<unsigned> simulated;

        template <typename T>
        void _log(unsigned time, T msg) const;
        std::string getUniqueName(const std::string& name);

    protected:
        SimulatedComponent(std::string name);

        void log(unsigned time, unsigned msg) const;
        void log(unsigned time, std::string msg) const;

    public:
        virtual ~SimulatedComponent();

        const std::string &getName() const;
        bool finishedTick(unsigned time);
        virtual void tick(unsigned time) = 0;
        void step(unsigned time);
};

std::ostream& operator<<(std::ostream& out, SimulatedComponent* component);

#endif

