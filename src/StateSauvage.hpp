#ifndef STATESAUVAGE_HPP  
#define STATESAUVAGE_HPP
#include "State.hpp"
class StateSauvage : public State {
public:
    void handle() override; 
    std::string getName() const override;
};
#endif