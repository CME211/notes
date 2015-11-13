#include <sstream>
#include <stdexcept>
#include <string>

#define BOOST_DISABLE_ASSERTS
#include <boost/multi_array.hpp>
#include <jpeglib.h>

#include "hw6.hpp"


void ReadGrayscaleJPEG(std::string filename, boost::multi_array<unsigned char,2> &img)
{
  /* Open the file, read the header, and allocate memory */

  FILE *f = fopen(filename.c_str(), "rb");
  if (not f)
  {
    std::stringstream s;
    s << __func__ << ": Failed to open file " << filename;
    throw std::runtime_error(s.str());
  }

  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr jerr;

  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_decompress(&cinfo);
  jpeg_stdio_src(&cinfo, f);
  jpeg_read_header(&cinfo, true);

  if (cinfo.num_components != 1 or cinfo.jpeg_color_space != JCS_GRAYSCALE)
  {
    std::stringstream s;
    s << __func__ << ": Attempt to read color file " << filename;
    throw std::runtime_error(s.str());
  }

  img.resize(boost::extents[cinfo.image_height][cinfo.image_width]);
  unsigned char *raw_image = img.data();

  /* Decompress JPEG */
 
  jpeg_start_decompress(&cinfo);
  JSAMPROW row_pointer;
  row_pointer = (unsigned char *) malloc(cinfo.output_width*cinfo.num_components);

  unsigned long location = 0;
  while (cinfo.output_scanline < cinfo.image_height)
  {
    jpeg_read_scanlines(&cinfo, &row_pointer, 1);
    for (unsigned int i = 0; i < cinfo.image_width*cinfo.num_components; i++) 
    {
      raw_image[location++] = row_pointer[i];
    }
  }

  jpeg_finish_decompress(&cinfo);
  jpeg_destroy_decompress(&cinfo);
  free(row_pointer);
  fclose(f);
}


void WriteGrayscaleJPEG(std::string filename, boost::multi_array<unsigned char,2> &img)
{
  /* Open the file and write the header */

  FILE *f = fopen(filename.c_str(), "wb");
  if (not f)
  {
    std::stringstream s;
    s << __func__ << ": Failed to open file " << filename;
    throw std::runtime_error(s.str());
  }

  struct jpeg_compress_struct cinfo;
  struct jpeg_error_mgr       jerr;
 
  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_compress(&cinfo);
  jpeg_stdio_dest(&cinfo, f);

  auto shape             = img.shape();
  cinfo.image_width      = (unsigned int)shape[1];
  cinfo.image_height     = (unsigned int)shape[0];
  cinfo.input_components = 1;
  cinfo.in_color_space   = JCS_GRAYSCALE;

  jpeg_set_defaults(&cinfo);
  jpeg_set_quality (&cinfo, 95, true);  // 95 is the quality (can be 0 to 100)

  /* Compress image */

  jpeg_start_compress(&cinfo, true);

  JSAMPROW row_pointer;
  unsigned char *raw_image = img.data();
  while (cinfo.next_scanline < cinfo.image_height)
  {
    row_pointer = (JSAMPROW) &raw_image[cinfo.next_scanline*cinfo.image_width];
    jpeg_write_scanlines(&cinfo, &row_pointer, 1);
  }

  jpeg_finish_compress(&cinfo);
  fclose(f);
}


#ifdef DEBUG
int main()
{
  boost::multi_array<unsigned char,2> img;
  ReadGrayscaleJPEG("stanford.jpg", img);
  WriteGrayscaleJPEG("test.jpg", img);
  return 0;
}
#endif /* DEBUG */
