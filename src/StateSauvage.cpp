#include "StateSauvage.hpp"
#include "Context.hpp"
#include "StateExplorationSansDanger.hpp"
#include "StateExplorationAvecRencontres.hpp"
#include "StatePartySetup.hpp"
#include <ctime>
#include "Pokedex.hpp"
#include "Player.hpp"
void StateSauvage::handle(){
    std::srand(std::time(nullptr)); 
    Pokedex* pokedex = Pokedex::getInstance("../resources/pokedex.csv");
    Player *player = this->context_->getPlayer();
    int PokemonCount = player->getCapturedPokemonCount();
    int randomIndex = std::rand() % pokedex->getPokemonCount();
    Pokemon* wildPokemon = pokedex->getOnePokebyId(randomIndex);
    std::cout << "A wild " << wildPokemon->getName() << " appears!" << std::endl;
    while (true){
    std::string choice;
    std::cout << "Do you want to fight (f) or flee (r)? ";
    std::cin >> choice;
    if (choice == "r" || choice == "R") {
        std::cout << "You ran away safely!\n";
    
        if (PokemonCount>=6){   
            this->context_->TransitionTo(new StateExplorationAvecRencontres());
            break;
        }
            this->context_->TransitionTo(new StateExplorationSansDanger()); 
            break;
    } else if (choice == "f" || choice == "F") {
        std::cout << "You chose to fight the wild " << wildPokemon->getName() << "!\n";
        this->context_->TransitionTo(new StatePartySetup(player->getPokeball));
        break;
    } 
    }
}

std::string StateSauvage::getName() const{
    return "Rencontre avec Pokemon sauvage";
}
