#ifndef GALAGA_HPP
#define GALAGA_HPP


#include "schermobject.hpp"
#include "hwlib.hpp"
#include <array>
#include <stdlib.h>


/// @file

/// \brief
/// class Galaga
/// \details
/// This is a class wich contains an array with al the object that can be seen on the screen.
/// This class is essentialy the base of the game. 
/// It starts the game and ends the game.
/// It runs through the array and updates and draws the game, the responsibility of drawing and updating is done by each object itself. 
class Galaga{
private:

    hwlib::window & w;
    bool toestand;
    //std::vector<SchermObject> lijst;
    std::array<SchermObject *, 26> lijst;
    int score=0;


public:
   /// \brief
   /// A construct with just a window.
   /// \details
   /// A useles constructor
    Galaga(hwlib::window & w):
    w(w)
    {
        
    }

   /// \brief
   /// Constructor containing the window and the array.
   /// \details
   /// This constructor initializes a window and an array containing the objects for on screen. 
   /// the standard amount of object is now 26, this is the arduino due doesn't support a vector so there has to be a pre determined set of objects.
    Galaga(hwlib::window & w, std::array<SchermObject *, 26> lijst):
    w ( w ), lijst( lijst )
    {
        }
    /// \brief
   /// Destructor of the Galaga class.
   /// \details
   /// no specifics.
    ~Galaga()
    {}
    
    
    void draw();
    bool update();
    void shoot_bullet();
    void add_schermObject(SchermObject & object, int i);
    bool determine_interaction();
    void game_over();
    void game_begin();
    
    void * operator new(std::size_t n)
    {
        void * const p = std::malloc(n);
        // handle p == 0
        return p;
    }

    void operator delete(void * p) // or delete(void *, std::size_t)
    {
        std::free(p);
    }
};



#endif