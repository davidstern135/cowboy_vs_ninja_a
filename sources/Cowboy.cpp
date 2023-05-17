//
// Created by david on 5/15/2023.
//

#include "Cowboy.hpp"
#include <iostream>


namespace ariel {
    Cowboy::Cowboy(string name, Point &location): Character(name, location, 110), bulletsLeft(6){}
    void Cowboy::shoot(Character* enemy){
    }
    bool Cowboy::hasboolets(){
        return true;
    }
    void Cowboy::reload(){
    }
    string Cowboy::print(){
        return "fix cowboy print";
    }
} // ariel