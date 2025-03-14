#include <stdio.h>
#include <stdlib.h>

#define MayinSayisi 8
#define TabloBoyutu 10

void AltTablo();
void Tablo();
void TabloPrint();
void MayinYerlestir();
void AltTabloPrint();
int Oyun(int satir, int sutun);
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
while(durum == 1)
{
TabloPrint();
printf("\nSatir ve sutun sayisini giriniz: ");
scanf("%d %d",&satir, &sutun);
Oyun(satir, sutun);
printf("%d",durum);
}
}
void TabloOlustur()
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
void AltTablo()
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
void TabloPrint()
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
void AltTabloPrint()
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
void MayinYerlestir()
{
    srand(time(NULL));
    int satir, sutun;
    for(int i=1; i <= MayinSayisi; i++)
    {
        satir = 1 + rand()%TabloBoyutu;
        sutun = 1 + rand()%TabloBoyutu;
        if(alttablo[satir][sutun] == -1)
        {
            i--;
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
    if(alttablo[satir][sutun] == -1)
    {
        printf("\nOyunu kaybetdiniz..\n");
        AltTabloPrint();
    }
    else if(alttablo[satir][sutun] > 0 && cTablo[satir][sutun] == '#')
    {
        cTablo[satir][sutun] = '0' + alttablo[satir][sutun];
    }
    else if(alttablo[satir][sutun] == 0 && cTablo[satir][sutun] == '#')
    {
         durum1(satir,sutun);
    }
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
