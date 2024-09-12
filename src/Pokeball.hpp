#ifndef Pokeball_HPP  
#define Pokeball_HPP
#include "SetOfPokemon.hpp"
#include "Pokedex.hpp"
#include <iostream>
class Pokeball : public SetOfPokemon {
private:
public:
    Pokeball();
    Pokemon* getOnePokebyName(string name) override;
    Pokemon* getOnePokebyId(int id) override;
    void addPokemonbyName(string name);
    void addPokemonbyId(int it);
    bool removePokemonByName(const std::string& name);
    bool removePokemonById(int id);
    void addPokemonback(Pokemon* pokemon); //method to add back from pokemonparty
    ~Pokeball();
};
#endif