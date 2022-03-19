#include "carwash.h"
#include "boolean.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>


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


void tampilkan(){
	struct antre *temp1,*temp2;

	printf("\nTempat Cuci 1 ");
	if(startSatu == NULL){
		printf("( Kosong )");
	}else{
		temp1 = startSatu;
		printf("( %s, waktu sisa : %d menit) ",temp1->nopol,temp1->waktu);
		temp1 = temp1->next;
		while(temp1 != NULL){
			printf("<-- %s ",temp1->nopol);
			temp1 = temp1->next;
		}		
	}
	
	printf("\nTempat Cuci 2 ");
	if(startDua == NULL){
		printf("( Kosong )");
	}else{
		temp2 = startDua;
		printf("( %s, waktu sisa : %d menit) ",temp2->nopol,temp2->waktu);
		temp2 = temp2->next;
		while(temp2 != NULL){
			printf("<-- %s ",temp2->nopol);
			temp2 = temp2->next;
		}		
	}
	
}

void menu(int *pm){
	printf("\n\nMenu :\n");
	printf("1. Tambah Mobil Untuk Dicuci\n");
	printf("2. Keluarkan Mobil Dari Antrian\n");
	printf("3. simulasi waktu ( %d menit)\n",clock);
	printf("4. Petunjuk\n");
	printf("5. Selesai\n");
	do{
		printf("pilihan : ");scanf("%d",pm);
		if(*pm<1 || *pm>5){
			printf("pilihan diantara 1 - 5, silahkan isi lagi.\n");
		}
	}while(*pm<1 || *pm>5);
	
}

void menuTerpilih(int mt, int *exit){
	char alias[15];int dec, jenis, temp_waktu,flag,pil;
	switch(mt){
		case 1:
			do{
				printf("\nmasukkan nopol (sebagai identitas dari mobil) :");scanf("%s",&alias);
				dec = ceknopol(alias,&flag);
				if(dec != 0){
					printf("ada nopol pemilik mobil yang sama. silahkan isi dengan nopol yang berbeda.\n");
				}
			}while(dec != 0);
		//	waktu_dtg = waktuDatang();
			jenis = jenisCuci();
			if(jenis == 4){break;}
			enqueue(alias, jenis);
			notif(alias, jenis);
			continuesButton();
			*exit = 0;
			break;
		case 2:
			pil = isEmpty();
			if(pil == 0){
				printf("tidak ada mobil.");
				continuesButton();
				break;
			}
			do{
				flag = 0;
				printf("\nmasukkan nopol pemilik mobil yang mobilnya ingin dikeluarkan (jika tidak jadi isi 0) : ");scanf("%s",&alias);
				if(alias[0]=='0'){
					break;
				}
				dec = ceknopol(alias,&flag);
				if(dec == 0){
					printf("tidak ada mobil dengan nopol pemilik tersebut. silahkan isi dengan nopol yang berbeda.\n");
				}
			}while(dec == 0);
			keluarin(flag,alias);
			*exit = 0;
			break;
		case 3:
			simulasiWaktu();
			*exit = 0;
			break;
		case 4:
			petunjuk();
			*exit = 0;
			continuesButton();
			break;
		case 5:
			pil = isEmpty();
			if(pil != 0){
				printf("masih ada mobil yang sedang dicuci. tidak bisa keluar dari program.\n");
				continuesButton();
				*exit = 0;
				break;	
			}
			*exit = 1;
			system("cls");
			printf("Hari ini, dengan total waktu kerja %d menit, \n",jumlah_waktu);
			printf("THANK YOU!!!\n\n");
			judul();
			break;
	}
}

void continuesButton(){
	printf("\nTekan apapun untuk melanjutkan!");
	getch();
}

int ceknopol(char alias[], int *flag){
	struct antre *temp1,*temp2;
	temp1 = startSatu;
	temp2 = startDua;
	
	int check = 0;

	if(temp1 != NULL){
		while(temp1 != NULL){
			if(strcmp(alias,temp1->nopol) == 0){
				check++;
				*flag = 1;	
			}
			temp1 = temp1->next;
		}	
	}
	if(temp2 != NULL){
		while(temp2 != NULL){
			if(strcmp(alias,temp2->nopol) == 0){
				check++;
				*flag = 2;
			}
			temp2 = temp2->next;
		}	
	}
	return check;
}

