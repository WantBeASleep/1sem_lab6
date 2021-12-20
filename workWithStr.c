#include "./mylib.h"
#include <stdlib.h>

list *processed(list *data){
    list *sWorld = data;
    list *bindWorlds = data;
    int fFlag = 1;
    list fClean;
    fClean.prev = data;

    while(sWorld->prev){
        list *eWorld = sWorld;
        while ((sWorld->prev) && (sWorld->prev->letter != ' ')) sWorld = sWorld->prev;
        eWorld = oneWorldChange(sWorld, eWorld);
        if(fFlag) clean(&(fClean), eWorld), data = eWorld, fFlag = 0;
        else clean(bindWorlds, eWorld), bindWorlds->prev = eWorld;
        if (sWorld->prev){
            bindWorlds = sWorld->prev;
            sWorld = sWorld->prev->prev;
        }
        else break;
    }
    return data;
}

list *oneWorldChange(list *sWorld, list *eWorld){
    for(list *i = eWorld; i != sWorld; i = i->prev){
        int repFlag = 0;
        int charRep = i->letter;
        for(list *j = i->prev; j && j->letter != ' '; j = j->prev){
            if(j->letter == charRep){
                repFlag = 1;
                break;
            }
        }
        if(repFlag){
            if(i == eWorld) eWorld = eWorld->prev;
            else change(i, eWorld);
        }
    }
    return eWorld;
}

void clean(list *start, list *end){
    list *idx = start->prev;
    while (idx != end){
        list *tmp = idx;
        idx = idx->prev;
        free(tmp);
    }
}

void allclean(list *start){
    list *idx = start;
    while(idx){
        list *tmp = idx;
        idx = idx->prev;
        free(tmp);
    }
}

void change(list *index, list *data){
    list *bind = data;
    while (bind->prev != index) bind = bind->prev;
    free(bind->prev);
    bind->prev = bind->prev->prev;
}