#include "StateExplorationAvecRencontres.hpp"
#include "StateCombat.hpp"
#include "Context.hpp"

void StateExplorationAvecRencontres::handle() {
    std::cout << "État d'exploration avec rencontres : Vous pouvez rencontrer des Pokémon ou des joueurs.\n";
    this->context_->TransitionTo(new StateCombat());
}