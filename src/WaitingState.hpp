#ifndef WAITINGSTATE_HPP  
#define WAITINGSTATE_HPP
#include "State.hpp"

class WaitingState : public State {
public:
    void handle() override;
    std::string getName() const override;
};
#endif