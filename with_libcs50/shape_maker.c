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

    char *arr[] = {"ok", "cool"};
    for (int i = 0; i < 2; i++)
    {
        printf("arr[%d] = %c\n", i, arr[0]);
    }
    
    string shape = get_string("Which shape you want to draw? ");
}