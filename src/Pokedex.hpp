#ifndef Pokedex_HPP  
#define Pokedex_HPP
#include <iostream>
#include <fstream>  
#include <sstream> 
#include "SetOfPokemon.hpp"
class Pokedex : public SetOfPokemon {
private:
    static Pokedex* instance;
    Pokedex(const std::string& filename);

public:
    static Pokedex* getInstance(const std::string& filename);
    Pokemon* getOnePokebyName(string name) override;
    Pokemon* getOnePokebyId(int id) override;
    ~Pokedex();
};
#endif