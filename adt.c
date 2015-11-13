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

#include <string.h>
#include <stdlib.h>

#include "adt.h"
#include "enums.h"
#include "galloc.h"
#include "ilist.h"
#include "ial.h"
#include "stack.h"

TVariable* token_to_var(TToken *token)
{
    TVariable* var = gmalloc(sizeof(TVariable));

    
    if (token->type == TOKEN_IDENTIFIER)
    {
        var->initialized = 0;
        var->name = gmalloc(strlen(token->data) + 1);
        strcpy(var->name, token->data);   
    }
    else if(token->type == TOKEN_STRING_VALUE)
    {
        var->initialized = 1;
        var->name = gmalloc(strlen(token->data) + 1);
        strcpy(var->name, token->data);
        var->var_type = TYPE_STRING;
        var->data.str = var->name;
    }
    else if(token->type == TOKEN_DOUBLE_VALUE)
    {
        var->initialized = 1;
        var->name = gmalloc(strlen(token->data) + 1);
        strcpy(var->name, token->data);
        var->var_type = TYPE_DOUBLE;
        var->data.d = strtod(token->data, NULL);
    }
    else if(token->type == TOKEN_INT_VALUE)
    {
        var->initialized = 1;
        var->name = gmalloc(strlen(token->data) + 1);
        strcpy(var->name, token->data);
        var->var_type = TYPE_INT;
        var->data.i = strtod(token->data, NULL);
    }
    
    return var;
}

TFunction* token_to_function(TToken *token)
{
    TFunction* func = gmalloc(sizeof(TFunction));

    func->name = gmalloc(strlen(token->data) + 1);
    strcpy(func->name, token->data);
    func->defined = 0;
    func->ins_list = list_init();
    func->local_tab = htab_init(HTAB_SIZE);
    func->params_stack = stack_init();

    return func;
}