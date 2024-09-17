#ifndef STATEPARTYSETUP_HPP
#define STATEPARTYSETUP_HPP

#include "State.hpp"
#include "Pokeball.hpp"
#include "PokemonParty.hpp"

class StatePartySetup : public State {
public:
    StatePartySetup(Pokeball* pokeball, PokemonParty* party);
    void handle() override;
    std::string getName() const override;
};

#endif
