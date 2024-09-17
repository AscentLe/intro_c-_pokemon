#include "StateCombatSauvage.hpp"
#include "StateExplorationSansDanger.hpp"
#include "StateExplorationAvecRencontres.hpp"
#include "Context.hpp"

void StateCombatSauvage::handle()
{
}

std::string StateCombatSauvage::getName() const{
    return "Combat avec Pokemon sauvege";
}
