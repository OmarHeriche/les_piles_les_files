#include <stdlib.h>
// #include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct cellule  *list;
typedef struct cellule{
    char info[100];
    list svt;
}cellule;

void allouer(list *nouv){
    *nouv=(list)malloc(sizeof(cellule));
}

bool pal(char ch[100]){
    int i =0,j=strlen(ch)-1;
    while (i<j)
    {
        if(ch[i]!=ch[j]){
            return(false);
        }
        i++;
        j--;
    }
    return(true);

}

int main(){
    printf("enter ur sentence :");
    char ch[50];
    scanf("%[^\n]s",ch);
    //char ch[50]="oimar ici a ab pallap";
    printf("the sentence : %s",ch);
    char *tmp;
    int i,j,tch,ttmp,k,cpt;
    tch=strlen(ch)-1;

    i=0;
    cpt=0;
    while(ch[tch]==' '){tch--;}
    while(i<=tch){
        k=0;
        while(ch[i]==' '&&i<=tch){
            i++;
        }
        j=i;
        while(ch[j]!=' '&&j<tch){
            j++;
        }
        if(ch[j]==' '){j--;}
        tmp=malloc(sizeof(char)*50);
        if(i-j==0){cpt++;}
        if(j-i==1&&ch[i]==ch[j]){cpt++;}
        while(i<=j&&ch[i]!=' '&&ch[j]!=' '){
            (tmp)[k]=ch[i];
            k++;
            i++;
        }
        i++;
        if(pal((tmp))==true){cpt++;}
    }
    printf("\nle nombre des palindromes : %d",cpt);
    return 0;
}

