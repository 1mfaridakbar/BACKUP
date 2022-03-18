#ifndef carwash_H
#define carwash_H

#include "boolean.h"
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<conio.h>
#define MAX 30

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
void keluarin(int flag,char alias[]);
int out(char alias[], struct antre* temp);
void tampilanAwal();
void judul();
void petunjuk();
int isEmpty();

int jumlahAntre[5];
int jumlahUmurAscending[5];
int jumlahUmur[5];
int age[3] = {35,50,80};
int clock = 15;
int antrean;
int jumlah_waktu;
