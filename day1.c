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
    char * err_ptr;
    while(fgets(line,10,input)){
        sum+=strtol(line,&err_ptr,10);
        if(strcmp(line, "\n")==0){
            if(sum > max){
                max = sum;
            }
            sum = 0;
        }
    }
    printf("maximum je %d\n", max);
    
    return 0;
}