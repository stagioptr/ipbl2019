/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/Max/SCADE/STAGIOPTR/KCG/config.txt
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Integration_Integration.h"

/* Integration::Integration/ */
void Integration_Integration(
  inC_Integration_Integration *inC,
  outC_Integration_Integration *outC)
{
  inC_accellerometerSensor_AccellerometerSensor _1_tmp_input;
  inC_tempratureSensor_TemperatureSensor tmp_input;

  outC->_L15 = inC->aX;
  outC->_L16 = inC->aY;
  outC->_L17 = inC->aZ;
  outC->_L18 = inC->gX;
  outC->_L19 = inC->gY;
  outC->_L20 = inC->gZ;
  _1_tmp_input.aX = outC->_L15;
  _1_tmp_input.aY = outC->_L16;
  _1_tmp_input.aZ = outC->_L17;
  _1_tmp_input.gX = outC->_L18;
  _1_tmp_input.gY = outC->_L19;
  _1_tmp_input.gZ = outC->_L20;
  /* _L14=(AccellerometerSensor::accellerometerSensor#1)/ */
  accellerometerSensor_AccellerometerSensor(
    &_1_tmp_input,
    &outC->Context_accellerometerSensor_1);
  outC->_L14 = outC->Context_accellerometerSensor_1.deltaAX;
  outC->_L13 = outC->Context_accellerometerSensor_1.deltaAY;
  outC->_L12 = outC->Context_accellerometerSensor_1.deltaAZ;
  outC->_L11 = outC->Context_accellerometerSensor_1.deltaGX;
  outC->_L10 = outC->Context_accellerometerSensor_1.deltaGY;
  outC->_L9 = outC->Context_accellerometerSensor_1.deltaGZ;
  outC->deltaGZ = outC->_L9;
  outC->deltaGY = outC->_L10;
  outC->deltaGX = outC->_L11;
  outC->deltaAZ = outC->_L12;
  outC->deltaAY = outC->_L13;
  outC->deltaAX = outC->_L14;
  outC->_L8 = inC->humRaw;
  /* _L7=(HumiditySensor::humiditySensor#1)/ */
  humiditySensor_HumiditySensor(outC->_L8, &outC->Context_humiditySensor_1);
  outC->_L7 = outC->Context_humiditySensor_1.value;
  outC->humValue = outC->_L7;
  outC->_L4 = inC->tempRaw;
  outC->_L5 = inC->tempMax;
  outC->_L6 = inC->tempMin;
  tmp_input.raw = outC->_L4;
  tmp_input.max = outC->_L5;
  tmp_input.min = outC->_L6;
  /* _L1=(TemperatureSensor::tempratureSensor#1)/ */
  tempratureSensor_TemperatureSensor(
    &tmp_input,
    &outC->Context_tempratureSensor_1);
  outC->_L1 = outC->Context_tempratureSensor_1.value;
  outC->_L2 = outC->Context_tempratureSensor_1.validity;
  outC->_L3 = outC->Context_tempratureSensor_1.meanValue;
  outC->tempMeanValue = outC->_L3;
  outC->tempValidity = outC->_L2;
  outC->tempValue = outC->_L1;
}

#ifndef KCG_USER_DEFINED_INIT
void Integration_init_Integration(outC_Integration_Integration *outC)
{
  outC->_L20 = kcg_lit_float32(0.0);
  outC->_L19 = kcg_lit_float32(0.0);
  outC->_L18 = kcg_lit_float32(0.0);
  outC->_L17 = kcg_lit_float32(0.0);
  outC->_L16 = kcg_lit_float32(0.0);
  outC->_L15 = kcg_lit_float32(0.0);
  outC->_L14 = kcg_lit_float32(0.0);
  outC->_L13 = kcg_lit_float32(0.0);
  outC->_L12 = kcg_lit_float32(0.0);
  outC->_L11 = kcg_lit_float32(0.0);
  outC->_L10 = kcg_lit_float32(0.0);
  outC->_L9 = kcg_lit_float32(0.0);
  outC->_L8 = kcg_lit_int32(0);
  outC->_L7 = kcg_lit_float32(0.0);
  outC->_L6 = kcg_lit_float32(0.0);
  outC->_L5 = kcg_lit_float32(0.0);
  outC->_L4 = kcg_lit_uint16(0);
  outC->_L1 = kcg_lit_float32(0.0);
  outC->_L2 = kcg_true;
  outC->_L3 = kcg_lit_float32(0.0);
  outC->deltaGZ = kcg_lit_float32(0.0);
  outC->deltaGY = kcg_lit_float32(0.0);
  outC->deltaGX = kcg_lit_float32(0.0);
  outC->deltaAZ = kcg_lit_float32(0.0);
  outC->deltaAY = kcg_lit_float32(0.0);
  outC->deltaAX = kcg_lit_float32(0.0);
  outC->humValue = kcg_lit_float32(0.0);
  outC->tempMeanValue = kcg_lit_float32(0.0);
  outC->tempValidity = kcg_true;
  outC->tempValue = kcg_lit_float32(0.0);
  /* _L1=(TemperatureSensor::tempratureSensor#1)/ */
  tempratureSensor_init_TemperatureSensor(&outC->Context_tempratureSensor_1);
  /* _L7=(HumiditySensor::humiditySensor#1)/ */
  humiditySensor_init_HumiditySensor(&outC->Context_humiditySensor_1);
  /* _L14=(AccellerometerSensor::accellerometerSensor#1)/ */
  accellerometerSensor_init_AccellerometerSensor(
    &outC->Context_accellerometerSensor_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Integration_reset_Integration(outC_Integration_Integration *outC)
{
  /* _L1=(TemperatureSensor::tempratureSensor#1)/ */
  tempratureSensor_reset_TemperatureSensor(&outC->Context_tempratureSensor_1);
  /* _L7=(HumiditySensor::humiditySensor#1)/ */
  humiditySensor_reset_HumiditySensor(&outC->Context_humiditySensor_1);
  /* _L14=(AccellerometerSensor::accellerometerSensor#1)/ */
  accellerometerSensor_reset_AccellerometerSensor(
    &outC->Context_accellerometerSensor_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Integration_Integration.c
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

