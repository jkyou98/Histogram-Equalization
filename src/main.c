/**
 * @file main.c
 * @author StanleyHsu (jkyou98@gmail.com)
 * @brief This is Demo Code for hist equaliation and use UID2 image as
 * example
 * @version 0.1
 * @date 2022-01-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "BMP.h"
#include "HistEqualize.h"
#include "RAW.h"
#include "param.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_PATH "res/lena_gray.raw"
#define IMAGE_BIT 8
#define WIDTH 512
#define HEIGHT 512
#define HE_MIN 0
#define HE_MAX 255

int
main (void)
{
  char filepath[256];
  uint8_t *In_Out_IMG = (uint8_t *)calloc (WIDTH * HEIGHT, sizeof (uint8_t));
  uint16_t bins = HE_MAX - HE_MIN + 1;
  uint32_t *hist = (uint32_t *)calloc (bins, sizeof (uint32_t));
  uint32_t *cdf = (uint32_t *)calloc (bins, sizeof (uint32_t));
  // initialize parameters
  ImageInfo IMG_Info = { .image = (void *)In_Out_IMG,
                         .width = WIDTH,
                         .height = HEIGHT,
                         .bit = IMAGE_BIT };
  HistEqualize_param HE_Param = { .bins = bins,
                                  .cdf = (void *)cdf,
                                  .hist = (void *)hist,
                                  .HE_max = HE_MAX,
                                  .HE_min = HE_MIN }; // Reading Image
  sprintf (filepath, "%s", IMAGE_PATH);
  RAW_READ_uint8_t (filepath, In_Out_IMG, WIDTH, HEIGHT);
  // Histogram Equalization
  HistEqualize (&IMG_Info, &HE_Param);
  // Save the result
  RAW_WRITE_uint8_t ("lena_gray_HistEqualize.raw", In_Out_IMG, WIDTH, HEIGHT);
  BMP_W_GRAY_8BIT ("lena_gray_HistEqualize.bmp", In_Out_IMG, WIDTH, HEIGHT);

  free (In_Out_IMG);
  free (hist);
  free (cdf);
  return (0);
}