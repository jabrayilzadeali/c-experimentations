#include "libcs50/cs50.h"
#include <stdio.h>

void add_white_spaces(int height, int row)
{
    int white_spaces = height - row;
    for (int white_space_index = 0; white_space_index < white_spaces; white_space_index++)
    {
        printf(" ");
    }
}

void add_blocks(int row)
{
    for (int col = 0; col < row; col++)
    {
        printf("#");
    }
    
}

void draw(int height)
{
    for (int row = 1; row < height + 1; row++)
    {

        add_white_spaces(height, row);

        add_blocks(row);
        printf("  ");
        add_blocks(row);
        // Go new line
        printf("\n");
    }
}

int main()
{
    while(true)
    {
        int height;
        do
        {
            height = get_int("Height: ");
        } while (height < 0 || height > 8);
        printf("\n");
        draw(height);
        printf("\n");
    }
}
