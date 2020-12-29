#pragma once
#include<vector>
#include<iostream>
#include<math.h>
#include "Surface.h"


using namespace std;


class Scene {

private:
    double bg_r, bg_g, bg_b;
    int rays_num, max_recurs, sample_lev, sample_lev2, rays_num2;
    Camera *cam=nullptr;
    std::vector<Surface*> surfs;
    std::vector<Light*> lights;
    double **rgb;
    int rec_i = 0;
    Vector temp_vec, p0, camleft;
    Ray *rays;
    int imageWidth=0, imageHeight=0;

public:
    Scene(double bg_r, double bg_g, double bg_b, int rays_num, int max_recurs, int sample_lev);

    ~Scene();

    void setCam(Camera& cam, int imageWidth, int imageHeight);

    void addSurface(Surface& surf);

    void addLight(Light& light);

    double* trace(Ray& camray, int rec, double* rgb);

    void render(uint8_t* rgbData);

};