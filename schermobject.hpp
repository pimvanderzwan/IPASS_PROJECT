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
    int new_location_x;
    int new_location_y;
public:
    SchermObject(hwlib::window & w, const hwlib::xy & location, int speed, int direction):
        drawable( w, location ),
        speed( speed ),
        direction( direction )
        {active = false;
        new_location_x = location.x;
        new_location_y = location.y;
        }
        
        virtual void draw();
        virtual void update();
        bool determine_interaction(SchermObject& rhs);
        bool is_active();
        void activate();
        void deactivate();
        hwlib::xy get_location();
        void set_location(hwlib::xy location);        
        bool within( int x, int a, int b );
        bool overlaps( const SchermObject & other );
        virtual void persona(hwlib::xy location);
}; 
#endif