// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "build/parser.cxx" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hxx"

// User implementation prologue.

#line 51 "build/parser.cxx" // lalr1.cc:412
// Unqualified %code blocks.
#line 75 "parser.y" // lalr1.cc:413

    #include <iostream>     // cerr, endl
    #include <utility>      // move
    #include <string>

    #include "scanner.hpp"

    using std::move;

    #ifdef  yylex
    # undef yylex
    #endif
    #define yylex scanner->lex

    template <class T, class V>
    T&& enlist(T& t, V& v)
    {
        t.push_back(move(v));
        return move(t);
    }

#line 75 "build/parser.cxx" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 161 "build/parser.cxx" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (yy::scanner* scanner_yyarg, ParserCallback* cb_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      cb (cb_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 23: // inform_expr
        value.copy< ast::Expression > (other.value);
        break;

      case 22: // determ_depen
        value.copy< ast::FunctionOf > (other.value);
        break;

      case 25: // inform_quant
      case 26: // entropy
      case 27: // mutual_inf
        value.copy< ast::Quantity > (other.value);
        break;

      case 19: // inform_inequ
        value.copy< ast::Relation > (other.value);
        break;

      case 24: // inform_term
        value.copy< ast::Term > (other.value);
        break;

      case 20: // markov_chain
      case 21: // mutual_indep
      case 28: // mut_inf_core
        value.copy< ast::VarCore > (other.value);
        break;

      case 30: // var_list
        value.copy< ast::VarList > (other.value);
        break;

      case 4: // NUM
        value.copy< double > (other.value);
        break;

      case 5: // SIGN
      case 6: // REL
        value.copy< int > (other.value);
        break;

      case 3: // NAME
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 23: // inform_expr
        value.copy< ast::Expression > (v);
        break;

      case 22: // determ_depen
        value.copy< ast::FunctionOf > (v);
        break;

      case 25: // inform_quant
      case 26: // entropy
      case 27: // mutual_inf
        value.copy< ast::Quantity > (v);
        break;

      case 19: // inform_inequ
        value.copy< ast::Relation > (v);
        break;

      case 24: // inform_term
        value.copy< ast::Term > (v);
        break;

      case 20: // markov_chain
      case 21: // mutual_indep
      case 28: // mut_inf_core
        value.copy< ast::VarCore > (v);
        break;

      case 30: // var_list
        value.copy< ast::VarList > (v);
        break;

      case 4: // NUM
        value.copy< double > (v);
        break;

      case 5: // SIGN
      case 6: // REL
        value.copy< int > (v);
        break;

      case 3: // NAME
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::Expression v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::FunctionOf v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::Quantity v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::Relation v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::Term v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::VarCore v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::VarList v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const double v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 23: // inform_expr
        value.template destroy< ast::Expression > ();
        break;

      case 22: // determ_depen
        value.template destroy< ast::FunctionOf > ();
        break;

      case 25: // inform_quant
      case 26: // entropy
      case 27: // mutual_inf
        value.template destroy< ast::Quantity > ();
        break;

      case 19: // inform_inequ
        value.template destroy< ast::Relation > ();
        break;

      case 24: // inform_term
        value.template destroy< ast::Term > ();
        break;

      case 20: // markov_chain
      case 21: // mutual_indep
      case 28: // mut_inf_core
        value.template destroy< ast::VarCore > ();
        break;

      case 30: // var_list
        value.template destroy< ast::VarList > ();
        break;

      case 4: // NUM
        value.template destroy< double > ();
        break;

      case 5: // SIGN
      case 6: // REL
        value.template destroy< int > ();
        break;

      case 3: // NAME
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 23: // inform_expr
        value.move< ast::Expression > (s.value);
        break;

      case 22: // determ_depen
        value.move< ast::FunctionOf > (s.value);
        break;

      case 25: // inform_quant
      case 26: // entropy
      case 27: // mutual_inf
        value.move< ast::Quantity > (s.value);
        break;

      case 19: // inform_inequ
        value.move< ast::Relation > (s.value);
        break;

      case 24: // inform_term
        value.move< ast::Term > (s.value);
        break;

      case 20: // markov_chain
      case 21: // mutual_indep
      case 28: // mut_inf_core
        value.move< ast::VarCore > (s.value);
        break;

      case 30: // var_list
        value.move< ast::VarList > (s.value);
        break;

      case 4: // NUM
        value.move< double > (s.value);
        break;

      case 5: // SIGN
      case 6: // REL
        value.move< int > (s.value);
        break;

      case 3: // NAME
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  parser::symbol_type
  parser::make_END (const location_type& l)
  {
    return symbol_type (token::T_END, l);
  }

  parser::symbol_type
  parser::make_NAME (const std::string& v, const location_type& l)
  {
    return symbol_type (token::T_NAME, v, l);
  }

  parser::symbol_type
  parser::make_NUM (const double& v, const location_type& l)
  {
    return symbol_type (token::T_NUM, v, l);
  }

  parser::symbol_type
  parser::make_SIGN (const int& v, const location_type& l)
  {
    return symbol_type (token::T_SIGN, v, l);
  }

  parser::symbol_type
  parser::make_REL (const int& v, const location_type& l)
  {
    return symbol_type (token::T_REL, v, l);
  }



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 23: // inform_expr
        value.move< ast::Expression > (that.value);
        break;

      case 22: // determ_depen
        value.move< ast::FunctionOf > (that.value);
        break;

      case 25: // inform_quant
      case 26: // entropy
      case 27: // mutual_inf
        value.move< ast::Quantity > (that.value);
        break;

      case 19: // inform_inequ
        value.move< ast::Relation > (that.value);
        break;

      case 24: // inform_term
        value.move< ast::Term > (that.value);
        break;

      case 20: // markov_chain
      case 21: // mutual_indep
      case 28: // mut_inf_core
        value.move< ast::VarCore > (that.value);
        break;

      case 30: // var_list
        value.move< ast::VarList > (that.value);
        break;

      case 4: // NUM
        value.move< double > (that.value);
        break;

      case 5: // SIGN
      case 6: // REL
        value.move< int > (that.value);
        break;

      case 3: // NAME
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 23: // inform_expr
        value.copy< ast::Expression > (that.value);
        break;

      case 22: // determ_depen
        value.copy< ast::FunctionOf > (that.value);
        break;

      case 25: // inform_quant
      case 26: // entropy
      case 27: // mutual_inf
        value.copy< ast::Quantity > (that.value);
        break;

      case 19: // inform_inequ
        value.copy< ast::Relation > (that.value);
        break;

      case 24: // inform_term
        value.copy< ast::Term > (that.value);
        break;

      case 20: // markov_chain
      case 21: // mutual_indep
      case 28: // mut_inf_core
        value.copy< ast::VarCore > (that.value);
        break;

      case 30: // var_list
        value.copy< ast::VarList > (that.value);
        break;

      case 4: // NUM
        value.copy< double > (that.value);
        break;

      case 5: // SIGN
      case 6: // REL
        value.copy< int > (that.value);
        break;

      case 3: // NAME
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 23: // inform_expr
        yylhs.value.build< ast::Expression > ();
        break;

      case 22: // determ_depen
        yylhs.value.build< ast::FunctionOf > ();
        break;

      case 25: // inform_quant
      case 26: // entropy
      case 27: // mutual_inf
        yylhs.value.build< ast::Quantity > ();
        break;

      case 19: // inform_inequ
        yylhs.value.build< ast::Relation > ();
        break;

      case 24: // inform_term
        yylhs.value.build< ast::Term > ();
        break;

      case 20: // markov_chain
      case 21: // mutual_indep
      case 28: // mut_inf_core
        yylhs.value.build< ast::VarCore > ();
        break;

      case 30: // var_list
        yylhs.value.build< ast::VarList > ();
        break;

      case 4: // NUM
        yylhs.value.build< double > ();
        break;

      case 5: // SIGN
      case 6: // REL
        yylhs.value.build< int > ();
        break;

      case 3: // NAME
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 100 "parser.y" // lalr1.cc:859
    { /* allow empty (or pure comment) lines */ }
