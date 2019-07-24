#ifndef GRAYSCALE_IMAGE_128X128_HPP
#define GRAYSCALE_IMAGE_128X128_HPP

/// \@file

namespace hwlib {

/// \brief
/// Grayscale image 128 by 128 class.
/// \details
/// This class creates an image the size of the oled.
/// The class contains an array of bytes (8192 to be precise) and an xy size.
/// The class is used for writing pictures on the oled.
/// This is done by first turning the picture to 128x128 size and putting the bytes in a char array.

class Grayscale_image_128x128 {
private:

    uint8_t data[ 8192 ];
    
    Grayscale get_implementation( xy pos ) const;
public:
    xy size;
   /// \brief
   /// Grayscale image 128 by 128 constructor.
   /// \details
   /// Constructor set the size 128 by 128.
   /// The Given array is put in to the member array.
   Grayscale_image_128x128(uint8_t *data_constructor
   ) 
   {size = xy( 128, 128 );
    for (int i=0;i<8192;i++) 
    {
       data[i] = data_constructor[i];
    }
 }

};

};

#endif

