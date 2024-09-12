#include "SetOfPokemon.hpp"
int SetOfPokemon::findPokebyName(string name){
    for (size_t i = 0; i < arrayofPokemon.size(); ++i) {
        if (arrayofPokemon[i]->getName() == name) {
            return static_cast<int>(i);  
        }
    }
    return -1; 
}

int SetOfPokemon::findPokebyId(int id){
    for (size_t i = 0; i < arrayofPokemon.size(); ++i) {
        if (arrayofPokemon[i]->getId() == id) {
            return static_cast<int>(i); 
        }
    }
    return -1; 
}
void SetOfPokemon::displayList()
{
    for (Pokemon * pokemon : arrayofPokemon){
        pokemon -> displayInfo();
    }
}
SetOfPokemon::SetOfPokemon() {}

SetOfPokemon::~SetOfPokemon() {}