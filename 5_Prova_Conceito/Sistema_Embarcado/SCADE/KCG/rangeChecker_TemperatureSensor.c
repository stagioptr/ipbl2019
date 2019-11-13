/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/Max/SCADE/STAGIOPTR/KCG/config.txt
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "rangeChecker_TemperatureSensor.h"

/* TemperatureSensor::rangeChecker/ */
void rangeChecker_TemperatureSensor(
  inC_rangeChecker_TemperatureSensor *inC,
  outC_rangeChecker_TemperatureSensor *outC)
{
  outC->_L2 = inC->max;
  outC->_L1 = inC->Input3;
  outC->_L4 = outC->_L1 <= outC->_L2;
  outC->_L3 = inC->min;
  outC->_L5 = outC->_L1 >= outC->_L3;
  outC->_L6 = outC->_L5 & outC->_L4;
  outC->Output1 = outC->_L6;
}

#ifndef KCG_USER_DEFINED_INIT
void rangeChecker_init_TemperatureSensor(
  outC_rangeChecker_TemperatureSensor *outC)
{
  outC->_L6 = kcg_true;
  outC->_L5 = kcg_true;
  outC->_L4 = kcg_true;
  outC->_L1 = kcg_lit_float32(0.0);
  outC->_L2 = kcg_lit_float32(0.0);
  outC->_L3 = kcg_lit_float32(0.0);
  outC->Output1 = kcg_true;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void rangeChecker_reset_TemperatureSensor(
  outC_rangeChecker_TemperatureSensor *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** rangeChecker_TemperatureSensor.c
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

