/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2012  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.16 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The software has been licensed to  ARM LIMITED whose registered office
is situated at  110 Fulbourn Road,  Cambridge CB1 9NJ,  England solely
for  the  purposes  of  creating  libraries  for  ARM7, ARM9, Cortex-M
series,  and   Cortex-R4   processor-based  devices,  sublicensed  and
distributed as part of the  MDK-ARM  Professional  under the terms and
conditions  of  the   End  User  License  supplied  with  the  MDK-ARM
Professional. 
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : GUIDRV_FlexColor.h
Purpose     : Interface definition for GUIDRV_FlexColor driver
---------------------------END-OF-HEADER------------------------------
*/

#ifndef GUIDRV_FLEXCOLOR_H
#define GUIDRV_FLEXCOLOR_H

#include "GUI.h"

/*********************************************************************
*
*       Configuration macros
*/
//
// Operation modes (16bpp)
//
#define GUIDRV_FLEXCOLOR_M16C0B8  GUIDRV_FlexColor_SetMode16bppC0B8
#define GUIDRV_FLEXCOLOR_M16C1B8  GUIDRV_FlexColor_SetMode16bppC1B8
#define GUIDRV_FLEXCOLOR_M16C0B16 GUIDRV_FlexColor_SetMode16bppC0B16
#define GUIDRV_FLEXCOLOR_M16C1B16 GUIDRV_FlexColor_SetMode16bppC1B16

//
// Operation modes (18bpp)
//
#define GUIDRV_FLEXCOLOR_M18C0B9  GUIDRV_FlexColor_SetMode18bppC0B9
#define GUIDRV_FLEXCOLOR_M18C1B9  GUIDRV_FlexColor_SetMode18bppC1B9
#define GUIDRV_FLEXCOLOR_M18C0B18 GUIDRV_FlexColor_SetMode18bppC0B18
#define GUIDRV_FLEXCOLOR_M18C1B18 GUIDRV_FlexColor_SetMode18bppC1B18

//
// Controller selection
//
#define GUIDRV_FLEXCOLOR_F66708   GUIDRV_FlexColor_SetFunc66708
#define GUIDRV_FLEXCOLOR_F66709   GUIDRV_FlexColor_SetFunc66709
#define GUIDRV_FLEXCOLOR_F66712   GUIDRV_FlexColor_SetFunc66712
#define GUIDRV_FLEXCOLOR_F66714   GUIDRV_FlexColor_SetFunc66714
#define GUIDRV_FLEXCOLOR_F66718   GUIDRV_FlexColor_SetFunc66718
#define GUIDRV_FLEXCOLOR_F66719   GUIDRV_FlexColor_SetFunc66719
#define GUIDRV_FLEXCOLOR_F66720   GUIDRV_FlexColor_SetFunc66720

//
// Hardware interfaces
//
#define GUIDRV_FLEXCOLOR_IF_TYPE_I  0
#define GUIDRV_FLEXCOLOR_IF_TYPE_II 1

/*********************************************************************
*
*       Configuration structure
*/
typedef struct {
  //
  // Driver specific configuration items
  //
  int FirstSEG;
  int FirstCOM;
  int Orientation;
  U16 RegEntryMode;
  int NumDummyReads;
} CONFIG_FLEXCOLOR;

/*********************************************************************
*
*       Display drivers
*/
//
// Addresses
//
extern const GUI_DEVICE_API GUIDRV_Win_API;

extern const GUI_DEVICE_API GUIDRV_FlexColor_API;

//
// Macros to be used in configuration files
//
#if defined(WIN32) && !defined(LCD_SIMCONTROLLER)

  #define GUIDRV_FLEXCOLOR &GUIDRV_Win_API

#else

  #define GUIDRV_FLEXCOLOR &GUIDRV_FlexColor_API

#endif

