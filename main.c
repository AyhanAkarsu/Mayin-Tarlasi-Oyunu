#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MayinSayisi 8
#define TabloBoyutu 10

void TabloOlustur(void);
void AltTablo(void);
void TabloPrint(void);
void MayinYerlestir(void);
void AltTabloPrint(void);
int Oyun(int satir, int sutun);
void durum1(int satir, int sutun);
int durum = 1;

char cTablo[TabloBoyutu][TabloBoyutu];
int alttablo[TabloBoyutu][TabloBoyutu];

int main()
{
    int satir, sutun;
    TabloOlustur();
    AltTablo();
    MayinYerlestir();
    printf("********Mayin Tarlasi Oyunu***********\n");
    while (durum == 1)
    {
        TabloPrint();
        printf("\nSatir ve sutun sayisini giriniz (1-8): ");
        if (scanf("%d %d", &satir, &sutun) != 2)
        {
            printf("Gecersiz giris. Oyun sonlandirildi.\n");
            break;
        }
        Oyun(satir, sutun);
    }
    return 0;
}
void TabloOlustur(void)
{
    for(int i=1; i < TabloBoyutu-1; i++)
    {
        for(int j=1; j < TabloBoyutu-1; j++)
        {
            cTablo[i][j] = '#';
        }
    }
    for(int i=0; i < TabloBoyutu; i++)
    {
        cTablo[0][i] = '*';
        cTablo[i][0] = '*';
        cTablo[TabloBoyutu-1][i] = '*';
        cTablo[i][TabloBoyutu-1] = '*';
    }
}
void AltTablo(void)
{
       for(int i=1; i < TabloBoyutu-1; i++)
        {
        for(int j=1; j < TabloBoyutu-1; j++)
        {
            alttablo[i][j] = 0;
        }
    }
    for(int i=0; i < TabloBoyutu; i++)
    {
        alttablo[0][i] = 1;
        alttablo[i][0] = 1;
        alttablo[TabloBoyutu-1][i] = 1;
        alttablo[i][TabloBoyutu-1] = 1;
    }
}
void TabloPrint(void)
{
    printf("  ");
    for(int i=1; i < TabloBoyutu-1; i++)
    {
        printf("%3d",i);
    }
     printf("\n--------------------------------");
    printf("\n");
    for(int i=1; i < TabloBoyutu-1; i++)
    {
        printf("%d|",i);
        for(int j=1; j < TabloBoyutu-1; j++)
        {
            printf("%3c",cTablo[i][j]);
        }
        printf("  |%d\n",i);
    }
    printf("--------------------------------\n");
      printf("  ");
     for(int i=1; i < TabloBoyutu-1; i++)
    {
        printf("%3d",i);
    }
}
void AltTabloPrint(void)
{
        printf("  ");
    for(int i=1; i < TabloBoyutu-1; i++)
    {
        printf("%3d",i);
    }
     printf("\n--------------------------------");
    printf("\n");
    for(int i=1; i < TabloBoyutu-1; i++)
    {
        printf("%d|",i);
        for(int j=1; j < TabloBoyutu-1; j++)
        {
            printf("%3d",alttablo[i][j]);
        }
        printf("  |%d\n",i);
    }
    printf("--------------------------------\n");
      printf("  ");
     for(int i=1; i < TabloBoyutu-1; i++)
    {
        printf("%3d",i);
    }
}
void MayinYerlestir(void)
{
    srand(time(NULL));
    int satir, sutun;
    for(int i=1; i <= MayinSayisi; i++)
    {
        satir = 1 + rand() % (TabloBoyutu - 2);
        sutun = 1 + rand() % (TabloBoyutu - 2);
        if(alttablo[satir][sutun] == -1)
        {
            i--;
            continue;
        }
        alttablo[satir][sutun] = -1;
        for(int k=-1; k <= 1; k++)
        {
            for(int j=-1; j <= 1; j++)
            {
                if(alttablo[satir][sutun] == -1)
                {
                    if(alttablo[satir+k][sutun+j] != -1)
                    {
                        alttablo[satir+k][sutun+j] ++;
                    }
                }
            }
        }
    }
}
int Oyun(int satir, int sutun)
{
    if (satir < 1 || satir >= TabloBoyutu - 1 ||
        sutun < 1 || sutun >= TabloBoyutu - 1)
    {
        printf("Gecersiz koordinat. 1 ile 8 arasinda deger girin.\n");
        return 0;
    }

    if(alttablo[satir][sutun] == -1)
    {
        printf("\nOyunu kaybettiniz.\n");
        AltTabloPrint();
        durum = 0;
    }
    else if(alttablo[satir][sutun] > 0 && cTablo[satir][sutun] == '#')
    {
        cTablo[satir][sutun] = '0' + alttablo[satir][sutun];
    }
    else if(alttablo[satir][sutun] == 0 && cTablo[satir][sutun] == '#')
    {
         durum1(satir,sutun);
    return 0;
}
void durum1(int satir, int sutun)
{
    cTablo[satir][sutun] = '0';
        for(int i=-1; i <= 1; i++)
        {
      for(int j=-1; j <= 1; j++)
      {
           if(alttablo[satir+i][sutun+j] > 0)
          {
              cTablo[satir+i][sutun+j] = '0' + alttablo[satir+i][sutun+j];
          }
      }
  }
}
