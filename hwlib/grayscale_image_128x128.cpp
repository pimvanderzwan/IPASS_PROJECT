#include "grayscale_image_128x128.hpp"

/// \@file

/// \brief
/// Oled get function.
/// \details
/// This function return one byte on a given location.
/// this byte represent two bytes on the screen.

hwlib::Grayscale hwlib::Grayscale_image_128x128::get_implementation( xy pos ) const { // returns 1 byte (for 2 pixels)
        return ( data[pos.x + ( pos.y / 2 ) * size.x]);
}
