#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "schermobject.hpp"


class Enemy : public SchermObject{
private:
    int direction_x_of_y;
public:
    
    Enemy(hwlib::window & w, const hwlib::xy & location, int speed, int direction):
        SchermObject(w, location, speed, direction)
    
    {
    }
    
    void draw () override;
    void draw_inverse();
    void update () override;
    void move_right();
    void move_left();
//    void persona(hwlib::xy location) override;
    
    
    };


#endif