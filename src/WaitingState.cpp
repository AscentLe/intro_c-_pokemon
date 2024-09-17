#include "WaitingState.hpp"
#include <cctype>
#include <algorithm>
#include "StateExplorationSansDanger.hpp"
#include "Context.hpp"
#include "Pokedex.hpp"
void WaitingState::handle(){
    Player *player = this->context_->getPlayer();
    std::string userInput;
    Pokedex* pokedex = Pokedex::getInstance("../resources/pokedex.csv");
    Pokemon* chosenPokemon = nullptr;
    while (chosenPokemon == nullptr) {
    std::cout << "Please choose a starter Pokemon. Type their name or id to choose (case sensitive): ";
    std::cout << "1. Bulbasaur\n";
    std::cout << "4. Charmander\n";
    std::cout << "7. Squirtle\n";
    std::cin >> userInput;
    if (std::all_of(userInput.begin(), userInput.end(), ::isdigit)) {
        try {
            int id = std::stoi(userInput);
            if (id == 1 || id == 4 || id == 7) {
                chosenPokemon = pokedex->getOnePokebyId(id);
            } else {
                std::cout << "Invalid ID. Please choose one of the specified Pokemon IDs.\n";
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Invalid ID format. Please enter a valid number.\n";
        }
        } 
    else {
        chosenPokemon = pokedex->getOnePokebyName(userInput);
        if (chosenPokemon) {
            if (chosenPokemon->getName() != "Bulbasaur" && chosenPokemon->getName() != "Charmander" && chosenPokemon->getName() != "Squirtle") {
                    std::cout << "Invalid Pokemon name. Please choose one of the specified Pokemon names.\n";
                    chosenPokemon = nullptr;
                }
            } else {
                std::cout << "Invalid Pokemon name. Please choose one of the specified Pokemon names.\n";
            }
    }
    }
    player->captureStarterPokemon(chosenPokemon);
    std::cout << "You have chosen " << chosenPokemon->getName() << " as your starter Pokemon!" << std::endl;
    std::cout << "Transitioning to Exploration State." << std::endl;
    this->context_->TransitionTo(new StateExplorationSansDanger());
}
std::string WaitingState::getName() const{
    return "WaitingState";
}
