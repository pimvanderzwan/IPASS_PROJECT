#include "schermobject.hpp"


void SchermObject::draw(){
    //hwlib::cout << "hello";
    }
void SchermObject::draw_inverse(){}



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


bool SchermObject::overlaps( SchermObject & other ){
    
    //https://www.geeksforgeeks.org/find-two-rectangles-overlap/
    
    if (upper_left_corner().x > other.lower_right_corner().x || other.upper_left_corner().x > lower_right_corner().x){return false;}    
    if (upper_left_corner().y < other.lower_right_corner().y || other.upper_left_corner().y < lower_right_corner().y){return false;}
    
    return true;
}