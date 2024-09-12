#ifndef POKEMONPARTY_HPP  
#define POKEMONPARTY_HPP
#include "SetOfPokemon.hpp"
#include "Pokeball.hpp"
#include <iostream>
class PokemonParty : public SetOfPokemon{
private:
    static const int MAX_PARTY_SIZE = 6; 
    std::vector<Pokemon*> party; 
    Pokeball* linkedPokeball; 

public:
    PokemonParty(const std::vector<std::string>& names, Pokeball* pokeball);

    PokemonParty(const std::vector<int>& ids, Pokeball* pokeball);
    
    ~PokemonParty(); 

    void displayParty() const;

    Pokemon* getOnePokebyName(string name) override;
    
    Pokemon* getOnePokebyId(int id) override;

    void disband();
};
#endif