#line 1099 "build/parser.cxx" // lalr1.cc:859
    break;

  case 3:
#line 101 "parser.y" // lalr1.cc:859
    { cb->relation(move(yystack_[0].value.as< ast::Relation > ())); }
#line 1105 "build/parser.cxx" // lalr1.cc:859
    break;

  case 4:
#line 102 "parser.y" // lalr1.cc:859
    { cb->mutual_independence(move(yystack_[0].value.as< ast::VarCore > ())); }
#line 1111 "build/parser.cxx" // lalr1.cc:859
    break;

  case 5:
#line 103 "parser.y" // lalr1.cc:859
    { cb->markov_chain(move(yystack_[0].value.as< ast::VarCore > ())); }
#line 1117 "build/parser.cxx" // lalr1.cc:859
    break;

  case 6:
#line 104 "parser.y" // lalr1.cc:859
    { cb->function_of(move(yystack_[0].value.as< ast::FunctionOf > ())); }
#line 1123 "build/parser.cxx" // lalr1.cc:859
    break;

  case 7:
#line 109 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::Relation > () = {yystack_[2].value.as< ast::Expression > (), yystack_[1].value.as< int > (), yystack_[0].value.as< ast::Expression > ()}; }
#line 1129 "build/parser.cxx" // lalr1.cc:859
    break;

  case 8:
