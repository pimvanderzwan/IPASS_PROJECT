#ifndef SCHERMOBJECT_HPP
#define SCHERMOBJECT_HPP

#include "drawable.hpp"
#include "hwlib.hpp"


//class location;
/// @file

/// \brief
/// class SchermObject ADT.
/// \details
/// class inherits location and window from drawable.
/// clas contains a speed, direction, active and the previous location of the object.

class SchermObject : public drawable {
protected:
    int speed;
    int direction;
    bool active;
    hwlib::xy old_location;



public:
/// \brief
/// constructor initializes a window, location, speed and direction.
/// \details
/// the activity of the object is automatically set to 0.
    SchermObject(hwlib::window & w, const hwlib::xy & location, int speed, int direction):
        drawable( w, location ),
        speed( speed ),
        direction( direction )
        {active = false;
        }
        
        virtual hwlib::xy upper_left_corner();
        virtual hwlib::xy lower_right_corner();
        virtual void draw();
        virtual void draw_inverse();
        virtual void update();
        

        bool is_active();
        void activate();
        void deactivate();
        
        hwlib::xy get_location();
        void set_location(hwlib::xy location);        
        
        bool overlaps(  SchermObject & other );
        bool determine_interaction(SchermObject& rhs);        

        //virtual void persona(persona_lijst);
}; 
#endif