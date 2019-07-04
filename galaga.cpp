#include "galaga.hpp"
#include "player.hpp"


/// \@file

/// \brief
/// A loop function
/// \details
/// This function calls on the draw function of the object in the array.

void Galaga::draw(){
    for(size_t  i = 0; i < lijst.size(); i++)
    {
        lijst[i] -> draw();
    }

}

/// \brief
/// A loop function
/// \details
/// This function calls on the update function of the objects in the array.

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

/// \brief
/// A loop function for determining an interaction.
/// \details
/// This function checks if there has been any interaction between objects.
/// The function checks on index 1 through 6 if they are active and if there was an interaction between the player.
/// Index 1 to 6 is used because the enemies are placed here.
/// The function also checks on index 6 through 26 if they are active and if there was an interaction between and enemy and a projectile.
/// if and enemy is killed it deactivates the bullet and the enemy.
/// the enemy is reactivated on a random position 5 steps removed between its first location.
bool Galaga::determine_interaction(){
// Interaction between Player and enemies
for(size_t j = 1; j < 6; j++){
            if (lijst[j]->is_active() and lijst[0] -> determine_interaction( *lijst[j] )) // Player is killed
            {
               //hwlib::cout << "player killed\n"; 
               game_over();//
               return true; // to flag that the player is killed
            }
}

// Interaction between Enemies and projectielen.
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
                    int r = (rand() %10)-5; //Generate random nummer (-5 ... 5)
                    lijst[i]->set_location(hwlib::xy(lijst[0]->get_location().x+r,0)); // set new location for killed enemy
                    return false;
                }
           }
         }
    }
    return false;
}

/// \brief
/// A loop function for shooting a projectile.
/// \details
/// This function checks if there are any is in active bullet on index 6 through 26 if a bullet inactive it is set active.
/// making the bullet active 'shoots' the projectile.

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
/// \brief
/// A loop function for ening the game.
/// \details
/// This function deactivates al the object in the array.
/// The function then opens a terminal and displays game over and the amount of enemies killed.

void Galaga::game_over(){
    // change toestand naar game over
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

/// \brief
/// A function to show the start.
/// \details
/// This function checks if there has been any interaction between objects.

void Galaga::game_begin(){
    auto font    = hwlib::font_default_8x8();
    auto display = hwlib::terminal_from( w, font ); 
    display 
            << "\t0202"
            << "Galaga on Due" << "\n" 
            << "door Pim" ;   
    w.clear();
}   

/// \brief
/// Adding function
/// \details
/// This function adds an object to the array at a specified index.

void Galaga::add_schermObject(SchermObject & object, int i){
    lijst[i]= &object;
    }  
    