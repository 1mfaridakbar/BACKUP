
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "carw.h"



boolean ListEmpty (List L)
{
	return(First(L) == Nil);
}


void CreateList (List * L)
{
	First(*L) = Nil;
}

address Alokasi (infotype X)
{
	address P;
	
	P=(address) malloc (sizeof(ElmtList));
	if (P!=Nil){
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}
	else {
		return Nil;
		}
}

void DeAlokasi (address P)
{
	free(P);
}

void enqueue (List * L, infotype X)
{
	address P;
	
	P = Alokasi(X);
	if (P != Nil){
		InsertLast(&(*L),P);
	}
}


void dequeue (List * L, infotype * X)
{
	address P;
	
	P = First(*L);
	DelFirst(&(*L), &P);
	*X = Info(P);
	DeAlokasi(P);
}

void InsertFirst (List * L, address P)
{
	Next(P) = First(*L);
	First(*L) = P;
}


void InsertLast (List * L, address P)
{
	address Last;
	
	if (ListEmpty(*L)) {
		InsertFirst(&(*L), P);
	} else {
		Last = First(*L);
		
		while (Next(Last) != Nil)
		{
			Last = Next(Last);
		}

		Next(Last) = P;
	}
}


void DelFirst (List * L, address * P)
{
	*P = First(*L);
	First(*L) = Next(First(*L));
	Next(*P) = Nil;
}


void Setfirst(List * L, address P)
{
	First(*L) = P;
}

void Set

