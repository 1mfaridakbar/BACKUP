#include <stdio.h>
#include <stdlib.h>
#inlude "l_wash.h"
#define MNT 60
#define JAM 4

int main()
{
	list antrian, antrian2;
	int jenis_mobil;
	int tempat1=0, tempat2=0;
	int temp1=0, temp2=0;
	int waktu_dtg, waktu_A=0, waktu_B=0;
	int statusB=1;
	char pengantri='y';
	
	initial(&antrian);
	initial(&antrian2);
	
	printf("\n 1.) Mobil Jenis A = 30 menit \n 2. Mobil jenis B = 45 menit \n 3. Mobil jenis C = 75 menit\n\n ");
	
	while (pengantri == 'y' && (tempat1<300 || tempat2<300))
	{
		printf("\n\n Jenis Mobil : "); scanf("%d", &jenis_mobil);
		printf("\n\n Waktu Kedatangan : "); scanf("%d", &waktu_dtg);
		
		if ((statusB==1 && waktu_A<=waktu_B || waktu_A<waktu_B))
	}
}
