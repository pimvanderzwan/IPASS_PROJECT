#define CATCH_CONFIG_MAIN 
#include "window.hpp"
#include "schermobject.hpp"
#include "catch.hpp"

window w(hwlib::xy(128,64));

TEST_CASE( "overlap function, one parameter" ){
   SchermObject a (w, hwlib::xy((uint16_t)10,(uint16_t)10), 1, 0);
   SchermObject b (w, hwlib::xy((uint16_t)5, (uint16_t)15), 1, 0);
   REQUIRE( a.overlaps(b));   
}
