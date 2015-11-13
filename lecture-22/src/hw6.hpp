#ifndef ASSIGNMENT6_HPP
#define ASSIGNMENT6_HPP

#include <string>

#include <boost/multi_array.hpp>

/* Reads a grayscale JPEG image and returns the contents in the Boost MultiArray */
void ReadGrayscaleJPEG(std::string filename, boost::multi_array<unsigned char,2> &img);

/* Writes the contents of a Boost MultiArray to a grayscale JPEG image. */
void WriteGrayscaleJPEG(std::string filename, boost::multi_array<unsigned char,2> &img);

#endif /* ASSIGNMENT6_HPP */
