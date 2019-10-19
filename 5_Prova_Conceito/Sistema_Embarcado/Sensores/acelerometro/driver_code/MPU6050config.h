/**
 * \file
 * \brief Configuration header file for MPU6050 accelerometer/gyroscope
 *
 * This header file is used to configure settings of the MPU6050 module.
 */

#ifndef __MPU6050_CONFIG_H
#define __MPU6050_CONFIG_H

#if !defined(MPU6050_CONFIG_INIT_DRIVER_IN_STARTUP)
  #define MPU6050_CONFIG_INIT_DRIVER_IN_STARTUP  (0)
   /*!< 1: Initialize driver durin startup, 0: Do not call Init during startup */
#endif

#endif /* __MPU6050_CONFIG_H */
