//
// Created by david on 5/15/2023.
//

#include "Character.hpp"
#include <iostream>

using namespace std;
namespace ariel {
    bool Character::isAlive() {
        return true;
    }

    Character::Character(string CharName, Point &Charlocation, int CharHP)
            : name(CharName), location(Charlocation), health(CharHP) {}

    Character::Character(Character &other)
            : name(other.getName()), location(other.getLocation()), health(other.health) {}

    double Character::distance(const Character *const other) {
        return 1;
    }

    void Character::hit(int hurtPoint){

    }

    string Character::getName(){
        return this->name;
    }

    Point Character::getLocation(){
        return this->location;
    }

    string Character::print(){
        return "fix print";
    }
    Character& Character::operator=(const Character& other){
        if(this==&other){
            return *this;
        }
        this->name=other.name;
        this->location=other.location;
        this->health=other.health;
        return *this;

    }

}