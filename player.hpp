#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "schermobject.hpp"
#include "hwlib.hpp"


/// @file

/// \brief
/// Player class derived from SchermObject.
/// \details
/// Inherits window, location, speed and direction from Schermobject.


class Player : public SchermObject {
private:

public:

    /// \brief
    /// Player constructor.
    /// \details
    /// Constructs a player at a location with a speed and.
    Player(hwlib::window & w, const hwlib::xy & location, int speed, int direction):
        SchermObject(w, location, speed, direction)
    {}
    
    hwlib::xy upper_left_corner() override;
    hwlib::xy lower_right_corner() override;
    
    void draw () override;
    void draw_inverse();
    void update () override;
    void move_right();
    void move_left();
    void set_bitmap(unsigned char d0, unsigned char d1,
                    unsigned char d2, unsigned char d3,
                    unsigned char d4, unsigned char d5,
                    unsigned char d6, unsigned char d7);
};



#endif