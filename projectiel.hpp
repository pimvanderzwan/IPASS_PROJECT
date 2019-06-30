#ifndef PROJECTIEL_HPP
#define PROJECTIEL_HPP

#include "schermobject.hpp"
#include "hwlib.hpp"

class Projectiel : public SchermObject{
private:
    int toestand;
public:

    Projectiel(hwlib::window & w, const hwlib::xy & location, int speed, int direction):
     SchermObject(w, location, speed, direction)
    {}
    void draw() override;
    void update() override;
    void persona(hwlib::xy location) override;
    void inverse_draw();
    };


#endif