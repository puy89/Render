#pragma once
#include<math.h>

class Vector {
public:
    double x, y, z;


    Vector();

    Vector(double x, double y, double z);

    Vector(Vector& other);

    Vector(Vector& v1, Vector& v2);

    double dot(Vector other);

    Vector& prod(double scalar, Vector& tar);

    Vector& minus(Vector& other, Vector& tar);

    void idiv(double scalar);

    void cross(Vector other, Vector& tar);

    Vector* cross(Vector& other);

    Vector* prod(double scalar);

    Vector* plus(Vector& other);

    Vector* minus(Vector other);

    Vector* getPerp();

    double normalize();

    double size();

    double size2();

    bool equals(Vector& other);

    Vector& linePos(Vector& direct, double t, Vector& tar);

};

