#include "Player.hpp"
#include "cstdlib"
#include "ctime"
#include "Pokedex.hpp"
Player::Player() : pokeball(new Pokeball()), party(new PokemonParty({}, pokeball)) {}

Player::~Player() {
    delete pokeball;
    delete party;
}

void Player::capturePokemon(const std::string& name) {
    Pokemon* pokemon = Pokedex::getInstance("../resources/pokedex.csv")->getOnePokebyName(name);
    if (pokemon != nullptr) {
        std::srand(std::time(nullptr));
        int randomValue = std::rand() % 100;
        if (randomValue < 80) {
            pokeball->addPokemonback(pokemon);
            std::cout << "Captured " << name << " successfully!" << std::endl;
        } else {

            std::cout << "Failed to capture " << name << "." << std::endl;
        }
    } else {
        std::cout << "Pokemon " << name << " not found." << std::endl;
    }
}

void Player::captureStarterPokemon(Pokemon *pokemon){
    Pokemon* pokemonadded=pokemon;
    pokeball->addPokemonback(pokemon);
}

int Player::getCapturedPokemonCount() const {
    return pokeball->getPokemonCount();
}

void Player::addPokemonToParty(const std::string& name) {
    if (party->getPokemonCount() >= 6) {
        std::cout << "Party is full! Cannot add more Pokémon." << std::endl;
        return;
    }
    Pokemon* pokemon = pokeball->getOnePokebyName(name);
    if (pokemon != nullptr) {
        party->addPokemonback(pokemon);
        pokeball->removePokemonByName(name);
        std::cout << "Added " << name << " to your party." << std::endl;
    } else {
        std::cout << "Pokemon " << name << " not found in Pokeball." << std::endl;
    }
}

Pokeball* Player::getPokeball() {
    return pokeball; 
}

PokemonParty* Player::getParty() const {
    return party;
}