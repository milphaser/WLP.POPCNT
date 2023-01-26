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
	printf("(Counts the number of 1s in the src)\n\n");

	BYTE src[] = {0x00, 0xFF, 0x08, 0x5A, 0x13};

	for(int i = 0; i < sizeof(src)/sizeof(BYTE); i++)
	{
		printf("%02X %d\n", src[i], __pop_count(src[i]));
	}

	printf("\n");

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
BYTE __pop_count(BYTE src)
//  Връща броя на единиците, съдържащи се във входния байт src
//  https://web.archive.org/web/20151229003112/http://blogs.msdn.com/b/jeuge/archive/2005/06/08/hakmem-bit-count.aspx
//  Брой на осн. група инструкции: N = 2 + k.5
//  - k(min) = 0 => N = 2 + 0.5 = 2
//  - k(avg) = 4 => N = 2 + 4.5 = 22
//  - k(max) = 8 => N = 2 + 8.5 = 42
{
//	BYTE result;

	__asm
	{
				mov BL, [src]
				xor AL, AL

	L_LOOP:     mov DL, BL
				and DL, 0x01
				add AL, DL

				shr BL, 1
                jnz L_LOOP

//				mov [result], AL
	}

//	При използване на класическия компилатор,
//	резултатът се връща неявно през регистър EAX
//	и междинната буферна променлива result не е задължителна,
//  но не е грешно и да се използва
//    return result;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
