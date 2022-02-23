/**
 * @file param.h
 * @author StanleyHsu (jkyou98@gmail.com)
 * @brief  Define the stuct of image and parameters of algorithm
 * @version 0.1
 * @date 2022-01-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef PARAM_H_
#define PARAM_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
  /**
   * A structure to represent image basic info.
   */
  typedef struct ImageInfo_t
  {
    /**
     * @name Buffer
     */
    /*@{*/
    void *image;        /**< pointer which point to image buffer */
    void *output_image; /**< pointer which point to output buffer */
    /*@}*/
    /**
     * @name Info
     */
    /*@{*/
    uint16_t width;        /**<  image width */
    uint16_t height;       /**< image height*/
    uint8_t bit;           /**< image bit*/
    uint8_t update_status; /**< 0:original,
                            *1:*image updated,
                            *2:save to *output_image */
    /*@}*/
  } ImageInfo;
  /**
   * A structure to represent histogran equalization parameter info.
   */
  typedef struct HistEqualize_param_t
  {
    /**
     * @name Buffer
     */
    /*@{*/
    void *hist; /**< pointer which point to histogram buffer */
    void *cdf;  /**< pointer which point to CDF buffer */
    /*@}*/
    /**
     * @name Parameters
     */
    /*@{*/
    uint8_t HE_min; /**< minimum of histogram equalization */
    uint8_t HE_max; /**< minimum of histogram equalization */
    uint16_t bins;  /**< binsof histogram equalization */
    /*@}*/
  } HistEqualize_param;

#ifdef __cplusplus
}
#endif
#endif