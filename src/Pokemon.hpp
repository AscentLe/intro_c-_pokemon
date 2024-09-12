#ifndef POKEMON_HPP  
#define POKEMON_HPP
#include <string>
using std::string;
class Pokemon {
private:
    int id;
    string name;
    double hitPoint;
    double attack;
    double defense;
    double speed;
    int generation;
    bool legendary;
    static int NbPokemon;
public:
    Pokemon(int id, const string &name, double hitPoint, double attack, double defense, double speed, int generation, bool legendary);
    Pokemon(const Pokemon &anotherPokemon); 

    ~Pokemon();

    int getId() const;
    string getName() const;
    double getHitPoint() const;
    double getAttack() const;
    double getDefense() const;
    double getSpeed() const; 
    int getGeneration() const;
    bool getLegendary() const;
    static int getNb();

    void setHP(double hp);

    void displayInfo() const;
    void attackPokemon(Pokemon &anotherPokemon);
};
#endif