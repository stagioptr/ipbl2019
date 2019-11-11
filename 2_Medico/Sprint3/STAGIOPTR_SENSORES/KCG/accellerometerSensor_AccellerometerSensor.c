/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/Max/SCADE/STAGIOPTR/KCG/config.txt
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "accellerometerSensor_AccellerometerSensor.h"

/* AccellerometerSensor::accellerometerSensor/ */
void accellerometerSensor_AccellerometerSensor(
  inC_accellerometerSensor_AccellerometerSensor *inC,
  outC_accellerometerSensor_AccellerometerSensor *outC)
{
  outC->_L6 = inC->gZ;
  outC->deltaGZ = outC->_L6;
  outC->_L5 = inC->gY;
  outC->deltaGY = outC->_L5;
  outC->_L4 = inC->gX;
  outC->deltaGX = outC->_L4;
  outC->_L3 = inC->aZ;
  outC->deltaAZ = outC->_L3;
  outC->_L2 = inC->aY;
  outC->deltaAY = outC->_L2;
  outC->_L1 = inC->aX;
  outC->deltaAX = outC->_L1;
}

#ifndef KCG_USER_DEFINED_INIT
void accellerometerSensor_init_AccellerometerSensor(
  outC_accellerometerSensor_AccellerometerSensor *outC)
{
  outC->_L6 = kcg_lit_float32(0.0);
  outC->_L5 = kcg_lit_float32(0.0);
  outC->_L4 = kcg_lit_float32(0.0);
  outC->_L3 = kcg_lit_float32(0.0);
  outC->_L2 = kcg_lit_float32(0.0);
  outC->_L1 = kcg_lit_float32(0.0);
  outC->deltaGZ = kcg_lit_float32(0.0);
  outC->deltaGY = kcg_lit_float32(0.0);
  outC->deltaGX = kcg_lit_float32(0.0);
  outC->deltaAZ = kcg_lit_float32(0.0);
  outC->deltaAY = kcg_lit_float32(0.0);
  outC->deltaAX = kcg_lit_float32(0.0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void accellerometerSensor_reset_AccellerometerSensor(
  outC_accellerometerSensor_AccellerometerSensor *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** accellerometerSensor_AccellerometerSensor.c
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

