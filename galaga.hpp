#ifndef GALAGA_HPP
#define GALAGA_HPP


#include "schermobject.hpp"
#include "hwlib.hpp"
#include <array>
#include <stdlib.h>



class Galaga{
private:

    hwlib::window & w;
    bool toestand;
    //std::vector<SchermObject> lijst;
    std::array<SchermObject *, 26> lijst;


public:

    Galaga(hwlib::window & w):
    w(w)
    {
        
    }

    
    Galaga(hwlib::window & w, std::array<SchermObject *, 26> lijst):
    w ( w ), lijst( lijst )
    {
        }
        
    ~Galaga()
    {}
    
    void initialize();
    void draw();
    bool update();
    void shoot_bullet();
    void test_function();
    void add_schermObject(SchermObject & object, int i);
    void determine_interaction();
    void time_function();
    void game_over();
    
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