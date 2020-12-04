#include <stdio.h>
#include <stdlib.h>

#include <conio.h>
#include <time.h>

int sayilar[50];

void sayi_sirala();
bool sayi_uret();
void sayi_yazdir(int duzen);
int toplam_bul();
float ortalama_bul(int toplam, int i);

int main(void)
{
   int i = 50;
   time_t t;
   srand((unsigned) time(&t));

   if (sayi_uret())
   {
    printf("Sayilar Rastgele Uretildi. Yazdiriliyor...\n\n");
   }
   else
   {
    printf("Sayi uretmede hata... Program sonlandirildi.");
   }

   sayi_yazdir(0);
   sayi_sirala();
   sayi_yazdir(1);

   printf("\n SAYILARIN : \n");
   printf("\n =========== \n");
   printf("\n Toplami    = \t"); printf("%10.d",toplam_bul());
   printf("\n Adedi     = \t"); printf("%10.d",i);
   printf("\n Ortalamasi = \t"); printf("%10.2f",ortalama_bul(toplam_bul(), i));
}


bool sayi_uret()
{
   int i;


   for ( i = 0; i <=49; i++ )
   {
    sayilar[i] = rand();
   }
   return true;
}

void sayi_sirala()
{
   int buyuk = 0;
   int kucuk = 0;
   int gecici = 0;

   for( buyuk=0; buyuk<49; buyuk++ )
   {
    for( kucuk = buyuk+1; kucuk<=49; kucuk++)
    {
         if( sayilar[buyuk] > sayilar[kucuk] )
         {
        gecici = sayilar[buyuk];
        sayilar[buyuk] = sayilar[kucuk];
            sayilar[kucuk] = gecici;
         }
    }
   }
}

void sayi_yazdir(int duzen)
{
   int i;
   if (duzen == 0)
   {
      printf("\n RASTGELE URETILEN SAYILAR (KARISIK) \n");
      printf("\n =================================== \n");
   }
   else
   {
      printf("\n SIRALAMA SONRASI SAYILAR \n");
      printf("\n ======================== \n");
   }

   for (i = 0; i <=49; i++)
   {
       printf("%d\t",sayilar[i]);
   }
}

int toplam_bul()
{
   int i = 0, toplam = 0, sonuc = 0;
   for (i = 0; i <=49; i++)
   {
    toplam += sayilar[i];
   }
   return toplam;
}

float ortalama_bul(int toplam, int i)
{
   float ortalama = 0;
   ortalama = toplam / i;
   return ortalama;
