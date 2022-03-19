#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include "carwash.h"
#include "boolean.h"

int main(){
	int pilih_menu,exit;
	
	tampilanAwal();

	do{
		system("cls");
		tampilkan();
		menu(&pilih_menu);
		menuTerpilih(pilih_menu,&exit);
	}while(exit != 1);

	return 0;
}

