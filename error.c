/*
 * Course IFJ @ FIT VUT Brno, 2015
 * IFJ15 Interpreter Project
 *
 * Authors:
 * Lukas Osadsky  - xosads00
 * Pavol Plaskon  - xplask00
 * Pavel Pospisil - xpospi88
 * Matej Postolka - xposto02
 *
 * Unless otherwise stated, all code is licensed under a
 * Creative Commons Attribution-ShareAlike 4.0 International License
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "galloc.h"

void exit_error(int err)
{
    switch(err)
    {
        case(E_LEX):
            fprintf(stderr, "Error: lexical error\n");
            break;          
        case(E_INTERNAL):
            fprintf(stderr, "Error: Something went wrong!\n");
            break;
        case(E_ALLOC):
            fprintf(stderr, "Error: Memory allocation failed!\n");
            err = E_INTERNAL;
            break;
    }
    
    gcDestroy();
    exit(err);
}