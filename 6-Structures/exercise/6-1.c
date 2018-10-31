/*
Regis (a comp.lang.c regular) also provided a solution, which was far too big to post here.
It may still be available from his website(http://www.info.unicaen.fr/~regis/getword.html).
*/

/* K&R 6-1: "Our version of getword() does not properly handle
   underscores, string constants, or preprocessor control lines.
   Write a better version."

   This is intended to be a solution to K&R 6-1 in "category 0" as
   defined by the official rules given on Richard Heathfield's "The C
   Programming Language Answers To Exercises" page, found at
   http://users.powernet.co.uk/eton/kandr2/index.html.

   For more information on the language for which this is a lexical
   analyzer, please see the comment preceding getword() below.

   Note that there is a small modification to ungetch() as defined by
   K&R.  Hopefully this lies within the rules. */

/* knr61.c - answer to K&R2 exercise 6-1.
   Copyright (C) 2000 Ben Pfaff <blp@gnu.org>.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
   02111-1307, USA. */
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tokens.  Other non-whitespace characters self-represent themselves
   as tokens. */
enum token
  {
    TOK_ID = UCHAR_MAX + 1,     /* Identifier. */
    TOK_STRING,                 /* String constant. */
    TOK_CHAR,                   /* Character constant. */
    TOK_EOF                     /* End of file. */
  };

enum token getword (char *word, int lim);

static int skipws (void);
static int getstelem (char **, int *, int);
    
static int getch (void);
static void ungetch (int);
static void putch (char **, int *, int);

/* Main program for testing. */
int
main (void)
{
  ungetch ('\n');
  
  for (;;)
    {
      char word[64];
      enum token token;

      /* Get token. */
      token = getword (word, sizeof word);

      /* Print token type. */
      switch (token)
        {
        case TOK_ID:
          printf ("id");
          break;

        case TOK_STRING:
          printf ("string");
          break;

        case TOK_CHAR:
          printf ("char");
          break;

        case TOK_EOF:
          printf ("eof\n");
          return 0;

        default:
          printf ("other");
          word[0] = token;
          word[1] = '\0';
          break;
        }

      /* Print token value more or less unambiguously. */
      {
        const char *s;

        printf ("\t'");
        for (s = word; *s != '\0'; s++)
          if (isprint (*s) && *s != '\'')
            putchar (*s);
          else if (*s == '\'')
            printf ("\\'");
          else
            /* Potentially wrong. */
            printf ("\\x%02x", *s);
        printf ("'\n");
      }
    }
}

/* Parses C-like tokens from stdin:

        - Parses C identifiers and string and character constants.

        - Other characters, such as operators, punctuation, and digits
          not part of identifiers are considered as tokens in
          themselves.

        - Skip comments and preprocessor control lines.

   Does not handle trigraphs, line continuation with \, or numerous
   other special C features.

   Returns a token type.  This is either one of TOK_* above, or a single
   character in the range 0...UCHAR_MAX.

   If TOK_ID, TOK_STRING, or TOK_CHAR is returned, WORD[] is filled
   with the identifier or string value, truncated at LIM - 1
   characters and terminated with '\0'.

   For other returned token types, WORD[] is indeterminate. */
enum token
getword (char *word, int lim)
{
  int beg_line, c;
  
  for (;;)
    {
      beg_line = skipws ();
      c = getch ();

      if (!beg_line || c != '#')
        break;
      
      /* Skip preprocessor directive. */
      do
        {
          c = getch ();
          if (c == EOF)
            return TOK_EOF;
        }
      while (c != '\n');
      ungetch ('\n');
    }
  
  if (c == EOF)
    return TOK_EOF;
  else if (c == '_' || isalpha ((unsigned char) c))
    {
      do
        {
          putch (&word, &lim, c);
          c = getch ();
        }
      while (isalnum ((unsigned char) c) || c == '_');

      ungetch (c);
      return TOK_ID;
    }
  else if (c == '\'' || c == '"')
    {
      int quote = c;
      word[0] = '\0';
      while (getstelem (&word, &lim, quote))
        ;
      return quote == '\'' ? TOK_CHAR : TOK_STRING;
    }
  else
    return (unsigned char) c;
}

