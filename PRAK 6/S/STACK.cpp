/* File        : SpNRSLL.h */
/* Deskripsi   : ADT list berkait dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Diedit oleh : Muhamad Farid Akbar (211511045) */
/* Tanggal     : 10-3-2022 */
/* Tanggal Rev 1    : 12-3-2022 */
/* Tanggal Rev 2    : 15-3-2022 */
/* Tanggal Pengeditan STACK    : 17-3-2022 */


#include "STACK.h"
#include <stdio.h>
#include <stdlib.h>


boolean ListEmpty (List L)
/* Mengirim true jika List Kosong */
{
	return(First(L) == Nil);
}
/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	First(*L) = Nil;
}
/**** Manajemen Memory ****/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
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
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	free(P);
}
/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
{
	address P;
	boolean Q;
	
	P = First(L);
	Q = false;
	while ((P != Nil) && (!Q)) {
		if (X == Info(P)) {
			Q = true;
		}
		else {
			P = Next(P);
		}
	}

}
boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	address Ps;
	boolean Q;
	
	Ps = First(L);
	Q = false;
	while ((Ps != Nil)&&(!Q)){
		if(Ps == P){
			Q = true;
		}
		else {
			Ps = Next(Ps);
		}
	}
	return Q;
}
	
address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
	address Prec;
	address P;

	if (Next(P) == Nil) {
		Prec = Nil;
	} else {
		P = First(L);
		
		while ((Next(P) != Nil) && (Info(P) != X))
		{
			Prec = P;
			P = Next(P);
		}

		if (Info(P) == X)
		{
			return Prec;
		} else {
			return Nil;
		}
	}
}
/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (List * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P;
	
	P = Alokasi(X);
	if (P != Nil){
		InsertFirst(&(*L),P);
	}
}
void push (List * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
	address P;
	
	P = Alokasi(X);
	if (P != Nil){
		InsertLast(&(*L),P);
	}
}
/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */
{
	address P;
	
	P = First(*L);
	DelFirst(&(*L), &P);
	*X = Info(P);
	DeAlokasi(P);
}
void pop (List * L, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
{
	address P;
	DelLast(&(*L), &P);
	*X = Info(P);
	DeAlokasi(P);
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P) = First(*L);
	First(*L) = P;
}
void InsertAfter (List * L, address P, address Prec)
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
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
/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Next(First(*L));
	Next(*P) = Nil;
}
void DelP (List * L, infotype X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	address P;
	address Prec;
  	infotype Y;

  	P = First(*L);

  	if (Info(P) == X) {
    	DelVFirst(L, &Y);
  	} else {
    	Prec = P;
		P = Next(P);

    	while (P != Nil) {
      		if (Info(P) == X){
        		Next(Prec) = Next(P);
        		P = Nil;
      		} else {
        		Prec = P;
        		P = Next(P);
      		}
    	}
  	}
}
void DelLast (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
{
	address Last, PrecLast;

	Last = First(*L);

	if (Next(Last) == Nil) {
		DelFirst(&(*L), &(Last));
	} else {
		PrecLast = Nil;
		
		while (Next(Last) != Nil)
		{
			PrecLast = Last;
			Last = Next(Last);
		}
		
		*P = Last;
		Next(PrecLast) = Nil;
	}
}
void DelAfter (List * L, address * Pdel, address Prec)
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
}
/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L)
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
{
	int i;
	address P = First(L);
	
	if (P == Nil) {
		printf("List Kosong !\n");
	} else {
		printf("[ ");
		
		do
		{
			printf("%s ", Info(P));
			P = Next(P);
			i++;
		} while (P != Nil);
		
		printf("]");
	}
	
	printf("\n");
}

/***************************************/
/*******  PROSES TERHADAP LIST  ********/
/***************************************/
void DelAll (List * L)
/* Delete semua elemen list dan alamat elemen di dealokasi */
{
	infotype X;
	
	while (!ListEmpty(*L))
	{
		DelVFirst(&(*L), &X);
	}
}
