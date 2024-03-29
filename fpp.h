/******************************************************************************
Copyright (c) 2023 - present AinsleySnow
Copyright (c) 1993 - 2011 Daniel Stenberg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

/**********************************************************************
 *
 * fpp.h
 *
 */
#include <stdbool.h>


struct fppTag
{
    int tag;
    void *data;
};

#define NFLAG_BUILTIN   1
#define NFLAG_PREDEFINE 2

/* end of taglist: */
#define FPPTAG_END 0

/* To make the preprocessed output keep the comments: */
#define FPPTAG_KEEPCOMMENTS 1 /* data is true or false */

/* To define symbols to the preprocessor: */
#define FPPTAG_DEFINE 2 /* data is the string "symbol" or "symbol=<value>" */

/* To make the preprocessor ignore all non-fatal errors: */
#define FPPTAG_IGNORE_NONFATAL 3 /* data is true or false */

/* To add an include directory to the include directory list: */
#define FPPTAG_INCLUDE_DIR 4 /* data is directory name ending with a '/' (on
				amiga a ':' is also valid) */

/* To define all machine specific built-in #defines, default is true: */
#define FPPTAG_BUILTINS 5 /* data is true or false */

/* To define predefines like __LINE__, __DATE__, etc. default is true: */
#define FPPTAG_PREDEFINES 6 /* data is true or false */

/* To make fpp leave C++ comments in the output: */
#define FPPTAG_IGNORE_CPLUSPLUS 7 /* data is true or false */

/* To define new sizes to #if sizeof: */
#define FPPTAG_SIZEOF_TABLE 8 /* data is sizeof table string */

/* To undefine symbols: */
#define FPPTAG_UNDEFINE 9 /* data is symbol name */

/* Output all #defines: */
#define FPPTAG_OUTPUT_DEFINES 10 /* data is true or false */

/* Initial input file name: */
#define FPPTAG_INPUT_NAME 11 /* data is string */

/* Input function: */
#define FPPTAG_INPUT 12 /* data is an input funtion */

/* Output function: */
#define FPPTAG_OUTPUT 13 /* data is an output function */

/* User data, sent in the last argument to the input function: */
#define FPPTAG_USERDATA 14 /* data is user data */

/* Whether to exclude #line instructions in the output, default is false */
#define FPPTAG_LINE 15 /* data is true or false */

/* Error function. This is called when FPP finds any warning/error/fatal: */
#define FPPTAG_ERROR 16 /* data is function pointer to a
			   "void (*)(void *, char *, va_list)" */

/* Whether to warn for illegal cpp instructions */
#define FPPTAG_WARNILLEGALCPP 17 /* data is boolean, default is false */

/* Output the 'line' keyword on #line-lines? */
#define FPPTAG_OUTPUTLINE 18 /* data is boolean, default is true */

/* Do not output the version information string */
#define FPPTAG_IGNOREVERSION 19 /* data is boolean, default is false */

/* Output all included file names to stderr */
#define FPPTAG_OUTPUTINCLUDES 20 /* data is boolean, default is false */

/* Display warning if there is any brace, bracket or parentheses unbalance */
#define FPPTAG_OUTPUTBALANCE 21 /* data is boolean, default is false */

/* Display all whitespaces in the source */
#define FPPTAG_OUTPUTSPACE 22 /* data is boolean, default is false */

/* Allow nested comments */
#define FPPTAG_NESTED_COMMENTS 23 /* data is boolean, default is false */

/* Enable warnings at nested comments */
#define FPPTAG_WARN_NESTED_COMMENTS 24 /* data is boolean, default is false */

/* Enable warnings at missing includes */
#define FPPTAG_WARNMISSINCLUDE 25 /* data is boolean, default is true */

/* Output the main file */
#define FPPTAG_OUTPUTMAIN 26 /* data is boolean, default is true */

/* Include file */
#define FPPTAG_INCLUDE_FILE 27 /* data is char pointer */

/* Include macro file */
#define FPPTAG_INCLUDE_MACRO_FILE 28 /* data is char pointer */

/* Evaluate the right part of a concatenate before the concat */
#define FPPTAG_RIGHTCONCAT 29 /* data is boolean, default is false */

/* Include the specified file at the beginning of each function */
#define FPPTAG_INITFUNC 30 /* data is char pointer or NULL */

/* Define function to be excluded from the "beginning-function-addings" */
#define FPPTAG_EXCLFUNC 31 /* data is char pointer */

/* Enable output of all function names defined in the source */
#define FPPTAG_DISPLAYFUNCTIONS 32

/* Switch on WWW-mode */
#define FPPTAG_WEBMODE 33

int fppPreProcess(struct fppTag *);
