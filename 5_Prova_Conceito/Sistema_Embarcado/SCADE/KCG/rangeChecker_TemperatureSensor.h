/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/Max/SCADE/STAGIOPTR/KCG/config.txt
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */
#ifndef _rangeChecker_TemperatureSensor_H_
#define _rangeChecker_TemperatureSensor_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_float32 /* Input3/ */ Input3;
  kcg_float32 /* max/ */ max;
  kcg_float32 /* min/ */ min;
} inC_rangeChecker_TemperatureSensor;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* Output1/ */ Output1;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_float32 /* _L3/ */ _L3;
  kcg_float32 /* _L2/ */ _L2;
  kcg_float32 /* _L1/ */ _L1;
  kcg_bool /* _L4/ */ _L4;
  kcg_bool /* _L5/ */ _L5;
  kcg_bool /* _L6/ */ _L6;
} outC_rangeChecker_TemperatureSensor;

/* ===========  node initialization and cycle functions  =========== */
/* TemperatureSensor::rangeChecker/ */
extern void rangeChecker_TemperatureSensor(
  inC_rangeChecker_TemperatureSensor *inC,
  outC_rangeChecker_TemperatureSensor *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void rangeChecker_reset_TemperatureSensor(
  outC_rangeChecker_TemperatureSensor *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void rangeChecker_init_TemperatureSensor(
  outC_rangeChecker_TemperatureSensor *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _rangeChecker_TemperatureSensor_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** rangeChecker_TemperatureSensor.h
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

