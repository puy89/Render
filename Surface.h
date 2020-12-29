#pragma once
#include "Misc.h"

class Surface{
public:
    Material *mat;
    virtual Vector& normal(Vector &pos, Vector &tar) = 0;

    virtual double intersect(Ray &ray) = 0;
};

class Plane : public Surface {
    Vector& cnormal;
    double c;


public:
    Plane(Vector lnormal, double c, Material& lmat);

    Plane(double x, double y, double z, double c, Material& lmat);

    ~Plane();

    double intersect(Ray& ray);

    Vector& normal(Vector& pos, Vector& tar);
};

class Sphere : public Surface
{
public:
    Vector& center;
    double radius, radius2, center2;

    Sphere(double x, double y, double z, double radius, Material& mat);

    ~Sphere();

    Vector& normal(Vector& pos, Vector& tar);

    double intersect(Ray& ray);

};