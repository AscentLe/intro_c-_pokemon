#include "State.hpp"

class StateCombat : public State {
public:
    void handle() override; 
    std::string getName() const override;
};
