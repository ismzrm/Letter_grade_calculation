#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
0-39:FF 40 - 49 :FD 50 - 59 :DC 60 - 69 :CC
70 - 79 :BC 80 - 89 :BB 90 - 100 :AA
*/
int main(int argc, char *argv[]) {
	char isim[20]; char soyisim[20];
	char ders[20]; float vize;
	float final;  float ortalama;
	char *durum; char *harf;
	FILE *dosya;
	dosya=fopen("bilgiler.txt","a");
	setlocale(LC_ALL,"turkish");
	printf("��rencinin ad�n� yaz�n�z  :"); gets(isim);
	printf("��rencinin soyad�n� yaz�n�z  :"); gets(soyisim);
	printf("��rencinin dersini yaz�n�z  :"); gets(ders);
	printf("��rencinin vize notu nedir  :"); scanf("%f",&vize);
	printf("��rencinin final notu nedir  :"); scanf("%f",&final);
	ortalama=vize*0.40+final*0.60;
	if (ortalama<60) {durum="KALDI";}
	else {durum="GE�T�";}
	if (ortalama<=39) {harf="FF";}
	if (ortalama>=40 && ortalama<=49) {harf="FD";}
	if (ortalama>=50 && ortalama<=59) {harf="DC";}
    if (ortalama>=60 && ortalama<=69) {harf="CC";}
    if (ortalama>=70 && ortalama<=79) {harf="BC";}
    if (ortalama>=80 && ortalama<=89) {harf="BB";}
    if (ortalama>=90 && ortalama<=100) {harf="AA";}
	fprintf(dosya,"%s %s %s %.2f %.2f %.2f %s %s\n",isim,soyisim,ders,vize,final,ortalama,durum,harf);
	fclose(dosya);
	printf("T�M B�LG�LER KAYDED�LD�.\n");
	printf("%.1f %s %s",ortalama,durum,harf);
	getch();
}
