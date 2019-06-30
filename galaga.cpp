#include "galaga.hpp"
#include "player.hpp"

void Galaga::initialize(){

    //add_schermObject(player3, 2);
    
        //hwlib::cout << "lijst1: "; 
    //for(size_t  i=0;i < 3;i++){ 
        //hwlib::cout << lijst[i]->get_location() << "   ";
    //}
    
}

void Galaga::draw(){
    for(size_t  i=0;i < lijst.size(); i++)
    {
        //hwlib::cout << "  voor draw Galaga" ;
        lijst[i] -> draw();
        //hwlib::wait_ms(50);
    }
    //lijst[0]-> draw();
    //w.flush();
    //hwlib::wait_ms( 200 );   
    //hwlib::cout << "lijst: "; 
    //for(size_t  i=0;i < lijst.size(); i++){ 
        //hwlib::cout << lijst[i]->get_location() << "   ";
    };
    

    //hwlib::cout << " eind draw Galaga" ;   



bool Galaga::update(){
    for(size_t  i=0;i < lijst.size(); i++)
    {
        //hwlib::cout << "  voor draw Galaga" ;
        lijst[i] -> update();
        //hwlib::wait_ms(50);
    }
    //for(auto & j : lijst){
    //    if ()
        
    //    }
        return true;
    }
    

void Galaga::shoot_bullet(){
    
     for(size_t  i=6;i < lijst.size(); i++)
    {
        if (!lijst[i]->is_active()){ //find fist inactive bullet and activate
            lijst[i]->set_location(hwlib::xy(lijst[0]->get_location().x + 4, lijst[0]->get_location().y)); // kopieer de location van de player.
            lijst[i]->activate();
            lijst[i]->update();
            return;
        }
    }
    return;
}
    
    
    

void Galaga::test_function()
{
    hwlib::wait_ms(2000);
    
    }
    
void Galaga::add_schermObject(SchermObject & object, int i)
{
    lijst[i]= &object;
    }  