#ifndef carwash_H
#define carwash_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>

struct antre{
	char nama[10];
	int tipe;
	int umur;
	struct antre *next;
}*startSatu = NULL, *startDua = NULL;

void tampilkan();
void menu(int *pm);
void menuTerpilih(int mt,int *exit);
void continuesButton();
int cekNama(char alias[], int *flag);
int tipeCuci();
void countAntre();
void countUmur();
void enqueue(char alias[],int tipe);
int pilih();
void enq(struct antre *make, struct antre *temp, int choice);
void notif(char alias[], int tipe);
void simulasiWaktu();
void checkUmurStart();
void dequeue(int pilih);
void tambahPendapatan(int pilih);
void keluarin(int flag,char alias[]);
int out(char alias[], struct antre* temp);
void tampilanAwal();
void judul();
void petunjuk();
int isEmpty();

int jumlahAntre[5];
int jumlahUmurAscending[5];
int jumlahUmur[5];
int age[3] = {30,45,75};
int harga[3] ={40000,50000,60000};
int clock = 15;
int antrean;
int jumlah_pendapatan;
int jumlah_waktu;
