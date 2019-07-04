#include "player.hpp"

/// \@file

/// \brief
/// Void draw function
/// \details
/// Function overrides the virtual function in ScherObject.
/// If the Player is active the function draws a bitmap at the location of the player object.

void Player::draw(){
    
   if (active == true)
    {

        w.write(hwlib::xy( location ), hwlib::image_8x8 (0xff, 0xe7 , 0xc3,  0x81, 0x00, 0x00, 0x00, 0x00));

        }
        
}

/// \brief
/// Void inverse draw function
/// \details
/// Function overrides the virtual function in ScherObject.
/// If the Player is active the function removes the bitmap at the location of the player object.

void Player::draw_inverse()
{   
    if (active == true)
    {

   w.write(hwlib::xy( location ), hwlib::image_8x8 (0xff, 0xff , 0xff,  0xff, 0xff, 0xff,0xff, 0xff));
        }
}

/// \brief
/// Void update function
/// \details
/// Function is not in use.


void Player::update(){}   

/// \brief
/// Void move function
/// \details
/// Function first removes the bitmap of the player and then updates the location of the player by one to the right.
/// The function also handels the problem of moving out of bounds.
    
void Player::move_right(){
    draw_inverse();
    old_location = location;
    location.x += 1;
    if(location.x > 120){ // to make sure not out of bound
        location.x = 120;
        }
    }
    
/// \brief
/// Void move function
/// \details
/// Function first removes the bitmap of the player and then updates the location of the player by one to the left.
/// The function also handels the problem of moving out of bounds.
    
void Player::move_left(){
    draw_inverse();
    old_location = location;    
    location.x -= 1;
    if(location.x < 0){
        location.x = 0;
        }
    }
    
/// \brief
/// Void create Player function
/// \details
/// Function creates a bitmap which becomes look of the player. 
    
void Player::set_bitmap(unsigned char d0, unsigned char d1,
                        unsigned char d2, unsigned char d3,
                        unsigned char d4, unsigned char d5,
                        unsigned char d6, unsigned char d7)
                        { }
                        
                        
/// \brief
/// Get function.
/// \details
/// Function gives the location of the upper left corner of the bounding box
                        
hwlib::xy Player::upper_left_corner(){
    return hwlib::xy(location.x, location.y+8);
}
    
/// \brief
/// Get function.
/// \details
/// Function gives the location of the lower right corner of the bounding box


hwlib::xy Player::lower_right_corner(){
    return hwlib::xy(location.x+8, location.y);
}