/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 151 "./cgram.y"

# include "pass1.h"
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

#undef n_type
#define n_type ptype
#undef n_qual
#define n_qual pqual
#undef n_df
#define n_df pdf

int fun_inline;	/* Reading an inline function */
int oldstyle;	/* Current function being defined */
static struct symtab *xnf;
extern int enummer, tvaloff, inattr;
extern struct rstack *rpole;
static int alwinl;
P1ND *cftnod;
static int attrwarn = 1;

#define	NORETYP	SNOCREAT /* no return type, save in unused field in symtab */

struct genlist {
	struct genlist *next;
	P1ND *p;
	TWORD t;
};

       P1ND *bdty(int op, ...);
static void fend(void);
static void fundef(P1ND *tp, P1ND *p);
static void olddecl(P1ND *p, P1ND *a);
static struct symtab *init_declarator(P1ND *tn, P1ND *p, int assign, P1ND *a,
	char *as);
static void resetbc(int mask);
static void swend(void);
static void addcase(P1ND *p);
#ifdef GCC_COMPAT
static void gcccase(P1ND *p, P1ND *);
#endif
static struct attr *gcc_attr_wrapper(P1ND *p);
static void adddef(void);
static void savebc(void);
static void swstart(int, TWORD);
static void genswitch(int, TWORD, struct swents **, int);
static char *mkpstr(char *str);
static struct symtab *clbrace(P1ND *);
static P1ND *cmop(P1ND *l, P1ND *r);
static P1ND *xcmop(P1ND *out, P1ND *in, P1ND *str);
static void mkxasm(char *str, P1ND *p);
static P1ND *xasmop(char *str, P1ND *p);
static P1ND *biop(int op, P1ND *l, P1ND *r);
static void flend(void);
static P1ND *gccexpr(int bn, P1ND *q);
static char * simname(char *s);
static P1ND *tyof(P1ND *);	/* COMPAT_GCC */
static P1ND *voidcon(void);
static P1ND *funargs(P1ND *p);
static void oldargs(P1ND *p);
static void uawarn(P1ND *p, char *s);
static int con_e(P1ND *p);
static void dainit(P1ND *d, P1ND *a);
static P1ND *tymfix(P1ND *p);
static P1ND *namekill(P1ND *p, int clr);
static P1ND *aryfix(P1ND *p);
static P1ND *dogen(struct genlist *g, P1ND *e);
static struct genlist *newgen(P1ND *p, P1ND *q);
static struct genlist *addgen(struct genlist *g, struct genlist *h);

static void savlab(int);
static void xcbranch(P1ND *, int);
extern int *mkclabs(void);

#define	TYMFIX(inp) { \
	P1ND *pp = inp; \
	inp = tymerge(pp->n_left, pp->n_right); \
	p1nfree(pp->n_left); p1nfree(pp); }

struct xalloc;
extern struct xalloc *bkpole, *sapole;
extern int cbkp, cstp;
extern int usdnodes;
struct bks {
	struct xalloc *ptr;
	int off;
};

/*
 * State for saving current switch state (when nested switches).
 */
struct savbc {
	struct savbc *next;
	int brklab;
	int contlab;
	int flostat;
	int swx;
	struct xalloc *bkptr;
	int bkoff;
	struct xalloc *stptr;
	int stoff;
	int numnode;
} *savbc, *savctx;


