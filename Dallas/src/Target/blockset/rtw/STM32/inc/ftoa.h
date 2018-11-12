/************************************************************************************//**
* \file         ftoa.c
* \brief        Float to ASCII header file. Derived from http://ideone.com/XC2gPw.
* \internal
*----------------------------------------------------------------------------------------
*                          C O P Y R I G H T
*----------------------------------------------------------------------------------------
*  Copyright (c) 2014  by Feaser           http://www.feaser.com    All rights reserved
*  Copyright (c) 2014  by HAN Automotive   http://www.han.nl        All rights reserved
*
*----------------------------------------------------------------------------------------
*                            L I C E N S E
*----------------------------------------------------------------------------------------
* This file is part of the HANcoder Target Matlab/Simulink Blockset environment. For the
* licensing terms, please contact HAN Automotive.
*
* This software has been carefully tested, but is not guaranteed for any particular
* purpose. HAN Automotive does not offer any warranties and does not guarantee the
* accuracy, adequacy, or completeness of the software and is not responsible for any
* errors or omissions or the results obtained from use of the software.
*
* \endinternal
****************************************************************************************/
#ifndef FTOA_H
#define FTOA_H

/****************************************************************************************
* Function prototypes
****************************************************************************************/
char* ftoa(char* dest, double num, int afterPoint, char decimalSeparator);


#endif /* FTOA_H */
/********************************* end of ftoa.h ***************************************/


