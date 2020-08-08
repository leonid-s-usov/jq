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
  YYSYMBOL_63_ = 63,                       /* ')'  */
  YYSYMBOL_64_ = 64,                       /* '$'  */
  YYSYMBOL_65_ = 65,                       /* '@'  */
  YYSYMBOL_66_ = 66,                       /* ':'  */
  YYSYMBOL_67_ = 67,                       /* '.'  */
  YYSYMBOL_68_ = 68,                       /* '['  */
  YYSYMBOL_69_ = 69,                       /* ']'  */
  YYSYMBOL_70_ = 70,                       /* '{'  */
  YYSYMBOL_71_ = 71,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 72,                  /* $accept  */
  YYSYMBOL_TopLevel = 73,                  /* TopLevel  */
  YYSYMBOL_Module = 74,                    /* Module  */
  YYSYMBOL_Imports = 75,                   /* Imports  */
  YYSYMBOL_FuncDefs = 76,                  /* FuncDefs  */
  YYSYMBOL_Exp = 77,                       /* Exp  */
  YYSYMBOL_HandleMethodSpec = 78,          /* HandleMethodSpec  */
  YYSYMBOL_HandleRefSpec = 79,             /* HandleRefSpec  */
  YYSYMBOL_Break = 80,                     /* Break  */
  YYSYMBOL_Import = 81,                    /* Import  */
  YYSYMBOL_ImportWhat = 82,                /* ImportWhat  */
  YYSYMBOL_ImportFrom = 83,                /* ImportFrom  */
  YYSYMBOL_FuncDef = 84,                   /* FuncDef  */
  YYSYMBOL_Params = 85,                    /* Params  */
  YYSYMBOL_Param = 86,                     /* Param  */
  YYSYMBOL_String = 87,                    /* String  */
  YYSYMBOL_88_1 = 88,                      /* @1  */
  YYSYMBOL_89_2 = 89,                      /* @2  */
  YYSYMBOL_QQString = 90,                  /* QQString  */
  YYSYMBOL_ElseBody = 91,                  /* ElseBody  */
  YYSYMBOL_ExpD = 92,                      /* ExpD  */
  YYSYMBOL_Term = 93,                      /* Term  */
  YYSYMBOL_Args = 94,                      /* Args  */
  YYSYMBOL_Arg = 95,                       /* Arg  */
  YYSYMBOL_Patterns = 96,                  /* Patterns  */
  YYSYMBOL_Pattern = 97,                   /* Pattern  */
  YYSYMBOL_ArrayPats = 98,                 /* ArrayPats  */
  YYSYMBOL_ObjPats = 99,                   /* ObjPats  */
  YYSYMBOL_ObjPat = 100,                   /* ObjPat  */
  YYSYMBOL_Keyword = 101,                  /* Keyword  */
  YYSYMBOL_MkDict = 102,                   /* MkDict  */
  YYSYMBOL_MkDictPair = 103                /* MkDictPair  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 130 "src/parser.y"

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


#line 576 "src/parser.c"


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
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2500

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  180
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  347

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
       2,     2,     2,     2,     2,     2,    64,    58,     2,     2,
      62,    63,    56,    54,    50,    55,    67,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    61,
      52,    51,    53,    60,    65,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    49,    71,     2,     2,     2,     2,
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
       0,   312,   312,   331,   336,   339,   350,   353,   358,   361,
     366,   397,   400,   404,   408,   412,   415,   418,   423,   426,
     429,   432,   435,   440,   447,   451,   455,   459,   463,   467,
     471,   475,   479,   483,   487,   491,   495,   499,   503,   507,
     511,   515,   521,   527,   531,   535,   539,   543,   547,   551,
     555,   559,   563,   567,   573,   576,   579,   585,   589,   594,
     597,   600,   607,   613,   616,   633,   642,   649,   657,   668,
     673,   679,   682,   687,   691,   695,   702,   702,   706,   706,
     713,   716,   719,   725,   728,   733,   736,   739,   745,   748,
     751,   754,   757,   760,   763,   766,   769,   772,   775,   779,
     785,   788,   791,   794,   797,   800,   803,   806,   809,   812,
     815,   818,   821,   824,   831,   834,   837,   840,   847,   851,
     860,   872,   878,   882,   883,   884,   885,   888,   891,   896,
     901,   904,   909,   913,   916,   921,   924,   929,   932,   937,
     940,   943,   946,   949,   952,   960,   966,   969,   972,   975,
     978,   981,   984,   987,   990,   993,   996,   999,  1002,  1005,
    1008,  1011,  1014,  1017,  1020,  1023,  1028,  1031,  1032,  1033,
    1036,  1039,  1042,  1045,  1049,  1053,  1057,  1061,  1065,  1069,
    1077
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
  "'%'", "NONOPT", "'?'", "';'", "'('", "')'", "'$'", "'@'", "':'", "'.'",
  "'['", "']'", "'{'", "'}'", "$accept", "TopLevel", "Module", "Imports",
  "FuncDefs", "Exp", "HandleMethodSpec", "HandleRefSpec", "Break",
  "Import", "ImportWhat", "ImportFrom", "FuncDef", "Params", "Param",
  "String", "@1", "@2", "QQString", "ElseBody", "ExpD", "Term", "Args",
  "Arg", "Patterns", "Pattern", "ArrayPats", "ObjPats", "ObjPat",
  "Keyword", "MkDict", "MkDictPair", YY_NULLPTR
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
      63,    59,    40,    41,    36,    64,    58,    46,    91,    93,
     123,   125
};
#endif

#define YYPACT_NINF (-169)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-167)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,   819,    46,   138,    -2,    11,  -169,    12,  -169,    85,
     819,   229,   229,   871,    19,   485,  -169,   819,   579,  1234,
     310,   551,   379,  1744,    51,  -169,   819,  -169,    -3,  -169,
       4,     4,   711,   138,   739,   819,  -169,  -169,   -24,  2081,
      65,   579,     9,    68,   579,   111,   130,  -169,  -169,   141,
    -169,    -6,    90,  1429,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,   819,  -169,  -169,   156,    82,
      92,  -169,  1021,   -18,    96,   819,  2439,   100,   101,   103,
     121,   819,   819,   819,   819,   819,   819,   819,   819,   819,
     819,   819,   819,   819,   819,   819,   819,   819,   819,   819,
     819,   819,   819,   819,   819,   819,  -169,  -169,     0,  2255,
     112,   -29,     1,   199,   160,  -169,  -169,  -169,  2255,   711,
    -169,  -169,  1780,  2255,     5,  -169,  -169,     3,   819,   631,
    1464,   -29,   -29,  1264,   659,   126,  -169,   102,  -169,   113,
    1499,  -169,  -169,  -169,  -169,   438,   125,  -169,   125,  1534,
     110,  -169,   125,   125,  -169,   438,  2325,   380,   380,  2290,
    2384,  2358,   144,  2325,  2325,  2325,  2325,  2325,  2325,   380,
     380,  2255,  2290,  2325,   380,   380,    -6,    -6,    -4,    -4,
      -4,  -169,   819,  -169,  -169,   175,   -29,   930,    79,  -169,
     819,   122,   114,   819,   124,   969,    22,  -169,  -169,   819,
    -169,   107,  -169,  2468,    78,  -169,  1816,  -169,  1977,  -169,
      16,    17,   819,  -169,   144,   819,  -169,   819,  -169,  -169,
      -5,  -169,   125,   136,    20,   136,   120,   125,   136,   136,
    -169,  1569,  -169,  -169,   -20,   128,   132,   819,   184,   135,
     -14,  -169,   143,   -29,   819,  1073,  -169,  -169,  1125,  -169,
     791,   150,  -169,   192,  -169,  -169,  -169,  -169,     3,   145,
    -169,   819,   819,  -169,  -169,   819,   819,  1319,  2255,  2116,
    -169,   125,   125,   136,  -169,   -29,  -169,   -29,   -29,  1604,
     146,   -29,   930,  -169,   -29,  -169,  2255,   154,   155,   157,
    1177,  -169,  -169,  -169,   819,  2168,  2220,  1852,  1888,   819,
    -169,  -169,   136,   136,  -169,  -169,  -169,   153,   -29,  -169,
    -169,  -169,  -169,  -169,  -169,   165,  1924,  -169,   819,   819,
     819,  1639,   -29,  -169,  -169,  -169,  2029,  1674,  1374,  -169,
    -169,  -169,  -169,   819,  -169,  1709,  -169
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    54,     0,     6,   120,    95,   112,     0,    89,     0,
      54,     0,     0,    54,     0,     0,    76,    54,     0,     0,
       0,     0,     0,     0,     0,    53,    54,   113,    51,     1,
       0,     0,     8,     6,    54,    54,    91,    78,     0,     0,
     120,     0,     0,     0,     0,    21,     0,    62,    60,     0,
      80,    36,     0,     0,   118,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    54,   119,    98,     0,    97,
       0,   116,     0,     0,   177,    54,     0,   173,   178,     0,
     167,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    24,     5,     0,    10,
      94,     0,     0,     0,     0,    68,    67,     3,     2,     8,
       7,    63,     0,   129,     0,   127,    80,     0,    54,     0,
       0,     0,     0,     0,     0,     0,    61,     0,   123,   114,
       0,    99,    93,   124,   115,     0,     0,   126,     0,     0,
     175,   176,     0,     0,   117,     0,    44,    45,    46,    28,
      27,    26,    32,    30,    35,    38,    40,    43,    29,    49,
      50,    31,    33,    25,    47,    48,    34,    37,    39,    41,
      42,    57,    54,    52,    90,     0,     0,     0,     0,   131,
      54,    96,     0,    54,   105,     0,     0,     9,    64,    54,
     121,     0,    75,     0,     0,    71,     0,    17,     0,   114,
       0,     0,    54,    22,    20,    54,    81,    54,    77,   122,
       0,   169,     0,   180,    87,   170,     0,     0,   172,   171,
     168,     0,   132,   135,     0,     0,     0,    54,     0,     0,
       0,   137,     0,     0,    54,     0,    92,   125,     0,   104,
      54,   101,    66,     0,   128,    79,    73,    74,     0,     0,
      69,    54,    54,    16,    15,    54,    54,     0,    23,     0,
      86,     0,     0,   174,    58,     0,   133,     0,     0,     0,
     139,     0,     0,   134,     0,   130,    11,   103,   111,   110,
       0,   100,    65,    72,    54,     0,     0,     0,     0,    54,
      18,    82,    85,   179,   136,   145,   141,     0,     0,   143,
     138,   142,   102,   108,   107,   109,     0,    84,    54,    54,
      54,     0,     0,   140,   106,    70,     0,     0,     0,    19,
     144,    83,    12,    54,    14,     0,    13
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,  -169,   183,    91,    -1,  -169,  -169,  -169,  -169,
    -169,   197,   -11,  -169,   -37,    -7,  -169,  -169,   104,  -104,
    -157,     7,  -169,    29,    18,  -168,  -169,  -169,   -51,   -16,
     -83,  -169
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    32,   127,   119,    24,   193,    25,    33,
      34,   124,    26,   214,   215,    27,    50,   136,   147,   274,
     233,    28,   134,   135,   198,   199,   244,   250,   251,    88,
      89,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,   235,   120,    76,   191,   238,   239,   212,     7,    39,
     121,     7,    45,    79,   120,    87,    51,    53,    42,    43,
      82,   129,   141,   125,   125,   120,   262,    97,   243,    97,
     285,   128,   155,   132,   133,   195,   292,     1,   137,   196,
     140,   197,   138,   143,    16,   155,    29,    16,   156,   286,
     113,   114,   115,   157,   116,    37,   116,   293,   253,   253,
      35,   156,   192,   -55,   122,   123,   209,   213,   210,   200,
     161,    36,   231,   120,   150,   280,   122,   123,   275,   276,
     283,   142,   240,    46,   159,   295,   263,   122,   123,    38,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   201,   118,   314,   129,   315,
     316,   253,   205,   319,   312,   313,   321,    35,   254,    40,
       5,     6,     7,     8,   145,   122,   123,   216,   218,   268,
     144,   269,   152,   224,    97,   146,   226,   227,    87,   228,
     333,   226,   227,   148,   265,    30,    31,   151,    87,   220,
     221,   153,   158,   234,   340,   234,   162,   163,    16,   234,
     234,   165,   194,   206,   164,   225,   237,    97,   -56,   242,
     232,   252,   256,   257,   259,   281,   282,    41,   290,    19,
     249,   241,    20,    21,   287,    22,   302,   267,   288,   255,
     202,   291,   258,     4,     5,     6,     7,     8,   133,   294,
     301,   304,   318,     9,   322,   323,   130,   324,    10,   332,
     207,   277,    11,    12,   278,   334,   279,    13,   126,    14,
      15,   303,   341,    40,     5,     6,     7,     8,   264,   234,
     211,   320,    16,     0,   234,     0,   289,     0,     0,     0,
       0,     0,     0,   296,    17,     0,     0,     0,     0,   300,
       0,    18,     0,    19,   -54,   203,    20,    21,   204,    22,
     305,   306,    16,     0,   307,   308,   252,     0,     0,     0,
       0,     0,     0,     0,     0,   249,     0,     0,   234,   234,
       0,    41,     0,    19,     0,     0,    20,    21,     0,    22,
       0,     0,     0,   326,     0,     0,     0,     0,   331,     0,
     -88,    77,     0,     0,    78,   -88,     0,     7,     0,   -88,
     -88,   -88,   -88,   -88,     0,     0,     0,   336,   337,   338,
     -88,   -88,   -88,     0,     0,   -88,   -88,   -88,     0,   -88,
       0,     0,   345,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,     0,    16,     0,     0,   -88,     0,     0,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,     0,
     -88,   -88,     0,   -88,     0,     0,   -88,   -88,   -88,   -88,
      83,   -88,     0,    84,     0,     0,     7,     0,     0,     0,
    -167,  -167,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,    97,     0,     0,     0,     0,     0,     0,
    -167,  -167,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -167,  -167,   111,   112,   113,   114,   115,   230,
     116,    85,    84,    86,     0,     7,     0,     0,     0,     0,
    -166,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,     0,   -59,    47,     0,     0,     0,
       0,    48,     0,     0,   -59,   -59,   -59,   -59,     0,     0,
      85,     0,    86,     0,     0,   -59,   -59,   -59,     0,  -166,
     -59,   -59,   -59,     0,   -59,     0,     0,     0,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,     0,
       0,   -59,     0,     0,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,     0,   -59,   -59,     0,   -59,    49,
       0,   -59,    80,     0,   -59,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
      10,     0,     0,     0,    11,    12,     0,     0,     0,    13,
      52,    14,    15,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     9,    16,     0,     0,     0,    10,     0,
       0,     0,    11,    12,     0,     0,    17,    13,     0,    14,
      15,     0,     0,    18,     0,    19,   -54,     0,    20,    21,
      81,    22,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   217,     0,    17,     4,     5,     6,     7,     8,
       0,    18,     0,    19,   -54,     9,    20,    21,     0,    22,
      10,     0,     0,     0,    11,    12,     0,     0,     0,    13,
     223,    14,    15,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     9,    16,     0,     0,     0,    10,     0,
       0,     0,    11,    12,     0,     0,    17,    13,     0,    14,
      15,     0,     0,    18,     0,    19,   -54,     0,    20,    21,
       0,    22,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     4,     5,     6,     7,     8,
       0,    18,     0,    19,   -54,     9,    20,    21,     0,    22,
      10,     0,     0,     0,    11,    12,     0,     0,     0,    13,
       0,    14,    15,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     9,    16,     0,     0,     0,    10,     0,
       0,     0,    11,    12,     0,     0,    17,    13,     0,    14,
      15,     0,     0,    18,     0,    19,   -54,     0,    20,    21,
       0,    22,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     4,     5,     6,     7,     8,
     131,    18,     0,    19,     0,     9,    20,    21,     0,    22,
      10,     0,     0,     0,    11,    12,     0,     0,     0,    13,
       0,    14,    15,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     9,    16,     0,     0,     0,    10,     0,
       0,     0,    11,    12,     0,     0,    17,    13,     0,    14,
      15,     0,     0,    18,     0,    19,     0,     0,    20,    21,
     299,    22,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     4,     5,     6,     7,     8,
       0,    18,     0,    19,     0,     9,    20,    21,     0,    22,
      10,     0,     0,     0,    11,    12,     0,     0,     0,    13,
       0,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,   245,     0,    44,   246,    19,     0,     7,    20,    21,
       0,    22,     0,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,    91,    92,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,     0,   248,    95,    96,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
      91,    92,    93,    94,     0,   260,     0,     0,   261,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,    91,    92,    93,    94,     0,     0,     0,     0,
     154,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,   116,    91,    92,    93,    94,     0,     0,
       0,     0,   297,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,   116,    91,    92,    93,    94,
       0,     0,     0,     0,   298,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,   116,    54,     0,
       0,     0,     0,     0,     0,     0,   325,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,     0,     0,     0,     0,    75,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   222,     0,   149,    91,    92,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
     309,     0,   310,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   343,     0,   344,    91,    92,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,    91,    92,    93,    94,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
      95,    96,   149,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,    91,    92,
      93,    94,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,    95,    96,   219,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,    91,    92,    93,    94,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
      95,    96,   229,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,    91,    92,
      93,    94,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,    95,    96,   236,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,    91,    92,    93,    94,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
      95,    96,   284,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,    91,    92,
      93,    94,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,    95,    96,   317,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,    91,    92,    93,    94,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
      95,    96,   339,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,    91,    92,
      93,    94,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,    95,    96,   342,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,    91,    92,    93,    94,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
      95,    96,   346,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,    91,
      92,    93,    94,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   117,    95,    96,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,    91,    92,    93,    94,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     116,   208,    95,    96,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,    91,    92,    93,    94,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,   270,    95,    96,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,     0,     0,    91,    92,    93,
      94,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,   329,    95,    96,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,    91,    92,    93,    94,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,   330,
      95,    96,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   335,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   272,
       0,     0,   273,    95,    96,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,   116,    91,    92,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
     271,   272,     0,     0,     0,    95,    96,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
      91,    92,    93,    94,     0,     0,     0,     0,     0,     0,
       0,   139,     0,     0,     0,     0,     0,    95,    96,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,    91,    92,    93,    94,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,    95,    96,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,   311,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,    91,    92,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   327,    95,    96,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,    91,
      92,    93,    94,     0,     0,     0,     0,     0,     0,     0,
     328,     0,     0,     0,     0,     0,    95,    96,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,    91,    92,    93,    94,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     116,    95,    96,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,     0,    91,
      92,    93,    94,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,   116,    95,    96,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,  -167,    92,    93,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     116,    95,    96,     0,     0,     0,     0,     0,    97,  -167,
    -167,  -167,  -167,  -167,  -167,   104,   105,     0,    92,    93,
       0,     0,     0,     0,     0,     0,  -167,   109,   110,   111,
     112,   113,   114,   115,    95,   116,     0,     0,     0,     0,
       0,    97,     0,     0,    92,    93,     0,     0,   104,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,    97,   116,     0,
       0,     0,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   160,   116,     0,     0,     0,     0,     0,
       0,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   266,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74
};

static const yytype_int16 yycheck[] =
{
       1,   158,     5,    19,     4,   162,   163,     4,     7,    10,
      13,     7,    13,    20,     5,    22,    17,    18,    11,    12,
      21,    32,    13,    30,    31,     5,     4,    33,   196,    33,
      50,    32,    50,    34,    35,    64,    50,    16,    62,    68,
      41,    70,    66,    44,    43,    50,     0,    43,    66,    69,
      56,    57,    58,    71,    60,    43,    60,    71,    42,    42,
      62,    66,    62,    65,    67,    68,    61,    64,    63,    68,
      86,    60,   155,     5,    75,   232,    67,    68,    62,    62,
     237,    13,   165,    64,    85,   253,    64,    67,    68,     4,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   122,    65,   285,   129,   287,
     288,    42,   123,   291,   281,   282,   294,    62,    49,     4,
       5,     6,     7,     8,     4,    67,    68,   138,   139,    61,
      29,    63,    60,   144,    33,     4,    44,    45,   155,    47,
     318,    44,    45,    63,    47,    17,    18,     1,   165,   141,
     142,    69,    66,   156,   332,   158,    66,    66,    43,   162,
     163,    50,    60,    13,    71,    49,    66,    33,    65,     4,
      55,   197,    60,    69,    60,    49,    66,    62,     4,    64,
     197,   192,    67,    68,    66,    70,     4,   213,    66,   200,
       1,    66,   203,     4,     5,     6,     7,     8,   209,    66,
      60,    66,    66,    14,    60,    60,    33,    60,    19,    66,
     129,   222,    23,    24,   225,    60,   227,    28,    31,    30,
      31,   268,   336,     4,     5,     6,     7,     8,   209,   232,
     136,   292,    43,    -1,   237,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,   254,    55,    -1,    -1,    -1,    -1,   260,
      -1,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
     271,   272,    43,    -1,   275,   276,   292,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   292,    -1,    -1,   281,   282,
      -1,    62,    -1,    64,    -1,    -1,    67,    68,    -1,    70,
      -1,    -1,    -1,   304,    -1,    -1,    -1,    -1,   309,    -1,
       0,     1,    -1,    -1,     4,     5,    -1,     7,    -1,     9,
      10,    11,    12,    13,    -1,    -1,    -1,   328,   329,   330,
      20,    21,    22,    -1,    -1,    25,    26,    27,    -1,    29,
      -1,    -1,   343,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    -1,    63,    -1,    -1,    66,    67,    68,    69,
       1,    71,    -1,     4,    -1,    -1,     7,    -1,    -1,    -1,
      10,    11,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,     1,
      60,    62,     4,    64,    -1,     7,    -1,    -1,    -1,    -1,
      71,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,     0,     1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,     9,    10,    11,    12,    -1,    -1,
      62,    -1,    64,    -1,    -1,    20,    21,    22,    -1,    71,
      25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,    61,    -1,    63,    64,
      -1,    66,     1,    -1,    69,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,
       1,    30,    31,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    14,    43,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    23,    24,    -1,    -1,    55,    28,    -1,    30,
      31,    -1,    -1,    62,    -1,    64,    65,    -1,    67,    68,
      69,    70,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,    55,     4,     5,     6,     7,     8,
      -1,    62,    -1,    64,    65,    14,    67,    68,    -1,    70,
      19,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,
       1,    30,    31,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    14,    43,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    23,    24,    -1,    -1,    55,    28,    -1,    30,
      31,    -1,    -1,    62,    -1,    64,    65,    -1,    67,    68,
      -1,    70,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,     4,     5,     6,     7,     8,
      -1,    62,    -1,    64,    65,    14,    67,    68,    -1,    70,
      19,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,
      -1,    30,    31,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    14,    43,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    23,    24,    -1,    -1,    55,    28,    -1,    30,
      31,    -1,    -1,    62,    -1,    64,    65,    -1,    67,    68,
      -1,    70,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,     4,     5,     6,     7,     8,
      61,    62,    -1,    64,    -1,    14,    67,    68,    -1,    70,
      19,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,
      -1,    30,    31,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    14,    43,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    23,    24,    -1,    -1,    55,    28,    -1,    30,
      31,    -1,    -1,    62,    -1,    64,    -1,    -1,    67,    68,
      69,    70,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,     4,     5,     6,     7,     8,
      -1,    62,    -1,    64,    -1,    14,    67,    68,    -1,    70,
      19,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,     1,    -1,    62,     4,    64,    -1,     7,    67,    68,
      -1,    70,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    64,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
       9,    10,    11,    12,    -1,    66,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    60,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    -1,    -1,    -1,    -1,    62,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    -1,    63,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      61,    -1,    63,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    -1,    63,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,     9,    10,    11,    12,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      26,    27,    63,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,     9,    10,
      11,    12,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    26,    27,    63,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,     9,    10,    11,    12,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      26,    27,    63,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,     9,    10,
      11,    12,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    26,    27,    63,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,     9,    10,    11,    12,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      26,    27,    63,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,     9,    10,
      11,    12,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    26,    27,    63,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,     9,    10,    11,    12,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      26,    27,    63,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,     9,    10,
      11,    12,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    26,    27,    63,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,     9,    10,    11,    12,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      26,    27,    63,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,     9,
      10,    11,    12,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    26,    27,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,     9,    10,    11,    12,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,     9,    10,    11,    12,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,     9,    10,    11,
      12,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,     9,    10,    11,    12,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    -1,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,     9,    10,    11,    12,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,     9,    10,    11,    12,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,     9,
      10,    11,    12,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,    26,    27,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    26,    60,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    10,    11,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    33,    60,    -1,
      -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,     4,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    73,    74,     4,     5,     6,     7,     8,    14,
      19,    23,    24,    28,    30,    31,    43,    55,    62,    64,
      67,    68,    70,    77,    78,    80,    84,    87,    93,     0,
      17,    18,    75,    81,    82,    62,    60,    43,     4,    77,
       4,    62,    93,    93,    62,    77,    64,     1,     6,    64,
      88,    77,     1,    77,     4,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    62,   101,     1,     4,    87,
       1,    69,    77,     1,     4,    62,    64,    87,   101,   102,
     103,     9,    10,    11,    12,    26,    27,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    60,    61,    65,    77,
       5,    13,    67,    68,    83,    87,    83,    76,    77,    84,
      75,    61,    77,    77,    94,    95,    89,    62,    66,    20,
      77,    13,    13,    77,    29,     4,     4,    90,    63,    63,
      77,     1,    60,    69,    69,    50,    66,    71,    66,    77,
       4,   101,    66,    66,    71,    50,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,     4,    62,    79,    60,    64,    68,    70,    96,    97,
      68,    87,     1,    66,    69,    77,    13,    76,    61,    61,
      63,    90,     4,    64,    85,    86,    77,     1,    77,    63,
      96,    96,    61,     1,    77,    49,    44,    45,    47,    63,
       1,   102,    55,    92,    93,    92,    63,    66,    92,    92,
     102,    77,     4,    97,    98,     1,     4,    62,    64,    87,
      99,   100,   101,    42,    49,    77,    60,    69,    77,    60,
      66,    69,     4,    64,    95,    47,     4,   101,    61,    63,
      61,    21,    22,    25,    91,    62,    62,    77,    77,    77,
      92,    49,    66,    92,    63,    50,    69,    66,    66,    77,
       4,    66,    50,    71,    66,    97,    77,    69,    69,    69,
      77,    60,     4,    86,    66,    77,    77,    77,    77,    61,
      63,    46,    92,    92,    97,    97,    97,    63,    66,    97,
     100,    97,    60,    60,    60,    69,    77,    25,    20,    61,
      61,    77,    66,    97,    60,    61,    77,    77,    77,    63,
      97,    91,    63,    61,    63,    77,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    80,
      80,    80,    80,    81,    81,    82,    82,    82,    83,    84,
      84,    85,    85,    86,    86,    86,    88,    87,    89,    87,
      90,    90,    90,    91,    91,    92,    92,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    94,    94,    95,
      96,    96,    97,    97,    97,    98,    98,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   102,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     0,     3,     0,     2,     0,     2,
       2,     5,     9,    11,     9,     5,     5,     4,     6,     8,
       4,     2,     4,     5,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     0,     1,     3,     1,     3,     1,
       2,     3,     2,     2,     3,     5,     4,     2,     1,     5,
       8,     1,     3,     2,     2,     1,     0,     4,     0,     5,
       0,     2,     4,     5,     3,     3,     2,     1,     1,     1,
       3,     2,     4,     3,     2,     1,     3,     2,     2,     3,
       5,     4,     6,     5,     4,     3,     7,     6,     6,     6,
       5,     5,     1,     1,     3,     3,     2,     3,     2,     2,
       1,     4,     4,     3,     3,     4,     3,     1,     3,     1,
       3,     1,     2,     3,     3,     1,     3,     1,     3,     2,
       4,     3,     3,     3,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     3,     3,
       3,     3,     3,     1,     4,     2,     2,     1,     1,     5,
       3
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
#line 2292 "src/parser.c"
        break;

    case YYSYMBOL_FIELD: /* FIELD  */
