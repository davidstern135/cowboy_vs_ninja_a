//
// Created by david on 5/16/2023.
//
#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
#include <cmath>
#include <iostream>
#include <string.h>

using namespace ariel;
using namespace std;


TEST_CASE("ctor for class point, doesnt throw") {
    CHECK_NOTHROW(Point());
    CHECK_NOTHROW(Point(1, 1));
    CHECK_NOTHROW(Point(1.1, 1));
    CHECK_NOTHROW(Point(1, 1.1));
    CHECK_NOTHROW(Point(1.1, 1.1));
    CHECK_NOTHROW(Point(-1, 1));
    CHECK_NOTHROW(Point(-1.1, 1));
    CHECK_NOTHROW(Point(1, -1.1));
    CHECK_NOTHROW(Point(-1.1, -1.1));
}

TEST_CASE("func dont throw in class point") {
    Point point1(1, 1);
    Point point2(1, 1);
    Point point3(1, 1);
    CHECK_NOTHROW(point1.print());
    CHECK_NOTHROW(point1.moveTowards(point2, point3, 15.5));
    CHECK_NOTHROW(point1.moveTowards(point2, point3, 15));
    CHECK_NOTHROW(point1.getX());
    CHECK_NOTHROW(point1.getY());
    CHECK_NOTHROW(point1.distance(point2));
}

TEST_CASE("func works right in class point") {
    Point point1(-1, 1);
    Point point2(2, 1);
    Point point3(3.3, 2.4);
    Point point4(2.1, 4.5);
    Point point5(5, 1);
    CHECK_EQ(point1.getY(), 1);
    CHECK_EQ(point1.getX(), -1);
    CHECK_NE(point2.getX(), -2);
    CHECK_NE(point2.getY(), 1.5);
    CHECK_EQ(point1.distance(point2), point2.distance(point1));
    CHECK_EQ(point3.distance(point2), point2.distance(point3));
    CHECK_EQ(point4.distance(point2), point2.distance(point4));
    CHECK_EQ(point1.distance(point3), point3.distance(point1));
    CHECK_EQ(point5.distance(point2), point1.distance(point2));
}

TEST_CASE("checking character ctor") {
    Point point1(1.1, 1.1);
    Point point2(2.5, 1.2);
    CHECK_NOTHROW(Character("david", point1, 100));
    CHECK_NOTHROW(Character("stern", point2, 150));
}

TEST_CASE("checking chracter no throws") {
    Point point1(1.1, 1.1);
    Point point2(2.5, 1.2);
    Character david("david", point1, 100);
    Character stern("stern", point2, 150);

    CHECK_NOTHROW(david.hit(20));
    CHECK_NOTHROW(david.hit(20));
    CHECK_NOTHROW(stern.distance(&david));
    CHECK_NOTHROW(david.print());
    CHECK_NOTHROW(david.getName());
    CHECK_NOTHROW(david.getLocation());
    CHECK_NOTHROW(david.isAlive());
    CHECK_NOTHROW(Character yossi = david);
}

TEST_CASE("checking character") {
    Point point1(1.1, 1.2);
    Point point2(2.5, 1.2);
    Character david("david", point1, 100);
    Character stern("stern", point2, 150);
    CHECK(david.isAlive());
    CHECK_EQ(david.getLocation().getX(), 1.1);
    CHECK_EQ(david.getLocation().getY(), 1.2);
    CHECK_EQ(david.distance(&stern), stern.distance(&david));
    david.hit(20);
    david.hit(30);
    david.hit(50);
    CHECK_FALSE(david.isAlive());
}

