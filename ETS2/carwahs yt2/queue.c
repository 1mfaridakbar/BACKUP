#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

queue Q;
int x;

void initial(queue *Q)
{
	(*Q).head=0;
	(*Q).tail=0;
} 

void insert(queue *Q,int vmobil)
{
	if ((*Q).head < 10)
	{
		(*Q).tail = (*Q).tail + 1;
		(*Q).head = (*Q).head + 1;
		(*Q).mobil[(*Q).tail]=vmobil;
		printf("\n nomor antrian anda : %d \n Waktu Kedatangan : %d ", (*Q).tail, (*Q).mobil[(*Q).tail]);
	}
	else 
	{
		printf("Tidak dapat mengantri");
	}
}

void Delete(queue *Q,int *vmobil)
{
	if ((*Q).head == 0)
	{
		printf("\n Antrian kosong, dapat langsung dilayani");
	}
	else
	{
		*vmobil = (*Q).mobil[(*Q).head];
		printf("\n Mobil nomor antrian %d telah selesai dicuci", (*Q).head);
		(*Q).head = (*Q).head + 1;
	}
}

void sethead(queue *Q,int fn)
{
	(*Q).head = fn;
}

void settali(queue *Q,int fn)
{
	(*Q).tail = fn;
}

int isfull(queue Q)
{
	if ((Q).tail == 20)
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


int isempty(queue Q)
{
	if ((Q).head == 0)
	{
		printf(" \n Antrian masih Kosong, Anda dapat mengambil antrian ");
		return 0;
	}
	else
	{
		return 1;
	}
}

void reset(queue *Q)
{
	(*Q).head=0;
	(*Q).tail=0;
}
