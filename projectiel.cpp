#include "projectiel.hpp"

void Projectiel::update() {
    if(is_active()){
        old_location = location;
        draw_inverse();
        location.y -= 1;
        if(location.y < 0){ 
            active = false;
            return;
    }  
    //draw();
    }
    
    }

void Projectiel::draw(){
    w.write( hwlib::xy( location ) );
    
    //persona(location);
    
    }
    
void Projectiel::draw_inverse(){
    w.write( hwlib::xy( location ), w.background );
    
    }
    

/*void Projectiel::persona(hwlib::xy location){
    w.write( hwlib::xy(location.x + 1, location.y));
    w.write( hwlib::xy(location.x, location.y +1));
    w.write( hwlib::xy(location.x - 1, location.y));

    } */
    
                        
hwlib::xy Projectiel::upper_left_corner(){
    return location;
}

hwlib::xy Projectiel::lower_right_corner(){
    return location;
}