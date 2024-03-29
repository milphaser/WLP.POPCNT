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
	printf("Counts the number of 1s in the src\n");

	BYTE src = 0x00;
	printf("src = %02X dst = %d\n", src, __bit_counter(src));

	src = 0xFF;
	printf("src = %02X dst = %d\n", src, __bit_counter(src));

	src = 0x08;
	printf("src = %02X dst = %d\n", src, __bit_counter(src));

	src = 0x5A;
	printf("src = %02X dst = %d\n", src, __bit_counter(src));

	src = 0x13;
	printf("src = %02X dst = %d\n", src, __bit_counter(src));

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
BYTE __bit_counter(BYTE src)
//  ����� ���� �� ���������, ��������� �� ��� ������� ���� src
{
//	BYTE result;

	__asm
	{
			//  �������� AL � DL �� ��������� �� ��������������, �. �.
			//  ���������� �� ��������� �� ����� ������������ ���� �������� AL
			mov EBX, 8
			mov CL, [src]
			xor AL, AL

	L_LOOP:	shl CL, 1

			// Branch Elimination Technique
			sbb DL, DL
			and DL, 0x01
			add AL, DL

			dec EBX
			jnz L_LOOP

//            mov [result], AL
	}

//	��� ���������� �� ����������� ����������,
//	���������� �� ����� ������ ���� �������� EAX
//	� ���������� ������� ���������� result �� � ������������,
//  �� �� � ������ � �� �� ��������
//    return result;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
