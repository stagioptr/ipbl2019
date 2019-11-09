/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/Max/SCADE/STAGIOPTR/KCG/config.txt
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */
#ifndef _Integration_Integration_H_
#define _Integration_Integration_H_

#include "kcg_types.h"
#include "accellerometerSensor_AccellerometerSensor.h"
#include "humiditySensor_HumiditySensor.h"
#include "tempratureSensor_TemperatureSensor.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_uint16 /* tempRaw/ */ tempRaw;
  kcg_int32 /* humRaw/ */ humRaw;
  kcg_float32 /* aX/ */ aX;
  kcg_float32 /* aY/ */ aY;
  kcg_float32 /* aZ/ */ aZ;
  kcg_float32 /* gX/ */ gX;
  kcg_float32 /* gY/ */ gY;
  kcg_float32 /* gZ/ */ gZ;
  kcg_float32 /* tempMax/ */ tempMax;
  kcg_float32 /* tempMin/ */ tempMin;
} inC_Integration_Integration;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* tempValue/ */ tempValue;
  kcg_bool /* tempValidity/ */ tempValidity;
  kcg_float32 /* tempMeanValue/ */ tempMeanValue;
  kcg_float32 /* humValue/ */ humValue;
  kcg_float32 /* deltaAX/ */ deltaAX;
  kcg_float32 /* deltaAY/ */ deltaAY;
  kcg_float32 /* deltaAZ/ */ deltaAZ;
  kcg_float32 /* deltaGX/ */ deltaGX;
  kcg_float32 /* deltaGY/ */ deltaGY;
  kcg_float32 /* deltaGZ/ */ deltaGZ;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_tempratureSensor_TemperatureSensor /* _L1=(TemperatureSensor::tempratureSensor#1)/ */ Context_tempratureSensor_1;
  outC_humiditySensor_HumiditySensor /* _L7=(HumiditySensor::humiditySensor#1)/ */ Context_humiditySensor_1;
  outC_accellerometerSensor_AccellerometerSensor /* _L14=(AccellerometerSensor::accellerometerSensor#1)/ */ Context_accellerometerSensor_1;
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_float32 /* _L3/ */ _L3;
  kcg_bool /* _L2/ */ _L2;
  kcg_float32 /* _L1/ */ _L1;
  kcg_uint16 /* _L4/ */ _L4;
  kcg_float32 /* _L5/ */ _L5;
  kcg_float32 /* _L6/ */ _L6;
  kcg_float32 /* _L7/ */ _L7;
  kcg_int32 /* _L8/ */ _L8;
  kcg_float32 /* _L9/ */ _L9;
  kcg_float32 /* _L10/ */ _L10;
  kcg_float32 /* _L11/ */ _L11;
  kcg_float32 /* _L12/ */ _L12;
  kcg_float32 /* _L13/ */ _L13;
  kcg_float32 /* _L14/ */ _L14;
  kcg_float32 /* _L15/ */ _L15;
  kcg_float32 /* _L16/ */ _L16;
  kcg_float32 /* _L17/ */ _L17;
  kcg_float32 /* _L18/ */ _L18;
  kcg_float32 /* _L19/ */ _L19;
  kcg_float32 /* _L20/ */ _L20;
} outC_Integration_Integration;

/* ===========  node initialization and cycle functions  =========== */
/* Integration::Integration/ */
extern void Integration_Integration(
  inC_Integration_Integration *inC,
  outC_Integration_Integration *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Integration_reset_Integration(outC_Integration_Integration *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Integration_init_Integration(outC_Integration_Integration *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _Integration_Integration_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Integration_Integration.h
** Generation date: 2019-11-01T16:58:20
*************************************************************$ */

