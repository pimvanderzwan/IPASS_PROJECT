#include "glcd_oled_i2c_128x128_direct.hpp"

/// \@file

/// \brief
/// I2C bus clear function.
/// \details
/// This function clears the buffer.


void hwlib::glcd_oled_i2c_128x128_direct::clearBuffer()
   {
	for(int i = 0; i < 8192; i++){
		if (buffer[i]) { // 
			buffer[i] = 0;
		}
	}
   }

/// \brief
/// OLED write function.
/// \details
/// This function converts a color to a greyscale wich is a byte and writes it on the OLED.
void hwlib::glcd_oled_i2c_128x128_direct::write_implementation( 
      xy pos, 
      color col 
        )  {

      write_implementation (pos, Grayscale(col)); 
   }      


/// \brief
/// Oled grayscale 4 bit write.
/// \details
/// One Pixel on the OLED represents 4 bits so by writing a byte you write two pixel.
/// This function writes the least significant bits of a given byte.
/// If the location of the x coordinat is even the least significant byte is shifted 
/// to the more significant byte.
/// If the x is uneven no shifting is required.
/// the byte is then written 

void hwlib::glcd_oled_i2c_128x128_direct::write_implementation( 
      xy pos, 
      Grayscale grayscale // only use the LS 4-bit
   )  { 
      int a = (pos.x/2 + ( pos.y *64 )); // position in the buffer, 1 byte contains 2 pixels
 
         if((pos.x%2) == 0){ //If this is an even pixel, and therefore needs shifting to the more significant pixel
            buffer[ a ] = (buffer[ a ] & 0x0f) | (grayscale.grayscale << 4); // Even pixel
        } else {
       buffer[ a ]= (buffer[ a ] & 0xf0) | (grayscale.grayscale ); //  Odd pixel
        }
      pixels_byte_write( xy( pos.x/2, pos.y ), buffer[ a ] );   

   }   



/// \brief
/// OlED pixel write.
/// \details
/// This function writes a Grayscale to the pixel at location pos.
/// If the location is outside the window
/// the call has no effect.


void hwlib::glcd_oled_i2c_128x128_direct::write( 
      xy pos, 
      Grayscale grayscale
   ){
      if( ( pos.x >= 0 ) && ( pos.x < size.x ) 
        && ( pos.y >= 0 ) && ( pos.y < size.y ) 
      ){

         write_implementation( pos, grayscale );
      }   
   }   

/// \brief
/// OLED image write.
/// \details
/// This function writes a greyscale image on a location.

void hwlib::glcd_oled_i2c_128x128_direct::write( 
      xy pos, 
      const Grayscale_image & img){          
      for( const auto p : all( img.size ) ){ 
         write( pos + p, img[ p ] );
      }
   }  
  


/// \brief
/// Oled write function.
/// \details
/// The function writes a grayscale pixel (by default) black (=GS15) on given location.

void hwlib::glcd_oled_i2c_128x128_direct::write( 
    xy pos 
   ){
      write( pos, Grayscale(0xFF) );
   }



/// \brief
/// OLED write function.
/// \details
/// function writes and image on given location.
void hwlib::glcd_oled_i2c_128x128_direct::write( 
      xy pos, 
      const image & img
   ){          
      for( const auto p : all( img.size ) ){ // 20190703 Fixed by Pim van der Zwan,use img.size instead of size of entire window.
         write( pos + p, img[ p ] );
   }
   }


/// \brief
/// OLED clear function.
/// \details
/// Function sets the write zone from location 0 to the size of the screen.
/// The function then sets every pixel to black.

void hwlib::glcd_oled_i2c_128x128_direct::clear()  { // TODO, this should be more efficient?
      const uint8_t d = ( background == white ) ? 0xFF : 0x00;
      command( ssd1327_commands::set_column_address,  0,  63 );
      command( ssd1327_commands::set_row_address,     0,  127 ); 
      auto t = bus.write( address );
      t.write( ssd1327_data_prefix );
      for( uint_fast16_t x = 0; x < sizeof( buffer ); ++x ){                
	      buffer[ x ] = d;
		   t.write( d );
      }   

     cursor = xy( 255, 255 );
   }
/// \brief
/// OLED flush function.
/// \details
/// This function flushes the 
   
void hwlib::glcd_oled_i2c_128x128_direct::flush()  {}  


