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



#include "carwash.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>



void enqueue(char alias[], int jenis)
{
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
			printf("\n Antrian dibelakang : %s ",temp1->nopol,temp1->waktu);
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
			printf("\n Antrian dibelakang : %s ",temp2->nopol);
			temp2 = temp2->next;
		}		
	}
}

void menu(int *pm)
{
	printf("\n\n MENU :\n");
	printf(" 1. Ambil Tiket untuk mencuci\n");
	printf(" 2. Tidak Jadi Mencuci\n");
	printf(" 3. Melakukan Simulasi untuk %d menit \n",clock);
	printf(" 4. Petunjuk\n");
	printf(" 5. Tutup Carwash");
	
	do
	{
		printf(" Pilihan : "); scanf("%d",pm);
		if(*pm < 1 || *pm >5)
		{
			printf(" Hanya dapat memilih diantara 1-5 \n Pilih Kembali :");
		}
	}while (*pm < 1 || *pm > 5);
	
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
		case 5: // ganti jadi dell all
			pil = isEmpty();
			if(pil != 0){
				printf("masih ada mobil yang sedang dicuci. tidak bisa keluar dari program.\n");
				continuesButton();
				*exit = 0;
				break;	
			}
			*exit = 1;
			system("cls");
			printf("THANK YOU!!!\n\n");	
			break;
	}
}


void tampilanAwal()
{
	petunjuk();
	continuesButton();
	system("cls");
}

void continuesButton(){
	printf("\nTekan apapun untuk melanjutkan!");
	getch();
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

void simulasiWaktu(){
	if(startSatu != NULL){
		startSatu->waktu -= clock;
	}
	if(startDua != NULL){
		startDua->waktu -= clock;
	}
	checkwaktuStart();
}


int pilih(){
	int c, d, swap;
	jumlahwaktunaik[0] = jumlahwaktu[0];
	jumlahwaktunaik[1] = jumlahwaktu[1];
	jumlahwaktunaik[2] = jumlahwaktu[2];
	jumlahwaktunaik[3] = jumlahwaktu[3];
	jumlahwaktunaik[4] = jumlahwaktu[4];
	
	for (c = 0 ; c < 4; c++){
    	for (d = 0 ; d < 4 - c ; d++){
      		if (jumlahwaktunaik[d] > jumlahwaktunaik[d+1]){
        		swap = jumlahwaktunaik[d];
        		jumlahwaktunaik[d] = jumlahwaktunaik[d+1];
        		jumlahwaktunaik[d+1] = swap;
      		}
    	}
	}
	for (c = 0; c < 5; c++){
    	if (jumlahwaktu[c] == jumlahwaktunaik[0]){
        	break;
    	}
	}
	antrean = c;
  	return c;
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
		case 2:
			printf(" %d menit.\n",jumlahwaktu[2]+temp_waktu);break;
		case 3:
			printf(" %d menit.\n",jumlahwaktu[3]+temp_waktu);break;
		case 4:
			printf(" %d menit.\n",jumlahwaktu[4]+temp_waktu);break;
		}
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
	printf("\nNo.\t| jenis\t\t\t\t| Lama Pengerjaan\t| \n");
	printf("1.\t| KELAS 'A'\t\t\t| %d menit\t\t| \n",waktucucitmpl[0]);
	printf("2.\t| KELAS 'B'\t\t\t| %d menit\t\t| \n",waktucucitmpl[1]);
	printf("3.\t| KELAS 'C'\t\t\t| %d menit\t\t| \n",waktucucitmpl[2]);
	printf("4. Tidak Jadi\n");
	do{
		printf("Pilihan : ");scanf("%d",&ch);
		if(ch<1 || ch>4){
			printf("pilihan diantara 1 - 4, silahkan isi lagi.\n");
		}
	}while(ch<1 || ch>4);
	return ch;
}


void checkwaktuStart(){
	if(startSatu != NULL){
		if(startSatu->waktu == 0){
			dequeue(0);
		}
	}
	if(startDua != NULL){
		if(startDua->waktu == 0){
			dequeue(1);
		}
	}
}


void keluarin(int flag, char alias[]){
	struct antre *temp1,*temp2,*temp3,*temp4,*temp5; 
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



void petunjuk(){
	printf("\n\tPetunjuk Penggunaan Program : \n");
	printf("-> Untuk menambah mobil yang ingin dicuci pilih 1 pada menu\n");
	printf("-> Untuk mengeluarkan mobil dari antrian bila tidak jadi mencuci pilih 2 pada menu\n");
	printf("-> Untuk menjalankan simulasi selama 10 menit pilih 3 pada menu\n");
	printf("-> Untuk melihat petunjuk pilih 4 pada menu\n");
	printf("-> Untuk keluar dari program pilih 5 pada menu\n");
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

