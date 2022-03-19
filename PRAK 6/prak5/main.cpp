/* File        : SpNRSLL.h */
/* Deskripsi   : ADT list berkait dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Diedit oleh : Muhamad Farid Akbar (211511045) */
/* Tanggal     : 10-3-2022 */
/* Tanggal Rev 1    : 12-3-2022 */
/* Tanggal Rev 2    : 15-3-2022 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "SpNRSLL.h"
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
	ElmtListkota nama_kota[2];

	nama_kota[0].info_kota = "Jakarta";
	nama_kota[1].info_kota = "Bandung";
	
	//Create List kota 0
	printf("Kota %s : ",nama_kota[0].info_kota);
	CreateList(&nama_kota[0].orang);
	InsVLast(&nama_kota[0].orang,"Bagas");
	InsVLast(&nama_kota[0].orang,"Bagus");
	InsVLast(&nama_kota[0].orang,"zuxxy");
	InsVLast(&nama_kota[0].orang,"Luxxy");
	InsVLast(&nama_kota[0].orang,"kris");
	PrintInfo(nama_kota[0].orang);
	printf("\n");

	//Create List kota 1
	printf("Kota %s : ",nama_kota[1].info_kota);
	CreateList(&nama_kota[1].orang);
	InsVLast(&nama_kota[1].orang,"jajang");
	InsVLast(&nama_kota[1].orang,"jaka");
	InsVLast(&nama_kota[1].orang,"juki");
	InsVLast(&nama_kota[1].orang,"jojon");
	InsVLast(&nama_kota[1].orang,"joni");
	PrintInfo(nama_kota[1].orang);
	printf("\n");
	
	//Insert First dikota 0
	printf("\nDilakukan Insert First 'Abi' pada kota Jakarta : \n");	
	InsVFirst(&nama_kota[0].orang, "Abi");
	printf("Kota %s : ",nama_kota[0].info_kota);
	PrintInfo(nama_kota[0].orang);

	//Insert First dikota 1
	printf("\nDilakukan Insert First 'Jaki' pada kota Bandung : \n");	
	InsVFirst(&nama_kota[1].orang, "Jaki");
	printf("Kota %s : ",nama_kota[1].info_kota);
	PrintInfo(nama_kota[1].orang);
	
	//Insert Last dikota 0
	printf("\nDilakukan Insert Last 'Ikbal' pada kota Jakarta : \n");	
	InsVLast(&nama_kota[0].orang, "Ikbal");
	printf("Kota %s : ",nama_kota[0].info_kota);
	PrintInfo(nama_kota[0].orang);

	//Insert Last dikota 1
	printf("\nDilakukan Insert Last 'Rizky' pada kota Bandung : \n");	
	InsVLast(&nama_kota[1].orang, "Rizky");
	printf("Kota %s : ",nama_kota[1].info_kota);
	PrintInfo(nama_kota[1].orang);
	
	//Insert After dikota 0
	printf("\nDilakukan Insert After di posisi 3 'Salsa' pada kota Jakarta : \n");	
	// InsVLast(&nama_kota[0].orang, "Sanur");
	InsertAfter(&nama_kota[0].orang,Alokasi("Salsa"),Next(First(nama_kota[0].orang)));
	printf("Kota %s : ",nama_kota[0].info_kota);
	PrintInfo(nama_kota[0].orang);

	//Insert After dikota 1
	printf("\nDilakukan Insert After di posisi 3 'Nurul' pada kota Bandung : \n");	
	// InsVLast(&nama_kota[1].orang, "Nurdin");
	InsertAfter(&nama_kota[1].orang,Alokasi("Nurul"),Next(First(nama_kota[1].orang)));
	printf("Kota %s : ",nama_kota[1].info_kota);
	PrintInfo(nama_kota[1].orang);

	//Delete First dikota 0
	printf("\nDilakukan Delete First pada kota Jakarta : \n");	
	DelVFirst(&nama_kota[0].orang, &anggota);
	printf("Kota %s : ",nama_kota[0].info_kota);
	PrintInfo(nama_kota[0].orang);

	//Delete First dikota 1
	printf("\nDilakukan Delete First pada kota Bandung : \n");	
	DelVFirst(&nama_kota[1].orang, &anggota);
	printf("Kota %s : ",nama_kota[1].info_kota);
	PrintInfo(nama_kota[1].orang);

	//Delete Last dikota 0
	printf("\nDilakukan Delete Last pada kota Jakarta : \n");	
	DelVLast(&nama_kota[0].orang, &anggota);
	printf("Kota %s : ",nama_kota[0].info_kota);
	PrintInfo(nama_kota[0].orang);

	//Delete Last dikota 1
	printf("\nDilakukan Delete Last pada kota Bandung : \n");	
	DelVLast(&nama_kota[1].orang, &anggota);
	printf("Kota %s : ",nama_kota[1].info_kota);
	PrintInfo(nama_kota[1].orang);
	
	//Delete kriteria dikota 0
	printf("\nDilakukan Delete kriteria 'Salsa' pada kota Jakarta : \n");	
	DelP(&nama_kota[0].orang,"Salsa");
	printf("Kota %s : ",nama_kota[0].info_kota);
	PrintInfo(nama_kota[0].orang);

	//Delete kriteria dikota 1
	printf("\nDilakukan Delete kriteria 'joni' pada kota Bandung : \n");	
	DelP(&nama_kota[1].orang,"joni");
	printf("Kota %s : ",nama_kota[1].info_kota);
	PrintInfo(nama_kota[1].orang);
	
	//Hasil Akhir
	printf("\n ===========HASIL AKHIR============== \n");	
	printf("Kota %s : ",nama_kota[0].info_kota);
	PrintInfo(nama_kota[0].orang);

	printf("Kota %s : ",nama_kota[1].info_kota);
	PrintInfo(nama_kota[1].orang);

	return 0;
}
