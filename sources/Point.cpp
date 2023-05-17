//
// Created by david on 5/15/2023.
//
#include "Point.hpp"

using namespace std;
namespace ariel{
    Point::Point(){
        this->paramY=0;
        this->paramY=0;
    }

    Point::Point(double parX,double parY):paramX(parX),paramY(parY){};

    double Point::distance(Point other){

        return 1.1;
    }

    string Point::print(){
        return "fix point printer";
    }

    Point Point::moveTowards(Point srcP, Point desP,double distance){
        return Point(1,1);
    }

    double Point::getX(){
        return this->paramX;
    }

    double Point::getY(){
        return this->paramY;
    }
}
#include "Point.hpp"