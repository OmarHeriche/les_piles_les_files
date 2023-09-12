#include <stdlib.h>
// #include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct cellule *list;
typedef struct cellule{
    int info;
    list svt;
}cellule;

void allouer (list *nouv){
    *nouv=(list)malloc(sizeof(cellule));
}

void enfiler(list *tete,list *queue , int elt){
    list nouv;
    allouer(&nouv);
    nouv->info=elt;
    nouv->svt=NULL;
    if(*tete!=NULL){
        (*queue)->svt=nouv;
    }
    else{
        *tete=nouv;
    }
    *queue=nouv;
}

void defiler(list *tete,list *queue , int  *elt){
    list tmp =*tete;
    *elt =tmp->info;
    *tete=(*tete)->svt;
    free(tmp);
    if(*tete==NULL){
        *queue=NULL;
    }
}

int main(){
    int cpt=0,a,n,x ;
    printf("enter a : ");
    scanf("%d",&a);
    printf("enter n : ");
    scanf("%d",&n);

    list queue =NULL, tete=NULL;
    enfiler(&tete,&queue,a);
    cpt++;
    while(tete!=NULL){
        if(cpt<n){
            enfiler(&tete,&queue,2*(tete->info)+1);
            cpt++;
        }
        if(cpt<n){
            enfiler(&tete,&queue,3*(tete->info)+1);
            cpt++;
        }
        defiler(&tete,&queue,&x);
        printf("\t%d",x);
    }
    return 0 ;
}