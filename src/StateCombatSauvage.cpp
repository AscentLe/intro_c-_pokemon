#include "StateCombatSauvage.hpp"
#include "StateExplorationSansDanger.hpp"
#include "StateExplorationAvecRencontres.hpp"
#include "Context.hpp"

void StateCombatSauvage::handle(){
    std::cout << "Combat avec Pokemon sauvage" << std::endl;
    this->context_->TransitionTo(new StateExplorationSansDanger());
}

std::string StateCombatSauvage::getName() const{
    return "Combat avec Pokemon sauvege";
}
