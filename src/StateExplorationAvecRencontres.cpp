#include "StateExplorationAvecRencontres.hpp"
#include "StateCombat.hpp"
#include "Context.hpp"

void StateExplorationAvecRencontres::handle() {
    std::cout << "État d'exploration avec rencontres : Vous pouvez rencontrer des Pokémon ou des houeurs.\n";
    this->context_->TransitionTo(new StateCombat());
}

std::string StateExplorationAvecRencontres::getName() const
{
    return "Explorations avec rencontres";
}
