/**
 * Copyright (c) 2011-2016, Jack Mo (mobangjack@foxmail.com).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __CBUS_H__
#define __CBUS_H__

/**************************************************/
/*                  Control Bus                   */
/**************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>

#pragma pack(1)

#define VEC3_TYPED_DEF(TYPE,NAME) \
typedef struct \
{ \
	TYPE x; \
	TYPE y; \
	TYPE z; \
}NAME;

#define GIM2_TYPED_DEF(TYPE,NAME) \
typedef struct \
{ \
	TYPE p; \
	TYPE t; \
}NAME;

#define GIM3_TYPED_DEF(TYPE,NAME) \
typedef struct \
{ \
	TYPE p; \
	TYPE t; \
	TYPE z; \
}NAME;

VEC3_TYPED_DEF(int32_t, ChassisState_i) // Chassis state control typedef (int)
VEC3_TYPED_DEF(int16_t, ChassisState_s) // Chassis state control typedef (short)
GIM2_TYPED_DEF(int16_t, PantiltState_s) // Pantilt state control typedef (short)


#define CBUS_FS_CP     (1u<<0)
#define CBUS_FS_CP_ABS (1u<<1)
#define CBUS_FS_CV     (1u<<2)
#define CBUS_FS_GV     (1u<<3)
#define CBUS_FS_GP_ABS (1u<<4)
#define CBUS_FS_LASR   (1u<<5)
#define CBUS_FS_FRIC   (1u<<6)
#define CBUS_FS_TRIG   (1u<<7)

#define CBUS_FS_MOD (CBUS_FS_CP|CBUS_FS_CP_ABS|CBUS_FS_GV|CBUS_FS_GP_ABS)
#define CBUS_FS_FUN (CBUS_FS_LASR|CBUS_FS_FRIC|CBUS_FS_TRIG)

#define CBUS_FS_ALL (CBUS_FS_MOD|CBUS_FS_FUN)

#define CBUS_VALUE_SCALE 1e3f

typedef struct
{
	uint32_t fs; // Flag bits
	ChassisState_i cp; // Chassis position, unit: linear: mm, angular: 1e-3rad
	ChassisState_s cv; // Chassis velocity, unit: linear: mm/s, angular: 1e-3rad/s
	PantiltState_s gp; // Pantilt position, unit: linear: mm, angular: rad
	PantiltState_s gv; // Pantilt velocity, unit: linear: mm/s, angular: 1e-3rad/s
}CBus_t;

#pragma pack()

void CBus_Init(CBus_t* cbus);

#ifdef __cplusplus
}
#endif

#endif