#line 36 "src/parser.y"
            { jv_free(((*yyvaluep).literal)); }
#line 2298 "src/parser.c"
        break;

    case YYSYMBOL_LITERAL: /* LITERAL  */
#line 36 "src/parser.y"
            { jv_free(((*yyvaluep).literal)); }
#line 2304 "src/parser.c"
        break;

    case YYSYMBOL_FORMAT: /* FORMAT  */
#line 36 "src/parser.y"
            { jv_free(((*yyvaluep).literal)); }
#line 2310 "src/parser.c"
        break;

    case YYSYMBOL_QQSTRING_TEXT: /* QQSTRING_TEXT  */
#line 36 "src/parser.y"
            { jv_free(((*yyvaluep).literal)); }
#line 2316 "src/parser.c"
        break;

    case YYSYMBOL_Module: /* Module  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2322 "src/parser.c"
        break;

    case YYSYMBOL_Imports: /* Imports  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2328 "src/parser.c"
        break;

    case YYSYMBOL_FuncDefs: /* FuncDefs  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2334 "src/parser.c"
        break;

    case YYSYMBOL_Exp: /* Exp  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2340 "src/parser.c"
        break;

    case YYSYMBOL_HandleMethodSpec: /* HandleMethodSpec  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2346 "src/parser.c"
        break;

    case YYSYMBOL_HandleRefSpec: /* HandleRefSpec  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2352 "src/parser.c"
        break;

    case YYSYMBOL_Break: /* Break  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2358 "src/parser.c"
        break;

    case YYSYMBOL_Import: /* Import  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2364 "src/parser.c"
        break;

    case YYSYMBOL_ImportWhat: /* ImportWhat  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2370 "src/parser.c"
        break;

    case YYSYMBOL_ImportFrom: /* ImportFrom  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2376 "src/parser.c"
        break;

    case YYSYMBOL_FuncDef: /* FuncDef  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2382 "src/parser.c"
        break;

    case YYSYMBOL_Params: /* Params  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2388 "src/parser.c"
        break;

    case YYSYMBOL_Param: /* Param  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2394 "src/parser.c"
        break;

    case YYSYMBOL_String: /* String  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2400 "src/parser.c"
        break;

    case YYSYMBOL_QQString: /* QQString  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2406 "src/parser.c"
        break;

    case YYSYMBOL_ElseBody: /* ElseBody  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2412 "src/parser.c"
        break;

    case YYSYMBOL_ExpD: /* ExpD  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2418 "src/parser.c"
        break;

    case YYSYMBOL_Term: /* Term  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2424 "src/parser.c"
        break;

    case YYSYMBOL_Args: /* Args  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2430 "src/parser.c"
        break;

    case YYSYMBOL_Arg: /* Arg  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2436 "src/parser.c"
        break;

    case YYSYMBOL_Patterns: /* Patterns  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2442 "src/parser.c"
        break;

    case YYSYMBOL_Pattern: /* Pattern  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2448 "src/parser.c"
        break;

    case YYSYMBOL_ArrayPats: /* ArrayPats  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2454 "src/parser.c"
        break;

    case YYSYMBOL_ObjPats: /* ObjPats  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2460 "src/parser.c"
        break;

    case YYSYMBOL_ObjPat: /* ObjPat  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2466 "src/parser.c"
        break;

    case YYSYMBOL_Keyword: /* Keyword  */
