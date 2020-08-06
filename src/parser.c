/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "compile.h"
#include "jv_alloc.h"
#define YYMALLOC jv_mem_alloc
#define YYFREE jv_mem_free

#line 82 "src/parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_PARSER_H_INCLUDED
# define YY_YY_SRC_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 11 "src/parser.y"

#include "locfile.h"
struct lexer_param;

#define YYLTYPE location
#define YYLLOC_DEFAULT(Loc, Rhs, N)             \
  do {                                          \
    if (N) {                                    \
      (Loc).start = YYRHSLOC(Rhs, 1).start;     \
      (Loc).end = YYRHSLOC(Rhs, N).end;         \
    } else {                                    \
      (Loc).start = YYRHSLOC(Rhs, 0).end;       \
      (Loc).end = YYRHSLOC(Rhs, 0).end;         \
    }                                           \
  } while (0)

#line 134 "src/parser.c"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INVALID_CHARACTER = 258,       /* INVALID_CHARACTER  */
    IDENT = 259,                   /* IDENT  */
    FIELD = 260,                   /* FIELD  */
    LITERAL = 261,                 /* LITERAL  */
    FORMAT = 262,                  /* FORMAT  */
    REC = 263,                     /* ".."  */
    SETMOD = 264,                  /* "%="  */
    EQ = 265,                      /* "=="  */
    NEQ = 266,                     /* "!="  */
    DEFINEDOR = 267,               /* "//"  */
    AS = 268,                      /* "as"  */
    DEF = 269,                     /* "def"  */
    CODEF = 270,                   /* "codef"  */
    MODULE = 271,                  /* "module"  */
    IMPORT = 272,                  /* "import"  */
    INCLUDE = 273,                 /* "include"  */
    IF = 274,                      /* "if"  */
    THEN = 275,                    /* "then"  */
    ELSE = 276,                    /* "else"  */
    ELSE_IF = 277,                 /* "elif"  */
    REDUCE = 278,                  /* "reduce"  */
    FOREACH = 279,                 /* "foreach"  */
    END = 280,                     /* "end"  */
    AND = 281,                     /* "and"  */
    OR = 282,                      /* "or"  */
    TRY = 283,                     /* "try"  */
    CATCH = 284,                   /* "catch"  */
    LABEL = 285,                   /* "label"  */
    BREAK = 286,                   /* "break"  */
    LOC = 287,                     /* "__loc__"  */
    HIGHPRECPIPE = 288,            /* ">|"  */
    SETPIPE = 289,                 /* "|="  */
    SETPLUS = 290,                 /* "+="  */
    SETMINUS = 291,                /* "-="  */
    SETMULT = 292,                 /* "*="  */
    SETDIV = 293,                  /* "/="  */
    SETDEFINEDOR = 294,            /* "//="  */
    LESSEQ = 295,                  /* "<="  */
    GREATEREQ = 296,               /* ">="  */
    ALTERNATION = 297,             /* "?//"  */
    QQSTRING_START = 298,          /* QQSTRING_START  */
    QQSTRING_TEXT = 299,           /* QQSTRING_TEXT  */
    QQSTRING_INTERP_START = 300,   /* QQSTRING_INTERP_START  */
    QQSTRING_INTERP_END = 301,     /* QQSTRING_INTERP_END  */
    QQSTRING_END = 302,            /* QQSTRING_END  */
    FUNCDEF = 303,                 /* FUNCDEF  */
    NONOPT = 304                   /* NONOPT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INVALID_CHARACTER 258
#define IDENT 259
#define FIELD 260
#define LITERAL 261
#define FORMAT 262
#define REC 263
#define SETMOD 264
#define EQ 265
#define NEQ 266
#define DEFINEDOR 267
#define AS 268
#define DEF 269
#define CODEF 270
#define MODULE 271
#define IMPORT 272
#define INCLUDE 273
#define IF 274
#define THEN 275
#define ELSE 276
#define ELSE_IF 277
#define REDUCE 278
#define FOREACH 279
#define END 280
#define AND 281
#define OR 282
#define TRY 283
#define CATCH 284
#define LABEL 285
#define BREAK 286
#define LOC 287
#define HIGHPRECPIPE 288
#define SETPIPE 289
#define SETPLUS 290
#define SETMINUS 291
#define SETMULT 292
#define SETDIV 293
#define SETDEFINEDOR 294
#define LESSEQ 295
#define GREATEREQ 296
#define ALTERNATION 297
#define QQSTRING_START 298
#define QQSTRING_TEXT 299
#define QQSTRING_INTERP_START 300
#define QQSTRING_INTERP_END 301
#define QQSTRING_END 302
#define FUNCDEF 303
#define NONOPT 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "src/parser.y"

  jv literal;
  block blk;

#line 256 "src/parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (block* answer, int* errors, struct locfile* locations, struct lexer_param* lexer_param_ptr);

#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INVALID_CHARACTER = 3,          /* INVALID_CHARACTER  */
  YYSYMBOL_IDENT = 4,                      /* IDENT  */
  YYSYMBOL_FIELD = 5,                      /* FIELD  */
  YYSYMBOL_LITERAL = 6,                    /* LITERAL  */
  YYSYMBOL_FORMAT = 7,                     /* FORMAT  */
  YYSYMBOL_REC = 8,                        /* ".."  */
  YYSYMBOL_SETMOD = 9,                     /* "%="  */
  YYSYMBOL_EQ = 10,                        /* "=="  */
  YYSYMBOL_NEQ = 11,                       /* "!="  */
  YYSYMBOL_DEFINEDOR = 12,                 /* "//"  */
  YYSYMBOL_AS = 13,                        /* "as"  */
  YYSYMBOL_DEF = 14,                       /* "def"  */
  YYSYMBOL_CODEF = 15,                     /* "codef"  */
  YYSYMBOL_MODULE = 16,                    /* "module"  */
  YYSYMBOL_IMPORT = 17,                    /* "import"  */
  YYSYMBOL_INCLUDE = 18,                   /* "include"  */
  YYSYMBOL_IF = 19,                        /* "if"  */
  YYSYMBOL_THEN = 20,                      /* "then"  */
  YYSYMBOL_ELSE = 21,                      /* "else"  */
  YYSYMBOL_ELSE_IF = 22,                   /* "elif"  */
  YYSYMBOL_REDUCE = 23,                    /* "reduce"  */
  YYSYMBOL_FOREACH = 24,                   /* "foreach"  */
  YYSYMBOL_END = 25,                       /* "end"  */
  YYSYMBOL_AND = 26,                       /* "and"  */
  YYSYMBOL_OR = 27,                        /* "or"  */
  YYSYMBOL_TRY = 28,                       /* "try"  */
  YYSYMBOL_CATCH = 29,                     /* "catch"  */
  YYSYMBOL_LABEL = 30,                     /* "label"  */
  YYSYMBOL_BREAK = 31,                     /* "break"  */
  YYSYMBOL_LOC = 32,                       /* "__loc__"  */
  YYSYMBOL_HIGHPRECPIPE = 33,              /* ">|"  */
  YYSYMBOL_SETPIPE = 34,                   /* "|="  */
  YYSYMBOL_SETPLUS = 35,                   /* "+="  */
  YYSYMBOL_SETMINUS = 36,                  /* "-="  */
  YYSYMBOL_SETMULT = 37,                   /* "*="  */
  YYSYMBOL_SETDIV = 38,                    /* "/="  */
  YYSYMBOL_SETDEFINEDOR = 39,              /* "//="  */
  YYSYMBOL_LESSEQ = 40,                    /* "<="  */
  YYSYMBOL_GREATEREQ = 41,                 /* ">="  */
  YYSYMBOL_ALTERNATION = 42,               /* "?//"  */
  YYSYMBOL_QQSTRING_START = 43,            /* QQSTRING_START  */
  YYSYMBOL_QQSTRING_TEXT = 44,             /* QQSTRING_TEXT  */
  YYSYMBOL_QQSTRING_INTERP_START = 45,     /* QQSTRING_INTERP_START  */
  YYSYMBOL_QQSTRING_INTERP_END = 46,       /* QQSTRING_INTERP_END  */
  YYSYMBOL_QQSTRING_END = 47,              /* QQSTRING_END  */
  YYSYMBOL_FUNCDEF = 48,                   /* FUNCDEF  */
  YYSYMBOL_49_ = 49,                       /* '|'  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_51_ = 51,                       /* '='  */
  YYSYMBOL_52_ = 52,                       /* '<'  */
  YYSYMBOL_53_ = 53,                       /* '>'  */
  YYSYMBOL_54_ = 54,                       /* '+'  */
  YYSYMBOL_55_ = 55,                       /* '-'  */
  YYSYMBOL_56_ = 56,                       /* '*'  */
  YYSYMBOL_57_ = 57,                       /* '/'  */
  YYSYMBOL_58_ = 58,                       /* '%'  */
  YYSYMBOL_NONOPT = 59,                    /* NONOPT  */
  YYSYMBOL_60_ = 60,                       /* '?'  */
  YYSYMBOL_61_ = 61,                       /* ';'  */
  YYSYMBOL_62_ = 62,                       /* '('  */
  YYSYMBOL_63_ = 63,                       /* '$'  */
  YYSYMBOL_64_ = 64,                       /* ')'  */
  YYSYMBOL_65_ = 65,                       /* ':'  */
  YYSYMBOL_66_ = 66,                       /* '.'  */
  YYSYMBOL_67_ = 67,                       /* '['  */
  YYSYMBOL_68_ = 68,                       /* ']'  */
  YYSYMBOL_69_ = 69,                       /* '{'  */
  YYSYMBOL_70_ = 70,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_TopLevel = 72,                  /* TopLevel  */
  YYSYMBOL_Module = 73,                    /* Module  */
  YYSYMBOL_Imports = 74,                   /* Imports  */
  YYSYMBOL_FuncDefs = 75,                  /* FuncDefs  */
  YYSYMBOL_Exp = 76,                       /* Exp  */
  YYSYMBOL_Import = 77,                    /* Import  */
  YYSYMBOL_ImportWhat = 78,                /* ImportWhat  */
  YYSYMBOL_ImportFrom = 79,                /* ImportFrom  */
  YYSYMBOL_FuncDef = 80,                   /* FuncDef  */
  YYSYMBOL_Params = 81,                    /* Params  */
  YYSYMBOL_Param = 82,                     /* Param  */
  YYSYMBOL_String = 83,                    /* String  */
  YYSYMBOL_84_1 = 84,                      /* @1  */
  YYSYMBOL_85_2 = 85,                      /* @2  */
  YYSYMBOL_QQString = 86,                  /* QQString  */
  YYSYMBOL_ElseBody = 87,                  /* ElseBody  */
  YYSYMBOL_ExpD = 88,                      /* ExpD  */
  YYSYMBOL_Term = 89,                      /* Term  */
  YYSYMBOL_Args = 90,                      /* Args  */
  YYSYMBOL_Arg = 91,                       /* Arg  */
  YYSYMBOL_Patterns = 92,                  /* Patterns  */
  YYSYMBOL_Pattern = 93,                   /* Pattern  */
  YYSYMBOL_ArrayPats = 94,                 /* ArrayPats  */
  YYSYMBOL_ObjPats = 95,                   /* ObjPats  */
  YYSYMBOL_ObjPat = 96,                    /* ObjPat  */
  YYSYMBOL_Keyword = 97,                   /* Keyword  */
  YYSYMBOL_MkDict = 98,                    /* MkDict  */
  YYSYMBOL_MkDictPair = 99                 /* MkDictPair  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 127 "src/parser.y"

#include "lexer.h"
struct lexer_param {
  yyscan_t lexer;
};
#define FAIL(loc, msg)                                             \
  do {                                                             \
    location l = loc;                                              \
    yyerror(&l, answer, errors, locations, lexer_param_ptr, msg);  \
    /*YYERROR*/;                                                   \
  } while (0)

