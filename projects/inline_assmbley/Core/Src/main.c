
#include "stdint.h"


int main()
{
	uint8_t var_1=0x10;
	uint8_t var_2=0x20;
	__asm volatile("MOV %0,%1":"=r"(var_2):"r"(var_1));
	
	while(1)
	{
	}
}