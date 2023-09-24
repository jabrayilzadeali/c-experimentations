#include <stdio.h>
#include "libcs50/cs50.h"
// gcc tic_tac_toe.c -o bin/tic_tac_toe libcs50/cs50.c && ./bin/tic_tac_toe

#define TEST(func, expected)                                                    \
    do                                                                          \
    {                                                                           \
        int result = func;                                                      \
        if (result == expected)                                                 \
            printf("Test Passed: Expected = %d\n", expected);                   \
        else                                                                    \
            printf("Test Failed: Got = %d, Expected = %d\n", result, expected); \
    } while (0)

void display_board(char board[], int len);
void play_friend(char board[], int len);

int main()
{
    printf("Hello Tic Tac Toe\n");
    char board[] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };
    int len = sizeof(board) / sizeof(board[0]);
    int turn = 0;
    display_board(board, len);
    play_friend(board, len);

    return 0;
}

void display_board(char board[], int len)
{
    printf("\n");
    for (int i = 0; i < len; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("\n");
            printf("-----------\n");
        }
        if (board[i] == '-')
        {
            printf("   ");
        }
        else
        {
            printf(" %c ", board[i]);
        }

        if (i == 2 || i == 5 || i == 8)
        {
        }
        else
        {
            printf("|");
        }
    }
    printf("\n\n");
}

// {
//     0, 1, 2,
//     3, 4, 5,
//     6, 7, 8,
// }

bool define_winner(char board[], char player)
{
    if (
        (board[0] == board[1] && board[1] == board[2] && board[0] != '-' && board[1] != '-' && board[2] != '-') ||
        (board[3] == board[4] && board[4] == board[5] && board[3] != '-' && board[4] != '-' && board[5] != '-') ||
        (board[6] == board[7] && board[7] == board[8] && board[6] != '-' && board[7] != '-' && board[8] != '-') ||
        (board[0] == board[3] && board[3] == board[6] && board[0] != '-' && board[3] != '-' && board[6] != '-') ||
        (board[1] == board[4] && board[4] == board[7] && board[1] != '-' && board[4] != '-' && board[7] != '-') ||
        (board[2] == board[5] && board[5] == board[8] && board[2] != '-' && board[5] != '-' && board[8] != '-') ||
        (board[0] == board[4] && board[4] == board[8] && board[0] != '-' && board[4] != '-' && board[8] != '-') ||
        (board[6] == board[4] && board[4] == board[2] && board[6] != '-' && board[4] != '-' && board[2] != '-'))
    {
        printf("Player `%c` winned The Game\n", player);
        return true;
    }
    return false;
}


bool inside_the_array(char my_array[], char user_input)
{
    for (int i = 0; i < 9; i++)
    {
        if (user_input == my_array[i])
            return true;
    }
    return false;
}

int get_player_input(char player, char board[])
{
    char keys[] = { 'q', 'w', 'e', 'a', 's', 'd', 'z', 'x', 'c' };
    char user_input;
    int pos;

    do
    {
        user_input = get_char("%c: ", player);
        for (int i = 0; i < 9; i++)
        {
            if (keys[i] == user_input)
                pos = i;
        }
        if (!inside_the_array(keys, user_input) || board[pos] != '-')
        {
            printf("board[%i] = `%c` I am inside of this shit\n", pos, board[pos]);
        }
    }
    while (!inside_the_array(keys, user_input) || board[pos] != '-');
    printf("%c || ", board[pos]);
    printf("%i", pos);
    return pos;
}

void play_friend(char board[], int len)
{
    int turn = 0;
    while (turn < 9)
    {
        char player = turn % 2 == 0 ? 'X' : 'O';
        int pos = get_player_input(player, board);
        board[pos] = player;
        display_board(board, len);
        turn += 1;
        if (define_winner(board, player))
        {
            break;
        }
    }
}

void against_ai()
{
}