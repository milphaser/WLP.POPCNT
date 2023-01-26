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

typedef unsigned char BYTE;

//---------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
//	BYTE src = 0x5A;
//	BYTE src = 0x13;
//	BYTE src = 0xAA;
//	BYTE src = 0xA5;
//	BYTE src = 0x55;
//	BYTE src = 0x00;
	BYTE src = 0xFF;
	BYTE dst;

	printf("Counts the number of 1s in the src\n");

	__asm
	{
			mov EBX, 8
			mov cl, [src]
			mov dl, 0

	L_LOOP:
			shl cl, 1
			jnc L_SKIP      // Classical branching
			inc dl
	L_SKIP:

			dec EBX
			jnz L_LOOP

			mov [dst], dl
	}

	printf("src = %02X\n", src);
	printf("dst = %d\n", dst);

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
