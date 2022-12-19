#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int RPS(char myChoice, char oponentChoice){
    switch (myChoice)
    {
    case 'X':
        if(oponentChoice == 'A'){
            return 3;// draw
        }else if(oponentChoice == 'B'){
            return 0;// lost
        }else if(oponentChoice == 'C'){
            return 6;// won
        }
        break;
    case 'Y':
        if(oponentChoice == 'B'){
            return 3;// draw
        } else if(oponentChoice == 'C'){
            return 0;// lost
        }else if(oponentChoice == 'A'){
            return 6;// won
        }
        break;
    case 'Z':
        if(oponentChoice == 'C'){
            return 3;// draw
        } else if(oponentChoice == 'A'){
            return 0;// lost
        }else if(oponentChoice == 'B'){
            return 6;// won
        }
        break;
                
    default:
        break;
    }
}

int main(){
    FILE * input = fopen("day2_input.txt", "r");
    if(input == NULL){
        fprintf(stderr, "malloc chyba");
        return 1;
    }
    char line[5];
    int score = 0;
    while(fgets(line, 5, input)){
        // switch for choices i should play
        switch (line[2])
        {
        case 'X':
            score += 1;
            score += RPS(line[2], line[0]);
            break;
        case 'Y':
            score += 2;
            score += RPS(line[2], line[0]);
            break;

        case 'Z':
            score += 3;
            score += RPS(line[2], line[0]);
            break;

        default:
            fprintf(stderr, "wrong input");
            break;
        }
    }
    printf("score: %d\n", score);
    return 0;
}