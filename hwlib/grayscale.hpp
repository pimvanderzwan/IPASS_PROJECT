#ifndef GRAYSCALE_HPP
#define GRAYSCALE_HPP


/// \@file


namespace hwlib {

/// \brief
/// Grayscale class.
/// \details
/// This class contains a byte.
/// The class is used to convert normal colors to 16 shade grayscales.

class Grayscale{ // based on 4 bits 
public:
    uint8_t grayscale;
    
    /// \brief
    /// Grayscale constructor.
    /// \details
    /// The grayscale is given a color variable col.
    /// The col is then turned into 4 bit value in the grayscale byte.

    Grayscale(uint8_t grayscale):
    grayscale( grayscale )
    {}
    Grayscale(color col)
    {   
        grayscale = ((0.30 * col.red + 0.59 * col.green +  0.11* col.blue)/16);
    }
};

};

#endif
