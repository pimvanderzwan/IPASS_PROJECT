#include "enemy.hpp"

void Enemy::draw(){
    
   if (active == true)
    {
        draw_inverse();
        persona(location);
        //hwlib::cout << "begin draw enemy " << location ;
        //w.write( hwlib::xy( location ) );
        //w.write(hwlib::xy( location ), hwlib::image_8x8 (0x00, 0x81, 0xc3, 0xe7, 0xff, 0xff, 0xff, 0xff));
        }
        
        //hwlib::cout << "    end draw player" ;
}

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
    //hwlib::cout << "begin draw player inverse " << location ;
    // w.write( hwlib::xy( location ), w.background);
    //w.write(hwlib::xy( location ), hwlib::image_8x8 (0xff, 0xff , 0xff,  0xff, 0xff, 0xff,0xff, 0xff));
        }
}
void Enemy::update(){
    draw_inverse();
    location.y += speed;
    if(location.y > 64){ 
        location.y = 0;
    }
    draw();
    //hwlib::cout << "hello from update enemy";
    }
    
    
void Enemy::persona(hwlib::xy location) {
    w.write(hwlib::xy(location.x, location.y +1 ));
    w.write(hwlib::xy(location.x, location.y +2 ));
    w.write(hwlib::xy(location.x, location.y +3));
    w.write(hwlib::xy(location.x, location.y +4));
    w.write(hwlib::xy(location.x, location.y ));
    w.write(hwlib::xy(location.x-1, location.y +3));
    w.write(hwlib::xy(location.x+1, location.y +3));
    
    }