#include <stdio.h>
#include <stdlib.h>
#include "./mylib.h"

void input(){
    int p;
    list *idx = NULL;

    while ((p=getchar()) != EOF){
        if (p == '\n'){
            idx = processed(idx);
            output(idx);
            allclean(idx);
            idx = NULL;
            p=getchar();
            if (p == EOF) break;
        }
        list *newLetter;
        newLetter = (list *)malloc(sizeof(list));
        newLetter->letter = p;
        newLetter->prev = idx;
        idx = newLetter;
    } 

    return;
}
