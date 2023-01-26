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
//  Word-Level Parallelism
//  Henry S. Warren, Jr. Hacker's Delight. Chapter 5, Eq. 1
//  Брой на осн. група инструкции: N = 3 + 4 + ((3 x 7) + 6) + 1 = 35
{
	BYTE x = src;
	BYTE t = x;

	////////////////////////////////////////////////////////////////////////////
	//  Henry S. Warren, Jr. Hacker's Delight
	//  Instead of looping over the entire number,
	//	sum up the number in blocks of 4-bits and count them in parallel.
	////////////////////////////////////////////////////////////////////////////
	//  [1] Count the bits in each of the two 4-bits fields in parallel
	t = (t >> 1) & 0x77;
	x = x - t;
	//
	t = (t >> 1) & 0x33;
	x = x - t;
	//
	t = (t >> 1) & 0x11;
	x = x - t;
	////////////////////////////////////////////////////////////////////////////
	//  [2] Sum 1 pair of 4-bits sums
	x = (x + (x >> 4)) & 0x0F;
	////////////////////////////////////////////////////////////////////////////

	return x;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
