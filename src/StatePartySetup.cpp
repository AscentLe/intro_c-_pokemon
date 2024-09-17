#include "StatePartySetup.hpp"
#include "Context.hpp"
#include "StateCombatSauvage.hpp"
#include "StateCombat.hpp"
#include <iostream>
#include "Player.hpp"

StatePartySetup::StatePartySetup() {}

void StatePartySetup::handle() {
    Player* player = this->context_->getPlayer();
    std::string choice;
    std::cout << "Do you want to add or remove Pokémon from your party? (Enter 'add', 'remove' or 'no'):" << std::endl;
    std::cin >> choice;
    if (choice == "add") {
        addPokemons(player);
    } else if (choice == "remove") {
        removePokemons(player);
    } else if (choice == "no") {
        this->context_->TransitionTo(new StateCombatSauvage());
    } else {
        std::cout << "Invalid choice. Please restart the process." << std::endl;
    }

    this->context_->TransitionTo(new StateCombatSauvage()); 
}

void StatePartySetup::addPokemons(Player* player) {
    std::string userInput;
    while (true) {
        std::cout << "Enter the name of the Pokémon you want to add to your party:" << std::endl;
        std::cout << "Type 'exit' to go back." << std::endl;
        std::cin >> userInput;
        if (userInput == "exit") {
            break;
        }
        Pokemon* pokemon = nullptr;
        pokemon = player->getPokeball()->getOnePokebyName(userInput);
        if (pokemon) {
            player->addPokemonToParty(userInput);
            std::cout << "Added " << userInput << " to your party." << std::endl;
            continue;
        }
        std::cout << "Invalid input or Pokémon not found in your Pokéball. Please try again." << std::endl;
    }
}

void StatePartySetup::removePokemons(Player* player) {
    std::string userInput;

    while (true) {
        std::cout << "Enter the name of the Pokémon you want to remove from your party:" << std::endl;
        std::cout << "Type 'exit' to go back." << std::endl;
        std::cin >> userInput;

        if (userInput == "exit") {
            break;
        }
        bool removed = player->removePokemonFromParty(userInput);
        if (removed) {
            std::cout << "Removed " << userInput << " from your party and added it back to your Pokéball." << std::endl;
        } else {
            std::cout << "Pokémon with name " << userInput << " not found in your party. Please try again." << std::endl;
        }
    }
}

std::string StatePartySetup::getName() const {
    return "StatePartySetup";
}
