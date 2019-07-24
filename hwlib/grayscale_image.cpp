#include "grayscale.hpp"


/// \brief
/// Oled grayscale get function.
/// \details
/// This function retuns 1 byte which represents two pixels on the
/// screen. The LS part is on the left (even pixel), the MS part is on the right (odd pixel)


hwlib::Grayscale  hwlib::Grayscale_image::get_implementation( xy pos ) const { // returns 1 byte (for 2 pixels)
        return ( data[pos.x + ( pos.y / 2 ) * size.x]);
}


 
/// \brief
/// Grayscale operator[].
/// \details
/// Check if the position requested is outside of the size of the image.

hwlib::Grayscale hwlib::Grayscale_image::operator[]( xy pos ) const {
      return (
               ( pos.x >= 0 ) && ( pos.x < size.x )
            && ( pos.y >= 0 ) && ( pos.y < size.y )
         )
            ? get_implementation( pos )
            : Grayscale(0x00);
   }
