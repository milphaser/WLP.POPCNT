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

	WORD src1[] = {0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
				   0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F};

	for(int i = 0; i < sizeof(src1)/sizeof(WORD); i++)
	{
		printf("%04X %d\n", src1[i], __pop_count(src1[i]));
	}

	printf("\n");
	system("pause");

	WORD src2[] = {0x0000, 0x0010, 0x0020, 0x0030, 0x0040, 0x0050, 0x0060, 0x0070,
				   0x0080, 0x0090, 0x00A0, 0x00B0, 0x00C0, 0x00D0, 0x00E0, 0x00F0};

	for(int i = 0; i < sizeof(src2)/sizeof(WORD); i++)
	{
		printf("%04X %d\n", src2[i], __pop_count(src2[i]));
	}

	printf("\n");
	system("pause");

	WORD src3[] = {0x0000, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0600, 0x0700,
				   0x0800, 0x0900, 0x0A00, 0x0B00, 0x0C00, 0x0D00, 0x0E00, 0x0F00};

	for(int i = 0; i < sizeof(src3)/sizeof(WORD); i++)
	{
		printf("%04X %d\n", src3[i], __pop_count(src3[i]));
	}

	printf("\n");
	system("pause");

	WORD src4[] = {0x0000, 0x0101, 0x0202, 0x0303, 0x0404, 0x0505, 0x0606, 0x0707,
				   0x0808, 0x0909, 0x0A0A, 0x0B0B, 0x0C0C, 0x0D0D, 0x0E0E, 0x0F0F};

	for(int i = 0; i < sizeof(src3)/sizeof(WORD); i++)
	{
		printf("%04X %d\n", src4[i], __pop_count(src4[i]));
	}

	printf("\n");
	system("pause");

//	WORD src = 0xCDEF;
//	WORD src = 0x0F0F;
//	printf("%04X %d\n", src, __pop_count(src));
//	system("pause");

	return 0;
}
//---------------------------------------------------------------------------
WORD __pop_count(WORD src)
//  ����� ���� �� ���������, ��������� �� ��� �������� ���� src
//  Word-Level Parallelism
//  Henry S. Warren, Jr. Hacker's Delight. Chapter 5, Eq. 1
//  ���� �� ���. ����� ����������: N = 3 + 4 + ((3 x 6) + (2 x 5)) + 1 = 36
{
	WORD x = src;
	WORD t = x;

	////////////////////////////////////////////////////////////////////////////
	//  Henry S. Warren, Jr. Hacker's Delight
	//  Instead of looping over the entire number,
	//	sum up the number in blocks of 4-bits and count them in parallel.
	////////////////////////////////////////////////////////////////////////////
	//  [1] Count the bits in each of the four 4-bits fields in parallel
	t = (t >> 1) & 0x7777;
	x = x - t;
	//
	t = (t >> 1) & 0x3333;
	x = x - t;
	//
	t = (t >> 1) & 0x1111;
	x = x - t;
	////////////////////////////////////////////////////////////////////////////
	//  [2] Sum the 2 pairs of 4-bits sums
	x = (x + (x >> 4)) & 0x0F0F;
	////////////////////////////////////////////////////////////////////////////
	//  [3] Sum the 1 pair of 8-bits sums
	x = (x + (x >> 8)) & 0x00FF;
	////////////////////////////////////////////////////////////////////////////

	return x;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
