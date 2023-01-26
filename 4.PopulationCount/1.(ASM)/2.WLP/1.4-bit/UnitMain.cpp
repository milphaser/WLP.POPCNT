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
	BYTE src[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
	              0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

	for(int i = 0; i < sizeof(src)/sizeof(BYTE); i++)
	{
		printf("%02X %d\n", src[i], __pop_count_4(src[i]));
	}

	printf("\n");

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
BYTE __pop_count_4(BYTE src)
//  Връща броя на единиците, съдържащи се във входния байт src
//  NOTE: Този първоначален вариант работи с мл. тетрада на src
//	[WLP Application]
//  Брой на осн. група инструкции: 2+2.5 = 12
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