#line 112 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::VarCore > () = enlist(yystack_[2].value.as< ast::VarCore > (), yystack_[0].value.as< ast::VarList > ()); }
#line 1135 "build/parser.cxx" // lalr1.cc:859
    break;

  case 9:
#line 113 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::VarCore > () = {yystack_[4].value.as< ast::VarList > (), yystack_[2].value.as< ast::VarList > (), yystack_[0].value.as< ast::VarList > ()}; }
#line 1141 "build/parser.cxx" // lalr1.cc:859
    break;

  case 10:
#line 116 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::VarCore > () = enlist(yystack_[2].value.as< ast::VarCore > (), yystack_[0].value.as< ast::VarList > ()); }
#line 1147 "build/parser.cxx" // lalr1.cc:859
    break;

  case 11:
#line 117 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::VarCore > () = {yystack_[2].value.as< ast::VarList > (), yystack_[0].value.as< ast::VarList > ()}; }
#line 1153 "build/parser.cxx" // lalr1.cc:859
    break;

  case 12:
#line 120 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::FunctionOf > () = {yystack_[2].value.as< ast::VarList > (), yystack_[0].value.as< ast::VarList > ()}; }
#line 1159 "build/parser.cxx" // lalr1.cc:859
    break;

  case 13:
#line 125 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::Expression > () = enlist(yystack_[2].value.as< ast::Expression > (), yystack_[0].value.as< ast::Term > ().flip_sign(yystack_[1].value.as< int > ())); }
#line 1165 "build/parser.cxx" // lalr1.cc:859
    break;

  case 14:
#line 126 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::Expression > () = {yystack_[0].value.as< ast::Term > ().flip_sign(yystack_[1].value.as< int > ())}; }
#line 1171 "build/parser.cxx" // lalr1.cc:859
    break;

  case 15:
#line 127 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::Expression > () = {yystack_[0].value.as< ast::Term > ()}; }
#line 1177 "build/parser.cxx" // lalr1.cc:859
    break;

  case 16:
#line 130 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::Term > () = {yystack_[1].value.as< double > (), yystack_[0].value.as< ast::Quantity > ()}; }
#line 1183 "build/parser.cxx" // lalr1.cc:859
    break;

  case 17:
#line 131 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::Term > () = { 1, yystack_[0].value.as< ast::Quantity > ()}; }
#line 1189 "build/parser.cxx" // lalr1.cc:859
    break;

  case 18:
#line 132 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::Term > () = {yystack_[0].value.as< double > ()}; }
#line 1195 "build/parser.cxx" // lalr1.cc:859
    break;

  case 19:
#line 135 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::Quantity > () = yystack_[0].value.as< ast::Quantity > (); }
#line 1201 "build/parser.cxx" // lalr1.cc:859
    break;

  case 20:
#line 136 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::Quantity > () = yystack_[0].value.as< ast::Quantity > (); }
#line 1207 "build/parser.cxx" // lalr1.cc:859
    break;

  case 21:
#line 139 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::Quantity > () = {{yystack_[1].value.as< ast::VarList > ()}}; }
#line 1213 "build/parser.cxx" // lalr1.cc:859
    break;

  case 22:
#line 140 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::Quantity > () = {{yystack_[3].value.as< ast::VarList > ()}, yystack_[1].value.as< ast::VarList > ()}; }
#line 1219 "build/parser.cxx" // lalr1.cc:859
    break;

  case 23:
#line 143 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::Quantity > () = {{yystack_[1].value.as< ast::VarCore > ()}}; }
#line 1225 "build/parser.cxx" // lalr1.cc:859
    break;

  case 24:
#line 144 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::Quantity > () = {{yystack_[3].value.as< ast::VarCore > ()}, yystack_[1].value.as< ast::VarList > ()}; }
#line 1231 "build/parser.cxx" // lalr1.cc:859
    break;

  case 25:
#line 147 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::VarCore > () = enlist(yystack_[2].value.as< ast::VarCore > (), yystack_[0].value.as< ast::VarList > ()); }
#line 1237 "build/parser.cxx" // lalr1.cc:859
    break;

  case 26:
#line 148 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::VarCore > () = {yystack_[2].value.as< ast::VarList > (), yystack_[0].value.as< ast::VarList > ()}; }
#line 1243 "build/parser.cxx" // lalr1.cc:859
    break;

  case 29:
