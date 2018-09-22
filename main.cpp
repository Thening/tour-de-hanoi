#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#define nbrdisk 5

SDL_Surface *ecran,*rectangle1,*rectangle2,*rectangle3,*hori,*disk[nbrdisk];
SDL_Rect position2,position1,position3,position,courant,courant1,courant2,courant3;
typedef struct pile {
     SDL_Rect position[nbrdisk];
    }PILE;
PILE P1,P2,P3;
typedef int Tableau[nbrdisk];
Tableau barr1,barr2,barr3;


 void Reconstruire(){

     int n=nbrdisk,i=0,d=0;
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0,0,255));
    /*creation des barres*/
    courant1.y=position.y-0.5*hori->h;
    courant2.y=position.y-0.5*hori->h;
    courant3.y=position.y-0.5*hori->h;
    position.x=0;
    position.y =300;
    SDL_BlitSurface(hori, NULL, ecran,&position);
    position1.x=150;
    position1.y =100;
    SDL_BlitSurface(rectangle1, NULL, ecran,&position1);
    position2.y=100;
    position2.x=400;
    SDL_BlitSurface(rectangle2, NULL, ecran,&position2);
     position3.x =650;
    position3.y=100;
    SDL_BlitSurface(rectangle3, NULL, ecran,&position3);
    for(i=0;i<n;i++){
       if(barr1[i]==1){
           courant1.x=P1.position[i].x;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant1);
           courant1.y-=10;
           }
       if(barr2[i]==1){
           courant2.x=P2.position[i].x;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant2);
           courant2.y-=10;
           }
       if(barr3[i]==1){
           courant3.x=P3.position[i].x;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant3);
           courant3.y-=10;
           }
        }
    SDL_Flip(ecran);
     }


 void deplacer(int depart,int arrive){
     int i;
     Reconstruire();
     if((depart==1)&&(arrive==2))
     {
         for(i=nbrdisk-1;i>=0;i--)
             if(barr1[i]==1) {
                barr1[i]=0;
                break;
             }
          courant.x=P1.position[i].x;
          courant.y=P1.position[i].y;
          //deplacement vers le haut
          while(1)
        {
          Reconstruire();
          courant.y-=10;
          SDL_BlitSurface(disk[i],NULL,ecran,&courant);
          SDL_Flip(ecran);SDL_Delay(50);
          if(courant.y==80) break;
        }
        //deplacement horizontale
           while(1)
        {
           Reconstruire();
           courant.x+=10;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant);
           SDL_Flip(ecran);SDL_Delay(50);
           if(courant.x==P2.position[i].x) break;
        }
       //deplacement vers le bas
         while(1)
        {
           Reconstruire();
           courant.y+=10;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant);
           SDL_Flip(ecran);SDL_Delay(50);
           if(courant.y==courant2.y) break;
        }
        barr2[i]=1;
        Reconstruire();
        SDL_Flip(ecran);
     }
     //cas 2

     if((depart==1)&&(arrive==3))
     {
         for(i=nbrdisk-1;i>=0;i--)
             if(barr1[i]==1) {
                barr1[i]=0;
                break;
             }
          courant.x=P1.position[i].x;
          courant.y=P1.position[i].y;
          //deplacement vers le haut
          while(1)
        {
          Reconstruire();
          courant.y-=10;
          SDL_BlitSurface(disk[i],NULL,ecran,&courant);
          SDL_Flip(ecran);SDL_Delay(50);
          if(courant.y==80) break;
        }
        //deplacement horizontale
           while(1)
        {
           Reconstruire();
           courant.x+=10;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant);
           SDL_Flip(ecran);SDL_Delay(50);
           if(courant.x==P3.position[i].x) break;
        }
       //deplacement vers le bas
         while(1)
        {
           Reconstruire();
           courant.y+=10;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant);
           SDL_Flip(ecran);SDL_Delay(50);
           if(courant.y==courant3.y) break;
        }
        barr3[i]=1;
        Reconstruire();
        SDL_Flip(ecran);
     }
     //cas 3
     if((depart==2)&&(arrive==3))
     {
         for(i=nbrdisk-1;i>=0;i--)
             if(barr2[i]==1) {
                barr2[i]=0;
                break;
             }
          courant.x=P2.position[i].x;
          courant.y=P2.position[i].y;
          //deplacement vers le haut
          while(1)
        {
          Reconstruire();
          courant.y-=10;
          SDL_BlitSurface(disk[i],NULL,ecran,&courant);
          SDL_Flip(ecran);SDL_Delay(50);
          if(courant.y==80) break;
        }
        //deplacement horizontale
           while(1)
        {
           Reconstruire();
           courant.x+=10;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant);
           SDL_Flip(ecran);SDL_Delay(50);
           if(courant.x==P3.position[i].x) break;
        }
       //deplacement vers le bas
         while(1)
        {
           Reconstruire();
           courant.y+=10;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant);
           SDL_Flip(ecran);SDL_Delay(50);
           if(courant.y==courant3.y) break;
        }
        barr3[i]=1;
        Reconstruire();
        SDL_Flip(ecran);
     }
     //cas 4
          if((depart==2)&&(arrive==1))
     {
         for(i=nbrdisk-1;i>=0;i--)
             if(barr2[i]==1) {
                barr2[i]=0;
                break;
             }
          courant.x=P2.position[i].x;
          courant.y=P2.position[i].y;
          //deplacement vers le haut
          while(1)
        {
          Reconstruire();
          courant.y-=10;
          SDL_BlitSurface(disk[i],NULL,ecran,&courant);
          SDL_Flip(ecran);SDL_Delay(50);
          if(courant.y==80) break;
        }
        //deplacement horizontale
           while(1)
        {
           Reconstruire();
           courant.x-=10;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant);
           SDL_Flip(ecran);SDL_Delay(50);
           if(courant.x==P1.position[i].x) break;
        }
       //deplacement vers le bas
         while(1)
        {
           Reconstruire();
           courant.y+=10;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant);
           SDL_Flip(ecran);SDL_Delay(50);
           if(courant.y==courant1.y) break;
        }
        barr1[i]=1;
        Reconstruire();
        SDL_Flip(ecran);
     }
     //cas 5
          if((depart==3)&&(arrive==1))
     {
         for(i=nbrdisk-1;i>=0;i--)
             if(barr3[i]==1) {
                barr3[i]=0;
                break;
             }
          courant.x=P3.position[i].x;
          courant.y=P3.position[i].y;
          //deplacement vers le haut
          while(1)
        {
          Reconstruire();
          courant.y-=10;
          SDL_BlitSurface(disk[i],NULL,ecran,&courant);
          SDL_Flip(ecran);SDL_Delay(50);
          if(courant.y==80) break;
        }
        //deplacement horizontale
           while(1)
        {
           Reconstruire();
           courant.x-=10;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant);
           SDL_Flip(ecran);SDL_Delay(50);
           if(courant.x==P1.position[i].x) break;
        }
       //deplacement vers le bas
         while(1)
        {
           Reconstruire();
           courant.y+=10;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant);
           SDL_Flip(ecran);SDL_Delay(50);
           if(courant.y==courant1.y) break;
        }
        barr1[i]=1;
        Reconstruire();
        SDL_Flip(ecran);
     }
    //cas 6
              if((depart==3)&&(arrive==2))
     {
         for(i=nbrdisk-1;i>=0;i--)
             if(barr3[i]==1) {
                barr3[i]=0;
                break;
             }
          courant.x=P3.position[i].x;
          courant.y=P3.position[i].y;
          //deplacement vers le haut
          while(1)
        {
          Reconstruire();
          courant.y-=10;
          SDL_BlitSurface(disk[i],NULL,ecran,&courant);
          SDL_Flip(ecran);SDL_Delay(50);
          if(courant.y==80) break;
        }
        //deplacement horizontale
           while(1)
        {
           Reconstruire();
           courant.x-=10;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant);
           SDL_Flip(ecran);SDL_Delay(50);
           if(courant.x==P2.position[i].x) break;
        }
       //deplacement vers le bas
         while(1)
        {
           Reconstruire();
           courant.y+=10;
           SDL_BlitSurface(disk[i],NULL,ecran,&courant);
           SDL_Flip(ecran);SDL_Delay(50);
           if(courant.y==courant2.y) break;
        }
        barr2[i]=1;
        Reconstruire();
        SDL_Flip(ecran);
     }

    }

    void liberer(){
    int i;
    SDL_FreeSurface(hori);
    SDL_FreeSurface(rectangle1);
    SDL_FreeSurface(rectangle2);
    SDL_FreeSurface(rectangle3);
    for(i=0;i<nbrdisk;i++) SDL_FreeSurface(disk[i]);
     }

