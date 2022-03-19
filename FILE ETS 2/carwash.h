/* File        : SpNRSLL.h */
/* Deskripsi   : ADT list berkait dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Diedit oleh : Muhamad Farid Akbar (211511045) */
/* Tanggal     : 10-3-2022 */
/* Tanggal Rev 1    : 12-3-2022 */
/* Tanggal Rev 2    : 15-3-2022 */
/* Tanggal Pengeditan QUEUE    : 17-3-2022 */


#ifndef carwash_H
#define carwash_H
#include "boolean.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>


struct antre{
	char nopol[10];
	int jenis;
	int waktu;
	int waktu_dtg;
	struct antre *next;
} *startSatu = NULL, *startDua = NULL;


void enqueue(char alias[], int jenis);
void enq(struct antre *buat, struct antre *temp, int pilihan);
void dequeue(int pilih);
void notif(char alias[], int jenis);
int ceknopol(char alias[], int *flag);
void menuTerpilih(int mt, int *exit);
void continuesButton();
void menu(int *pm);
int out(char alias[], struct antre* temp);
void tampilanAwal();
void tampilkan();
int jenisCuci();
void countwaktu();
void keluarin(int flag, char alias[]);
void simulasiWaktu();
void checkwaktuStart();
int pilih();
void judul();
int isEmpty();
void petunjuk();


int jumlah_waktu;
int jumlahwaktu[2];
int jumlahwaktunaik[2];
int jumlahAntre[2];
int waktucuci[3] = {35,50,80};
int waktucucitmpl[3] = {30,45,75};
int clock = 10;
int antrean;



#endif
