#include "StateExplorationSansDanger.hpp"
#include "StateExplorationAvecRencontres.hpp"
#include "StateSauvage.hpp"
#include "Context.hpp"
#include "Player.hpp"

void StateExplorationSansDanger::handle() {
    std::string userInput;
    std::cout << "You are exploring without danger. You can battle and capture wild Pokemon. Once you have 6 captured Pokemon, you will have a chance to encounter other trainers. \n";
    std::cout << "Type any key to continue: ";
    std::cin >> userInput;
    Player *player = this->context_->getPlayer();
    int PokemonCount = player->getCapturedPokemonCount();
    if (PokemonCount>=6){   
        this->context_->TransitionTo(new StateExplorationAvecRencontres());
    }
    else {
        this->context_->TransitionTo(new StateSauvage());
    }
}

std::string StateExplorationSansDanger::getName() const{
    return "Exploration sans danger";
}
