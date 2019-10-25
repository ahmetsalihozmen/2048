#include <stdio.h>
#include <time.h>
#include <locale.h>
int main(int argc, char *argv[]) {
	int oyun[4][4],i,j,sonuc,k,puan,kontrol,a,b,oyun2[4][4],kont2,puan2,yildiz1,yildiz2,dizi[6],hpuan;	char yon;
	setlocale(LC_ALL, "Turkish");
	srand (time(NULL));
	hpuan=0;
	basla:
	//Burada oyuncu e tuþuna basarsa oyunu highscore hariç baþtan baþlatýyor.
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
	//Gerçek oyunda arada bir 4 sayýsý rastgele gelebiliyor bu yüzden beþ tane 2 bir tane de 4 ün olduðu diziden sayýyý rastgele seçiyor.
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
	printf("2048 OYUNUNA HOÞGELDÝNÝZ\nYön tuþlarý ile oynanýr\nGeri almak için u tuþuna basýnýz\nBaþtan baþlamak için e tuþuna basýnýz\n");
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
	//Sonuc döngümüzü döndüren deðiþken
		do{
			yon = getch();
		}
		while(yon!=80 && yon!=75 && yon!=77 && yon!=72 && yon!='u' && yon!='e');
		if(yon=='e'){
			goto basla;
		}
		if(yon=='u'){
			puan=puan2;
			if(kont2==0){//Daha önce deðiþiklk yapýldý mý diye kontrol ediliyor
			system("cls");
			printf("Highscore:%d\nPuan:%d\n",hpuan,puan2);
			for(i=0;i<=3;i++){
				printf("-----------------------------\n|");
				for(j=0;j<=3;j++){//Önceki matrisi yazdýrýyor
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
			for(i=0;i<=3;i++){//Yedek matrisi ana matrise atýyor.
				for(j=0;j<=3;j++){
					oyun[i][j]=oyun2[i][j];
				}
			}
			}
		}	
		else{		
		puan2=puan;
		for(k=0;k<=2;k++){
			//Burada a ile b yi deðiþtirmemim sebebi adým sayýsýna göre 1 sayý daha az kontrol ediyor bu da bize hýz kazandýrýyor.
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
				//Burada ilk adýmda yedek matrisi kaydediyor.
				}
			}
		}
			}
			if(yon==80){//AÞAÐI Hareketi burada yapýlýyor.
			for(j=0;j<=3;j++){
				for(i=0;i<=a;i++){
						if(oyun[i][j]==oyun[i+1][j]){
							oyun[i+1][j]=oyun[i+1][j]*-2;// Burada o sayýnýn daha önce toplandýðýný iþaretlemek için -2 ile çarpýlýyor.
							oyun[i][j]=0;
							puan=-oyun[i+1][j]+puan;
							if(oyun[i+1][j]==2048){//2048 eþitse oyunu bitirmesi için çýkýyor.
								sonuc=1;
							}	
						}
						if(oyun[i+1][j]==0 && oyun[i][j]!=0){// Eðer yan yana 2 sýfýr varsa yer deðiþtirmiyor.
							oyun[i+1][j]=oyun[i][j];
							oyun[i][j]=0;
						}
					}
				}
			}
		if(yon==75){//SOL Hareketi burada yapýlýyor
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
		if(yon==77){//SAÐ Hareketi burada yapýlýyor
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
		if(yon==72){//YUKARI Hareketi burada yapýlýyor.
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
				//Burada -2 ile çarpýlan sayýlar pozitif olarak çýkartýlýyor.
				}
			}
		}
		if(kontrol>0){//Rastgele sayýlar atanýyor sýfýr mý diye kontrol ediliyor.
		do {i=rand()%4;
			j=rand()%4;
			k=rand()%6;
		}
		while(oyun[i][j]!=0);
		oyun[i][j]=dizi[k];
		yildiz1=i;
		yildiz2=j;
		if(puan>hpuan){//Þuanki puan highscore dan yüksek mi diye kontrol ediliyor. 
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
	printf("TEBRÝKLER KAZANDINIZ!!!!\nYeniden baþlamak için E tuþuna basýnýz.",hpuan);
	do {yon = getch();
	}
	while(yon!='e');
}
else{
	printf("Kaybettiniz.\nYeniden baþlamak için E tuþuna basýnýz.",hpuan);
	do {yon = getch();
	}
	while(yon!='e');
}
goto basla;
//Burada baþa geri dönüyor.
getch();
return 0;
}
