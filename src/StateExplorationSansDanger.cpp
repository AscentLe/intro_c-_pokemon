#include "StateExplorationSansDanger.hpp"
#include "StateExplorationAvecRencontres.hpp"
#include "Context.hpp"

void StateExplorationSansDanger::handle() {
    std::cout << "État d'exploration sans danger : Vous explorez pour attraper des Pokemon.\n";
    this->context_->TransitionTo(new StateExplorationAvecRencontres());
}