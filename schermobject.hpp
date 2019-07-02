#ifndef SCHERMOBJECT_HPP
#define SCHERMOBJECT_HPP

#include "drawable.hpp"
#include "hwlib.hpp"

class location;
class SchermObject : public drawable {
protected:
    int speed;
    int direction;
    bool active;
    hwlib::xy old_location;



public:
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