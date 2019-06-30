#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "schermobject.hpp"
#include "hwlib.hpp"
//#include <iostream>

class Player : public SchermObject {
private:
    //bitmap? persona?
    int toestand;
   // hwlib::image_8x8 bitmap; // = hwlib::image_8x8(0x3A3A, 0x3A3A, 0x3A3A, 0x3A3A, 0x3A3A, 0x3A3A, 0x3A3A, 0x3A3A);
    //auto ;
public:

    Player(hwlib::window & w, const hwlib::xy & location, int speed, int direction):
        SchermObject(w, location, speed, direction)
    
    {}
    
    void draw () override;
    void draw_inverse();
    void update () override;
    void move_right();
    void move_left();
    void persona(hwlib::xy location) override;
    void set_bitmap(unsigned char d0, unsigned char d1,
                    unsigned char d2, unsigned char d3,
                    unsigned char d4, unsigned char d5,
                    unsigned char d6, unsigned char d7);
};



#endif