int jenisCuci(){
	int ch;
	printf("\nNo.\t| jenis\t\t\t\t| Lama Pengerjaan\t|\n");
	printf("1.\t| JENIS A\t\t\t| %d\t\t\t|\n",waktucucitmpl[0]);
	printf("2.\t| JENIS B\t\t\t| %d\t\t\t|\n",waktucucitmpl[1]);
	printf("3.\t| JENIS C\t\t\t| %d\t\t\t|\n",waktucucitmpl[2]);
	printf("4. Tidak Jadi\n");
	do{
		printf("Pilihan : ");scanf("%d",&ch);
		if(ch<1 || ch>4){
			printf("pilihan diantara 1 - 4, silahkan isi lagi.\n");
		}
	}while(ch<1 || ch>4);
	return ch;
}

//void CreateTime(waktu &T){
//	T.hour = 0;
//	T.min = 0;
//}
//
//int scanWaktuJ()
//{
//	int swj;
//	
//	printf("Masukkan Jam Kedatangan : ");scanf("%d",&swj);
//	
//	return swj;
//}
//
//int scanWaktuM()
//{
//	int swm;
//	
//	printf("Masukkan Menit Kedatangan : ");scanf("%d",&swm);
//	
//	return swm;
//}
//
//
//bool IsTimeValid(waktu T){
//	if(7 <= T.hour && T.hour <= 12 || 13<= T.hour && T.hour <= 17){
//		if(0 <= T.min && T.min < 60){
//			return true;
//		}else{
//			return false;
//		}
//	}else{
//		return false;
//	}
//}
//
//void FixTime(waktu &T){
//	while(IsTimeValid(T)==false){
//		T.hour++;
//		T.min = 0;	
//	}		
//}


void countAntre(){
	
	int count;
	struct antre *temp1,*temp2;
	temp1 = startSatu;
	temp2 = startDua;
	
	count = 0;
	while(temp1 != NULL){
		temp1 = temp1->next;
		count++;
	}
	jumlahAntre[0] = count;
	
	count = 0;
	while(temp2 != NULL){
		
		temp2 = temp2->next;
		count++;
		
	}
	jumlahAntre[1] = count;
}

void countwaktu(){
	struct antre *temp1,*temp2;
	temp1 = startSatu;
	temp2 = startDua;
	
	jumlahwaktu[0] = 0;jumlahwaktu[1] = 0;
	
	if(startSatu == NULL){
		jumlahwaktu[0] = 0;
	}else{
		while(temp1!=NULL){
			jumlahwaktu[0] += temp1->waktu;
			temp1 = temp1->next;
		}	
	}
	if(startDua == NULL){
		jumlahwaktu[1] = 0;
	}else{
		while(temp2!=NULL){
			jumlahwaktu[1] += temp2->waktu;
			temp2 = temp2->next;
		}
	}
}

void enqueue(char alias[], int jenis){
	int pilihan;
	
	struct antre *buat, *temp;
	buat = (struct antre*)malloc(sizeof(struct antre));
	
	if(buat == NULL){
		printf("\nerror, tidak tersedia memori\n");
	}else{
		strcpy(buat->nopol,alias);
		buat->next = NULL;
		switch(jenis){
			case 1:
				buat->jenis = 1;
				buat->waktu = waktucuci[0];
				break;
			case 2:
				buat->jenis = 2;
				buat->waktu = waktucuci[1];
				break;
			case 3:
				buat->jenis = 3;
				buat->waktu = waktucuci[2];	
		}
	}
	
	countwaktu();
	pilihan = pilih();
	switch(pilihan){
		case 0:
			temp = startSatu;
			enq(buat,temp,pilihan);
			break;
		case 1:
			temp = startDua;
			enq(buat,temp,pilihan);
			break;
	}
}

