#include "OLED_SSD_1327.cpp"



/// \brief
/// Oled grayscale get function.
/// \details
/// This function retuns 1 byte which represents two pixel on the
/// screen.


Grayscale_image::Grayscale get_implementation( xy pos ) const { // returns 1 byte (for 2 pixels)
        return ( data[pos.x + ( pos.y / 2 ) * size.x]);
}

/// \brief
/// OLED Grayscale image function.
/// \details
/// This function copies a given array in to the array of the class.

Grayscale_image::Grayscale_image(uint8_t *data_constructor
   ) 
   {size = xy( 8, 8 );
    for (int i=0;i<32;i++) 
    {
       data[i] = data_constructor[i];
    }
 }
 
/// \brief
/// Grayscale operator[].
/// \details
/// Check if a lcoation is outside of the screen.


Grayscale_image::Grayscale operator[]( xy pos ) const {
      return (
               ( pos.x >= 0 ) && ( pos.x < size.x )
            && ( pos.y >= 0 ) && ( pos.y < size.y )
         )
            ? get_implementation( pos )
            : Grayscale(0x00);
   }

/// \brief
/// Oled get function.
/// \details
/// This function return one byte on a given location.
/// this byte represent two bytes on the screen.


Grayscale_image_128x128::Grayscale get_implementation( xy pos ) const { // returns 1 byte (for 2 pixels)
        return ( data[pos.x + ( pos.y / 2 ) * size.x]);
            }

/// \brief
/// I2C bus send command function.
/// \details
/// Send command with out data to the OLED.
/// By sending a command prefix for data, but not sending data.

void ssd1327_i2c::command( ssd1327_commands c ){
      uint8_t data[] = { 
         ssd1327_cmd_prefix, (uint8_t) c 
      };
      bus.write( address ).write( 
         data, 
         sizeof( data ) / sizeof( uint8_t ) 
      );      
   } 
   


/// \brief
/// I2C bus send command and data function.
/// \details
/// Send command with data to the OLED.
/// By sending a command prefix for data and sending one byte of data.

 void ssd1327_i2c::command( ssd1327_commands c, uint8_t d0 ){
      uint8_t data[] = { 
         ssd1327_cmd_prefix, (uint8_t) c, 
         ssd1327_cmd_prefix, d0
      };
      bus.write( address ).write( 
         data, 
         sizeof( data ) / sizeof( uint8_t ) 
      );    
   } 	

/// \brief
/// I2C bus send command and data function.
/// \details
/// Send command with data to the OLED.
/// By sending a command prefix for data and sending two bytes of data.

void ssd1327_i2c::command( ssd1327_commands c , uint8_t d0, uint8_t d1 ){
      uint8_t data[] = { 
         ssd1327_cmd_prefix, (uint8_t) c, 
         ssd1327_cmd_prefix, d0, 
         ssd1327_cmd_prefix, d1 
      };
      bus.write( address ).write( 
         data, 
         sizeof( data ) / sizeof( uint8_t ) 
      );     
   } 	


/// \brief
/// I2C bus write function.
/// \details
/// This function sets the write zone column x and row y.
/// And writes a byte in the write zone.

void ssd1327_i2c::pixels_byte_write( xy location, uint8_t d ){
       // evt schuiven indien even pixel
       
       //zet de write zone (
       //write pixel     
       // What to do with the bytes we need to write
      if( location != cursor ){ // To avoid rewriting the commands over and over
         command( ssd1327_commands::set_column_address,  location.x, 63 );
         command( ssd1327_commands::set_row_address,     location.y, 127 ); 
         cursor = location;
      }   

      uint8_t data[] = { ssd1327_data_prefix, d };
      bus.write( address ).write( 
         data, 
         sizeof( data ) / sizeof( uint8_t ) 
      ); 
      cursor.x++;  
    
   }




/// \brief
/// I2C bus clear function.
/// \details
/// This function clears the buffer.


void glcd_oled_i2c_128x128_direct::clearBuffer()
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
/// This function converts a color to a greyscale and writes it on the OLED.
void glcd_oled_i2c_128x128_direct::write_implementation( 
      xy pos, 
      color col 
        ) override {

      write_implementation (pos, Grayscale(col)); 
   }      


/// \brief
/// Oled grayscale 4 bit write.
/// \details
/// This function writes the least significant bits of a given byte.
/// If the location of the x coordinat is even the least significant byte is shifted 
/// to the more significant byte.
/// If the x is uneven no shifting is required.
/// the byte is then written 

void glcd_oled_i2c_128x128_direct::write_implementation( 
      xy pos, 
      Grayscale grayscale // only use the LS 4-bit
   )  { 
      int a = (pos.x/2 + ( pos.y *64 )); // position in the buffer
 
         if((pos.x%2) == 0){//If this is an even pixel, and therefore needs shifting 				      to the more significant pixel

            buffer[ a ] = (buffer[ a ] & 0x0f) | (grayscale.grayscale << 4); // Even

        } else {
       buffer[ a ]= (buffer[ a ] & 0xf0) | (grayscale.grayscale ); //  Odd
        }
      pixels_byte_write( xy( pos.x/2, pos.y ), buffer[ a ] );   

   }   






/// \brief
/// OlED pixel write.
/// \details
/// This function writes a the Grayscale to the pixel at location pos.
/// If the location is outside the window
/// the call has no effect.


void glcd_oled_i2c_128x128_direct::write( 
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

void glcd_oled_i2c_128x128_direct::write( 
      xy pos, 
      const Grayscale_image & img){          
      for( const auto p : all( img.size ) ){ 
         write( pos + p, img[ p ] );
      }
   }  
  


/// \brief
/// Oled write function.
/// \details
/// The function writes a grayscale pixel black on given location.

void glcd_oled_i2c_128x128_direct::write( 
    xy pos 
   ){
      write( pos, Grayscale(0xFF) );
   }



/// \brief
/// OLED write function.
/// \details
/// function writes and image on given location.
void glcd_oled_i2c_128x128_direct::write( 
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

void glcd_oled_i2c_128x128_direct::clear() override { // Dit moet anders
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
   
void glcd_oled_i2c_128x128_direct::flush() override {}  


