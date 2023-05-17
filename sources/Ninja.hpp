//
// Created by david on 5/15/2023.
//

#ifndef CPP_NINJA_HPP
#define CPP_NINJA_HPP
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
namespace ariel {

    class Ninja:public Character {
        int speed;
    public:
        Ninja(string name, int HPNinja, Point location, int speed);
        void move(Character* enemy);
        void slash(Character* enemy);
        int getSpeed();
    };
    class OldNinja:public Ninja{
    public:
        OldNinja(string name , Point location);
    };
    class YoungNinja:public Ninja{
    public:
        YoungNinja(string name , Point location);
    };
    class TrainedNinja:public Ninja{
    public:
        TrainedNinja(string name , Point location);
    };

} // ariel

#endif //CPP_NINJA_HPP
