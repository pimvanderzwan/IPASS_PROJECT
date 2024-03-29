#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "hwlib.hpp"
/// @file

/// \brief
/// class drawable ADT.
/// \details
/// class contains a window and a location.

class drawable { 
protected:

   hwlib::window & w;
   hwlib::xy location;
   
public:
    /// \brief
    /// constructor...
    /// \details
    /// constructor initializes a window and a location.
   drawable( hwlib::window & w, const hwlib::xy & location ):
      w( w ),
      location( location )
   {}      
   
   virtual void draw() = 0;
   virtual void update(){}
   hwlib::xy get_location();
   
};


#endif