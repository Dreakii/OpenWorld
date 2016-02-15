#ifndef CCAMERA_HPP_INCLUDED
#define CCAMERA_HPP_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//const double M_PI = 3.14159265358;

class Ccamera
{
 private:

    float  px;
    float  py;
    float  pz;
    float angle;

    float  cam_x;
    float  cam_y;

    glm::mat4 View;

 public:

    Ccamera();// : px( 0.0f ) , py( 0.0f ) , pz( 40.0f ) , angle( 0.0f ) , cam_x( 1.0f ) , cam_y( 0.0f ;
    void set();
    glm::mat4 GetView();
    void left();
    void right();
    void front();
    void back();
    void up();
    void down();
    void target_right();
    void target_left();
};


#endif // CCAMERA_HPP_INCLUDED
