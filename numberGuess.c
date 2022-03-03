/*
Include headers

Declare and init: max number of game, max value that user can choose
Declare variables: number, guess number, input, conditions, guesses, total game
Declare Arrays: keep track of results and guesses

Declare and init the menu

loop menu:
    Print out the menu 
    Press 1 to play a game 
    Press 2 to change the max number 
    Press 3 to quit

    prompt for user selection

    1: randomize the number, reset number of guesses
       prompt and validate the guessing number
       allows 'q' as exit

       Init random number generator
            Too high
            Too low
            Correct and save the result


    2: prompt for max and validate the input

    3: exit the loop menu

output the thank you statement

result loop
    Print the results and number of guesses



*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum gameResult{LOST, WIN};

int main(){
    const int MAX_GAME = 1000;
    const int MAX_VALUE = 10000;

    int condition = 1, maxCond = 1;
    int number,  max = 10,inputMax, totalGame = 0, selection, numOfGuesses, correct; 
    char guessNumber[100];
    
    int result[MAX_GAME];
    int totalGuesses[MAX_GAME];
    
    
    const char *gameResult[] = {"Lost","Win"};
    const char menu[] = "Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n";

    time_t t;
    enum gameResult game;

    while(condition == 1){
        printf("\n%s\nYour selection: ",menu);
        scanf("%d", &selection);
        
        if(selection == 1){
            srand((unsigned) time(&t));
            number = (rand () % max) + 1; 
            numOfGuesses = 0;
            game = LOST;
            correct = 0;
            while(correct != 1){
                printf("Enter a number: ");
                scanf("%s", guessNumber);
                

                if(*guessNumber == 'q'){
                    break;
                }
                else{
                    if (atoi(guessNumber) == number){
                        game = WIN;
                        printf("=> Correct! You have won!\n");
                        correct = 1;
                    }
                    else if (atoi(guessNumber) > number){
                        printf("Too high\n");

                    }
                    else if (atoi(guessNumber) < number){
                        printf("Too low\n");
                    }
                }
                numOfGuesses++;
            }
            result[totalGame] = game;
            totalGuesses[totalGame]=numOfGuesses;
            totalGame++;


        }
        else if(selection == 2){
            maxCond = 1;
            printf("The max value you can set is: %d\n",MAX_VALUE);
            while(maxCond == 1){
                
                printf("Enter a new max value: ");
                scanf("%d",&inputMax);
                if(inputMax < 0){
                    printf("Max value cannot be negative!\n");
                }
                else if (inputMax > MAX_VALUE){
                    printf("Max value must be less than %d\n",MAX_VALUE);   
                }
                else{
                    max = inputMax;
                    maxCond = 0;
                }
            }


        }
        else if (selection == 3){
            break;
        }
        else{
            printf("Invalid Selection\n");
            
        }
        printf("----------------------------------\n");

    }
    printf("\nThank you for playing the Number Guessing Game!\n\n");
    printf("Game\tResult\tGuesses\n");
    for (int game = 0; game < totalGame; game++){

        printf("%d\t %s\t  %d\n", game, gameResult[result[game]], totalGuesses[game]);
       
    }
    return(0);
}

