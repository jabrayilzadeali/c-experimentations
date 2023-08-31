#include "libcs50/cs50.h"
#include <string.h>

#include <stdio.h>

/*
 * This is shape maker
 * you can create
 * - [x] rectangle
 * - [x] square
 * - [x] triangle
 * - [ ] circle
 * - [ ] kite
 * - [ ] rhombus
 * - [ ] oval
 * - [ ] octagon
 * - [ ] parelleogram
 * - [ ] trapezium
 * - [ ] pentagon
 */

// if background is dark make sure it is true else false
bool dark_mode = true;

bool string_comparison(string str1, string str2)
{
    if (strlen(str1) != strlen(str2))
    {
        return false;
    }
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] == str2[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int print_outside_color()
{
    char block = dark_mode ? printf("⬜️") : printf("⬛️");
    return 0;
}

int print_inside_color()
{
    char block = dark_mode ? printf("⬛️") : printf("⬜️");
    return 0;
}

bool does_element_exist_in_shapes(char *shapes[], int length_of_shapes, char *user_selected_shape)
{
    for (int i = 0; i < length_of_shapes; i++)
    {
        if (string_comparison(shapes[i], user_selected_shape))
        {
            return true;
        }
    }
    return false;
}

int run_rectangle()
{
    int width;
    int height;
    bool dark_mode = true;
    char fill_inside;
    do
    {
        width = get_int("width: ");
        height = get_int("height: ");
        if (width <= 2 || height <= 2)
        {
            fill_inside = 'y';
        }
        else
        {
            fill_inside = get_char("fill inside(y/n): ");
        }
    } while (width < 0 && width > 70 && height < 0 && height > 70 && fill_inside != 'y' && fill_inside != 'n');
    // } while (fill_inside != 'y' && fill_inside != 'n');

    printf("Here we will create rectangle\n");
    if (fill_inside == 'n')
    {
        for (int row = 0; row < height; row++)
        {
            if (row == 0 || row == height - 1)
            {
                for (int i = 0; i < width; i++)
                {
                    print_outside_color();
                }
                printf("\n");
            }
            else
            {
                print_outside_color();
                for (int i = 0; i < width - 2; i++)
                {
                    print_inside_color();
                }
                print_outside_color();
                printf("\n");

            }
        }
    }
    else if (fill_inside == 'y')
    {
        for (int row = 0; row < height; row++)
        {
            for (int i = 0; i < width; i++)
            {
                print_outside_color();
            }
            printf("\n");
        }
    }

    printf("\n");
    return 0;
}

int run_square()
{
    printf("run square\n");
    int side;
    char fill_inside;
    do
    {
        side = get_int("side: ");
        if (side <= 2)
        {
            fill_inside = 'y';
        }
        else
        {
            fill_inside = get_char("fill inside(y/n): ");
        }
    } while (side < 0 && side > 70 && fill_inside != 'y' && fill_inside != 'n');
    printf("Here we will create square\n");
    if (fill_inside == 'n')
    {
        for (int row = 0; row < side; row++)
        {
            if (row == 0 || row == side - 1)
            {
                for (int i = 0; i < side; i++)
                {
                    print_outside_color();
                }
                printf("\n");
            }
            else
            {
                print_outside_color();
                for (int i = 0; i < side - 2; i++)
                {
                    print_inside_color();
                }
                print_outside_color();
                printf("\n");
            }
        }
    }
    else if (fill_inside == 'y')
    {
        for (int row = 0; row < side; row++)
        {
            for (int i = 0; i < side; i++)
            {
                print_outside_color();
            }
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}

int run_triangle()
{
    int side;
    char fill_inside;
    do
    {
        side = get_int("side: ");
        if (side <= 3)
        {
            fill_inside = 'y';
        }
        else
        {
            fill_inside = get_char("fill inside(y/n): ");
        }
    } while (side < 0 && side > 70 && fill_inside != 'y' && fill_inside != 'n');
    
    if (fill_inside == 'y')
    {
        for (int i = 0; i < side; i++)
        {
            for (int k = 0; k < i + 1; k++)
            {
                print_outside_color();
            }
            printf("\n");
        }
    }
    else if (fill_inside == 'n')
    {
        for (int row = 0; row < side; row++)
        {

            if (row == 0 || row == 1 || row == side - 1)
            {
                for (int col = 0; col < row + 1; col++)
                {
                    print_outside_color();
                }
                printf("\n");
            }
            else
            {
                for (int col = 0; col < row + 1; col++)
                {
                    // printf("row: %i\n", row);
                    if (col == 0 || col == row)
                    {
                        print_outside_color();
                    }
                    else
                    {
                        print_inside_color();
                    }
                }
                printf("\n");
                
            }
        }
        
    }
    
    
    
}

int main()
{

    string user_selected_shape;
    char *shapes[] = {
        "rectangle",
        "square",
        "triangle",
        "circle",
        "kite",
        "rhombus",
        "oval",
        "octagon",
        "parelleogram",
        "trapezium",
        "pentagon",
    };
    int length_of_shapes = sizeof(shapes) / sizeof(shapes[0]);

    do
    {
        bool str_comp = string_comparison("abcd", "abcd");
        printf("%b\n", str_comp);

        for (int i = 0; i < length_of_shapes; i++)
        {
            printf("- %s\n", shapes[i]);
        }

        user_selected_shape = get_string("Which shape you want to draw: ");
    } while (!does_element_exist_in_shapes(shapes, length_of_shapes, user_selected_shape));

    if (string_comparison(user_selected_shape, "rectangle"))
    {
        run_rectangle();
    }
    else if (string_comparison(user_selected_shape, "square"))
    {
        run_square();
    }
    else if (string_comparison(user_selected_shape, "triangle"))
    {
        run_triangle();
    }

    // check if element exist in shapes array
}
