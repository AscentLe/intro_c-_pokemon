#include "Player.hpp"
#include "cstdlib"
#include "ctime"
#include "Pokedex.hpp"
Player::Player() : pokeball(new Pokeball()) {}

Player::~Player() {
    delete pokeball;
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

int Player::getCapturedPokemonCount() const {
}

Pokeball* Player::getPokeball() {
    return pokeball; 
}