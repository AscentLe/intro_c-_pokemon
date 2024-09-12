#include "State.hpp"
class Context {
private:
    State *state_;
public:
    Context(State *state);
    ~Context();

    void TransitionTo(State *state);
    void Request();
};