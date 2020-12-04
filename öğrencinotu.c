#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Ogrenci
{
    double vizeNotu;
    double finalNotu;
    int id;
    struct Ogrenci *sonraki;
} ogrenci;

ogrenci *ilk=NULL,*son=NULL,*gecici,*onceki;
int ekle()
{
    while(1)
    {
        gecici=(ogrenci*)malloc(sizeof(ogrenci));
        printf("id: ");
        scanf("%d",&gecici->id);
        if(gecici->id==-1)
        {
            return 0;
        }
        printf("Vize notu: ");
        scanf("%lf",&gecici->vizeNotu);
        printf("Final notu: ");
        scanf("%lf",&gecici->finalNotu);
        if(ilk==NULL)
        {
            ilk=gecici;
            son=gecici;
            son->sonraki=NULL;
        }
        else
        {
            son->sonraki=gecici;
            son=gecici;
            son->sonraki=NULL;
        }
    }
    return 0;

}

void sil()
{
    int toplamNot;
    for(gecici=ilk; gecici!=NULL; gecici=gecici->sonraki)
    {
        toplamNot=(gecici->finalNotu*0.6)+(gecici->vizeNotu*0.4);
        if(toplamNot<60)
        {
            if(gecici==ilk)
            {
                ilk=gecici->sonraki;
            }
            else if(gecici->sonraki==NULL)
            {
                son=onceki;
                son->sonraki=NULL;
            }
            else
            {
                onceki->sonraki=gecici->sonraki;
            }
        }
        onceki=gecici;
    }
}

void listele()
{
    int a;
    if(ilk!=NULL)
    {
        for(gecici=ilk; gecici!=NULL; gecici=gecici->sonraki)
        {
            if(gecici==ilk)
                printf("id               | V i z e|   Final\n");
            printf("%-20d%-11.2lf%.2lf\n",gecici->id,gecici->vizeNotu,gecici->finalNotu);
        }
        a=getch();
    }

}

int main()
{
    int secenek;
    ekle();
    sil();
    listele();
}