void yyerror(YYLTYPE* loc, block* answer, int* errors,
             struct locfile* locations, struct lexer_param* lexer_param_ptr, const char *s){
  (*errors)++;
  if (strstr(s, "unexpected")) {
#ifdef WIN32
      locfile_locate(locations, *loc, "jq: error: %s (Windows cmd shell quoting issues?)", s);
#else
      locfile_locate(locations, *loc, "jq: error: %s (Unix shell quoting issues?)", s);
#endif
  } else {
      locfile_locate(locations, *loc, "jq: error: %s", s);
  }
}

int yylex(YYSTYPE* yylval, YYLTYPE* yylloc, block* answer, int* errors,
          struct locfile* locations, struct lexer_param* lexer_param_ptr) {
  yyscan_t lexer = lexer_param_ptr->lexer;
  int tok = jq_yylex(yylval, yylloc, lexer);
  if ((tok == LITERAL || tok == QQSTRING_TEXT) && !jv_is_valid(yylval->literal)) {
    jv msg = jv_invalid_get_msg(jv_copy(yylval->literal));
    if (jv_get_kind(msg) == JV_KIND_STRING) {
      FAIL(*yylloc, jv_string_value(msg));
    } else {
      FAIL(*yylloc, "Invalid literal");
    }
    jv_free(msg);
    jv_free(yylval->literal);
    yylval->literal = jv_null();
  }
  return tok;
}

/* Returns string message if the block is a constant that is not valid as an
 * object key. */
static jv check_object_key(block k) {
  if (block_is_const(k) && block_const_kind(k) != JV_KIND_STRING) {
    char errbuf[15];
    return jv_string_fmt("Cannot use %s (%s) as object key",
        jv_kind_name(block_const_kind(k)),
        jv_dump_string_trunc(block_const(k), errbuf, sizeof(errbuf)));
  }
  return jv_invalid();
}

static block gen_index(block obj, block key) {
  return BLOCK(gen_subexp(key), obj, gen_op_simple(INDEX));
}

static block gen_index_opt(block obj, block key) {
  return BLOCK(gen_subexp(key), obj, gen_op_simple(INDEX_OPT));
}

static block gen_slice_index(block obj, block start, block end, opcode idx_op) {
  block key = BLOCK(gen_subexp(gen_const(jv_object())),
                    gen_subexp(gen_const(jv_string("start"))),
                    gen_subexp(start),
                    gen_op_simple(INSERT),
                    gen_subexp(gen_const(jv_string("end"))),
                    gen_subexp(end),
                    gen_op_simple(INSERT));
  return BLOCK(key, obj, gen_op_simple(idx_op));
}

static block constant_fold(block a, block b, int op) {
  if (!block_is_single(a) || !block_is_const(a) ||
      !block_is_single(b) || !block_is_const(b))
    return gen_noop();
  if (op == '+') {
    if (block_const_kind(a) == JV_KIND_NULL) {
      block_free(a);
      return b;
    }
    if (block_const_kind(b) == JV_KIND_NULL) {
      block_free(b);
      return a;
    }
  }
  if (block_const_kind(a) != block_const_kind(b))
    return gen_noop();

  jv res = jv_invalid();

  if (block_const_kind(a) == JV_KIND_NUMBER) {
    jv jv_a = block_const(a);
    jv jv_b = block_const(b);

    double na = jv_number_value(jv_a);
    double nb = jv_number_value(jv_b);

    int cmp = jv_cmp(jv_a, jv_b);

    switch (op) {
    case '+': res = jv_number(na + nb); break;
    case '-': res = jv_number(na - nb); break;
    case '*': res = jv_number(na * nb); break;
    case '/': res = jv_number(na / nb); break;
    case EQ:  res = (cmp == 0 ? jv_true() : jv_false()); break;
    case NEQ: res = (cmp != 0 ? jv_true() : jv_false()); break;
    case '<': res = (cmp < 0 ? jv_true() : jv_false()); break;
    case '>': res = (cmp > 0 ? jv_true() : jv_false()); break;
    case LESSEQ: res = (cmp <= 0 ? jv_true() : jv_false()); break;
    case GREATEREQ: res = (cmp >= 0 ? jv_true() : jv_false()); break;
    default: break;
    }
  } else if (op == '+' && block_const_kind(a) == JV_KIND_STRING) {
    res = jv_string_concat(block_const(a),  block_const(b));
  } else {
    return gen_noop();
  }

  if (jv_get_kind(res) == JV_KIND_INVALID)
    return gen_noop();

  block_free(a);
  block_free(b);
  return gen_const(res);
}

static block gen_binop(block a, block b, int op) {
  block folded = constant_fold(a, b, op);
  if (!block_is_noop(folded))
    return folded;

  const char* funcname = 0;
  switch (op) {
  case '+': funcname = "_plus"; break;
  case '-': funcname = "_minus"; break;
  case '*': funcname = "_multiply"; break;
  case '/': funcname = "_divide"; break;
  case '%': funcname = "_mod"; break;
  case EQ: funcname = "_equal"; break;
  case NEQ: funcname = "_notequal"; break;
  case '<': funcname = "_less"; break;
  case '>': funcname = "_greater"; break;
  case LESSEQ: funcname = "_lesseq"; break;
  case GREATEREQ: funcname = "_greatereq"; break;
  }
  assert(funcname);

  return gen_call(funcname, BLOCK(gen_lambda(a), gen_lambda(b)));
}

static block gen_format(block a, jv fmt) {
  return BLOCK(a, gen_call("format", gen_lambda(gen_const(fmt))));
}

static block gen_definedor_assign(block object, block val) {
  block tmp = gen_op_var_fresh(STOREV, "tmp");
  return BLOCK(gen_op_simple(DUP),
               val, tmp,
               gen_call("_modify", BLOCK(gen_lambda(object),
                                         gen_lambda(gen_definedor(gen_noop(),
                                                                  gen_op_bound(LOADV, tmp))))));
}

static block gen_update(block object, block val, int optype) {
  block tmp = gen_op_var_fresh(STOREV, "tmp");
  return BLOCK(gen_op_simple(DUP),
               val,
               tmp,
               gen_call("_modify", BLOCK(gen_lambda(object),
                                         gen_lambda(gen_binop(gen_noop(),
                                                              gen_op_bound(LOADV, tmp),
                                                              optype)))));
}


#line 572 "src/parser.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2383

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  174
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  346

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    63,    58,     2,     2,
      62,    64,    56,    54,    50,    55,    66,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    65,    61,
      52,    51,    53,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    67,     2,    68,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,    49,    70,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   309,   309,   328,   333,   336,   347,   350,   355,   358,
     363,   367,   394,   397,   401,   405,   409,   412,   415,   420,
     423,   426,   429,   432,   437,   444,   448,   452,   456,   460,
     464,   468,   472,   476,   480,   484,   488,   492,   496,   500,
     504,   508,   512,   518,   524,   528,   532,   536,   540,   544,
     548,   552,   556,   560,   565,   568,   585,   594,   601,   609,
     620,   625,   631,   634,   639,   643,   651,   658,   658,   662,
     662,   669,   672,   675,   681,   684,   689,   692,   695,   701,
     704,   707,   714,   718,   721,   724,   727,   730,   733,   736,
     739,   742,   745,   749,   755,   758,   761,   764,   767,   770,
     773,   776,   779,   782,   785,   788,   791,   794,   797,   800,
     803,   806,   809,   816,   820,   829,   841,   846,   847,   848,
     849,   852,   855,   860,   865,   868,   873,   877,   880,   885,
     888,   893,   896,   901,   904,   907,   910,   913,   916,   924,
     930,   933,   936,   939,   942,   945,   948,   951,   954,   957,
     960,   963,   966,   969,   972,   975,   978,   981,   984,   987,
     992,   995,   996,   997,  1000,  1003,  1006,  1009,  1013,  1017,
    1021,  1025,  1029,  1033,  1041
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INVALID_CHARACTER",
  "IDENT", "FIELD", "LITERAL", "FORMAT", "\"..\"", "\"%=\"", "\"==\"",
  "\"!=\"", "\"//\"", "\"as\"", "\"def\"", "\"codef\"", "\"module\"",
  "\"import\"", "\"include\"", "\"if\"", "\"then\"", "\"else\"",
  "\"elif\"", "\"reduce\"", "\"foreach\"", "\"end\"", "\"and\"", "\"or\"",
  "\"try\"", "\"catch\"", "\"label\"", "\"break\"", "\"__loc__\"",
  "\">|\"", "\"|=\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"//=\"",
  "\"<=\"", "\">=\"", "\"?//\"", "QQSTRING_START", "QQSTRING_TEXT",
  "QQSTRING_INTERP_START", "QQSTRING_INTERP_END", "QQSTRING_END",
  "FUNCDEF", "'|'", "','", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "NONOPT", "'?'", "';'", "'('", "'$'", "')'", "':'", "'.'", "'['",
  "']'", "'{'", "'}'", "$accept", "TopLevel", "Module", "Imports",
  "FuncDefs", "Exp", "Import", "ImportWhat", "ImportFrom", "FuncDef",
  "Params", "Param", "String", "@1", "@2", "QQString", "ElseBody", "ExpD",
  "Term", "Args", "Arg", "Patterns", "Pattern", "ArrayPats", "ObjPats",
  "ObjPat", "Keyword", "MkDict", "MkDictPair", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   124,
      44,    61,    60,    62,    43,    45,    42,    47,    37,   304,
      63,    59,    40,    36,    41,    58,    46,    91,    93,   123,
     125
};
#endif

