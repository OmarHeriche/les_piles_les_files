#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

float string_to_number(char ch){
    int number =ch-'0';
    return number;
}
/*void calculator(int a ,int b,char oper ,float *result){/////        the calculator :
    *result=a;
    if(oper=='+')
    {
    *result=a+b;
    printf("%.2f+%.2f=%.2f",a,b,*result);
    }
    if(oper=='-')
    {
    *result=a-b;
    printf("%.2f-%.2f=%.2f",a,b,*result);
    }
    if(oper=='*')
    {
    *result=a*b;
    printf("%.2fx%.2f=%.2f",a,b,*result);
    }
    if(oper=='/')
    {
    *result=a/b;
    printf("%.2f/%.2f=%.2f",a,b,*result);
    }

}*/

int main(){
    //printf("%d",'5'-'0');
    char ch[20],oper;
    int i,taille,cpt=0;//intializit d b 0;
    float a,b,result;
    printf("enter ur equation : ");
    scanf("%s",&ch);
    taille=strlen(ch);
    a=0;//////////////////////////////////hedda ta3 kbar;
    b=0;//////////////////////////////////hedda ta3 kbar tani;
    i=0;
    if ((ch[i]>='0'&&ch[i]<='9'))//make a ;
    {
        while((ch[i]>='0'&&ch[i]<='9')&&(ch[i]!='/')){
            a=a*10+string_to_number(ch[i]);
            i++;
            cpt++;
        }
        printf("\na=%.1f",a);
        //id+=1 ;//bach 2 fois mydkhlch l a;
        i=i-1;
    }
    int condoper=1,place;
    for (int i = cpt; i < taille; i++)
    {
        b=0;
        condoper=1;
        if ((ch[i]=='+')||(ch[i]=='-')||(ch[i]=='*')||(ch[i]=='/'))//make oper ;
        {
            if(condoper==1){
                place=i;
                condoper=0;
            }
            oper=ch[i];
            cpt++;
            //printf("\noper=%c",oper);
        }
        ////////////////////////            ta3 a:
        /*else if ((ch[i]>='0'&&ch[i]<='9')&&(id==0))
        {
            while((ch[i]>='0'&&ch[i]<='9')&&(ch[i]!='/')){
                a=a*10+string_to_number(ch[i]);
                i++;
                cpt++;
            }
            printf("\na=%.1f",a);
            id+=1 ;//bach 2 fois mydkhlch l a;
            i=i-1;
        }*/
        ///////////////////////////         ta3 b:
        else if (ch[i]>='0'&&ch[i]<='9')//make b;
        {
            while(i<taille&&(ch[i]>='0'&&ch[i]<='9')){
                b=b*10+string_to_number(ch[i]);
                i++;
                cpt++;
            }

            //printf("\nb=%.1f",b);
            i=i-1;
        }
        printf("\n");
        if(oper=='+'&&i!=place)
        {
        a=a+b;
        //printf("%.2f+%.2f=%.2f",a,b,a);
        }
        if(oper=='-'&&i!=place)
        {
        a=a-b;
        //printf("%.2f-%.2f=%.2f",a,b,a);
        }
        if(oper=='*'&&i!=place)
        {
        a=a*b;
        //printf("%.2fx%.2f=%.2f",a,b,result);
        }
        if(oper=='/'&&i!=place)
        {
        a=a/b;
        //printf("%.2f/%.2f=%.2f",a,b,a);
        }

    }
    //printf("\ncpt=%d\n",cpt);
    /*if(oper=='+')
    {
    result=a+b;
    printf("%.2f+%.2f=%.2f",a,b,result);
    }
    if(oper=='-')
    {
    result=a-b;
    printf("%.2f-%.2f=%.2f",a,b,result);
    }
    if(oper=='*')
    {
    result=a*b;
    printf("%.2fx%.2f=%.2f",a,b,result);
    }
    if(oper=='/')
    {
    result=a/b;
    printf("%.2f/%.2f=%.2f",a,b,result);
    }*/
    printf("\n");

    /////////////////////////////////////////////////el hedda :
    printf("\nthe result is : %.1f",a);
    return 0;
}
