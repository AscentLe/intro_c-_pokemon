#include "Pokemon.hpp"
#include <iostream>

int Pokemon::NbPokemon = 0;

Pokemon::Pokemon(int id, const string &name, double hitPoint, double attack, double defense, double speed, int generation, bool legendary) : id(id), name(name), hitPoint(hitPoint), attack(attack), defense(defense), speed(speed), generation(generation), legendary(legendary){
    //std::cout << "Constructeur" << std::endl;
    //std::cout << "Nom : " << name << std::endl;
    NbPokemon+=1;
} 
Pokemon:: Pokemon(const Pokemon &anotherPokemon):id(anotherPokemon.id), name(anotherPokemon.name), hitPoint(anotherPokemon.hitPoint), attack(anotherPokemon.attack), defense(anotherPokemon.defense), speed(anotherPokemon.speed), generation(anotherPokemon.generation), legendary(anotherPokemon.legendary){
    //std::cout << "Copie : " << std::endl;
    NbPokemon+=1;
}

Pokemon::~Pokemon(){
    //std::cout << "Ici le destructeur" << std::endl;
    NbPokemon-=1;
}

void Pokemon::displayInfo() const{
    std::cout << id << "\n" << name << "\n" << hitPoint << "\n" << attack << "\n" << defense << "\n" << speed << "\n" << generation << "\n" << legendary << std::endl;
}

void Pokemon::attackPokemon(Pokemon &anotherPokemon){
    std::cout << name << " attacks " << anotherPokemon.getName() << std::endl;
    double damage=attack-anotherPokemon.getDefense();
    if (damage<=0){
        damage=0;
        std::cout << "This has no effect" << std::endl;
    }
    anotherPokemon.setHP(anotherPokemon.getHitPoint()-damage);
    if (anotherPokemon.getHitPoint()<=0){
        std::cout << anotherPokemon.getName() << " is dead!" << std::endl;
    }
}

int Pokemon::getId() const{
    return id;
}

string Pokemon::getName() const{
    return name;
}

double Pokemon::getHitPoint() const{
    return this->hitPoint;
}

double Pokemon::getAttack() const{
    return this->defense;
}

double Pokemon::getDefense() const{
    return this->defense;
}

double Pokemon::getSpeed() const{
    return speed;
}

int Pokemon::getGeneration() const{
    return this->generation;
}

bool Pokemon::getLegendary() const{
    return legendary;
}

int Pokemon::getNb()
{
    return NbPokemon;
}

void Pokemon::setHP(double hp){

    if (hp<0){
        hp=0;
    }
    hitPoint=hp;
    std::cout << name << " is now at HP=" << hitPoint << std::endl;
}
