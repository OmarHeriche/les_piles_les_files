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
void push(list *p ,int src){
    list nouv;
    allouer(&nouv);
    nouv->info=src;
    nouv->svt=*p;
    *p=nouv;
}
void pop(list *p,int *dest){

        *dest=(*p)->info;
        list tmp=*p;
        *p=(*p)->svt;
        free(tmp);

}
bool pile_vide(list p){
    if(p==NULL){
        return(true);
    }
    else{return(false);}
}

int main(){
    list a,b,c;
    a=NULL;
    b=NULL;
    c=NULL;
    int data;
    for (int i = 0; i < 5; i++)
    {
        printf("\nenter tha value : ");
        scanf("%d",&data);
        push(&a,data);
    }
    // printf("\nbefor sorting : ");
    // while(pile_vide(a)!=true)
    // {
    //     pop(&a,&data);
    //    printf("\t %d ",data);
    // }

    int x, max;
    while (a!=NULL)
    {
        pop(&a,&max);
        while (a!=NULL){
            pop(&a,&x);
            if(max<x){
                push(&c,max);
                max=x;
            }
            else{
                push(&c,x);
            }
        }
        push(&b,max);
        while (c!=NULL){
            pop(&c,&x);
            push(&a,x);
        }
    }
    printf("\nafter sorting :\n");
    list p=b;
        while(p!=NULL)
    {
       printf("\t %d ",p->info);
       p=p->svt;
    }
    printf("\nthe end");


    return 0;
}
