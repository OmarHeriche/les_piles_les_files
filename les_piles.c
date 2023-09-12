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

typedef struct cordo{
    int i;
    int j;
}cordo;

typedef struct cellule2 *pile;
typedef struct cellule2{
    cordo info;
    pile svt;
}cellule2;

void allouer (list *nouv){
    *nouv=(list)malloc(sizeof(cellule));
}
void allouer_cordo (pile *nouv){
    *nouv=(pile)malloc(sizeof(cellule2));
}
void push(pile *p ,cordo src){
    pile nouv;
    allouer_cordo(&nouv);
    nouv->info=src;
    nouv->svt=*p;
    *p=nouv;
}
void pop(pile *p,cordo *dest){
    if (*p ==NULL)
    {
        printf("\nla pile est vide :");
    }
    else{
        *dest=(*p)->info;
        list tmp=*p;
        *p=(*p)->svt;
        free(tmp);
    }
}
bool pile_vide(pile p){
    if(p==NULL){
        return(true);
    }
    else{return(false);}
}

int main(){

    //          prepation :
    int l,c;
    printf("\nenter  the number of colomn :");
    scanf("%d",&c);
    printf("\nenter  the number of ligns :");
    scanf("%d",&l);

    int mat[l][c];
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("\nremplir %d , %d :",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    cordo start_pos,now_pos,tmp;
    printf("\nenter the lign  :");
    scanf("%d",&start_pos.i);
    printf("\nenter the colonne  :");
    scanf("%d",&start_pos.j);

    int li_rah_yrouh=mat[start_pos.i][start_pos.j];

                // process :
    list p=NULL;
    push(&p,start_pos);

    while (pile_vide(p)!=true)
    {
        pop(&p,&now_pos);
        if (mat[now_pos.i][now_pos.j]==li_rah_yrouh)
        {
            mat[now_pos.i][now_pos.j]=0;

            if (now_pos.i<l)
            {
                tmp=now_pos;
                tmp.i++;
                push(&p,tmp);
            }
            if (now_pos.i>0)
            {
                tmp=now_pos;
                tmp.i--;
                push(&p,tmp);
            }
            if (now_pos.j<c)
            {
                tmp=now_pos;
                tmp.j++;
                push(&p,tmp);
            }
            if (now_pos.j>0)
            {
                tmp=now_pos;
                tmp.j--;
                push(&p,tmp);
            }
        }
    }

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }





    return 0;
}