TEST_CASE("checking cowboy and ninja ctor no throw") {
    Point point1(-1, 1);
    Point point2(2, 1);
    Point point3(3.3, 2.4);
    Point point4(2.1, 4.5);
    Point point5(5, 1);
    CHECK_NOTHROW(Cowboy("david", point1));
    CHECK_NOTHROW(Ninja("davids", 100, point2, 10));
    CHECK_NOTHROW(OldNinja("davidst", point3));
    CHECK_NOTHROW(TrainedNinja("davidstr", point4));
    CHECK_NOTHROW(YoungNinja("davidstern", point5));
}
TEST_CASE("checking cowboy and ninja ctor") {
    Point point1(-1, 1);
    Point point2(2, 1);
    Point point3(3.3, 2.4);
    Point point4(2.1, 4.5);
    Point point5(5, 1);
    Cowboy david("david", point1);
    Ninja nin("nin", 100, point2, 10);
    OldNinja old("old", point3);
    TrainedNinja trained("trained", point4);
    YoungNinja young("young", point5);
    CHECK_NOTHROW(david.hasboolets());
    CHECK(david.hasboolets());
    CHECK_NOTHROW(david.shoot(&nin));
    CHECK_NOTHROW(david.reload());
    CHECK_NOTHROW(david.isAlive());
    CHECK_NOTHROW(david.print());
    CHECK_NOTHROW(david.hit(10));
    CHECK_NOTHROW(david.getLocation());
    CHECK_NOTHROW(david.getName());

    CHECK_NOTHROW(nin.getSpeed());
    CHECK_NOTHROW(nin.print());
    CHECK_NOTHROW(nin.hit(10));
    CHECK_NOTHROW(nin.getLocation());
    CHECK_NOTHROW(nin.getName());
    CHECK_NOTHROW(nin.isAlive());
    CHECK_NOTHROW(nin.slash(&david));

    CHECK_NOTHROW(old.getSpeed());
    CHECK_NOTHROW(old.print());
    CHECK_NOTHROW(old.hit(10));
    CHECK_NOTHROW(old.getLocation());
    CHECK_NOTHROW(old.getName());
    CHECK_NOTHROW(old.isAlive());
    CHECK_NOTHROW(old.slash(&david));


    CHECK_NOTHROW(trained.getSpeed());
    CHECK_NOTHROW(trained.print());
    CHECK_NOTHROW(trained.hit(10));
    CHECK_NOTHROW(trained.getLocation());
    CHECK_NOTHROW(trained.getName());
    CHECK_NOTHROW(trained.isAlive());
    CHECK_NOTHROW(trained.slash(&nin));


    CHECK_NOTHROW(young.getSpeed());
    CHECK_NOTHROW(young.print());
    CHECK_NOTHROW(young.hit(10));
    CHECK_NOTHROW(young.getLocation());
    CHECK_NOTHROW(young.getName());
    CHECK_NOTHROW(young.isAlive());
    CHECK_NOTHROW(young.slash(&nin));
}
TEST_CASE("checking cowboy and ninja") {
    Point point1(1.1, 1.2);
    Point point2(2.5, 1.2);
    Point point3(3.3, 2.4);
    Point point4(2.1, 4.5);
    Point point5(5, 1);
    Cowboy david("david", point1);
    Ninja nin("nin", 100, point2, 10);
    OldNinja old("old", point3);
    TrainedNinja trained("trained", point4);
    YoungNinja young("young", point5);
    CHECK_EQ(nin.getSpeed(),10);
    CHECK_EQ(old.getSpeed(),8);
    CHECK_EQ(trained.getSpeed(),12);
    CHECK_EQ(young.getSpeed(),14);
    CHECK(david.isAlive());
    CHECK(old.isAlive());
    CHECK(nin.isAlive());
    CHECK(young.isAlive());
    CHECK(trained.isAlive());
    for(int i=0;i<6;i++){
        CHECK(david.hasboolets());
        david.shoot(&old);
    }
    CHECK(old.isAlive());
    CHECK_FALSE(david.hasboolets());
    david.reload();
    CHECK(david.hasboolets());
}
TEST_CASE("Test Teams class ctor") {
    Point point1(1.1, 1.2);
    Point point2(2.5, 1.2);
    Point point3(3, 1.2);

    Cowboy david("david", point1);
    Cowboy stern("stern", point2);
    Cowboy stern2("stern2", point3);

    CHECK_NOTHROW(Team team(&david));
    CHECK_NOTHROW(Team2 team2(&stern));
    CHECK_NOTHROW(SmartTeam smartTeam(&stern2));
}TEST_CASE("Test Teams class no throw") {
    Point point1(1.1, 1.2);
    Point point2(2.5, 1.2);
    Point point3(3, 1.2);
    Point point4(1.1, 1.4);
    Point point5(2.5, 1.5);
    Point point6(3, 1.6);
    Point point7(1.1, 1.7);
    Point point8(2.5, 1.8);
    Point point9(3, 1.9);
    Cowboy david("david", point1);
    Cowboy stern("stern", point2);
    Cowboy stern2("stern2", point3);
    OldNinja pl1("pl1",point4);
    OldNinja pl2("pl2",point5);
    YoungNinja pl3("pl3",point6);
    YoungNinja pl4("pl4",point7);
    TrainedNinja pl5("pl5",point8);
    TrainedNinja pl6("pl6",point9);

    Team team(&david);
    Team2 team2(&stern);
    SmartTeam smartTeam(&stern2);
    CHECK_NOTHROW(team.add(&pl1));
    CHECK_NOTHROW(team.add(&pl3));

    CHECK_NOTHROW(team.add(&pl2));
    CHECK_NOTHROW(team.add(&pl4));

    CHECK_NOTHROW(team.add(&pl5));
    CHECK_NOTHROW(team.add(&pl6));
    CHECK(team.stillAlive());
    CHECK(team2.stillAlive());
    CHECK(smartTeam.stillAlive());
    CHECK_NOTHROW(team.print());
    CHECK_NOTHROW(team2.print());
    CHECK_NOTHROW(smartTeam.print());
}
TEST_CASE("Test all Teams classes") {
    Point point1(1.1, 1.2);
    Point point2(2.5, 1.2);
    Cowboy david("david", point1);
    Cowboy stern("stern", point2);
    Team team(&david);
    team.add(&stern);
    CHECK_EQ(team.stillAlive(),2);
    Point point3(3.3, 2.4);
    Point point4(2.1, 4.5);
    Cowboy davids("davids", point3);
    Cowboy sternd("sternd", point4);
    Team team2(&davids);
    team.add(&sternd);
    team.attack(&team2);
    CHECK_EQ(team.stillAlive(),2);
}
