/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/Max/SCADE/STAGIOPTR/KCG/config.txt
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "humiditySensor_HumiditySensor.h"

/* HumiditySensor::humiditySensor/ */
void humiditySensor_HumiditySensor(
  /* raw/ */
  kcg_int32 raw,
  outC_humiditySensor_HumiditySensor *outC)
{
  outC->_L9 = HUMIDITY_MAX_HumiditySensor;
  outC->_L8 = HUMIDITY_MIN_HumiditySensor;
  outC->_L7 = outC->_L8 - outC->_L9;
  outC->_L12 = /* _L12= */(kcg_float32) outC->_L7;
  outC->_L3 = SENSOR_MIN_HumiditySensor;
  outC->_L2 = SENSOR_MAX_HumiditySensor;
  outC->_L4 = outC->_L2 - outC->_L3;
  outC->_L11 = /* _L11= */(kcg_float32) outC->_L4;
  outC->_L5 = outC->_L12 / outC->_L11;
  outC->_L1 = raw;
  outC->_L10 = /* _L10= */(kcg_float32) outC->_L1;
  outC->_L6 = outC->_L10 * outC->_L5;
  outC->_L14 = outC->_L6 - outC->_L12;
  outC->value = outC->_L14;
}

#ifndef KCG_USER_DEFINED_INIT
void humiditySensor_init_HumiditySensor(
  outC_humiditySensor_HumiditySensor *outC)
{
  outC->_L14 = kcg_lit_float32(0.0);
  outC->_L12 = kcg_lit_float32(0.0);
  outC->_L11 = kcg_lit_float32(0.0);
  outC->_L10 = kcg_lit_float32(0.0);
  outC->_L9 = kcg_lit_int32(0);
  outC->_L8 = kcg_lit_int32(0);
  outC->_L7 = kcg_lit_int32(0);
  outC->_L6 = kcg_lit_float32(0.0);
  outC->_L5 = kcg_lit_float32(0.0);
  outC->_L4 = kcg_lit_int32(0);
  outC->_L3 = kcg_lit_int32(0);
  outC->_L2 = kcg_lit_int32(0);
  outC->_L1 = kcg_lit_int32(0);
  outC->value = kcg_lit_float32(0.0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void humiditySensor_reset_HumiditySensor(
  outC_humiditySensor_HumiditySensor *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** humiditySensor_HumiditySensor.c
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