/* Skips whitespace and comments read from stdin.
   Returns nonzero if a newline was encountered, indicating that we're
   at the beginning of a line. */
static int
skipws (void)
{
  /* Classification of an input character. */
  enum class
    {
      CLS_WS = 0,               /* Whitespace. */
      CLS_BEG_CMT,              /* Slash-star beginning a comment. */
      CLS_END_CMT,              /* Star-slash ending a comment. */
      CLS_OTHER,                /* None of the above. */

      CLS_IN_CMT = 4            /* Combined with one of the above,
                                   indicates we're inside a comment. */
    };

  /* Either 0, if we're not inside a comment,
     or CLS_IN_CMT, if we are inside a comment. */
  enum class in_comment = 0;

  /* Have we encountered a newline outside a comment? */
  int beg_line = 0;
  
  for (;;)
    {
      int c;                    /* Input character. */
      enum class class;         /* Classification of `c'. */

      /* Get an input character and determine its classification. */
      c = getch ();
      switch (c)
        {
        case '\n':
          if (!in_comment)
            beg_line = 1;
          /* Fall through. */
          
        case ' ': case '\f': case '\r': case '\t': case '\v':
          class = CLS_WS;
          break;

        case '/':
          /* Outside a comment, slash-star begins a comment. */
          if (!in_comment)
            {
              c = getch ();
              if (c == '*')
                class = CLS_BEG_CMT;
              else
                {
                  ungetch (c);
                  c = '/';
                  class = CLS_OTHER;
                }
            }
          else
            class = CLS_OTHER;
          break;

        case '*':
          /* Inside a comment, star-slash ends the comment. */
          if (in_comment)
            {
              c = getch ();
              if (c == '/')
                class = CLS_END_CMT;
              else
                {
                  ungetch (c);
                  class = CLS_OTHER;
                }
            }
          else
            class = CLS_OTHER;
          break;

        default:
          /* Other characters. */
          if (c == EOF)
            return 0;
          class = CLS_OTHER;
        }

      /* Handle character `c' according to its classification
         and whether we're inside a comment. */
      switch (class | in_comment)
        {
        case CLS_WS:
        case CLS_WS | CLS_IN_CMT:
        case CLS_OTHER | CLS_IN_CMT:
          break;

        case CLS_BEG_CMT:
          in_comment = CLS_IN_CMT;
          break;

        case CLS_OTHER:
          ungetch (c);
          return beg_line;

        case CLS_END_CMT | CLS_IN_CMT:
          in_comment = 0;
          break;

        case CLS_BEG_CMT | CLS_IN_CMT:
        case CLS_END_CMT:
        default:
          printf ("can't happen\n");
          break;
        }
    }
}

/* Get a character inside a quoted string or character constant.
   QUOTE is ' for a character constant or " for a quoted string.
   *WORDP points to a string being constructed that has *LIMP bytes
   available. */
static int 
getstelem (char **wordp, int *limp, int quote)
{
  int c;

  /* Handle end-of-quote and EOF. */
  c = getch ();
  if (c == quote || c == EOF)
    return 0;

  /* Handle ordinary string characters. */
  if (c != '\\')
    {
      putch (wordp, limp, c);
      return 1;
    }

  /* We're in a \ escape sequence.
     Get the second character. */
  c = getch ();
  if (c == EOF)
    return 0;

  /* Handle simple single-character escapes. */
  {
    static const char escapes[] = {"''??\"\"\\\\a\ab\bf\fn\nr\rt\tv\v"};
    const char *cp = strchr (escapes, c);
    if (cp != NULL)
      {
        putch (wordp, limp, cp[1]);
        return 1;
      }
  }

  /* Handle hexadecimal and octal escapes.
     This also handles invalid escapes by default,
     doing nothing useful with them.
     That's okay because invalid escapes generate undefined behavior. */
  {
    unsigned char v = 0;

    if (c == 'x' || c == 'X')
      for (;;)
        {
          static const char hexits[] = "0123456789abcdef";
          const char *p;

          c = getch ();
          p = strchr (hexits, tolower ((unsigned char) c));
          if (p == NULL)
            break;
          v = v * 16 + (p - hexits);
        }
    else
      {
        int i;

        for (i = 0; i < 3; i++)
          {
            v = v * 8 + (c - '0');
            c = getch ();
            if (c < '0' || c > '7')
              break;
          }
      }
        
    putch (wordp, limp, v);
    ungetch (c);
  }
  
  return 1;
}

