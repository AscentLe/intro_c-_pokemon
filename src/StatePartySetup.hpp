#ifndef STATEPARTYSETUP_HPP
#define STATEPARTYSETUP_HPP

#include "State.hpp"
#include "Pokeball.hpp"
#include "PokemonParty.hpp"
#include "Player.hpp"

class StatePartySetup : public State {
public:
    StatePartySetup();
    void handle() override;
    std::string getName() const override;
    void addPokemons(Player* player);
    void removePokemons(Player* player);
};

#endif
