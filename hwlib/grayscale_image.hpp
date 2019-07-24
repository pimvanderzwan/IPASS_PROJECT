#ifndef GRAYSCALE_IMAGE_HPP
#define GRAYSCALE_IMAGE_HPP

/// \@file

namespace hwlib {

/// \brief
/// Grayscale image class.
/// \details
/// This class is used to create images constisting of 16 pixels.
/// Constains a byte array and a size.
/// every byte represents 2 pixels.

class Grayscale_image { //4 bits, 16 grayscales, 32 bytes
private:

    uint8_t data[ 32 ];
    // is het praktisch om dit zo te doen of is het fout?
    
    Grayscale get_implementation( xy pos ) const;
public:
    xy size;

   /// \brief
   /// Grayscale image constructor.
   /// \details
   /// Constructor sets size to xy 8 by 8 and puts a given array in to the member array.

   Grayscale_image(uint8_t *data_constructor
   ) 
   {size = xy( 8, 8 );
    for (int i=0;i<32;i++) 
    {
       data[i] = data_constructor[i];
    }
 }
   Grayscale operator[]( xy pos ) const;
   
};
};
#endif 
