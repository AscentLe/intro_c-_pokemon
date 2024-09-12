#ifndef SETOFPOKEMON_HPP  
#define SETOFPOKEMON_HPP

#include <vector>
#include "Pokemon.hpp"
class SetOfPokemon {
protected:
    std::vector<Pokemon *> arrayofPokemon;
    int findPokebyName(string name);
    int findPokebyId(int id);
public:
    virtual Pokemon* getOnePokebyName(string name)=0;
    virtual Pokemon* getOnePokebyId(int id)=0;
    void displayList();
    
    SetOfPokemon();

    virtual ~SetOfPokemon();
};   
#endif