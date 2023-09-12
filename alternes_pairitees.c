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
    list a,p,i;
    a=NULL;
    p=NULL;
    i=NULL;
    int input;
    for(int i =0;i<5;i++){
        printf("\nenter the %d number : ",i+1);
        scanf("%d",&input);
        push(&a,input);
    }
    int cpt=0;
    while(pile_vide(a)!=true){
        pop(&a,&input);
        if(input%2==0){
            push(&p,input);
            cpt++;
        }
        else{
            push(&i,input);
            cpt--;
        }
    }
    list first, second;
    if(cpt>0){
        first=p;
        second=i;
    }
    else{
        first=i;
        second=p;
    }
    while(pile_vide(first)!=true&&pile_vide(second)!=true){
        pop(&first,&input);
        push(&a,input);
        pop(&second,&input);
        push(&a,input);
    }
    while(pile_vide(first)!=true){
        pop(&first,&input);
        push(&a,input);
    }
    while(pile_vide(second)!=true){
        pop(&second,&input);
        push(&a,input);
    }
    while (pile_vide(a)!=true)
    {
        pop(&a,&input);
        printf("\t%d",input);
    }
    if (cpt>=2)
    {
        printf("\nles nb paires rahom bzzaf !");
    }
    if (cpt<=-2)
    {
        printf("\nles nb impaires rahom bzzaf !");
    }
    
    
    return 0 ;
}