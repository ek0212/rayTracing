#pragma once

#include "Vec3.h"
#include <iostream>

using Color = Vec3;

/**
 * @brief Writes the color value of a pixel to an output stream.
 * 
 * The `write_color` function converts the color components of a `Color` (which is a `Vec3`) from a floating-point range
 * [0, 1] to an integer range [0, 255] and outputs them as RGB values in a format suitable for image file writing.
 * 
 * @param out The output stream where the color will be written. This is typically a file stream for an image file.
 * @param pixel_color The color value of the pixel to write, represented as a `Color` (alias for `Vec3`).
 */
void write_color(std::ostream& out, const Color& pixel_color) {
    auto r = pixel_color.x();    
    auto g = pixel_color.y();    
    auto b = pixel_color.z();    

    // Translate the [0,1] component values to the byte range [0,255].
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write out the pixel Color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}