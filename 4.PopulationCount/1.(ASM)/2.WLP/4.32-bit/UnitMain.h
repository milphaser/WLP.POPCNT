//---------------------------------------------------------------------------

#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
typedef unsigned char BYTE;
typedef unsigned short int WORD;
typedef unsigned int DWORD;

DWORD __pop_count(DWORD src);
WORD __pop_count(WORD src);
BYTE __pop_count(BYTE src);
BYTE __pop_count_4(BYTE src);
//---------------------------------------------------------------------------
#endif
