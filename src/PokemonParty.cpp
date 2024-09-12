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

Pokemon *PokemonParty::getOnePokebyName(string name)
{
    return nullptr;
}

Pokemon *PokemonParty::getOnePokebyId(int id)
{
    return nullptr;
}
