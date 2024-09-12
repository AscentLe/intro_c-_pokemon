#include "Pokedex.hpp"
Pokedex* Pokedex::instance = nullptr;
Pokedex::Pokedex(const std::string &filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) { 
    std::stringstream ss(line); 
    std::string cell;
    std::vector<std::string> donneesLigne;
    while (std::getline(ss, cell, ',')) {
        donneesLigne.push_back(cell);
    }
    int id = std::stoi(donneesLigne[0]);         
    std::string name = donneesLigne[1];            
    double hp = std::stod(donneesLigne[5]);         
    double attack = std::stod(donneesLigne[6]);        
    double defense = std::stod(donneesLigne[7]);   
    double speed = std::stod(donneesLigne[10]);     
    int generation = std::stoi(donneesLigne[11]);
    bool legendary = (donneesLigne[12] == "True");

    Pokemon* pokemonPtr = new Pokemon(id, name, hp, attack, defense, speed, generation, legendary);
    arrayofPokemon.push_back(pokemonPtr);
    }
    file.close();
}

Pokedex* Pokedex::getInstance(const std::string& filename){
    if (instance == nullptr) {
        instance = new Pokedex(filename);
    }
    return instance;
}

Pokemon* Pokedex::getOnePokebyName(std::string name) {
    int indexInList=this->findPokebyName(name);
    if (indexInList!=1){
        return new Pokemon(*(this->arrayofPokemon.at(indexInList)));
    }
    return nullptr;
}

Pokemon* Pokedex::getOnePokebyId(int id) {
    int indexInList=this->findPokebyId(id);
    if (indexInList!=1){
        return new Pokemon(*(this->arrayofPokemon.at(indexInList)));
    }
    return nullptr;
}

Pokedex::~Pokedex() {
    std::cout << "Destroying Pokedex." << std::endl;
    for (Pokemon* pokemon : arrayofPokemon) {
        delete pokemon;
    }
}