#line 178 "y.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    C_STRING = 258,                /* C_STRING  */
    C_ICON = 259,                  /* C_ICON  */
    C_FCON = 260,                  /* C_FCON  */
    C_NAME = 261,                  /* C_NAME  */
    C_TYPENAME = 262,              /* C_TYPENAME  */
    C_ANDAND = 263,                /* C_ANDAND  */
    C_OROR = 264,                  /* C_OROR  */
    C_GOTO = 265,                  /* C_GOTO  */
    C_RETURN = 266,                /* C_RETURN  */
    C_TYPE = 267,                  /* C_TYPE  */
    C_CLASS = 268,                 /* C_CLASS  */
    C_ASOP = 269,                  /* C_ASOP  */
    C_RELOP = 270,                 /* C_RELOP  */
    C_EQUOP = 271,                 /* C_EQUOP  */
    C_DIVOP = 272,                 /* C_DIVOP  */
    C_SHIFTOP = 273,               /* C_SHIFTOP  */
    C_INCOP = 274,                 /* C_INCOP  */
    C_UNOP = 275,                  /* C_UNOP  */
    C_STROP = 276,                 /* C_STROP  */
    C_STRUCT = 277,                /* C_STRUCT  */
    C_QUALIFIER = 278,             /* C_QUALIFIER  */
    C_FUNSPEC = 279,               /* C_FUNSPEC  */
    C_IF = 280,                    /* C_IF  */
    C_ELSE = 281,                  /* C_ELSE  */
    C_SWITCH = 282,                /* C_SWITCH  */
    C_BREAK = 283,                 /* C_BREAK  */
    C_CONTINUE = 284,              /* C_CONTINUE  */
    C_WHILE = 285,                 /* C_WHILE  */
    C_DO = 286,                    /* C_DO  */
    C_FOR = 287,                   /* C_FOR  */
    C_DEFAULT = 288,               /* C_DEFAULT  */
    C_CASE = 289,                  /* C_CASE  */
    C_SIZEOF = 290,                /* C_SIZEOF  */
    C_ENUM = 291,                  /* C_ENUM  */
    C_ELLIPSIS = 292,              /* C_ELLIPSIS  */
    C_ASM = 293,                   /* C_ASM  */
    NOMATCH = 294,                 /* NOMATCH  */
    C_TYPEOF = 295,                /* C_TYPEOF  */
    C_ATTRIBUTE = 296,             /* C_ATTRIBUTE  */
    PCC_OFFSETOF = 297,            /* PCC_OFFSETOF  */
    GCC_DESIG = 298,               /* GCC_DESIG  */
    C_STATICASSERT = 299,          /* C_STATICASSERT  */
    C_ALIGNAS = 300,               /* C_ALIGNAS  */
    C_ALIGNOF = 301,               /* C_ALIGNOF  */
    C_GENERIC = 302,               /* C_GENERIC  */
    C_ATOMIC = 303                 /* C_ATOMIC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define C_STRING 258
#define C_ICON 259
#define C_FCON 260
#define C_NAME 261
#define C_TYPENAME 262
#define C_ANDAND 263
#define C_OROR 264
#define C_GOTO 265
#define C_RETURN 266
#define C_TYPE 267
#define C_CLASS 268
#define C_ASOP 269
#define C_RELOP 270
#define C_EQUOP 271
#define C_DIVOP 272
#define C_SHIFTOP 273
#define C_INCOP 274
#define C_UNOP 275
#define C_STROP 276
#define C_STRUCT 277
#define C_QUALIFIER 278
#define C_FUNSPEC 279
#define C_IF 280
#define C_ELSE 281
#define C_SWITCH 282
#define C_BREAK 283
#define C_CONTINUE 284
#define C_WHILE 285
#define C_DO 286
#define C_FOR 287
#define C_DEFAULT 288
#define C_CASE 289
#define C_SIZEOF 290
#define C_ENUM 291
#define C_ELLIPSIS 292
#define C_ASM 293
#define NOMATCH 294
#define C_TYPEOF 295
#define C_ATTRIBUTE 296
#define PCC_OFFSETOF 297
#define GCC_DESIG 298
#define C_STATICASSERT 299
#define C_ALIGNAS 300
#define C_ALIGNOF 301
#define C_GENERIC 302
#define C_ATOMIC 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 258 "./cgram.y"

	TWORD type;
	int intval;
	P1ND *nodep;
	struct symtab *symp;
	struct rstack *rp;
	char *strp;
	struct bks *bkp;
	struct flt flt;
	struct lexint li;
	struct genlist *g;

#line 340 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_C_STRING = 3,                   /* C_STRING  */
  YYSYMBOL_C_ICON = 4,                     /* C_ICON  */
  YYSYMBOL_C_FCON = 5,                     /* C_FCON  */
  YYSYMBOL_C_NAME = 6,                     /* C_NAME  */
  YYSYMBOL_C_TYPENAME = 7,                 /* C_TYPENAME  */
  YYSYMBOL_C_ANDAND = 8,                   /* C_ANDAND  */
  YYSYMBOL_C_OROR = 9,                     /* C_OROR  */
  YYSYMBOL_C_GOTO = 10,                    /* C_GOTO  */
  YYSYMBOL_C_RETURN = 11,                  /* C_RETURN  */
  YYSYMBOL_C_TYPE = 12,                    /* C_TYPE  */
  YYSYMBOL_C_CLASS = 13,                   /* C_CLASS  */
  YYSYMBOL_C_ASOP = 14,                    /* C_ASOP  */
  YYSYMBOL_C_RELOP = 15,                   /* C_RELOP  */
  YYSYMBOL_C_EQUOP = 16,                   /* C_EQUOP  */
  YYSYMBOL_C_DIVOP = 17,                   /* C_DIVOP  */
  YYSYMBOL_C_SHIFTOP = 18,                 /* C_SHIFTOP  */
  YYSYMBOL_C_INCOP = 19,                   /* C_INCOP  */
  YYSYMBOL_C_UNOP = 20,                    /* C_UNOP  */
  YYSYMBOL_C_STROP = 21,                   /* C_STROP  */
  YYSYMBOL_C_STRUCT = 22,                  /* C_STRUCT  */
  YYSYMBOL_C_QUALIFIER = 23,               /* C_QUALIFIER  */
  YYSYMBOL_C_FUNSPEC = 24,                 /* C_FUNSPEC  */
  YYSYMBOL_C_IF = 25,                      /* C_IF  */
  YYSYMBOL_C_ELSE = 26,                    /* C_ELSE  */
  YYSYMBOL_C_SWITCH = 27,                  /* C_SWITCH  */
  YYSYMBOL_C_BREAK = 28,                   /* C_BREAK  */
  YYSYMBOL_C_CONTINUE = 29,                /* C_CONTINUE  */
  YYSYMBOL_C_WHILE = 30,                   /* C_WHILE  */
  YYSYMBOL_C_DO = 31,                      /* C_DO  */
  YYSYMBOL_C_FOR = 32,                     /* C_FOR  */
  YYSYMBOL_C_DEFAULT = 33,                 /* C_DEFAULT  */
  YYSYMBOL_C_CASE = 34,                    /* C_CASE  */
  YYSYMBOL_C_SIZEOF = 35,                  /* C_SIZEOF  */
  YYSYMBOL_C_ENUM = 36,                    /* C_ENUM  */
  YYSYMBOL_C_ELLIPSIS = 37,                /* C_ELLIPSIS  */
  YYSYMBOL_C_ASM = 38,                     /* C_ASM  */
  YYSYMBOL_NOMATCH = 39,                   /* NOMATCH  */
  YYSYMBOL_C_TYPEOF = 40,                  /* C_TYPEOF  */
  YYSYMBOL_C_ATTRIBUTE = 41,               /* C_ATTRIBUTE  */
  YYSYMBOL_PCC_OFFSETOF = 42,              /* PCC_OFFSETOF  */
  YYSYMBOL_GCC_DESIG = 43,                 /* GCC_DESIG  */
  YYSYMBOL_C_STATICASSERT = 44,            /* C_STATICASSERT  */
  YYSYMBOL_C_ALIGNAS = 45,                 /* C_ALIGNAS  */
  YYSYMBOL_C_ALIGNOF = 46,                 /* C_ALIGNOF  */
  YYSYMBOL_C_GENERIC = 47,                 /* C_GENERIC  */
  YYSYMBOL_C_ATOMIC = 48,                  /* C_ATOMIC  */
  YYSYMBOL_49_ = 49,                       /* ','  */
  YYSYMBOL_50_ = 50,                       /* '='  */
  YYSYMBOL_51_ = 51,                       /* '?'  */
  YYSYMBOL_52_ = 52,                       /* ':'  */
  YYSYMBOL_53_ = 53,                       /* '|'  */
  YYSYMBOL_54_ = 54,                       /* '^'  */
  YYSYMBOL_55_ = 55,                       /* '&'  */
  YYSYMBOL_56_ = 56,                       /* '+'  */
  YYSYMBOL_57_ = 57,                       /* '-'  */
  YYSYMBOL_58_ = 58,                       /* '*'  */
  YYSYMBOL_59_ = 59,                       /* '['  */
  YYSYMBOL_60_ = 60,                       /* '('  */
  YYSYMBOL_61_ = 61,                       /* ';'  */
  YYSYMBOL_62_ = 62,                       /* ')'  */
  YYSYMBOL_63_ = 63,                       /* ']'  */
  YYSYMBOL_64_ = 64,                       /* '{'  */
  YYSYMBOL_65_ = 65,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_ext_def_list = 67,              /* ext_def_list  */
  YYSYMBOL_external_def = 68,              /* external_def  */
  YYSYMBOL_funtype = 69,                   /* funtype  */
  YYSYMBOL_kr_args = 70,                   /* kr_args  */
  YYSYMBOL_declaration_specifiers = 71,    /* declaration_specifiers  */
  YYSYMBOL_merge_attribs = 72,             /* merge_attribs  */
  YYSYMBOL_type_sq = 73,                   /* type_sq  */
  YYSYMBOL_cf_spec = 74,                   /* cf_spec  */
  YYSYMBOL_typeof = 75,                    /* typeof  */
  YYSYMBOL_attribute_specifier = 76,       /* attribute_specifier  */
  YYSYMBOL_attribute_list = 77,            /* attribute_list  */
  YYSYMBOL_attribute = 78,                 /* attribute  */
  YYSYMBOL_declarator = 79,                /* declarator  */
  YYSYMBOL_ecq = 80,                       /* ecq  */
  YYSYMBOL_r = 81,                         /* r  */
  YYSYMBOL_c = 82,                         /* c  */
  YYSYMBOL_type_qualifier_list = 83,       /* type_qualifier_list  */
  YYSYMBOL_identifier_list = 84,           /* identifier_list  */
  YYSYMBOL_parameter_type_list = 85,       /* parameter_type_list  */
  YYSYMBOL_parameter_list = 86,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 87,     /* parameter_declaration  */
  YYSYMBOL_abstract_declarator = 88,       /* abstract_declarator  */
  YYSYMBOL_ib2 = 89,                       /* ib2  */
  YYSYMBOL_maybe_r = 90,                   /* maybe_r  */
  YYSYMBOL_arg_dcl_list = 91,              /* arg_dcl_list  */
  YYSYMBOL_arg_declaration = 92,           /* arg_declaration  */
  YYSYMBOL_arg_param_list = 93,            /* arg_param_list  */
  YYSYMBOL_block_item_list = 94,           /* block_item_list  */
  YYSYMBOL_block_item = 95,                /* block_item  */
  YYSYMBOL_declaration = 96,               /* declaration  */
  YYSYMBOL_init_declarator_list = 97,      /* init_declarator_list  */
  YYSYMBOL_98_1 = 98,                      /* @1  */
  YYSYMBOL_enum_dcl = 99,                  /* enum_dcl  */
  YYSYMBOL_enum_head = 100,                /* enum_head  */
  YYSYMBOL_moe_list = 101,                 /* moe_list  */
  YYSYMBOL_moe = 102,                      /* moe  */
  YYSYMBOL_struct_dcl = 103,               /* struct_dcl  */
  YYSYMBOL_attr_var = 104,                 /* attr_var  */
  YYSYMBOL_attr_spec_list = 105,           /* attr_spec_list  */
  YYSYMBOL_str_head = 106,                 /* str_head  */
  YYSYMBOL_struct_dcl_list = 107,          /* struct_dcl_list  */
  YYSYMBOL_struct_declaration = 108,       /* struct_declaration  */
  YYSYMBOL_optsemi = 109,                  /* optsemi  */
  YYSYMBOL_specifier_qualifier_list = 110, /* specifier_qualifier_list  */
  YYSYMBOL_merge_specifiers = 111,         /* merge_specifiers  */
  YYSYMBOL_struct_declarator_list = 112,   /* struct_declarator_list  */
  YYSYMBOL_113_2 = 113,                    /* @2  */
  YYSYMBOL_struct_declarator = 114,        /* struct_declarator  */
  YYSYMBOL_xnfdeclarator = 115,            /* xnfdeclarator  */
  YYSYMBOL_init_declarator = 116,          /* init_declarator  */
  YYSYMBOL_begbr = 117,                    /* begbr  */
  YYSYMBOL_initializer = 118,              /* initializer  */
  YYSYMBOL_init_list = 119,                /* init_list  */
  YYSYMBOL_designation = 120,              /* designation  */
  YYSYMBOL_designator_list = 121,          /* designator_list  */
  YYSYMBOL_designator = 122,               /* designator  */
  YYSYMBOL_optcomma = 123,                 /* optcomma  */
  YYSYMBOL_ibrace = 124,                   /* ibrace  */
  YYSYMBOL_compoundstmt = 125,             /* compoundstmt  */
  YYSYMBOL_begin = 126,                    /* begin  */
  YYSYMBOL_statement = 127,                /* statement  */
  YYSYMBOL_asmstatement = 128,             /* asmstatement  */
  YYSYMBOL_svstr = 129,                    /* svstr  */
  YYSYMBOL_mvol = 130,                     /* mvol  */
  YYSYMBOL_xasm = 131,                     /* xasm  */
  YYSYMBOL_oplist = 132,                   /* oplist  */
  YYSYMBOL_oper = 133,                     /* oper  */
  YYSYMBOL_cnstr = 134,                    /* cnstr  */
  YYSYMBOL_label = 135,                    /* label  */
  YYSYMBOL_doprefix = 136,                 /* doprefix  */
  YYSYMBOL_ifprefix = 137,                 /* ifprefix  */
  YYSYMBOL_ifelprefix = 138,               /* ifelprefix  */
  YYSYMBOL_whprefix = 139,                 /* whprefix  */
  YYSYMBOL_forprefix = 140,                /* forprefix  */
  YYSYMBOL_141_3 = 141,                    /* $@3  */
  YYSYMBOL_switchpart = 142,               /* switchpart  */
  YYSYMBOL_143_e = 143,                    /* .e  */
  YYSYMBOL_elist = 144,                    /* elist  */
  YYSYMBOL_e2 = 145,                       /* e2  */
  YYSYMBOL_e = 146,                        /* e  */
  YYSYMBOL_xbegin = 147,                   /* xbegin  */
  YYSYMBOL_term = 148,                     /* term  */
  YYSYMBOL_gen_ass_list = 149,             /* gen_ass_list  */
  YYSYMBOL_gen_assoc = 150,                /* gen_assoc  */
  YYSYMBOL_xa = 151,                       /* xa  */
  YYSYMBOL_clbrace = 152,                  /* clbrace  */
  YYSYMBOL_string = 153,                   /* string  */
  YYSYMBOL_cast_type = 154                 /* cast_type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  274
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  518

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
       2,     2,     2,     2,     2,     2,     2,     2,    55,     2,
      60,    62,    58,    56,    49,    57,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    61,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    63,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,    53,    65,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   294,   294,   295,   298,   299,   300,   301,   302,   305,
     309,   312,   313,   322,   325,   326,   327,   328,   331,   332,
     340,   341,   342,   343,   344,   348,   354,   355,   358,   361,
     362,   365,   366,   370,   373,   374,   377,   382,   383,   391,
     392,   396,   397,   401,   402,   403,   406,   410,   413,   414,
     415,   416,   417,   418,   419,   422,   428,   435,   436,   440,
     444,   449,   450,   460,   461,   471,   472,   481,   487,   491,
     497,   498,   502,   503,   507,   508,   512,   516,   520,   524,
     528,   532,   538,   541,   542,   548,   549,   553,   558,   562,
     571,   572,   575,   576,   586,   587,   591,   603,   604,   604,
     610,   611,   614,   615,   618,   619,   622,   623,   624,   625,
     628,   637,   641,   644,   656,   659,   660,   663,   664,   667,
     668,   672,   677,   678,   682,   685,   686,   690,   691,   691,
     695,   705,   711,   723,   738,   750,   753,   762,   765,   768,
     776,   780,   783,   786,   787,   788,   791,   792,   795,   796,
     797,   798,   801,   802,   805,   813,   818,   825,   826,   829,
     834,   835,   838,   869,   870,   871,   872,   878,   887,   900,
     912,   920,   928,   936,   947,   990,   991,   992,   993,   994,
     995,   996,   999,  1000,  1003,  1006,  1007,  1010,  1011,  1012,
    1015,  1016,  1019,  1020,  1025,  1026,  1029,  1030,  1031,  1032,
    1037,  1040,  1048,  1053,  1063,  1077,  1091,  1091,  1104,  1129,
    1130,  1133,  1134,  1137,  1138,  1139,  1144,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1170,  1176,  1177,  1178,  1179,
    1180,  1181,  1182,  1185,  1186,  1190,  1194,  1202,  1207,  1212,
    1213,  1216,  1217,  1218,  1219,  1220,  1237,  1238,  1239,  1240,
    1241,  1242,  1245,  1248,  1257,  1260,  1261,  1264,  1265,  1268,
    1271,  1274,  1275,  1278,  1281
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "C_STRING", "C_ICON",
  "C_FCON", "C_NAME", "C_TYPENAME", "C_ANDAND", "C_OROR", "C_GOTO",
  "C_RETURN", "C_TYPE", "C_CLASS", "C_ASOP", "C_RELOP", "C_EQUOP",
  "C_DIVOP", "C_SHIFTOP", "C_INCOP", "C_UNOP", "C_STROP", "C_STRUCT",
  "C_QUALIFIER", "C_FUNSPEC", "C_IF", "C_ELSE", "C_SWITCH", "C_BREAK",
  "C_CONTINUE", "C_WHILE", "C_DO", "C_FOR", "C_DEFAULT", "C_CASE",
  "C_SIZEOF", "C_ENUM", "C_ELLIPSIS", "C_ASM", "NOMATCH", "C_TYPEOF",
  "C_ATTRIBUTE", "PCC_OFFSETOF", "GCC_DESIG", "C_STATICASSERT",
  "C_ALIGNAS", "C_ALIGNOF", "C_GENERIC", "C_ATOMIC", "','", "'='", "'?'",
  "':'", "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'['", "'('", "';'",
  "')'", "']'", "'{'", "'}'", "$accept", "ext_def_list", "external_def",
  "funtype", "kr_args", "declaration_specifiers", "merge_attribs",
  "type_sq", "cf_spec", "typeof", "attribute_specifier", "attribute_list",
  "attribute", "declarator", "ecq", "r", "c", "type_qualifier_list",
  "identifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "abstract_declarator", "ib2", "maybe_r",
  "arg_dcl_list", "arg_declaration", "arg_param_list", "block_item_list",
  "block_item", "declaration", "init_declarator_list", "@1", "enum_dcl",
  "enum_head", "moe_list", "moe", "struct_dcl", "attr_var",
  "attr_spec_list", "str_head", "struct_dcl_list", "struct_declaration",
  "optsemi", "specifier_qualifier_list", "merge_specifiers",
  "struct_declarator_list", "@2", "struct_declarator", "xnfdeclarator",
  "init_declarator", "begbr", "initializer", "init_list", "designation",
  "designator_list", "designator", "optcomma", "ibrace", "compoundstmt",
  "begin", "statement", "asmstatement", "svstr", "mvol", "xasm", "oplist",
  "oper", "cnstr", "label", "doprefix", "ifprefix", "ifelprefix",
  "whprefix", "forprefix", "$@3", "switchpart", ".e", "elist", "e2", "e",
  "xbegin", "term", "gen_ass_list", "gen_assoc", "xa", "clbrace", "string",
  "cast_type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-354)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-211)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -354,   863,  -354,  -354,  -354,  -354,  -354,  -354,    -4,  -354,
    -354,    35,    43,    42,    64,    91,    95,   129,   246,   276,
    -354,  -354,  2153,   102,  -354,  2153,  2153,  -354,  -354,   110,
    -354,  -354,    67,  -354,   132,     9,  -354,   109,    -4,   137,
    -354,   139,  1136,   149,  1320,  1136,  1109,  -354,  -354,   110,
     268,    51,   276,   156,   122,  2153,  -354,  -354,  1486,    25,
     172,  -354,  -354,  -354,  1182,  1391,   197,    55,  -354,   174,
    -354,   233,  -354,  -354,  -354,   181,   240,  1320,  1320,  -354,
     193,  -354,   206,  1320,  1320,  1320,  1320,   802,  1109,   155,
    -354,  -354,  1525,   286,   283,   228,   262,  1978,  1576,   232,
     250,  -354,  -354,   110,  -354,   290,  -354,  -354,   483,   -12,
     130,  -354,   256,   272,    -4,  -354,   890,  -354,   275,  1320,
     278,  1206,   312,  -354,  1989,  -354,  -354,   265,   -13,   280,
     269,  -354,   301,   304,   307,  -354,  -354,   351,  -354,   295,
     -19,  1136,  -354,   286,   286,  1365,  1109,   297,  1320,   286,
     286,   286,   286,  -354,  1590,   678,   308,  -354,   795,  1182,
     167,   198,  1320,  1320,  1320,  1320,  1320,  1320,  1320,  1320,
    1320,  1251,  1320,  1320,  1320,  1320,  1320,  1320,  -354,  -354,
     255,  1320,  1136,  -354,  -354,   309,   317,   322,  1320,  -354,
    -354,  -354,  -354,    23,    45,   314,    17,   974,   320,   328,
     321,   333,   329,  -354,   337,   346,  1320,  -354,  -354,   102,
     548,  -354,  -354,  -354,  -354,   340,   740,   740,   740,   740,
     740,  1320,   740,  1762,  -354,   122,  -354,   233,  -354,  -354,
     135,   990,  -354,  1320,  1320,  1989,  -354,  1320,    58,   126,
     -12,   198,   396,  -354,  -354,  2103,  1320,  1320,   197,   338,
    -354,  -354,  1320,   -14,   134,  -354,   233,  -354,   352,   355,
     371,   990,  -354,   802,   286,   380,  1109,  2040,  -354,   613,
    1813,   909,   912,   198,   374,    -4,   305,  2153,  1296,   383,
    1052,   368,   990,   443,   417,  -354,   410,   990,   990,  1320,
    1916,  1112,  1217,   862,     7,     7,  -354,  -354,  -354,  1441,
     385,  1136,   386,   262,    14,  -354,  -354,    -4,    -4,   389,
    1320,  -354,  1826,  1320,  1320,  -354,  -354,  1320,  1019,  -354,
    1905,   152,  -354,  -354,  -354,   314,  -354,   421,   431,  -354,
    -354,   397,  1989,  -354,  -354,   -12,   400,   122,   291,  -354,
    1320,  -354,   414,   955,    48,  -354,  1989,  1989,   196,  -354,
    -354,  -354,  -354,   990,   990,  -354,  -354,   990,  1320,  -354,
    -354,  -354,   404,   411,   418,   423,  -354,  -354,  1136,   415,
    1320,   416,  1078,   419,  1839,   420,  -354,   286,   185,   198,
      -4,  -354,  -354,   430,   413,  1452,    -4,  2153,  2051,  1320,
    -354,  -354,   435,  -354,  -354,   448,  -354,  -354,  -354,  1890,
    -354,  1604,  1655,  1669,  2123,   459,  1320,  -354,   422,  -354,
     740,  -354,    10,  -354,  -354,  -354,  1426,   200,   439,  -354,
    -354,   347,   990,  -354,  1320,  -354,   776,   295,  -354,  1320,
     233,   233,   990,  -354,   273,   394,  -354,   427,    31,  -354,
     474,  -354,   467,   471,  -354,   414,  -354,    -4,    -4,    -4,
    -354,   472,  2051,  -354,  -354,  -354,  -354,  -354,  -354,  1320,
    1320,  1967,  1320,  -354,  -354,  1320,  -354,   955,  -354,  -354,
     414,  1503,    -4,  -354,  1683,   484,   475,  -354,  1320,  2173,
    -354,  1320,   480,  -354,   481,  -354,  -354,  -354,    -4,   476,
     489,  -354,  1734,  1514,  -354,   492,  -354,   233,  1320,   990,
    -354,   990,  -354,  -354,  -354,  -354,  -354,   501,   495,  -354,
    -354,   514,  1748,  -354,  -354,   233,  -354,  -354
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       3,     0,     1,     8,    41,    19,    18,    29,   113,    22,
      30,   102,   185,     0,     0,     0,     0,    26,     0,     0,
       7,     2,    11,     0,    13,    14,    16,    28,    23,     9,
       5,    21,     0,    20,     0,     0,   115,   117,   114,   101,
     186,     0,     0,     0,     0,     0,     0,    57,    59,    39,
       0,     0,     0,     0,     0,    12,    85,    94,    10,     0,
       0,    97,    15,    17,    83,     0,     0,     0,     6,   111,
     116,     0,   271,   256,   257,   254,     0,     0,     0,   269,
       0,   269,     0,     0,     0,     0,     0,     0,   126,   273,
     124,   258,     0,   234,   184,     0,    36,     0,     0,     0,
       0,    58,    60,    40,    43,     0,   162,     4,     0,   113,
       0,    86,     0,   137,   113,    95,     0,    56,    55,    53,
       0,     0,    83,    48,    49,    61,    47,    69,     0,     0,
      63,    65,   106,   107,   157,   104,   112,     0,   119,   134,
       0,   211,   263,   242,   241,     0,     0,     0,     0,   238,
     240,   239,   237,   235,     0,     0,     0,   125,    70,    83,
      82,   274,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,   236,
       0,     0,   211,   272,    32,    37,     0,    34,     0,    24,
      25,    27,    42,     0,   254,    19,     0,     0,     0,     0,
       0,     0,     0,   201,     0,     0,     0,   178,   161,     0,
       0,    90,    92,   164,    93,     0,     0,     0,     0,     0,
       0,   210,     0,     0,    88,     0,    87,     0,    98,   142,
     151,   139,    44,    54,     0,    50,    84,     0,    70,    82,
     113,    68,     0,    46,    45,     0,     0,     0,   158,     0,
     110,   120,     0,   113,     0,   127,   190,   182,     0,     0,
     212,   213,   216,     0,   243,     0,     0,     0,   259,     0,
       0,     0,    71,    72,     0,   113,     0,     0,    83,    82,
     223,   222,   219,   228,   227,   232,   229,   217,   218,     0,
       0,   224,   225,   226,   230,   231,   233,   252,   253,     0,
       0,   211,     0,    36,   184,   179,   180,   113,   113,     0,
       0,   173,     0,     0,     0,   171,   172,     0,   206,   200,
       0,   113,   160,    91,   177,     0,   181,     0,   165,   166,
     167,     0,   209,   170,   163,   113,     0,     0,     0,   149,
       0,   141,   157,     0,     0,   152,    52,    51,    71,    67,
      62,    64,    66,   108,   109,   105,   100,   131,     0,   130,
     128,   122,   121,     0,   187,   191,   183,   250,     0,     0,
       0,     0,     0,     0,     0,   163,   270,   244,   151,    73,
     113,    78,    74,     0,     0,     0,   113,     0,   221,     0,
     249,   251,     0,    33,    35,     0,   196,   197,   175,     0,
     174,     0,     0,     0,     0,     0,     0,   198,     0,   203,
       0,    89,   113,    99,   156,   155,     0,   151,     0,   159,
     146,   151,   143,   148,     0,   153,   132,   134,   123,     0,
     190,     0,   214,   215,   245,     0,   246,     0,     0,   265,
       0,   262,   163,     0,   248,   157,    75,   113,   113,   113,
      80,     0,   220,    38,    96,   176,   202,   208,   204,   210,
     210,     0,     0,   169,   138,     0,   154,     0,   140,   145,
     157,     0,   133,   129,     0,   188,     0,   255,     0,     0,
     264,     0,     0,   260,     0,    79,    76,    77,   113,     0,
       0,   199,     0,     0,   147,     0,   192,     0,     0,   268,
     266,   267,   261,   247,    81,   207,   205,     0,     0,   144,
     194,   189,     0,   168,   150,     0,   193,   195
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -354,  -354,  -354,  -354,  -354,    18,   306,     6,  -354,  -354,
      -8,   261,  -354,    71,   406,  -354,   445,  -149,  -354,  -238,
    -354,   324,   -75,   318,  -121,  -354,   519,  -354,   432,  -190,
       5,  -354,  -354,  -354,  -354,  -354,   343,  -354,    -5,   -15,
    -354,  -354,   461,  -354,   -55,   497,  -354,  -354,   173,  -354,
     264,  -354,   140,  -353,   182,  -354,   258,  -316,  -354,   557,
     -82,  -163,   610,   -69,  -354,  -354,   192,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -284,  -174,  -354,
     -29,  -354,    88,  -354,   136,   546,  -354,   440,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    21,    22,    53,   209,    24,    88,    26,    27,
      28,   186,   187,    49,   120,   121,   122,    50,   128,   129,
     130,   131,   273,   277,   123,    55,    56,   110,   210,   211,
     212,    59,   337,    31,    32,   134,   135,    33,   113,    38,
      34,   137,   138,   362,    89,    90,   254,   427,   255,    60,
      61,   230,   420,   342,   343,   344,   345,   249,   421,   213,
     108,   214,   215,    91,    41,   258,   364,   365,   511,   216,
     217,   218,   219,   220,   221,   404,   222,   331,   259,   260,
     223,   155,    93,   438,   439,   145,   378,    94,   262
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,   237,   140,    37,    52,   153,    30,    25,   300,   272,
      48,    36,   139,    92,   161,    97,    98,   183,    95,    23,
     323,    99,   100,   309,   167,   445,   418,    14,    25,    14,
      70,    25,    25,   256,   405,   124,   242,    14,   358,   383,
      54,    39,   102,   257,    70,    64,    65,    64,    65,   243,
      36,    14,   241,   326,   327,   328,   329,   330,   154,   333,
    -136,    25,     5,   156,     4,   177,    40,     6,   470,   338,
      68,    25,    29,    54,   114,   310,   395,     8,     9,   323,
     479,    47,   139,   127,   305,   276,   115,   231,   306,   348,
      51,    11,   235,   480,    58,    13,    14,   307,   423,    14,
      16,    36,    42,    17,   224,   141,    36,   424,     4,   228,
      64,    65,   261,   104,    25,    69,   238,   159,   239,   267,
     136,   103,   265,   105,    43,   109,   270,   392,     4,   484,
     124,    66,     4,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   290,   291,   292,   293,   294,   295,   296,   451,
      48,    44,   299,   261,   495,    45,   338,   384,   336,   287,
      18,    25,    19,    57,   276,   143,   144,    14,   312,    64,
      65,   149,   150,   151,   152,   489,   490,   320,   339,   225,
      18,   153,    19,   360,   238,   159,   239,   363,   275,    46,
     112,   226,   332,    14,   340,   361,    67,   379,   240,    71,
     341,  -103,     4,   132,   133,   346,   338,   152,   347,    96,
     253,    64,    65,   158,   159,   160,    25,   353,   354,   101,
     106,   338,   116,   357,    52,   158,   159,   160,   339,   275,
      48,    36,    36,   264,   154,   349,    72,    14,  -118,   369,
     374,   141,   371,   339,   340,    36,   142,   463,   359,   385,
     444,    25,     4,   146,   238,   159,   239,   278,   279,   340,
     388,   297,   298,   127,   102,  -158,   148,    36,   185,    47,
     381,     4,   261,   379,     4,    25,    72,    73,    74,    75,
     321,   399,     4,    25,   401,   402,   183,    14,   403,   332,
     184,   101,    77,    78,   190,   127,   335,   414,   415,    36,
      36,     4,   396,   397,    18,   179,    19,   180,    79,    14,
      51,   416,   191,    36,   422,    80,   227,    14,   245,    81,
      82,   152,  -135,   238,   159,   239,    18,    36,    19,   426,
     411,    62,    63,    87,    18,   236,    19,   376,   -84,   432,
     102,   232,   244,   287,   433,   181,   182,   252,   440,    64,
      65,   246,   192,    18,   247,    19,   248,   266,     5,   377,
     452,   363,   476,     6,   278,   279,   308,   382,   338,   301,
     271,   303,    36,     8,     9,   446,   162,   461,    36,   302,
     313,   450,   315,   165,   166,   167,   168,    11,   314,   317,
     339,    13,    14,    25,   316,   471,    16,   318,   319,    17,
     474,   324,   350,   356,    36,   127,   340,   464,   321,   459,
      25,   472,   469,   179,   366,   180,   250,   367,    36,   103,
     368,   172,   173,   174,   175,   176,   177,   167,   510,   370,
     332,   332,   165,   492,   167,   168,   493,   380,   422,    36,
      36,    36,   485,   486,   487,   386,   517,   391,   393,   499,
     398,   408,   501,   181,   182,   440,   477,   409,   435,   410,
     167,   168,   412,   417,    70,   428,   175,   176,   177,   512,
     430,   429,   431,   175,   176,   177,   448,   434,   436,   478,
      36,   441,   462,   504,   193,   443,    72,    73,    74,   194,
     195,    76,   447,   196,   197,     6,     7,   453,   253,   175,
     176,   177,    77,    78,   468,     8,     9,    10,   198,   454,
     199,   200,   201,   202,   203,   204,   205,   206,    79,    11,
     460,    12,   377,    13,    14,    80,   481,    15,    16,    81,
      82,    17,   482,   483,   488,   498,   497,   505,    83,    84,
      85,    86,   502,    87,   207,   514,   503,   106,   208,   193,
     506,    72,    73,    74,   194,   195,    76,   509,   196,   197,
       6,     7,   513,   515,   394,   274,   234,    77,    78,   352,
       8,     9,    10,   198,   111,   199,   200,   201,   202,   203,
     204,   205,   206,    79,    11,   157,    12,   269,    13,    14,
      80,   355,    15,    16,    81,    82,    17,   387,   251,   467,
     473,   413,   425,    83,    84,    85,    86,   494,    87,   207,
     107,    35,   106,   322,   193,   500,    72,    73,    74,   194,
     195,    76,   475,   196,   197,     6,     7,   147,   304,     0,
       0,     0,    77,    78,     0,     8,     9,    10,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,    79,    11,
       0,    12,     0,    13,    14,    80,     0,    15,    16,    81,
      82,    17,     0,     0,     0,     0,     0,     0,    83,    84,
      85,    86,     0,    87,   207,     0,     0,   106,   373,   193,
       0,    72,    73,    74,   194,   195,    76,     0,   196,   197,
       6,     7,     0,     0,     0,     0,     0,    77,    78,     0,
       8,     9,    10,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,    79,    11,     0,    12,     0,    13,    14,
      80,     0,    15,    16,    81,    82,    17,     0,     0,     0,
       0,     0,     0,    83,    84,    85,    86,     0,    87,   207,
       0,   193,   106,    72,    73,    74,   194,   325,    76,     0,
     196,   197,     0,     0,     0,     0,     0,     0,     0,    77,
      78,     0,     0,     0,     0,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,    79,     0,     0,    12,     0,
       0,     0,    80,     0,   162,   163,    81,    82,     0,     0,
     164,   165,   166,   167,   168,    83,    84,    85,    86,     0,
      87,   207,     0,     0,   106,    72,    73,    74,    75,     5,
      76,     0,     0,     0,     6,     0,     0,    14,    47,     0,
       0,    77,    78,     0,     8,     9,   170,   171,     0,   172,
     173,   174,   175,   176,   177,     0,    14,    79,    11,     0,
       0,     0,    13,    14,    80,     0,     0,    16,    81,    82,
      17,     0,     0,   158,   159,   160,     0,    83,    84,    85,
      86,     0,    87,     2,     3,     0,   106,     0,     0,     4,
       5,     0,     0,     0,     0,     6,     7,   165,   166,   167,
     168,     0,     0,     0,     0,     8,     9,    10,     0,     0,
       0,     0,     0,    72,    73,    74,    75,     0,    76,    11,
       0,    12,     0,    13,    14,     0,     0,    15,    16,    77,
      78,    17,    72,    73,    74,    75,     0,    76,   175,   176,
     177,    18,     0,    19,    20,    79,     0,     0,    77,    78,
       0,     0,    80,     0,     0,   101,    81,    82,     0,     0,
       0,     0,     0,     0,    79,    83,    84,    85,    86,     0,
      87,    80,     0,    14,   229,    81,    82,     0,    72,    73,
      74,    75,     0,    76,    83,    84,    85,    86,     0,    87,
     158,   159,   160,   376,    77,    78,     0,    72,    73,    74,
      75,     0,    76,     0,     0,     0,     0,     0,     0,     0,
      79,     0,     0,    77,    78,     0,     0,    80,   162,   163,
       0,    81,    82,     0,   164,   165,   166,   167,   168,    79,
      83,    84,    85,    86,     0,    87,    80,     0,     0,   419,
      81,    82,    72,    73,    74,    75,     0,    76,     0,    83,
      84,    85,    86,     0,    87,   311,     0,     0,    77,    78,
     170,   171,     0,   172,   173,   174,   175,   176,   177,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,    80,     0,     0,     0,    81,    82,   165,   166,   167,
     168,     0,     0,     0,    83,    84,    85,    86,     0,    87,
    -210,    72,    73,    74,    75,     5,    76,     0,     0,     0,
       6,     0,     0,     0,     0,     0,     0,    77,    78,     0,
       8,     9,     0,     0,     0,   172,   173,   174,   175,   176,
     177,   437,     0,    79,    11,     0,     5,     0,    13,    14,
      80,     6,     0,    16,    81,    82,    17,   165,   166,   167,
     168,     8,     9,    83,    84,    85,    86,     0,    87,    72,
      73,    74,    75,     5,    76,    11,     0,     0,     6,    13,
      14,     0,     0,     0,    16,    77,    78,    17,     8,     9,
       0,     0,     0,     0,     0,     0,   173,   174,   175,   176,
     177,    79,    11,     0,     0,     0,    13,    14,    80,     0,
       0,    16,    81,    82,    17,    72,    73,    74,    75,     0,
      76,    83,    84,    85,    86,   117,    87,     0,     0,     0,
       0,    77,    78,     0,     0,   118,     0,     0,     0,    72,
      73,    74,    75,     0,    76,     0,     0,    79,     0,   117,
       0,     0,     0,     0,    80,    77,    78,     0,    81,    82,
       0,     0,   165,   166,   167,   168,     0,    83,    84,    85,
     119,    79,    87,     0,     0,     0,     0,     0,    80,     0,
       0,     0,    81,    82,    72,    73,    74,    75,     0,    76,
       0,    83,    84,    85,   233,     0,    87,     0,     0,     0,
      77,    78,   174,   175,   176,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,     0,     0,    80,     0,     0,     0,    81,    82,    72,
      73,    74,    75,   289,    76,     0,    83,    84,    85,    86,
       0,    87,     0,     0,     0,    77,    78,     0,     0,   236,
       0,     0,     0,    72,    73,    74,    75,     0,    76,     0,
       0,    79,     0,     0,     0,     0,     0,     0,    80,    77,
      78,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    79,    87,     0,     0,     0,
       0,     0,    80,     0,     0,     0,    81,    82,    72,    73,
      74,    75,     0,    76,     0,    83,    84,    85,    86,     0,
      87,     0,     0,     0,    77,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,     5,     0,
      79,     0,     0,     6,     7,     0,     0,    80,     0,     0,
       0,    81,    82,     8,     9,    10,     0,     0,     0,     0,
      83,    84,    85,    86,     0,   263,     0,    11,     0,     0,
       0,    13,    14,     0,   162,   163,    16,     0,     0,    17,
     164,   165,   166,   167,   168,     0,     0,     0,     0,   162,
     163,     0,     0,   126,     0,   164,   165,   166,   167,   168,
     162,   163,     0,   465,     0,     0,   164,   165,   166,   167,
     168,     0,     0,     0,     0,   169,   170,   171,     0,   172,
     173,   174,   175,   176,   177,     0,     0,     0,     0,   466,
     169,   170,   171,     0,   172,   173,   174,   175,   176,   177,
       0,   169,   170,   171,   390,   172,   173,   174,   175,   176,
     177,   162,   163,     0,     0,   449,     0,   164,   165,   166,
     167,   168,   162,   163,   112,     0,     0,    14,   164,   165,
     166,   167,   168,   162,   163,  -113,  -113,     0,     0,   164,
     165,   166,   167,   168,     0,    64,    65,  -113,     0,     0,
       0,     0,   169,   170,   171,     0,   172,   173,   174,   175,
     176,   177,     0,   169,   170,   171,   466,   172,   173,   174,
     175,   176,   177,     0,   169,   170,   171,   508,   172,   173,
     174,   175,   176,   177,   162,   163,     0,   178,     0,     0,
     164,   165,   166,   167,   168,     0,     0,     0,   162,   163,
       0,     0,     0,     0,   164,   165,   166,   167,   168,     0,
       0,     0,   162,   163,     0,     0,     0,     0,   164,   165,
     166,   167,   168,     0,     0,   169,   170,   171,     0,   172,
     173,   174,   175,   176,   177,     0,     0,     0,   189,   169,
     170,   171,     0,   172,   173,   174,   175,   176,   177,     0,
       0,     0,   268,   169,   170,   171,     0,   172,   173,   174,
     175,   176,   177,   162,   163,     0,   456,     0,     0,   164,
     165,   166,   167,   168,     0,     0,     0,   162,   163,     0,
       0,     0,     0,   164,   165,   166,   167,   168,     0,     0,
       0,   162,   163,     0,     0,     0,     0,   164,   165,   166,
     167,   168,     0,     0,   169,   170,   171,     0,   172,   173,
     174,   175,   176,   177,     0,     0,     0,   457,   169,   170,
     171,     0,   172,   173,   174,   175,   176,   177,     0,     0,
       0,   458,   169,   170,   171,     0,   172,   173,   174,   175,
     176,   177,   162,   163,     0,   496,     0,     0,   164,   165,
     166,   167,   168,     0,     0,     0,   162,   163,     0,     0,
       0,     0,   164,   165,   166,   167,   168,     0,     0,     0,
     162,   163,     0,     0,     0,     0,   164,   165,   166,   167,
     168,     0,     0,   169,   170,   171,     0,   172,   173,   174,
     175,   176,   177,     0,     0,     0,   507,   169,   170,   171,
       0,   172,   173,   174,   175,   176,   177,     0,     0,     0,
     516,   169,   170,   171,     0,   172,   173,   174,   175,   176,
     177,   162,   163,   334,     0,     0,     0,   164,   165,   166,
     167,   168,     0,     0,   162,   163,     0,     0,     0,     0,
     164,   165,   166,   167,   168,     0,     0,   162,   163,     0,
       0,     0,     0,   164,   165,   166,   167,   168,     0,     0,
       0,     0,   169,   170,   171,     0,   172,   173,   174,   175,
     176,   177,     0,     0,   375,   169,   170,   171,     0,   172,
     173,   174,   175,   176,   177,     0,     0,   400,   169,   170,
     171,     0,   172,   173,   174,   175,   176,   177,   162,   163,
     442,     0,     0,     0,   164,   165,   166,   167,   168,     0,
       0,     0,     0,   162,   163,     0,     0,     0,     0,   164,
     165,   166,   167,   168,   162,   163,     0,     0,     0,     0,
     164,   165,   166,   167,   168,     0,     0,     0,     0,   169,
     170,   171,   406,   172,   173,   174,   175,   176,   177,     0,
       0,   455,     0,     0,   169,   170,   171,   407,   172,   173,
     174,   175,   176,   177,     0,   169,   170,   171,   389,   172,
     173,   174,   175,   176,   177,   162,   163,     0,     0,     0,
       0,   164,   165,   166,   167,   168,   162,   163,     0,     0,
       0,     0,   164,   165,   166,   167,   168,   162,   163,     0,
       0,     0,     0,   164,   165,   166,   167,   168,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   491,
     172,   173,   174,   175,   176,   177,     0,   188,   170,   171,
       0,   172,   173,   174,   175,   176,   177,     0,   169,   170,
     171,     0,   172,   173,   174,   175,   176,   177,   162,   163,
       0,     0,     0,     0,   164,   165,   166,   167,   168,   162,
     163,     0,     0,     0,     0,     0,   165,   166,   167,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   372,
     170,   171,     0,   172,   173,   174,   175,   176,   177,     0,
       0,     0,   171,     0,   172,   173,   174,   175,   176,   177,
       5,     0,     0,     0,     0,     6,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,     0,     0,
       5,     0,     0,     0,     0,     6,     7,     0,     0,    11,
     351,     0,     0,    13,    14,     8,     9,    10,    16,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,    11,
       5,     0,     0,    13,    14,     6,     7,    15,    16,     0,
       0,    17,     0,     0,     0,     8,     9,    10,     0,     0,
       5,     0,     0,     0,     0,     6,     0,     0,     0,    11,
       0,     0,     0,    13,    14,     8,     9,     0,    16,     0,
       0,    17,     0,     0,     0,     0,   437,     0,     0,    11,
       0,     0,     0,    13,    14,     0,     0,     0,    16,     0,
       0,    17
};

static const yytype_int16 yycheck[] =
{
       8,   122,    71,     8,    19,    87,     1,     1,   182,   158,
      18,    19,    67,    42,    89,    44,    45,     3,    42,     1,
     210,    45,    46,     6,    17,   378,   342,    41,    22,    41,
      38,    25,    26,    52,   318,    64,    49,    41,    52,   277,
      22,     6,    50,    62,    52,    59,    60,    59,    60,    62,
      58,    41,   127,   216,   217,   218,   219,   220,    87,   222,
      50,    55,     7,    87,     6,    58,    23,    12,   421,    21,
      61,    65,     1,    55,    49,    58,    62,    22,    23,   269,
      49,    23,   137,    65,    61,   160,    61,   116,    65,   238,
      19,    36,   121,    62,    23,    40,    41,    52,    50,    41,
      45,   109,    60,    48,   109,    60,   114,    59,     6,   114,
      59,    60,   141,    62,   108,     6,    58,    59,    60,   148,
      65,    50,   146,    52,    60,    54,   155,   301,     6,   445,
     159,    64,     6,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   387,
     158,    60,   181,   182,   470,    60,    21,   278,   227,   188,
      58,   155,    60,    61,   239,    77,    78,    41,   197,    59,
      60,    83,    84,    85,    86,   459,   460,   206,    43,    49,
      58,   263,    60,    49,    58,    59,    60,   256,    62,    60,
      38,    61,   221,    41,    59,    61,    64,   272,   127,    60,
      65,    64,     6,     6,     7,   234,    21,   119,   237,    60,
     139,    59,    60,    58,    59,    60,   210,   246,   247,    23,
      64,    21,    50,   252,   239,    58,    59,    60,    43,    62,
     238,   239,   240,   145,   263,   240,     3,    41,    64,   263,
     269,    60,   266,    43,    59,   253,     6,   410,   253,   278,
      65,   245,     6,    60,    58,    59,    60,    59,    60,    59,
     289,     6,     7,   245,   272,    65,    60,   275,     6,    23,
     275,     6,   301,   348,     6,   269,     3,     4,     5,     6,
     209,   310,     6,   277,   313,   314,     3,    41,   317,   318,
      62,    23,    19,    20,    62,   277,   225,     6,     7,   307,
     308,     6,   307,   308,    58,    19,    60,    21,    35,    41,
     239,   340,    62,   321,   343,    42,    60,    41,    49,    46,
      47,   233,    50,    58,    59,    60,    58,   335,    60,   358,
     335,    25,    26,    60,    58,    23,    60,    64,    63,   368,
     348,    63,    62,   372,   368,    59,    60,    52,   372,    59,
      60,    50,    62,    58,    50,    60,    49,    60,     7,   271,
     389,   430,   431,    12,    59,    60,    52,    62,    21,    60,
      62,    49,   380,    22,    23,   380,     8,   406,   386,    62,
      60,   386,    61,    15,    16,    17,    18,    36,    60,    60,
      43,    40,    41,   387,    61,   424,    45,    60,    52,    48,
     429,    61,     6,    65,   412,   387,    59,   412,   337,   404,
     404,   426,    65,    19,    62,    21,    65,    62,   426,   348,
      49,    53,    54,    55,    56,    57,    58,    17,   497,    49,
     459,   460,    15,   462,    17,    18,   465,    63,   467,   447,
     448,   449,   447,   448,   449,    62,   515,    62,    62,   478,
      61,    30,   481,    59,    60,   479,    62,    26,   370,    62,
      17,    18,    62,    49,   472,    61,    56,    57,    58,   498,
      52,    60,    49,    56,    57,    58,    63,    62,    62,    52,
     488,    62,    60,   488,     1,    65,     3,     4,     5,     6,
       7,     8,    62,    10,    11,    12,    13,    62,   427,    56,
      57,    58,    19,    20,    65,    22,    23,    24,    25,    61,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      61,    38,   434,    40,    41,    42,    52,    44,    45,    46,
      47,    48,    65,    62,    62,    60,    52,    61,    55,    56,
      57,    58,    62,    60,    61,    50,    65,    64,    65,     1,
      61,     3,     4,     5,     6,     7,     8,    65,    10,    11,
      12,    13,    61,    49,   303,   159,   121,    19,    20,   245,
      22,    23,    24,    25,    55,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    88,    38,   155,    40,    41,
      42,   248,    44,    45,    46,    47,    48,   279,   137,   417,
     427,   337,   344,    55,    56,    57,    58,   467,    60,    61,
      53,     1,    64,    65,     1,   479,     3,     4,     5,     6,
       7,     8,   430,    10,    11,    12,    13,    81,   188,    -1,
      -1,    -1,    19,    20,    -1,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    38,    -1,    40,    41,    42,    -1,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    60,    61,    -1,    -1,    64,    65,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    -1,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    60,    61,
      -1,     1,    64,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    38,    -1,
      -1,    -1,    42,    -1,     8,     9,    46,    47,    -1,    -1,
      14,    15,    16,    17,    18,    55,    56,    57,    58,    -1,
      60,    61,    -1,    -1,    64,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    -1,    41,    23,    -1,
      -1,    19,    20,    -1,    22,    23,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    -1,    41,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    45,    46,    47,
      48,    -1,    -1,    58,    59,    60,    -1,    55,    56,    57,
      58,    -1,    60,     0,     1,    -1,    64,    -1,    -1,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,    36,
      -1,    38,    -1,    40,    41,    -1,    -1,    44,    45,    19,
      20,    48,     3,     4,     5,     6,    -1,     8,    56,    57,
      58,    58,    -1,    60,    61,    35,    -1,    -1,    19,    20,
      -1,    -1,    42,    -1,    -1,    23,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    55,    56,    57,    58,    -1,
      60,    42,    -1,    41,    64,    46,    47,    -1,     3,     4,
       5,     6,    -1,     8,    55,    56,    57,    58,    -1,    60,
      58,    59,    60,    64,    19,    20,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    19,    20,    -1,    -1,    42,     8,     9,
      -1,    46,    47,    -1,    14,    15,    16,    17,    18,    35,
      55,    56,    57,    58,    -1,    60,    42,    -1,    -1,    64,
      46,    47,     3,     4,     5,     6,    -1,     8,    -1,    55,
      56,    57,    58,    -1,    60,    61,    -1,    -1,    19,    20,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    46,    47,    15,    16,    17,
      18,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    60,
      61,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,
      22,    23,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      58,    33,    -1,    35,    36,    -1,     7,    -1,    40,    41,
      42,    12,    -1,    45,    46,    47,    48,    15,    16,    17,
      18,    22,    23,    55,    56,    57,    58,    -1,    60,     3,
       4,     5,     6,     7,     8,    36,    -1,    -1,    12,    40,
      41,    -1,    -1,    -1,    45,    19,    20,    48,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,
      58,    35,    36,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,    45,    46,    47,    48,     3,     4,     5,     6,    -1,
       8,    55,    56,    57,    58,    13,    60,    -1,    -1,    -1,
      -1,    19,    20,    -1,    -1,    23,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    35,    -1,    13,
      -1,    -1,    -1,    -1,    42,    19,    20,    -1,    46,    47,
      -1,    -1,    15,    16,    17,    18,    -1,    55,    56,    57,
      58,    35,    60,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    46,    47,     3,     4,     5,     6,    -1,     8,
      -1,    55,    56,    57,    58,    -1,    60,    -1,    -1,    -1,
      19,    20,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,     3,
       4,     5,     6,    52,     8,    -1,    55,    56,    57,    58,
      -1,    60,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    19,
      20,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    35,    60,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    47,     3,     4,
       5,     6,    -1,     8,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,
      35,    -1,    -1,    12,    13,    -1,    -1,    42,    -1,    -1,
      -1,    46,    47,    22,    23,    24,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    60,    -1,    36,    -1,    -1,
      -1,    40,    41,    -1,     8,     9,    45,    -1,    -1,    48,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,     8,
       9,    -1,    -1,    62,    -1,    14,    15,    16,    17,    18,
       8,     9,    -1,    37,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      49,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      -1,    49,    50,    51,    63,    53,    54,    55,    56,    57,
      58,     8,     9,    -1,    -1,    63,    -1,    14,    15,    16,
      17,    18,     8,     9,    38,    -1,    -1,    41,    14,    15,
      16,    17,    18,     8,     9,    49,    50,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    -1,    49,    50,    51,    63,    53,    54,    55,
      56,    57,    58,    -1,    49,    50,    51,    63,    53,    54,
      55,    56,    57,    58,     8,     9,    -1,    62,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    49,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    62,    49,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    62,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,     8,     9,    -1,    62,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    -1,    -1,     8,     9,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,    -1,
      -1,     8,     9,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    62,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    62,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,     8,     9,    -1,    62,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    -1,    -1,    -1,    62,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      62,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,     8,     9,    61,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    -1,     8,     9,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    -1,    -1,    61,    49,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    -1,    -1,    61,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,     8,     9,
      61,    -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,     8,     9,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    49,
      50,    51,    37,    53,    54,    55,    56,    57,    58,    -1,
      -1,    61,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     8,     9,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    18,     8,     9,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,     8,     9,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    -1,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,     8,     9,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,     8,
       9,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    51,    -1,    53,    54,    55,    56,    57,    58,
       7,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,
       7,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    36,
      37,    -1,    -1,    40,    41,    22,    23,    24,    45,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
       7,    -1,    -1,    40,    41,    12,    13,    44,    45,    -1,
      -1,    48,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    40,    41,    22,    23,    -1,    45,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    33,    -1,    -1,    36,
      -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    45,    -1,
      -1,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,     0,     1,     6,     7,    12,    13,    22,    23,
      24,    36,    38,    40,    41,    44,    45,    48,    58,    60,
      61,    68,    69,    71,    72,    73,    74,    75,    76,    79,
      96,    99,   100,   103,   106,   128,    76,   104,   105,     6,
      23,   130,    60,    60,    60,    60,    60,    23,    76,    79,
      83,    79,   105,    70,    71,    91,    92,    61,    79,    97,
     115,   116,    72,    72,    59,    60,    64,    64,    61,     6,
      76,    60,     3,     4,     5,     6,     8,    19,    20,    35,
      42,    46,    47,    55,    56,    57,    58,    60,    73,   110,
     111,   129,   146,   148,   153,   154,    60,   146,   146,   154,
     154,    23,    76,    79,    62,    79,    64,   125,   126,    79,
      93,    92,    38,   104,    49,    61,    50,    13,    23,    58,
      80,    81,    82,    90,   146,     6,    62,    71,    84,    85,
      86,    87,     6,     7,   101,   102,    65,   107,   108,   110,
     129,    60,     6,   148,   148,   151,    60,   151,    60,   148,
     148,   148,   148,   126,   146,   147,   154,   111,    58,    59,
      60,    88,     8,     9,    14,    15,    16,    17,    18,    49,
      50,    51,    53,    54,    55,    56,    57,    58,    62,    19,
      21,    59,    60,     3,    62,     6,    77,    78,    49,    62,
      62,    62,    62,     1,     6,     7,    10,    11,    25,    27,
      28,    29,    30,    31,    32,    33,    34,    61,    65,    71,
      94,    95,    96,   125,   127,   128,   135,   136,   137,   138,
     139,   140,   142,   146,   104,    49,    61,    60,   104,    64,
     117,   146,    63,    58,    82,   146,    23,    90,    58,    60,
      79,    88,    49,    62,    62,    49,    50,    50,    49,   123,
      65,   108,    52,    79,   112,   114,    52,    62,   131,   144,
     145,   146,   154,    60,   148,   154,    60,   146,    62,    94,
     146,    62,    83,    88,    80,    62,    88,    89,    59,    60,
     146,   146,   146,   146,   146,   146,   146,   146,   146,    52,
     146,   146,   146,   146,   146,   146,   146,     6,     7,   146,
     144,    60,    62,    49,   153,    61,    65,    52,    52,     6,
      58,    61,   146,    60,    60,    61,    61,    60,    60,    52,
     146,    79,    65,    95,    61,     7,   127,   127,   127,   127,
     127,   143,   146,   127,    61,    79,   129,    98,    21,    43,
      59,    65,   119,   120,   121,   122,   146,   146,    83,   104,
       6,    37,    87,   146,   146,   102,    65,   146,    52,   104,
      49,    61,   109,   129,   132,   133,    62,    62,    49,   154,
      49,   154,    49,    65,   146,    61,    64,   148,   152,    88,
      63,   104,    62,    85,    90,   146,    62,    89,   146,    52,
      63,    62,   144,    62,    77,    62,   104,   104,    61,   146,
      61,   146,   146,   146,   141,   143,    37,    52,    30,    26,
      62,   104,    62,   116,     6,     7,   146,    49,   123,    64,
     118,   124,   146,    50,    59,   122,   146,   113,    61,    60,
      52,    49,   146,   154,    62,   148,    62,    33,   149,   150,
     154,    62,    61,    65,    65,   119,   104,    62,    63,    63,
     104,    85,   146,    62,    61,    61,    62,    62,    62,    96,
      61,   146,    60,   127,   104,    37,    63,   120,    65,    65,
     119,   146,   105,   114,   146,   132,   129,    62,    52,    49,
      62,    52,    65,    62,   123,   104,   104,   104,    62,   143,
     143,    52,   146,   146,   118,   123,    62,    52,    60,   146,
     150,   146,    62,    65,   104,    61,    61,    62,    63,    65,
     129,   134,   146,    61,    50,    49,    62,   129
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    68,    68,    68,    69,
      69,    70,    70,    71,    72,    72,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      74,    75,    75,    76,    77,    77,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    80,    80,
      80,    80,    80,    80,    80,    81,    82,    83,    83,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    89,    90,    90,    91,    91,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    96,    97,    98,    97,
      99,    99,   100,   100,   101,   101,   102,   102,   102,   102,
     103,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     107,   108,   109,   109,   110,   111,   111,   112,   113,   112,
     114,   114,   114,   114,   114,   115,   115,   116,   116,   116,
     116,   116,   117,   118,   118,   118,   119,   119,   120,   120,
     120,   120,   121,   121,   122,   122,   122,   123,   123,   124,
     125,   125,   126,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   128,   128,   129,   130,   130,   131,   131,   131,
     132,   132,   133,   133,   134,   134,   135,   135,   135,   135,
     135,   136,   137,   138,   139,   140,   141,   140,   142,   143,
     143,   144,   144,   145,   145,   145,   145,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   147,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   149,   149,   150,   150,   151,
     152,   153,   153,   154,   154
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     3,     1,     2,     1,     1,     1,
       2,     0,     1,     1,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     4,     4,     1,     4,     1,     1,
       1,     4,     4,     6,     1,     3,     0,     1,     4,     2,
       3,     1,     4,     3,     4,     4,     4,     3,     1,     1,
       2,     3,     3,     1,     2,     1,     1,     1,     2,     1,
       2,     1,     3,     1,     3,     1,     3,     3,     2,     1,
       1,     2,     2,     3,     3,     4,     5,     5,     3,     5,
       4,     6,     0,     0,     1,     1,     2,     3,     2,     4,
       1,     2,     1,     1,     2,     3,     7,     1,     0,     5,
       5,     2,     1,     2,     1,     3,     1,     1,     3,     3,
       4,     3,     3,     0,     1,     1,     2,     2,     3,     1,
       2,     3,     1,     2,     1,     2,     1,     1,     0,     4,
       2,     2,     3,     4,     0,     2,     5,     2,     6,     3,
       6,     4,     1,     1,     4,     2,     2,     4,     2,     1,
       6,     0,     1,     2,     3,     2,     2,     0,     1,     1,
       3,     2,     1,     2,     1,     2,     2,     2,     7,     4,
       2,     2,     2,     2,     3,     3,     4,     2,     1,     2,
       2,     2,     5,     6,     1,     0,     1,     2,     4,     6,
       0,     1,     4,     6,     1,     3,     3,     3,     3,     5,
       2,     1,     4,     3,     4,     6,     0,     6,     4,     1,
       0,     0,     1,     1,     3,     3,     1,     3,     3,     3,
       5,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     3,     4,     5,     5,     7,     5,     4,
       4,     4,     3,     3,     1,     6,     1,     1,     1,     3,
       6,     7,     5,     2,     6,     1,     3,     3,     3,     0,
       1,     1,     2,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
    YYNOMEM;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* ext_def_list: %empty  */
