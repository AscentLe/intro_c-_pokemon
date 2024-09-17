#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Pokeball.hpp"
#include "PokemonParty.hpp"
class Player {
private:
    Pokeball* pokeball;
    PokemonParty* party;
public:
    Player();
    ~Player();
    void capturePokemon(const std::string& name);
    void captureStarterPokemon(Pokemon * pokemon);
    int getCapturedPokemonCount() const;
    void addPokemonToParty(const std::string& name);
    Pokeball* getPokeball();
    PokemonParty* getParty() const;
};
#endif