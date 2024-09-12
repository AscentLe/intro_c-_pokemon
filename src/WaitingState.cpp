#include "WaitingState.hpp"
#include "StateExplorationSansDanger.hpp"
#include "Context.hpp"
void WaitingState::handle(){
    std::cout << "État d'attente. Appuyez sur une touche pour commencer...\n";
    this->context_->TransitionTo(new StateExplorationSansDanger());
}