#define YYPACT_NINF (-147)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-161)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,   876,     3,   122,   -24,   -15,  -147,    18,  -147,    63,
      26,   876,   225,   225,   942,    52,    22,  -147,   876,   616,
    1238,   309,   547,   377,  1621,   876,  -147,    -4,  -147,    -3,
      -3,   876,   122,   780,   876,  -147,  -147,     7,    65,  1994,
    2293,    51,    53,   616,   108,    74,  -147,  -147,   130,  -147,
      -9,    83,  1376,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,   876,  -147,  -147,   150,    18,    95,
      90,  -147,  1073,   -11,    94,   876,  2322,    98,   101,    97,
     119,   876,   876,   876,   876,   876,   876,   876,   876,   876,
     876,   876,   876,   876,   876,   876,   876,   876,   876,   876,
     876,   876,   876,   876,   876,   876,  -147,  -147,  2168,   112,
      66,    -2,   478,   161,  -147,  -147,  -147,  2168,   876,  -147,
    -147,  1657,  2168,    25,  -147,  -147,     8,   876,   113,   683,
      66,    66,  1268,   750,   127,  -147,    36,  -147,  -147,  1411,
    -147,  -147,  -147,  -147,   437,   118,  -147,   118,  1446,   114,
    -147,   118,   118,  -147,   437,  2238,   527,   527,  2203,   596,
     224,   145,  2238,  2238,  2238,  2238,  2238,  2238,   527,   527,
    2168,  2203,  2238,   527,   527,    -9,    -9,    -8,    -8,    -8,
    -147,   178,    66,   999,    11,  -147,   876,   123,   120,   876,
     126,  1037,    16,  -147,  -147,   876,  -147,    99,  -147,  2351,
      84,  -147,  1693,   185,  -147,  1890,   -36,    15,   876,  -147,
     145,   876,  -147,   876,  -147,  -147,   -19,  -147,   118,   141,
       9,   141,   128,   118,   141,   141,  -147,  -147,  -147,   -13,
     129,   132,   876,   188,   135,     0,  -147,   136,    66,   876,
    1109,  -147,  -147,  1145,  -147,   846,   142,  -147,   199,  -147,
    -147,  -147,  -147,     8,   140,  -147,   143,   876,   876,  -147,
    -147,   876,   876,  1304,  2168,  2029,  -147,   118,   118,   141,
      66,  -147,    66,    66,  1481,   144,    66,   999,  -147,    66,
    -147,  2168,   146,   147,   152,  1181,  -147,  -147,  -147,   876,
     876,  2081,  2133,  1729,  1765,   876,  -147,  -147,   141,   141,
    -147,  -147,  -147,   148,    66,  -147,  -147,  -147,  -147,  -147,
    -147,   154,  1801,  1837,  -147,   876,   876,   876,  1516,    66,
    -147,  -147,  -147,   876,  1942,  1551,  1340,  -147,  -147,  2168,
    -147,  -147,   876,  -147,  1586,  -147
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     6,   115,    89,   106,   108,    80,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
       0,     0,     0,     0,     0,     0,   107,    52,     1,     0,
       0,     8,     6,     0,     0,    85,    69,     0,     0,     0,
       0,     0,     0,     0,    22,     0,    82,    83,     0,    71,
      37,     0,     0,   113,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,     0,   114,    92,     0,     0,    91,
       0,   111,     0,     0,   171,     0,     0,   167,   172,     0,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     5,    10,    88,
       0,     0,     0,     0,    59,    58,     3,     2,     8,     7,
      54,     0,   123,     0,   121,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,   117,   109,     0,
      93,    87,   118,   110,     0,     0,   120,     0,     0,   169,
     170,     0,     0,   112,     0,    45,    46,    47,    29,    28,
      27,    33,    31,    36,    39,    41,    44,    30,    50,    51,
      32,    34,    26,    48,    49,    35,    38,    40,    42,    43,
      84,     0,     0,     0,     0,   125,     0,    90,     0,     0,
      99,     0,     0,     9,    55,     0,   116,     0,    66,     0,
       0,    62,     0,     0,    18,     0,     0,     0,     0,    23,
      21,     0,    72,     0,    68,    53,     0,   163,     0,   174,
      78,   164,     0,     0,   166,   165,   162,   126,   129,     0,
       0,     0,     0,     0,     0,     0,   131,     0,     0,     0,
       0,    86,   119,     0,    98,     0,    95,    57,     0,   122,
      70,    64,    65,     0,     0,    60,     0,     0,     0,    17,
      16,     0,     0,     0,    24,     0,    77,     0,     0,   168,
       0,   127,     0,     0,     0,   133,     0,     0,   128,     0,
     124,    12,    97,   105,   104,     0,    94,    56,    63,     0,
       0,     0,     0,     0,     0,     0,    19,    73,    76,   173,
     130,   139,   135,     0,     0,   137,   132,   136,    96,   102,
     101,   103,     0,     0,    75,     0,     0,     0,     0,     0,
     134,   100,    61,     0,     0,     0,     0,    20,   138,    11,
      74,    13,     0,    15,     0,    14
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,   183,    82,    -1,  -147,  -147,   186,   -12,
    -147,   -45,     6,  -147,  -147,    86,  -115,  -146,    -5,  -147,
      19,    13,  -118,  -147,  -147,   -62,   -18,  -120,  -147
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    31,   126,   118,    32,    33,   123,    25,
     210,   211,    26,    49,   135,   146,   270,   229,    27,   133,
     134,   194,   195,   239,   245,   246,    88,    89,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   119,    75,    28,    78,    78,   248,    41,    42,   120,
      39,   231,   208,    44,   119,   234,   235,    50,    52,   128,
     257,    82,    75,    46,    97,    97,   271,    79,    47,    87,
     127,   154,   131,   132,   227,   124,   124,   280,    34,   154,
      17,    17,   142,     1,   236,    35,   155,   113,   114,   115,
     287,   116,   116,   248,   155,   281,   119,   248,   119,   156,
     249,    36,   121,   122,   140,   196,   141,    37,   160,   136,
     288,   209,   137,   149,   238,   121,   122,   272,   144,   258,
     222,   223,   276,   224,   158,    48,   205,   279,    38,   206,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,    45,   128,   121,   122,   121,
     122,   201,     4,     5,     6,     7,     8,   197,   138,   191,
     290,   308,   309,   192,   145,   193,   212,   143,   215,    29,
      30,    97,   220,   222,   223,   263,   260,   147,   264,    16,
     230,   150,   230,   216,   217,   151,   230,   230,   152,   157,
      87,    17,   310,   161,   311,   312,   162,   163,   315,   164,
      87,   317,   190,   228,   202,   247,   221,   213,    97,   233,
      19,    40,   237,   251,    21,    22,   254,    23,   252,   266,
     277,   262,   285,   278,   282,   250,   330,   283,   253,   244,
     286,   289,   296,   297,   132,   299,   318,   319,   300,   314,
     203,   338,   320,   329,   331,   129,   125,   273,   298,   340,
     274,   207,   275,   230,   259,   316,     0,     0,   230,     4,
       5,     6,     7,     8,    92,    93,     0,     0,     0,     0,
       0,   284,     0,     0,     0,     0,     0,     0,   291,     0,
      95,     0,     0,     0,   295,     0,    16,    97,     0,     0,
       0,     0,     0,     0,   104,   105,   301,   302,    17,   247,
     303,   304,   230,   230,     0,     0,   109,   110,   111,   112,
     113,   114,   115,     0,   116,     0,     0,    19,    40,     0,
       0,    21,    22,   244,    23,     0,     0,     0,   322,   323,
       0,     0,     0,     0,   328,     0,     0,     0,     0,   -79,
      76,     0,     0,    77,   -79,     0,    78,     0,   -79,   -79,
     -79,   -79,   -79,     0,   334,   335,   336,     0,     0,   -79,
     -79,   -79,   339,     0,   -79,   -79,   -79,     0,   -79,     0,
       0,   344,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,     0,    17,     0,     0,   -79,     0,     0,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,     0,   -79,
     -79,     0,     0,   -79,   -79,   -79,   -79,   -79,    83,   -79,
       0,    84,     0,     0,    78,     0,     0,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,    85,
      86,    84,     0,     0,    78,     0,     0,  -160,     0,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
      17,     0,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     0,     9,    10,     0,     0,     0,    11,     0,    85,
      86,    12,    13,     0,     0,     0,    14,  -160,    15,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,  -161,  -161,     0,
      19,    20,     0,   199,    21,    22,   200,    23,    80,     0,
       0,     4,     5,     6,     7,     8,     0,     0,     0,     0,
      97,     9,    10,     0,     0,     0,    11,  -161,  -161,     0,
      12,    13,     0,     0,     0,    14,     0,    15,    16,  -161,
    -161,   111,   112,   113,   114,   115,     0,   116,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,    92,    93,     0,    19,
      20,     0,     0,    21,    22,    81,    23,    51,     0,     0,
       4,     5,     6,     7,     8,     0,     0,     0,     0,    97,
       9,    10,     0,     0,     0,    11,   104,   105,     0,    12,
      13,     0,     0,     0,    14,     0,    15,    16,   109,   110,
     111,   112,   113,   114,   115,     0,   116,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,     0,    19,    20,
       0,     0,    21,    22,   214,    23,     0,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     0,     9,    10,     0,
       0,     0,    11,     0,     0,     0,    12,    13,     0,     0,
       0,    14,     0,    15,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,     0,    19,    20,     0,     0,    21,
      22,   219,    23,     0,     4,     5,     6,     7,     8,     0,
       0,     0,     0,     0,     9,    10,     0,     0,     0,    11,
       0,     0,     0,    12,    13,     0,     0,     0,    14,     0,
      15,    16,     0,     0,     4,     5,     6,     7,     8,     0,
       0,     0,     0,    17,     9,    10,     0,     0,     0,    11,
       0,     0,     0,    12,    13,    18,     0,     0,    14,     0,
      15,    16,    19,    20,     0,     0,    21,    22,     0,    23,
       0,     0,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,   130,    19,    20,     0,     0,    21,    22,     0,    23,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       9,    10,     0,     0,     0,    11,     0,     0,     0,    12,
      13,     0,     0,     0,    14,     0,    15,    16,     0,     0,
       4,     5,     6,     7,     8,     0,     0,     0,     0,    17,
       9,    10,     0,     0,     0,    11,     0,     0,     0,    12,
      13,    18,     0,     0,    14,     0,    15,    16,    19,    20,
       0,     0,    21,    22,   294,    23,     0,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,     0,    19,    20,
       0,     0,    21,    22,     0,    23,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     0,     9,    10,     0,     0,
       0,    11,     0,     0,     0,    12,    13,     0,     0,     0,
      14,     0,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
     240,     0,     0,   241,    43,    20,    78,     0,    21,    22,
       0,    23,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     0,     0,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,   243,    95,    96,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
       0,     0,    91,    92,    93,    94,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,   116,     0,    95,
      96,     0,   255,     0,     0,   256,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,    91,    92,
      93,    94,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,   116,     0,    95,    96,     0,     0,     0,
       0,   153,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,    91,    92,    93,    94,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
       0,    95,    96,     0,     0,     0,     0,   292,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,     0,     0,
      91,    92,    93,    94,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,   116,     0,    95,    96,     0,
       0,     0,     0,   293,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,    53,     0,     0,     0,     0,     0,     0,   321,
       0,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,     0,     0,     0,     0,
      74,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,    91,    92,    93,    94,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,   218,
      95,    96,   148,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,    91,
      92,    93,    94,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   305,    95,    96,   306,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,    91,    92,    93,    94,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     116,   342,    95,    96,   343,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
      91,    92,    93,    94,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,    95,    96,     0,
     148,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,    91,    92,    93,    94,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,    95,    96,     0,   225,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
      91,    92,    93,    94,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,    95,    96,     0,
     232,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,    91,    92,    93,    94,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,    95,    96,     0,   313,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
      91,    92,    93,    94,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,    95,    96,     0,
     337,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,    91,    92,    93,    94,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,    95,    96,     0,   341,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
      91,    92,    93,    94,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,    95,    96,     0,
     345,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,    91,    92,    93,    94,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,   117,    95,    96,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
       0,     0,    91,    92,    93,    94,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,   116,   204,    95,
      96,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,    91,    92,
      93,    94,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,   116,   265,    95,    96,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,    91,    92,    93,    94,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
     326,    95,    96,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,     0,     0,
      91,    92,    93,    94,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,   116,   327,    95,    96,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,    91,    92,    93,    94,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,   332,    95,    96,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,   116,   333,    91,
      92,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,   267,   268,     0,     0,   269,    95,    96,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     116,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,   267,   268,     0,     0,     0,    95,    96,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,     0,     0,     0,     0,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,   139,     0,     0,     0,     0,     0,
      95,    96,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,    91,    92,
      93,    94,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,    95,    96,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,     0,   307,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
      91,    92,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   324,    95,    96,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,    91,    92,    93,    94,     0,     0,     0,     0,
       0,     0,     0,   325,     0,     0,     0,     0,     0,    95,
      96,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,    91,    92,    93,
      94,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,   116,    95,    96,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,    91,    92,    93,    94,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,    95,
      96,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,  -161,    92,    93,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,     0,   116,    95,    96,     0,     0,     0,     0,
       0,    97,  -161,  -161,  -161,  -161,  -161,  -161,   104,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -161,
     109,   110,   111,   112,   113,   114,   115,    53,   116,     0,
       0,     0,     0,     0,     0,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,   159,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,   261,     0,     0,     0,     0,
       0,     0,     0,     0,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
       1,     5,    20,     0,     7,     7,    42,    12,    13,    13,
      11,   157,     4,    14,     5,   161,   162,    18,    19,    31,
       4,    22,    40,     1,    33,    33,    62,    21,     6,    23,
      31,    50,    33,    34,   154,    29,    30,    50,    62,    50,
      43,    43,    43,    16,   164,    60,    65,    56,    57,    58,
      50,    60,    60,    42,    65,    68,     5,    42,     5,    70,
      49,    43,    66,    67,    13,    67,    13,     4,    86,    62,
      70,    63,    65,    74,   192,    66,    67,    62,     4,    63,
      44,    45,   228,    47,    85,    63,    61,   233,    62,    64,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    63,   128,    66,    67,    66,
      67,   122,     4,     5,     6,     7,     8,   121,    63,    63,
     248,   277,   278,    67,     4,    69,   137,    29,   139,    17,
      18,    33,   143,    44,    45,    61,    47,    64,    64,    31,
     155,     1,   157,   140,   141,    60,   161,   162,    68,    65,
     154,    43,   280,    65,   282,   283,    65,    70,   286,    50,
     164,   289,    60,    55,    13,   193,    49,    64,    33,    65,
      62,    63,     4,    60,    66,    67,    60,    69,    68,     4,
      49,   209,     4,    65,    65,   196,   314,    65,   199,   193,
      65,    65,    60,     4,   205,    65,    60,    60,    65,    65,
     128,   329,    60,    65,    60,    32,    30,   218,   263,   334,
     221,   135,   223,   228,   205,   287,    -1,    -1,   233,     4,
       5,     6,     7,     8,    10,    11,    -1,    -1,    -1,    -1,
      -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,
      26,    -1,    -1,    -1,   255,    -1,    31,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,   267,   268,    43,   287,
     271,   272,   277,   278,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    -1,    -1,    62,    63,    -1,
      -1,    66,    67,   287,    69,    -1,    -1,    -1,   299,   300,
      -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,     0,
       1,    -1,    -1,     4,     5,    -1,     7,    -1,     9,    10,
      11,    12,    13,    -1,   325,   326,   327,    -1,    -1,    20,
      21,    22,   333,    -1,    25,    26,    27,    -1,    29,    -1,
      -1,   342,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,     1,    70,
      -1,     4,    -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    62,
      63,     4,    -1,    -1,     7,    -1,    -1,    70,    -1,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      43,    -1,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    14,    15,    -1,    -1,    -1,    19,    -1,    62,
      63,    23,    24,    -1,    -1,    -1,    28,    70,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    10,    11,    -1,
      62,    63,    -1,    65,    66,    67,    68,    69,     1,    -1,
      -1,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      33,    14,    15,    -1,    -1,    -1,    19,    40,    41,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    31,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    10,    11,    -1,    62,
      63,    -1,    -1,    66,    67,    68,    69,     1,    -1,    -1,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    33,
      14,    15,    -1,    -1,    -1,    19,    40,    41,    -1,    23,
      24,    -1,    -1,    -1,    28,    -1,    30,    31,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    -1,    66,    67,     1,    69,    -1,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,
      67,     1,    69,    -1,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,    -1,
      30,    31,    -1,    -1,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    43,    14,    15,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    23,    24,    55,    -1,    -1,    28,    -1,
      30,    31,    62,    63,    -1,    -1,    66,    67,    -1,    69,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    -1,    -1,    66,    67,    -1,    69,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      14,    15,    -1,    -1,    -1,    19,    -1,    -1,    -1,    23,
      24,    -1,    -1,    -1,    28,    -1,    30,    31,    -1,    -1,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    43,
      14,    15,    -1,    -1,    -1,    19,    -1,    -1,    -1,    23,
      24,    55,    -1,    -1,    28,    -1,    30,    31,    62,    63,
      -1,    -1,    66,    67,    68,    69,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    -1,    66,    67,    -1,    69,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,
      28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
       1,    -1,    -1,     4,    62,    63,     7,    -1,    66,    67,
      -1,    69,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,     9,    10,    11,    12,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    -1,    26,
      27,    -1,    65,    -1,    -1,    68,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,     9,    10,
      11,    12,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    60,    -1,    26,    27,    -1,    -1,    -1,
      -1,    68,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,     9,    10,    11,    12,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,    26,    27,    -1,    -1,    -1,    -1,    68,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
       9,    10,    11,    12,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,    -1,    26,    27,    -1,
      -1,    -1,    -1,    68,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,     4,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,
      62,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,     9,    10,    11,    12,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      26,    27,    64,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,     9,
      10,    11,    12,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    26,    27,    64,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,     9,    10,    11,    12,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    26,    27,    64,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
       9,    10,    11,    12,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    26,    27,    -1,
      64,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,     9,    10,    11,    12,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    26,    27,    -1,    64,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
       9,    10,    11,    12,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    26,    27,    -1,
      64,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,     9,    10,    11,    12,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    26,    27,    -1,    64,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
       9,    10,    11,    12,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    26,    27,    -1,
      64,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,     9,    10,    11,    12,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    26,    27,    -1,    64,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
       9,    10,    11,    12,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    26,    27,    -1,
      64,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,     9,    10,    11,    12,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    61,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,     9,    10,    11,    12,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    61,    26,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,     9,    10,
      11,    12,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    60,    61,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,     9,    10,    11,    12,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      61,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
       9,    10,    11,    12,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,    61,    26,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,     9,    10,    11,    12,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    61,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    61,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    -1,    -1,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,     9,    10,
      11,    12,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,     9,    10,    11,
      12,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    60,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,     9,    10,    11,    12,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    26,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    60,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,     4,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    72,    73,     4,     5,     6,     7,     8,    14,
      15,    19,    23,    24,    28,    30,    31,    43,    55,    62,
      63,    66,    67,    69,    76,    80,    83,    89,     0,    17,
      18,    74,    77,    78,    62,    60,    43,     4,    62,    76,
      63,    89,    89,    62,    76,    63,     1,     6,    63,    84,
      76,     1,    76,     4,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    62,    97,     1,     4,     7,    83,
       1,    68,    76,     1,     4,    62,    63,    83,    97,    98,
      99,     9,    10,    11,    12,    26,    27,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    60,    61,    76,     5,
      13,    66,    67,    79,    83,    79,    75,    76,    80,    74,
      61,    76,    76,    90,    91,    85,    62,    65,    63,    20,
      13,    13,    76,    29,     4,     4,    86,    64,    64,    76,
       1,    60,    68,    68,    50,    65,    70,    65,    76,     4,
      97,    65,    65,    70,    50,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      60,    63,    67,    69,    92,    93,    67,    83,     1,    65,
      68,    76,    13,    75,    61,    61,    64,    86,     4,    63,
      81,    82,    76,    64,     1,    76,    92,    92,    61,     1,
      76,    49,    44,    45,    47,    64,     1,    98,    55,    88,
      89,    88,    64,    65,    88,    88,    98,     4,    93,    94,
       1,     4,    62,    63,    83,    95,    96,    97,    42,    49,
      76,    60,    68,    76,    60,    65,    68,     4,    63,    91,
      47,     4,    97,    61,    64,    61,     4,    21,    22,    25,
      87,    62,    62,    76,    76,    76,    88,    49,    65,    88,
      50,    68,    65,    65,    76,     4,    65,    50,    70,    65,
      93,    76,    68,    68,    68,    76,    60,     4,    82,    65,
      65,    76,    76,    76,    76,    61,    64,    46,    88,    88,
      93,    93,    93,    64,    65,    93,    96,    93,    60,    60,
      60,    68,    76,    76,    25,    20,    61,    61,    76,    65,
      93,    60,    61,    61,    76,    76,    76,    64,    93,    76,
      87,    64,    61,    64,    76,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    78,    78,    78,    79,
      80,    80,    81,    81,    82,    82,    82,    84,    83,    85,
      83,    86,    86,    86,    87,    87,    88,    88,    88,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    91,    92,    92,    93,    93,    93,    94,
      94,    95,    95,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    98,    98,    98,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     0,     3,     0,     2,     0,     2,
       2,     9,     5,     9,    11,     9,     5,     5,     4,     6,
       8,     4,     2,     4,     5,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     4,     2,     3,     5,     4,     2,     1,
       5,     8,     1,     3,     2,     2,     1,     0,     4,     0,
       5,     0,     2,     4,     5,     3,     3,     2,     1,     1,
       1,     3,     2,     2,     3,     2,     4,     3,     2,     1,
       3,     2,     2,     3,     5,     4,     6,     5,     4,     3,
       7,     6,     6,     6,     5,     5,     1,     1,     1,     3,
       3,     2,     3,     2,     2,     1,     4,     3,     3,     4,
       3,     1,     3,     1,     3,     1,     2,     3,     3,     1,
       3,     1,     3,     2,     4,     3,     3,     3,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     3,     3,     3,     3,     3,     1,     4,     2,
       2,     1,     1,     5,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, answer, errors, locations, lexer_param_ptr, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, answer, errors, locations, lexer_param_ptr); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, block* answer, int* errors, struct locfile* locations, struct lexer_param* lexer_param_ptr)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (answer);
  YYUSE (errors);
  YYUSE (locations);
  YYUSE (lexer_param_ptr);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, block* answer, int* errors, struct locfile* locations, struct lexer_param* lexer_param_ptr)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, answer, errors, locations, lexer_param_ptr);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, block* answer, int* errors, struct locfile* locations, struct lexer_param* lexer_param_ptr)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), answer, errors, locations, lexer_param_ptr);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, answer, errors, locations, lexer_param_ptr); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, block* answer, int* errors, struct locfile* locations, struct lexer_param* lexer_param_ptr)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (answer);
  YYUSE (errors);
  YYUSE (locations);
  YYUSE (lexer_param_ptr);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_IDENT: /* IDENT  */
