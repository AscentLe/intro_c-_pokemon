#include "Context.hpp"

Context::Context(State *state, Player *player) : state_(nullptr), player_(player){
    this->TransitionTo(state);
}

Context::~Context(){
    delete state_;
}

void Context::TransitionTo(State *state){
    //std::cout << "Context: Transition to " << state->getName() << "\n";
    if (this->state_ != nullptr){
        delete this->state_;
    }
    this->state_=state;
    this->state_->set_context(this);
}

void Context::Request(){
    this->state_->handle();
}

Player* Context::getPlayer() const {
    return player_;
}