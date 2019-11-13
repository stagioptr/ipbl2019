/* STAGIOPTR_mapping.c */

#include "STAGIOPTR_type.h"
#include "STAGIOPTR_interface.h"
#include "STAGIOPTR_mapping.h"

#include "SmuTypes.h"
#include "SmuMapping.h"

#include "kcg_sensors.h"

/* mapping declaration */

#define DECL_ITER(name) extern const MappingIterator iter_##name


#define DECL_SCOPE(name, count) extern const MappingEntry name##_entries[count]; extern const MappingScope name

DECL_SCOPE(scope_1, 16);
DECL_SCOPE(scope_0, 1);

/* clock definition */


/* mapping definition */


const MappingEntry scope_1_entries[16] = {
    /* 0 */ { MAP_OUTPUT, "value", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx.value, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 0 },
    /* 1 */ { MAP_INPUT, "raw", NULL, sizeof(kcg_int32), (size_t)&inputs_ctx.raw, &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 1 },
    /* 2 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_int32), (size_t)&outputs_ctx._L1, &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 2 },
    /* 3 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_int32), (size_t)&outputs_ctx._L2, &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 3 },
    /* 4 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_int32), (size_t)&outputs_ctx._L3, &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 4 },
    /* 5 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_int32), (size_t)&outputs_ctx._L4, &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 5 },
    /* 6 */ { MAP_LOCAL, "_L5", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L5, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 6 },
    /* 7 */ { MAP_LOCAL, "_L6", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L6, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 7 },
    /* 8 */ { MAP_LOCAL, "_L7", NULL, sizeof(kcg_int32), (size_t)&outputs_ctx._L7, &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 8 },
    /* 9 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_int32), (size_t)&outputs_ctx._L8, &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 9 },
    /* 10 */ { MAP_LOCAL, "_L9", NULL, sizeof(kcg_int32), (size_t)&outputs_ctx._L9, &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 10 },
    /* 11 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L10, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 11 },
    /* 12 */ { MAP_LOCAL, "_L11", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L11, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 12 },
    /* 13 */ { MAP_LOCAL, "_L12", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L12, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 13 },
    /* 14 */ { MAP_LOCAL, "_L14", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L14, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 14 },
    /* 15 */ { MAP_LOCAL, "_L16", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L16, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 15 }
};
const MappingScope scope_1 = {
    "HumiditySensor::humiditySensor/ humiditySensor_HumiditySensor",
    scope_1_entries, 16
};

const MappingEntry scope_0_entries[1] = {
    /* 0 */ { MAP_ROOT, "HumiditySensor::humiditySensor", NULL, 0, 0, NULL, NULL, NULL, &scope_1, 1, 0 }
};
const MappingScope scope_0 = {
    "",
    scope_0_entries, 1
};

/* entry point */
const MappingScope* pTop = &scope_0;
