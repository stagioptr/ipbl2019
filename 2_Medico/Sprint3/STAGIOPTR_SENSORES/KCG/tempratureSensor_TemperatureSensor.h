/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/Max/SCADE/STAGIOPTR/KCG/config.txt
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */
#ifndef _tempratureSensor_TemperatureSensor_H_
#define _tempratureSensor_TemperatureSensor_H_

#include "kcg_types.h"
#include "rangeChecker_TemperatureSensor.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_uint16 /* raw/ */ raw;
  kcg_float32 /* max/ */ max;
  kcg_float32 /* min/ */ min;
} inC_tempratureSensor_TemperatureSensor;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* value/ */ value;
  kcg_bool /* validity/ */ validity;
  kcg_float32 /* meanValue/ */ meanValue;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_bool init;
  kcg_float32 /* delayInput/ */ delayInput;
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_rangeChecker_TemperatureSensor /* _L13=(TemperatureSensor::rangeChecker#1)/ */ Context_rangeChecker_1;
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_uint16 /* _L7/ */ _L7;
  kcg_float32 /* _L8/ */ _L8;
  kcg_float32 /* _L9/ */ _L9;
  kcg_float32 /* _L12/ */ _L12;
  kcg_bool /* _L13/ */ _L13;
  kcg_float32 /* _L14/ */ _L14;
  kcg_float32 /* _L16/ */ _L16;
  kcg_float32 /* _L17/ */ _L17;
  kcg_float32 /* _L18/ */ _L18;
  kcg_float32 /* _L19/ */ _L19;
} outC_tempratureSensor_TemperatureSensor;

/* ===========  node initialization and cycle functions  =========== */
/* TemperatureSensor::tempratureSensor/ */
extern void tempratureSensor_TemperatureSensor(
  inC_tempratureSensor_TemperatureSensor *inC,
  outC_tempratureSensor_TemperatureSensor *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void tempratureSensor_reset_TemperatureSensor(
  outC_tempratureSensor_TemperatureSensor *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void tempratureSensor_init_TemperatureSensor(
  outC_tempratureSensor_TemperatureSensor *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _tempratureSensor_TemperatureSensor_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** tempratureSensor_TemperatureSensor.h
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

