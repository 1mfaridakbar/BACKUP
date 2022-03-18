#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#inlcude "l_wash.h"


void initial(list *L)
{
	head(*L)=0;
	tail(*L)=0;
} 

void insert(list *L,int vmobil);
{
	if (head(*L) < 10)
	{
		tail(*L) = tail(*L) + 1;
		head(*L) = head(*L) + 1;
		mobil(*L)[tail(*L)]=vmobil;
		printf("\n nomor antrian anda : %d \n Waktu Kedatangan : %d ", tail(*L), mobil(*L)[tail(*L)]);
	}
	else 
	{
		printf("Tidak dapat mengantri");
	}
}

void Delete(list *L,int *vmobil)
{
	if (head(*L) == 0)
	{
		printf("\n Antrian kosong, dapat langsung dilayani");
	}
	else
	{
		*vmobil = mobil(*L)[head(*L)];
		printf("\n Mobil nomor antrian %d telah selesai dicuci", head(*L));
		head(*L) = head(*L) + 1;
	}
}

void sethead(list *L,int fn)
{
	head(*L) = fn;
}

void settali(list *L,int fn)
{
	tail(*L) = fn;
}

int isfull(list L)
{
	if (tail(L) == 20)
	{
		printf(" \n Sudah Tidak bisa mengantri");
		return 0;
	}
	else
	{
		printf(" \n Anda dapat mengambil antrian");
		return 1;
	}
}


int isempty(list L)
{
	if (head(L) == 0)
	{
		printf(" \n Antrian masih Kosong, Anda dapat mengambil antrian ");
		return 0;
	}
	else
	{
		return 1;
	}
}

void reset(list *L)
{
	head(*L)=0;
	tail(*L)=0;
}
