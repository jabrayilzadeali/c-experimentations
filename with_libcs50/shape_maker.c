#include "libcs50/cs50.h"
#include <stdio.h>

/*
 * This is shape maker
 * you can create
 * circle
 * rectangle
 * square
 * triangle
 * kite
 * rhombus
 * oval
 * octagon
 * parelleogram
 * trapezium
 * pentagon
 */

int main()
{

    char *arr[] = {
        "circle",
        "rectangle",
        "square",
        "triangle",
        "kite",
        "rhombus",
        "oval",
        "octagon",
        "parelleogram",
        "trapezium",
        "pentagon",
    };
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("%s\n", arr[0]);
    printf("%s\n", arr[1]);
    for (int i = 0; i < length; i++)
    {
        printf("arr[%d] = %s\n", i, arr[i]);
    }

    string shape = get_string("Which shape you want to draw? ");
}
