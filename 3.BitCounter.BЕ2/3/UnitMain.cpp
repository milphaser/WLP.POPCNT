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
	printf("Counts the number of 1s in the src\n");

	BYTE src = 0x00;
	printf("src = %02X dst = %d\n", src, __bit_counter(src));

	src = 0xFF;
	printf("src = %02X dst = %d\n", src, __bit_counter(src));

	src = 0x08;
	printf("src = %02X dst = %d\n", src, __bit_counter(src));

	src = 0x5A;
	printf("src = %02X dst = %d\n", src, __bit_counter(src));

	src = 0x13;
	printf("src = %02X dst = %d\n", src, __bit_counter(src));

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
BYTE __bit_counter(BYTE src)
//  Връща броя на единиците, съдържащи се във входния байт src
//  Пълно развиване на циклите
//  Брой на осн. група инструкции: 1 + 8.4 = 33
{
//	BYTE result;

	__asm
	{
			//  Регистри AL и DL са разменени по предназанчение, т. к.
			//  резултатът от функцията се връща задължително през регистър AL
			xor AL, AL

			//--- 0 ----
			mov BL, 0x01
			mov CL, [src]
			and BL, CL
			add AL, BL

			//--- 1 ----
			mov BL, 0x01
			shr CL, 1
			and BL, CL
			add AL, BL

			//--- 2 ----
			mov BL, 0x01
			shr CL, 1
			and BL, CL
			add AL, BL

			//--- 3 ----
			mov BL, 0x01
			shr CL, 1
			and BL, CL
			add AL, BL

			//--- 4 ----
			mov BL, 0x01
			shr CL, 1
			and BL, CL
			add AL, BL

			//--- 5 ----
			mov BL, 0x01
			shr CL, 1
			and BL, CL
			add AL, BL

			//--- 6 ----
			mov BL, 0x01
			shr CL, 1
			and BL, CL
			add AL, BL

			//--- 7 ----
			mov BL, 0x01
			shr CL, 1
			and BL, CL
			add AL, BL

//            mov [result], AL
	}

//	При използване на класическия компилатор,
//	резултатът се връща неявно през регистър EAX
//	и междинната буферна променлива result не е задължителна,
//  но не е грешно и да се използва
//    return result;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
