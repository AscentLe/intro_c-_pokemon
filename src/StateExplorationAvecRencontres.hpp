#ifndef STATEEXPLORATIONAVECRENCONTRES_HPP  
#define STATEEXPLORATIONAVECRENCONTRES_HPP
#include "State.hpp"

class StateExplorationAvecRencontres : public State {
public:
    void handle() override;  
    std::string getName() const override;
};
#endif