void initilisationTableau(Tableau t,int x){
     int i;
     for(i=0;i<nbrdisk;i++) t[i]=x;}
void hanoi(int n,int i,int j)
     {
     int intermediaire=6-(i+j);
     if(n>0){
           hanoi(n-1,i,intermediaire);
           deplacer(i,j);
           hanoi(n-1,intermediaire,j);
            }
     }

void pause()
{
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
        }
    }
}



void creer_disques()
{


    int n=nbrdisk,i=0,d=0;
    ecran = SDL_SetVideoMode(800, 400, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("tour hanoi !", NULL);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0,0,255));
    /*creation des barres*/
     hori = SDL_CreateRGBSurface(SDL_HWSURFACE,800,20, 32, 0,0, 0, 0);
    position.x=0;
    position.y =300;
    SDL_FillRect(hori, NULL, SDL_MapRGB(ecran->format, 0,0,255));
    SDL_BlitSurface(hori, NULL, ecran,&position);
    rectangle1 = SDL_CreateRGBSurface(SDL_HWSURFACE,10,200, 32, 0,0, 0, 0);
    position1.x=150;
    position1.y =100;
    SDL_FillRect(rectangle1, NULL, SDL_MapRGB(rectangle1->format, 0,0, 0));
    SDL_BlitSurface(rectangle1, NULL, ecran,&position1);
    position2.y=100;
    position2.x=400;
    rectangle2 = SDL_CreateRGBSurface(SDL_HWSURFACE,10,200, 32, 0,0, 0, 0);
    SDL_FillRect(rectangle2, NULL, SDL_MapRGB(rectangle2->format, 0,0, 0));
    SDL_BlitSurface(rectangle2, NULL, ecran,&position2);
     position3.x =650;
    position3.y=100;
    rectangle3 = SDL_CreateRGBSurface(SDL_HWSURFACE,10,200, 32, 0,0, 0, 0);
    SDL_FillRect(rectangle3, NULL, SDL_MapRGB(rectangle3->format, 0,0, 0));
    SDL_BlitSurface(rectangle3, NULL, ecran,&position3);
    for(i=0;i<n;i++){
        disk[i]=SDL_CreateRGBSurface(SDL_HWSURFACE,200-d,10,32,0,0,0,0);
        SDL_FillRect(disk[i],NULL,SDL_MapRGB(disk[i]->format,255,0,255));
        P1.position[i].x=position1.x-(disk[i]->w)/2+5;
        P1.position[i].y=position.y-d-0.5*hori->h;

        P2.position[i].x=position2.x-(disk[i]->w)/2+5;
        P2.position[i].y=position.y-d-0.5*hori->h;


        P3.position[i].x=position3.x-(disk[i]->w)/2+5;
        P3.position[i].y=position.y-d-0.5*hori->h;d+=10;
    }
        SDL_Flip(ecran);

    }


int main(int argc, char *argv[])
{




    SDL_Init(SDL_INIT_VIDEO);
    creer_disques();
    initilisationTableau(barr1,1);
    initilisationTableau(barr2,0);
    initilisationTableau(barr3,0);
    hanoi(nbrdisk,1,3);
    pause();
    liberer();
    SDL_Quit();
    return EXIT_SUCCESS;

}


