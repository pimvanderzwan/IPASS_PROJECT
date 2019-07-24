#include "ssd1327_i2c.hpp"

/// \@file


/// \brief
/// I2C bus send command function.
/// \details
/// Send command with out data to the OLED.
/// By sending a command prefix for data, but not sending data.

void hwlib::ssd1327_i2c::command( ssd1327_commands c ){
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

 void hwlib::ssd1327_i2c::command( ssd1327_commands c, uint8_t d0 ){
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

void hwlib::ssd1327_i2c::command( ssd1327_commands c , uint8_t d0, uint8_t d1 ){
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

void hwlib::ssd1327_i2c::pixels_byte_write( xy location, uint8_t d ){
       // evt schuiven indien even pixel
       
       //zet de write zone (zie hieronder)
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




