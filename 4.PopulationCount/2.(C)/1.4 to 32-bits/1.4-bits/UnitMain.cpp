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

	BYTE src[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
				  0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

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
//  Връща броя на единиците, съдържащи се в мл. терада на входния байт src
//  Henry S. Warren, Jr. Hacker's Delight. Chapter 5, Eq. 1
{
//	BYTE x = src & 0xF;
//	BYTE t = x;
//
//	while(t != 0)
//	{
//		t >>= 1;
//		x -= t;
//	}
//
//	return x;

	BYTE x = src & 0xF;
	BYTE t = x;

	//  Count the bits in the one 4-bits field
	t = t >> 1;
	x = x - t;

	t = t >> 1;
	x = x - t;

	t = t >> 1;
	x = x - t;

    return x;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
