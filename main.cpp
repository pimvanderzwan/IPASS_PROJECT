#include "hwlib.hpp"
#include "galaga.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "projectiel.hpp"
#include "schermobject.hpp"



class Inputbutton{
private:
    bool state;
    uint8_t arduino;
    
public: 
    
    
    };




int main()
{   
    
    namespace target = hwlib::target;
 
    auto Button_left = hwlib::target::pin_in( hwlib::target::pins::d10);
    auto Button_mid = hwlib::target::pin_in( hwlib::target::pins::d9);
    auto Button_right = hwlib::target::pin_in( hwlib::target::pins::d8);

    auto sck = target::pin_out( target::pins::d3 ); //D0 --> D3
    auto mosi = target::pin_out( target::pins::d4 );  //D1 --> D4
    //auto miso = target::pin_in_dummy( target::pins::miso );  //Not implemented
    auto res = target::pin_out( target::pins::d5 );  // RES
    auto dc = target::pin_out( target::pins::d6 ); //DC
    auto cs = target::pin_out( target::pins::d7 ); //CS  

   
    auto spi_bus = hwlib::spi_bus_bit_banged_sclk_mosi_miso( sck, mosi, hwlib::pin_in_dummy );
    //auto font    = hwlib::font_default_8x8();
    auto oled = hwlib::glcd_oled_spi_128x64_direct_res_dc_cs( spi_bus, res, dc, cs ); 
    // auto display = hwlib::terminal_from( oled, font ); 
     
    oled.clear();
    
    std::array<SchermObject *, 10> lijst;   

    Player player (oled, hwlib::xy((uint16_t)60,(uint16_t)60), 0, 0);
    player.activate();
    lijst[0]= &player;
    //add_schermObject(player, 0);
    
    
    Enemy enemy1 (oled, hwlib::xy((uint16_t)12,(uint16_t)1), 8, 0);
    enemy1.activate();
    lijst[1] =&enemy1;
    Enemy enemy2 (oled, hwlib::xy((uint16_t)37,(uint16_t)1), 6, 0);
    enemy2.activate();
    lijst[2] =&enemy2;
    Enemy enemy3 (oled, hwlib::xy((uint16_t)62,(uint16_t)1), 4, 0);
    enemy3.activate();
    lijst[3] =&enemy3;
    Enemy enemy4 (oled, hwlib::xy((uint16_t)87,(uint16_t)1), 7, 0);
    enemy4.activate();
    lijst[4] =&enemy4;
    Enemy enemy5 (oled, hwlib::xy((uint16_t)112,(uint16_t)1), 3, 0);
    enemy5.activate();
    lijst[5] =&enemy5;
    
    Projectiel bullet1(oled, hwlib::xy((uint16_t)112,(uint16_t)1), 3, 0);
    lijst[6] =&bullet1;
    Projectiel bullet2(oled, hwlib::xy((uint16_t)112,(uint16_t)1), 3, 0);
    lijst[7] =&bullet2;
    Projectiel bullet3(oled, hwlib::xy((uint16_t)112,(uint16_t)1), 3, 0);
    lijst[8] =&bullet3;
    Projectiel bullet4(oled, hwlib::xy((uint16_t)112,(uint16_t)1), 3, 0);
    lijst[9] =&bullet4;
 
   /* Enemy enemy6 (oled, hwlib::xy((uint16_t)60,(uint16_t)10), 1, 0);
    enemy6.activate();
    lijst[6] =&enemy6;
    Enemy enemy7 (oled, hwlib::xy((uint16_t)70,(uint16_t)10), 1, 0);
    enemy7.activate();
    lijst[7] =&enemy7;
    Enemy enemy8 (oled, hwlib::xy((uint16_t)80,(uint16_t)10), 5, 0);
    enemy8.activate();
    lijst[8] =&enemy8;
    Enemy enemy9 (oled, hwlib::xy((uint16_t)90,(uint16_t)10), 2, 0);
    enemy9.activate();
    lijst[9] =&enemy9;*/
    
 
    
    Galaga game(oled, lijst);
    game.initialize();
    game.draw();

    size_t begin_tijd = hwlib::now_us()/1000; //dit is de begin tijd in milliseconden.
    size_t actuele_tijd;
    
    for(;;){
        Button_left.refresh();
        Button_mid.refresh();
        Button_right.refresh();
        
        
        auto bu_left = Button_left.read();
        auto bu_mid = Button_mid.read();
        auto bu_right = Button_right.read();
        actuele_tijd = hwlib::now_us()/1000; // dit is de actuele tijd in milliseconden.
        
        if(actuele_tijd - begin_tijd > 200){  // na een verloop van 50 milliseconden update het scherm.
            begin_tijd = actuele_tijd;
            game.update();

        }
        //oled.clear();
        //game.draw();

        
        if (bu_left == 1){
            player.move_left();
            //game.draw();
                /*uint16_t i = 10;
                while (i < 118){
                oled.write( hwlib::xy( i, 30 ) );
                  hwlib::wait_ms( 10 );
                i = i+2;
                // oled.clear();
                }*/
            }
        if (bu_mid == 1){
                game.shoot_bullet();
                //hwlib::cout << milliseconden << "\n";
            }
            
        if (bu_right == 1){
                player.move_right();
                //game.draw();
        }
}
}
