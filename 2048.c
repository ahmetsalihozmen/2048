#include <stdio.h>
#include <time.h>
#include <locale.h>
int main(int argc, char *argv[]) {
	int oyun[4][4],i,j,sonuc,k,puan,kontrol,a,b,oyun2[4][4],kont2,puan2,yildiz1,yildiz2,dizi[6],hpuan;	char yon;
	setlocale(LC_ALL, "Turkish");
	srand (time(NULL));
	hpuan=0;
	basla:
	//Burada oyuncu e tu�una basarsa oyunu highscore hari� ba�tan ba�lat�yor.
	system("cls");
	for(i=0;i<=3;i++){
		for(j=0;j<=3;j++){
			oyun[i][j]=0;
		}
	}
	for(i=0;i<=4;i++){
		dizi[i]=2;
	}
	dizi[5]=4;
	//Ger�ek oyunda arada bir 4 say�s� rastgele gelebiliyor bu y�zden be� tane 2 bir tane de 4 �n oldu�u diziden say�y� rastgele se�iyor.
	for(sonuc=0;sonuc<=1;sonuc++){
		i=rand()%4;
		j=rand()%4;
		oyun[i][j]=2;
	}
	for(i=0;i<=3;i++){
		for(j=0;j<=3;j++){
			oyun2[i][j]=oyun[i][j];
	}
	}
	puan=0;
	puan2=0;
	printf("2048 OYUNUNA HO�GELD�N�Z\nY�n tu�lar� ile oynan�r\nGeri almak i�in u tu�una bas�n�z\nBa�tan ba�lamak i�in e tu�una bas�n�z\n");
	printf("Highscore:%d\nPuan:%d\n",hpuan,puan);
	for(i=0;i<=3;i++){
		printf("-----------------------------\n|");
		for(j=0;j<=3;j++){
				if(oyun[i][j]!=0){
				printf(" %4d |",oyun[i][j]);					
				}
				else{
					printf("      |");
				}

		}
	printf("\n");
	}
	printf("-----------------------------\n");
	sonuc=0;
	kontrol=1;
	while(sonuc==0){
	//Sonuc d�ng�m�z� d�nd�ren de�i�ken
		do{
			yon = getch();
		}
		while(yon!=80 && yon!=75 && yon!=77 && yon!=72 && yon!='u' && yon!='e');
		if(yon=='e'){
			goto basla;
		}
		if(yon=='u'){
			puan=puan2;
			if(kont2==0){//Daha �nce de�i�iklk yap�ld� m� diye kontrol ediliyor
			system("cls");
			printf("Highscore:%d\nPuan:%d\n",hpuan,puan2);
			for(i=0;i<=3;i++){
				printf("-----------------------------\n|");
				for(j=0;j<=3;j++){//�nceki matrisi yazd�r�yor
					if(oyun2[i][j]!=0){
					printf(" %4d |",oyun2[i][j]);					
					}
					else{
					printf("      |");
					}
			}
	printf("\n");
	}
	printf("-----------------------------\n");	
			for(i=0;i<=3;i++){//Yedek matrisi ana matrise at�yor.
				for(j=0;j<=3;j++){
					oyun[i][j]=oyun2[i][j];
				}
			}
			}
		}	
		else{		
		puan2=puan;
		for(k=0;k<=2;k++){
			//Burada a ile b yi de�i�tirmemim sebebi ad�m say�s�na g�re 1 say� daha az kontrol ediyor bu da bize h�z kazand�r�yor.
			if(k==1){
				a=1;
				b=2;
			}
			else{
				if(k==2){
					a=0;
					b=3;
				}
				else{
				a=2;
				b=1;
				for(i=0;i<=3;i++){
					for(j=0;j<=3;j++){
						oyun2[i][j]=oyun[i][j];
				//Burada ilk ad�mda yedek matrisi kaydediyor.
				}
			}
		}
			}
			if(yon==80){//A�A�I Hareketi burada yap�l�yor.
			for(j=0;j<=3;j++){
				for(i=0;i<=a;i++){
						if(oyun[i][j]==oyun[i+1][j]){
							oyun[i+1][j]=oyun[i+1][j]*-2;// Burada o say�n�n daha �nce topland���n� i�aretlemek i�in -2 ile �arp�l�yor.
							oyun[i][j]=0;
							puan=-oyun[i+1][j]+puan;
							if(oyun[i+1][j]==2048){//2048 e�itse oyunu bitirmesi i�in ��k�yor.
								sonuc=1;
							}	
						}
						if(oyun[i+1][j]==0 && oyun[i][j]!=0){// E�er yan yana 2 s�f�r varsa yer de�i�tirmiyor.
							oyun[i+1][j]=oyun[i][j];
							oyun[i][j]=0;
						}
					}
				}
			}
		if(yon==75){//SOL Hareketi burada yap�l�yor
			for(i=0;i<=3;i++){
				for(j=3;j>=b;j--){
						if(oyun[i][j]==oyun[i][j-1]){
							oyun[i][j-1]=oyun[i][j-1]*-2;
							oyun[i][j]=0;
							puan=-oyun[i][j-1]+puan;
							if(oyun[i][j-1]==2048){
								sonuc=1;
							}
					 }
						if(oyun[i][j-1]==0 && oyun[i][j]!=0){
							oyun[i][j-1]=oyun[i][j];
							oyun[i][j]=0;					
						}
				}
			}
		}
		if(yon==77){//SA� Hareketi burada yap�l�yor
			for(i=0;i<=3;i++){
				for(j=0;j<=a;j++){
					if(oyun[i][j]==oyun[i][j+1]){
						oyun[i][j+1]=oyun[i][j+1]*-2;
						oyun[i][j]=0;
						puan=-oyun[i][j+1]+puan;
						if(oyun[i][j+1]==2048){
							sonuc=1;
						}
					}
				 if(oyun[i][j+1]==0 && oyun[i][j]!=0){
						oyun[i][j+1]=oyun[i][j];
						oyun[i][j]=0;					
					}
				}
			}
		}
		if(yon==72){//YUKARI Hareketi burada yap�l�yor.
			for(j=0;j<=3;j++){
				for(i=3;i>=b;i--){
					if(oyun[i][j]==oyun[i-1][j]){
						oyun[i-1][j]=oyun[i-1][j]*-2;
						oyun[i][j]=0;
						puan=-oyun[i-1][j]+puan;
						if(oyun[i-1][j]==2048){
							sonuc=1;
						}
					}
					if(oyun[i-1][j]==0 && oyun[i][j]!=0){
						oyun[i-1][j]=oyun[i][j];
						oyun[i][j]=0;
					}
				}
			}
		}
		}
		for(i=0;i<=3;i++){
			for(j=0;j<=3;j++){
				if(oyun[i][j]==0){
					kontrol=kontrol+1;
				}
				if(oyun[i][j]<0){
					oyun[i][j]=oyun[i][j]*-1;
				//Burada -2 ile �arp�lan say�lar pozitif olarak ��kart�l�yor.
				}
			}
		}
		if(kontrol>0){//Rastgele say�lar atan�yor s�f�r m� diye kontrol ediliyor.
		do {i=rand()%4;
			j=rand()%4;
			k=rand()%6;
		}
		while(oyun[i][j]!=0);
		oyun[i][j]=dizi[k];
		yildiz1=i;
		yildiz2=j;
		if(puan>hpuan){//�uanki puan highscore dan y�ksek mi diye kontrol ediliyor. 
			hpuan=puan;
		}
		system("cls");
		printf("Highscore:%d\nPuan:%d\n",hpuan,puan);
		for(i=0;i<=3;i++){
			printf("-----------------------------\n|");
			for(j=0;j<=3;j++){
				if(i==yildiz1 && j==yildiz2){
					printf(" %4d*|",oyun[i][j]);
				}
				else{
					if(oyun[i][j]!=0){
					printf(" %4d |",oyun[i][j]);					
					}
					else{
						printf("      |");
					}
				}	
			}
			printf("\n");
		}
		printf("-----------------------------");
		printf("\n");
		kontrol=0;
		}
		else{sonuc=2;
		}
		kont2=0;
 }
}
if(sonuc==1){
	printf("TEBR�KLER KAZANDINIZ!!!!\nYeniden ba�lamak i�in E tu�una bas�n�z.",hpuan);
	do {yon = getch();
	}
	while(yon!='e');
}
else{
	printf("Kaybettiniz.\nYeniden ba�lamak i�in E tu�una bas�n�z.",hpuan);
	do {yon = getch();
	}
	while(yon!='e');
}
goto basla;
//Burada ba�a geri d�n�yor.
getch();
return 0;
}