#line 36 "src/parser.y"
            { jv_free(((*yyvaluep).literal)); }
#line 2258 "src/parser.c"
        break;

    case YYSYMBOL_FIELD: /* FIELD  */
#line 36 "src/parser.y"
            { jv_free(((*yyvaluep).literal)); }
#line 2264 "src/parser.c"
        break;

    case YYSYMBOL_LITERAL: /* LITERAL  */
#line 36 "src/parser.y"
            { jv_free(((*yyvaluep).literal)); }
#line 2270 "src/parser.c"
        break;

    case YYSYMBOL_FORMAT: /* FORMAT  */
#line 36 "src/parser.y"
            { jv_free(((*yyvaluep).literal)); }
#line 2276 "src/parser.c"
        break;

    case YYSYMBOL_QQSTRING_TEXT: /* QQSTRING_TEXT  */
#line 36 "src/parser.y"
            { jv_free(((*yyvaluep).literal)); }
#line 2282 "src/parser.c"
        break;

    case YYSYMBOL_Module: /* Module  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2288 "src/parser.c"
        break;

    case YYSYMBOL_Imports: /* Imports  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2294 "src/parser.c"
        break;

    case YYSYMBOL_FuncDefs: /* FuncDefs  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2300 "src/parser.c"
        break;

    case YYSYMBOL_Exp: /* Exp  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2306 "src/parser.c"
        break;

    case YYSYMBOL_Import: /* Import  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2312 "src/parser.c"
        break;

    case YYSYMBOL_ImportWhat: /* ImportWhat  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2318 "src/parser.c"
        break;

    case YYSYMBOL_ImportFrom: /* ImportFrom  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2324 "src/parser.c"
        break;

    case YYSYMBOL_FuncDef: /* FuncDef  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2330 "src/parser.c"
        break;

    case YYSYMBOL_Params: /* Params  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2336 "src/parser.c"
        break;

    case YYSYMBOL_Param: /* Param  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2342 "src/parser.c"
        break;

    case YYSYMBOL_String: /* String  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2348 "src/parser.c"
        break;

    case YYSYMBOL_QQString: /* QQString  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2354 "src/parser.c"
        break;

    case YYSYMBOL_ElseBody: /* ElseBody  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2360 "src/parser.c"
        break;

    case YYSYMBOL_ExpD: /* ExpD  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2366 "src/parser.c"
        break;

    case YYSYMBOL_Term: /* Term  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2372 "src/parser.c"
        break;

    case YYSYMBOL_Args: /* Args  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2378 "src/parser.c"
        break;

    case YYSYMBOL_Arg: /* Arg  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2384 "src/parser.c"
        break;

    case YYSYMBOL_Patterns: /* Patterns  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2390 "src/parser.c"
        break;

    case YYSYMBOL_Pattern: /* Pattern  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2396 "src/parser.c"
        break;

    case YYSYMBOL_ArrayPats: /* ArrayPats  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2402 "src/parser.c"
        break;

    case YYSYMBOL_ObjPats: /* ObjPats  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2408 "src/parser.c"
        break;

    case YYSYMBOL_ObjPat: /* ObjPat  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2414 "src/parser.c"
        break;

    case YYSYMBOL_Keyword: /* Keyword  */
#line 36 "src/parser.y"
            { jv_free(((*yyvaluep).literal)); }
