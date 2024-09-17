#include "PokemonParty.hpp"

PokemonParty::PokemonParty(const std::vector<std::string>& names, Pokeball* pokeball) : linkedPokeball(pokeball) {
    for (const std::string& name : names) {
        if (party.size() >= MAX_PARTY_SIZE) {
            std::cout << "Cannot add more Pokémon. Party is full!" << std::endl;
            break;
        }
        Pokemon* pokemon = linkedPokeball->getOnePokebyName(name);
        if (pokemon != nullptr) {
            party.push_back(pokemon); 
            linkedPokeball->removePokemonByName(name);
        } else {
            std::cout << "Failed to add Pokémon with name: " << name << " to the party." << std::endl;
        }
    }
}
PokemonParty::PokemonParty(const std::vector<int>& ids, Pokeball* pokeball) : linkedPokeball(pokeball) {
    for (int id : ids) {
        if (party.size() >= MAX_PARTY_SIZE) {
            std::cout << "Cannot add more Pokémon. Party is full!" << std::endl;
            break;
        }
        Pokemon* pokemon = linkedPokeball->getOnePokebyId(id);
        if (pokemon != nullptr) {
            party.push_back(pokemon); 
            linkedPokeball->removePokemonById(id);
        } else {
            std::cout << "Failed to add Pokémon with ID: " << id << " to the party." << std::endl;
        }
    }
}

bool PokemonParty::hasAtLeastOnePokemon() const {
    return party.size() > 0;
}

void PokemonParty::disband() {
    std::cout << "Disbanding the Pokemon Party..." << std::endl;
    for (Pokemon* p : party) {
        linkedPokeball->addPokemonback(p);
        std::cout << "Returned Pokemon to Pokeball." << std::endl;
    }
    party.clear(); 
}

PokemonParty::~PokemonParty(){
}

void PokemonParty::displayParty() const {
    std::cout << "Current Pokémon Party:" << std::endl;
    for (const Pokemon* p : party) {
        p->displayInfo();
    }
}

int PokemonParty::getPokemonCount() const {
    return arrayofPokemon.size();
}

void PokemonParty::addPokemonback(Pokemon *pokemon){
    arrayofPokemon.push_back(pokemon);
    std::cout << "Pokemon added to Pokeball." << std::endl;
}

bool PokemonParty::removePokemonByName(const std::string& name) {
    if (!hasAtLeastOnePokemon()) {
        std::cout << "Cannot remove Pokémon. Your party must have at least one Pokémon." << std::endl;
        return false;
    }
    for (auto it = party.begin(); it != party.end(); ++it) {
        if ((*it)->getName() == name) {
            linkedPokeball->addPokemonback(*it);
            party.erase(it); 
            std::cout << "Removed " << name << " from your party and added it back to your Pokéball." << std::endl;
            return true;
        }
    }
    std::cout << "Pokémon with name " << name << " not found in your party." << std::endl;
    return false;
}

Pokemon *PokemonParty::getOnePokebyName(string name)
{
    return nullptr;
}

Pokemon *PokemonParty::getOnePokebyId(int id)
{
    return nullptr;
}
