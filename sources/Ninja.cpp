//
// Created by david on 5/15/2023.
//

#include "Ninja.hpp"

namespace ariel {
    Ninja::Ninja(string name, int HPNinja, Point location, int speed)
            :Character(name, location, HPNinja), speed(speed) {}

    void Ninja::move(Character* enemy) {
    }

    void Ninja::slash(Character* enemy) {
        enemy->hit(40);
    }

    int Ninja::getSpeed(){
        return this->speed;
    }

    OldNinja::OldNinja(string name, Point location)
            : Ninja(name, 150, location, 8) {}

    YoungNinja::YoungNinja(string name, Point location)
            : Ninja(name, 100, location, 14) {}

    TrainedNinja::TrainedNinja(string name, Point location)
            : Ninja(name, 120, location, 12) {}

} // ariel