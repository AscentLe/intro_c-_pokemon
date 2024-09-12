#include "StateCombat.hpp"
#include "StateExplorationAvecRencontres.hpp"
#include "Context.hpp"

void StateCombat::handle() {
    std::cout << "État de combat : Vous êtes en combat !\n";
    this->context_->TransitionTo(new StateExplorationAvecRencontres());
}
std::string StateCombat::getName() const{
    return "Combat";
}
