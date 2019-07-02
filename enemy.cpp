#include "enemy.hpp"

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
        //hwlib::cout << "enemy activated " << location << "\n";
        //location.x = 
        }

}
bool Enemy::determine_interaction(SchermObject& rhs){

    return false;
    
    }

    
/*void Enemy::persona(hwlib::xy location) {
    w.write(hwlib::xy(location.x, location.y +1 ));
    w.write(hwlib::xy(location.x, location.y +2 ));
    w.write(hwlib::xy(location.x, location.y +3));
    w.write(hwlib::xy(location.x, location.y +4));
    w.write(hwlib::xy(location.x, location.y ));
    w.write(hwlib::xy(location.x-1, location.y +3));
    w.write(hwlib::xy(location.x+1, location.y +3));
    
    } */ 
    
 //   void Enemy::persona(){}
 
hwlib::xy Enemy::upper_left_corner(){
    return hwlib::xy(location.x-1, location.y+4);
}

hwlib::xy Enemy::lower_right_corner(){
    return hwlib::xy(location.x+1, location.y);
}