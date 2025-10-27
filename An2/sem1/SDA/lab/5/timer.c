//
// Created by student on 27/10/25.
//
/* fisierul timer.c */
#include <time.h>
#include "timer.h"

clock_t aux;

void starton(void)
{
    aux=clock();
}

float startoff(void)
{
    return(clock()-(float)aux);
}