//
// Created by david on 5/15/2023.
//

#include "Team.hpp"

namespace ariel {
    Team::Team(Character* leader) : leader(leader) {}
    Team::~Team() {}
    void Team::add(Character* teammate) {}
    void Team::attack(Team* enemiesTeam) {}
    int Team::stillAlive() {
        return 0;
    }
    string Team::print(){return "Team not ready";}






} // ariel