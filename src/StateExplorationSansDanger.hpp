#include "State.hpp"

class StateExplorationSansDanger : public State {
public:
    void handle() override; 
    std::string getName() const override;
};