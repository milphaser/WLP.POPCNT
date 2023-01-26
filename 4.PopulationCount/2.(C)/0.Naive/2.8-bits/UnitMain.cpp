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

	BYTE src1[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
				   0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

	for(int i = 0; i < sizeof(src1)/sizeof(BYTE); i++)
	{
		printf("%02X %d\n", src1[i], __pop_count(src1[i]));
	}

	printf("\n");
	system("pause");

	BYTE src2[] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70,
				   0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0};

	for(int i = 0; i < sizeof(src2)/sizeof(BYTE); i++)
	{
		printf("%02X %d\n", src2[i], __pop_count(src2[i]));
	}

	printf("\n");
	system("pause");

	return 0;
}
//---------------------------------------------------------------------------
BYTE __pop_count(BYTE src)
//  Връща броя на единиците, съдържащи се във входния байт src
//  Брой на осн. група инструкции: N = 3 + 2 + (k x 6) + 1
//  - k(min) = 0 => N = 3 + 2 + (0 x 6) + 1 = 6
//  - k(avg) = 4 => N = 3 + 2 + (4 x 6) + 1 = 30
//  - k(max) = 8 => N = 3 + 2 + (8 x 6) + 1 = 54
{
	BYTE count = 0;

	while(src != 0)
	{
		count += src & 0x01;
		src >>= 1;
	}

	return count;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
