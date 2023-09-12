#include <stdlib.h>
// #include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
typedef struct cordo
{
    int i;
    int j;
}cordo;


int main(){
    int line=0,col=0,first_diago=0,sec_diago=0;
    int moumouh;
    bool end_game=false,first_time=true,secondt_time=true;
    int board[3][3];
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=2;
        }
    }
    cordo prd,svt,my_choise;
    int cpt=0;                                      // it's the cpt hannouni
        while(end_game==false){
            if(first_time){
                // taking prd placement::start;first
                printf("\nenter the row number:");
                scanf("%d",&prd.i);
                printf("\nenter the column number:");
                scanf("%d",&prd.j);
                board[prd.i][prd.j]=1;
                cpt++;
                // taking iput placement::end;
                printf("\n\n");
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        printf("| %d |\t",board[i][j]);
                    }
                    printf("\n");
                }
                // boot respounce::start;first reponse;
                if(board[1][1]==2&&first_time){
                    board[1][1]=0;
                    cpt++;
                    first_time=false;
                    my_choise.i=1;
                    my_choise.j=1;
                }
                if(board[0][0]==2&&first_time){
                    board[0][0]=0;
                    cpt++;
                    first_time=false;
                    my_choise.i=0;
                    my_choise.j=0;
                }
                if(board[0][2]==2&&first_time){
                    board[0][2]=0;
                    cpt++;
                    first_time=false;
                    my_choise.i=0;
                    my_choise.j=2;
                }
                if(board[2][0]==2&&first_time){
                    board[2][0]=0;
                    cpt++;
                    first_time=false;
                    my_choise.i=2;
                    my_choise.j=0;
                }
                if(board[2][2]==2&&first_time){
                    board[2][2]=0;
                    cpt++;
                    first_time=false;
                    my_choise.i=2;
                    my_choise.j=2;
                }
                first_time=false;
            }
            // boot respounce::end;
            printf("\n\n");
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    printf("| %d |\t",board[i][j]);
                }
                printf("\n");
            }
                                                                // second turn start
            printf("\nenter the row number:");
            scanf("%d",&svt.i);
            printf("\nenter the column number:");
            scanf("%d",&svt.j);
            cpt++;
            board[svt.i][svt.j]=1;

            printf("\n\n");
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    printf("| %d |\t",board[i][j]);
                }
                printf("\n");
            }

        // boot respounce::start;second reponse;
        // the defence start
        if(secondt_time){
            if( prd.i==svt.i || prd.j==svt.j){
                if(prd.i==svt.i){
                    if(board[svt.i][0]+board[svt.i][1]+board[svt.i][2]==4){
                        for(int i =0;i<3;i++){
                            if(board[svt.i][i]==2){
                                board[svt.i][i]=0;
                                cpt++;
                            }
                        }
                    }
                }
                if(prd.j==svt.j){
                    if(board[0][svt.j]+board[1][svt.j]+board[2][svt.j]==4){
                        for(int i =0;i<3;i++){
                            if(board[i][svt.j]==2){
                                board[i][svt.j]=0;
                                cpt++;
                            }
                        }
                    }
                }
            }
            if((svt.i==2&&svt.j==0)&&(my_choise.i!=1&&my_choise.j!=1)){
                board[0][2]=0;
            }
            if((svt.i==0&&svt.j==2)&&(my_choise.i!=1&&my_choise.j!=1)){
                board[2][0]=0;
            }
            if((svt.i==2&&svt.j==2)&&(my_choise.i!=1&&my_choise.j!=1)){
                board[2][0]=0;
            }
            if((my_choise.i==1 && my_choise.j==1)){
                if((prd.i==prd.j && svt.i==svt.j)||(prd.i==svt.j&&prd.j==svt.i)){
                    board[2][1]=0;
                    cpt++;
                }
            }
            secondt_time=false;
        }
        // the defence end
        printf("\n\n");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                printf("| %d |\t",board[i][j]);
            }
            printf("\n");
        }

        // boot respounce::end;second reponse;
                                                                    // second turn end
                                                                    // after second turn start
        while(end_game==false){
            for(int i =0;i<3;i++){
                line=0,col=0,first_diago=0,sec_diago=0;
                for(int j =0;j<3;j++){
                    line=line+board[i][j];
                    col=col+board[j][i];
                    first_diago=first_diago+board[j][j];
                    sec_diago=sec_diago+board[2-j][j];
                }
                if(line==3||line==0||col==3||col==0||first_diago==3||first_diago==0||sec_diago==3||sec_diago==0){
                    // end_game=true;
                    break;
                }
                printf("\ntest\n");
            }
            if(end_game==false){
                printf("\nenter the row number:");
                scanf("%d",&prd.i);
                printf("\nenter the column number:");
                scanf("%d",&prd.j);
                board[prd.i][prd.j]=1;
                cpt++;

                printf("\n\n");
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        printf("| %d |\t",board[i][j]);
                    }
                    printf("\n");
                }

                if(cpt==9){end_game=true;}
                if(end_game==false){
                    bool hotit=false;
                    for(int i =0;i<3;i++){
                        line=0,col=0,first_diago=0,sec_diago=0;
                        for(int j =0;j<3;j++){
                            line=line+board[i][j];
                            col=col+board[j][i];
                            first_diago=first_diago+board[j][j];
                            sec_diago=sec_diago+board[2-j][j];
                        moumouh=j;
                        }
                        if(line==4){
                            for(int k=0;k<3;k++){
                                if(board[i][k]==2&&hotit==false){
                                    board[i][k]=0;
                                    cpt++;
                                    hotit=true;
                                }
                            }
                        }
                        if(col==4){
                            for(int k=0;k<3;k++){
                                if(board[k][moumouh]==2&&hotit==false){
                                    board[k][moumouh]=0;
                                    cpt++;
                                    hotit=true;
                                }
                            }
                        }
                        if(first_diago==4){
                            for(int k=0;k<3;k++){
                                if(board[k][k]==2&&hotit==false){
                                    board[k][k]=0;
                                    cpt++;
                                    hotit=true;
                                }
                            }
                        }
                        if(sec_diago==4){
                            for(int k=0;k<3;k++){
                                if(board[2-k][k]==2&&hotit==false){
                                    board[2-k][k]=0;
                                    cpt++;
                                    hotit=true;
                                }
                            }
                        }

                    }
                }
                printf("\n\n");
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        printf("| %d |\t",board[i][j]);
                    }
                    printf("\n");
                }

                }
            }

                                                                    //  end after second turn
        //the signs of the end of the game :: start;
        if(cpt==9){end_game=true;}
        //the signs of the end of the game :: end;
    }
    if(line==3||col==3||first_diago==3||sec_diago==3){
        printf("\nthe 1 player win");
    }
    if(line==0||col==0||first_diago==0||sec_diago==0){
        printf("\nthe 0 player win");
    }
    if(cpt>=9){
        printf("\nthe board is full");
    }
    printf("\nthe end");


    return 0;
}
