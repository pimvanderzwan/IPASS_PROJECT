#include "schermobject.hpp"


void SchermObject::draw(){
    //hwlib::cout << "hello";
    
    }
bool SchermObject::determine_interaction( SchermObject& rhs ){
    if(overlaps( rhs )){
        //hwlib::cout << "hit \n";
        return true;
        }
    else{
        return false;
        }
    
    }
    
void SchermObject::update(){
    //hwlib::cout << "hello";
    }
    
bool SchermObject::is_active(){
    return active;
}

void SchermObject::activate(){
    active = true;
}


void SchermObject::deactivate(){
    active = false;
}


hwlib::xy SchermObject::get_location(){
    return location;
}

void SchermObject::set_location(hwlib::xy rhs){
    location = rhs;
}   
   
bool SchermObject::within( int x, int a, int b ){
    return ( x >= a ) && ( x <= b );

}

bool SchermObject::overlaps( const SchermObject & other ){
    bool x_overlap = within( 
      location.x, 
      other.location.x, 
      other.location.x // + other.size.x
   ) || within( 
      other.location.x, 
      location.x, 
      location.x // + size.x
   );
     
   bool y_overlap = within( 
      location.y, 
      other.location.y, 
      other.location.y // + other.size.y
   ) || within( 
      other.location.y, 
      location.y, 
      location.y //+ size.y
   );
   
   return x_overlap && y_overlap;
}
void SchermObject::persona(hwlib::xy location){
    }