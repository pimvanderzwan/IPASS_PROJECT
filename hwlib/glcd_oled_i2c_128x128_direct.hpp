#ifndef GLCD_OLED_I2C_128X128_direct_hpp
#define GLCD_OLED_I2C_128X128_direct_hpp

#include "ssd1327_i2c.hpp"
#include "grayscale.hpp"
#include "grayscale_image.hpp"

/// \@file


namespace hwlib {


/// \brief
/// OLED direct class for the i2c connected 128x128 Grayscale OLED based on ssd1327
/// \details
/// This class writes to the OLED window directly (without writing and flushing a buffer).
/// This class contains a buffer array (size 8192) and a constant size.
/// The class also contains several overwritten write functions due to name hiding
/// When writing a pixel one byte is written to the OLED (containing 2-pixel information)
/// TODO: make sure that a byte is not written twice to the OLED when writing a consecutive area



class glcd_oled_i2c_128x128_direct : public ssd1327_i2c, public window {
private:

   static auto constexpr wsize = xy( 128, 128 );

   uint8_t buffer[ wsize.x * wsize.y / 2 ]; // total 128*128/2 = 8192 Data bytes
   void clearBuffer();
   void write_implementation( xy pos, color col ) override;
   void write_implementation( xy pos, Grayscale grayscale); 
public:
   
	
   /// \brief
   /// OLED direct constructor.
   /// \details
   /// constructor provided the i2c channel and an address to send data to the ssd1327 (default = 0x3C).
   glcd_oled_i2c_128x128_direct( i2c_bus & bus, uint_fast8_t address = 0x3C ): 
      ssd1327_i2c( bus, address ),
      window( wsize, white, black ) 
   
{
    bus.write( address ).write( 
         ssd1327_initialization, 
         sizeof( ssd1327_initialization ) / sizeof( uint8_t ) );
    clearBuffer();
    wait_ms( 300 );
}

   void write( xy pos, Grayscale grayscale);
   void write( xy pos, const Grayscale_image & img);
   void write( xy pos );
   void write( xy pos, const image & img);
   void clear() override;
   void flush() override;
};

};


#endif 

