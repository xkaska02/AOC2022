#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE * input = fopen("day1_input.txt", "r");
    if(input == NULL){
        fprintf(stderr, "malloc chyba");
        return 1;
    }
    // 10 je random cislo co jsem vybral
    char line[10];
    int sum = 0;
    int max = 0;
    int max2 = 0;
    int max3 = 0;
    char * err_ptr;
    while(fgets(line,10,input)){
        sum+=strtol(line,&err_ptr,10);
        if(strcmp(line, "\n")==0){
            if(sum > max){
                max3 = max2;
                max2 = max;
                max = sum;
            } else if(sum > max2){
                max3 = max2;
                max2 = sum;
            } else if(sum > max3){
                max3 = sum;
            }
            sum = 0;
        }
    }
    // kvuli poslednimu radku, nevim jak porovnavat EOF tak tam nacpu tohle
    if(sum > max){
        max3 = max2;
        max2 = max;
        max = sum;
    } else if(sum > max2){
        max3 = max2;
        max2 = sum;
    } else if(sum > max3){
        max3 = sum;
    }
    printf("maximum je %d\n", max);
    printf("soucet 3 nejvyssich je %d\n", max+max2+max3);
    
    return 0;
}