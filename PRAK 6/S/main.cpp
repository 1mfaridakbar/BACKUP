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
#include "STACK.h"
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
	
	printf("\t\t INI BAGIAN STACK\t\t\n\n");
	
	//Create List Bagian 0
	printf("Bagian %s : ",urutan_angka[0].info_angka);
	CreateList(&urutan_angka[0].angka);
	push(&urutan_angka[0].angka,"1");
	push(&urutan_angka[0].angka,"3");
	push(&urutan_angka[0].angka,"5");
	push(&urutan_angka[0].angka,"7");
	push(&urutan_angka[0].angka,"9");
	PrintInfo(urutan_angka[0].angka);
	printf("\n");

	//Create List Bagian 1
	printf("Bagian %s : ",urutan_angka[1].info_angka);
	CreateList(&urutan_angka[1].angka);
	push(&urutan_angka[1].angka,"2");
	push(&urutan_angka[1].angka,"4");
	push(&urutan_angka[1].angka,"6");
	push(&urutan_angka[1].angka,"8");
	push(&urutan_angka[1].angka,"10");
	PrintInfo(urutan_angka[1].angka);
	printf("\n");
		
	//Insert Last dikota 0
	printf("\nDilakukan push '11' pada Bagian 1 : \n");	
	push(&urutan_angka[0].angka, "11");
	printf("Bagian %s : ",urutan_angka[0].info_angka);
	PrintInfo(urutan_angka[0].angka);

	//Insert Last dikota 1
	printf("\nDilakukan push '12' pada Bagian 2 : \n");	
	push(&urutan_angka[1].angka, "12");
	printf("Bagian %s : ",urutan_angka[1].info_angka);
	PrintInfo(urutan_angka[1].angka);


	//Delete Last dikota 0
	printf("\nDilakukan pop pada Bagian 1 : \n");	
	pop(&urutan_angka[0].angka, &anggota);
	printf("Bagian %s : ",urutan_angka[0].info_angka);
	PrintInfo(urutan_angka[0].angka);

	//Delete Last dikota 1
	printf("\nDilakukan pop pada Bagian 2 : \n");	
	pop(&urutan_angka[1].angka, &anggota);
	printf("Bagian %s : ",urutan_angka[1].info_angka);
	PrintInfo(urutan_angka[1].angka);
	
	printf("\nDilakukan top pada Bagian 1 Ditimpa dengan '13' : \n");	
	pop(&urutan_angka[0].angka, &anggota);
	printf("Bagian %s : ",urutan_angka[0].info_angka);
	push(&urutan_angka[0].angka, "13");
	printf("Bagian %s : ",urutan_angka[0].info_angka);
	PrintInfo(urutan_angka[0].angka);
	
	printf("\nDilakukan top pada Bagian 1 Ditimpa dengan '14' : \n");	
	pop(&urutan_angka[1].angka, &anggota);
	printf("Bagian %s : ",urutan_angka[1].info_angka);
	push(&urutan_angka[1].angka, "14");
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
