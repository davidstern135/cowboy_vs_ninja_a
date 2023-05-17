//
// Created by david on 5/15/2023.
//

#ifndef CPP_POINT_HPP
#define CPP_POINT_HPP
#include <iostream>

using namespace std;

namespace ariel{
    class Point {
        double paramX;
        double paramY;

    public:
        Point();
        Point(double paX,double paY);
        double distance(Point other);
        string print();
        Point moveTowards(Point srcP, Point desP,double distance);
        double getX();
        double getY();
    };
}


#endif //COWBOY_VS_NINJA_A_MAIN_POINT_HPP
