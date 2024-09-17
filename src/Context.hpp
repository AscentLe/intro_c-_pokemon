#include "State.hpp"
#include "Player.hpp"
class Context {
private:
    State *state_;
    Player *player_;
public:
    Context(State *state, Player *player);
    ~Context();

    void TransitionTo(State *state);
    void Request();
    Player* getPlayer() const;
};