#line 155 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::VarList > () = enlist(yystack_[2].value.as< ast::VarList > (), yystack_[0].value.as< std::string > ()); }
#line 1249 "build/parser.cxx" // lalr1.cc:859
    break;

  case 30:
#line 156 "parser.y" // lalr1.cc:859
    { yylhs.value.as< ast::VarList > () = {yystack_[0].value.as< std::string > ()}; }
#line 1255 "build/parser.cxx" // lalr1.cc:859
    break;


#line 1259 "build/parser.cxx" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -20;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
       7,   -20,    41,    21,    -9,    -6,    16,   -20,    30,    31,
     -20,    13,   -20,   -20,   -20,   -20,    25,   -20,   -20,    37,
      37,   -20,    37,    37,    21,    10,    37,    37,    37,    50,
      33,    35,    27,    22,    22,   -20,    52,     6,    22,    22,
     -20,   -20,    37,   -20,   -20,    37,   -20,    37,    37,    37,
      40,    42,    22,    22,    22,   -20,   -20
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,    30,    18,     0,     0,     0,     0,     3,     5,     4,
       6,     0,    15,    17,    19,    20,     0,    16,    14,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,    10,    13,     7,     0,    11,    12,
      29,    21,     0,    27,    23,     0,    28,     0,     0,     0,
       0,     0,    25,    26,     9,    22,    24
  };

  const signed char
  parser::yypgoto_[] =
  {
     -20,   -20,   -20,   -20,   -20,   -20,    34,     3,    58,   -20,
     -20,   -20,    29,   -19
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    31,    47,    16
  };

  const unsigned char
  parser::yytable_[] =
  {
      30,    32,    19,    33,    34,    20,    18,    37,    38,    39,
       1,     2,     3,    49,     2,     3,    21,     4,    24,    25,
       4,     5,    29,    50,     5,     2,    51,    35,    52,    53,
      54,     4,    26,    27,    28,     5,    43,    22,    29,    23,
       1,    29,    46,    29,    43,    41,    42,    44,    45,    29,
      46,     4,    55,    40,    56,     5,    29,    24,    29,    36,
      17,    48
  };

  const unsigned char
  parser::yycheck_[] =
  {
      19,    20,    11,    22,    23,    11,     3,    26,    27,    28,
       3,     4,     5,     7,     4,     5,     0,    10,     5,     6,
      10,    14,    16,    42,    14,     4,    45,    24,    47,    48,
      49,    10,     7,     8,     9,    14,     9,     7,    16,     8,
       3,    16,    15,    16,     9,    12,    13,    12,    13,    16,
      15,    10,    12,     3,    12,    14,    16,     5,    16,    25,
       2,    32
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     4,     5,    10,    14,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    30,    25,    24,    11,
      11,     0,     7,     8,     5,     6,     7,     8,     9,    16,
      30,    28,    30,    30,    30,    24,    23,    30,    30,    30,
       3,    12,    13,     9,    12,    13,    15,    29,    29,     7,
      30,    30,    30,    30,    30,    12,    12
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    17,    18,    18,    18,    18,    18,    19,    20,    20,
      21,    21,    22,    23,    23,    23,    24,    24,    24,    25,
      25,    26,    26,    27,    27,    28,    28,    29,    29,    30,
      30
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     1,     1,     1,     1,     3,     3,     5,
       3,     3,     3,     3,     2,     1,     2,     1,     1,     1,
       1,     4,     6,     4,     6,     3,     3,     1,     1,     3,
       1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NAME", "NUM", "SIGN", "REL",
  "'/'", "'.'", "':'", "'H'", "'('", "')'", "'|'", "'I'", "';'", "','",
  "$accept", "statement", "inform_inequ", "markov_chain", "mutual_indep",
  "determ_depen", "inform_expr", "inform_term", "inform_quant", "entropy",
  "mutual_inf", "mut_inf_core", "colon", "var_list", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   100,   100,   101,   102,   103,   104,   109,   112,   113,
     116,   117,   120,   125,   126,   127,   130,   131,   132,   135,
     136,   139,   140,   143,   144,   147,   148,   151,   152,   155,
     156
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      11,    12,     2,     2,    16,     2,     8,     7,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     9,    15,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    10,    14,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    13,     2,     2,     2,     2,     2,
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
       5,     6
    };
    const unsigned int user_token_number_max_ = 261;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1710 "build/parser.cxx" // lalr1.cc:1167
#line 159 "parser.y" // lalr1.cc:1168


void yy::parser::error(const parser::location_type& l, const std::string& m)
{
    throw yy::parser::syntax_error(l, m);
}
