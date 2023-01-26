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

	DWORD src[] = {0x0000,
				  0x0001, 0x0010, 0x0100, 0x1000,
				  0x0002, 0x0020, 0x0200, 0x2000,
				  0x0003, 0x0030, 0x0300, 0x3000,
				  0x000F, 0x00F0, 0x0F00, 0xF000,
				  0xFFFF, 0XFFFFFFFF};

	for(int i = 0; i < sizeof(src)/sizeof(DWORD); i++)
	{
		printf("%04X %d\n", src[i], __pop_count(src[i]));
	}

	printf("\n");

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
DWORD __pop_count(DWORD src)
//  Връща броя на единиците, съдържащи се във входната двойна дума src
//	[WLP Application]
//  Брой на осн. група инструкции: 1+5.5 = 26
{
//	DWORD result;

	__asm
	{
			//  Init
			mov EAX, [src]

			//  Add 16 groups of single bits (half adder)
			mov EDX, EAX
			shr EDX, 1
			and EDX, 0x55555555
			and EAX, 0x55555555
			add EAX, EDX

			//  Add 8 groups of two bits
			mov EDX, EAX
			shr EDX, 2
			and EDX, 0x33333333
			and EAX, 0x33333333
			add EAX, EDX

			//  Add 4 groups of four bits
			mov EDX, EAX
			shr EDX, 4
			and EDX, 0x0F0F0F0F
			and EAX, 0x0F0F0F0F
			add EAX, EDX

			//  Add 2 groups of eight bits
			mov EDX, EAX
			shr EDX, 8
			and EDX, 0x00FF00FF
			and EAX, 0x00FF00FF
			add EAX, EDX

			//  Add 1 group of sixteen bits
			mov EDX, EAX
			shr EDX, 16
			and EDX, 0x0000FFFF
			and EAX, 0x0000FFFF
			add EAX, EDX

//            mov [result], EAX
	}

//	При използване на класическия компилатор,
//	резултатът се връща неявно през регистър EAX
//	и междинната буферна променлива result не е задължителна,
//  но не е грешно и да се използва
//    return result;
}
//---------------------------------------------------------------------------
WORD __pop_count(WORD src)
//  Връща броя на единиците, съдържащи се във входната дума src
//	[WLP Application]
//  Брой на осн. група инструкции: 1+4.5 = 21
{
//	WORD result;

	__asm
	{
			//  Init
			mov AX, [src]

			//  Add 8 groups of single bits (half adder)
			mov DX, AX
			shr DX, 1
			and DX, 0x5555
			and AX, 0x5555
			add AX, DX

			//  Add 4 groups of two bits
			mov DX, AX
			shr DX, 2
			and DX, 0x3333
			and AX, 0x3333
			add AX, DX

			//  Add 2 groups of four bits
			mov DX, AX
			shr DX, 4
			and DX, 0x0F0F
			and AX, 0x0F0F
			add AX, DX

			//  Add 1 group of eight bits
			mov DX, AX
			shr DX, 8
			and DX, 0x00FF
			and AX, 0x00FF
			add AX, DX

//            mov [result], AX
	}

//	При използване на класическия компилатор,
//	резултатът се връща неявно през регистър AX
//	и междинната буферна променлива result не е задължителна,
//  но не е грешно и да се използва
//    return result;
}
//---------------------------------------------------------------------------
BYTE __pop_count(BYTE src)
//  Връща броя на единиците, съдържащи се във входния байт src
//	[WLP Application]
//  Брой на осн. група инструкции: 1+3.5 = 16
{
//	BYTE result;

	__asm
	{
			//  Init
			mov AL, [src]

			//  Add 4 groups of single bits (half adder)
			mov DL, AL
			shr DL, 1
			and DL, 0x55
			and AL, 0x55
			add AL, DL

			//  Add 2 groups of two bits
			mov DL, AL
			shr DL, 2
			and DL, 0x33
			and AL, 0x33
			add AL, DL

			//  Add 1 group of four bits
			mov DL, AL
			shr DL, 4
			and DL, 0x0F
			and AL, 0x0F
			add AL, DL

//            mov [result], AL
	}

//	При използване на класическия компилатор,
//	резултатът се връща неявно през регистър AL
//	и междинната буферна променлива result не е задължителна,
//  но не е грешно и да се използва
//    return result;
}
//---------------------------------------------------------------------------
BYTE __pop_count_4(BYTE src)
//  Връща броя на единиците, съдържащи се във входния байт src
//  NOTE: Този първоначален вариант работи с мл. тетрада на src
//	[WLP Application]
//  Брой на осн. група инструкции: 1+2.5 = 11
{
//	BYTE result;

	__asm
	{
			//  Init
			mov AL, [src]
			and AL, 0x0F

			//  Add 4 groups of single bits (half adder)
			mov DL, AL
			shr DL, 1
			and DL, 0x05
			and AL, 0x05
			add AL, DL

			//  Add 2 groups of two bits
			mov DL, AL
			shr DL, 2
			and DL, 0x03
			and AL, 0x03
			add AL, DL

//            mov [result], AL
	}

//	При използване на класическия компилатор,
//	резултатът се връща неявно през регистър AL
//	и междинната буферна променлива result не е задължителна,
//  но не е грешно и да се използва
//    return result;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
