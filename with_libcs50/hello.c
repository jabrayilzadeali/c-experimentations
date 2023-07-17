#include <stdio.h>
#include "libcs50/cs50.h"

int main(void) {
    string name = get_string("What's your name? ");
    string city = get_string("Where do you live? ");
    printf("hello my name is , %s and I live in %s", name, city);
}