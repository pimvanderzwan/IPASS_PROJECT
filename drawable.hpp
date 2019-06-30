#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "hwlib.hpp"

class drawable {
protected:

   hwlib::window & w;
   hwlib::xy location;
   
public:

   drawable( hwlib::window & w, const hwlib::xy & location ):
      w( w ),
      location( location )
   {}      
   
   virtual void draw() = 0;
   virtual void update(){}
   hwlib::xy get_location();
   
};


#endif