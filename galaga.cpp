#include "galaga.hpp"
#include "player.hpp"

void Galaga::initialize(){

}

void Galaga::draw(){
    for(size_t  i = 0; i < lijst.size(); i++)
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
}


bool Galaga::update(){
    for(size_t  i=0;i < lijst.size(); i++)
    {   
        {
        //hwlib::cout << "  voor draw Galaga" ;
        lijst[i] -> update();
        //hwlib::wait_ms(50);
        }

    }
    return true;
}
    
void Galaga::determine_interaction(){

for (size_t i = 0; i < lijst.size(); i++){
         for(size_t j = 0; j < lijst.size(); j++){
            if (i==0 and j!=0 and lijst[i] -> determine_interaction( *lijst[j] )) // Player is killed
            {
               hwlib::cout << "player killed\n"; 
               game_over();//
               return; 
            }
            else {
                if (i > 0 and i < 6 and i != j and lijst[i] -> determine_interaction( *lijst[j])) // enemy is killed
                {
                    lijst[i]->deactivate(); //enemy
                    lijst[j]->deactivate(); // bullet
                    hwlib::cout << "enemy killed " << i << "\n"; // 
                    hwlib::cout << "projectiel gone " << j << "\n";
                }
           }
        }
    }
}

void Galaga::shoot_bullet(){
     for (size_t i = 0; i < lijst.size(); i++)
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
    
void Galaga::game_over(){
    // verander toestand naar game over
     for (size_t i = 0; i < lijst.size(); i++)
    {
        if (!lijst[i]->is_active()){
            lijst[i]->deactivate();
        }

    }
    auto font    = hwlib::font_default_8x8();
    auto display = hwlib::terminal_from( w, font );
    w.clear(); 
    display 
            << "game over" << hwlib::flush;   // put game end on screen
}   
 
void Galaga::game_begin(){
    auto font    = hwlib::font_default_8x8();
    auto display = hwlib::terminal_from( w, font ); 
    display 
            << "Galaga on Due" 
         << "\n" << "door Pim" << hwlib::flush;   
    w.clear();
}   


void Galaga::add_schermObject(SchermObject & object, int i){
    lijst[i]= &object;
    }  
    