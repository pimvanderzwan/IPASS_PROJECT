#include "enemy.hpp"

/// \@file
///
/// \brief
/// Void draw function.
/// \details
/// This function creates the look of the enemy.
/// This function uses the location of the enemy object to as a reference point to draw its persona.
/// A bitmap is not used because the time it takes to draw.



void Enemy::draw(){
    
   if (active == true)
    {
        w.write(hwlib::xy(location.x, location.y +1), w.foreground );
        w.write(hwlib::xy(location.x, location.y +2), w.foreground );
        w.write(hwlib::xy(location.x, location.y +3), w.foreground);
        w.write(hwlib::xy(location.x, location.y +4), w.foreground);
        w.write(hwlib::xy(location.x, location.y ), w.foreground);
        w.write(hwlib::xy(location.x-1, location.y +3), w.foreground);
        w.write(hwlib::xy(location.x+1, location.y +3), w.foreground);
        }
        
}

/// \brief
/// Void inverse draw function.
/// \details
/// This function removes the look of the enemy.
/// This function works the same as the draw function, but it draws the background.

void Enemy::draw_inverse()
{   
    if (active == true)
    {
    w.write(hwlib::xy(location.x, location.y +1), w.background );
    w.write(hwlib::xy(location.x, location.y +2), w.background );
    w.write(hwlib::xy(location.x, location.y +3), w.background);
    w.write(hwlib::xy(location.x, location.y +4), w.background);
    w.write(hwlib::xy(location.x, location.y ), w.background);
    w.write(hwlib::xy(location.x-1, location.y +3), w.background);
    w.write(hwlib::xy(location.x+1, location.y +3), w.background);
        }
}

/// \brief
/// Void update function.
/// \details
/// This function checks if the enemy is active. Then calls on the draw inverse function to remove the image of the enemy.
/// The speed is added to the y axis of the location.
/// If the location of the enemy is outside the screen the object is disactivated and placed on the top of screen.
/// If the Enemy is inactive its activated.

void Enemy::update(){
    if(is_active()){
    draw_inverse();
    old_location = location;
    location.y += speed;
    if(location.y > 64){
        deactivate();
        location.y = 0;
    }
    }
    else{
        activate();
        }

}


/// \brief
/// Get function.
/// \details
/// Function gives the location of the upper left corner of the bounding box
 
hwlib::xy Enemy::upper_left_corner(){
    return hwlib::xy(location.x-1, location.y+4);
}

/// \brief
/// Get function.
/// \details
/// Function gives the location of the lower right corner of the bounding box

hwlib::xy Enemy::lower_right_corner(){
    return hwlib::xy(location.x+1, location.y);
}