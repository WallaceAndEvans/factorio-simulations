#ifndef __COMPONENT_H
#define __COMPONENT_H

#include <ostream>
#include <string>

struct Lane {
    enum Type { LEFT, RIGHT, COUNT };
};

Lane::Type operator+=(Lane::Type &l, int r);
std::ostream &operator<<(std::ostream &out, Lane::Type lane);

const unsigned LANE_LENGTH = 4;

class SimulatedComponent {
  private:
    const std::string name;
    unsigned simulated;

    template <typename T> void _log(unsigned time, T msg) const;
    std::string getUniqueName(const std::string &name);

  protected:
    SimulatedComponent(std::string name);

    virtual void tick(unsigned time) = 0;

  public:
    virtual ~SimulatedComponent();

    const std::string &getName() const;
    bool finishedStep(unsigned time);
    void step(unsigned time);
};

std::ostream &operator<<(std::ostream &out, SimulatedComponent *component);

#endif
