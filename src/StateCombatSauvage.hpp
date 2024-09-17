#ifndef STATECOMBATSAUVAGE_HPP  
#define STATECOMBATSAUVAGE_HPP
#include "State.hpp"

class StateCombatSauvage : public State {
public:
    void handle() override; 
    std::string getName() const override;
};
#endif