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
typedef unsigned short int WORD;
typedef unsigned int DWORD;

//---------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	DWORD x, y, z;

	x = 0x08080808;
	y = x * 0x01010101;
	z = y >> 24;

    printf("%08X %08X %08X\n", x, y, z);

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
