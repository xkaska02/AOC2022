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
    FILE * input = fopen("day3_simple_input.txt", "r");
    if(input == NULL){
        fprintf(stderr, "malloc error");
        return 1;
    }
    // eyeballing the size is not the best solution i guess
    char line[50];
    char halfLine[25];
    int sum = 0;
    // naive solution
    /* while(fgets(line, 50, input)){
        secondHalfString(line,halfLine,strlen(line));
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
        }         
    } */

    // part two
    char line2[50];
    char line3[50];
    while(fgets(line, 50, input)){
        fgets(line2, 50, input);
        fgets(line3, 50, input);
        for(int i = 0; i < strlen(line); i++){
            if(strchr(line2, line[i])){
                if(strchr(line3, line[i])){
                    if(islower(line[i])){
                    sum += line[i] - 'a' + 1;
                    break; // it is given in the task that only 1 item per line is in both halves
                }else if(isupper(line[i])){
                    sum += line[i] - 'A' + 27;
                    break; // it is given in the task that only 1 item per line is in both halves
                }
                }
            }
        }
    }

    printf("%d\n", sum);
    return 0;
}