/*********************************************************************
*
*       Configuration interface
*/
#if !defined(WIN32) || defined(LCD_SIMCONTROLLER)

  //
  // Display controller configuration
  //
  void GUIDRV_FlexColor_SetFunc66708     (GUI_DEVICE * pDevice);
  void GUIDRV_FlexColor_SetFunc66709     (GUI_DEVICE * pDevice);
  void GUIDRV_FlexColor_SetFunc66712     (GUI_DEVICE * pDevice);
  void GUIDRV_FlexColor_SetFunc66714     (GUI_DEVICE * pDevice);
  void GUIDRV_FlexColor_SetFunc66718     (GUI_DEVICE * pDevice);
  void GUIDRV_FlexColor_SetFunc66719     (GUI_DEVICE * pDevice);
  void GUIDRV_FlexColor_SetFunc66720     (GUI_DEVICE * pDevice);

  //
  // Operation mode configuration (16bpp)
  //
  void GUIDRV_FlexColor_SetMode16bppC0B8 (GUI_DEVICE * pDevice);
  void GUIDRV_FlexColor_SetMode16bppC1B8 (GUI_DEVICE * pDevice);
  void GUIDRV_FlexColor_SetMode16bppC0B16(GUI_DEVICE * pDevice);
  void GUIDRV_FlexColor_SetMode16bppC1B16(GUI_DEVICE * pDevice);

  //
  // Drawing mode configuration (18bpp)
  //
  void GUIDRV_FlexColor_SetMode18bppC0B9 (GUI_DEVICE * pDevice);
  void GUIDRV_FlexColor_SetMode18bppC1B9 (GUI_DEVICE * pDevice);
  void GUIDRV_FlexColor_SetMode18bppC0B18(GUI_DEVICE * pDevice);
  void GUIDRV_FlexColor_SetMode18bppC1B18(GUI_DEVICE * pDevice);

  //
  // User interface
  //
  void GUIDRV_FlexColor_SetFunc(GUI_DEVICE * pDevice, GUI_PORT_API * pHW_API, void (* pfFunc)(GUI_DEVICE * pDevice), void (* pfMode)(GUI_DEVICE * pDevice));
  void GUIDRV_FlexColor_Config (GUI_DEVICE * pDevice, CONFIG_FLEXCOLOR * pConfig);
  
  //
  // Hardware interface
  //
  void GUIDRV_FlexColor_SetInterface66709_B16(GUI_DEVICE * pDevice, int Type);
  void GUIDRV_FlexColor_SetInterface66712_B16(GUI_DEVICE * pDevice, int Type);
  void GUIDRV_FlexColor_SetInterface66712_B18(GUI_DEVICE * pDevice, int Type);
  void GUIDRV_FlexColor_SetInterface66720_B16(GUI_DEVICE * pDevice, int Type);

#else

  //
  // Display controller configuration
  //
  #define GUIDRV_FlexColor_SetFunc66708(pDevice)
  #define GUIDRV_FlexColor_SetFunc66709(pDevice)
  #define GUIDRV_FlexColor_SetFunc66712(pDevice)
  #define GUIDRV_FlexColor_SetFunc66714(pDevice)
  #define GUIDRV_FlexColor_SetFunc66718(pDevice)
  #define GUIDRV_FlexColor_SetFunc66719(pDevice)
  #define GUIDRV_FlexColor_SetFunc66720(pDevice)

  //
  // Operation mode configuration (16bpp)
  //
  #define GUIDRV_FlexColor_SetMode16bppC0B8(pDevice)
  #define GUIDRV_FlexColor_SetMode16bppC1B8(pDevice)
  #define GUIDRV_FlexColor_SetMode16bppC0B16(pDevice)
  #define GUIDRV_FlexColor_SetMode16bppC1B16(pDevice)

  //
  // Drawing mode configuration (18bpp)
  //
  #define GUIDRV_FlexColor_SetMode18bppC0B9(pDevice)
  #define GUIDRV_FlexColor_SetMode18bppC1B9(pDevice)
  #define GUIDRV_FlexColor_SetMode18bppC0B18(pDevice)
  #define GUIDRV_FlexColor_SetMode18bppC1B18(pDevice)

  //
  // User interface
  //
  #define GUIDRV_FlexColor_SetFunc(pDevice, pHW_API, pfFunc, pfMode)
  #define GUIDRV_FlexColor_Config(pDevice, pConfig)

  //
  // Hardware interface
  //
  #define GUIDRV_FlexColor_SetInterface66709_B16(pDevice, Type)
  #define GUIDRV_FlexColor_SetInterface66712_B16(pDevice, Type)
  #define GUIDRV_FlexColor_SetInterface66712_B18(pDevice, Type)
  #define GUIDRV_FlexColor_SetInterface66720_B18(pDevice, Type)

#endif

#endif /* GUIDRV_FLEXCOLOR_H */

/*************************** End of file ****************************/
