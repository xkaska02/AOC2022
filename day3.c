#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * @brief get second half of the string
 * 
 * @param original string we want to divide
 * @param secondHalf string where the half will be stored
 * @param size size of original string
 * @return error code
 */
int secondHalfString(char original[], char secondHalf[], int size){
    for(int i = 0; i <= size/2; i++){
        secondHalf[i] = original[(size/2)+i];
    }
    secondHalf[size/2] = '\0';
    return 0;
}

int main(){
    FILE * input = fopen("day3_input.txt", "r");
    if(input == NULL){
        fprintf(stderr, "malloc error");
        return 1;
    }
    // eyeballing the size is not the best solution i guess
    char line[50];
    char halfLine[25];
    int sum = 0;
    // fgets(line, 50, input);
    // secondHalfString(line, halfLine, strlen(line));
    // printf("%s", halfLine);
    // naive solution
    while(fgets(line, 50, input)){
        //printf("%c", line[0]);
        secondHalfString(line,halfLine,strlen(line));
        //printf("%s\n", halfLine);
        for(int i = 0; i<strlen(line)/2; i++){
            if(strchr(halfLine, line[i]) != NULL){
                if(islower(line[i])){
                    sum += line[i] - 'a' + 1;
                    break; // it is given in the task that only 1 item per line is in both halves
                }else if(isupper(line[i])){
                    sum += line[i] - 'A' + 27;
                    break; // it is given in the task that only 1 item per line is in both halves
                }
            }
            //break; 
        }         
    }
    printf("%d\n", sum);
    return 0;
}