/* Capacity of putback buffer. */
#define BUFSIZE 100

/* Putback buffer. */
char buf[BUFSIZE];

/* Number of characters in putback buffer. */
int bufp = 0;

/* Retrieves and returns a character from stdin or from the putback
   buffer.
   Returns EOF if end of file is encountered. */
int 
getch (void)
{
  return bufp > 0 ? buf[--bufp] : getchar ();
}

/* Stuffs character C into the putback buffer.
   From the caller's perspective, fails silently if the putback buffer
   is full. */
void
ungetch (int c)
{
  if (c == EOF)
    return;
  
  if (bufp >= BUFSIZE)
    printf ("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

/* Stuffs character C into buffer *WORDP, which has *LIMP bytes
   available.
   Advances *WORDP and reduces *LIMP as appropriate.
   Drops the character on the floor if it would overflow the buffer.
   Ensures that *WORDP is null terminated if possible. */
static void 
putch (char **wordp, int *limp, int c)
{
  if (*limp > 1)
    {
      *(*wordp)++ = c;
      (*limp)--;
    }
  if (*limp > 0)
    **wordp = '\0';
}

/* 
   Local variables:
   compile-command: "checkergcc -W -Wall -ansi -pedantic knr61.c -o knr61"
   End: 
*/


/*
$ gcc -W -Wall -ansi -pedantic 6-1.c -o 6-1
$ ./6-1.exe < 6-1.c
id      'enum'
id      'token'
other   '{'
id      'TOK_ID'
other   '='
id      'UCHAR_MAX'
other   '+'
other   '1'
other   ','
id      'TOK_STRING'
other   ','
id      'TOK_CHAR'
other   ','
id      'TOK_EOF'
other   '}'
other   ';'
id      'enum'
id      'token'
id      'getword'
other   '('
id      'char'
other   '*'
id      'word'
other   ','
id      'int'
id      'lim'
other   ')'
other   ';'
id      'static'
id      'int'
id      'skipws'
other   '('
id      'void'
other   ')'
other   ';'
id      'static'
id      'int'
id      'getstelem'
other   '('
id      'char'
other   '*'
other   '*'
other   ','
id      'int'
other   '*'
other   ','
id      'int'
other   ')'
other   ';'
id      'static'
id      'int'
id      'getch'
other   '('
id      'void'
other   ')'
other   ';'
id      'static'
id      'void'
id      'ungetch'
other   '('
id      'int'
other   ')'
other   ';'
id      'static'
id      'void'
id      'putch'
other   '('
id      'char'
other   '*'
other   '*'
other   ','
id      'int'
other   '*'
other   ','
id      'int'
other   ')'
other   ';'
id      'int'
id      'main'
other   '('
id      'void'
other   ')'
other   '{'
id      'ungetch'
other   '('
char    '\x0a'
other   ')'
other   ';'
id      'for'
other   '('
other   ';'
other   ';'
other   ')'
other   '{'
id      'char'
id      'word'
other   '['
other   '6'
other   '4'
other   ']'
other   ';'
id      'enum'
id      'token'
id      'token'
other   ';'
id      'token'
other   '='
id      'getword'
other   '('
id      'word'
other   ','
id      'sizeof'
id      'word'
other   ')'
other   ';'
id      'switch'
other   '('
id      'token'
other   ')'
other   '{'
id      'case'
id      'TOK_ID'
other   ':'
id      'printf'
other   '('
string  'id'
other   ')'
other   ';'
id      'break'
other   ';'
id      'case'
id      'TOK_STRING'
other   ':'
id      'printf'
other   '('
string  'string'
other   ')'
other   ';'
id      'break'
other   ';'
id      'case'
id      'TOK_CHAR'
other   ':'
id      'printf'
other   '('
string  'char'
other   ')'
other   ';'
id      'break'
other   ';'
id      'case'
id      'TOK_EOF'
other   ':'
id      'printf'
other   '('
string  'eof\x0a'
other   ')'
other   ';'
id      'return'
other   '0'
other   ';'
id      'default'
other   ':'
id      'printf'
other   '('
string  'other'
other   ')'
other   ';'
id      'word'
other   '['
other   '0'
other   ']'
other   '='
id      'token'
other   ';'
id      'word'
other   '['
other   '1'
other   ']'
other   '='
char    ''
other   ';'
id      'break'
other   ';'
other   '}'
other   '{'
id      'const'
id      'char'
other   '*'
id      's'
other   ';'
id      'printf'
other   '('
string  '\x09\''
other   ')'
other   ';'
id      'for'
other   '('
id      's'
other   '='
id      'word'
other   ';'
other   '*'
id      's'
other   '!'
other   '='
char    ''
other   ';'
id      's'
other   '+'
other   '+'
other   ')'
id      'if'
other   '('
id      'isprint'
other   '('
other   '*'
id      's'
other   ')'
other   '&'
other   '&'
other   '*'
id      's'
other   '!'
other   '='
char    '\''
other   ')'
id      'putchar'
other   '('
other   '*'
id      's'
other   ')'
other   ';'
id      'else'
id      'if'
other   '('
other   '*'
id      's'
other   '='
other   '='
char    '\''
other   ')'
id      'printf'
other   '('
string  '\\''
other   ')'
other   ';'
id      'else'
id      'printf'
other   '('
string  '\x%02x'
other   ','
other   '*'
id      's'
other   ')'
other   ';'
id      'printf'
other   '('
string  '\'\x0a'
other   ')'
other   ';'
other   '}'
other   '}'
other   '}'
id      'enum'
id      'token'
id      'getword'
other   '('
id      'char'
other   '*'
id      'word'
other   ','
id      'int'
id      'lim'
other   ')'
other   '{'
id      'int'
id      'beg_line'
other   ','
id      'c'
other   ';'
id      'for'
other   '('
other   ';'
other   ';'
other   ')'
other   '{'
id      'beg_line'
other   '='
id      'skipws'
other   '('
other   ')'
other   ';'
id      'c'
other   '='
id      'getch'
other   '('
other   ')'
other   ';'
id      'if'
other   '('
other   '!'
id      'beg_line'
other   '|'
other   '|'
id      'c'
other   '!'
other   '='
char    '#'
other   ')'
id      'break'
other   ';'
id      'do'
other   '{'
id      'c'
other   '='
id      'getch'
other   '('
other   ')'
other   ';'
id      'if'
other   '('
id      'c'
other   '='
other   '='
id      'EOF'
other   ')'
id      'return'
id      'TOK_EOF'
other   ';'
other   '}'
id      'while'
other   '('
id      'c'
other   '!'
other   '='
char    '\x0a'
other   ')'
other   ';'
id      'ungetch'
other   '('
char    '\x0a'
other   ')'
other   ';'
other   '}'
id      'if'
other   '('
id      'c'
other   '='
other   '='
id      'EOF'
other   ')'
id      'return'
id      'TOK_EOF'
other   ';'
id      'else'
id      'if'
other   '('
id      'c'
other   '='
other   '='
char    '_'
other   '|'
other   '|'
id      'isalpha'
other   '('
other   '('
id      'unsigned'
id      'char'
other   ')'
id      'c'
other   ')'
other   ')'
other   '{'
id      'do'
other   '{'
id      'putch'
other   '('
other   '&'
id      'word'
other   ','
other   '&'
id      'lim'
other   ','
id      'c'
other   ')'
other   ';'
id      'c'
other   '='
id      'getch'
other   '('
other   ')'
other   ';'
other   '}'
id      'while'
other   '('
id      'isalnum'
other   '('
other   '('
id      'unsigned'
id      'char'
other   ')'
id      'c'
other   ')'
other   '|'
other   '|'
id      'c'
other   '='
other   '='
char    '_'
other   ')'
other   ';'
id      'ungetch'
other   '('
id      'c'
other   ')'
other   ';'
id      'return'
id      'TOK_ID'
other   ';'
other   '}'
id      'else'
id      'if'
other   '('
id      'c'
other   '='
other   '='
char    '\''
other   '|'
other   '|'
id      'c'
other   '='
other   '='
char    '"'
other   ')'
other   '{'
id      'int'
id      'quote'
other   '='
id      'c'
other   ';'
id      'word'
other   '['
other   '0'
other   ']'
other   '='
char    ''
other   ';'
id      'while'
other   '('
id      'getstelem'
other   '('
other   '&'
id      'word'
other   ','
other   '&'
id      'lim'
other   ','
id      'quote'
other   ')'
other   ')'
other   ';'
id      'return'
id      'quote'
other   '='
other   '='
char    '\''
other   '?'
id      'TOK_CHAR'
other   ':'
id      'TOK_STRING'
other   ';'
other   '}'
id      'else'
id      'return'
other   '('
id      'unsigned'
id      'char'
other   ')'
id      'c'
other   ';'
other   '}'
id      'static'
id      'int'
id      'skipws'
other   '('
id      'void'
other   ')'
other   '{'
id      'enum'
id      'class'
other   '{'
id      'CLS_WS'
other   '='
other   '0'
other   ','
id      'CLS_BEG_CMT'
other   ','
id      'CLS_END_CMT'
other   ','
id      'CLS_OTHER'
other   ','
id      'CLS_IN_CMT'
other   '='
other   '4'
other   '}'
other   ';'
id      'enum'
id      'class'
id      'in_comment'
other   '='
other   '0'
other   ';'
id      'int'
id      'beg_line'
other   '='
other   '0'
other   ';'
id      'for'
other   '('
other   ';'
other   ';'
other   ')'
other   '{'
id      'int'
id      'c'
other   ';'
id      'enum'
id      'class'
id      'class'
other   ';'
id      'c'
other   '='
id      'getch'
other   '('
other   ')'
other   ';'
id      'switch'
other   '('
id      'c'
other   ')'
other   '{'
id      'case'
char    '\x0a'
other   ':'
id      'if'
other   '('
other   '!'
id      'in_comment'
other   ')'
id      'beg_line'
other   '='
other   '1'
other   ';'
id      'case'
char    ' '
other   ':'
id      'case'
char    '\x0c'
other   ':'
id      'case'
char    '\x0d'
other   ':'
id      'case'
char    '\x09'
other   ':'
id      'case'
char    '\x0b'
other   ':'
id      'class'
other   '='
id      'CLS_WS'
other   ';'
id      'break'
other   ';'
id      'case'
char    '/'
other   ':'
id      'if'
other   '('
other   '!'
id      'in_comment'
other   ')'
other   '{'
id      'c'
other   '='
id      'getch'
other   '('
other   ')'
other   ';'
id      'if'
other   '('
id      'c'
other   '='
other   '='
char    '*'
other   ')'
id      'class'
other   '='
id      'CLS_BEG_CMT'
other   ';'
id      'else'
other   '{'
id      'ungetch'
other   '('
id      'c'
other   ')'
other   ';'
id      'c'
other   '='
char    '/'
other   ';'
id      'class'
other   '='
id      'CLS_OTHER'
other   ';'
other   '}'
other   '}'
id      'else'
id      'class'
other   '='
id      'CLS_OTHER'
other   ';'
id      'break'
other   ';'
id      'case'
char    '*'
other   ':'
id      'if'
other   '('
id      'in_comment'
other   ')'
other   '{'
id      'c'
other   '='
id      'getch'
other   '('
other   ')'
other   ';'
id      'if'
other   '('
id      'c'
other   '='
other   '='
char    '/'
other   ')'
id      'class'
other   '='
id      'CLS_END_CMT'
other   ';'
id      'else'
other   '{'
id      'ungetch'
other   '('
id      'c'
other   ')'
other   ';'
id      'class'
other   '='
id      'CLS_OTHER'
other   ';'
other   '}'
other   '}'
id      'else'
id      'class'
other   '='
id      'CLS_OTHER'
other   ';'
id      'break'
other   ';'
id      'default'
other   ':'
id      'if'
other   '('
id      'c'
other   '='
other   '='
id      'EOF'
other   ')'
id      'return'
other   '0'
other   ';'
id      'class'
other   '='
id      'CLS_OTHER'
other   ';'
other   '}'
id      'switch'
other   '('
id      'class'
other   '|'
id      'in_comment'
other   ')'
other   '{'
id      'case'
id      'CLS_WS'
other   ':'
id      'case'
id      'CLS_WS'
other   '|'
id      'CLS_IN_CMT'
other   ':'
id      'case'
id      'CLS_OTHER'
other   '|'
id      'CLS_IN_CMT'
other   ':'
id      'break'
other   ';'
id      'case'
id      'CLS_BEG_CMT'
other   ':'
id      'in_comment'
other   '='
id      'CLS_IN_CMT'
other   ';'
id      'break'
other   ';'
id      'case'
id      'CLS_OTHER'
other   ':'
id      'ungetch'
other   '('
id      'c'
other   ')'
other   ';'
id      'return'
id      'beg_line'
other   ';'
id      'case'
id      'CLS_END_CMT'
other   '|'
id      'CLS_IN_CMT'
other   ':'
id      'in_comment'
other   '='
other   '0'
other   ';'
id      'break'
other   ';'
id      'case'
id      'CLS_BEG_CMT'
other   '|'
id      'CLS_IN_CMT'
other   ':'
id      'case'
id      'CLS_END_CMT'
other   ':'
id      'default'
other   ':'
id      'printf'
other   '('
string  'can\'t happen\x0a'
other   ')'
other   ';'
id      'break'
other   ';'
other   '}'
other   '}'
other   '}'
id      'static'
id      'int'
id      'getstelem'
other   '('
id      'char'
other   '*'
other   '*'
id      'wordp'
other   ','
id      'int'
other   '*'
id      'limp'
other   ','
id      'int'
id      'quote'
other   ')'
other   '{'
id      'int'
id      'c'
other   ';'
id      'c'
other   '='
id      'getch'
other   '('
other   ')'
other   ';'
id      'if'
other   '('
id      'c'
other   '='
other   '='
id      'quote'
other   '|'
other   '|'
id      'c'
other   '='
other   '='
id      'EOF'
other   ')'
id      'return'
other   '0'
other   ';'
id      'if'
other   '('
id      'c'
other   '!'
other   '='
char    '\'
other   ')'
other   '{'
id      'putch'
other   '('
id      'wordp'
other   ','
id      'limp'
other   ','
id      'c'
other   ')'
other   ';'
id      'return'
other   '1'
other   ';'
other   '}'
id      'c'
other   '='
id      'getch'
other   '('
other   ')'
other   ';'
id      'if'
other   '('
id      'c'
other   '='
other   '='
id      'EOF'
other   ')'
id      'return'
other   '0'
other   ';'
other   '{'
id      'static'
id      'const'
id      'char'
id      'escapes'
other   '['
other   ']'
other   '='
other   '{'
string  '\'\'??""\\a\x07b\x08f\x0cn\x0ar\x0dt\x09v\x0b'
other   '}'
other   ';'
id      'const'
id      'char'
other   '*'
id      'cp'
other   '='
id      'strchr'
other   '('
id      'escapes'
other   ','
id      'c'
other   ')'
other   ';'
id      'if'
other   '('
id      'cp'
other   '!'
other   '='
id      'NULL'
other   ')'
other   '{'
id      'putch'
other   '('
id      'wordp'
other   ','
id      'limp'
other   ','
id      'cp'
other   '['
other   '1'
other   ']'
other   ')'
other   ';'
id      'return'
other   '1'
other   ';'
other   '}'
other   '}'
other   '{'
id      'unsigned'
id      'char'
id      'v'
other   '='
other   '0'
other   ';'
id      'if'
other   '('
id      'c'
other   '='
other   '='
char    'x'
other   '|'
other   '|'
id      'c'
other   '='
other   '='
char    'X'
other   ')'
id      'for'
other   '('
other   ';'
other   ';'
other   ')'
other   '{'
id      'static'
id      'const'
id      'char'
id      'hexits'
other   '['
other   ']'
other   '='
string  '0123456789abcdef'
other   ';'
id      'const'
id      'char'
other   '*'
id      'p'
other   ';'
id      'c'
other   '='
id      'getch'
other   '('
other   ')'
other   ';'
id      'p'
other   '='
id      'strchr'
other   '('
id      'hexits'
other   ','
id      'tolower'
other   '('
other   '('
id      'unsigned'
id      'char'
other   ')'
id      'c'
other   ')'
other   ')'
other   ';'
id      'if'
other   '('
id      'p'
other   '='
other   '='
id      'NULL'
other   ')'
id      'break'
other   ';'
id      'v'
other   '='
id      'v'
other   '*'
other   '1'
other   '6'
other   '+'
other   '('
id      'p'
other   '-'
id      'hexits'
other   ')'
other   ';'
other   '}'
id      'else'
other   '{'
id      'int'
id      'i'
other   ';'
id      'for'
other   '('
id      'i'
other   '='
other   '0'
other   ';'
id      'i'
other   '<'
other   '3'
other   ';'
id      'i'
other   '+'
other   '+'
other   ')'
other   '{'
id      'v'
other   '='
id      'v'
other   '*'
other   '8'
other   '+'
other   '('
id      'c'
other   '-'
char    '0'
other   ')'
other   ';'
id      'c'
other   '='
id      'getch'
other   '('
other   ')'
other   ';'
id      'if'
other   '('
id      'c'
other   '<'
char    '0'
other   '|'
other   '|'
id      'c'
other   '>'
char    '7'
other   ')'
id      'break'
other   ';'
other   '}'
other   '}'
id      'putch'
other   '('
id      'wordp'
other   ','
id      'limp'
other   ','
id      'v'
other   ')'
other   ';'
id      'ungetch'
other   '('
id      'c'
other   ')'
other   ';'
other   '}'
id      'return'
other   '1'
other   ';'
other   '}'
id      'char'
id      'buf'
other   '['
id      'BUFSIZE'
other   ']'
other   ';'
id      'int'
id      'bufp'
other   '='
other   '0'
other   ';'
id      'int'
id      'getch'
other   '('
id      'void'
other   ')'
other   '{'
id      'return'
id      'bufp'
other   '>'
other   '0'
other   '?'
id      'buf'
other   '['
other   '-'
other   '-'
id      'bufp'
other   ']'
other   ':'
id      'getchar'
other   '('
other   ')'
other   ';'
other   '}'
id      'void'
id      'ungetch'
other   '('
id      'int'
id      'c'
other   ')'
other   '{'
id      'if'
other   '('
id      'c'
other   '='
other   '='
id      'EOF'
other   ')'
id      'return'
other   ';'
id      'if'
other   '('
id      'bufp'
other   '>'
other   '='
id      'BUFSIZE'
other   ')'
id      'printf'
other   '('
string  'ungetch: too many characters\x0a'
other   ')'
other   ';'
id      'else'
id      'buf'
other   '['
id      'bufp'
other   '+'
other   '+'
other   ']'
other   '='
id      'c'
other   ';'
other   '}'
id      'static'
id      'void'
id      'putch'
other   '('
id      'char'
other   '*'
other   '*'
id      'wordp'
other   ','
id      'int'
other   '*'
id      'limp'
other   ','
id      'int'
id      'c'
other   ')'
other   '{'
id      'if'
other   '('
other   '*'
id      'limp'
other   '>'
other   '1'
other   ')'
other   '{'
other   '*'
other   '('
other   '*'
id      'wordp'
other   ')'
other   '+'
other   '+'
other   '='
id      'c'
other   ';'
other   '('
other   '*'
id      'limp'
other   ')'
other   '-'
other   '-'
other   ';'
other   '}'
id      'if'
other   '('
other   '*'
id      'limp'
other   '>'
other   '0'
other   ')'
other   '*'
other   '*'
id      'wordp'
other   '='
char    ''
other   ';'
other   '}'
eof
*/
