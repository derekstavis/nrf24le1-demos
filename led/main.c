#include <reg24le1.h>
#include <delay.h>

#define P00 P0_SB_D0
#define P01 P0_SB_D1
#define P02 P0_SB_D2
#define P03 P0_SB_D3
#define P04 P0_SB_D4
#define P05 P0_SB_D5
#define P06 P0_SB_D6

void
main(void)
{
	P0DIR = 0x00;

	while (1){

		P01 = !P01;
		P02 = !P02;
		P03 = !P03;
		P04 = !P04;
		P05 = !P05;
		P06 = !P06;

		delay_s(2);

	}
}
