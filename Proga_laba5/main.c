#include <stdio.h>
#include "strings.h"

int main() {
    char stro[200]; // {"C:\\Windows\\system32+E:\\Distrib\\msoffice.exe+/home/alex/prog/lab4.c"};
    fgets(stro, 200, stdin);
    printf("Here is your start string: %s\n", stro);
    process(stro);
    return 0;
}
