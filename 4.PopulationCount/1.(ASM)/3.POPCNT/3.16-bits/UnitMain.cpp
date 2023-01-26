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
	printf("(Counts the number of 1s in the src)\n");
	printf("[Implementation by POPCNT x86 Instruction]\n\n");

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
WORD __pop_count(WORD src)
//  Връща броя на единиците, съдържащи се във входния операнд src
//  [Implementation by POPCNT x86 Instruction]
//	Before an application attempts to use the POPCNT instruction,
//	it must check that the processor supports SSE4.2 (if
//	CPUID.01H:ECX.SSE4_2[bit 20] = 1) and POPCNT (if CPUID.01H:ECX.POPCNT[bit 23] = 1).
{
//	WORD result;

	__asm
	{
		mov AX, [src]
        popcnt AX, AX

//		mov [result], AX
	}

//	При използване на класическия компилатор,
//	резултатът се връща неявно през регистър EAX
//	и междинната буферна променлива result не е задължителна,
//  но не е грешно и да се използва
//    return result;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
