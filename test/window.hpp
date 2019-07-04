// example:
// declaration of a window class

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "hwlib.hpp"

class window :public hwlib::window {   
public:
    window( hwlib::xy size):
      hwlib::window( size ){}
      
 void clear() override{
}

 void flush() override{
}


 void write_implementation( 
      hwlib::xy pos, 
      hwlib::color col
   ) override {
   }
};
   
#endif // WINDOW_HPP
