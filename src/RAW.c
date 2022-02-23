#include "RAW.h"
#include <stdint.h>
#include <stdio.h>
void
RAW_READ_uint16_t (const char *fileName, uint16_t *image, uint16_t width,
                   uint16_t height)
{
  // Open the file for reading in binary mode
  FILE *imageFile = fopen (fileName, "rb");
  // read binary file
  fread (image, sizeof (*image), width * height, imageFile);
  fclose (imageFile);
}

void
RAW_WRITE_uint16_t (const char *fileName, uint16_t *image, uint16_t width,
                    uint16_t height)
{
  // Open the file for reading in binary mode
  FILE *outputFile = fopen (fileName, "wb+");
  // read binary file
  fwrite (image, sizeof (*image), width * height, outputFile);
  fclose (outputFile);
}
void
RAW_READ_uint8_t (const char *fileName, uint8_t *image, uint16_t width,
                  uint16_t height)
{
  // Open the file for reading in binary mode
  FILE *imageFile = fopen (fileName, "rb");
  // read binary file
  fread (image, sizeof (*image), width * height, imageFile);
  fclose (imageFile);
}

void
RAW_WRITE_uint8_t (const char *fileName, uint8_t *image, uint16_t width,
                   uint16_t height)
{
  // Open the file for reading in binary mode
  FILE *outputFile = fopen (fileName, "wb+");
  // read binary file
  fwrite (image, sizeof (*image), width * height, outputFile);
  fclose (outputFile);
}