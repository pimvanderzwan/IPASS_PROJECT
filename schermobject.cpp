#include "schermobject.hpp"


void SchermObject::draw(){
    //hwlib::cout << "hello";
    
    }
bool SchermObject::interaction(SchermObject& rhs){
    if(location == rhs.get_location()){
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
    return true;
    };
    
void SchermObject::persona(hwlib::xy location){
    }