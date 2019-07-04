#ifndef PROJECTIEL_HPP
#define PROJECTIEL_HPP

#include "schermobject.hpp"
#include "hwlib.hpp"

/// @file

/// \brief
/// class projectiel.
/// \details
/// Inherits window, location, speed and direction from Schermobject.

class Projectiel : public SchermObject{
private:

public:
    
    /// \brief
    /// Projectiel constructor.
    /// \details
    /// Constructs a projectile at a location with a speed and a direction.
    Projectiel(hwlib::window & w, const hwlib::xy & location, int speed, int direction):
     SchermObject(w, location, speed, direction)
    {}
    void draw() override;
    void update() override;
    void draw_inverse();
    
    hwlib::xy upper_left_corner() override;
    hwlib::xy lower_right_corner() override;
    };


#endif