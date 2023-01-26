//---------------------------------------------------------------------------

#pragma hdrstop
#pragma argsused


#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
#include "UnitMain.h"

//---------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	printf("Population Count\n");
	printf("Counts the number of 1s in the src\n");
	printf("[WLP Application]\n\n");

//	BYTE src[] = {0x00, 0xFF, 0x08, 0x5A, 0x13};
//	BYTE src[] = {0x0D, 0x00, 0x0F, 0x08, 0x0A, 0x03};
//	BYTE src[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
//	              0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
//	BYTE src[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
//				  0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
//				  0xF0, 0xE1, 0xD2, 0xC3, 0xB4, 0xA5, 0x96, 0x87,
//				  0x78, 0x69, 0x5A, 0x4B, 0x3C, 0x2D, 0x1E, 0x0F};
	WORD src[] = {0x0000,
				  0x0001, 0x0010, 0x0100, 0x1000,
				  0x0002, 0x0020, 0x0200, 0x2000,
				  0x0003, 0x0030, 0x0300, 0x3000,
				  0x000F, 0x00F0, 0x0F00, 0xF000,
				  0xFFFF};

	for(int i = 0; i < sizeof(src)/sizeof(WORD); i++)
	{
		printf("%04X %d\n", src[i], __pop_count(src[i]));
	}

	printf("\n");

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
WORD __pop_count(WORD src)
//  Връща броя на единиците, съдържащи се във входната дума src
//	[WLP Application]
//  Брой на осн. група инструкции: 1+4.5 = 21
{
//	WORD result;

	__asm
	{
			//  Init
			mov AX, [src]

			//  Add 8 groups of single bits (half adder)
			mov DX, AX
			shr DX, 1
			and DX, 0x5555
			and AX, 0x5555
			add AX, DX

			//  Add 4 groups of two bits
			mov DX, AX
			shr DX, 2
			and DX, 0x3333
			and AX, 0x3333
			add AX, DX

			//  Add 2 groups of four bits
			mov DX, AX
			shr DX, 4
			and DX, 0x0F0F
			and AX, 0x0F0F
			add AX, DX

			//  Add 1 group of eight bits
			mov DX, AX
			shr DX, 8
			and DX, 0x00FF
			and AX, 0x00FF
			add AX, DX

//            mov [result], AX
	}

//	При използване на класическия компилатор,
//	резултатът се връща неявно през регистър AX
//	и междинната буферна променлива result не е задължителна,
//  но не е грешно и да се използва
//    return result;
}
//---------------------------------------------------------------------------
BYTE __pop_count(BYTE src)
//  Връща броя на единиците, съдържащи се във входния байт src
//	[WLP Application]
//  Брой на осн. група инструкции: 1+3.5 = 16
{
//	BYTE result;

	__asm
	{
			//  Init
			mov AL, [src]

			//  Add 4 groups of single bits (half adder)
			mov DL, AL
			shr DL, 1
			and DL, 0x55
			and AL, 0x55
			add AL, DL

			//  Add 2 groups of two bits
			mov DL, AL
			shr DL, 2
			and DL, 0x33
			and AL, 0x33
			add AL, DL

			//  Add 1 group of four bits
			mov DL, AL
			shr DL, 4
			and DL, 0x0F
			and AL, 0x0F
			add AL, DL

//            mov [result], AL
	}

//	При използване на класическия компилатор,
//	резултатът се връща неявно през регистър AL
//	и междинната буферна променлива result не е задължителна,
//  но не е грешно и да се използва
//    return result;
}
//---------------------------------------------------------------------------
BYTE __pop_count_4(BYTE src)
//  Връща броя на единиците, съдържащи се във входния байт src
//  NOTE: Този първоначален вариант работи с мл. тетрада на src
//	[WLP Application]
//  Брой на осн. група инструкции: 1+2.5 = 11
{
//	BYTE result;

	__asm
	{
			//  Init
			mov AL, [src]
			and AL, 0x0F

			//  Add 4 groups of single bits (half adder)
			mov DL, AL
			shr DL, 1
			and DL, 0x05
			and AL, 0x05
			add AL, DL

			//  Add 2 groups of two bits
			mov DL, AL
			shr DL, 2
			and DL, 0x03
			and AL, 0x03
			add AL, DL

//            mov [result], AL
	}

//	При използване на класическия компилатор,
//	резултатът се връща неявно през регистър AL
//	и междинната буферна променлива result не е задължителна,
//  но не е грешно и да се използва
//    return result;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
