#include "schermobject.hpp"
/// \brief
/// Virtual function draw.
/// \details
/// function meant to draw the shape of the object.
/// this function is virtual and is meant to be overidden by the function in it's subclasses.

void SchermObject::draw(){}

/// \brief
/// Virtual function inverse draw.
/// \details
/// The function meant to remove the shape of the object.
/// This function is virtual and is meant to be overidden by the function in it's subclasses.

void SchermObject::draw_inverse(){}

/// \brief
/// Boolean function for interactions.
/// \details
/// The function returns a if an interaction has been determined between two objects.


bool SchermObject::determine_interaction( SchermObject& rhs ){
    if(overlaps( rhs )){
        //hwlib::cout << "hit \n";
        return true;
        }
    else{
        return false;
        }
    
    }

/// \brief
/// Virtual update function.
/// \details
/// This function is called on to update the activity and location of and object.
/// This is done by overriding the function in it's subclasses.

    
void SchermObject::update(){}

/// \brief
/// Boolean activity fucntion
/// \details
/// Gives the status of the object by returning this bool.
    
bool SchermObject::is_active(){
    return active;
}

/// \brief
/// Void set function
/// \details
/// Sets the activity to active.
    

void SchermObject::activate(){
    active = true;
}

/// \brief
/// Void set function.
/// \details
/// sets the activity to inactive.
    
void SchermObject::deactivate(){
    active = false;

}


/// \brief
/// Get function.
/// \details
/// Gets the location by returning it.

hwlib::xy SchermObject::get_location(){
    return location;
}

/// \brief
/// Void set function.
/// \details
/// sets the location of an object.
    

void SchermObject::set_location(hwlib::xy rhs){
    location = rhs;
}   

/// \brief
/// Boolean overlaps function.
/// \details
/// Gives the if the bounding box is overlapping with and other object bounding box.
/// The location of the boundig box is decided through a chain of responsibility where the size of the bounding boxes is set by subclasses.
    

bool SchermObject::overlaps( SchermObject & other ){
    
    //https://www.geeksforgeeks.org/find-two-rectangles-overlap/
    
    if (upper_left_corner().x > other.lower_right_corner().x || other.upper_left_corner().x > lower_right_corner().x){return false;}    
    if (upper_left_corner().y < other.lower_right_corner().y || other.upper_left_corner().y < lower_right_corner().y){return false;}
    
    return true;
}