#line 36 "src/parser.y"
            { jv_free(((*yyvaluep).literal)); }
#line 2472 "src/parser.c"
        break;

    case YYSYMBOL_MkDict: /* MkDict  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2478 "src/parser.c"
        break;

    case YYSYMBOL_MkDictPair: /* MkDictPair  */
#line 37 "src/parser.y"
            { block_free(((*yyvaluep).blk)); }
#line 2484 "src/parser.c"
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
#line 312 "src/parser.y"
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
    gen_op_simple(OUTPUT)
  );

  *answer = BLOCK((yyvsp[-2].blk), (yyvsp[-1].blk), gen_marker(TOP), main_loop);
}
#line 2806 "src/parser.c"
    break;

  case 3: /* TopLevel: Module Imports FuncDefs  */
#line 331 "src/parser.y"
                        {
  *answer = BLOCK((yyvsp[-2].blk), (yyvsp[-1].blk), (yyvsp[0].blk));
}
#line 2814 "src/parser.c"
    break;

  case 4: /* Module: %empty  */
#line 336 "src/parser.y"
       {
  (yyval.blk) = gen_noop();
}
#line 2822 "src/parser.c"
    break;

  case 5: /* Module: "module" Exp ';'  */
#line 339 "src/parser.y"
                 {
  if (!block_is_const((yyvsp[-1].blk))) {
    FAIL((yyloc), "Module metadata must be constant");
    (yyval.blk) = gen_noop();
    block_free((yyvsp[-1].blk));
  } else {
    (yyval.blk) = gen_module((yyvsp[-1].blk));
  }
}
#line 2836 "src/parser.c"
    break;

  case 6: /* Imports: %empty  */
