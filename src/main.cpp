#include <iostream>
#include "Pokemon.hpp"
#include "Pokedex.hpp"
#include "Pokeball.hpp"
#include "PokemonParty.hpp"
#include "Context.hpp"
#include "StateAttente.hpp"

void ClientCode(){
    Context *context = new Context(new WaitingState);
    context->Request();
    context->Request();
    delete context;
}

int main(){
    Pokeball pokeball;
    std::cout << "Nb of Pokemon : " << Pokemon::getNb()  << std::endl;
    Pokemon salameche(4,"salameche", 100, 50, 25, 1);
    std::cout << "Nb of Pokemon : " << Pokemon::getNb()  << std::endl;
    Pokemon bulbizarre(1, "bulbizarre", 100, 25, 10, 1);
    std::cout << "Nb of Pokemon : " << Pokemon::getNb()  << std::endl;
    Pokemon copie(salameche);
    std::cout << "Nb of Pokemon : " << Pokemon::getNb()  << std::endl;
    std::cout << "Info : " << std::endl;
    salameche.displayInfo(); 
    salameche.attackPokemon(bulbizarre);
    bulbizarre.attackPokemon(salameche);
    salameche.attackPokemon(bulbizarre);
    salameche.attackPokemon(bulbizarre);
    Pokedex* pokedex = Pokedex::getInstance("../resources/pokedex.csv");
    Pokemon* pikachu = pokedex->getOnePokebyName("Pikachu");
    if (pikachu != nullptr) {
        std::cout << "Found Pokemon: " << pikachu->getName() << std::endl;
    } else {
        std::cout << "Pokemon Pikachu not found." << std::endl;
    }
    Pokemon* poke500 = pokedex->getOnePokebyId(500);
    if (poke500 != nullptr) {
        std::cout << "Found Pokemon with ID 500: " << poke500->getName() << std::endl;
    } else {
        std::cout << "Pokemon with ID 500 not found." << std::endl;
    }
    pokeball.addPokemonbyName("Pikachu");
    pokeball.addPokemonbyId(500);
    pokeball.addPokemonbyId(1);
    pokeball.addPokemonbyId(10);
    pokeball.addPokemonbyId(100);
    pokeball.addPokemonbyId(200);
    pokeball.addPokemonbyId(300);
    pokeball.addPokemonbyId(400);
    pokeball.addPokemonbyId(600);
    pokeball.addPokemonbyId(700);

    std::vector<int> ids = {1,10,100,200,300,400,500};
    PokemonParty myParty(ids, &pokeball);

    /*myParty.displayParty();
    myParty.displayList();
    pokeball.displayList();*/
    myParty.disband();


    return 0;
}