#line 2420 "src/parser.c"
        break;

    case YYSYMBOL_MkDict: /* MkDict  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2426 "src/parser.c"
        break;

    case YYSYMBOL_MkDictPair: /* MkDictPair  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2432 "src/parser.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (block* answer, int* errors, struct locfile* locations, struct lexer_param* lexer_param_ptr)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, answer, errors, locations, lexer_param_ptr);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* TopLevel: Module Imports Exp  */
#line 309 "src/parser.y"
                   {  

  // it looks pretty when the boilerplate code calls to @main
  // but it's counter-productive: the call introduces an unneded frame

  // block main = gen_function("@main", gen_noop(), $3);
  // block call_main = block_bind_referenced(
  //   main,
  //   gen_location(@$, locations, gen_call("@main", gen_noop())),
  //   OP_IS_CALL_PSEUDO);

  block main_loop = BLOCK (
    gen_op_simple(START),
    (yyvsp[0].blk), // call_main
    gen_op_simple(OUT)
  );

  *answer = BLOCK((yyvsp[-2].blk), (yyvsp[-1].blk), gen_marker(TOP), main_loop);
}
#line 2754 "src/parser.c"
    break;

  case 3: /* TopLevel: Module Imports FuncDefs  */
#line 328 "src/parser.y"
                        {
  *answer = BLOCK((yyvsp[-2].blk), (yyvsp[-1].blk), (yyvsp[0].blk));
}
#line 2762 "src/parser.c"
    break;

  case 4: /* Module: %empty  */
#line 333 "src/parser.y"
       {
  (yyval.blk) = gen_noop();
}
#line 2770 "src/parser.c"
    break;

  case 5: /* Module: "module" Exp ';'  */
#line 336 "src/parser.y"
                 {
  if (!block_is_const((yyvsp[-1].blk))) {
    FAIL((yyloc), "Module metadata must be constant");
    (yyval.blk) = gen_noop();
    block_free((yyvsp[-1].blk));
  } else {
    (yyval.blk) = gen_module((yyvsp[-1].blk));
  }
}
#line 2784 "src/parser.c"
    break;

  case 6: /* Imports: %empty  */
#line 347 "src/parser.y"
       {
  (yyval.blk) = gen_noop();
}
#line 2792 "src/parser.c"
    break;

  case 7: /* Imports: Import Imports  */
#line 350 "src/parser.y"
               {
  (yyval.blk) = BLOCK((yyvsp[-1].blk), (yyvsp[0].blk));
}
#line 2800 "src/parser.c"
    break;

  case 8: /* FuncDefs: %empty  */
#line 355 "src/parser.y"
       {
  (yyval.blk) = gen_noop();
}
#line 2808 "src/parser.c"
    break;

  case 9: /* FuncDefs: FuncDef FuncDefs  */
#line 358 "src/parser.y"
                 {
  (yyval.blk) = block_join((yyvsp[-1].blk), (yyvsp[0].blk));
}
#line 2816 "src/parser.c"
    break;

  case 10: /* Exp: FuncDef Exp  */
#line 363 "src/parser.y"
                          {
  (yyval.blk) = block_bind_referenced((yyvsp[-1].blk), (yyvsp[0].blk), OP_IS_CALL_PSEUDO);
}
#line 2824 "src/parser.c"
    break;

  case 11: /* Exp: "codef" '(' '$' ')' IDENT ':' Exp ';' Exp  */
#line 367 "src/parser.y"
                                                        {
  /* coexp(body) */
  block coexp = gen_call("coexp", gen_lambda((yyvsp[-2].blk)));
  /* as $IDENT | */
  block covar = gen_op_var_fresh(STOREV, jv_string_value((yyvsp[-4].literal)));
  /* def IDENT: $IDENT | fhread; */
  block codef = gen_function(
    jv_string_value((yyvsp[-4].literal)), 
    gen_noop(), 
    BLOCK(
      gen_op_unbound(LOADV, jv_string_value((yyvsp[-4].literal))), 
      gen_call("fhread", gen_noop())
    )
  );

  /* Now bind $9 so it sees the codef */
  block b = block_bind_referenced(codef, (yyvsp[0].blk), OP_IS_CALL_PSEUDO | OP_HAS_BINDING);
  
  /* Now bind that so it sees the variable $IDENT */
  b = block_bind_referenced(covar, b, OP_HAS_VARIABLE);

  /* Now do the rest of the binding for a $IDENT | Exp */
  covar = block_take_block(&b);
  (yyval.blk) = BLOCK(gen_const(jv_null()), gen_destructure(coexp, covar, b));
  jv_free((yyvsp[-4].literal));
}
#line 2855 "src/parser.c"
    break;

  case 12: /* Exp: Term "as" Patterns '|' Exp  */
