/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/Max/SCADE/STAGIOPTR/KCG/config.txt
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */
#ifndef _accellerometerSensor_AccellerometerSensor_H_
#define _accellerometerSensor_AccellerometerSensor_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_float32 /* aX/ */ aX;
  kcg_float32 /* aY/ */ aY;
  kcg_float32 /* aZ/ */ aZ;
  kcg_float32 /* gX/ */ gX;
  kcg_float32 /* gY/ */ gY;
  kcg_float32 /* gZ/ */ gZ;
} inC_accellerometerSensor_AccellerometerSensor;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* deltaAX/ */ deltaAX;
  kcg_float32 /* deltaAY/ */ deltaAY;
  kcg_float32 /* deltaAZ/ */ deltaAZ;
  kcg_float32 /* deltaGX/ */ deltaGX;
  kcg_float32 /* deltaGY/ */ deltaGY;
  kcg_float32 /* deltaGZ/ */ deltaGZ;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_float32 /* _L1/ */ _L1;
  kcg_float32 /* _L2/ */ _L2;
  kcg_float32 /* _L3/ */ _L3;
  kcg_float32 /* _L4/ */ _L4;
  kcg_float32 /* _L5/ */ _L5;
  kcg_float32 /* _L6/ */ _L6;
} outC_accellerometerSensor_AccellerometerSensor;

/* ===========  node initialization and cycle functions  =========== */
/* AccellerometerSensor::accellerometerSensor/ */
extern void accellerometerSensor_AccellerometerSensor(
  inC_accellerometerSensor_AccellerometerSensor *inC,
  outC_accellerometerSensor_AccellerometerSensor *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void accellerometerSensor_reset_AccellerometerSensor(
  outC_accellerometerSensor_AccellerometerSensor *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void accellerometerSensor_init_AccellerometerSensor(
  outC_accellerometerSensor_AccellerometerSensor *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _accellerometerSensor_AccellerometerSensor_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** accellerometerSensor_AccellerometerSensor.h
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

