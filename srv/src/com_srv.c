/**
 * Copyright (c) 2016, Jack Mo (mobangjack@foxmail.com).
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

#include "com_srv.h"

void BtmRxCallback(uint8_t data)
{
	Btm_Proc(data);
}

void BtmIdleCallback(const uint8_t* buf, const uint32_t len)
{
	Dnl_Proc(buf, len);
}

void DbiRxCallback(uint8_t data)
{
	Dbi_Proc(data);
}

void DbiIdleCallback(const uint8_t* buf, const uint32_t len)
{
	Top_Proc(buf, len);
}

void TtyRxCallback(uint8_t data)
{
	Tty_Proc(data);
}

void TtyIdleCallback(const uint8_t* buf, const uint32_t len)
{
	Dnl_Proc(buf, len);
}


