/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : spiTemp.h
**     Project     : MAX6675
**     Processor   : MKL25Z128VLK4
**     Component   : fsl_spi
**     Version     : Component 1.3.0, Driver 01.00, CPU db: 3.00.000
**     Repository  : KSDK 1.3.0
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-10-31, 10:47, # CodeGen: 5
**     Contents    :
**         SPI_DRV_IRQHandler              - void SPI_DRV_IRQHandler(uint32_t instance);
**         SPI_DRV_MasterInit              - spi_status_t SPI_DRV_MasterInit(uint32_t instance,spi_master_state_t *...
**         SPI_DRV_MasterDeinit            - spi_status_t SPI_DRV_MasterDeinit(uint32_t instance);
**         SPI_DRV_MasterConfigureBus      - void SPI_DRV_MasterConfigureBus(uint32_t instance,const...
**         SPI_DRV_MasterTransferBlocking  - spi_status_t SPI_DRV_MasterTransferBlocking(uint32_t instance,const...
**         SPI_DRV_MasterTransfer          - spi_status_t SPI_DRV_MasterTransfer(uint32_t instance,const...
**         SPI_DRV_MasterGetTransferStatus - spi_status_t SPI_DRV_MasterGetTransferStatus(uint32_t instance,uint32_t *...
**         SPI_DRV_MasterAbortTransfer     - spi_status_t SPI_DRV_MasterAbortTransfer(uint32_t instance);
**         SPI_DRV_MasterIRQHandler        - void SPI_DRV_MasterIRQHandler(uint32_t instance);
**         SPI_DRV_SlaveInit               - spi_status_t SPI_DRV_SlaveInit(uint32_t instance,spi_slave_state_t *...
**         SPI_DRV_SlaveDeinit             - spi_status_t SPI_DRV_SlaveDeinit(uint32_t instance);
**         SPI_DRV_SlaveTransferBlocking   - spi_status_t SPI_DRV_SlaveTransferBlocking(uint32_t instance,const uint8_t *...
**         SPI_DRV_SlaveTransfer           - spi_status_t SPI_DRV_SlaveTransfer(uint32_t instance,const uint8_t *...
**         SPI_DRV_SlaveAbortTransfer      - spi_status_t SPI_DRV_SlaveAbortTransfer(uint32_t instance);
**         SPI_DRV_SlaveGetTransferStatus  - spi_status_t SPI_DRV_SlaveGetTransferStatus(uint32_t instance,uint32_t *...
**         SPI_DRV_SlaveIRQHandler         - void SPI_DRV_SlaveIRQHandler(uint32_t instance);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file spiTemp.h
** @version 01.00
*/         
/*!
**  @addtogroup spiTemp_module spiTemp module documentation
**  @{
*/         
#ifndef __spiTemp_H
#define __spiTemp_H
/* MODULE spiTemp. */

/* Include inherited beans */
#include "clockMan1.h"
#include "osa1.h"
#include "Cpu.h"

/*! @brief Device instance number */
#define spiTemp_IDX SPI0_IDX
/*! @brief Device instance number for backward compatibility */
#define FSL_SPITEMP spiTemp_IDX
/*! @brief spiTemp component mode, 0 for interrupt, 1 for DMA mode */
#define spiTemp_DMA_MODE 0U
/*! @brief spiTemp component mode for backward compatibility */
#define SPITEMP_DMA_MODE spiTemp_DMA_MODE

/*! @brief Master configuration declaration */
extern const spi_master_user_config_t spiTemp_MasterConfig0;
    

#endif
/* ifndef __spiTemp_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/