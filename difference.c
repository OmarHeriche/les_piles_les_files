#include <stdlib.h>
// #include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

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

    list ta=NULL,qa=NULL,tb=NULL,qb=NULL,tc=NULL,qc=NULL,t_inter=NULL,q_inter=NULL;
    int x,b_val;
    printf("\nenter the number for a : ");
    scanf("%d",&x);
    while(x!=123){
        printf("\nenter the number for a : ");
        enfiler(&ta,&qa,x);
        scanf("%d",&x);
    }
    printf("\nenter the number for b : ");
    scanf("%d",&x);
    while(x!=123){
        printf("\nenter the number for b : ");
        enfiler(&tb,&qb,x);
        scanf("%d",&x);
    }
    bool existe=false;
    while(ta!=NULL){
        defiler(&ta,&qa,&x);
        while(tb!=NULL&&existe==false){
            defiler(&tb,&qb,&b_val);
            if(x==b_val){existe=true;}
            enfiler(&t_inter,&q_inter,b_val);
        }
        if(existe==false){
            enfiler(&tc,&qc,x);
        }
        else{existe=false;}
        while(t_inter!=NULL){
            defiler(&t_inter,&q_inter,&b_val);
            enfiler(&tb,&qb,b_val);
        }
    }
    printf("\nthe result :");
    list p=tc;
    while(p!=NULL){
        sleep(1);
        printf("\t%d",p->info);
        p=p->svt;
    }
    
    

    return 0;
    }