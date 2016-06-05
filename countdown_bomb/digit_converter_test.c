#include <stdio.h>

//          TOP
//      RI2	LE1
//          MID
//      RI1     LE2
// DOT      BOT    

// DOT BOT MID TOP RI2 RI1 LE2 LE1

#define COD0 0x00 // 00000000
#define COD1 0x03 // 00000011
#define COD2 0x79 // 01111001
#define COD3 0x73 // 01110011
#define COD4 0x2B // 00101011
#define COD5 0x7A // 01111010
#define COD6 0x6D // 01101110
#define COD7 0x13 // 00010011
#define COD8 0x7F // 01111111
#define COD9 0x3B // 00111011

#define ATOI(a) (a & 0x0f)

void showNum(char val, int count);

int main(int argc, char **argv)
{

	char segs[] = { COD0, COD1, COD2, COD3, COD4, COD5, COD6, COD7, COD8, COD9 };

	char val;

	printf("Insert the number to convert: ");
	scanf("%c", &val);

	printf("Converted value: %x\n", segs[ ATOI(val) ]);	

	showNum(segs[ATOI(val)], 0);

}

void showNum(char val, int count)
{
	if (count==8)
	{
		return;
	}

	printf("%d %x\n", count, (val>>count)&0x01);
	
	showNum((val), (++count));

}
