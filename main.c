#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--------------declaration des variables globales
char unite[300]="//un /deux /trois /quatre /cinq /six /sept /huit /neuf /dix /onze /douze /treize /quatorze /quinze /seize /dix-sept /dix-huit /dix-neuf /";
char dizaine[300]="///vingt /trente /quarante /cinquante /soixante //quatre-vingt /";

//------------------------>header
char* centaine(double);
char* splitAt(char*,int);
char* toLettre(double);
char* concatener(char*,char*);

//------------------------->fonction principale
int main()
{
double n;
printf("TRANSFORMATION NOMBRE EN LETTRES\n");
printf("veuillez entrer votre nombre\n");
scanf("%lf",&n);
printf("reponse:%s",toLettre(n));

    return 0;
}

char* centaine (double n)
{
int nombre=(int)n;

if(nombre<20)
{
    return splitAt(unite,nombre);
}
else if(nombre<100)
{
int d=nombre/10,r;
d=(d==7)?6:d;
d=(d==9)?8:d;
r=(nombre-10*d);
return concatener(splitAt(dizaine,d),centaine(r));
}
else if(nombre<1000)
{
int c=nombre/100,r;
r=nombre-c*100;
c=(c==1)?0:c;
return concatener(concatener(splitAt(unite,c),"cent "),centaine(r));

}

}




//--------------−−>fonction pour extraire un chaine dont le format est le suivant: aaa/bbb/ccc/
//splitAt(1) retournerait bbb
char* splitAt(char*tab,int n)
{
n++;
int deb=0,fin=0,trouV=0,count=0,i;
char temp=" ",*res;
for(i=0;temp!='\0' && !trouV;i++)
    {
        temp=tab[i];
        if(temp=='/')count++;
        if(count==n && temp=='/')
        {
            deb=i;
        }
        if(count>n){
        fin=i;
        trouV=1;
        }
    }
res=(char*)malloc((fin-deb)*sizeof(char));
for(i=deb+1;i<fin;i++)res[i-deb-1]=tab[i];
res[fin]='\0';
return res;
}
//--------------------------->transformer en lettres
char* toLettre(double nombre)
{
if(nombre<1000)return centaine(nombre);
else
if(nombre<1000000)
{
int u=(int)nombre/1000,r;
r=(int)(nombre-u*1000);
u=(u==1)?0:u;
return concatener(concatener(centaine(u),"mille "),toLettre(r));

}
else
if(nombre<1000000000)
{
int u=(int)nombre/1000000,r;
r=(int)(nombre-u*1000000);
//u=(u==1)?0:u;
return concatener(concatener(centaine(u),"million "),toLettre(r));
}
else


//--------------−>phase experimental pour le milliard

if(nombre<1000000000000)
{
int u=(int)nombre/1000000000,r;
r=(int)(nombre-u*1000000000);

return concatener(concatener(centaine(u),"milliard "),toLettre(r));
}

}



//---------------------------->concatener deux chaines de caracter :)
char* concatener(char*t1,char*t2)
{int i;
char*res=(char*)malloc((strlen(t1)+strlen(t2))*sizeof(char));
for(i=0;i<strlen(t1);i++)res[i]=t1[i];
for(i=0;i<strlen(t2);i++)res[strlen(t1)+i]=t2[i];
return res;
}
