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

#ifndef ENUMS_H
#define ENUMS_H

#define VECTOR_AUTORESIZE_COEF 2
#define KEYWORDS_COUNT 10

enum error_codes
{
  E_OK,     //0  
  E_LEX,    //1
  E_SYNTAX,
  E_SEMANTIC_DEF,
  E_SEMANTIC_TYPES,
  E_AUTO_TYPE,
  E_SEMANTIC_OTHERS,
  E_READ_NUMBER,
  E_UNITIALIZED,
  E_ZERO_DIVISION,
  E_RUNTIME_OTHERS,
  E_INTERNAL

};

typedef enum tokens
{
//keywords
  token_auto,
  token_cin,
  token_cout,
  token_double,
  token_else,
  token_for,
  token_if,
  token_int,
  token_return,
  token_string,

//other tokens
  token_identifier, //identifier, not keyword
  token_eof

//math
  token_mul,
  token_div,
  token_add,
  token_sub,

//comparing
  token_equal,
  token_not_equal,
  token_greater,
  token_greater_equal,
  token_less,
  token_less_equal

//


}TToken_type;

#endif
