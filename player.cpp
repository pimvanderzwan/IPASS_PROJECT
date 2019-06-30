#include "player.hpp"


void Player::draw(){
    
   if (active == true)
    {
        //hwlib::cout << "begin draw player " << location ;
        w.write(hwlib::xy( location ), hwlib::image_8x8 (0xff, 0xe7 , 0xc3,  0x81, 0x00, 0x00, 0x00, 0x00));
        //w.write( hwlib::xy( location ) );
        //persona( location );
        }
        
        //hwlib::cout << "    end draw player" ;
}

void Player::draw_inverse()
{   
    if (active == true)
    {
    //hwlib::cout << "begin draw player inverse " << location ;
    /*w.write( hwlib::xy( location ), w.background);
    
    w.write( hwlib::xy(location.x + 1, location.y +1), w.background);
    w.write( hwlib::xy(location.x  -1, location.y -1), w.background);
    w.write( hwlib::xy(location.x + 1, location.y -1), w.background);
    w.write( hwlib::xy(location.x  -1, location.y +1), w.background);*/
   w.write(hwlib::xy( location ), hwlib::image_8x8 (0xff, 0xff , 0xff,  0xff, 0xff, 0xff,0xff, 0xff));
        }
}
void Player::update(){
    }   
    
void Player::move_right(){
    draw_inverse();
    location.x += 8;
    if(location.x > 120){ // to make sure not out of bound
        location.x = 120;
        }
    draw();
    
    }
    
    
void Player::move_left(){
    draw_inverse();
    location.x -= 8;
    if(location.x < 0){
        location.x = 0;
        }
    draw();
    }

void Player::persona(hwlib::xy location){
    w.write( hwlib::xy(location.x + 1, location.y +1) );
    w.write( hwlib::xy(location.x  -1, location.y -1) );
    w.write( hwlib::xy(location.x + 1, location.y -1) );
    w.write( hwlib::xy(location.x  -1, location.y +1) );
    
    }
    
void Player::set_bitmap(unsigned char d0, unsigned char d1,
                        unsigned char d2, unsigned char d3,
                        unsigned char d4, unsigned char d5,
                        unsigned char d6, unsigned char d7)
                        {
                           // bitmap(unsigned char d0, unsigned char d1,
                          //              unsigned char d2, unsigned char d3,
                           //             unsigned char d4, unsigned char d5,
                            //            unsigned char d6, unsigned char d7);
                        }