#line 394 "src/parser.y"
                           {
  (yyval.blk) = gen_destructure((yyvsp[-4].blk), (yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 2863 "src/parser.c"
    break;

  case 13: /* Exp: "reduce" Term "as" Patterns '(' Exp ';' Exp ')'  */
#line 397 "src/parser.y"
                                                {
  (yyval.blk) = gen_reduce((yyvsp[-7].blk), (yyvsp[-5].blk), (yyvsp[-3].blk), (yyvsp[-1].blk));
}
#line 2871 "src/parser.c"
    break;

  case 14: /* Exp: "foreach" Term "as" Patterns '(' Exp ';' Exp ';' Exp ')'  */
#line 401 "src/parser.y"
                                                         {
  (yyval.blk) = gen_foreach((yyvsp[-9].blk), (yyvsp[-7].blk), (yyvsp[-5].blk), (yyvsp[-3].blk), (yyvsp[-1].blk));
}
#line 2879 "src/parser.c"
    break;

  case 15: /* Exp: "foreach" Term "as" Patterns '(' Exp ';' Exp ')'  */
#line 405 "src/parser.y"
                                                 {
  (yyval.blk) = gen_foreach((yyvsp[-7].blk), (yyvsp[-5].blk), (yyvsp[-3].blk), (yyvsp[-1].blk), gen_noop());
}
#line 2887 "src/parser.c"
    break;

  case 16: /* Exp: "if" Exp "then" Exp ElseBody  */
#line 409 "src/parser.y"
                             {
  (yyval.blk) = gen_cond((yyvsp[-3].blk), (yyvsp[-1].blk), (yyvsp[0].blk));
}
#line 2895 "src/parser.c"
    break;

  case 17: /* Exp: "if" Exp "then" Exp "end"  */
#line 412 "src/parser.y"
                          {
  (yyval.blk) = gen_cond((yyvsp[-3].blk), (yyvsp[-1].blk), gen_noop());
}
#line 2903 "src/parser.c"
    break;

  case 18: /* Exp: "if" Exp "then" error  */
#line 415 "src/parser.y"
                      {
  FAIL((yyloc), "Possibly unterminated 'if' statement");
  (yyval.blk) = (yyvsp[-2].blk);
}
#line 2912 "src/parser.c"
    break;

  case 19: /* Exp: "try" '(' Exp ';' Exp ')'  */
#line 420 "src/parser.y"
                          {
  (yyval.blk) = gen_try((yyvsp[-3].blk), (yyvsp[-1].blk));
}
#line 2920 "src/parser.c"
    break;

  case 20: /* Exp: "try" '(' Exp ';' Exp ';' Exp ')'  */
#line 423 "src/parser.y"
                                  {
  (yyval.blk) = BLOCK(gen_call("_try_finally", BLOCK(gen_lambda((yyvsp[-5].blk)), gen_lambda((yyvsp[-3].blk)), gen_lambda((yyvsp[-1].blk)))));
}
#line 2928 "src/parser.c"
    break;

  case 21: /* Exp: "try" Exp "catch" Exp  */
#line 426 "src/parser.y"
                      {
  (yyval.blk) = gen_try((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 2936 "src/parser.c"
    break;

  case 22: /* Exp: "try" Exp  */
#line 429 "src/parser.y"
          {
  (yyval.blk) = gen_try((yyvsp[0].blk), gen_op_simple(BACKTRACK_0));
}
#line 2944 "src/parser.c"
    break;

  case 23: /* Exp: "try" Exp "catch" error  */
#line 432 "src/parser.y"
                        {
  FAIL((yyloc), "Possibly unterminated 'try' statement");
  (yyval.blk) = (yyvsp[-2].blk);
}
#line 2953 "src/parser.c"
    break;

  case 24: /* Exp: "label" '$' IDENT '|' Exp  */
#line 437 "src/parser.y"
                          {
  jv v = jv_string_fmt("*label-%s", jv_string_value((yyvsp[-2].literal)));
  (yyval.blk) = gen_location((yyloc), locations, gen_label(jv_string_value(v), (yyvsp[0].blk)));
  jv_free((yyvsp[-2].literal));
  jv_free(v);
}
#line 2964 "src/parser.c"
    break;

  case 25: /* Exp: Exp '?'  */
#line 444 "src/parser.y"
        {
  (yyval.blk) = gen_try((yyvsp[-1].blk), gen_op_simple(BACKTRACK_0));
}
#line 2972 "src/parser.c"
    break;

  case 26: /* Exp: Exp '=' Exp  */
#line 448 "src/parser.y"
            {
  (yyval.blk) = gen_call("_assign", BLOCK(gen_lambda((yyvsp[-2].blk)), gen_lambda((yyvsp[0].blk))));
}
#line 2980 "src/parser.c"
    break;

  case 27: /* Exp: Exp "or" Exp  */
#line 452 "src/parser.y"
             {
  (yyval.blk) = gen_or((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 2988 "src/parser.c"
    break;

  case 28: /* Exp: Exp "and" Exp  */
#line 456 "src/parser.y"
              {
  (yyval.blk) = gen_and((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 2996 "src/parser.c"
    break;

  case 29: /* Exp: Exp "//" Exp  */
#line 460 "src/parser.y"
             {
  (yyval.blk) = gen_definedor((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3004 "src/parser.c"
    break;

  case 30: /* Exp: Exp "//=" Exp  */
#line 464 "src/parser.y"
              {
  (yyval.blk) = gen_definedor_assign((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3012 "src/parser.c"
    break;

  case 31: /* Exp: Exp "|=" Exp  */
#line 468 "src/parser.y"
             {
  (yyval.blk) = gen_call("_modify", BLOCK(gen_lambda((yyvsp[-2].blk)), gen_lambda((yyvsp[0].blk))));
}
#line 3020 "src/parser.c"
    break;

  case 32: /* Exp: Exp '|' Exp  */
#line 472 "src/parser.y"
            {
  (yyval.blk) = block_join((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3028 "src/parser.c"
    break;

  case 33: /* Exp: Exp ">|" Exp  */
#line 476 "src/parser.y"
             {
  (yyval.blk) = block_join((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3036 "src/parser.c"
    break;

  case 34: /* Exp: Exp ',' Exp  */
#line 480 "src/parser.y"
            {
  (yyval.blk) = gen_both((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3044 "src/parser.c"
    break;

  case 35: /* Exp: Exp '+' Exp  */
#line 484 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '+');
}
#line 3052 "src/parser.c"
    break;

  case 36: /* Exp: Exp "+=" Exp  */
#line 488 "src/parser.y"
             {
  (yyval.blk) = gen_update((yyvsp[-2].blk), (yyvsp[0].blk), '+');
}
#line 3060 "src/parser.c"
    break;

  case 37: /* Exp: '-' Exp  */
#line 492 "src/parser.y"
        {
  (yyval.blk) = BLOCK((yyvsp[0].blk), gen_call("_negate", gen_noop()));
}
#line 3068 "src/parser.c"
    break;

  case 38: /* Exp: Exp '-' Exp  */
#line 496 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '-');
}
#line 3076 "src/parser.c"
    break;

  case 39: /* Exp: Exp "-=" Exp  */
#line 500 "src/parser.y"
             {
  (yyval.blk) = gen_update((yyvsp[-2].blk), (yyvsp[0].blk), '-');
}
#line 3084 "src/parser.c"
    break;

  case 40: /* Exp: Exp '*' Exp  */
#line 504 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '*');
}
#line 3092 "src/parser.c"
    break;

  case 41: /* Exp: Exp "*=" Exp  */
#line 508 "src/parser.y"
             {
  (yyval.blk) = gen_update((yyvsp[-2].blk), (yyvsp[0].blk), '*');
}
#line 3100 "src/parser.c"
    break;

  case 42: /* Exp: Exp '/' Exp  */
#line 512 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '/');
  if (block_is_const_inf((yyval.blk)))
    FAIL((yyloc), "Division by zero?");
}
#line 3110 "src/parser.c"
    break;

  case 43: /* Exp: Exp '%' Exp  */
#line 518 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '%');
  if (block_is_const_inf((yyval.blk)))
    FAIL((yyloc), "Remainder by zero?");
}
#line 3120 "src/parser.c"
    break;

  case 44: /* Exp: Exp "/=" Exp  */
#line 524 "src/parser.y"
             {
  (yyval.blk) = gen_update((yyvsp[-2].blk), (yyvsp[0].blk), '/');
}
#line 3128 "src/parser.c"
    break;

  case 45: /* Exp: Exp "%=" Exp  */
#line 528 "src/parser.y"
               {
  (yyval.blk) = gen_update((yyvsp[-2].blk), (yyvsp[0].blk), '%');
}
#line 3136 "src/parser.c"
    break;

  case 46: /* Exp: Exp "==" Exp  */
#line 532 "src/parser.y"
             {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), EQ);
}
#line 3144 "src/parser.c"
    break;

  case 47: /* Exp: Exp "!=" Exp  */
#line 536 "src/parser.y"
             {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), NEQ);
}
#line 3152 "src/parser.c"
    break;

  case 48: /* Exp: Exp '<' Exp  */
#line 540 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '<');
}
#line 3160 "src/parser.c"
    break;

  case 49: /* Exp: Exp '>' Exp  */
#line 544 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '>');
}
#line 3168 "src/parser.c"
    break;

  case 50: /* Exp: Exp "<=" Exp  */
#line 548 "src/parser.y"
             {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), LESSEQ);
}
#line 3176 "src/parser.c"
    break;

  case 51: /* Exp: Exp ">=" Exp  */
#line 552 "src/parser.y"
             {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), GREATEREQ);
}
#line 3184 "src/parser.c"
    break;

  case 52: /* Exp: Term  */
#line 556 "src/parser.y"
     {
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3192 "src/parser.c"
    break;

  case 53: /* Exp: '$' '(' Exp ')'  */
#line 560 "src/parser.y"
                {
  (yyval.blk) = gen_coexpression((yyvsp[-1].blk));
}
#line 3200 "src/parser.c"
    break;

  case 54: /* Import: ImportWhat ';'  */
#line 565 "src/parser.y"
               {
  (yyval.blk) = (yyvsp[-1].blk);
}
#line 3208 "src/parser.c"
    break;

  case 55: /* Import: ImportWhat Exp ';'  */
#line 568 "src/parser.y"
                   {
  if (!block_is_const((yyvsp[-1].blk))) {
    FAIL((yyloc), "Module metadata must be constant");
    (yyval.blk) = gen_noop();
    block_free((yyvsp[-2].blk));
    block_free((yyvsp[-1].blk));
  } else if (block_const_kind((yyvsp[-1].blk)) != JV_KIND_OBJECT) {
    FAIL((yyloc), "Module metadata must be an object");
    (yyval.blk) = gen_noop();
    block_free((yyvsp[-2].blk));
    block_free((yyvsp[-1].blk));
  } else {
    (yyval.blk) = gen_import_meta((yyvsp[-2].blk), (yyvsp[-1].blk));
  }
}
#line 3228 "src/parser.c"
    break;

  case 56: /* ImportWhat: "import" ImportFrom "as" '$' IDENT  */
#line 585 "src/parser.y"
                                   {
  jv v = block_const((yyvsp[-3].blk));
  // XXX Make gen_import take only blocks and the int is_data so we
  // don't have to free so much stuff here
  (yyval.blk) = gen_import(jv_string_value(v), jv_string_value((yyvsp[0].literal)), 1);
  block_free((yyvsp[-3].blk));
  jv_free((yyvsp[0].literal));
  jv_free(v);
}
#line 3242 "src/parser.c"
    break;

  case 57: /* ImportWhat: "import" ImportFrom "as" IDENT  */
#line 594 "src/parser.y"
                               {
  jv v = block_const((yyvsp[-2].blk));
  (yyval.blk) = gen_import(jv_string_value(v), jv_string_value((yyvsp[0].literal)), 0);
  block_free((yyvsp[-2].blk));
  jv_free((yyvsp[0].literal));
  jv_free(v);
}
#line 3254 "src/parser.c"
    break;

  case 58: /* ImportWhat: "include" ImportFrom  */
#line 601 "src/parser.y"
                     {
  jv v = block_const((yyvsp[0].blk));
  (yyval.blk) = gen_import(jv_string_value(v), NULL, 0);
  block_free((yyvsp[0].blk));
  jv_free(v);
}
#line 3265 "src/parser.c"
    break;

  case 59: /* ImportFrom: String  */
#line 609 "src/parser.y"
       {
  if (!block_is_const((yyvsp[0].blk))) {
    FAIL((yyloc), "Import path must be constant");
    (yyval.blk) = gen_const(jv_string(""));
    block_free((yyvsp[0].blk));
  } else {
    (yyval.blk) = (yyvsp[0].blk);
  }
}
#line 3279 "src/parser.c"
    break;

  case 60: /* FuncDef: "def" IDENT ':' Exp ';'  */
#line 620 "src/parser.y"
                        {
  (yyval.blk) = gen_function(jv_string_value((yyvsp[-3].literal)), gen_noop(), (yyvsp[-1].blk));
  jv_free((yyvsp[-3].literal));
}
#line 3288 "src/parser.c"
    break;

  case 61: /* FuncDef: "def" IDENT '(' Params ')' ':' Exp ';'  */
#line 625 "src/parser.y"
                                       {
  (yyval.blk) = gen_function(jv_string_value((yyvsp[-6].literal)), (yyvsp[-4].blk), (yyvsp[-1].blk));
  jv_free((yyvsp[-6].literal));
}
#line 3297 "src/parser.c"
    break;

  case 62: /* Params: Param  */
#line 631 "src/parser.y"
      {
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3305 "src/parser.c"
    break;

  case 63: /* Params: Params ';' Param  */
#line 634 "src/parser.y"
                 {
  (yyval.blk) = BLOCK((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3313 "src/parser.c"
    break;

  case 64: /* Param: '$' IDENT  */
#line 639 "src/parser.y"
          {
  (yyval.blk) = gen_param_regular(jv_string_value((yyvsp[0].literal)));
  jv_free((yyvsp[0].literal));
}
#line 3322 "src/parser.c"
    break;

  case 65: /* Param: '$' Keyword  */
#line 643 "src/parser.y"
            {
  (yyval.blk) = gen_param_regular(jv_string_value((yyvsp[0].literal)));
  jv_free((yyvsp[0].literal));
}
#line 3331 "src/parser.c"
    break;

  case 66: /* Param: IDENT  */
#line 651 "src/parser.y"
      {
  (yyval.blk) = gen_param(jv_string_value((yyvsp[0].literal)));
  jv_free((yyvsp[0].literal));
}
#line 3340 "src/parser.c"
    break;

  case 67: /* @1: %empty  */
#line 658 "src/parser.y"
               { (yyval.literal) = jv_string("text"); }
#line 3346 "src/parser.c"
    break;

  case 68: /* String: QQSTRING_START @1 QQString QQSTRING_END  */
#line 658 "src/parser.y"
                                                                          {
  (yyval.blk) = (yyvsp[-1].blk);
  jv_free((yyvsp[-2].literal));
}
#line 3355 "src/parser.c"
    break;

  case 69: /* @2: %empty  */
#line 662 "src/parser.y"
                      { (yyval.literal) = (yyvsp[-1].literal); }
#line 3361 "src/parser.c"
    break;

  case 70: /* String: FORMAT QQSTRING_START @2 QQString QQSTRING_END  */
#line 662 "src/parser.y"
                                                                  {
  (yyval.blk) = (yyvsp[-1].blk);
  jv_free((yyvsp[-2].literal));
}
#line 3370 "src/parser.c"
    break;

  case 71: /* QQString: %empty  */
#line 669 "src/parser.y"
       {
  (yyval.blk) = gen_const(jv_string(""));
}
#line 3378 "src/parser.c"
    break;

  case 72: /* QQString: QQString QQSTRING_TEXT  */
#line 672 "src/parser.y"
                       {
  (yyval.blk) = gen_binop((yyvsp[-1].blk), gen_const((yyvsp[0].literal)), '+');
}
#line 3386 "src/parser.c"
    break;

  case 73: /* QQString: QQString QQSTRING_INTERP_START Exp QQSTRING_INTERP_END  */
#line 675 "src/parser.y"
                                                       {
  (yyval.blk) = gen_binop((yyvsp[-3].blk), gen_format((yyvsp[-1].blk), jv_copy((yyvsp[-4].literal))), '+');
}
#line 3394 "src/parser.c"
    break;

  case 74: /* ElseBody: "elif" Exp "then" Exp ElseBody  */
#line 681 "src/parser.y"
                               {
  (yyval.blk) = gen_cond((yyvsp[-3].blk), (yyvsp[-1].blk), (yyvsp[0].blk));
}
#line 3402 "src/parser.c"
    break;

  case 75: /* ElseBody: "else" Exp "end"  */
#line 684 "src/parser.y"
                 {
  (yyval.blk) = (yyvsp[-1].blk);
}
#line 3410 "src/parser.c"
    break;

  case 76: /* ExpD: ExpD '|' ExpD  */
#line 689 "src/parser.y"
              {
  (yyval.blk) = block_join((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3418 "src/parser.c"
    break;

  case 77: /* ExpD: '-' ExpD  */
#line 692 "src/parser.y"
         {
  (yyval.blk) = BLOCK((yyvsp[0].blk), gen_call("_negate", gen_noop()));
}
#line 3426 "src/parser.c"
    break;

  case 78: /* ExpD: Term  */
#line 695 "src/parser.y"
     {
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3434 "src/parser.c"
    break;

  case 79: /* Term: '.'  */
#line 701 "src/parser.y"
    {
  (yyval.blk) = gen_noop();
}
#line 3442 "src/parser.c"
    break;

  case 80: /* Term: ".."  */
#line 704 "src/parser.y"
    {
  (yyval.blk) = gen_call("recurse", gen_noop());
}
#line 3450 "src/parser.c"
    break;

  case 81: /* Term: "break" '$' IDENT  */
#line 707 "src/parser.y"
                {
  jv v = jv_string_fmt("*label-%s", jv_string_value((yyvsp[0].literal)));     // impossible symbol
  (yyval.blk) = gen_location((yyloc), locations,
                    gen_op_unbound(BACKTRACK_PC, jv_string_value(v)));
  jv_free(v);
  jv_free((yyvsp[0].literal));
}
#line 3462 "src/parser.c"
    break;

  case 82: /* Term: "break" error  */
#line 714 "src/parser.y"
            {
  FAIL((yyloc), "break requires a label to break to");
  (yyval.blk) = gen_noop();
}
#line 3471 "src/parser.c"
    break;

  case 83: /* Term: "break" LITERAL  */
#line 718 "src/parser.y"
              {
  (yyval.blk) = gen_op_const(BACKTRACK_N, (yyvsp[0].literal));
}
#line 3479 "src/parser.c"
    break;

  case 84: /* Term: Term FIELD '?'  */
#line 721 "src/parser.y"
               {
  (yyval.blk) = gen_index_opt((yyvsp[-2].blk), gen_const((yyvsp[-1].literal)));
}
#line 3487 "src/parser.c"
    break;

  case 85: /* Term: FIELD '?'  */
#line 724 "src/parser.y"
          {
  (yyval.blk) = gen_index_opt(gen_noop(), gen_const((yyvsp[-1].literal)));
}
#line 3495 "src/parser.c"
    break;

  case 86: /* Term: Term '.' String '?'  */
#line 727 "src/parser.y"
                    {
  (yyval.blk) = gen_index_opt((yyvsp[-3].blk), (yyvsp[-1].blk));
}
#line 3503 "src/parser.c"
    break;

  case 87: /* Term: '.' String '?'  */
#line 730 "src/parser.y"
               {
  (yyval.blk) = gen_index_opt(gen_noop(), (yyvsp[-1].blk));
}
#line 3511 "src/parser.c"
    break;

  case 88: /* Term: Term FIELD  */
#line 733 "src/parser.y"
                        {
  (yyval.blk) = gen_index((yyvsp[-1].blk), gen_const((yyvsp[0].literal)));
}
#line 3519 "src/parser.c"
    break;

  case 89: /* Term: FIELD  */
#line 736 "src/parser.y"
                   {
  (yyval.blk) = gen_index(gen_noop(), gen_const((yyvsp[0].literal)));
}
#line 3527 "src/parser.c"
    break;

  case 90: /* Term: Term '.' String  */
#line 739 "src/parser.y"
                             {
  (yyval.blk) = gen_index((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3535 "src/parser.c"
    break;

  case 91: /* Term: '.' String  */
#line 742 "src/parser.y"
                        {
  (yyval.blk) = gen_index(gen_noop(), (yyvsp[0].blk));
}
#line 3543 "src/parser.c"
    break;

  case 92: /* Term: '.' error  */
#line 745 "src/parser.y"
          {
  FAIL((yyloc), "try .[\"field\"] instead of .field for unusually named fields");
  (yyval.blk) = gen_noop();
}
#line 3552 "src/parser.c"
    break;

  case 93: /* Term: '.' IDENT error  */
#line 749 "src/parser.y"
                {
  jv_free((yyvsp[-1].literal));
  FAIL((yyloc), "try .[\"field\"] instead of .field for unusually named fields");
  (yyval.blk) = gen_noop();
}
#line 3562 "src/parser.c"
    break;

  case 94: /* Term: Term '[' Exp ']' '?'  */
#line 755 "src/parser.y"
                     {
  (yyval.blk) = gen_index_opt((yyvsp[-4].blk), (yyvsp[-2].blk));
}
#line 3570 "src/parser.c"
    break;

  case 95: /* Term: Term '[' Exp ']'  */
#line 758 "src/parser.y"
                              {
  (yyval.blk) = gen_index((yyvsp[-3].blk), (yyvsp[-1].blk));
}
#line 3578 "src/parser.c"
    break;

  case 96: /* Term: Term '.' '[' Exp ']' '?'  */
#line 761 "src/parser.y"
                         {
  (yyval.blk) = gen_index_opt((yyvsp[-5].blk), (yyvsp[-2].blk));
}
#line 3586 "src/parser.c"
    break;

  case 97: /* Term: Term '.' '[' Exp ']'  */
#line 764 "src/parser.y"
                                  {
  (yyval.blk) = gen_index((yyvsp[-4].blk), (yyvsp[-1].blk));
}
#line 3594 "src/parser.c"
    break;

  case 98: /* Term: Term '[' ']' '?'  */
#line 767 "src/parser.y"
                 {
  (yyval.blk) = block_join((yyvsp[-3].blk), gen_op_simple(EACH_OPT));
}
#line 3602 "src/parser.c"
    break;

  case 99: /* Term: Term '[' ']'  */
#line 770 "src/parser.y"
                          {
  (yyval.blk) = block_join((yyvsp[-2].blk), gen_op_simple(EACH));
}
#line 3610 "src/parser.c"
    break;

  case 100: /* Term: Term '[' Exp ':' Exp ']' '?'  */
#line 773 "src/parser.y"
                             {
  (yyval.blk) = gen_slice_index((yyvsp[-6].blk), (yyvsp[-4].blk), (yyvsp[-2].blk), INDEX_OPT);
}
#line 3618 "src/parser.c"
    break;

  case 101: /* Term: Term '[' Exp ':' ']' '?'  */
#line 776 "src/parser.y"
                         {
  (yyval.blk) = gen_slice_index((yyvsp[-5].blk), (yyvsp[-3].blk), gen_const(jv_null()), INDEX_OPT);
}
#line 3626 "src/parser.c"
    break;

  case 102: /* Term: Term '[' ':' Exp ']' '?'  */
#line 779 "src/parser.y"
                         {
  (yyval.blk) = gen_slice_index((yyvsp[-5].blk), gen_const(jv_null()), (yyvsp[-2].blk), INDEX_OPT);
}
#line 3634 "src/parser.c"
    break;

  case 103: /* Term: Term '[' Exp ':' Exp ']'  */
#line 782 "src/parser.y"
                                      {
  (yyval.blk) = gen_slice_index((yyvsp[-5].blk), (yyvsp[-3].blk), (yyvsp[-1].blk), INDEX);
}
#line 3642 "src/parser.c"
    break;

  case 104: /* Term: Term '[' Exp ':' ']'  */
#line 785 "src/parser.y"
                                  {
  (yyval.blk) = gen_slice_index((yyvsp[-4].blk), (yyvsp[-2].blk), gen_const(jv_null()), INDEX);
}
#line 3650 "src/parser.c"
    break;

  case 105: /* Term: Term '[' ':' Exp ']'  */
#line 788 "src/parser.y"
                                  {
  (yyval.blk) = gen_slice_index((yyvsp[-4].blk), gen_const(jv_null()), (yyvsp[-1].blk), INDEX);
}
#line 3658 "src/parser.c"
    break;

  case 106: /* Term: LITERAL  */
#line 791 "src/parser.y"
        {
  (yyval.blk) = gen_const((yyvsp[0].literal));
}
#line 3666 "src/parser.c"
    break;

  case 107: /* Term: String  */
#line 794 "src/parser.y"
       {
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3674 "src/parser.c"
    break;

  case 108: /* Term: FORMAT  */
#line 797 "src/parser.y"
       {
  (yyval.blk) = gen_format(gen_noop(), (yyvsp[0].literal));
}
#line 3682 "src/parser.c"
    break;

  case 109: /* Term: '(' Exp ')'  */
#line 800 "src/parser.y"
            {
  (yyval.blk) = (yyvsp[-1].blk);
}
#line 3690 "src/parser.c"
    break;

  case 110: /* Term: '[' Exp ']'  */
#line 803 "src/parser.y"
            {
  (yyval.blk) = gen_collect((yyvsp[-1].blk));
}
#line 3698 "src/parser.c"
    break;

  case 111: /* Term: '[' ']'  */
#line 806 "src/parser.y"
        {
  (yyval.blk) = gen_const(jv_array());
}
#line 3706 "src/parser.c"
    break;

  case 112: /* Term: '{' MkDict '}'  */
#line 809 "src/parser.y"
               {
  block o = gen_const_object((yyvsp[-1].blk));
  if (o.first != NULL)
    (yyval.blk) = o;
  else
    (yyval.blk) = BLOCK(gen_subexp(gen_const(jv_object())), (yyvsp[-1].blk), gen_op_simple(POP));
}
#line 3718 "src/parser.c"
    break;

  case 113: /* Term: '$' IDENT  */
#line 816 "src/parser.y"
          {
  (yyval.blk) = gen_location((yyloc), locations, gen_op_unbound(LOADV, jv_string_value((yyvsp[0].literal))));
  jv_free((yyvsp[0].literal));
}
#line 3727 "src/parser.c"
    break;

  case 114: /* Term: '$' Keyword  */
#line 820 "src/parser.y"
            {
  if (strcmp(jv_string_value((yyvsp[0].literal)), "__loc__") == 0) {
    (yyval.blk) = gen_const(JV_OBJECT(jv_string("file"), jv_copy(locations->fname),
                             jv_string("line"), jv_number(locfile_get_line(locations, (yyloc).start) + 1)));
  } else {
    (yyval.blk) = gen_location((yyloc), locations, gen_op_unbound(LOADV, jv_string_value((yyvsp[0].literal))));
  }
  jv_free((yyvsp[0].literal));
}
#line 3741 "src/parser.c"
    break;

  case 115: /* Term: IDENT  */
#line 829 "src/parser.y"
      {
  const char *s = jv_string_value((yyvsp[0].literal));
  if (strcmp(s, "false") == 0)
    (yyval.blk) = gen_const(jv_false());
  else if (strcmp(s, "true") == 0)
    (yyval.blk) = gen_const(jv_true());
  else if (strcmp(s, "null") == 0)
    (yyval.blk) = gen_const(jv_null());
  else
    (yyval.blk) = gen_location((yyloc), locations, gen_call(s, gen_noop()));
  jv_free((yyvsp[0].literal));
}
#line 3758 "src/parser.c"
    break;

  case 116: /* Term: IDENT '(' Args ')'  */
#line 841 "src/parser.y"
                   {
  (yyval.blk) = gen_call(jv_string_value((yyvsp[-3].literal)), (yyvsp[-1].blk));
  (yyval.blk) = gen_location((yylsp[-3]), locations, (yyval.blk));
  jv_free((yyvsp[-3].literal));
}
#line 3768 "src/parser.c"
    break;

  case 117: /* Term: '(' error ')'  */
#line 846 "src/parser.y"
              { (yyval.blk) = gen_noop(); }
#line 3774 "src/parser.c"
    break;

  case 118: /* Term: '[' error ']'  */
#line 847 "src/parser.y"
              { (yyval.blk) = gen_noop(); }
#line 3780 "src/parser.c"
    break;

  case 119: /* Term: Term '[' error ']'  */
#line 848 "src/parser.y"
                   { (yyval.blk) = (yyvsp[-3].blk); }
#line 3786 "src/parser.c"
    break;

  case 120: /* Term: '{' error '}'  */
#line 849 "src/parser.y"
              { (yyval.blk) = gen_noop(); }
#line 3792 "src/parser.c"
    break;

  case 121: /* Args: Arg  */
#line 852 "src/parser.y"
    {
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3800 "src/parser.c"
    break;

  case 122: /* Args: Args ';' Arg  */
#line 855 "src/parser.y"
             {
  (yyval.blk) = BLOCK((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3808 "src/parser.c"
    break;

  case 123: /* Arg: Exp  */
#line 860 "src/parser.y"
    {
  (yyval.blk) = gen_lambda((yyvsp[0].blk));
}
#line 3816 "src/parser.c"
    break;

  case 124: /* Patterns: Patterns "?//" Pattern  */
#line 865 "src/parser.y"
                       {
  (yyval.blk) = BLOCK((yyvsp[-2].blk), gen_destructure_alt((yyvsp[0].blk)));
}
#line 3824 "src/parser.c"
    break;

  case 125: /* Patterns: Pattern  */
#line 868 "src/parser.y"
        {
  (yyval.blk) = gen_destructure_alt((yyvsp[0].blk));
}
#line 3832 "src/parser.c"
    break;

  case 126: /* Pattern: '$' IDENT  */
#line 873 "src/parser.y"
          {
  (yyval.blk) = gen_op_unbound(STOREV, jv_string_value((yyvsp[0].literal)));
  jv_free((yyvsp[0].literal));
}
#line 3841 "src/parser.c"
    break;

  case 127: /* Pattern: '[' ArrayPats ']'  */
#line 877 "src/parser.y"
                  {
  (yyval.blk) = BLOCK((yyvsp[-1].blk), gen_op_simple(POP));
}
#line 3849 "src/parser.c"
    break;

  case 128: /* Pattern: '{' ObjPats '}'  */
#line 880 "src/parser.y"
                {
  (yyval.blk) = BLOCK((yyvsp[-1].blk), gen_op_simple(POP));
}
#line 3857 "src/parser.c"
    break;

  case 129: /* ArrayPats: Pattern  */
#line 885 "src/parser.y"
        {
  (yyval.blk) = gen_array_matcher(gen_noop(), (yyvsp[0].blk));
}
#line 3865 "src/parser.c"
    break;

  case 130: /* ArrayPats: ArrayPats ',' Pattern  */
#line 888 "src/parser.y"
                      {
  (yyval.blk) = gen_array_matcher((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3873 "src/parser.c"
    break;

  case 131: /* ObjPats: ObjPat  */
#line 893 "src/parser.y"
       {
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3881 "src/parser.c"
    break;

  case 132: /* ObjPats: ObjPats ',' ObjPat  */
#line 896 "src/parser.y"
                   {
  (yyval.blk) = BLOCK((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3889 "src/parser.c"
    break;

  case 133: /* ObjPat: '$' IDENT  */
#line 901 "src/parser.y"
          {
  (yyval.blk) = gen_object_matcher(gen_const((yyvsp[0].literal)), gen_op_unbound(STOREV, jv_string_value((yyvsp[0].literal))));
}
#line 3897 "src/parser.c"
    break;

  case 134: /* ObjPat: '$' IDENT ':' Pattern  */
#line 904 "src/parser.y"
                      {
  (yyval.blk) = gen_object_matcher(gen_const((yyvsp[-2].literal)), BLOCK(gen_op_simple(DUP), gen_op_unbound(STOREV, jv_string_value((yyvsp[-2].literal))), (yyvsp[0].blk)));
}
#line 3905 "src/parser.c"
    break;

  case 135: /* ObjPat: IDENT ':' Pattern  */
#line 907 "src/parser.y"
                  {
  (yyval.blk) = gen_object_matcher(gen_const((yyvsp[-2].literal)), (yyvsp[0].blk));
}
#line 3913 "src/parser.c"
    break;

  case 136: /* ObjPat: Keyword ':' Pattern  */
#line 910 "src/parser.y"
                    {
  (yyval.blk) = gen_object_matcher(gen_const((yyvsp[-2].literal)), (yyvsp[0].blk));
}
#line 3921 "src/parser.c"
    break;

  case 137: /* ObjPat: String ':' Pattern  */
#line 913 "src/parser.y"
                   {
  (yyval.blk) = gen_object_matcher((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3929 "src/parser.c"
    break;

  case 138: /* ObjPat: '(' Exp ')' ':' Pattern  */
#line 916 "src/parser.y"
                        {
  jv msg = check_object_key((yyvsp[-3].blk));
  if (jv_is_valid(msg)) {
    FAIL((yyloc), jv_string_value(msg));
  }
  jv_free(msg);
  (yyval.blk) = gen_object_matcher((yyvsp[-3].blk), (yyvsp[0].blk));
}
#line 3942 "src/parser.c"
    break;

  case 139: /* ObjPat: error ':' Pattern  */
#line 924 "src/parser.y"
                  {
  FAIL((yyloc), "May need parentheses around object key expression");
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3951 "src/parser.c"
    break;

  case 140: /* Keyword: "as"  */
#line 930 "src/parser.y"
     {
  (yyval.literal) = jv_string("as");
}
#line 3959 "src/parser.c"
    break;

  case 141: /* Keyword: "def"  */
#line 933 "src/parser.y"
      {
  (yyval.literal) = jv_string("def");
}
#line 3967 "src/parser.c"
    break;

  case 142: /* Keyword: "codef"  */
#line 936 "src/parser.y"
        {
  (yyval.literal) = jv_string("codef");
}
#line 3975 "src/parser.c"
    break;

  case 143: /* Keyword: "module"  */
#line 939 "src/parser.y"
         {
  (yyval.literal) = jv_string("module");
}
#line 3983 "src/parser.c"
    break;

  case 144: /* Keyword: "import"  */
#line 942 "src/parser.y"
         {
  (yyval.literal) = jv_string("import");
}
#line 3991 "src/parser.c"
    break;

  case 145: /* Keyword: "include"  */
#line 945 "src/parser.y"
          {
  (yyval.literal) = jv_string("include");
}
#line 3999 "src/parser.c"
    break;

  case 146: /* Keyword: "if"  */
#line 948 "src/parser.y"
     {
  (yyval.literal) = jv_string("if");
}
#line 4007 "src/parser.c"
    break;

  case 147: /* Keyword: "then"  */
#line 951 "src/parser.y"
       {
  (yyval.literal) = jv_string("then");
}
#line 4015 "src/parser.c"
    break;

  case 148: /* Keyword: "else"  */
#line 954 "src/parser.y"
       {
  (yyval.literal) = jv_string("else");
}
#line 4023 "src/parser.c"
    break;

  case 149: /* Keyword: "elif"  */
#line 957 "src/parser.y"
       {
  (yyval.literal) = jv_string("elif");
}
#line 4031 "src/parser.c"
    break;

  case 150: /* Keyword: "reduce"  */
#line 960 "src/parser.y"
         {
  (yyval.literal) = jv_string("reduce");
}
#line 4039 "src/parser.c"
    break;

  case 151: /* Keyword: "foreach"  */
#line 963 "src/parser.y"
          {
  (yyval.literal) = jv_string("foreach");
}
#line 4047 "src/parser.c"
    break;

  case 152: /* Keyword: "end"  */
#line 966 "src/parser.y"
      {
  (yyval.literal) = jv_string("end");
}
#line 4055 "src/parser.c"
    break;

  case 153: /* Keyword: "and"  */
#line 969 "src/parser.y"
      {
  (yyval.literal) = jv_string("and");
}
#line 4063 "src/parser.c"
    break;

  case 154: /* Keyword: "or"  */
#line 972 "src/parser.y"
     {
  (yyval.literal) = jv_string("or");
}
#line 4071 "src/parser.c"
    break;

  case 155: /* Keyword: "try"  */
#line 975 "src/parser.y"
      {
  (yyval.literal) = jv_string("try");
}
#line 4079 "src/parser.c"
    break;

  case 156: /* Keyword: "catch"  */
#line 978 "src/parser.y"
        {
  (yyval.literal) = jv_string("catch");
}
#line 4087 "src/parser.c"
    break;

  case 157: /* Keyword: "label"  */
#line 981 "src/parser.y"
        {
  (yyval.literal) = jv_string("label");
}
#line 4095 "src/parser.c"
    break;

  case 158: /* Keyword: "break"  */
#line 984 "src/parser.y"
        {
  (yyval.literal) = jv_string("break");
}
#line 4103 "src/parser.c"
    break;

  case 159: /* Keyword: "__loc__"  */
#line 987 "src/parser.y"
          {
  (yyval.literal) = jv_string("__loc__");
}
#line 4111 "src/parser.c"
    break;

  case 160: /* MkDict: %empty  */
#line 992 "src/parser.y"
       {
  (yyval.blk)=gen_noop();
}
#line 4119 "src/parser.c"
    break;

  case 161: /* MkDict: MkDictPair  */
#line 995 "src/parser.y"
            { (yyval.blk) = (yyvsp[0].blk); }
#line 4125 "src/parser.c"
    break;

  case 162: /* MkDict: MkDictPair ',' MkDict  */
#line 996 "src/parser.y"
                        { (yyval.blk)=block_join((yyvsp[-2].blk), (yyvsp[0].blk)); }
#line 4131 "src/parser.c"
    break;

  case 163: /* MkDict: error ',' MkDict  */
#line 997 "src/parser.y"
                   { (yyval.blk) = (yyvsp[0].blk); }
#line 4137 "src/parser.c"
    break;

  case 164: /* MkDictPair: IDENT ':' ExpD  */
#line 1000 "src/parser.y"
               {
  (yyval.blk) = gen_dictpair(gen_const((yyvsp[-2].literal)), (yyvsp[0].blk));
 }
#line 4145 "src/parser.c"
    break;

  case 165: /* MkDictPair: Keyword ':' ExpD  */
#line 1003 "src/parser.y"
                   {
  (yyval.blk) = gen_dictpair(gen_const((yyvsp[-2].literal)), (yyvsp[0].blk));
  }
#line 4153 "src/parser.c"
    break;

  case 166: /* MkDictPair: String ':' ExpD  */
#line 1006 "src/parser.y"
                  {
  (yyval.blk) = gen_dictpair((yyvsp[-2].blk), (yyvsp[0].blk));
  }
#line 4161 "src/parser.c"
    break;

  case 167: /* MkDictPair: String  */
#line 1009 "src/parser.y"
         {
  (yyval.blk) = gen_dictpair((yyvsp[0].blk), BLOCK(gen_op_simple(POP), gen_op_simple(DUP2),
                              gen_op_simple(DUP2), gen_op_simple(INDEX)));
  }
#line 4170 "src/parser.c"
    break;

  case 168: /* MkDictPair: '$' IDENT ':' ExpD  */
#line 1013 "src/parser.y"
                     {
  (yyval.blk) = gen_dictpair(gen_location((yyloc), locations, gen_op_unbound(LOADV, jv_string_value((yyvsp[-2].literal)))),
                    (yyvsp[0].blk));
  }
#line 4179 "src/parser.c"
    break;

  case 169: /* MkDictPair: '$' IDENT  */
#line 1017 "src/parser.y"
            {
  (yyval.blk) = gen_dictpair(gen_const((yyvsp[0].literal)),
                    gen_location((yyloc), locations, gen_op_unbound(LOADV, jv_string_value((yyvsp[0].literal)))));
  }
#line 4188 "src/parser.c"
    break;

  case 170: /* MkDictPair: '$' Keyword  */
#line 1021 "src/parser.y"
              {
  (yyval.blk) = gen_dictpair(gen_const((yyvsp[0].literal)),
                    gen_location((yyloc), locations, gen_op_unbound(LOADV, jv_string_value((yyvsp[0].literal)))));
  }
#line 4197 "src/parser.c"
    break;

  case 171: /* MkDictPair: IDENT  */
#line 1025 "src/parser.y"
        {
  (yyval.blk) = gen_dictpair(gen_const(jv_copy((yyvsp[0].literal))),
                    gen_index(gen_noop(), gen_const((yyvsp[0].literal))));
  }
#line 4206 "src/parser.c"
    break;

  case 172: /* MkDictPair: Keyword  */
#line 1029 "src/parser.y"
          {
  (yyval.blk) = gen_dictpair(gen_const(jv_copy((yyvsp[0].literal))),
                    gen_index(gen_noop(), gen_const((yyvsp[0].literal))));
  }
#line 4215 "src/parser.c"
    break;

  case 173: /* MkDictPair: '(' Exp ')' ':' ExpD  */
#line 1033 "src/parser.y"
                       {
  jv msg = check_object_key((yyvsp[-3].blk));
  if (jv_is_valid(msg)) {
    FAIL((yyloc), jv_string_value(msg));
  }
  jv_free(msg);
  (yyval.blk) = gen_dictpair((yyvsp[-3].blk), (yyvsp[0].blk));
  }
#line 4228 "src/parser.c"
    break;

  case 174: /* MkDictPair: error ':' ExpD  */
#line 1041 "src/parser.y"
                 {
  FAIL((yyloc), "May need parentheses around object key expression");
  (yyval.blk) = (yyvsp[0].blk);
  }
#line 4237 "src/parser.c"
    break;


#line 4241 "src/parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, answer, errors, locations, lexer_param_ptr, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, answer, errors, locations, lexer_param_ptr);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, answer, errors, locations, lexer_param_ptr);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, answer, errors, locations, lexer_param_ptr, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, answer, errors, locations, lexer_param_ptr);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, answer, errors, locations, lexer_param_ptr);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1045 "src/parser.y"


int jq_parse(struct locfile* locations, block* answer) {
  struct lexer_param scanner;
  YY_BUFFER_STATE buf;
  jq_yylex_init_extra(0, &scanner.lexer);
  buf = jq_yy_scan_bytes(locations->data, locations->length, scanner.lexer);
  int errors = 0;
  *answer = gen_noop();
  yyparse(answer, &errors, locations, &scanner);
  jq_yy_delete_buffer(buf, scanner.lexer);
  jq_yylex_destroy(scanner.lexer);
  if (errors > 0) {
    block_free(*answer);
    *answer = gen_noop();
  }
  return errors;
}

int jq_parse_library(struct locfile* locations, block* answer) {
  int errs = jq_parse(locations, answer);
  if (errs) return errs;
  if (block_has_main(*answer)) {
    locfile_locate(locations, UNKNOWN_LOCATION, "jq: error: library should only have function definitions, not a main expression");
    return 1;
  }
  assert(block_has_only_binders_and_imports(*answer, OP_IS_CALL_PSEUDO));
  return 0;
}
