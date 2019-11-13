/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/Max/SCADE/STAGIOPTR/KCG/config.txt
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */
#ifndef _humiditySensor_HumiditySensor_H_
#define _humiditySensor_HumiditySensor_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* value/ */ value;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_int32 /* _L1/ */ _L1;
  kcg_int32 /* _L2/ */ _L2;
  kcg_int32 /* _L3/ */ _L3;
  kcg_int32 /* _L4/ */ _L4;
  kcg_float32 /* _L5/ */ _L5;
  kcg_float32 /* _L6/ */ _L6;
  kcg_int32 /* _L7/ */ _L7;
  kcg_int32 /* _L8/ */ _L8;
  kcg_int32 /* _L9/ */ _L9;
  kcg_float32 /* _L10/ */ _L10;
  kcg_float32 /* _L11/ */ _L11;
  kcg_float32 /* _L12/ */ _L12;
  kcg_float32 /* _L14/ */ _L14;
} outC_humiditySensor_HumiditySensor;

/* ===========  node initialization and cycle functions  =========== */
/* HumiditySensor::humiditySensor/ */
extern void humiditySensor_HumiditySensor(
  /* raw/ */
  kcg_int32 raw,
  outC_humiditySensor_HumiditySensor *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void humiditySensor_reset_HumiditySensor(
  outC_humiditySensor_HumiditySensor *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void humiditySensor_init_HumiditySensor(
  outC_humiditySensor_HumiditySensor *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _humiditySensor_HumiditySensor_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** humiditySensor_HumiditySensor.h
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

