#include <stdio.h>
#include "./mylib.h"


void outputRecursion(list *data){
    if (data->prev) outputRecursion(data->prev);
    printf("%c", data->letter);
    return;
}

void output(list *data){
    printf("output - '");
    outputRecursion(data);
    printf("'\n");
}
