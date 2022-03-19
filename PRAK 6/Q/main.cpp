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

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "QUEUE.h"
#include "boolean.h"


int main (){
	List L;
	address P;
	infotype X;
	bool check;
	int menu;
	int pmenu;
	CreateList(&L);	
	infotype anggota;
	ElmtListangka urutan_angka[2];

	urutan_angka[0].info_angka = "1";
	urutan_angka[1].info_angka = "2";
	
	printf("\t\t INI BAGIAN QUEUE\t\t\n\n");
	
	//Create List Bagian 0
	printf("Bagian %s : ",urutan_angka[0].info_angka);
	CreateList(&urutan_angka[0].angka);
	enqueue(&urutan_angka[0].angka,"1");
	enqueue(&urutan_angka[0].angka,"3");
	enqueue(&urutan_angka[0].angka,"5");
	enqueue(&urutan_angka[0].angka,"7");
	enqueue(&urutan_angka[0].angka,"9");
	PrintInfo(urutan_angka[0].angka);
	printf("\n");

	//Create List Bagian 1
	printf("Bagian %s : ",urutan_angka[1].info_angka);
	CreateList(&urutan_angka[1].angka);
	enqueue(&urutan_angka[1].angka,"2");
	enqueue(&urutan_angka[1].angka,"4");
	enqueue(&urutan_angka[1].angka,"6");
	enqueue(&urutan_angka[1].angka,"8");
	enqueue(&urutan_angka[1].angka,"10");
	PrintInfo(urutan_angka[1].angka);
	printf("\n");
		
	//Insert Last dikota 0
	printf("\nDilakukan enqueue '11' pada Bagian 1 : \n");	
	enqueue(&urutan_angka[0].angka, "11");
	printf("Bagian %s : ",urutan_angka[0].info_angka);
	PrintInfo(urutan_angka[0].angka);

	//Insert Last dikota 1
	printf("\nDilakukan enqueue '12' pada Bagian 2 : \n");	
	enqueue(&urutan_angka[1].angka, "12");
	printf("Bagian %s : ",urutan_angka[1].info_angka);
	PrintInfo(urutan_angka[1].angka);


	//Delete First dikota 0
	printf("\nDilakukan dequeue pada Bagian 1 : \n");	
	dequeue(&urutan_angka[0].angka, &anggota);
	printf("Bagian %s : ",urutan_angka[0].info_angka);
	PrintInfo(urutan_angka[0].angka);

	//Delete First dikota 1
	printf("\nDilakukan dequeue pada Bagian 2 : \n");	
	dequeue(&urutan_angka[1].angka, &anggota);
	printf("Bagian %s : ",urutan_angka[1].info_angka);
	PrintInfo(urutan_angka[1].angka);
	
	
	//Hasil Akhir
	printf("\n ===========HASIL AKHIR============== \n");	
	printf("Bagian %s : ",urutan_angka[0].info_angka);
	PrintInfo(urutan_angka[0].angka);

	printf("Bagian %s : ",urutan_angka[1].info_angka);
	PrintInfo(urutan_angka[1].angka);

	return 0;
}