#line 295 "./cgram.y"
                  { ftnend(); }
#line 2185 "y.tab.c"
    break;

  case 4: /* external_def: funtype kr_args compoundstmt  */
#line 298 "./cgram.y"
                                                { fend(); }
#line 2191 "y.tab.c"
    break;

  case 5: /* external_def: declaration  */
#line 299 "./cgram.y"
                                { blevel = 0; symclear(0); }
#line 2197 "y.tab.c"
    break;

  case 8: /* external_def: error  */
#line 302 "./cgram.y"
                         { blevel = 0; }
#line 2203 "y.tab.c"
    break;

  case 9: /* funtype: declarator  */
#line 305 "./cgram.y"
                                                 {
		    fundef(mkty(INT, 0, 0), (yyvsp[0].nodep));
		    cftnsp->sflags |= NORETYP;
		}
#line 2212 "y.tab.c"
    break;

  case 10: /* funtype: declaration_specifiers declarator  */
#line 309 "./cgram.y"
                                                    { fundef((yyvsp[-1].nodep),(yyvsp[0].nodep)); }
#line 2218 "y.tab.c"
    break;

  case 13: /* declaration_specifiers: merge_attribs  */
#line 322 "./cgram.y"
                                 { (yyval.nodep) = typenode((yyvsp[0].nodep)); }
