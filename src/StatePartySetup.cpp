#include "StatePartySetup.hpp"
#include "Context"
#include "StateCombatSauvage.hpp"
#include "StateCombat.hpp"
#include <iostream>
#include "Player.hpp"

StatePartySetup::StatePartySetup() {}

void StatePartySetup::handle() {
    Player* player = this->context_->getPlayer();
    std::string userInput;
    while (true) {
        std::cout << "Current Pokemon Party:\n";
        party_->displayParty();

        std::cout << "\nPokemon in Pokeball:\n";
        for (int i = 0; i < pokeball_->getPokemonCount(); ++i) {
            pokeball_->getOnePokebyId(i)->displayInfo(); 
        }

        std::cout << "\nWould you like to add a Pokemon to your party? (yes/no): ";
        std::cin >> userInput;

        if (userInput == "no") {
            std::cout << "Exiting party setup.\n";
            break;
        } else if (userInput == "yes") {
            if (party_->getPokemonCount() >= 6) {
                std::cout << "Your party is full! Cannot add more Pokemon.\n";
                continue;
            }

            std::cout << "Please enter the name or ID of the Pokemon you want to add: ";
            std::cin >> userInput;

            Pokemon* chosenPokemon = nullptr;
            if (std::all_of(userInput.begin(), userInput.end(), ::isdigit)) {
                int id = std::stoi(userInput);
                chosenPokemon = pokeball_->getOnePokebyId(id);
            } else {
                chosenPokemon = pokeball_->getOnePokebyName(userInput);
            }

            if (chosenPokemon != nullptr) {
                if (party_->getPokemonCount() < 6) {
                    party_->addPokemonback(chosenPokemon);
                    pokeball_->removePokemonById(chosenPokemon->getId());
                    std::cout << "Pokemon " << chosenPokemon->getName() << " added to your party.\n";
                } else {
                    std::cout << "Party is full. Cannot add more Pokemon.\n";
                }
            } else {
                std::cout << "Invalid Pokemon name or ID. Please try again.\n";
            }
        } else {
            std::cout << "Invalid input. Please type 'yes' or 'no'.\n";
        }
    }

    std::cout << "Transitioning to another state...\n";
    this->context_->TransitionTo(new StateExplorationSansDanger());  // Assuming this is the next state
}

std::string StatePartySetup::getName() const {
    return "StatePartySetup";
}