#line 350 "src/parser.y"
       {
  (yyval.blk) = gen_noop();
}
#line 2844 "src/parser.c"
    break;

  case 7: /* Imports: Import Imports  */
#line 353 "src/parser.y"
               {
  (yyval.blk) = BLOCK((yyvsp[-1].blk), (yyvsp[0].blk));
}
#line 2852 "src/parser.c"
    break;

  case 8: /* FuncDefs: %empty  */
#line 358 "src/parser.y"
       {
  (yyval.blk) = gen_noop();
}
#line 2860 "src/parser.c"
    break;

  case 9: /* FuncDefs: FuncDef FuncDefs  */
#line 361 "src/parser.y"
                 {
  (yyval.blk) = block_join((yyvsp[-1].blk), (yyvsp[0].blk));
}
#line 2868 "src/parser.c"
    break;

  case 10: /* Exp: FuncDef Exp  */
#line 366 "src/parser.y"
                          {
  (yyval.blk) = block_bind_referenced((yyvsp[-1].blk), (yyvsp[0].blk), OP_IS_CALL_PSEUDO);
}
#line 2876 "src/parser.c"
    break;

  case 11: /* Exp: Term "as" Patterns '|' Exp  */
#line 397 "src/parser.y"
                           {
  (yyval.blk) = gen_destructure((yyvsp[-4].blk), (yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 2884 "src/parser.c"
    break;

  case 12: /* Exp: "reduce" Term "as" Patterns '(' Exp ';' Exp ')'  */
#line 400 "src/parser.y"
                                                {
  (yyval.blk) = gen_reduce((yyvsp[-7].blk), (yyvsp[-5].blk), (yyvsp[-3].blk), (yyvsp[-1].blk));
}
#line 2892 "src/parser.c"
    break;

  case 13: /* Exp: "foreach" Term "as" Patterns '(' Exp ';' Exp ';' Exp ')'  */
#line 404 "src/parser.y"
                                                         {
  (yyval.blk) = gen_foreach((yyvsp[-9].blk), (yyvsp[-7].blk), (yyvsp[-5].blk), (yyvsp[-3].blk), (yyvsp[-1].blk));
}
#line 2900 "src/parser.c"
    break;

  case 14: /* Exp: "foreach" Term "as" Patterns '(' Exp ';' Exp ')'  */
#line 408 "src/parser.y"
                                                 {
  (yyval.blk) = gen_foreach((yyvsp[-7].blk), (yyvsp[-5].blk), (yyvsp[-3].blk), (yyvsp[-1].blk), gen_noop());
}
#line 2908 "src/parser.c"
    break;

  case 15: /* Exp: "if" Exp "then" Exp ElseBody  */
#line 412 "src/parser.y"
                             {
  (yyval.blk) = gen_cond((yyvsp[-3].blk), (yyvsp[-1].blk), (yyvsp[0].blk));
}
#line 2916 "src/parser.c"
    break;

  case 16: /* Exp: "if" Exp "then" Exp "end"  */
#line 415 "src/parser.y"
                          {
  (yyval.blk) = gen_cond((yyvsp[-3].blk), (yyvsp[-1].blk), gen_noop());
}
#line 2924 "src/parser.c"
    break;

  case 17: /* Exp: "if" Exp "then" error  */
#line 418 "src/parser.y"
                      {
  FAIL((yyloc), "Possibly unterminated 'if' statement");
  (yyval.blk) = (yyvsp[-2].blk);
}
#line 2933 "src/parser.c"
    break;

  case 18: /* Exp: "try" '(' Exp ';' Exp ')'  */
#line 423 "src/parser.y"
                          {
  (yyval.blk) = gen_try((yyvsp[-3].blk), (yyvsp[-1].blk));
}
#line 2941 "src/parser.c"
    break;

  case 19: /* Exp: "try" '(' Exp ';' Exp ';' Exp ')'  */
#line 426 "src/parser.y"
                                  {
  (yyval.blk) = BLOCK(gen_call("_try_finally", BLOCK(gen_lambda((yyvsp[-5].blk)), gen_lambda((yyvsp[-3].blk)), gen_lambda((yyvsp[-1].blk)))));
}
#line 2949 "src/parser.c"
    break;

  case 20: /* Exp: "try" Exp "catch" Exp  */
#line 429 "src/parser.y"
                      {
  (yyval.blk) = gen_try((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 2957 "src/parser.c"
    break;

  case 21: /* Exp: "try" Exp  */
#line 432 "src/parser.y"
          {
  (yyval.blk) = gen_try((yyvsp[0].blk), gen_op_simple(BACKTRACK_0));
}
#line 2965 "src/parser.c"
    break;

  case 22: /* Exp: "try" Exp "catch" error  */
#line 435 "src/parser.y"
                        {
  FAIL((yyloc), "Possibly unterminated 'try' statement");
  (yyval.blk) = (yyvsp[-2].blk);
}
#line 2974 "src/parser.c"
    break;

  case 23: /* Exp: "label" '$' IDENT '|' Exp  */
#line 440 "src/parser.y"
                          {
  jv v = jv_string_fmt("*label-%s", jv_string_value((yyvsp[-2].literal)));
  (yyval.blk) = gen_location((yyloc), locations, gen_label(jv_string_value(v), (yyvsp[0].blk)));
  jv_free((yyvsp[-2].literal));
  jv_free(v);
}
#line 2985 "src/parser.c"
    break;

  case 24: /* Exp: Exp '?'  */
#line 447 "src/parser.y"
        {
  (yyval.blk) = gen_try((yyvsp[-1].blk), gen_op_simple(BACKTRACK_0));
}
#line 2993 "src/parser.c"
    break;

  case 25: /* Exp: Exp '=' Exp  */
#line 451 "src/parser.y"
            {
  (yyval.blk) = gen_call("_assign", BLOCK(gen_lambda((yyvsp[-2].blk)), gen_lambda((yyvsp[0].blk))));
}
#line 3001 "src/parser.c"
    break;

  case 26: /* Exp: Exp "or" Exp  */
#line 455 "src/parser.y"
             {
  (yyval.blk) = gen_or((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3009 "src/parser.c"
    break;

  case 27: /* Exp: Exp "and" Exp  */
#line 459 "src/parser.y"
              {
  (yyval.blk) = gen_and((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3017 "src/parser.c"
    break;

  case 28: /* Exp: Exp "//" Exp  */
#line 463 "src/parser.y"
             {
  (yyval.blk) = gen_definedor((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3025 "src/parser.c"
    break;

  case 29: /* Exp: Exp "//=" Exp  */
#line 467 "src/parser.y"
              {
  (yyval.blk) = gen_definedor_assign((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3033 "src/parser.c"
    break;

  case 30: /* Exp: Exp "|=" Exp  */
#line 471 "src/parser.y"
             {
  (yyval.blk) = gen_call("_modify", BLOCK(gen_lambda((yyvsp[-2].blk)), gen_lambda((yyvsp[0].blk))));
}
#line 3041 "src/parser.c"
    break;

  case 31: /* Exp: Exp '|' Exp  */
#line 475 "src/parser.y"
            {
  (yyval.blk) = block_join((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3049 "src/parser.c"
    break;

  case 32: /* Exp: Exp ">|" Exp  */
#line 479 "src/parser.y"
             {
  (yyval.blk) = block_join((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3057 "src/parser.c"
    break;

  case 33: /* Exp: Exp ',' Exp  */
#line 483 "src/parser.y"
            {
  (yyval.blk) = gen_both((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3065 "src/parser.c"
    break;

  case 34: /* Exp: Exp '+' Exp  */
#line 487 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '+');
}
#line 3073 "src/parser.c"
    break;

  case 35: /* Exp: Exp "+=" Exp  */
#line 491 "src/parser.y"
             {
  (yyval.blk) = gen_update((yyvsp[-2].blk), (yyvsp[0].blk), '+');
}
#line 3081 "src/parser.c"
    break;

  case 36: /* Exp: '-' Exp  */
#line 495 "src/parser.y"
        {
  (yyval.blk) = BLOCK((yyvsp[0].blk), gen_call("_negate", gen_noop()));
}
#line 3089 "src/parser.c"
    break;

  case 37: /* Exp: Exp '-' Exp  */
#line 499 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '-');
}
#line 3097 "src/parser.c"
    break;

  case 38: /* Exp: Exp "-=" Exp  */
#line 503 "src/parser.y"
             {
  (yyval.blk) = gen_update((yyvsp[-2].blk), (yyvsp[0].blk), '-');
}
#line 3105 "src/parser.c"
    break;

  case 39: /* Exp: Exp '*' Exp  */
#line 507 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '*');
}
#line 3113 "src/parser.c"
    break;

  case 40: /* Exp: Exp "*=" Exp  */
#line 511 "src/parser.y"
             {
  (yyval.blk) = gen_update((yyvsp[-2].blk), (yyvsp[0].blk), '*');
}
#line 3121 "src/parser.c"
    break;

  case 41: /* Exp: Exp '/' Exp  */
#line 515 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '/');
  if (block_is_const_inf((yyval.blk)))
    FAIL((yyloc), "Division by zero?");
}
#line 3131 "src/parser.c"
    break;

  case 42: /* Exp: Exp '%' Exp  */
#line 521 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '%');
  if (block_is_const_inf((yyval.blk)))
    FAIL((yyloc), "Remainder by zero?");
}
#line 3141 "src/parser.c"
    break;

  case 43: /* Exp: Exp "/=" Exp  */
#line 527 "src/parser.y"
             {
  (yyval.blk) = gen_update((yyvsp[-2].blk), (yyvsp[0].blk), '/');
}
#line 3149 "src/parser.c"
    break;

  case 44: /* Exp: Exp "%=" Exp  */
#line 531 "src/parser.y"
               {
  (yyval.blk) = gen_update((yyvsp[-2].blk), (yyvsp[0].blk), '%');
}
#line 3157 "src/parser.c"
    break;

  case 45: /* Exp: Exp "==" Exp  */
#line 535 "src/parser.y"
             {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), EQ);
}
#line 3165 "src/parser.c"
    break;

  case 46: /* Exp: Exp "!=" Exp  */
#line 539 "src/parser.y"
             {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), NEQ);
}
#line 3173 "src/parser.c"
    break;

  case 47: /* Exp: Exp '<' Exp  */
#line 543 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '<');
}
#line 3181 "src/parser.c"
    break;

  case 48: /* Exp: Exp '>' Exp  */
#line 547 "src/parser.y"
            {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), '>');
}
#line 3189 "src/parser.c"
    break;

  case 49: /* Exp: Exp "<=" Exp  */
#line 551 "src/parser.y"
             {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), LESSEQ);
}
#line 3197 "src/parser.c"
    break;

  case 50: /* Exp: Exp ">=" Exp  */
#line 555 "src/parser.y"
             {
  (yyval.blk) = gen_binop((yyvsp[-2].blk), (yyvsp[0].blk), GREATEREQ);
}
#line 3205 "src/parser.c"
    break;

  case 51: /* Exp: Term  */
#line 559 "src/parser.y"
     {
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3213 "src/parser.c"
    break;

  case 52: /* Exp: HandleMethodSpec '@' HandleRefSpec  */
#line 563 "src/parser.y"
                                   {
  (yyval.blk) = gen_location((yyloc), locations, gen_handle_call((yyvsp[-2].blk), (yyvsp[0].blk)));
}
#line 3221 "src/parser.c"
    break;

  case 53: /* Exp: Break  */
#line 567 "src/parser.y"
      {
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3229 "src/parser.c"
    break;

  case 54: /* HandleMethodSpec: %empty  */
#line 573 "src/parser.y"
       {
  (yyval.blk) = gen_const(jv_string(""));
}
#line 3237 "src/parser.c"
    break;

  case 55: /* HandleMethodSpec: IDENT  */
#line 576 "src/parser.y"
      {
  (yyval.blk) = gen_const((yyvsp[0].literal));
}
#line 3245 "src/parser.c"
    break;

  case 56: /* HandleMethodSpec: '(' Exp ')'  */
#line 579 "src/parser.y"
            {
  (yyval.blk) = (yyvsp[-1].blk);
}
#line 3253 "src/parser.c"
    break;

  case 57: /* HandleRefSpec: IDENT  */
#line 585 "src/parser.y"
      {
  (yyval.blk) = gen_location((yyloc), locations, gen_op_unbound(LOADV, jv_string_value((yyvsp[0].literal))));
  jv_free((yyvsp[0].literal));
}
#line 3262 "src/parser.c"
    break;

  case 58: /* HandleRefSpec: '(' Exp ')'  */
#line 589 "src/parser.y"
            {
  (yyval.blk) = (yyvsp[-1].blk);
}
#line 3270 "src/parser.c"
    break;

  case 59: /* Break: "break"  */
#line 594 "src/parser.y"
      {
  (yyval.blk) = gen_op_const(BACKTRACK_N, jv_number(1));
}
#line 3278 "src/parser.c"
    break;

  case 60: /* Break: "break" LITERAL  */
#line 597 "src/parser.y"
              {
  (yyval.blk) = gen_op_const(BACKTRACK_N, (yyvsp[0].literal));
}
#line 3286 "src/parser.c"
    break;

  case 61: /* Break: "break" '$' IDENT  */
#line 600 "src/parser.y"
                {
  jv v = jv_string_fmt("*label-%s", jv_string_value((yyvsp[0].literal)));     // impossible symbol
  (yyval.blk) = gen_location((yyloc), locations,
                    gen_op_unbound(BACKTRACK_PC, jv_string_value(v)));
  jv_free(v);
  jv_free((yyvsp[0].literal));
}
#line 3298 "src/parser.c"
    break;

  case 62: /* Break: "break" error  */
#line 607 "src/parser.y"
            {
  FAIL((yyloc), "`break <arg>` requires a label to break to, or a non-negative integer to bypass N forkpoints");
  (yyval.blk) = gen_noop();
}
#line 3307 "src/parser.c"
    break;

  case 63: /* Import: ImportWhat ';'  */
#line 613 "src/parser.y"
               {
  (yyval.blk) = (yyvsp[-1].blk);
}
#line 3315 "src/parser.c"
    break;

  case 64: /* Import: ImportWhat Exp ';'  */
#line 616 "src/parser.y"
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
#line 3335 "src/parser.c"
    break;

  case 65: /* ImportWhat: "import" ImportFrom "as" '$' IDENT  */
#line 633 "src/parser.y"
                                   {
  jv v = block_const((yyvsp[-3].blk));
  // XXX Make gen_import take only blocks and the int is_data so we
  // don't have to free so much stuff here
  (yyval.blk) = gen_import(jv_string_value(v), jv_string_value((yyvsp[0].literal)), 1);
  block_free((yyvsp[-3].blk));
  jv_free((yyvsp[0].literal));
  jv_free(v);
}
#line 3349 "src/parser.c"
    break;

  case 66: /* ImportWhat: "import" ImportFrom "as" IDENT  */
#line 642 "src/parser.y"
                               {
  jv v = block_const((yyvsp[-2].blk));
  (yyval.blk) = gen_import(jv_string_value(v), jv_string_value((yyvsp[0].literal)), 0);
  block_free((yyvsp[-2].blk));
  jv_free((yyvsp[0].literal));
  jv_free(v);
}
#line 3361 "src/parser.c"
    break;

  case 67: /* ImportWhat: "include" ImportFrom  */
#line 649 "src/parser.y"
                     {
  jv v = block_const((yyvsp[0].blk));
  (yyval.blk) = gen_import(jv_string_value(v), NULL, 0);
  block_free((yyvsp[0].blk));
  jv_free(v);
}
#line 3372 "src/parser.c"
    break;

  case 68: /* ImportFrom: String  */
#line 657 "src/parser.y"
       {
  if (!block_is_const((yyvsp[0].blk))) {
    FAIL((yyloc), "Import path must be constant");
    (yyval.blk) = gen_const(jv_string(""));
    block_free((yyvsp[0].blk));
  } else {
    (yyval.blk) = (yyvsp[0].blk);
  }
}
#line 3386 "src/parser.c"
    break;

  case 69: /* FuncDef: "def" IDENT ':' Exp ';'  */
#line 668 "src/parser.y"
                        {
  (yyval.blk) = gen_function(jv_string_value((yyvsp[-3].literal)), gen_noop(), (yyvsp[-1].blk));
  jv_free((yyvsp[-3].literal));
}
#line 3395 "src/parser.c"
    break;

  case 70: /* FuncDef: "def" IDENT '(' Params ')' ':' Exp ';'  */
#line 673 "src/parser.y"
                                       {
  (yyval.blk) = gen_function(jv_string_value((yyvsp[-6].literal)), (yyvsp[-4].blk), (yyvsp[-1].blk));
  jv_free((yyvsp[-6].literal));
}
#line 3404 "src/parser.c"
    break;

  case 71: /* Params: Param  */
#line 679 "src/parser.y"
      {
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3412 "src/parser.c"
    break;

  case 72: /* Params: Params ';' Param  */
#line 682 "src/parser.y"
                 {
  (yyval.blk) = BLOCK((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3420 "src/parser.c"
    break;

  case 73: /* Param: '$' IDENT  */
#line 687 "src/parser.y"
          {
  (yyval.blk) = gen_param_regular(jv_string_value((yyvsp[0].literal)));
  jv_free((yyvsp[0].literal));
}
#line 3429 "src/parser.c"
    break;

  case 74: /* Param: '$' Keyword  */
#line 691 "src/parser.y"
            {
  (yyval.blk) = gen_param_regular(jv_string_value((yyvsp[0].literal)));
  jv_free((yyvsp[0].literal));
}
#line 3438 "src/parser.c"
    break;

  case 75: /* Param: IDENT  */
#line 695 "src/parser.y"
      {
  (yyval.blk) = gen_param(jv_string_value((yyvsp[0].literal)));
  jv_free((yyvsp[0].literal));
}
#line 3447 "src/parser.c"
    break;

  case 76: /* @1: %empty  */
#line 702 "src/parser.y"
               { (yyval.literal) = jv_string("text"); }
#line 3453 "src/parser.c"
    break;

  case 77: /* String: QQSTRING_START @1 QQString QQSTRING_END  */
#line 702 "src/parser.y"
                                                                          {
  (yyval.blk) = (yyvsp[-1].blk);
  jv_free((yyvsp[-2].literal));
}
#line 3462 "src/parser.c"
    break;

  case 78: /* @2: %empty  */
#line 706 "src/parser.y"
                      { (yyval.literal) = (yyvsp[-1].literal); }
#line 3468 "src/parser.c"
    break;

  case 79: /* String: FORMAT QQSTRING_START @2 QQString QQSTRING_END  */
#line 706 "src/parser.y"
                                                                  {
  (yyval.blk) = (yyvsp[-1].blk);
  jv_free((yyvsp[-2].literal));
}
#line 3477 "src/parser.c"
    break;

  case 80: /* QQString: %empty  */
#line 713 "src/parser.y"
       {
  (yyval.blk) = gen_const(jv_string(""));
}
#line 3485 "src/parser.c"
    break;

  case 81: /* QQString: QQString QQSTRING_TEXT  */
#line 716 "src/parser.y"
                       {
  (yyval.blk) = gen_binop((yyvsp[-1].blk), gen_const((yyvsp[0].literal)), '+');
}
#line 3493 "src/parser.c"
    break;

  case 82: /* QQString: QQString QQSTRING_INTERP_START Exp QQSTRING_INTERP_END  */
#line 719 "src/parser.y"
                                                       {
  (yyval.blk) = gen_binop((yyvsp[-3].blk), gen_format((yyvsp[-1].blk), jv_copy((yyvsp[-4].literal))), '+');
}
#line 3501 "src/parser.c"
    break;

  case 83: /* ElseBody: "elif" Exp "then" Exp ElseBody  */
#line 725 "src/parser.y"
                               {
  (yyval.blk) = gen_cond((yyvsp[-3].blk), (yyvsp[-1].blk), (yyvsp[0].blk));
}
#line 3509 "src/parser.c"
    break;

  case 84: /* ElseBody: "else" Exp "end"  */
#line 728 "src/parser.y"
                 {
  (yyval.blk) = (yyvsp[-1].blk);
}
#line 3517 "src/parser.c"
    break;

  case 85: /* ExpD: ExpD '|' ExpD  */
#line 733 "src/parser.y"
              {
  (yyval.blk) = block_join((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3525 "src/parser.c"
    break;

  case 86: /* ExpD: '-' ExpD  */
#line 736 "src/parser.y"
         {
  (yyval.blk) = BLOCK((yyvsp[0].blk), gen_call("_negate", gen_noop()));
}
#line 3533 "src/parser.c"
    break;

  case 87: /* ExpD: Term  */
#line 739 "src/parser.y"
     {
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3541 "src/parser.c"
    break;

  case 88: /* Term: '.'  */
#line 745 "src/parser.y"
    {
  (yyval.blk) = gen_noop();
}
#line 3549 "src/parser.c"
    break;

  case 89: /* Term: ".."  */
#line 748 "src/parser.y"
    {
  (yyval.blk) = gen_call("recurse", gen_noop());
}
#line 3557 "src/parser.c"
    break;

  case 90: /* Term: Term FIELD '?'  */
#line 751 "src/parser.y"
               {
  (yyval.blk) = gen_index_opt((yyvsp[-2].blk), gen_const((yyvsp[-1].literal)));
}
#line 3565 "src/parser.c"
    break;

  case 91: /* Term: FIELD '?'  */
#line 754 "src/parser.y"
          {
  (yyval.blk) = gen_index_opt(gen_noop(), gen_const((yyvsp[-1].literal)));
}
#line 3573 "src/parser.c"
    break;

  case 92: /* Term: Term '.' String '?'  */
#line 757 "src/parser.y"
                    {
  (yyval.blk) = gen_index_opt((yyvsp[-3].blk), (yyvsp[-1].blk));
}
#line 3581 "src/parser.c"
    break;

  case 93: /* Term: '.' String '?'  */
#line 760 "src/parser.y"
               {
  (yyval.blk) = gen_index_opt(gen_noop(), (yyvsp[-1].blk));
}
#line 3589 "src/parser.c"
    break;

  case 94: /* Term: Term FIELD  */
#line 763 "src/parser.y"
                        {
  (yyval.blk) = gen_index((yyvsp[-1].blk), gen_const((yyvsp[0].literal)));
}
#line 3597 "src/parser.c"
    break;

  case 95: /* Term: FIELD  */
#line 766 "src/parser.y"
                   {
  (yyval.blk) = gen_index(gen_noop(), gen_const((yyvsp[0].literal)));
}
#line 3605 "src/parser.c"
    break;

  case 96: /* Term: Term '.' String  */
#line 769 "src/parser.y"
                             {
  (yyval.blk) = gen_index((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3613 "src/parser.c"
    break;

  case 97: /* Term: '.' String  */
#line 772 "src/parser.y"
                        {
  (yyval.blk) = gen_index(gen_noop(), (yyvsp[0].blk));
}
#line 3621 "src/parser.c"
    break;

  case 98: /* Term: '.' error  */
#line 775 "src/parser.y"
          {
  FAIL((yyloc), "try .[\"field\"] instead of .field for unusually named fields");
  (yyval.blk) = gen_noop();
}
#line 3630 "src/parser.c"
    break;

  case 99: /* Term: '.' IDENT error  */
#line 779 "src/parser.y"
                {
  jv_free((yyvsp[-1].literal));
  FAIL((yyloc), "try .[\"field\"] instead of .field for unusually named fields");
  (yyval.blk) = gen_noop();
}
#line 3640 "src/parser.c"
    break;

  case 100: /* Term: Term '[' Exp ']' '?'  */
#line 785 "src/parser.y"
                     {
  (yyval.blk) = gen_index_opt((yyvsp[-4].blk), (yyvsp[-2].blk));
}
#line 3648 "src/parser.c"
    break;

  case 101: /* Term: Term '[' Exp ']'  */
#line 788 "src/parser.y"
                              {
  (yyval.blk) = gen_index((yyvsp[-3].blk), (yyvsp[-1].blk));
}
#line 3656 "src/parser.c"
    break;

  case 102: /* Term: Term '.' '[' Exp ']' '?'  */
#line 791 "src/parser.y"
                         {
  (yyval.blk) = gen_index_opt((yyvsp[-5].blk), (yyvsp[-2].blk));
}
#line 3664 "src/parser.c"
    break;

  case 103: /* Term: Term '.' '[' Exp ']'  */
#line 794 "src/parser.y"
                                  {
  (yyval.blk) = gen_index((yyvsp[-4].blk), (yyvsp[-1].blk));
}
#line 3672 "src/parser.c"
    break;

  case 104: /* Term: Term '[' ']' '?'  */
#line 797 "src/parser.y"
                 {
  (yyval.blk) = block_join((yyvsp[-3].blk), gen_op_simple(EACH_OPT));
}
#line 3680 "src/parser.c"
    break;

  case 105: /* Term: Term '[' ']'  */
#line 800 "src/parser.y"
                          {
  (yyval.blk) = block_join((yyvsp[-2].blk), gen_op_simple(EACH));
}
#line 3688 "src/parser.c"
    break;

  case 106: /* Term: Term '[' Exp ':' Exp ']' '?'  */
#line 803 "src/parser.y"
                             {
  (yyval.blk) = gen_slice_index((yyvsp[-6].blk), (yyvsp[-4].blk), (yyvsp[-2].blk), INDEX_OPT);
}
#line 3696 "src/parser.c"
    break;

  case 107: /* Term: Term '[' Exp ':' ']' '?'  */
#line 806 "src/parser.y"
                         {
  (yyval.blk) = gen_slice_index((yyvsp[-5].blk), (yyvsp[-3].blk), gen_const(jv_null()), INDEX_OPT);
}
#line 3704 "src/parser.c"
    break;

  case 108: /* Term: Term '[' ':' Exp ']' '?'  */
#line 809 "src/parser.y"
                         {
  (yyval.blk) = gen_slice_index((yyvsp[-5].blk), gen_const(jv_null()), (yyvsp[-2].blk), INDEX_OPT);
}
#line 3712 "src/parser.c"
    break;

  case 109: /* Term: Term '[' Exp ':' Exp ']'  */
#line 812 "src/parser.y"
                                      {
  (yyval.blk) = gen_slice_index((yyvsp[-5].blk), (yyvsp[-3].blk), (yyvsp[-1].blk), INDEX);
}
#line 3720 "src/parser.c"
    break;

  case 110: /* Term: Term '[' Exp ':' ']'  */
#line 815 "src/parser.y"
                                  {
  (yyval.blk) = gen_slice_index((yyvsp[-4].blk), (yyvsp[-2].blk), gen_const(jv_null()), INDEX);
}
#line 3728 "src/parser.c"
    break;

  case 111: /* Term: Term '[' ':' Exp ']'  */
#line 818 "src/parser.y"
                                  {
  (yyval.blk) = gen_slice_index((yyvsp[-4].blk), gen_const(jv_null()), (yyvsp[-1].blk), INDEX);
}
#line 3736 "src/parser.c"
    break;

  case 112: /* Term: LITERAL  */
#line 821 "src/parser.y"
        {
  (yyval.blk) = gen_const((yyvsp[0].literal));
}
#line 3744 "src/parser.c"
    break;

  case 113: /* Term: String  */
#line 824 "src/parser.y"
       {
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3752 "src/parser.c"
    break;

  case 114: /* Term: '(' Exp ')'  */
#line 831 "src/parser.y"
            {
  (yyval.blk) = (yyvsp[-1].blk);
}
#line 3760 "src/parser.c"
    break;

  case 115: /* Term: '[' Exp ']'  */
#line 834 "src/parser.y"
            {
  (yyval.blk) = gen_collect((yyvsp[-1].blk));
}
#line 3768 "src/parser.c"
    break;

  case 116: /* Term: '[' ']'  */
#line 837 "src/parser.y"
        {
  (yyval.blk) = gen_const(jv_array());
}
#line 3776 "src/parser.c"
    break;

  case 117: /* Term: '{' MkDict '}'  */
#line 840 "src/parser.y"
               {
  block o = gen_const_object((yyvsp[-1].blk));
  if (o.first != NULL)
    (yyval.blk) = o;
  else
    (yyval.blk) = BLOCK(gen_subexp(gen_const(jv_object())), (yyvsp[-1].blk), gen_op_simple(POP));
}
#line 3788 "src/parser.c"
    break;

  case 118: /* Term: '$' IDENT  */
#line 847 "src/parser.y"
          {
  (yyval.blk) = gen_location((yyloc), locations, gen_op_unbound(LOADV, jv_string_value((yyvsp[0].literal))));
  jv_free((yyvsp[0].literal));
}
#line 3797 "src/parser.c"
    break;

  case 119: /* Term: '$' Keyword  */
#line 851 "src/parser.y"
            {
  if (strcmp(jv_string_value((yyvsp[0].literal)), "__loc__") == 0) {
    (yyval.blk) = gen_const(JV_OBJECT(jv_string("file"), jv_copy(locations->fname),
                             jv_string("line"), jv_number(locfile_get_line(locations, (yyloc).start) + 1)));
  } else {
    (yyval.blk) = gen_location((yyloc), locations, gen_op_unbound(LOADV, jv_string_value((yyvsp[0].literal))));
  }
  jv_free((yyvsp[0].literal));
}
#line 3811 "src/parser.c"
    break;

  case 120: /* Term: IDENT  */
#line 860 "src/parser.y"
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
#line 3828 "src/parser.c"
    break;

  case 121: /* Term: IDENT '(' Args ')'  */
#line 872 "src/parser.y"
                   {
  (yyval.blk) = gen_call(jv_string_value((yyvsp[-3].literal)), (yyvsp[-1].blk));
  (yyval.blk) = gen_location((yylsp[-3]), locations, (yyval.blk));
  jv_free((yyvsp[-3].literal));
}
#line 3838 "src/parser.c"
    break;

  case 122: /* Term: '$' '(' Exp ')'  */
#line 878 "src/parser.y"
                {
  (yyval.blk) = gen_coexpression((yyvsp[-1].blk));
}
#line 3846 "src/parser.c"
    break;

  case 123: /* Term: '(' error ')'  */
#line 882 "src/parser.y"
              { (yyval.blk) = gen_noop(); }
#line 3852 "src/parser.c"
    break;

  case 124: /* Term: '[' error ']'  */
#line 883 "src/parser.y"
              { (yyval.blk) = gen_noop(); }
#line 3858 "src/parser.c"
    break;

  case 125: /* Term: Term '[' error ']'  */
#line 884 "src/parser.y"
                   { (yyval.blk) = (yyvsp[-3].blk); }
#line 3864 "src/parser.c"
    break;

  case 126: /* Term: '{' error '}'  */
#line 885 "src/parser.y"
              { (yyval.blk) = gen_noop(); }
#line 3870 "src/parser.c"
    break;

  case 127: /* Args: Arg  */
#line 888 "src/parser.y"
    {
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3878 "src/parser.c"
    break;

  case 128: /* Args: Args ';' Arg  */
#line 891 "src/parser.y"
             {
  (yyval.blk) = BLOCK((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3886 "src/parser.c"
    break;

  case 129: /* Arg: Exp  */
#line 896 "src/parser.y"
    {
  (yyval.blk) = gen_lambda((yyvsp[0].blk));
}
#line 3894 "src/parser.c"
    break;

  case 130: /* Patterns: Patterns "?//" Pattern  */
#line 901 "src/parser.y"
                       {
  (yyval.blk) = BLOCK((yyvsp[-2].blk), gen_destructure_alt((yyvsp[0].blk)));
}
#line 3902 "src/parser.c"
    break;

  case 131: /* Patterns: Pattern  */
#line 904 "src/parser.y"
        {
  (yyval.blk) = gen_destructure_alt((yyvsp[0].blk));
}
#line 3910 "src/parser.c"
    break;

  case 132: /* Pattern: '$' IDENT  */
#line 909 "src/parser.y"
          {
  (yyval.blk) = gen_op_unbound(STOREV, jv_string_value((yyvsp[0].literal)));
  jv_free((yyvsp[0].literal));
}
#line 3919 "src/parser.c"
    break;

  case 133: /* Pattern: '[' ArrayPats ']'  */
#line 913 "src/parser.y"
                  {
  (yyval.blk) = BLOCK((yyvsp[-1].blk), gen_op_simple(POP));
}
#line 3927 "src/parser.c"
    break;

  case 134: /* Pattern: '{' ObjPats '}'  */
#line 916 "src/parser.y"
                {
  (yyval.blk) = BLOCK((yyvsp[-1].blk), gen_op_simple(POP));
}
#line 3935 "src/parser.c"
    break;

  case 135: /* ArrayPats: Pattern  */
#line 921 "src/parser.y"
        {
  (yyval.blk) = gen_array_matcher(gen_noop(), (yyvsp[0].blk));
}
#line 3943 "src/parser.c"
    break;

  case 136: /* ArrayPats: ArrayPats ',' Pattern  */
#line 924 "src/parser.y"
                      {
  (yyval.blk) = gen_array_matcher((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3951 "src/parser.c"
    break;

  case 137: /* ObjPats: ObjPat  */
#line 929 "src/parser.y"
       {
  (yyval.blk) = (yyvsp[0].blk);
}
#line 3959 "src/parser.c"
    break;

  case 138: /* ObjPats: ObjPats ',' ObjPat  */
#line 932 "src/parser.y"
                   {
  (yyval.blk) = BLOCK((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 3967 "src/parser.c"
    break;

  case 139: /* ObjPat: '$' IDENT  */
#line 937 "src/parser.y"
          {
  (yyval.blk) = gen_object_matcher(gen_const((yyvsp[0].literal)), gen_op_unbound(STOREV, jv_string_value((yyvsp[0].literal))));
}
#line 3975 "src/parser.c"
    break;

  case 140: /* ObjPat: '$' IDENT ':' Pattern  */
#line 940 "src/parser.y"
                      {
  (yyval.blk) = gen_object_matcher(gen_const((yyvsp[-2].literal)), BLOCK(gen_op_simple(DUP), gen_op_unbound(STOREV, jv_string_value((yyvsp[-2].literal))), (yyvsp[0].blk)));
}
#line 3983 "src/parser.c"
    break;

  case 141: /* ObjPat: IDENT ':' Pattern  */
#line 943 "src/parser.y"
                  {
  (yyval.blk) = gen_object_matcher(gen_const((yyvsp[-2].literal)), (yyvsp[0].blk));
}
#line 3991 "src/parser.c"
    break;

  case 142: /* ObjPat: Keyword ':' Pattern  */
#line 946 "src/parser.y"
                    {
  (yyval.blk) = gen_object_matcher(gen_const((yyvsp[-2].literal)), (yyvsp[0].blk));
}
#line 3999 "src/parser.c"
    break;

  case 143: /* ObjPat: String ':' Pattern  */
#line 949 "src/parser.y"
                   {
  (yyval.blk) = gen_object_matcher((yyvsp[-2].blk), (yyvsp[0].blk));
}
#line 4007 "src/parser.c"
    break;

  case 144: /* ObjPat: '(' Exp ')' ':' Pattern  */
#line 952 "src/parser.y"
                        {
  jv msg = check_object_key((yyvsp[-3].blk));
  if (jv_is_valid(msg)) {
    FAIL((yyloc), jv_string_value(msg));
  }
  jv_free(msg);
  (yyval.blk) = gen_object_matcher((yyvsp[-3].blk), (yyvsp[0].blk));
}
#line 4020 "src/parser.c"
    break;

  case 145: /* ObjPat: error ':' Pattern  */
#line 960 "src/parser.y"
                  {
  FAIL((yyloc), "May need parentheses around object key expression");
  (yyval.blk) = (yyvsp[0].blk);
}
#line 4029 "src/parser.c"
    break;

  case 146: /* Keyword: "as"  */
#line 966 "src/parser.y"
     {
  (yyval.literal) = jv_string("as");
}
#line 4037 "src/parser.c"
    break;

  case 147: /* Keyword: "def"  */
#line 969 "src/parser.y"
      {
  (yyval.literal) = jv_string("def");
}
#line 4045 "src/parser.c"
    break;

  case 148: /* Keyword: "codef"  */
#line 972 "src/parser.y"
        {
  (yyval.literal) = jv_string("codef");
}
#line 4053 "src/parser.c"
    break;

  case 149: /* Keyword: "module"  */
#line 975 "src/parser.y"
         {
  (yyval.literal) = jv_string("module");
}
#line 4061 "src/parser.c"
    break;

  case 150: /* Keyword: "import"  */
#line 978 "src/parser.y"
         {
  (yyval.literal) = jv_string("import");
}
#line 4069 "src/parser.c"
    break;

  case 151: /* Keyword: "include"  */
#line 981 "src/parser.y"
          {
  (yyval.literal) = jv_string("include");
}
#line 4077 "src/parser.c"
    break;

  case 152: /* Keyword: "if"  */
#line 984 "src/parser.y"
     {
  (yyval.literal) = jv_string("if");
}
#line 4085 "src/parser.c"
    break;

  case 153: /* Keyword: "then"  */
#line 987 "src/parser.y"
       {
  (yyval.literal) = jv_string("then");
}
#line 4093 "src/parser.c"
    break;

  case 154: /* Keyword: "else"  */
#line 990 "src/parser.y"
       {
  (yyval.literal) = jv_string("else");
}
#line 4101 "src/parser.c"
    break;

  case 155: /* Keyword: "elif"  */
#line 993 "src/parser.y"
       {
  (yyval.literal) = jv_string("elif");
}
#line 4109 "src/parser.c"
    break;

  case 156: /* Keyword: "reduce"  */
#line 996 "src/parser.y"
         {
  (yyval.literal) = jv_string("reduce");
}
#line 4117 "src/parser.c"
    break;

  case 157: /* Keyword: "foreach"  */
#line 999 "src/parser.y"
          {
  (yyval.literal) = jv_string("foreach");
}
#line 4125 "src/parser.c"
    break;

  case 158: /* Keyword: "end"  */
#line 1002 "src/parser.y"
      {
  (yyval.literal) = jv_string("end");
}
#line 4133 "src/parser.c"
    break;

  case 159: /* Keyword: "and"  */
#line 1005 "src/parser.y"
      {
  (yyval.literal) = jv_string("and");
}
#line 4141 "src/parser.c"
    break;

  case 160: /* Keyword: "or"  */
#line 1008 "src/parser.y"
     {
  (yyval.literal) = jv_string("or");
}
#line 4149 "src/parser.c"
    break;

  case 161: /* Keyword: "try"  */
#line 1011 "src/parser.y"
      {
  (yyval.literal) = jv_string("try");
}
#line 4157 "src/parser.c"
    break;

  case 162: /* Keyword: "catch"  */
#line 1014 "src/parser.y"
        {
  (yyval.literal) = jv_string("catch");
}
#line 4165 "src/parser.c"
    break;

  case 163: /* Keyword: "label"  */
#line 1017 "src/parser.y"
        {
  (yyval.literal) = jv_string("label");
}
#line 4173 "src/parser.c"
    break;

  case 164: /* Keyword: "break"  */
#line 1020 "src/parser.y"
        {
  (yyval.literal) = jv_string("break");
}
#line 4181 "src/parser.c"
    break;

  case 165: /* Keyword: "__loc__"  */
#line 1023 "src/parser.y"
          {
  (yyval.literal) = jv_string("__loc__");
}
#line 4189 "src/parser.c"
    break;

  case 166: /* MkDict: %empty  */
#line 1028 "src/parser.y"
       {
  (yyval.blk)=gen_noop();
}
#line 4197 "src/parser.c"
    break;

  case 167: /* MkDict: MkDictPair  */
#line 1031 "src/parser.y"
            { (yyval.blk) = (yyvsp[0].blk); }
#line 4203 "src/parser.c"
    break;

  case 168: /* MkDict: MkDictPair ',' MkDict  */
#line 1032 "src/parser.y"
                        { (yyval.blk)=block_join((yyvsp[-2].blk), (yyvsp[0].blk)); }
#line 4209 "src/parser.c"
    break;

  case 169: /* MkDict: error ',' MkDict  */
#line 1033 "src/parser.y"
                   { (yyval.blk) = (yyvsp[0].blk); }
#line 4215 "src/parser.c"
    break;

  case 170: /* MkDictPair: IDENT ':' ExpD  */
#line 1036 "src/parser.y"
               {
  (yyval.blk) = gen_dictpair(gen_const((yyvsp[-2].literal)), (yyvsp[0].blk));
 }
#line 4223 "src/parser.c"
    break;

  case 171: /* MkDictPair: Keyword ':' ExpD  */
#line 1039 "src/parser.y"
                   {
  (yyval.blk) = gen_dictpair(gen_const((yyvsp[-2].literal)), (yyvsp[0].blk));
  }
#line 4231 "src/parser.c"
    break;

  case 172: /* MkDictPair: String ':' ExpD  */
#line 1042 "src/parser.y"
                  {
  (yyval.blk) = gen_dictpair((yyvsp[-2].blk), (yyvsp[0].blk));
  }
#line 4239 "src/parser.c"
    break;

  case 173: /* MkDictPair: String  */
#line 1045 "src/parser.y"
         {
  (yyval.blk) = gen_dictpair((yyvsp[0].blk), BLOCK(gen_op_simple(POP), gen_op_simple(DUP2),
                              gen_op_simple(DUP2), gen_op_simple(INDEX)));
  }
#line 4248 "src/parser.c"
    break;

  case 174: /* MkDictPair: '$' IDENT ':' ExpD  */
#line 1049 "src/parser.y"
                     {
  (yyval.blk) = gen_dictpair(gen_location((yyloc), locations, gen_op_unbound(LOADV, jv_string_value((yyvsp[-2].literal)))),
                    (yyvsp[0].blk));
  }
#line 4257 "src/parser.c"
    break;

  case 175: /* MkDictPair: '$' IDENT  */
#line 1053 "src/parser.y"
            {
  (yyval.blk) = gen_dictpair(gen_const((yyvsp[0].literal)),
                    gen_location((yyloc), locations, gen_op_unbound(LOADV, jv_string_value((yyvsp[0].literal)))));
  }
#line 4266 "src/parser.c"
    break;

  case 176: /* MkDictPair: '$' Keyword  */
#line 1057 "src/parser.y"
              {
  (yyval.blk) = gen_dictpair(gen_const((yyvsp[0].literal)),
                    gen_location((yyloc), locations, gen_op_unbound(LOADV, jv_string_value((yyvsp[0].literal)))));
  }
#line 4275 "src/parser.c"
    break;

  case 177: /* MkDictPair: IDENT  */
#line 1061 "src/parser.y"
        {
  (yyval.blk) = gen_dictpair(gen_const(jv_copy((yyvsp[0].literal))),
                    gen_index(gen_noop(), gen_const((yyvsp[0].literal))));
  }
#line 4284 "src/parser.c"
    break;

  case 178: /* MkDictPair: Keyword  */
#line 1065 "src/parser.y"
          {
  (yyval.blk) = gen_dictpair(gen_const(jv_copy((yyvsp[0].literal))),
                    gen_index(gen_noop(), gen_const((yyvsp[0].literal))));
  }
#line 4293 "src/parser.c"
    break;

  case 179: /* MkDictPair: '(' Exp ')' ':' ExpD  */
#line 1069 "src/parser.y"
                       {
  jv msg = check_object_key((yyvsp[-3].blk));
  if (jv_is_valid(msg)) {
    FAIL((yyloc), jv_string_value(msg));
  }
  jv_free(msg);
  (yyval.blk) = gen_dictpair((yyvsp[-3].blk), (yyvsp[0].blk));
  }
#line 4306 "src/parser.c"
    break;

  case 180: /* MkDictPair: error ':' ExpD  */
#line 1077 "src/parser.y"
                 {
  FAIL((yyloc), "May need parentheses around object key expression");
  (yyval.blk) = (yyvsp[0].blk);
  }
#line 4315 "src/parser.c"
    break;


#line 4319 "src/parser.c"

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

#line 1081 "src/parser.y"


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
