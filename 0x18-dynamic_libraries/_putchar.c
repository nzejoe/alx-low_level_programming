#include "main.h"
#include <unistd.h>
/**
* main - this function takes a single character and prints to the screen
* @c: the character to print
* Return: retuns nothing
*/
int _putchar(char c) {
    return (write(1, &c, 1));
}

