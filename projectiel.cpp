#include "projectiel.hpp"


/// \@file
///
/// \brief
/// Void update function.
/// \details
/// This function checks if the projectile is active. then removes it from the screen using the draw inverse function.
/// It then lowers the y axis of the location of the projectile to make it move up.
/// if the projectiel goes out of sreen it is set to inactive.

void Projectiel::update() {
    if(is_active()){
        old_location = location;
        draw_inverse();
        location.y -= 1;
        if(location.y < 0){
            active = false;
            return;
        }      
    }
}
/// \brief
/// Void draw function.
/// \details
/// This function draws the projectile on its location.

void Projectiel::draw(){
    w.write( hwlib::xy( location ) );
}   


/// \brief
/// Void draw inverse function.
/// \details
/// This function removes the projectile by drawing the background color on its location.
    
void Projectiel::draw_inverse(){
    w.write( hwlib::xy( location ), w.background );
    
    }

/// \brief
/// Get function.
/// \details
/// Function gives the location of the upper left corner of the bounding box.

hwlib::xy Projectiel::upper_left_corner(){
    return location;
}

/// \brief
/// Get function.
/// \details
/// Function gives the location of the lower right corner of the bounding box.

hwlib::xy Projectiel::lower_right_corner(){
    return location;
}