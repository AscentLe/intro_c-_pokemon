#ifndef STATECOMBAT_HPP  
#define STATECOMBAT_HPP
#include "State.hpp"

class StateCombat : public State {
public:
    void handle() override; 
    std::string getName() const override;
};
#endif