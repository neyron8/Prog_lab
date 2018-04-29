#include <stdio.h>
#include "func.h"

int main() {
    char stro[200] = {"C:\\Windows\\system32+E:\\Distrib\\msoffice.exe+/home/alex/prog/lab4.c"};
    printf("Here is your start string: %s\n", stro);
    process(stro);
    return 0;
}
