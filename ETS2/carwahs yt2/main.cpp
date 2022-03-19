#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#define MNT 60
#define JAM 4

int main()
{
	queue antrian, antrian2;
	int jenis_mobil;
	int tempat1=0, tempat2=0;
	int temp1=0, temp2=0;
	int waktu_dtg, waktu_A=0, waktu_B=0;
	int statusB=1;
	char pengantri;
	
	initial(&antrian);
	initial(&antrian2);
	
	printf("\n 1.) Mobil Jenis A = 30 menit \n 2. Mobil jenis B = 45 menit \n 3. Mobil jenis C = 75 menit\n\n ");
	printf("\n apakah anda mau mencuci \n\n ");
	scanf("%c", &pengantri);
	
	while(pengantri == 'y' && (tempat1<300 || tempat2<300))
	{
		printf("\n\n Jenis Mobil : "); scanf("%d", &jenis_mobil);
		printf("\n\n Waktu Kedatangan : "); scanf("%d", &waktu_dtg);
		
		if ((statusB==1 && waktu_A<=waktu_B) || waktu_A<waktu_B)
		{
			printf("\n Mobil ini masuk antrian A");
			insert(&antrian,waktu_dtg);
			
			if(tempat1==0){
				temp1=waktu_dtg;
			}
			else 
			{
				temp1=tempat1;
			}
			if (waktu_dtg>waktu_A)
			{
				waktu_A=waktu_dtg;
			}
			if (jenis_mobil == 1)
			{
				tempat1 = waktu_A + 35;
			}
				else if (jenis_mobil == 2)
				{
					tempat1 = waktu_A + 50;
				}
				else if (jenis_mobil == 3)
				{
					tempat1 = waktu_A + 80;
				}
				
				printf("\n Mobil ini akan dicuci pada : %d ", temp1);
				printf("\n Mobil ini akan selsai pada : %d ", tempat1);
				statusB=0;
				waktu_A=tempat1;
			}
		else 
		{
			printf("\n Mobil ini masuk antrian B");
			insert(&antrian2,waktu_dtg);
			
			if(tempat2 == 0){
				temp2 = waktu_dtg;
			}
			else 
			{
				temp2 = tempat2;
			}
			if (waktu_dtg>waktu_B)
			{
				waktu_B = waktu_dtg;
				temp2 = waktu_B;
			}
			if (jenis_mobil == 1)
			{
				tempat2 = waktu_B + 35;
			}
				else if (jenis_mobil == 2)
				{
					tempat2 = waktu_B + 50;
				}
				else if (jenis_mobil == 3)
				{
					tempat2 = waktu_B + 80;
				}
				
				printf("\n Mobil ini akan dicuci pada : %d ", temp2);
				printf("\n Mobil ini akan selsai pada : %d ", tempat2);
				statusB=1;
				waktu_B=tempat2;
			}
		}
		printf("\n apakah masih ada yang mengantri (y/n): "); 
		scanf("%c", &pengantri);
		return(1);
	}
	
	
	

