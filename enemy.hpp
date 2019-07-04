#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "schermobject.hpp"


/// \@file

/// \brief
/// Enemy class derived from SchermObject
/// \details
/// Inherits window, location, speed and direction from Schermobject.


class Enemy : public SchermObject{
private:
public:
    
    /// \brief
    /// Enemy constructor
    /// \details
    /// Constructs an enemy at a location with a speed and a direction.

    Enemy(hwlib::window & w, const hwlib::xy & location, int speed, int direction):
        SchermObject(w, location, speed, direction)
    
    {}
    
    void draw () override;
    void draw_inverse();
    void update () override;
    void move_right();
    void move_left();
    bool determine_interaction(SchermObject& rhs);

    hwlib::xy upper_left_corner() override;
    hwlib::xy lower_right_corner() override;
    
    };


#endif