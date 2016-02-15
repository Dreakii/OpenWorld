//CCamera.cpp

#include"CCamera.hpp"

Ccamera::Ccamera() : px( 0.0f ) , py( 0.0f ) , pz( 40.0f ) , angle( 0.0f ) , cam_x( 1.0f ) , cam_y( 0.0f ) {set();}

void Ccamera::set()
{
    View = glm::lookAt(
            glm::vec3(px,py,pz), // pozycja kamery
            glm::vec3(cam_x+px,cam_y+py,pz-1.0f), // cel kamery
            glm::vec3(0,0,1)); // obrot kamery
}

glm::mat4 Ccamera::GetView() {return View;};

void Ccamera::left(){ py -= cos((( angle + 90.f ) * M_PI ) / 180.0f); px -= sin((( angle + 90.f ) * M_PI ) / 180.0f); }

void Ccamera::right() { py += cos((( angle + 90.f ) * M_PI ) / 180.0f); px += sin((( angle + 90.f ) * M_PI ) / 180.0f); }

void Ccamera::front() { py += cos(( angle * M_PI ) / 180.0f); px += sin(( angle * M_PI ) / 180.0f); }

void Ccamera::back() { py -= cos(( angle * M_PI ) / 180.0f); px -= sin(( angle * M_PI ) / 180.0f); }

void Ccamera::up() { pz += 1.5f; }

void Ccamera::down() { pz -= 1.5f; }

void Ccamera::target_right() { angle += 15.1f; cam_y = cos(( angle * M_PI ) / 180.0f); cam_x = sin(( angle * M_PI ) / 180.0f); }

void Ccamera::target_left() { angle -= 15.1f; cam_y = cos(( angle * M_PI ) / 180.0f); cam_x = sin(( angle * M_PI ) / 180.0f); }
