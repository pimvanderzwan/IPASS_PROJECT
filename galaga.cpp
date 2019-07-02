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
    
bool Galaga::determine_interaction(){
// Player and enemies
for(size_t j = 1; j < 6; j++){
            if (lijst[j]->is_active() and lijst[0] -> determine_interaction( *lijst[j] )) // Player is killed
            {
               //hwlib::cout << "player killed\n"; 
               game_over();//
               return true; // to flag that the player is killed
            }
}

//Enemies and projectielen
for (size_t i = 1; i < 6; i++){
        if (lijst[i]->is_active()){
         for(size_t j = 6; j < 26; j++){
                if (lijst[j]->is_active() and lijst[i] -> determine_interaction( *lijst[j])) // enemy is killed
                {
                    score=score+1;
                    lijst[i]->deactivate(); //enemy
                    lijst[i]->draw_inverse();
                    lijst[j]->deactivate(); // bullet
                    lijst[j]->draw_inverse();
                    //hwlib::cout << "enemy killed " << i << "\n"; // 
                    //hwlib::cout << "projectiel gone " << j << "\n";
                    int r = (rand() %10)-5; //Generate random nummer (-5 ... 5)
                    //hwlib::cout << "random number: " << r << "\n";
                    lijst[i]->set_location(hwlib::xy(lijst[0]->get_location().x+r,0)); // set new location for killed enemy
                    return false;
                }
           }
         }
    }
    return false;
}

void Galaga::shoot_bullet(){
     for (size_t i = 6; i < lijst.size(); i++) //bullets only
    {
  
        if (!lijst[i]->is_active()){ //find fist inactive bullet and activate
            lijst[i]->set_location(hwlib::xy(lijst[0]->get_location().x + 4, lijst[0]->get_location().y)); // kopieer de location van de player.
            lijst[i]->activate();
            //hwlib::cout << "shoot bullet " << i << "location: " <<  lijst[i]->get_location() << "\n ";
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
    display //
            << "\t0302"
            << "game over \n"   // put game end on screen
            << "score: " << score << " enemies! ";
}   
 
void Galaga::game_begin(){
    auto font    = hwlib::font_default_8x8();
    auto display = hwlib::terminal_from( w, font ); 
    display 
            << "\t0202"
            << "Galaga on Due" << "\n" 
            << "door Pim" ;   
    w.clear();
}   


void Galaga::add_schermObject(SchermObject & object, int i){
    lijst[i]= &object;
    }  
    