#line 2224 "y.tab.c"
    break;

  case 14: /* merge_attribs: type_sq  */
#line 325 "./cgram.y"
                           { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2230 "y.tab.c"
    break;

  case 15: /* merge_attribs: type_sq merge_attribs  */
#line 326 "./cgram.y"
                                         { (yyval.nodep) = cmop((yyvsp[0].nodep), (yyvsp[-1].nodep)); }
#line 2236 "y.tab.c"
    break;

  case 16: /* merge_attribs: cf_spec  */
#line 327 "./cgram.y"
                           { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2242 "y.tab.c"
    break;

  case 17: /* merge_attribs: cf_spec merge_attribs  */
#line 328 "./cgram.y"
                                         { (yyval.nodep) = cmop((yyvsp[0].nodep), (yyvsp[-1].nodep)); }
#line 2248 "y.tab.c"
    break;

  case 18: /* type_sq: C_TYPE  */
#line 331 "./cgram.y"
                          { (yyval.nodep) = mkty((yyvsp[0].type), 0, 0); }
#line 2254 "y.tab.c"
    break;

  case 19: /* type_sq: C_TYPENAME  */
#line 332 "./cgram.y"
                              { 
			struct symtab *sp = lookup((yyvsp[0].strp), 0);
			if (sp->stype == ENUMTY) {
				sp->stype = strmemb(sp->td->ss)->stype;
			}
			(yyval.nodep) = mkty(sp->stype, sp->sdf, sp->sss);
			(yyval.nodep)->n_sp = sp;
		}
#line 2267 "y.tab.c"
    break;

  case 20: /* type_sq: struct_dcl  */
#line 340 "./cgram.y"
                              { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2273 "y.tab.c"
    break;

  case 21: /* type_sq: enum_dcl  */
#line 341 "./cgram.y"
                            { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2279 "y.tab.c"
    break;

  case 22: /* type_sq: C_QUALIFIER  */
#line 342 "./cgram.y"
                               { (yyval.nodep) = block(QUALIFIER, NULL, NULL, 0, 0, 0); (yyval.nodep)->n_qual = (yyvsp[0].type); }
#line 2285 "y.tab.c"
    break;

  case 23: /* type_sq: attribute_specifier  */
#line 343 "./cgram.y"
                                       { (yyval.nodep) = biop(ATTRIB, (yyvsp[0].nodep), 0); }
#line 2291 "y.tab.c"
    break;

  case 24: /* type_sq: C_ALIGNAS '(' e ')'  */
#line 344 "./cgram.y"
                                       { 
			(yyval.nodep) = biop(ALIGN, NULL, NULL);
			slval((yyval.nodep), con_e((yyvsp[-1].nodep)));
		}
#line 2300 "y.tab.c"
    break;

  case 25: /* type_sq: C_ALIGNAS '(' cast_type ')'  */
#line 348 "./cgram.y"
                                               {
			TYMFIX((yyvsp[-1].nodep));
			(yyval.nodep) = biop(ALIGN, NULL, NULL);
			slval((yyval.nodep), talign((yyvsp[-1].nodep)->n_type, (yyvsp[-1].nodep)->pss)/SZCHAR);
			p1tfree((yyvsp[-1].nodep));
		}
#line 2311 "y.tab.c"
    break;

  case 26: /* type_sq: C_ATOMIC  */
#line 354 "./cgram.y"
                            { uerror("_Atomic not supported"); (yyval.nodep) = bcon(0); }
#line 2317 "y.tab.c"
    break;

  case 27: /* type_sq: C_ATOMIC '(' cast_type ')'  */
#line 355 "./cgram.y"
                                              {
			uerror("_Atomic not supported"); (yyval.nodep) = (yyvsp[-1].nodep);
		}
#line 2325 "y.tab.c"
    break;

  case 28: /* type_sq: typeof  */
#line 358 "./cgram.y"
                          { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2331 "y.tab.c"
    break;

  case 29: /* cf_spec: C_CLASS  */
#line 361 "./cgram.y"
                           { (yyval.nodep) = block(CLASS, NULL, NULL, (yyvsp[0].type), 0, 0); }
#line 2337 "y.tab.c"
    break;

  case 30: /* cf_spec: C_FUNSPEC  */
#line 362 "./cgram.y"
                             { (yyval.nodep) = block(FUNSPEC, NULL, NULL, (yyvsp[0].type), 0, 0); }
#line 2343 "y.tab.c"
    break;

  case 31: /* typeof: C_TYPEOF '(' e ')'  */
#line 365 "./cgram.y"
                                      { (yyval.nodep) = tyof(eve((yyvsp[-1].nodep))); }
#line 2349 "y.tab.c"
    break;

  case 32: /* typeof: C_TYPEOF '(' cast_type ')'  */
#line 366 "./cgram.y"
                                              { TYMFIX((yyvsp[-1].nodep)); (yyval.nodep) = tyof((yyvsp[-1].nodep)); }
#line 2355 "y.tab.c"
    break;

  case 33: /* attribute_specifier: C_ATTRIBUTE '(' '(' attribute_list ')' ')'  */
#line 370 "./cgram.y"
                                                              { (yyval.nodep) = (yyvsp[-2].nodep); }
#line 2361 "y.tab.c"
    break;

  case 35: /* attribute_list: attribute ',' attribute_list  */
#line 374 "./cgram.y"
                                                { (yyval.nodep) = cmop((yyvsp[0].nodep), (yyvsp[-2].nodep)); }
#line 2367 "y.tab.c"
    break;

  case 36: /* attribute: %empty  */
#line 377 "./cgram.y"
                   {
#ifdef GCC_COMPAT
			 (yyval.nodep) = voidcon();
#endif
		}
#line 2377 "y.tab.c"
    break;

  case 37: /* attribute: C_NAME  */
#line 382 "./cgram.y"
                          { (yyval.nodep) = bdty(NAME, (yyvsp[0].strp)); }
#line 2383 "y.tab.c"
    break;

  case 38: /* attribute: C_NAME '(' elist ')'  */
#line 383 "./cgram.y"
                                        {
			(yyval.nodep) = bdty((yyvsp[-1].nodep) == NULL ? UCALL : CALL, bdty(NAME, (yyvsp[-3].strp)), (yyvsp[-1].nodep));
		}
#line 2391 "y.tab.c"
    break;

  case 39: /* declarator: '*' declarator  */
#line 391 "./cgram.y"
                                  { (yyval.nodep) = bdty(UMUL, (yyvsp[0].nodep)); }
#line 2397 "y.tab.c"
    break;

  case 40: /* declarator: '*' type_qualifier_list declarator  */
#line 392 "./cgram.y"
                                                      {
			(yyval.nodep) = (yyvsp[-1].nodep);
			(yyval.nodep)->n_left = (yyvsp[0].nodep);
		}
#line 2406 "y.tab.c"
    break;

  case 41: /* declarator: C_NAME  */
#line 396 "./cgram.y"
                          { (yyval.nodep) = bdty(NAME, (yyvsp[0].strp)); }
#line 2412 "y.tab.c"
    break;

  case 42: /* declarator: '(' attr_spec_list declarator ')'  */
#line 397 "./cgram.y"
                                                     {
			(yyval.nodep) = (yyvsp[-1].nodep);
			(yyval.nodep)->n_ap = attr_add((yyval.nodep)->n_ap, gcc_attr_wrapper((yyvsp[-2].nodep)));
		}
#line 2421 "y.tab.c"
    break;

  case 43: /* declarator: '(' declarator ')'  */
#line 401 "./cgram.y"
                                      { (yyval.nodep) = (yyvsp[-1].nodep); }
#line 2427 "y.tab.c"
    break;

  case 44: /* declarator: declarator '[' ecq ']'  */
#line 402 "./cgram.y"
                                          { (yyval.nodep) = biop(LB, (yyvsp[-3].nodep), (yyvsp[-1].nodep)); }
#line 2433 "y.tab.c"
    break;

  case 45: /* declarator: declarator '(' parameter_type_list ')'  */
#line 403 "./cgram.y"
                                                          {
			(yyval.nodep) = bdty(CALL, (yyvsp[-3].nodep), (yyvsp[-1].nodep));
		}
#line 2441 "y.tab.c"
    break;

  case 46: /* declarator: declarator '(' identifier_list ')'  */
#line 406 "./cgram.y"
                                                      {
			(yyval.nodep) = bdty(CALL, (yyvsp[-3].nodep), (yyvsp[-1].nodep));
			oldstyle = 1;
		}
#line 2450 "y.tab.c"
    break;

  case 47: /* declarator: declarator '(' ')'  */
#line 410 "./cgram.y"
                                      { (yyval.nodep) = bdty(UCALL, (yyvsp[-2].nodep)); }
#line 2456 "y.tab.c"
    break;

  case 48: /* ecq: maybe_r  */
#line 413 "./cgram.y"
                           { (yyval.nodep) = bcon(NOOFFSET); }
#line 2462 "y.tab.c"
    break;

  case 49: /* ecq: e  */
#line 414 "./cgram.y"
                      { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2468 "y.tab.c"
    break;

  case 50: /* ecq: r e  */
#line 415 "./cgram.y"
                       { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2474 "y.tab.c"
    break;

  case 51: /* ecq: c maybe_r e  */
#line 416 "./cgram.y"
                               { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2480 "y.tab.c"
    break;

  case 52: /* ecq: r c e  */
#line 417 "./cgram.y"
                         { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2486 "y.tab.c"
    break;

  case 53: /* ecq: '*'  */
#line 418 "./cgram.y"
                       { (yyval.nodep) = bcon(NOOFFSET); }
#line 2492 "y.tab.c"
    break;

  case 54: /* ecq: r '*'  */
#line 419 "./cgram.y"
                         { (yyval.nodep) = bcon(NOOFFSET); }
#line 2498 "y.tab.c"
    break;

  case 55: /* r: C_QUALIFIER  */
#line 422 "./cgram.y"
                              {
			if ((yyvsp[0].type) != 0)
				uerror("bad qualifier");
		}
#line 2507 "y.tab.c"
    break;

  case 56: /* c: C_CLASS  */
#line 428 "./cgram.y"
                          {
			if ((yyvsp[0].type) != STATIC)
				uerror("bad class keyword");
		}
#line 2516 "y.tab.c"
    break;

  case 57: /* type_qualifier_list: C_QUALIFIER  */
#line 435 "./cgram.y"
                               { (yyval.nodep) = biop(UMUL, 0, 0); (yyval.nodep)->n_qual = (yyvsp[0].type); }
#line 2522 "y.tab.c"
    break;

  case 58: /* type_qualifier_list: type_qualifier_list C_QUALIFIER  */
#line 436 "./cgram.y"
                                                   {
			(yyval.nodep) = (yyvsp[-1].nodep);
			(yyval.nodep)->n_qual |= (yyvsp[0].type);
		}
#line 2531 "y.tab.c"
    break;

  case 59: /* type_qualifier_list: attribute_specifier  */
#line 440 "./cgram.y"
                                       {
			(yyval.nodep) = block(UMUL, NULL, NULL, 0, 0, 0);
			(yyval.nodep)->n_ap = gcc_attr_wrapper((yyvsp[0].nodep));
		}
#line 2540 "y.tab.c"
    break;

  case 60: /* type_qualifier_list: type_qualifier_list attribute_specifier  */
#line 444 "./cgram.y"
                                                           {
			(yyvsp[-1].nodep)->n_ap = attr_add((yyvsp[-1].nodep)->n_ap, gcc_attr_wrapper((yyvsp[0].nodep)));
		}
#line 2548 "y.tab.c"
    break;

  case 61: /* identifier_list: C_NAME  */
#line 449 "./cgram.y"
                          { (yyval.nodep) = bdty(NAME, (yyvsp[0].strp)); oldargs((yyval.nodep)); }
#line 2554 "y.tab.c"
    break;

  case 62: /* identifier_list: identifier_list ',' C_NAME  */
#line 450 "./cgram.y"
                                              {
			(yyval.nodep) = cmop((yyvsp[-2].nodep), bdty(NAME, (yyvsp[0].strp)));
			oldargs((yyval.nodep)->n_right);
		}
#line 2563 "y.tab.c"
    break;

  case 63: /* parameter_type_list: parameter_list  */
#line 460 "./cgram.y"
                                  { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2569 "y.tab.c"
    break;

  case 64: /* parameter_type_list: parameter_list ',' C_ELLIPSIS  */
#line 461 "./cgram.y"
                                                 {
			(yyval.nodep) = cmop((yyvsp[-2].nodep), biop(ELLIPSIS, NULL, NULL));
		}
#line 2577 "y.tab.c"
    break;

  case 65: /* parameter_list: parameter_declaration  */
#line 471 "./cgram.y"
                                         { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2583 "y.tab.c"
    break;

  case 66: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 472 "./cgram.y"
                                                            {
			(yyval.nodep) = cmop((yyvsp[-2].nodep), (yyvsp[0].nodep));
		}
#line 2591 "y.tab.c"
    break;

  case 67: /* parameter_declaration: declaration_specifiers declarator attr_var  */
#line 481 "./cgram.y"
                                                              {
			if (glval((yyvsp[-2].nodep)) != SNULL && glval((yyvsp[-2].nodep)) != REGISTER)
				uerror("illegal parameter class");
			(yyval.nodep) = block(TYMERGE, (yyvsp[-2].nodep), (yyvsp[-1].nodep), INT, 0, 0);
			(yyval.nodep)->n_ap = gcc_attr_wrapper((yyvsp[0].nodep));
		}
#line 2602 "y.tab.c"
    break;

  case 68: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 487 "./cgram.y"
                                                              { 
			(yyvsp[-1].nodep)->n_ap = attr_add((yyvsp[-1].nodep)->n_ap, (yyvsp[0].nodep)->n_ap);
			(yyval.nodep) = block(TYMERGE, (yyvsp[-1].nodep), (yyvsp[0].nodep), INT, 0, 0);
		}
#line 2611 "y.tab.c"
    break;

  case 69: /* parameter_declaration: declaration_specifiers  */
#line 491 "./cgram.y"
                                          {
			(yyval.nodep) = block(TYMERGE, (yyvsp[0].nodep), bdty(NAME, NULL), INT, 0, 0);
		}
#line 2619 "y.tab.c"
    break;

  case 70: /* abstract_declarator: '*'  */
#line 497 "./cgram.y"
                       { (yyval.nodep) = bdty(UMUL, bdty(NAME, NULL)); }
#line 2625 "y.tab.c"
    break;

  case 71: /* abstract_declarator: '*' type_qualifier_list  */
#line 498 "./cgram.y"
                                           {
			(yyval.nodep) = (yyvsp[0].nodep);
			(yyval.nodep)->n_left = bdty(NAME, NULL);
		}
#line 2634 "y.tab.c"
    break;

  case 72: /* abstract_declarator: '*' abstract_declarator  */
#line 502 "./cgram.y"
                                           { (yyval.nodep) = bdty(UMUL, (yyvsp[0].nodep)); }
#line 2640 "y.tab.c"
    break;

  case 73: /* abstract_declarator: '*' type_qualifier_list abstract_declarator  */
#line 503 "./cgram.y"
                                                               {
			(yyval.nodep) = (yyvsp[-1].nodep);
			(yyval.nodep)->n_left = (yyvsp[0].nodep);
		}
#line 2649 "y.tab.c"
    break;

  case 74: /* abstract_declarator: '(' abstract_declarator ')'  */
#line 507 "./cgram.y"
                                               { (yyval.nodep) = (yyvsp[-1].nodep); }
#line 2655 "y.tab.c"
    break;

  case 75: /* abstract_declarator: '[' ecq ']' attr_var  */
#line 508 "./cgram.y"
                                        {
			(yyval.nodep) = block(LB, bdty(NAME, NULL), (yyvsp[-2].nodep), INT, 0, 0);
			(yyval.nodep)->n_ap = gcc_attr_wrapper((yyvsp[0].nodep));
		}
#line 2664 "y.tab.c"
    break;

  case 76: /* abstract_declarator: abstract_declarator '[' maybe_r ']' attr_var  */
#line 512 "./cgram.y"
                                                                {
			(yyval.nodep) = block(LB, (yyvsp[-4].nodep), bcon(NOOFFSET), INT, 0, 0);
			(yyval.nodep)->n_ap = gcc_attr_wrapper((yyvsp[0].nodep));
		}
#line 2673 "y.tab.c"
    break;

  case 77: /* abstract_declarator: abstract_declarator '[' e ']' attr_var  */
#line 516 "./cgram.y"
                                                          {
			(yyval.nodep) = block(LB, (yyvsp[-4].nodep), (yyvsp[-2].nodep), INT, 0, 0);
			(yyval.nodep)->n_ap = gcc_attr_wrapper((yyvsp[0].nodep));
		}
#line 2682 "y.tab.c"
    break;

  case 78: /* abstract_declarator: '(' ')' attr_var  */
#line 520 "./cgram.y"
                                    {
			(yyval.nodep) = bdty(UCALL, bdty(NAME, NULL));
			(yyval.nodep)->n_ap = gcc_attr_wrapper((yyvsp[0].nodep));
		}
#line 2691 "y.tab.c"
    break;

  case 79: /* abstract_declarator: '(' ib2 parameter_type_list ')' attr_var  */
#line 524 "./cgram.y"
                                                            {
			(yyval.nodep) = block(CALL, bdty(NAME, NULL), (yyvsp[-2].nodep), INT, 0, 0);
			(yyval.nodep)->n_ap = gcc_attr_wrapper((yyvsp[0].nodep));
		}
#line 2700 "y.tab.c"
    break;

  case 80: /* abstract_declarator: abstract_declarator '(' ')' attr_var  */
#line 528 "./cgram.y"
                                                        {
			(yyval.nodep) = block(UCALL, (yyvsp[-3].nodep), NULL, INT, 0, 0);
			(yyval.nodep)->n_ap = gcc_attr_wrapper((yyvsp[0].nodep));
		}
#line 2709 "y.tab.c"
    break;

  case 81: /* abstract_declarator: abstract_declarator '(' ib2 parameter_type_list ')' attr_var  */
#line 532 "./cgram.y"
                                                                                {
			(yyval.nodep) = block(CALL, (yyvsp[-5].nodep), (yyvsp[-2].nodep), INT, 0, 0);
			(yyval.nodep)->n_ap = gcc_attr_wrapper((yyvsp[0].nodep));
		}
#line 2718 "y.tab.c"
    break;

  case 82: /* ib2: %empty  */
#line 538 "./cgram.y"
                   { }
#line 2724 "y.tab.c"
    break;

  case 83: /* maybe_r: %empty  */
#line 541 "./cgram.y"
                   { }
#line 2730 "y.tab.c"
    break;

  case 84: /* maybe_r: C_QUALIFIER  */
#line 542 "./cgram.y"
                               { }
#line 2736 "y.tab.c"
    break;

  case 87: /* arg_declaration: declaration_specifiers arg_param_list ';'  */
#line 553 "./cgram.y"
                                                             {
			p1nfree((yyvsp[-2].nodep));
		}
#line 2744 "y.tab.c"
    break;

  case 88: /* arg_param_list: declarator attr_var  */
#line 558 "./cgram.y"
                                       {
			olddecl(block(TYMERGE, p1tcopy((yyvsp[-2].nodep)), (yyvsp[-1].nodep),
			    INT, 0, 0), (yyvsp[0].nodep));
		}
#line 2753 "y.tab.c"
    break;

  case 89: /* arg_param_list: arg_param_list ',' declarator attr_var  */
#line 562 "./cgram.y"
                                                          {
			olddecl(block(TYMERGE, p1tcopy((yyvsp[-4].nodep)), (yyvsp[-1].nodep),
			    INT, 0, 0), (yyvsp[0].nodep));
		}
#line 2762 "y.tab.c"
    break;

  case 93: /* block_item: statement  */
#line 576 "./cgram.y"
                             { stmtfree(); }
#line 2768 "y.tab.c"
    break;

  case 94: /* declaration: declaration_specifiers ';'  */
#line 586 "./cgram.y"
                                              { p1tfree((yyvsp[-1].nodep)); fun_inline = 0; }
#line 2774 "y.tab.c"
    break;

  case 95: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 587 "./cgram.y"
                                                                   {
			p1tfree((yyvsp[-2].nodep));
			fun_inline = 0;
		}
#line 2783 "y.tab.c"
    break;

  case 96: /* declaration: C_STATICASSERT '(' e ',' string ')' ';'  */
#line 591 "./cgram.y"
                                                           {
			int r = con_e((yyvsp[-4].nodep));
			if (r == 0) /* false */
				uerror((yyvsp[-2].strp));
		}
#line 2793 "y.tab.c"
    break;

  case 97: /* init_declarator_list: init_declarator  */
#line 603 "./cgram.y"
                                   { symclear(blevel); }
#line 2799 "y.tab.c"
    break;

  case 98: /* @1: %empty  */
#line 604 "./cgram.y"
                                                     { (yyval.nodep) = (yyvsp[-3].nodep); }
#line 2805 "y.tab.c"
    break;

  case 99: /* init_declarator_list: init_declarator_list ',' attr_var @1 init_declarator  */
#line 604 "./cgram.y"
                                                                                                {
			uawarn((yyvsp[-2].nodep), "init_declarator");
			symclear(blevel);
		}
#line 2814 "y.tab.c"
    break;

  case 100: /* enum_dcl: enum_head '{' moe_list optcomma '}'  */
#line 610 "./cgram.y"
                                                       { (yyval.nodep) = enumdcl((yyvsp[-4].symp)); }
#line 2820 "y.tab.c"
    break;

  case 101: /* enum_dcl: C_ENUM C_NAME  */
#line 611 "./cgram.y"
                                 {  (yyval.nodep) = enumref((yyvsp[0].strp)); }
#line 2826 "y.tab.c"
    break;

  case 102: /* enum_head: C_ENUM  */
#line 614 "./cgram.y"
                          { (yyval.symp) = enumhd(NULL); }
#line 2832 "y.tab.c"
    break;

  case 103: /* enum_head: C_ENUM C_NAME  */
#line 615 "./cgram.y"
                                 {  (yyval.symp) = enumhd((yyvsp[0].strp)); }
#line 2838 "y.tab.c"
    break;

  case 104: /* moe_list: moe  */
#line 618 "./cgram.y"
                       { moedef((yyvsp[0].strp), enummer++); }
#line 2844 "y.tab.c"
    break;

  case 105: /* moe_list: moe_list ',' moe  */
#line 619 "./cgram.y"
                                    { moedef((yyvsp[0].strp), enummer++); }
#line 2850 "y.tab.c"
    break;

  case 108: /* moe: C_NAME '=' e  */
#line 624 "./cgram.y"
                                { enummer = con_e((yyvsp[0].nodep)); (yyval.strp) = (yyvsp[-2].strp); }
#line 2856 "y.tab.c"
    break;

  case 109: /* moe: C_TYPENAME '=' e  */
#line 625 "./cgram.y"
                                    { enummer = con_e((yyvsp[0].nodep)); (yyval.strp) = (yyvsp[-2].strp); }
#line 2862 "y.tab.c"
    break;

  case 110: /* struct_dcl: str_head '{' struct_dcl_list '}'  */
#line 628 "./cgram.y"
                                                    {
			P1ND *p;

			(yyval.nodep) = dclstruct((yyvsp[-3].rp));
			if (pragma_allpacked) {
				p = bdty(CALL, bdty(NAME, "packed"),
				    bcon(pragma_allpacked));
				(yyval.nodep)->n_ap = attr_add((yyval.nodep)->n_ap,gcc_attr_wrapper(p)); }
		}
#line 2876 "y.tab.c"
    break;

  case 111: /* struct_dcl: C_STRUCT attr_var C_NAME  */
#line 637 "./cgram.y"
                                            { 
			(yyval.nodep) = rstruct((yyvsp[0].strp),(yyvsp[-2].intval));
			uawarn((yyvsp[-1].nodep), "struct_dcl");
		}
#line 2885 "y.tab.c"
    break;

  case 112: /* struct_dcl: str_head '{' '}'  */
#line 641 "./cgram.y"
                                    { (yyval.nodep) = dclstruct((yyvsp[-2].rp)); }
#line 2891 "y.tab.c"
    break;

  case 113: /* attr_var: %empty  */
#line 644 "./cgram.y"
                   {	
			P1ND *q, *p;

			p = pragma_aligned ? bdty(CALL, bdty(NAME, "aligned"),
			    bcon(pragma_aligned)) : NULL;
			if (pragma_packed) {
				q = bdty(NAME, "packed");
				p = (p == NULL ? q : cmop(p, q));
			}
			pragma_aligned = pragma_packed = 0;
			(yyval.nodep) = p;
		}
#line 2908 "y.tab.c"
    break;

  case 116: /* attr_spec_list: attr_spec_list attribute_specifier  */
#line 660 "./cgram.y"
                                                      { (yyval.nodep) = cmop((yyvsp[-1].nodep), (yyvsp[0].nodep)); }
#line 2914 "y.tab.c"
    break;

  case 117: /* str_head: C_STRUCT attr_var  */
#line 663 "./cgram.y"
                                     {  (yyval.rp) = bstruct(NULL, (yyvsp[-1].intval), (yyvsp[0].nodep));  }
#line 2920 "y.tab.c"
    break;

  case 118: /* str_head: C_STRUCT attr_var C_NAME  */
#line 664 "./cgram.y"
                                            {  (yyval.rp) = bstruct((yyvsp[0].strp), (yyvsp[-2].intval), (yyvsp[-1].nodep));  }
#line 2926 "y.tab.c"
    break;

  case 121: /* struct_declaration: specifier_qualifier_list struct_declarator_list optsemi  */
#line 672 "./cgram.y"
                                                                           {
			p1tfree((yyvsp[-2].nodep));
		}
#line 2934 "y.tab.c"
    break;

  case 122: /* optsemi: ';'  */
#line 677 "./cgram.y"
                       { }
#line 2940 "y.tab.c"
    break;

  case 123: /* optsemi: optsemi ';'  */
#line 678 "./cgram.y"
                               { werror("extra ; in struct"); }
#line 2946 "y.tab.c"
    break;

  case 124: /* specifier_qualifier_list: merge_specifiers  */
#line 682 "./cgram.y"
                                    { (yyval.nodep) = typenode((yyvsp[0].nodep)); }
#line 2952 "y.tab.c"
    break;

  case 125: /* merge_specifiers: type_sq merge_specifiers  */
#line 685 "./cgram.y"
                                            { (yyval.nodep) = cmop((yyvsp[0].nodep), (yyvsp[-1].nodep)); }
#line 2958 "y.tab.c"
    break;

  case 126: /* merge_specifiers: type_sq  */
#line 686 "./cgram.y"
                           { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2964 "y.tab.c"
    break;

  case 127: /* struct_declarator_list: struct_declarator  */
#line 690 "./cgram.y"
                                     { symclear(blevel); }
#line 2970 "y.tab.c"
    break;

  case 128: /* @2: %empty  */
#line 691 "./cgram.y"
                                              { (yyval.nodep)=(yyvsp[-2].nodep); }
#line 2976 "y.tab.c"
    break;

  case 129: /* struct_declarator_list: struct_declarator_list ',' @2 struct_declarator  */
#line 692 "./cgram.y"
                                          { symclear(blevel); }
#line 2982 "y.tab.c"
    break;

  case 130: /* struct_declarator: declarator attr_var  */
#line 695 "./cgram.y"
                                       {
			P1ND *p;

			(yyvsp[-1].nodep) = aryfix((yyvsp[-1].nodep));
			p = tymerge((yyvsp[-2].nodep), tymfix((yyvsp[-1].nodep)));
			if ((yyvsp[0].nodep))
				p->n_ap = attr_add(p->n_ap, gcc_attr_wrapper((yyvsp[0].nodep)));
			soumemb(p, (char *)(yyvsp[-1].nodep)->n_sp, 0);
			p1tfree(p);
		}
#line 2997 "y.tab.c"
    break;

  case 131: /* struct_declarator: ':' e  */
#line 705 "./cgram.y"
                         {
			int ie = con_e((yyvsp[0].nodep));
			if (fldchk(ie))
				ie = 1;
			falloc(NULL, ie, (yyvsp[-2].nodep));
		}
#line 3008 "y.tab.c"
    break;

  case 132: /* struct_declarator: declarator ':' e  */
#line 711 "./cgram.y"
                                    {
			int ie = con_e((yyvsp[0].nodep));
			if (fldchk(ie))
				ie = 1;
			if ((yyvsp[-2].nodep)->n_op == NAME) {
				/* XXX - tymfix() may alter $1 */
				tymerge((yyvsp[-3].nodep), tymfix((yyvsp[-2].nodep)));
				soumemb((yyvsp[-2].nodep), (char *)(yyvsp[-2].nodep)->n_sp, FIELD | ie);
				p1nfree((yyvsp[-2].nodep));
			} else
				uerror("illegal declarator");
		}
#line 3025 "y.tab.c"
    break;

  case 133: /* struct_declarator: declarator ':' e attr_spec_list  */
#line 723 "./cgram.y"
                                                   {
			int ie = con_e((yyvsp[-1].nodep));
			if (fldchk(ie))
				ie = 1;
			if ((yyvsp[-3].nodep)->n_op == NAME) {
				/* XXX - tymfix() may alter $1 */
				tymerge((yyvsp[-4].nodep), tymfix((yyvsp[-3].nodep)));
				if ((yyvsp[0].nodep))
					(yyvsp[-3].nodep)->n_ap = attr_add((yyvsp[-3].nodep)->n_ap,
					    gcc_attr_wrapper((yyvsp[0].nodep)));
				soumemb((yyvsp[-3].nodep), (char *)(yyvsp[-3].nodep)->n_sp, FIELD | ie);
				p1nfree((yyvsp[-3].nodep));
			} else
				uerror("illegal declarator");
		}
#line 3045 "y.tab.c"
    break;

  case 134: /* struct_declarator: %empty  */
#line 738 "./cgram.y"
                                       {
			P1ND *p = (yyvsp[0].nodep);
			char *c = permalloc(10);

			if (p->n_type != STRTY && p->n_type != UNIONTY)
				uerror("bad unnamed member type");
			snprintf(c, 10, "*%dFAKE", getlab());
			soumemb(p, c, 0);
		}
#line 3059 "y.tab.c"
    break;

  case 135: /* xnfdeclarator: declarator attr_var  */
#line 750 "./cgram.y"
                                       {
			(yyval.symp) = xnf = init_declarator((yyvsp[-2].nodep), (yyvsp[-1].nodep), 1, (yyvsp[0].nodep), 0);
		}
#line 3067 "y.tab.c"
    break;

  case 136: /* xnfdeclarator: declarator C_ASM '(' svstr ')'  */
#line 753 "./cgram.y"
                                                  {
			(yyval.symp) = xnf = init_declarator((yyvsp[-5].nodep), (yyvsp[-4].nodep), 1, NULL, (yyvsp[-1].strp));
		}
#line 3075 "y.tab.c"
    break;

  case 137: /* init_declarator: declarator attr_var  */
#line 762 "./cgram.y"
                                       {
			init_declarator((yyvsp[-2].nodep), (yyvsp[-1].nodep), 0, (yyvsp[0].nodep), 0);
		}
#line 3083 "y.tab.c"
    break;

  case 138: /* init_declarator: declarator C_ASM '(' svstr ')' attr_var  */
#line 765 "./cgram.y"
                                                           {
			init_declarator((yyvsp[-6].nodep), (yyvsp[-5].nodep), 0, (yyvsp[0].nodep), (yyvsp[-2].strp));
		}
#line 3091 "y.tab.c"
    break;

  case 139: /* init_declarator: xnfdeclarator '=' e  */
#line 768 "./cgram.y"
                                       { 
			if ((yyvsp[-2].symp)->sclass == STATIC || (yyvsp[-2].symp)->sclass == EXTDEF)
				statinit++;
			simpleinit((yyvsp[-2].symp), eve((yyvsp[0].nodep)));
			if ((yyvsp[-2].symp)->sclass == STATIC || (yyvsp[-2].symp)->sclass == EXTDEF)
				statinit--;
			xnf = NULL;
		}
#line 3104 "y.tab.c"
    break;

  case 140: /* init_declarator: xnfdeclarator '=' begbr init_list optcomma '}'  */
#line 776 "./cgram.y"
                                                                  {
			endinit(0);
			xnf = NULL;
		}
#line 3113 "y.tab.c"
    break;

  case 141: /* init_declarator: xnfdeclarator '=' begbr '}'  */
#line 780 "./cgram.y"
                                               { endinit(0); xnf = NULL; }
#line 3119 "y.tab.c"
    break;

  case 142: /* begbr: '{'  */
#line 783 "./cgram.y"
                       { beginit((yyvsp[(-1) - (1)].symp)); }
#line 3125 "y.tab.c"
    break;

  case 143: /* initializer: e  */
#line 786 "./cgram.y"
                               {  (yyval.nodep) = eve((yyvsp[0].nodep)); }
#line 3131 "y.tab.c"
    break;

  case 144: /* initializer: ibrace init_list optcomma '}'  */
#line 787 "./cgram.y"
                                                 { (yyval.nodep) = NULL; }
#line 3137 "y.tab.c"
    break;

  case 145: /* initializer: ibrace '}'  */
#line 788 "./cgram.y"
                              { asginit(bcon(0)); (yyval.nodep) = NULL; }
#line 3143 "y.tab.c"
    break;

  case 146: /* init_list: designation initializer  */
#line 791 "./cgram.y"
                                           { dainit((yyvsp[-1].nodep), (yyvsp[0].nodep)); }
#line 3149 "y.tab.c"
    break;

  case 147: /* init_list: init_list ',' designation initializer  */
#line 792 "./cgram.y"
                                                          { dainit((yyvsp[-1].nodep), (yyvsp[0].nodep)); }
#line 3155 "y.tab.c"
    break;

  case 148: /* designation: designator_list '='  */
#line 795 "./cgram.y"
                                       { desinit((yyvsp[-1].nodep)); (yyval.nodep) = NULL; }
#line 3161 "y.tab.c"
    break;

  case 149: /* designation: GCC_DESIG  */
#line 796 "./cgram.y"
                             { desinit(bdty(NAME, (yyvsp[0].strp))); (yyval.nodep) = NULL; }
#line 3167 "y.tab.c"
    break;

  case 150: /* designation: '[' e C_ELLIPSIS e ']' '='  */
#line 797 "./cgram.y"
                                              { (yyval.nodep) = biop(CM, (yyvsp[-4].nodep), (yyvsp[-2].nodep)); }
#line 3173 "y.tab.c"
    break;

  case 151: /* designation: %empty  */
#line 798 "./cgram.y"
                   { (yyval.nodep) = NULL; }
#line 3179 "y.tab.c"
    break;

  case 152: /* designator_list: designator  */
#line 801 "./cgram.y"
                              { (yyval.nodep) = (yyvsp[0].nodep); }
#line 3185 "y.tab.c"
    break;

  case 153: /* designator_list: designator_list designator  */
#line 802 "./cgram.y"
                                              { (yyval.nodep) = (yyvsp[0].nodep); (yyval.nodep)->n_left = (yyvsp[-1].nodep); }
#line 3191 "y.tab.c"
    break;

  case 154: /* designator: '[' e ']'  */
#line 805 "./cgram.y"
                             {
			int ie = con_e((yyvsp[-1].nodep));
			if (ie < 0) {
				uerror("designator must be non-negative");
				ie = 0;
			}
			(yyval.nodep) = biop(LB, NULL, bcon(ie));
		}
#line 3204 "y.tab.c"
    break;

  case 155: /* designator: C_STROP C_TYPENAME  */
#line 813 "./cgram.y"
                                      {
			if ((yyvsp[-1].intval) != DOT)
				uerror("invalid designator");
			(yyval.nodep) = bdty(NAME, (yyvsp[0].strp));
		}
#line 3214 "y.tab.c"
    break;

  case 156: /* designator: C_STROP C_NAME  */
#line 818 "./cgram.y"
                                  {
			if ((yyvsp[-1].intval) != DOT)
				uerror("invalid designator");
			(yyval.nodep) = bdty(NAME, (yyvsp[0].strp));
		}
#line 3224 "y.tab.c"
    break;

  case 159: /* ibrace: '{'  */
#line 829 "./cgram.y"
                       {  ilbrace(); }
#line 3230 "y.tab.c"
    break;

  case 160: /* compoundstmt: begin block_item_list '}'  */
#line 834 "./cgram.y"
                                             { flend(); }
#line 3236 "y.tab.c"
    break;

  case 161: /* compoundstmt: begin '}'  */
#line 835 "./cgram.y"
                             { flend(); }
#line 3242 "y.tab.c"
    break;

  case 162: /* begin: '{'  */
#line 838 "./cgram.y"
                      {
			struct savbc *bc = malloc(sizeof(struct savbc));
			if (blevel == 1) {
#ifdef STABS
				if (gflag)
					stabs_line(lineno);
#endif
				dclargs();
			}
#ifdef STABS
			if (gflag && blevel > 1)
				stabs_lbrac(blevel+1);
#endif
			++blevel;
			oldstyle = 0;
			bc->contlab = autooff;
			bc->next = savctx;
			bc->bkptr = bkpole;
			bc->bkoff = cbkp;
			bc->stptr = sapole;
			bc->stoff = cstp;
			bc->numnode = usdnodes;
			usdnodes = 0;
			bkpole = sapole = NULL;
			cbkp = cstp = 0;
			savctx = bc;
			if (!isinlining && sspflag && blevel == 2)
				sspstart();
		}
#line 3276 "y.tab.c"
    break;

  case 163: /* statement: e ';'  */
#line 869 "./cgram.y"
                         { ecomp(eve((yyvsp[-1].nodep))); symclear(blevel); }
#line 3282 "y.tab.c"
    break;

  case 165: /* statement: ifprefix statement  */
#line 871 "./cgram.y"
                                      { plabel((yyvsp[-1].intval)); reached = 1; }
#line 3288 "y.tab.c"
    break;

  case 166: /* statement: ifelprefix statement  */
#line 872 "./cgram.y"
                                        {
			if ((yyvsp[-1].intval) != NOLAB) {
				plabel( (yyvsp[-1].intval));
				reached = 1;
			}
		}
#line 3299 "y.tab.c"
    break;

  case 167: /* statement: whprefix statement  */
#line 878 "./cgram.y"
                                      {
			branch(contlab);
			plabel( brklab );
			if( (flostat&FBRK) || !(flostat&FLOOP))
				reached = 1;
			else
				reached = 0;
			resetbc(0);
		}
#line 3313 "y.tab.c"
    break;

  case 168: /* statement: doprefix statement C_WHILE '(' e ')' ';'  */
#line 887 "./cgram.y"
                                                            {
			plabel(contlab);
			if (flostat & FCONT)
				reached = 1;
			if (reached)
				cbranch(buildtree(NE, eve((yyvsp[-2].nodep)), bcon(0)),
				    bcon((yyvsp[-6].intval)));
			else
				p1tfree(eve((yyvsp[-2].nodep)));
			plabel( brklab);
			reached = 1;
			resetbc(0);
		}
#line 3331 "y.tab.c"
    break;

  case 169: /* statement: forprefix .e ')' statement  */
#line 901 "./cgram.y"
                        {  plabel( contlab );
			    if( flostat&FCONT ) reached = 1;
			    if( (yyvsp[-2].nodep) ) ecomp( (yyvsp[-2].nodep) );
			    branch((yyvsp[-3].intval));
			    plabel( brklab );
			    if( (flostat&FBRK) || !(flostat&FLOOP) ) reached = 1;
			    else reached = 0;
			    resetbc(0);
			    blevel--;
			    symclear(blevel);
			    }
#line 3347 "y.tab.c"
    break;

  case 170: /* statement: switchpart statement  */
#line 913 "./cgram.y"
                        { if( reached ) branch( brklab );
			    plabel( (yyvsp[-1].intval) );
			    swend();
			    plabel( brklab);
			    if( (flostat&FBRK) || !(flostat&FDEF) ) reached = 1;
			    resetbc(FCONT);
			    }
#line 3359 "y.tab.c"
    break;

  case 171: /* statement: C_BREAK ';'  */
#line 920 "./cgram.y"
                                {
			if (brklab == NOLAB)
				uerror("illegal break");
			else if (reached)
				branch(brklab);
			flostat |= FBRK;
			reached = 0;
		}
#line 3372 "y.tab.c"
    break;

  case 172: /* statement: C_CONTINUE ';'  */
#line 928 "./cgram.y"
                                   {
			if (contlab == NOLAB)
				uerror("illegal continue");
			else
				branch(contlab);
			flostat |= FCONT;
			goto rch;
		}
#line 3385 "y.tab.c"
    break;

  case 173: /* statement: C_RETURN ';'  */
#line 936 "./cgram.y"
                                 {
			branch(retlab);
			if (cftnsp->stype != VOID && 
			    (cftnsp->sflags & NORETYP) == 0 &&
			    cftnsp->stype != VOID+FTN)
				uerror("return value required");
			rch:
			if (!reached)
				warner(Wunreachable_code);
			reached = 0;
		}
#line 3401 "y.tab.c"
    break;

  case 174: /* statement: C_RETURN e ';'  */
#line 947 "./cgram.y"
                                   {
			P1ND *p, *q;

			p = nametree(cftnsp);
			p->n_type = DECREF(p->n_type);
			q = eve((yyvsp[-1].nodep));
#ifdef TARGET_TIMODE  
			{
			P1ND *r;
			if ((r = gcc_eval_ticast(RETURN, p, q)) != NULL)
				q = r;
			}
#endif
#ifndef NO_COMPLEX
			if (ANYCX(q) || ANYCX(p))
				q = cxret(q, p);
			else if (ISITY(p->n_type) || ISITY(q->n_type)) {
				q = imret(q, p);
				if (ISITY(p->n_type))
					p->n_type -= (FIMAG-FLOAT);
				if (ISITY(q->n_type))
					q->n_type -= (FIMAG-FLOAT);
			}
#endif
			p = buildtree(RETURN, p, q);
			if (p->n_type == VOID) {
				ecomp(p->n_right);
			} else {
				if (cftnod == NULL) {
					P1ND *r = tempnode(0, p->n_type,
					    p->n_df, p->pss);
					cftnod = tmpalloc(sizeof(P1ND));
					*cftnod = *r;
					p1tfree(r);
				}
				ecomp(buildtree(ASSIGN,
				    p1tcopy(cftnod), p->n_right));
			}
			p1tfree(p->n_left);
			p1nfree(p);
			branch(retlab);
			reached = 0;
		}
#line 3449 "y.tab.c"
    break;

  case 175: /* statement: C_GOTO C_NAME ';'  */
#line 990 "./cgram.y"
                                     { gotolabel((yyvsp[-1].strp)); goto rch; }
#line 3455 "y.tab.c"
    break;

  case 176: /* statement: C_GOTO '*' e ';'  */
#line 991 "./cgram.y"
                                    { ecomp(biop(GOTO, eve((yyvsp[-1].nodep)), NULL)); }
#line 3461 "y.tab.c"
    break;

  case 182: /* asmstatement: C_ASM mvol '(' svstr ')'  */
#line 999 "./cgram.y"
                                            { send_passt(IP_ASM, mkpstr((yyvsp[-1].strp))); }
#line 3467 "y.tab.c"
    break;

  case 183: /* asmstatement: C_ASM mvol '(' svstr xasm ')'  */
#line 1000 "./cgram.y"
                                                 { mkxasm((yyvsp[-2].strp), (yyvsp[-1].nodep)); }
#line 3473 "y.tab.c"
    break;

  case 184: /* svstr: string  */
#line 1003 "./cgram.y"
                         { (yyval.strp) = addstring((yyvsp[0].strp)); }
#line 3479 "y.tab.c"
    break;

  case 186: /* mvol: C_QUALIFIER  */
#line 1007 "./cgram.y"
                               { }
#line 3485 "y.tab.c"
    break;

  case 187: /* xasm: ':' oplist  */
#line 1010 "./cgram.y"
                              { (yyval.nodep) = xcmop((yyvsp[0].nodep), NULL, NULL); }
#line 3491 "y.tab.c"
    break;

  case 188: /* xasm: ':' oplist ':' oplist  */
#line 1011 "./cgram.y"
                                         { (yyval.nodep) = xcmop((yyvsp[-2].nodep), (yyvsp[0].nodep), NULL); }
#line 3497 "y.tab.c"
    break;

  case 189: /* xasm: ':' oplist ':' oplist ':' cnstr  */
#line 1012 "./cgram.y"
                                                   { (yyval.nodep) = xcmop((yyvsp[-4].nodep), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3503 "y.tab.c"
    break;

  case 190: /* oplist: %empty  */
#line 1015 "./cgram.y"
                                 { (yyval.nodep) = NULL; }
#line 3509 "y.tab.c"
    break;

  case 191: /* oplist: oper  */
#line 1016 "./cgram.y"
                        { (yyval.nodep) = (yyvsp[0].nodep); }
#line 3515 "y.tab.c"
    break;

  case 192: /* oper: svstr '(' e ')'  */
#line 1019 "./cgram.y"
                                   { (yyval.nodep) = xasmop((yyvsp[-3].strp), pconvert(eve((yyvsp[-1].nodep)))); }
#line 3521 "y.tab.c"
    break;

  case 193: /* oper: oper ',' svstr '(' e ')'  */
#line 1020 "./cgram.y"
                                            {
			(yyval.nodep) = cmop((yyvsp[-5].nodep), xasmop((yyvsp[-3].strp), pconvert(eve((yyvsp[-1].nodep)))));
		}
#line 3529 "y.tab.c"
    break;

  case 194: /* cnstr: svstr  */
#line 1025 "./cgram.y"
                         { (yyval.nodep) = xasmop((yyvsp[0].strp), bcon(0)); }
#line 3535 "y.tab.c"
    break;

  case 195: /* cnstr: cnstr ',' svstr  */
#line 1026 "./cgram.y"
                                   { (yyval.nodep) = cmop((yyvsp[-2].nodep), xasmop((yyvsp[0].strp), bcon(0))); }
#line 3541 "y.tab.c"
    break;

  case 196: /* label: C_NAME ':' attr_var  */
#line 1029 "./cgram.y"
                                       { deflabel((yyvsp[-2].strp), (yyvsp[0].nodep)); reached = 1; }
#line 3547 "y.tab.c"
    break;

  case 197: /* label: C_TYPENAME ':' attr_var  */
#line 1030 "./cgram.y"
                                           { deflabel((yyvsp[-2].strp), (yyvsp[0].nodep)); reached = 1; }
#line 3553 "y.tab.c"
    break;

  case 198: /* label: C_CASE e ':'  */
#line 1031 "./cgram.y"
                                { addcase(eve((yyvsp[-1].nodep))); reached = 1; }
#line 3559 "y.tab.c"
    break;

  case 199: /* label: C_CASE e C_ELLIPSIS e ':'  */
#line 1032 "./cgram.y"
                                             {
#ifdef GCC_COMPAT
			gcccase(eve((yyvsp[-3].nodep)), eve((yyvsp[-1].nodep))); reached = 1;
#endif
		}
#line 3569 "y.tab.c"
    break;

  case 200: /* label: C_DEFAULT ':'  */
#line 1037 "./cgram.y"
                                 { reached = 1; adddef(); flostat |= FDEF; }
#line 3575 "y.tab.c"
    break;

  case 201: /* doprefix: C_DO  */
#line 1040 "./cgram.y"
                     {
			savebc();
			brklab = getlab();
			contlab = getlab();
			plabel(  (yyval.intval) = getlab());
			reached = 1;
		}
#line 3587 "y.tab.c"
    break;

  case 202: /* ifprefix: C_IF '(' e ')'  */
#line 1048 "./cgram.y"
                               {
			xcbranch(eve((yyvsp[-1].nodep)), (yyval.intval) = getlab());
			reached = 1;
		}
#line 3596 "y.tab.c"
    break;

  case 203: /* ifelprefix: ifprefix statement C_ELSE  */
#line 1053 "./cgram.y"
                                            {
			if (reached)
				branch((yyval.intval) = getlab());
			else
				(yyval.intval) = NOLAB;
			plabel( (yyvsp[-2].intval));
			reached = 1;
		}
#line 3609 "y.tab.c"
    break;

  case 204: /* whprefix: C_WHILE '(' e ')'  */
#line 1063 "./cgram.y"
                                       {
			savebc();
			(yyvsp[-1].nodep) = eve((yyvsp[-1].nodep));
			if ((yyvsp[-1].nodep)->n_op == ICON && glval((yyvsp[-1].nodep)) != 0)
				flostat = FLOOP | (flostat & FP_CONTR_CBR);
			plabel( contlab = getlab());
			reached = 1;
			brklab = getlab();
			if (flostat & FLOOP)
				p1tfree((yyvsp[-1].nodep));
			else
				xcbranch((yyvsp[-1].nodep), brklab);
		}
#line 3627 "y.tab.c"
    break;

  case 205: /* forprefix: C_FOR '(' .e ';' .e ';'  */
#line 1077 "./cgram.y"
                                              {
			++blevel;
			if ((yyvsp[-3].nodep))
				ecomp((yyvsp[-3].nodep));
			savebc();
			contlab = getlab();
			brklab = getlab();
			plabel( (yyval.intval) = getlab());
			reached = 1;
			if ((yyvsp[-1].nodep))
				xcbranch((yyvsp[-1].nodep), brklab);
			else
				flostat |= FLOOP;
		}
#line 3646 "y.tab.c"
    break;

  case 206: /* $@3: %empty  */
#line 1091 "./cgram.y"
                             { ++blevel; }
#line 3652 "y.tab.c"
    break;

  case 207: /* forprefix: C_FOR '(' $@3 declaration .e ';'  */
#line 1091 "./cgram.y"
                                                              {
			savebc();
			contlab = getlab();
			brklab = getlab();
			plabel( (yyval.intval) = getlab());
			reached = 1;
			if ((yyvsp[-1].nodep))
				xcbranch((yyvsp[-1].nodep), brklab);
			else
				flostat |= FLOOP;
		}
#line 3668 "y.tab.c"
    break;

  case 208: /* switchpart: C_SWITCH '(' e ')'  */
#line 1104 "./cgram.y"
                                        {
			P1ND *p;
			int num;
			TWORD t;

			savebc();
			brklab = getlab();
			(yyvsp[-1].nodep) = eve((yyvsp[-1].nodep));
			if (!ISINTEGER((yyvsp[-1].nodep)->n_type)) {
				uerror("switch expression must have integer "
				       "type");
				t = INT;
			} else {
				(yyvsp[-1].nodep) = intprom((yyvsp[-1].nodep));
				t = (yyvsp[-1].nodep)->n_type;
			}
			p = tempnode(0, t, 0, 0);
			num = regno(p);
			ecomp(buildtree(ASSIGN, p, (yyvsp[-1].nodep)));
			branch( (yyval.intval) = getlab());
			swstart(num, t);
			reached = 0;
		}
#line 3696 "y.tab.c"
    break;

  case 209: /* .e: e  */
#line 1129 "./cgram.y"
                     { (yyval.nodep) = eve((yyvsp[0].nodep)); }
#line 3702 "y.tab.c"
    break;

  case 210: /* .e: %empty  */
#line 1130 "./cgram.y"
                        { (yyval.nodep)=0; }
#line 3708 "y.tab.c"
    break;

  case 211: /* elist: %empty  */
#line 1133 "./cgram.y"
                   { (yyval.nodep) = NULL; }
#line 3714 "y.tab.c"
    break;

  case 212: /* elist: e2  */
#line 1134 "./cgram.y"
                      { (yyval.nodep) = (yyvsp[0].nodep); }
#line 3720 "y.tab.c"
    break;

  case 214: /* e2: e2 ',' e  */
#line 1138 "./cgram.y"
                              { (yyval.nodep) = biop(CM, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3726 "y.tab.c"
    break;

  case 215: /* e2: e2 ',' cast_type  */
#line 1139 "./cgram.y"
                                      { /* hack for stdarg */
			TYMFIX((yyvsp[0].nodep));
			(yyvsp[0].nodep)->n_op = TYPE;
			(yyval.nodep) = biop(CM, (yyvsp[-2].nodep), (yyvsp[0].nodep));
		}
#line 3736 "y.tab.c"
    break;

  case 216: /* e2: cast_type  */
#line 1144 "./cgram.y"
                             { TYMFIX((yyvsp[0].nodep)); (yyvsp[0].nodep)->n_op = TYPE; (yyval.nodep) = (yyvsp[0].nodep); }
#line 3742 "y.tab.c"
    break;

  case 217: /* e: e ',' e  */
#line 1150 "./cgram.y"
                           { (yyval.nodep) = biop(COMOP, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3748 "y.tab.c"
    break;

  case 218: /* e: e '=' e  */
#line 1151 "./cgram.y"
                           {  (yyval.nodep) = biop(ASSIGN, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3754 "y.tab.c"
    break;

  case 219: /* e: e C_ASOP e  */
#line 1152 "./cgram.y"
                              {  (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3760 "y.tab.c"
    break;

  case 220: /* e: e '?' e ':' e  */
#line 1153 "./cgram.y"
                                 { (yyval.nodep)=biop(QUEST, (yyvsp[-4].nodep), biop(COLON, (yyvsp[-2].nodep), (yyvsp[0].nodep))); }
#line 3766 "y.tab.c"
    break;

  case 221: /* e: e '?' ':' e  */
#line 1154 "./cgram.y"
                               { (yyval.nodep) = biop(BIQUEST, (yyvsp[-3].nodep), (yyvsp[0].nodep)); }
#line 3772 "y.tab.c"
    break;

  case 222: /* e: e C_OROR e  */
#line 1155 "./cgram.y"
                              { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3778 "y.tab.c"
    break;

  case 223: /* e: e C_ANDAND e  */
#line 1156 "./cgram.y"
                                { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3784 "y.tab.c"
    break;

  case 224: /* e: e '|' e  */
#line 1157 "./cgram.y"
                           { (yyval.nodep) = biop(OR, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3790 "y.tab.c"
    break;

  case 225: /* e: e '^' e  */
#line 1158 "./cgram.y"
                           { (yyval.nodep) = biop(ER, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3796 "y.tab.c"
    break;

  case 226: /* e: e '&' e  */
#line 1159 "./cgram.y"
                           { (yyval.nodep) = biop(AND, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3802 "y.tab.c"
    break;

  case 227: /* e: e C_EQUOP e  */
#line 1160 "./cgram.y"
                                { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3808 "y.tab.c"
    break;

  case 228: /* e: e C_RELOP e  */
#line 1161 "./cgram.y"
                               { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3814 "y.tab.c"
    break;

  case 229: /* e: e C_SHIFTOP e  */
#line 1162 "./cgram.y"
                                 { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3820 "y.tab.c"
    break;

  case 230: /* e: e '+' e  */
#line 1163 "./cgram.y"
                           { (yyval.nodep) = biop(PLUS, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3826 "y.tab.c"
    break;

  case 231: /* e: e '-' e  */
#line 1164 "./cgram.y"
                           { (yyval.nodep) = biop(MINUS, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3832 "y.tab.c"
    break;

  case 232: /* e: e C_DIVOP e  */
#line 1165 "./cgram.y"
                               { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3838 "y.tab.c"
    break;

  case 233: /* e: e '*' e  */
#line 1166 "./cgram.y"
                           { (yyval.nodep) = biop(MUL, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3844 "y.tab.c"
    break;

  case 235: /* xbegin: begin  */
#line 1170 "./cgram.y"
                         {
			(yyval.intval) = getlab(); getlab(); getlab();
			branch((yyval.intval)); plabel(((yyval.intval))+2);
		}
#line 3853 "y.tab.c"
    break;

  case 236: /* term: term C_INCOP  */
#line 1176 "./cgram.y"
                                {  (yyval.nodep) = biop((yyvsp[0].intval), (yyvsp[-1].nodep), bcon(1)); }
#line 3859 "y.tab.c"
    break;

  case 237: /* term: '*' term  */
#line 1177 "./cgram.y"
                            { (yyval.nodep) = biop(UMUL, (yyvsp[0].nodep), NULL); }
#line 3865 "y.tab.c"
    break;

  case 238: /* term: '&' term  */
#line 1178 "./cgram.y"
                            { (yyval.nodep) = biop(ADDROF, (yyvsp[0].nodep), NULL); }
#line 3871 "y.tab.c"
    break;

  case 239: /* term: '-' term  */
#line 1179 "./cgram.y"
                            { (yyval.nodep) = biop(UMINUS, (yyvsp[0].nodep), NULL ); }
#line 3877 "y.tab.c"
    break;

  case 240: /* term: '+' term  */
#line 1180 "./cgram.y"
                            { (yyval.nodep) = biop(UPLUS, (yyvsp[0].nodep), NULL ); }
#line 3883 "y.tab.c"
    break;

  case 241: /* term: C_UNOP term  */
#line 1181 "./cgram.y"
                               { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[0].nodep), NULL); }
#line 3889 "y.tab.c"
    break;

  case 242: /* term: C_INCOP term  */
#line 1182 "./cgram.y"
                                {
			(yyval.nodep) = biop((yyvsp[-1].intval) == INCR ? PLUSEQ : MINUSEQ, (yyvsp[0].nodep), bcon(1));
		}
#line 3897 "y.tab.c"
    break;

  case 243: /* term: C_SIZEOF xa term  */
#line 1185 "./cgram.y"
                                    { (yyval.nodep) = biop(SZOF, (yyvsp[0].nodep), bcon(0)); inattr = (yyvsp[-1].intval); }
#line 3903 "y.tab.c"
    break;

  case 244: /* term: '(' cast_type ')' term  */
#line 1186 "./cgram.y"
                                                         {
			TYMFIX((yyvsp[-2].nodep));
			(yyval.nodep) = biop(CAST, (yyvsp[-2].nodep), (yyvsp[0].nodep));
		}
#line 3912 "y.tab.c"
    break;

  case 245: /* term: C_SIZEOF xa '(' cast_type ')'  */
#line 1190 "./cgram.y"
                                                                 {
			(yyval.nodep) = biop(SZOF, (yyvsp[-1].nodep), bcon(1));
			inattr = (yyvsp[-3].intval);
		}
#line 3921 "y.tab.c"
    break;

  case 246: /* term: C_ALIGNOF xa '(' cast_type ')'  */
#line 1194 "./cgram.y"
                                                  {
			int al;
			TYMFIX((yyvsp[-1].nodep));
			al = talign((yyvsp[-1].nodep)->n_type, (yyvsp[-1].nodep)->pss);
			(yyval.nodep) = bcon(al/SZCHAR);
			inattr = (yyvsp[-3].intval);
			p1tfree((yyvsp[-1].nodep));
		}
#line 3934 "y.tab.c"
    break;

  case 247: /* term: '(' cast_type ')' clbrace init_list optcomma '}'  */
#line 1202 "./cgram.y"
                                                                   {
			endinit(0);
			(yyval.nodep) = bdty(NAME, (yyvsp[-3].symp));
			(yyval.nodep)->n_op = CLOP;
		}
#line 3944 "y.tab.c"
    break;

  case 248: /* term: '(' cast_type ')' clbrace '}'  */
#line 1207 "./cgram.y"
                                                {
			endinit(0);
			(yyval.nodep) = bdty(NAME, (yyvsp[-1].symp));
			(yyval.nodep)->n_op = CLOP;
		}
#line 3954 "y.tab.c"
    break;

  case 249: /* term: term '[' e ']'  */
#line 1212 "./cgram.y"
                                  { (yyval.nodep) = biop(LB, (yyvsp[-3].nodep), (yyvsp[-1].nodep)); }
#line 3960 "y.tab.c"
    break;

  case 250: /* term: C_NAME '(' elist ')'  */
#line 1213 "./cgram.y"
                                         {
			(yyval.nodep) = biop((yyvsp[-1].nodep) ? CALL : UCALL, bdty(NAME, (yyvsp[-3].strp)), (yyvsp[-1].nodep));
		}
#line 3968 "y.tab.c"
    break;

  case 251: /* term: term '(' elist ')'  */
#line 1216 "./cgram.y"
                                       { (yyval.nodep) = biop((yyvsp[-1].nodep) ? CALL : UCALL, (yyvsp[-3].nodep), (yyvsp[-1].nodep)); }
#line 3974 "y.tab.c"
    break;

  case 252: /* term: term C_STROP C_NAME  */
#line 1217 "./cgram.y"
                                       { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), bdty(NAME, (yyvsp[0].strp))); }
#line 3980 "y.tab.c"
    break;

  case 253: /* term: term C_STROP C_TYPENAME  */
#line 1218 "./cgram.y"
                                           { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), bdty(NAME, (yyvsp[0].strp)));}
#line 3986 "y.tab.c"
    break;

  case 254: /* term: C_NAME  */
#line 1219 "./cgram.y"
                                                      { (yyval.nodep) = bdty(NAME, (yyvsp[0].strp)); }
#line 3992 "y.tab.c"
    break;

  case 255: /* term: PCC_OFFSETOF '(' cast_type ',' term ')'  */
#line 1220 "./cgram.y"
                                                            {
			TYMFIX((yyvsp[-3].nodep));
			(yyvsp[-3].nodep)->n_type = INCREF((yyvsp[-3].nodep)->n_type);
			(yyvsp[-3].nodep) = biop(CAST, (yyvsp[-3].nodep), bcon(0));
			if ((yyvsp[-1].nodep)->n_op == NAME) {
				(yyval.nodep) = biop(STREF, (yyvsp[-3].nodep), (yyvsp[-1].nodep));
			} else {
				P1ND *p = (yyvsp[-1].nodep);
				while (p->n_left->n_op != NAME)
					p = p->n_left;
				p->n_left = biop(STREF, (yyvsp[-3].nodep), p->n_left);
				(yyval.nodep) = (yyvsp[-1].nodep);
			}
			(yyval.nodep) = biop(ADDROF, (yyval.nodep), NULL);
			(yyvsp[-3].nodep) = block(NAME, NULL, NULL, ENUNSIGN(INTPTR), 0, 0);
			(yyval.nodep) = biop(CAST, (yyvsp[-3].nodep), (yyval.nodep));
		}
#line 4014 "y.tab.c"
    break;

  case 256: /* term: C_ICON  */
#line 1237 "./cgram.y"
                          { (yyval.nodep) = bdty(ICON, &((yyvsp[0].li))); }
#line 4020 "y.tab.c"
    break;

  case 257: /* term: C_FCON  */
#line 1238 "./cgram.y"
                          { (yyval.nodep) = bdty(FCON, &((yyvsp[0].flt))); }
#line 4026 "y.tab.c"
    break;

  case 258: /* term: svstr  */
#line 1239 "./cgram.y"
                         { (yyval.nodep) = bdty(STRING, (yyvsp[0].strp), styp()); }
#line 4032 "y.tab.c"
    break;

  case 259: /* term: '(' e ')'  */
#line 1240 "./cgram.y"
                             { (yyval.nodep)=(yyvsp[-1].nodep); }
#line 4038 "y.tab.c"
    break;

  case 260: /* term: '(' xbegin e ';' '}' ')'  */
#line 1241 "./cgram.y"
                                            { (yyval.nodep) = gccexpr((yyvsp[-4].intval), eve((yyvsp[-3].nodep))); }
#line 4044 "y.tab.c"
    break;

  case 261: /* term: '(' xbegin block_item_list e ';' '}' ')'  */
#line 1242 "./cgram.y"
                                                            {
			(yyval.nodep) = gccexpr((yyvsp[-5].intval), eve((yyvsp[-3].nodep)));
		}
#line 4052 "y.tab.c"
    break;

  case 262: /* term: '(' xbegin block_item_list '}' ')'  */
#line 1245 "./cgram.y"
                                                      { 
			(yyval.nodep) = gccexpr((yyvsp[-3].intval), voidcon());
		}
#line 4060 "y.tab.c"
    break;

  case 263: /* term: C_ANDAND C_NAME  */
#line 1248 "./cgram.y"
                                  {
			struct symtab *s = lookup((yyvsp[0].strp), SLBLNAME|STEMP);
			if (s->soffset == 0) {
				s->soffset = -getlab();
				s->sclass = STATIC;
			}
			savlab(s->soffset);
			(yyval.nodep) = biop(ADDROF, bdty(GOTO, (yyvsp[0].strp)), NULL);
		}
#line 4074 "y.tab.c"
    break;

  case 264: /* term: C_GENERIC '(' e ',' gen_ass_list ')'  */
#line 1257 "./cgram.y"
                                                       { (yyval.nodep) = dogen((yyvsp[-1].g), (yyvsp[-3].nodep)); }
#line 4080 "y.tab.c"
    break;

  case 265: /* gen_ass_list: gen_assoc  */
#line 1260 "./cgram.y"
                            { (yyval.g) = (yyvsp[0].g); }
#line 4086 "y.tab.c"
    break;

  case 266: /* gen_ass_list: gen_ass_list ',' gen_assoc  */
#line 1261 "./cgram.y"
                                             { (yyval.g) = addgen((yyvsp[-2].g), (yyvsp[0].g)); }
#line 4092 "y.tab.c"
    break;

  case 267: /* gen_assoc: cast_type ':' e  */
#line 1264 "./cgram.y"
                                  { TYMFIX((yyvsp[-2].nodep)); (yyval.g) = newgen((yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 4098 "y.tab.c"
    break;

  case 268: /* gen_assoc: C_DEFAULT ':' e  */
#line 1265 "./cgram.y"
                                  { (yyval.g) = newgen(0, (yyvsp[0].nodep)); }
#line 4104 "y.tab.c"
    break;

  case 269: /* xa: %empty  */
#line 1268 "./cgram.y"
                  { (yyval.intval) = inattr; inattr = 0; }
#line 4110 "y.tab.c"
    break;

  case 270: /* clbrace: '{'  */
#line 1271 "./cgram.y"
                        { P1ND *q = (yyvsp[(-1) - (1)].nodep); TYMFIX(q); (yyval.symp) = clbrace(q); }
#line 4116 "y.tab.c"
    break;

  case 271: /* string: C_STRING  */
#line 1274 "./cgram.y"
                            { (yyval.strp) = stradd(NULL, (yyvsp[0].strp)); }
#line 4122 "y.tab.c"
    break;

  case 272: /* string: string C_STRING  */
#line 1275 "./cgram.y"
                                   { (yyval.strp) = stradd((yyvsp[-1].strp), (yyvsp[0].strp)); }
#line 4128 "y.tab.c"
    break;

  case 273: /* cast_type: specifier_qualifier_list  */
#line 1278 "./cgram.y"
                                            {
			(yyval.nodep) = biop(TYMERGE, (yyvsp[0].nodep), bdty(NAME, NULL));
		}
#line 4136 "y.tab.c"
    break;

  case 274: /* cast_type: specifier_qualifier_list abstract_declarator  */
#line 1281 "./cgram.y"
                                                                {
			(yyval.nodep) = biop(TYMERGE, (yyvsp[-1].nodep), aryfix((yyvsp[0].nodep)));
		}
#line 4144 "y.tab.c"
    break;


#line 4148 "y.tab.c"

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
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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
  ++yynerrs;

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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1286 "./cgram.y"


P1ND *
mkty(TWORD t, union dimfun *d, struct ssdesc *ss)
{
	return block(TYPE, NULL, NULL, t, d, ss);
}

P1ND *
bdty(int op, ...)
{
	struct lexint *li;
	FLT *f2;
	CONSZ c;
	va_list ap;
	int val;
	register P1ND *q;

	va_start(ap, op);
	q = biop(op, NULL, NULL);

	switch (op) {
	case UMUL:
	case UCALL:
		q->n_left = va_arg(ap, P1ND *);
		q->n_rval = 0;
		break;

	case FCON:
		f2 = va_arg(ap, FLT *);
		q->n_scon = sfallo();
		*q->n_scon = f2->sf;
		q->n_type = f2->t;
		break;

	case ICON:
		li = va_arg(ap, struct lexint *);
		slval(q, li->val);
		q->n_type = li->t;
		break;

	case CALL:
		q->n_left = va_arg(ap, P1ND *);
		q->n_right = va_arg(ap, P1ND *);
		break;

	case LB:
		q->n_left = va_arg(ap, P1ND *);
		if ((val = va_arg(ap, int)) <= 0) {
			uerror("array size must be positive");
			val = 1;
		}
		q->n_right = bcon(val);
		break;

	case GOTO: /* for named labels */
		q->n_ap = attr_add(q->n_ap, attr_new(ATTR_P1LABELS, 1));
		/* FALLTHROUGH */
	case NAME:
		q->n_op = NAME;
		q->n_sp = va_arg(ap, struct symtab *); /* XXX survive tymerge */
		break;

	case STRING:
		q->n_type = PTR|CHAR;
		q->n_name = va_arg(ap, char *);
		c = va_arg(ap, TWORD);
		slval(q, c);
		break;

	default:
		cerror("bad bdty");
	}
	va_end(ap);

	return q;
}

static void
flend(void)
{
	struct savbc *sc;

	if (!isinlining && sspflag && blevel == 2)
		sspend();
#ifdef STABS
	if (gflag && blevel > 2)
		stabs_rbrac(blevel);
#endif
	--blevel;
	if( blevel == 1 )
		blevel = 0;
	symclear(blevel); /* Clean ut the symbol table */
	if (autooff > maxautooff)
		maxautooff = autooff;
	autooff = savctx->contlab;
	blkfree();
	stmtfree();
	bkpole = savctx->bkptr;
	cbkp = savctx->bkoff;
	sapole = savctx->stptr;
	cstp = savctx->stoff;
	usdnodes = savctx->numnode;
	sc = savctx->next;
	free(savctx);
	savctx = sc;
}

/*
 * XXX workaround routines for block level cleansing in gcc compat mode.
 * Temporary should be re reserved for this value before.
 */
static P1ND *
p1mcopy(P1ND *p)
{
	P1ND *q;

	q = xmalloc(sizeof(P1ND));
	*q = *p;

	switch (coptype(q->n_op)) {
	case BITYPE:
		q->n_right = p1mcopy(p->n_right);
		/* FALLTHROUGH */
	case UTYPE: 
		q->n_left = p1mcopy(p->n_left);
	}

	return(q);
}

static void
p1mfree(P1ND *p)
{
	int o = coptype(p->n_op);
	if (o == BITYPE)
		p1mfree(p->n_right);
	if (o != LTYPE)
		p1mfree(p->n_left);
	free(p);
}


static P1ND *
gccexpr(int bn, P1ND *q)
{
	P1ND *r, *p, *s;

	branch(bn+4);
	plabel(bn);
	r = buildtree(COMOP, biop(GOTO, bcon(bn+2), NULL), q);
	/* XXX hack to survive flend() */
	s = p1mcopy(r);
	p1tfree(r);
	flend();
	r = p1tcopy(s);
	p1mfree(s);
	q = r->n_right;
	/* XXX end hack */
	if (!(q->n_op == ICON && q->n_type == STRTY) && (r->n_type != VOID)) {
		p = tempnode(0, q->n_type, q->n_df, q->pss);
		r = buildtree(ASSIGN, p1tcopy(p), r);
		r = buildtree(COMOP, r, p);
	}
	return r;
}

static void
savebc(void)
{
	struct savbc *bc = malloc(sizeof(struct savbc));

	bc->brklab = brklab;
	bc->contlab = contlab;
	bc->flostat = flostat;
	bc->next = savbc;
	savbc = bc;
	flostat &= FP_CONTR_CBR;
}

static void
resetbc(int mask)
{
	struct savbc *bc;

	flostat = savbc->flostat | (flostat&mask);
	contlab = savbc->contlab;
	brklab = savbc->brklab;
	bc = savbc->next;
	free(savbc);
	savbc = bc;
}

struct swdef {
	struct swdef *next;	/* Next in list */
	int deflbl;		/* Label for "default" */
	struct swents *ents;	/* Linked sorted list of case entries */
	int nents;		/* # of entries in list */
	int num;		/* Node value will end up in */
	TWORD type;		/* Type of switch expression */
} *swpole;

/*
 * add case to switch
 */
static void
addcase(P1ND *p)
{
	struct swents **put, *w, *sw = malloc(sizeof(struct swents));
	CONSZ val;

	p = optloop(p);  /* change enum to ints */
	if (p->n_op != ICON || p->n_sp != NULL) {
		uerror( "non-constant case expression");
		return;
	}
	if (swpole == NULL) {
		uerror("case not in switch");
		return;
	}

	if (DEUNSIGN(swpole->type) != DEUNSIGN(p->n_type)) {
		val = glval(p);
		p = makety(p, mkqtyp(swpole->type));
		if (p->n_op != ICON)
			cerror("could not cast case value to type of switch "
			       "expression");
		if (glval(p) != val)
			werror("case expression truncated");
	}
	sw->sval = glval(p);
	p1tfree(p);
	put = &swpole->ents;
	if (ISUNSIGNED(swpole->type)) {
		for (w = swpole->ents;
		     w != NULL && (U_CONSZ)w->sval < (U_CONSZ)sw->sval;
		     w = w->next)
			put = &w->next;
	} else {
		for (w = swpole->ents; w != NULL && w->sval < sw->sval;
		     w = w->next)
			put = &w->next;
	}
	if (w != NULL && w->sval == sw->sval) {
		uerror("duplicate case in switch");
		return;
	}
	plabel(sw->slab = getlab());
	*put = sw;
	sw->next = w;
	swpole->nents++;
}

#ifdef GCC_COMPAT
void
gcccase(P1ND *ln, P1ND *hn)
{
	CONSZ i, l, h;

	l = icons(optim(ln));
	h = icons(optim(hn));

	if (h < l)
		i = l, l = h, h = i;

	for (i = l; i <= h; i++)
		addcase(xbcon(i, NULL, hn->n_type));
}
#endif

/*
 * add default case to switch
 */
static void
adddef(void)
{
	if (swpole == NULL)
		uerror("default not inside switch");
	else if (swpole->deflbl != 0)
		uerror("duplicate default in switch");
	else
		plabel( swpole->deflbl = getlab());
}

static void
swstart(int num, TWORD type)
{
	struct swdef *sw = malloc(sizeof(struct swdef));

	sw->deflbl = sw->nents = 0;
	sw->ents = NULL;
	sw->next = swpole;
	sw->num = num;
	sw->type = type;
	swpole = sw;
}

/*
 * end a switch block
 */
static void
swend(void)
{
	struct swents *sw, **swp;
	struct swdef *sp;
	int i;

	sw = FUNALLO(sizeof(struct swents));
	swp = FUNALLO(sizeof(struct swents *) * (swpole->nents+1));

	sw->slab = swpole->deflbl;
	swp[0] = sw;

	for (i = 1; i <= swpole->nents; i++) {
		swp[i] = swpole->ents;
		swpole->ents = swpole->ents->next;
	}
	genswitch(swpole->num, swpole->type, swp, swpole->nents);

	FUNFREE(sw);
	FUNFREE(swp);
	while (swpole->ents) {
		sw = swpole->ents;
		swpole->ents = sw->next;
		free(sw);
	}
	sp = swpole->next;
	free(swpole);
	swpole = sp;
}

/*
 * num: tempnode the value of the switch expression is in
 * type: type of the switch expression
 *
 * p points to an array of structures, each consisting
 * of a constant value and a label.
 * The first is >=0 if there is a default label;
 * its value is the label number
 * The entries p[1] to p[n] are the nontrivial cases
 * n is the number of case statements (length of list)
 */
static void
genswitch(int num, TWORD type, struct swents **p, int n)
{
	P1ND *r, *q;
	int i;

	if (mygenswitch(num, type, p, n))
		return;

	/* simple switch code */
	for (i = 1; i <= n; ++i) {
		/* already in 1 */
		r = tempnode(num, type, 0, 0);
		q = xbcon(p[i]->sval, NULL, type);
		r = buildtree(NE, r, clocal(q));
		xcbranch(r, p[i]->slab);
	}
	if (p[0]->slab > 0)
		branch(p[0]->slab);
}

/*
 * Declare a variable or prototype.
 */
static struct symtab *
init_declarator(P1ND *tn, P1ND *p, int assign, P1ND *a, char *as)
{
	int class = (int)glval(tn);
	struct symtab *sp;

	p = aryfix(p);
	p = tymerge(tn, p);
	if (a) {
		struct attr *ap = gcc_attr_wrapper(a);
		p->n_ap = attr_add(p->n_ap, ap);
	}

	p->n_sp = sp = lookup((char *)p->n_sp, 0); /* XXX */

	if (fun_inline && ISFTN(p->n_type))
		sp->sflags |= SINLINE;

	if (!ISFTN(p->n_type)) {
		if (assign) {
			defid2(p, class, as);
			sp = p->n_sp;
			sp->sflags |= SASG;
			if (sp->sflags & SDYNARRAY)
				uerror("can't initialize dynamic arrays");
			lcommdel(sp);
		} else
			nidcl2(p, class, as);
	} else {
		extern P1ND *parlink;
		if (assign)
			uerror("cannot initialise function");
		defid2(p, uclass(class), as);
		sp = p->n_sp;
		if (sp->sdf->dlst == 0 && !issyshdr)
			warner(Wstrict_prototypes);
		if (parlink) {
			/* dynamic sized arrays in prototypes */
			p1tfree(parlink); /* Free delayed tree */
			parlink = NULL;
		}
	}
	p1tfree(p);
	if (issyshdr)
		sp->sflags |= SINSYS; /* declared in system header */
	return sp;
}

/*
 * Declare old-stype function arguments.
 */
static void
oldargs(P1ND *p)
{
	blevel++;
	p->n_op = TYPE;
	p->n_type = FARG;
	p->n_sp = lookup((char *)p->n_sp, 0);/* XXX */
	defid(p, PARAM);
	blevel--;
}

/*
 * Set NAME nodes to a null name and index of LB nodes to NOOFFSET
 * unless clr is one, in that case preserve variable name.
 */
static P1ND *
namekill(P1ND *p, int clr)
{
	P1ND *q;
	int o = p->n_op;

	switch (coptype(o)) {
	case LTYPE:
		if (o == NAME) {
			if (clr)
				p->n_sp = NULL;
			else
				p->n_sp = lookup((char *)p->n_sp, 0);/* XXX */
		}
		break;

	case UTYPE:
		p->n_left = namekill(p->n_left, clr);
		break;

        case BITYPE:
                p->n_left = namekill(p->n_left, clr);
		if (o == LB) {
			if (clr) {
				p1tfree(p->n_right);
				p->n_right = bcon(NOOFFSET);
			} else
				p->n_right = eve(p->n_right);
		} else if (o == CALL)
			p->n_right = namekill(p->n_right, 1);
		else
			p->n_right = namekill(p->n_right, clr);
		if (o == TYMERGE) {
			q = tymerge(p->n_left, p->n_right);
			q->n_ap = attr_add(q->n_ap, p->n_ap);
			p1tfree(p->n_left);
			p1nfree(p);
			p = q;
		}
		break;
	}
	return p;
}

/*
 * Declare function arguments.
 */
static P1ND *
funargs(P1ND *p)
{
	extern P1ND *arrstk[10];

	if (p->n_op == ELLIPSIS)
		return p;

	p = namekill(p, 0);
	if (ISFTN(p->n_type))
		p->n_type = INCREF(p->n_type);
	if (ISARY(p->n_type)) {
		p->n_type += (PTR-ARY);
		if (p->n_df->ddim == -1)
			p1tfree(arrstk[0]), arrstk[0] = NULL;
		p->n_df++;
	}
	if (p->n_type == VOID && p->n_sp->sname == NULL)
		return p; /* sanitycheck later */
	else if (p->n_sp->sname == NULL)
		uerror("argument missing");
	else
		defid(p, PARAM);
	return p;
}

static P1ND *
listfw(P1ND *p, P1ND * (*f)(P1ND *))
{
        if (p->n_op == CM) {
                p->n_left = listfw(p->n_left, f);
                p->n_right = (*f)(p->n_right);
        } else
                p = (*f)(p);
	return p;
}


/*
 * Declare a function.
 */
static void
fundef(P1ND *tp, P1ND *p)
{
	extern int prolab;
	struct symtab *s;
	P1ND *q, *typ;
	int class = (int)glval(tp), oclass, ctval;

	/*
	 * We discard all names except for those needed for
	 * parameter declaration. While doing that, also change
	 * non-constant array sizes to unknown.
	 */
	ctval = tvaloff;
	for (q = p; coptype(q->n_op) != LTYPE &&
	    q->n_left->n_op != NAME; q = q->n_left) {
		if (q->n_op == CALL)
			q->n_right = namekill(q->n_right, 1);
	}
	if (q->n_op != CALL && q->n_op != UCALL) {
		uerror("invalid function definition");
		p = bdty(UCALL, p);
	} else if (q->n_op == CALL) {
		blevel = 1;
		argoff = ARGINIT;
		if (oldstyle == 0)
			q->n_right = listfw(q->n_right, funargs);
		p1listf(q->n_right, argsave);
		blevel = 0;
	}

	p = typ = tymerge(tp, p);
#ifdef GCC_COMPAT
	/* gcc seems to discard __builtin_ when declaring functions */
	if (strncmp("__builtin_", (char *)typ->n_sp, 10) == 0)
		typ->n_sp = (struct symtab *)((char *)typ->n_sp + 10);
#endif
	s = typ->n_sp = lookup((char *)typ->n_sp, 0); /* XXX */

	oclass = s->sclass;
	if (class == STATIC && oclass == EXTERN)
		werror("%s was first declared extern, then static", s->sname);

	if (fun_inline) {
		/* special syntax for inline functions */
		if (! strcmp(s->sname,"main")) 
			uerror("cannot inline main()");

		s->sflags |= SINLINE;
		inline_start(s, class);
		if (class == EXTERN)
			class = EXTDEF;
	} else if (class == EXTERN)
		class = SNULL; /* same result */

	cftnsp = s;
	defid(p, class);
	if (s->sdf->dlst == 0 && !issyshdr)
		warner(Wstrict_prototypes);
#ifdef GCC_COMPAT
	if (attr_find(p->n_ap, GCC_ATYP_ALW_INL)) {
		/* Temporary turn on temps to make always_inline work */
		alwinl = 1;
		if (xtemps == 0) alwinl |= 2;
		xtemps = 1;
	}
#endif
	prolab = getlab();
	send_passt(IP_PROLOG, -1, getexname(cftnsp), cftnsp->stype,
	    cftnsp->sclass == EXTDEF, prolab, ctval);
	blevel++;
#ifdef STABS
	if (gflag)
		stabs_func(s);
#endif
	p1tfree(tp);
	p1tfree(p);

}

static void
fend(void)
{
	if (blevel)
		cerror("function level error");
	ftnend();
	fun_inline = 0;
	if (alwinl & 2) xtemps = 0;
	alwinl = 0;
	cftnsp = NULL;
}

P1ND *
structref(P1ND *p, int f, char *name)
{
	P1ND *r;

	if (f == DOT)
		p = buildtree(ADDROF, p, NULL);
	r = biop(NAME, NULL, NULL);
	r->n_name = name;
	r = buildtree(STREF, p, r);
	return r;
}

static void
olddecl(P1ND *p, P1ND *a)
{
	struct symtab *s;

	p = namekill(p, 0);
	s = p->n_sp;
	if (s->slevel != 1 || s->stype == UNDEF)
		uerror("parameter '%s' not defined", s->sname);
	else if (s->stype != FARG)
		uerror("parameter '%s' redefined", s->sname);

	s->stype = p->n_type;
	s->sdf = p->n_df;
	s->sap = p->n_ap;
	if (a)
		attr_add(s->sap, gcc_attr_wrapper(a));
	p1nfree(p);
}

void
branch(int lbl)
{
	int r = reached++;
	ecomp(biop(GOTO, bcon(lbl), NULL));
	reached = r;
}

/*
 * Create a printable string based on an encoded string.
 */
static char *
mkpstr(char *str)
{
	char *os, *s;
	size_t l = strlen(str) + 3; /* \t + \n + \0 */

	os = s = stmtalloc(l);
	*s++ = '\t';
	while (*str) {
		if (*str == '\\')
			*s++ = esccon(&str);
		else
			*s++ = *str++;
	}
	*s++ = '\n';
	*s = 0;

	return os;
}

/*
 * Fake a symtab entry for compound literals.
 */
static struct symtab *
clbrace(P1ND *p)
{
	struct symtab *sp;

	sp = getsymtab(simname("cl"), STEMP);
	sp->stype = p->n_type;
	sp->squal = p->n_qual;
	sp->sdf = p->n_df;
	sp->sss = p->pss;
	sp->sap = p->n_ap;
	p1tfree(p);
	if (blevel == 0 && xnf != NULL) {
		sp->sclass = STATIC;
		sp->slevel = 2;
		sp->soffset = getlab();
	} else {
		sp->sclass = blevel ? AUTO : STATIC;
		if (!ISARY(sp->stype) || sp->sdf->ddim != NOOFFSET) {
			sp->soffset = NOOFFSET;
			oalloc(sp, &autooff);
		}
	}
	beginit(sp);
	return sp;
}

char *
simname(char *s)
{
	size_t len = strlen(s) + 10 + 1;
	char *w = tmpalloc(len); /* uncommon */

	snprintf(w, len, "%s%d", s, getlab());
	return w;
}

P1ND *
biop(int op, P1ND *l, P1ND *r)
{
	return block(op, l, r, INT, 0, 0);
}

static P1ND *
cmop(P1ND *l, P1ND *r)
{
	return biop(CM, l, r);
}

static P1ND *
voidcon(void)
{
	return block(ICON, NULL, NULL, STRTY, 0, 0);
}

/* Support for extended assembler a' la' gcc style follows below */

static P1ND *
xmrg(P1ND *out, P1ND *in)
{
	P1ND *p = in;

	if (p->n_op == XARG) {
		in = cmop(out, p);
	} else {
		while (p->n_left->n_op == CM)
			p = p->n_left;
		p->n_left = cmop(out, p->n_left);
	}
	return in;
}

/*
 * Put together in and out node lists in one list, and balance it with
 * the constraints on the right side of a CM node.
 */
static P1ND *
xcmop(P1ND *out, P1ND *in, P1ND *str)
{
	P1ND *p, *q;

	if (out) {
		/* D out-list sanity check */
		for (p = out; p->n_op == CM; p = p->n_left) {
			q = p->n_right;
			if (q->n_name[0] != '=' && q->n_name[0] != '+')
				uerror("output missing =");
		}
		if (p->n_name[0] != '=' && p->n_name[0] != '+')
			uerror("output missing =");
		if (in == NULL)
			p = out;
		else
			p = xmrg(out, in);
	} else if (in) {
		p = in;
	} else
		p = voidcon();

	if (str == NULL)
		str = voidcon();
	return cmop(p, str);
}

/*
 * Generate a XARG node based on a string and an expression.
 */
static P1ND *
xasmop(char *str, P1ND *p)
{

	p = biop(XARG, p, NULL);
	p->n_name = str;
	return p;
}

/*
 * Generate a XASM node based on a string and an expression.
 */
static void
mkxasm(char *str, P1ND *p)
{
	P1ND *q;

	q = biop(XASM, p->n_left, p->n_right);
	q->n_name = str;
	p1nfree(p);
	ecomp(optloop(q));
}

static struct attr *
gcc_attr_wrapper(P1ND *p)
{
#ifdef GCC_COMPAT
	return gcc_attr_parse(p);
#else
	if (p != NULL)
		uerror("gcc attribute used");
	return NULL;
#endif
}

#ifdef GCC_COMPAT
static P1ND *
tyof(P1ND *p)
{
	static struct symtab spp;
	P1ND *q = block(TYPE, NULL, NULL, p->n_type, p->n_df, p->pss);
	q->n_qual = p->n_qual;
	q->n_sp = &spp; /* for typenode */
	p1walkf(p, putjops, 0);
	p1tfree(p);
	return q;
}

#else
static P1ND *
tyof(P1ND *p)
{
	uerror("typeof gcc extension");
	return bcon(0);
}
#endif

/*
 * Traverse an unhandled expression tree bottom-up and call buildtree()
 * or equivalent as needed.
 */
P1ND *
eve(P1ND *p)
{
	struct symtab *sp;
	P1ND *r, *p1, *p2;
	int x;

	p1 = p->n_left;
	p2 = p->n_right;
	switch (p->n_op) {
	case NAME:
		sp = lookup((char *)p->n_sp,
		    attr_find(p->n_ap, ATTR_P1LABELS) ? SLBLNAME|STEMP : 0);
		if (sp->sflags & SINLINE)
			inline_ref(sp);
		r = nametree(sp);
		if (sp->sflags & SDYNARRAY)
			r = buildtree(UMUL, r, NULL);
#ifdef GCC_COMPAT
		if (attr_find(sp->sap, GCC_ATYP_DEPRECATED))
			warner(Wdeprecated_declarations, sp->sname);
#endif
		break;

	case DOT:
	case STREF:
		r = structref(eve(p1), p->n_op, (char *)p2->n_sp);
		p1nfree(p2);
		break;

	case CAST:
		p2 = eve(p2);
#ifndef NO_COMPLEX
		if (ANYCX(p1) || ANYCX(p2)) {
			r = cxcast(p1, p2);
			break;
		}
#endif
#ifdef TARGET_TIMODE
		if ((r = gcc_eval_ticast(CAST, p1, p2)) != NULL)
			break;
#endif
		p1 = buildtree(CAST, p1, p2);
		p1nfree(p1->n_left);
		r = p1->n_right;
		p1nfree(p1);
		break;


	case SZOF:
		x = xinline; xinline = 0; /* XXX hack */
		if (glval(p2) == 0)
			p1 = eve(p1);
		else
			TYMFIX(p1);
		p1nfree(p2);
		r = doszof(p1);
		xinline = x;
		break;

	case LB:
		p1 = eve(p1);
		p2 = eve(p2);
#ifdef TARGET_TIMODE
		if (isti(p2)) {
			P1ND *s = block(NAME, NULL, NULL, LONG, 0, 0);
			if ((r = gcc_eval_ticast(CAST, s, p2)) != NULL)
				p2 = r;
			p1nfree(s);
		}
#endif
		r = buildtree(UMUL, buildtree(PLUS, p1, p2), NULL);
		break;

	case COMPL:
#ifndef NO_COMPLEX
		p1 = eve(p1);
		if (ANYCX(p1))
			r = cxconj(p1);
		else
			r = buildtree(COMPL, p1, NULL);
		break;
#endif
	case UPLUS:
		r = eve(p1);
		if (r->n_op == FLD || r->n_type < INT)
			r = buildtree(PLUS, r, bcon(0)); /* must be size int */
		break;

	case UMINUS:
#ifndef NO_COMPLEX
		p1 = eve(p1);
		if (ANYCX(p1))
			r = cxop(UMINUS, p1, p1);
		else
			r = buildtree(UMINUS, p1, NULL);
		break;
#endif
	case NOT:
	case UMUL:
		p1 = eve(p1);
#ifdef TARGET_TIMODE
		if ((r = gcc_eval_tiuni(p->n_op, p1)) != NULL)
			break;
#endif
#ifndef NO_COMPLEX
		if (p->n_op == NOT && ANYCX(p1))
			p1 = cxop(NE, p1, bcon(0));
#endif
		r = buildtree(p->n_op, p1, NULL);
		break;

	case ADDROF:
		r = eve(p1);
		if (ISFTN(p->n_type)/* || ISARY(p->n_type) */){
#ifdef notdef
			werror( "& before array or function: ignored" );
#endif
		} else
			r = buildtree(ADDROF, r, NULL);
		break;

	case UCALL:
		p2 = NULL;
		/* FALLTHROUGH */
	case CALL:
		if (p1->n_op == NAME) {
			sp = lookup((char *)p1->n_sp, 0);
#ifndef NO_C_BUILTINS
			if (sp->sflags & SBUILTIN) {
				p1nfree(p1);
				r = builtin_check(sp, p2);
				break;
			}
#endif
			if (sp->stype == UNDEF) {
				p1->n_type = FTN|INT;
				p1->n_sp = sp;
				p1->n_ap = NULL;
				defid(p1, EXTERN);
			}
			p1nfree(p1);
#ifdef GCC_COMPAT
			if (attr_find(sp->sap, GCC_ATYP_DEPRECATED))
				warner(Wdeprecated_declarations, sp->sname);
#endif
			if (p->n_op == CALL)
				p2 = eve(p2);
			r = doacall(sp, nametree(sp), p2);
		} else {
			if (p->n_op == CALL)
				p2 = eve(p2);
			r = doacall(NULL, eve(p1), p2);
		}
		break;

#ifndef NO_COMPLEX
	case XREAL:
	case XIMAG:
		p1 = eve(p1);
		r = cxelem(p->n_op, p1);
		break;
#endif

	case COLON:
	case MUL:
	case DIV:
	case PLUS:
	case MINUS:
	case ASSIGN:
	case EQ:
	case NE:
	case OROR:
	case ANDAND:
#ifndef NO_COMPLEX
		p1 = eve(p1);
		p2 = eve(p2);
#ifdef TARGET_TIMODE
		if ((r = gcc_eval_timode(p->n_op, p1, p2)) != NULL)
			break;
#endif
		if (ANYCX(p1) || ANYCX(p2)) {
			r = cxop(p->n_op, p1, p2);
		} else if (ISITY(p1->n_type) || ISITY(p2->n_type)) {
			r = imop(p->n_op, p1, p2);
		} else
			r = buildtree(p->n_op, p1, p2);
		break;
#endif
	case MOD:
	case CM:
	case GT:
	case GE:
	case LT:
	case LE:
	case RS:
	case LS:
	case RSEQ:
	case LSEQ:
	case AND:
	case OR:
	case ER:
	case EREQ:
	case OREQ:
	case ANDEQ:
	case QUEST:
		p1 = eve(p1);
		p2 = eve(p2);
#ifdef TARGET_TIMODE
		if ((r = gcc_eval_timode(p->n_op, p1, p2)) != NULL)
			break;
#endif
		r = buildtree(p->n_op, p1, p2);
		break;

	case BIQUEST: /* gcc e ?: e op */
		p1 = eve(p1);
		r = tempnode(0, p1->n_type, p1->n_df, p1->pss);
		p2 = eve(biop(COLON, p1tcopy(r), p2));
		r = buildtree(QUEST, buildtree(ASSIGN, r, p1), p2);
		break;

	case INCR:
	case DECR:
	case MODEQ:
	case MINUSEQ:
	case PLUSEQ:
	case MULEQ:
	case DIVEQ:
		p1 = eve(p1);
		p2 = eve(p2);
#ifdef TARGET_TIMODE
		if ((r = gcc_eval_timode(p->n_op, p1, p2)) != NULL)
			break;
#endif
#ifndef NO_COMPLEX
		if (ANYCX(p1) || ANYCX(p2)) {
			r = cxop(UNASG p->n_op, p1tcopy(p1), p2);
			r = cxop(ASSIGN, p1, r);
			break;
		} else if (ISITY(p1->n_type) || ISITY(p2->n_type)) {
			r = imop(UNASG p->n_op, p1tcopy(p1), p2);
			r = cxop(ASSIGN, p1, r);
			break;
		}
		/* FALLTHROUGH */
#endif
		r = buildtree(p->n_op, p1, p2);
		break;

	case STRING:
		r = strend(p->n_name, (TWORD)glval(p));
		break;

	case COMOP:
		if (p1->n_op == GOTO) {
			/* inside ({ }), eve already called */
			r = buildtree(p->n_op, p1, p2);
		} else {
			p1 = eve(p1);
			r = buildtree(p->n_op, p1, eve(p2));
		}
		break;

	case TYPE:
	case ICON:
	case FCON:
	case TEMP:
		return p;

	case CLOP:
		r = nametree(p->n_sp);
		break;

	default:
#ifdef PCC_DEBUG
		p1fwalk(p, eprint, 0);
#endif
		cerror("eve");
		r = NULL;
	}
	p1nfree(p);
	return r;
}

int
con_e(P1ND *p)
{
	return (int)icons(optloop(eve(p)));
}

void
uawarn(P1ND *p, char *s)
{
	if (p == 0)
		return;
	if (attrwarn)
		werror("unhandled %s attribute", s);
	p1tfree(p);
}

static void
dainit(P1ND *d, P1ND *a)
{
	if (d == NULL) {
		asginit(a);
	} else if (d->n_op == CM) {
		int is = con_e(d->n_left);
		int ie = con_e(d->n_right);
		int i;

		p1nfree(d);
		if (ie < is)
			uerror("negative initializer range");
		desinit(biop(LB, NULL, bcon(is)));
		for (i = is; i < ie; i++)
			asginit(p1tcopy(a));
		asginit(a);
	} else {
		cerror("dainit");
	}
}

/*
 * Traverse down and tymerge() where appropriate.
 */
static P1ND *
tymfix(P1ND *p)
{
	P1ND *q;
	int o = coptype(p->n_op);

	switch (o) {
	case LTYPE:
		break;
	case UTYPE:
		p->n_left = tymfix(p->n_left);
		break;
	case BITYPE:
		p->n_left = tymfix(p->n_left);
		p->n_right = tymfix(p->n_right);
		if (p->n_op == TYMERGE) {
			q = tymerge(p->n_left, p->n_right);
			q->n_ap = attr_add(q->n_ap, p->n_ap);
			p1tfree(p->n_left);
			p1nfree(p);
			p = q;
		}
		break;
	}
	return p;
}

static P1ND *
aryfix(P1ND *p)
{
	P1ND *q;

	for (q = p; q->n_op != NAME; q = q->n_left) {
		if (q->n_op == LB) {
			q->n_right = optloop(eve(q->n_right));
			if ((blevel == 0 || rpole != NULL) &&
			    !nncon(q->n_right))
				uerror("array size not constant"); 
			/*
			 * Checks according to 6.7.5.2 clause 1:
			 * "...the expression shall have an integer type."
			 * "If the expression is a constant expression,	 
			 * it shall have a value greater than zero."
			 */
			if (!ISINTEGER(q->n_right->n_type))
				werror("array size is not an integer");
			else if (q->n_right->n_op == ICON &&
			    glval(q->n_right) < 0 &&
			    glval(q->n_right) != NOOFFSET) {
					uerror("array size cannot be negative");
					slval(q->n_right, 1);
			}
		} else if (q->n_op == CALL)
			q->n_right = namekill(q->n_right, 1);
	}
	return p;
}

struct labs {
	struct labs *next;
	int lab;
} *labp;

static void
savlab(int lab)
{
	struct labs *l = tmpalloc(sizeof(struct labs)); /* uncommon */
	l->lab = lab < 0 ? -lab : lab;
	l->next = labp;
	labp = l;
}

int *
mkclabs(void)
{
	struct labs *l;
	int i, *rv;

	for (i = 0, l = labp; l; l = l->next, i++)
		;
	rv = tmpalloc((i+1)*sizeof(int));	/* uncommon */
	for (i = 0, l = labp; l; l = l->next, i++)
		rv[i] = l->lab;
	rv[i] = 0;
	labp = 0;
	return rv;
}

void
xcbranch(P1ND *p, int lab)
{
#ifndef NO_COMPLEX
	if (ANYCX(p))
		p = cxop(NE, p, bcon(0));
#endif
	cbranch(buildtree(NOT, p, NULL), bcon(lab));
}

/*
 * New a case entry to genlist.
 * tn is type, e is expression.
 */
static struct genlist *
newgen(P1ND *tn, P1ND *e)
{
	struct genlist *ng;
	TWORD t;

	if (tn) {
		t = tn->n_type;
		p1tfree(tn);
	} else
		t = 0;

	/* add new entry */
	ng = malloc(sizeof(struct genlist));
	ng->next = NULL;
	ng->t = t;
	ng->p = e;
	return ng;
}

/*
 * Add a case entry to genlist.
 * g is list, ng is new entry.
 */
static struct genlist *
addgen(struct genlist *g, struct genlist *ng)
{
	struct genlist *w;

	/* search for duplicate type */
	for (w = g; w; w = w->next) {
		if (w->t == ng->t)
			uerror("duplicate type in _Generic");
	}
	ng->next = g;
	return ng;
}

static P1ND *
dogen(struct genlist *g, P1ND *e)
{
	struct genlist *ng;
	P1ND *w, *p;

	e = eve(e);

	/* search for direct match */
	for (ng = g, w = p = NULL; ng; ng = ng->next) {
		if (ng->t == 0)
			p = ng->p; /* save default */
		if (e->n_type == ng->t)
			w = ng->p;
	}

	/* if no match, use generic */
	if (w == NULL) {
		if (p == NULL) {
			uerror("_Generic: no default found");
			p = bcon(0);
		}
		w = p;
	}

	/* free tree */
	while (g) {
		if (g->p != w)
			p1tfree(g->p);
		ng = g->next;
		free(g);
		g = ng;
	}

	p1tfree(e);
	return w;
}
