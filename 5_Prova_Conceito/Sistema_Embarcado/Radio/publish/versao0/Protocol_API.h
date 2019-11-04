/** @file FAP.h
 *
 * @author Runar Kjellhaug
 *
 * @compiler This program has been tested with Keil C51 V7.50.
 *
 * @copyright
 * Copyright (c) 2005 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is confidential property of Nordic Semiconductor. The use,
 * copying, transfer or disclosure of such information is prohibited except by express written
 * agreement with Nordic Semiconductor.
 * @endcopyright
 *
 * $Date: 20.02.06 14:16 $
 * $Revision: 9 $
 *
 */

// UINT type definition
#ifndef _UINT_DEF_
#define _UINT_DEF_
typedef unsigned int UINT;
#endif  /* _UINT_DEF_ */

// uint8_t type definition
#ifndef _uint8_t_DEF_
#define _uint8_t_DEF_
typedef unsigned char uint8_t;
#endif   /* _uint8_t_DEF_ */

// Protocol_API.c prototypes
void L01_Set_Channel(uint8_t rf_ch);
uint8_t L01_Get_Channel(void);
uint8_t L01_Clear_IRQ(uint8_t irq_flag);
void L01_Write_TX_Pload(uint8_t *pBuf, uint8_t plWidth);
uint8_t L01_Get_Status(void);
uint8_t L01_RD_RX_PW_n(uint8_t pipe);
void L01_WR_RX_PW_n(uint8_t pipe, uint8_t plWidth);
uint8_t L01_Get_Current_Pipenum(void);
UINT L01_Read_RX_Pload(uint8_t *pBuf);
void L01_Flush_TX(void);
void L01_Flush_RX(void);
uint8_t L01_Get_FIFO(void);