int pilih(){
	int c, d, swap;
	jumlahwaktunaik[0] = jumlahwaktu[0];
	jumlahwaktunaik[1] = jumlahwaktu[1];
	
	for (c = 0 ; c < 2; c++){
    	for (d = 0 ; d < 2 - c ; d++){
      		if (jumlahwaktunaik[d] > jumlahwaktunaik[d+1]){
        		swap = jumlahwaktunaik[d];
        		jumlahwaktunaik[d] = jumlahwaktunaik[d+1];
        		jumlahwaktunaik[d+1] = swap;
      		}
    	}
	}
	for (c = 0; c < 2; c++){
    	if (jumlahwaktu[c] == jumlahwaktunaik[0]){
        	break;
    	}
	}
	antrean = c;
  	return c;
}

void enq(struct antre *buat, struct antre *temp, int pilihan){
	
	if(temp == NULL){
		switch(pilihan){
		case 0:
			startSatu = buat;
			break;
		case 1:
			startDua = buat;
			break;
		}
	}else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		buat->next = NULL;
		temp->next = buat;		
	}	
}			

void simulasiWaktu(){
	if(startSatu != NULL){
		startSatu->waktu -= clock;
	}
	if(startDua != NULL){
		startDua->waktu -= clock;
	}
	checkwaktuStart();
}

void notif(char alias[], int jenis){
	int temp_waktu;
	printf("\nmobil %s berhasil ditambahkan, perkiraan lama waktu hingga selesai adalah",alias);
	switch(jenis){
		case 1:
			temp_waktu = waktucuci[0];break;
		case 2:
			temp_waktu = waktucuci[1];break;
		case 3:
			temp_waktu = waktucuci[2];break;	
		}
	switch(antrean){
		case 0:
			printf(" %d menit.\n",jumlahwaktu[0]+temp_waktu);break;
		case 1:
			printf(" %d menit.\n",jumlahwaktu[1]+temp_waktu);break;
		}
}

void checkwaktuStart(){
	if(startSatu != NULL){
		if(startSatu->waktu == 0 || startSatu->waktu < 0){
			dequeue(0);
		}
	}
	if(startDua != NULL){
		if(startDua->waktu == 0  || startDua->waktu < 0){
			dequeue(1);
		}
	}
}


void dequeue(int pilih){
	struct antre *temp;
	switch(pilih){
		case 0:
			temp = startSatu;
			startSatu = startSatu->next;
			free(temp);
			break;
		case 1:
			temp = startDua;
			startDua = startDua->next;
			free(temp);
			break;
	}
}

void keluarin(int flag, char alias[]){
	struct antre *temp1,*temp2; 
	temp1 = startSatu;
	temp2 = startDua;
	
	switch(flag){
		case 1:
			out(alias,temp1);
			break;
		case 2:
			out(alias,temp2);
			break;
		}
	continuesButton();	
}

int out(char alias[], struct antre* temp){
	struct antre *freed;
	if(strcmp(alias,temp->nopol) == 0){
		printf("\nmobil yang sedang dalam pencucian tidak bisa dikeluarkan, silahkan menunggu sebentar.\n");
	}else{
		while(strcmp(alias,temp->next->nopol)!=0){
			temp = temp->next;
		}
		freed = temp->next;
		temp->next = temp->next->next;
		free(freed);
	}
}

void tampilanAwal(){
	judul();
	petunjuk();
	continuesButton();
	system("cls");
}

void judul(){
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("**** CARWASH SIMULATION ****\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void petunjuk(){
	printf("\nPetunjuk Penggunaan Program : \n");
	printf("-> Akan ditampilkan selalu tabel yang berisi list mobil masing masing tempat cuci\n");
	printf("-> Untuk menambah mobil yang ingin dicuci pilih 1 pada menu\n");
	printf("-> Untuk mengeluarkan mobil dari antrian pilih 2 pada menu\n");
	printf("-> Untuk menjalankan simulasi selama 10 menit pilih 3 pada menu\n");
	printf("-> Untuk melihat petunjuk pilih 4 pada menu\n");
	printf("-> Untuk keluar dari program pilih 5 pada menu\n");
	}
	
int isEmpty(){
	int check;
	if(startSatu != NULL){
			check++;	
	}
	if(startDua != NULL){
			check++;
	}
	return check;
}
