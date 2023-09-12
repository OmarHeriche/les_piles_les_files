#include <stdlib.h>
// #include <stdio.h>
#include <unistd.h>

int main(){
    for(int h=0;h<24;h++){
        for(int  min=0;min<60;min++){
            for(int sec=0;sec<60;sec++){
                sleep(1);
                printf("\n%d:%d:%d",h,min,sec);
            }
        }
    }
}