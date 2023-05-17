//
// Created by david on 5/15/2023.
//

#ifndef CPP_TEAM_HPP
#define CPP_TEAM_HPP
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <iostream>
#include <vector>

namespace ariel {

    class Team {
        Character* leader;
        vector<Character*> CowMembers;
        vector<Character*> NinMembers;
    public:
        Team(Character* leader);
        ~Team();
        void add(Character* newMember);
        void attack(Team* enemies);
        int stillAlive();
        virtual string print();
    };



} // ariel

#endif //CPP_TEAM_HPP
