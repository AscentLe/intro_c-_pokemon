#include "Pokeball.hpp"

Pokeball::Pokeball(){}

Pokemon* Pokeball::getOnePokebyName(std::string name) {
    int indexInList=this->findPokebyName(name);
    if (indexInList!=1){
        return new Pokemon(*(this->arrayofPokemon.at(indexInList)));
    }
    return nullptr;
}

Pokemon* Pokeball::getOnePokebyId(int id) {
    int indexInList=this->findPokebyId(id);
    if (indexInList!=1){
        return new Pokemon(*(this->arrayofPokemon.at(indexInList)));
    }
    return nullptr;
}

void Pokeball::addPokemonbyName(string name){
    Pokemon* pokemon = Pokedex::getInstance("../resources/pokedex.csv")->getOnePokebyName(name);
    if (pokemon != nullptr){
        arrayofPokemon.push_back(pokemon);
        std::cout << "Added pokemon " << name << " to pokeball" << std::endl;
    }
    else {
        std::cout << "Pokemon " << name << " not found" << std::endl;
    }
}

void Pokeball::addPokemonbyId(int id){
    Pokemon* pokemon = Pokedex::getInstance("../resources/pokedex.csv")->getOnePokebyId(id);
    if (pokemon != nullptr){
        arrayofPokemon.push_back(pokemon);
        std::cout << "Added pokemon " << id << " to pokeball" << std::endl;
    }
    else {
        std::cout << "Pokemon " << id << " not found" << std::endl;
    }
}

bool Pokeball::removePokemonByName(const std::string& name) {
    for (auto it = arrayofPokemon.begin(); it != arrayofPokemon.end(); ++it) {
        if ((*it)->getName() == name) {
            delete *it; 
            arrayofPokemon.erase(it); 
            std::cout << "Removed pokemon " << name << " from pokeball" << std::endl;
            return true;
        }
    }
    return false;
}

bool Pokeball::removePokemonById(int id) {
    for (auto it = arrayofPokemon.begin(); it != arrayofPokemon.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it; 
            arrayofPokemon.erase(it);
            std::cout << "Removed pokemon with ID " << id << " from pokeball" << std::endl;
            return true;
        }
    }
    return false;
}

void Pokeball::addPokemonback(Pokemon* pokemon) {
    arrayofPokemon.push_back(pokemon);
    std::cout << "Pokemon added to Pokeball." << std::endl;
}

int Pokeball::getPokemonCount() const {
    return arrayofPokemon.size();
}

Pokeball::~Pokeball(){
}
