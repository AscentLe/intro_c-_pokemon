#ifndef STATEEXPLORATIONSANSDANGER_HPP  
#define STATEEXPLORATIONSANSDANGER_HPP
#include "State.hpp"

class StateExplorationSansDanger : public State {
public:
    void handle() override; 
    std::string getName() const override;
};
#endif