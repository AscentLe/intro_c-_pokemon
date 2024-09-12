#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Pokeball.hpp"

class Player {
private:
    Pokeball* pokeball;

public:
    Player();
    ~Player();
    void capturePokemon(const std::string& name);
    int getCapturedPokemonCount() const;
    Pokeball* getPokeball();
};
#endif