#include "libcs50/cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int find_this_number = rand() % 100 + 1;
    // printf("%i\n", find_this_number);
    bool ai_plays;
    char game_difficulty[7];
    int number_of_guesses;
    bool user_selected_difficulty;

    while (1) {
        string game_play = get_string("Play myself or AI plays for me: ");
        if (strcmp(game_play, "me") == 0 || strcmp(game_play, "m") == 0) {
            ai_plays = false;
            break;
        }
        else if (strcmp(game_play, "ai") == 0 || strcmp(game_play, "a") == 0) {
            ai_plays = true;

            while (1) {
                char game_play =
                    get_char("Do you want to provide guessed number(y) or "
                             "randomly generate(n)? ");
                if (game_play == 'y') {
                    find_this_number = get_int("guess number is: ");
                    // printf("%i\n", find_this_number);
                    break;
                }
                else if (game_play == 'n') {
                    // printf("%i\n", find_this_number);
                    break;
                }
            }

            break;
        }
        else {
            printf("You can only use followings\n");
            printf(" - `me` or `m`\n");
            printf(" - `ai` or `a`\n");
        }
    }

    printf("choose deficulty:\n - e or easy,\n - m or medium\n - h or hard");

    do {
        string get_difficulty = get_string("\nThe dificulty: ");
        if (strcmp(get_difficulty, "easy") == 0 ||
            strcmp(get_difficulty, "e") == 0) {
            number_of_guesses = 15;
            user_selected_difficulty = true;
            strcpy(game_difficulty, "easy");
        }
        else if (strcmp(get_difficulty, "medium") == 0 ||
                 strcmp(get_difficulty, "m") == 0) {
            number_of_guesses = 10;
            user_selected_difficulty = true;
            strcpy(game_difficulty, "medium");
        }
        else if (strcmp(get_difficulty, "hard") == 0 ||
                 strcmp(get_difficulty, "h") == 0) {
            number_of_guesses = 5;
            user_selected_difficulty = true;
            strcpy(game_difficulty, "hard");
        }
        else {
            printf("You can only use followings\n");
            printf(" - `easy` or `e`\n");
            printf(" - `medium` or `m`\n");
            printf(" - `hard` or `h`\n");
        }
    } while (!user_selected_difficulty);

    printf("You choose %s\n", game_difficulty);
    printf("You have to guess in %i try\n", number_of_guesses);
    printf("---------------------------\n");
    printf("-------- Good Luck --------\n");
    printf("---------------------------\n\n");

    if (ai_plays) {
        int i = 0;
        int ai_guess = 50;
        int closest_min = 1;
        int closest_max = 100;
        printf("Ai solves this for me\n");
        printf("-----------------------\n");
        printf("\n\n");
        printf("find this number: %i\n", find_this_number);
        while (i < number_of_guesses) {

            if (ai_guess == find_this_number) {
                printf("\n");
                printf("-----------------------\n");
                printf("AI guess: %i\n", ai_guess);
                printf("AI Won in %i try\n", ++i);
                exit(0);
            }

            if (ai_guess < find_this_number) {
                closest_min = ai_guess;
                int diff = closest_max - closest_min;

                printf("\n");
                printf("AI guess is smaller\n");
                printf("AI guess: %i\n", ai_guess);

                if (diff <= 2) {
                    ai_guess = closest_min + 1;
                    i++;
                    continue;
                }

                printf("-----------------------\n");
                // printf("AI guess: %i\n", ai_guess);
                // printf("closest_min: %i\n", closest_min);
                // printf("closest_max: %i\n", closest_max);
                // printf("diff: %i\n", diff);

                ai_guess = closest_min + diff / 2;

                // printf("new AI guess: %i\n", ai_guess);
                // printf("-----------------------\n");
            }
            else if (ai_guess > find_this_number) {
                closest_max = ai_guess;
                int diff = closest_max - closest_min;
                printf("\n");
                printf("AI guess is bigger\n");
                printf("AI guess: %i\n", ai_guess);
                if (diff <= 2) {
                    ai_guess = closest_max - 1;
                    i++;
                    continue;
                }

                printf("-----------------------\n");
                // printf("AI guess: %i\n", ai_guess);
                // printf("closest_min: %i\n", closest_min);
                // printf("closest_max: %i\n", closest_max);
                // printf("diff: %i\n", diff);

                ai_guess = closest_min + diff / 2;

                // printf("new AI guess: %i\n", ai_guess);
                // printf("-----------------------\n");
            }
            i++;
        }
        printf("Game Over\n");
        exit(0);
    }

    int i = 0;
    while (i < number_of_guesses) {

        int user_guess = get_int("Please guess the number: ");

        int remaining_guesses = number_of_guesses - i - 1;

        if (user_guess == find_this_number) {
            i += 1;
            printf("You Won in %i try\n", i);
            exit(0);
        }

        printf(">>> Your remaining guesses %i\n", remaining_guesses);
        if (user_guess > find_this_number) {
            printf("your guess is bigger | >\n");
            printf("-------------------\n");
        }
        else if (user_guess < find_this_number) {
            printf("your guess is smaller| <\n");
            printf("-------------------\n");
        }
        i++;
    }
    printf("Game over\n");
}
