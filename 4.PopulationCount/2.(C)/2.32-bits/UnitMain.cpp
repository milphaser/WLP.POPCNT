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
	printf("Counts the number of 1s in the src\n");
	printf("[WLP Application]\n\n");

	DWORD src[] = {0x00, 0xFF, 0x08, 0x5A, 0x13};

	for(int i = 0; i < sizeof(src)/sizeof(DWORD); i++)
	{
		printf("%02X %d\n", src[i], __pop_count(src[i]));
	}

	printf("\n");

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
DWORD __pop_count(DWORD x)
//  Връща броя на единиците, съдържащи се във входния операнд от тип DWORD
//	[WLP Application]
//  https://web.archive.org/web/20151229003112/http://blogs.msdn.com/b/jeuge/archive/2005/06/08/hakmem-bit-count.aspx
//  Henry S. Warren, Jr. Hacker's Delight
//  NOTE: Да се обърне внимание, че в транслирания код се съдържа инструкция DIV.
//  Тя изисква няколко десетки машинни цикъла (Agner Fog's 4.instruction_tables.pdf)!!!
{
	//  Instead of looping over the entire number,
	//	sum up the number in blocks of 3 (octal) and count them in parallel.
	//  Note: Constants are octal

	//  Ver. 1
	//  https://web.archive.org/web/20151229003112/http://blogs.msdn.com/b/jeuge/archive/2005/06/08/hakmem-bit-count.aspx
//	DWORD Count = x - ((x >> 1) & 033333333333) - ((x >> 2) & 011111111111);
//	return ((Count + (Count >> 3)) & 030707070707) % 63;

	//  Ver. 2
	//  Henry S. Warren, Jr. Hacker's Delight
	//  Count bits in each 3-bit field
	DWORD t = (x >> 1) & 033333333333;
	x = x - t;
	t = (t >> 1) & 033333333333;
	x = x - t;
	//  6-bit sums
	x = (x + (x >> 3)) & 030707070707;
	//  Add 6-bit sums
	return x % 63;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
