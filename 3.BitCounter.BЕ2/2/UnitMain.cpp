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
//  Брой на осн. група инструкции: 2 + 8.4 = 34
{
//	BYTE result;

	__asm
	{
			//  Регистри AL и DL са разменени по предназанчение, т. к.
			//  резултатът от функцията се връща задължително през регистър AL
			mov CL, [src]
			xor AL, AL

			//--- 7 ----
			shl CL, 1
			// Branch Elimination Technique
			sbb DL, DL
			and DL, 0x01
			add AL, DL

			//--- 6 ----
			shl CL, 1
			// Branch Elimination Technique
			sbb DL, DL
			and DL, 0x01
			add AL, DL

			//--- 5 ----
			shl CL, 1
			// Branch Elimination Technique
			sbb DL, DL
			and DL, 0x01
			add AL, DL

			//--- 4 ----
			shl CL, 1
			// Branch Elimination Technique
			sbb DL, DL
			and DL, 0x01
			add AL, DL

			//--- 3 ----
			shl CL, 1
			// Branch Elimination Technique
			sbb DL, DL
			and DL, 0x01
			add AL, DL

			//--- 2 ----
			shl CL, 1
			// Branch Elimination Technique
			sbb DL, DL
			and DL, 0x01
			add AL, DL

			//--- 1 ----
			shl CL, 1
			// Branch Elimination Technique
			sbb DL, DL
			and DL, 0x01
			add AL, DL

			//--- 0 ----
			shl CL, 1
			// Branch Elimination Technique
			sbb DL, DL
			and DL, 0x01
			add AL, DL

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
