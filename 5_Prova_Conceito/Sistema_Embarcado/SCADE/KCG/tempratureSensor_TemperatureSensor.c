/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/Max/SCADE/STAGIOPTR/KCG/config.txt
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "tempratureSensor_TemperatureSensor.h"

/* TemperatureSensor::tempratureSensor/ */
void tempratureSensor_TemperatureSensor(
  inC_tempratureSensor_TemperatureSensor *inC,
  outC_tempratureSensor_TemperatureSensor *outC)
{
  inC_rangeChecker_TemperatureSensor tmp_input;

  outC->_L7 = inC->raw;
  outC->_L19 = /* _L19= */(kcg_float32) outC->_L7;
  outC->_L18 = kcg_lit_float32(2.0);
  /* _L14= */
  if (outC->init) {
    outC->_L14 = kcg_lit_float32(0.0);
  }
  else {
    outC->_L14 = outC->delayInput;
  }
  outC->_L8 = CONVERSION_FACTOR_TemperatureSensor;
  outC->delayInput = outC->_L19 * outC->_L8;
  outC->_L16 = outC->_L14 + outC->delayInput;
  outC->_L17 = outC->_L16 / outC->_L18;
  outC->meanValue = outC->_L17;
  outC->_L9 = inC->max;
  outC->_L12 = inC->min;
  tmp_input.Input3 = outC->delayInput;
  tmp_input.max = outC->_L9;
  tmp_input.min = outC->_L12;
  /* _L13=(TemperatureSensor::rangeChecker#1)/ */
  rangeChecker_TemperatureSensor(&tmp_input, &outC->Context_rangeChecker_1);
  outC->_L13 = outC->Context_rangeChecker_1.Output1;
  outC->validity = outC->_L13;
  outC->value = outC->delayInput;
  outC->init = kcg_false;
}

#ifndef KCG_USER_DEFINED_INIT
void tempratureSensor_init_TemperatureSensor(
  outC_tempratureSensor_TemperatureSensor *outC)
{
  outC->_L19 = kcg_lit_float32(0.0);
  outC->_L18 = kcg_lit_float32(0.0);
  outC->_L17 = kcg_lit_float32(0.0);
  outC->_L16 = kcg_lit_float32(0.0);
  outC->_L14 = kcg_lit_float32(0.0);
  outC->_L13 = kcg_true;
  outC->_L12 = kcg_lit_float32(0.0);
  outC->_L9 = kcg_lit_float32(0.0);
  outC->_L8 = kcg_lit_float32(0.0);
  outC->_L7 = kcg_lit_uint16(0);
  outC->delayInput = kcg_lit_float32(0.0);
  outC->init = kcg_true;
  outC->meanValue = kcg_lit_float32(0.0);
  outC->validity = kcg_true;
  outC->value = kcg_lit_float32(0.0);
  /* _L13=(TemperatureSensor::rangeChecker#1)/ */
  rangeChecker_init_TemperatureSensor(&outC->Context_rangeChecker_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void tempratureSensor_reset_TemperatureSensor(
  outC_tempratureSensor_TemperatureSensor *outC)
{
  outC->init = kcg_true;
  /* _L13=(TemperatureSensor::rangeChecker#1)/ */
  rangeChecker_reset_TemperatureSensor(&outC->Context_rangeChecker_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** tempratureSensor_TemperatureSensor.c
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

