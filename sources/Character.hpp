//
// Created by david on 5/15/2023.
//

#ifndef CPP_CHARACTER_HPP
#define CPP_CHARACTER_HPP
#pragma once
#include <iostream>
#include "Point.hpp"

using namespace std;
namespace ariel {
    class Character {
        string name;
        int health;
        Point location;
    public:
        Character(string CharName, Point &Charlocation, int CharHP);
        Character(Character& other);
        bool isAlive();
        double distance(const Character* const other);
        void hit(int hurtPoint);
        string getName();
        Point getLocation();
        virtual string print();
        Character& operator=(const Character& other);

    };
}


#endif //CPP_CHARACTER_HPP
