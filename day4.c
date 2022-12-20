#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE * input = fopen("day4_input.txt", "r");
    if(input == NULL){
        fprintf(stderr, "malloc error");
        return 1;
    }

    char line[15];
    int counter = 0;
    
	while(fgets(line, 15, input)){
        char* token = strtok(line, ",");
        char* rest = strtok(NULL, ",");
        char* first_number = strtok(token,"-");
        char* second_number = strtok(NULL, "-");
        char* third_number = strtok(rest, "-");
        char* fourth_number = strtok(NULL, "-");
        int num1, num2, num3, num4;
        num1 = strtol(first_number,NULL, 10);
        num2 = strtol(second_number,NULL, 10);
        num3 = strtol(third_number,NULL, 10);
        num4 = strtol(fourth_number,NULL, 10);
		// first range covers second
		if((num1 <= num3 && num2 >= num4) || (num3 <= num1 && num4 >= num2)){
			counter++;
		}
    }
	printf("counter %d\n", counter);
    return 0;
}