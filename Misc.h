#pragma once
#include "Vector.h"

class Camera {
public:
    Vector &pos; //double pos_x, pos_y, pos_z;
    Vector &look; //double look_x, look_y, look_z;
    Vector &look_v;
    Vector &up; //double up_x, up_y, up_z;
    Vector left, p_0;
    double screen_dist, screen_width, screen_height;


    Camera(double pos_x, double pos_y, double pos_z,
        double look_x, double look_y, double look_z,
        double up_x, double up_y, double up_z,
        double screen_dist, double screen_width);

    ~Camera();
};

class Material {
public:
    double diff_r, diff_g, diff_b;
    double spec_r, spec_g, spec_b;
    double reflect_r, reflect_g, reflect_b;
    bool reflect;
    double phong;
    double trans;


    Material(double diff_r, double diff_g, double diff_b,
        double spec_r, double spec_g, double spec_b,
        double reflect_r, double reflect_g, double reflect_b,
        double phong, double trans);
};

class Light {
    //double x, y, z;
public:
    Vector& pos;
    double r, g, b;
    double spec_intens, shadow_intens, radius;
    Light(double x, double y, double z,
        double r, double g, double b,
        double spec_intens, double shadow_intens, double radius);

    ~Light();
};


class Ray {
public:
    Light* light = nullptr;
    Vector& src, & direct;
    double src2, direct2, src_dot_direct, orig_size;

    Ray();

    Ray(Vector& lsrc, Vector& ldirect, Light& light);


    //for tracing rays from the eye (backward tracing)
    Ray(Vector& lsrc, Vector& ldirect);

    ~Ray();


    void getPos(double t, Vector& tar);

};
