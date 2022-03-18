#ifndef carw_H
#define carw_H



#include <stdio.h>
#include <conio.h>
#include "boolean.h"

#define MAX 30

typedef char* infotype;
typedef struct tElmtList *address;
typedef struct{
	int data[MAX];
	address First;
	int next;
}List;

boolean ListEmpty (List L);
void CreateList (List * L);
address Alokasi (infotype X);
void DeAlokasi (address P)
void enqueue (List * L, infotype X);
void InsertLast (List * L, address P);
void InsertFirst (List * L, address P);
void dequeue (List * L, infotype * X);
void DelFirst (List * L, address * P);
void SetFirst(List * L, address P);
void SetLast(List * L, address P);
void DelAll(List * L);


void jamdatang();	// untuk memvalidasi waktu kedatangan
void antrian();		// untuk masuk antrian
void mobil();		// untuk memvalidasi jenis mobil
void waktu();		// untuk memvalidasi waktu pencucian
void tutup();		// untuk memvalidasi bila tutup
