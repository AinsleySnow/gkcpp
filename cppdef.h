/******************************************************************************
 *                               FREXXWARE
 * ----------------------------------------------------------------------------
 *
 * Project: Frexx C Preprocessor
 * $Source: /home/user/start/cpp/RCS/cppdef.h,v $
 * $Revision: 1.4 $
 * $Date: 1993/12/06 13:51:20 $
 * $Author: start $
 * $State: Exp $
 * $Locker: start $
 *
 * ----------------------------------------------------------------------------
 * $Log: cppdef.h,v $
 * Revision 1.4  1993/12/06  13:51:20  start
 * A lot of new stuff (too much to mention)
 *
 * Revision 1.3  1993/11/29  14:01:13  start
 * New features added
 *
 * Revision 1.2  1993/11/11  07:16:39  start
 * New stuff
 *
 * Revision 1.1  1993/11/03  09:15:59  start
 * Initial revision
 *
 *
 *****************************************************************************/

// there used to be some lines of code of using Emacs defination
// to find machine type, but I don't think we need that anymore


/*
 *		   S y s t e m	 D e p e n d e n t
 *		D e f i n i t i o n s	 f o r	 C P P
 *
 * Definitions in this file may be edited to configure CPP for particular
 * host operating systems and target configurations.
 *
 * NOTE: cpp assumes it is compiled by a compiler that supports macros
 * with arguments.  If this is not the case (as for Decus C), #define
 * nomacarg -- and provide function equivalents for all macros.
 *
 * (Is there any C compiler that doesn't support macros with arguments?)
 * （Alas. Tears of the era.)
 * 
 * cpp also assumes the host and target implement the Ascii character set.
 * If this is not the case, you will have to do some editing here and there.
 * 
 * (...Or any host or target that totally ignores ASCII?)
 * (Tears again.)
 * 
 */

 // no longer needed to define true and false
 // manually, since we have stdbool.h, and in the
 // newest C23 standard we have the keywords true and false.

/*
 * Define the HOST operating system.  This is needed so that
 * cpp can use appropriate filename conventions.
 */


/*
 * In order to predefine machine-dependent constants,
 * several strings are defined here:
 *
 * MACHINE	defines the target cpu (by name)
 * SYSTEM	defines the target operating system
 * COMPILER	defines the target compiler
 *
 *	The above may be #defined as "" if they are not wanted.
 *	They should not be #defined as NULL.
 *
 * LINE_PREFIX	defines the # output line prefix, if not "line"
 *		This should be defined as "" if cpp is to replace
 *		the "standard" C pre-processor.
 */
#define LINE_PREFIX		"line"
/*
 * FILE_LOCAL	marks functions which are referenced only in the
 *		file they reside.  Some C compilers allow these
 *		to be marked "static" even though they are referenced
 *		by "extern" statements elsewhere.
 *
 * OK_DOLLAR	Should be set true if $ is a valid alphabetic character
 *		in identifiers (default), or zero if $ is invalid.
 *		Default is true.
 *
 * OK_CONCAT	Should be set true if # may be used to concatenate
 *		tokens in macros (per the Ansi Draft Standard) or
 *		false for old-style # processing (needed if cpp is
 *		to process assembler source code).
 */
#define OK_CONCAT true
/*
 * OK_DATE	Predefines the compilation date if set true.
 *		Not permitted by the Nov. 12, 1984 Draft Standard.
 */
#define OK_DATE true
/*
 *
 * OK_SIZEOF	Permits sizeof in #if preprocessor expressions.
 *		According to K&R V2 (page 232), this is not allowed.
 */
#define OK_SIZEOF true
/*
 * S_CHAR etc.	Define the sizeof the basic TARGET machine word types.
 *		By default, sizes are set to the values for the HOST
 *		computer.  If this is inappropriate, see the code in
 *		cpp3.c for details on what to change.  Also, if you
 *		have a machine where sizeof (signed int) differs from
 *		sizeof (unsigned int), you will have to edit code and
 *		tables in cpp3.c (and extend the -S option definition.)
 *
 * CPP_LIBRARY	May be defined if you have a site-specific include directory
 *		which is to be searched *before* the operating-system
 *		specific directories.
 */


/*
 * defaults
 */

#ifndef MSG_PREFIX
#define MSG_PREFIX		"cpp: "
#endif

/*
 * RECURSION_LIMIT may be set to -1 to disable the macro recursion test.
 */
#ifndef RECURSION_LIMIT
#define RECURSION_LIMIT 1000
#endif

/*
 * BITS_CHAR may be defined to set the number of bits per character.
 * it is needed only for multi-byte character constants.
 */
#ifndef BITS_CHAR
#define BITS_CHAR		8
#endif

/*
 * BIG_ENDIAN is set true on machines (such as the IBM 360 series)
 * where 'ab' stores 'a' in the high-bits and 'b' in the low-bits.
 * It is set false on machines (such as the PDP-11 and Vax-11)
 * where 'ab' stores 'a' in the low-bits and 'b' in the high-bits.
 * (Or is it the other way around?) -- Warning: BIG_ENDIAN code is untested.
 * [I *seems* to be the other way around, according to the code /OIS]
 */
#ifndef BIG_ENDIAN
#define BIG_ENDIAN		false
#endif

/*
 * COMMENT_INVISIBLE may be defined to allow "old-style" comment
 * processing, whereby the comment becomes a zero-length token
 * delimiter.  This permitted tokens to be concatenated in macro
 * expansions.	This was removed from the Draft Ansi Standard.
 */
#ifndef COMMENT_INVISIBLE
#define COMMENT_INVISIBLE	false
#endif

/*
 * OK_DOLLAR enables use of $ as a valid "letter" in identifiers.
 * This is a permitted extension to the Ansi Standard and is required
 * for e.g., VMS, RSX-11M, etc.   It should be set false if cpp is
 * used to preprocess assembler source on Unix systems.  OLD_PREPROCESSOR
 * sets OK_DOLLAR false for that reason.
 */
#ifndef OK_DOLLAR
#define OK_DOLLAR		true
#endif

/*
 * OK_CONCAT enables (one possible implementation of) token concatenation.
 * If cpp is used to preprocess Unix assembler source, this should be
 * set false as the concatenation character, #, is used by the assembler.
 */
#ifndef OK_CONCAT
#define OK_CONCAT		true
#endif

/*
 * OK_DATE may be enabled to predefine today's date as a string
 * at the start of each compilation.  This is apparently not permitted
 * by the Draft Ansi Standard.
 */
#ifndef OK_DATE
#define OK_DATE 	true
#endif

/*
 * OK_SIZEOF may be defined to allow sizeof(type) in #if expressions.
 * Actually, it is none of the preprocessors business how large these
 * things are, as they might be different with different compiler
 * options. Also, according to K&R V2, page 232, it is nonstandard.
 * This option was added in the PDC process, under no. *OIS*0.92*.
 */
#ifndef OK_SIZEOF
#define OK_SIZEOF	false
#endif

/*
 * Some common definitions.
 */

#ifndef DEBUG
#define DEBUG		false
#endif

/*
 * The following definitions are used to allocate memory for
 * work buffers.  In general, they should not be modified
 * by implementors.
 *
 * PAR_MAC	The maximum number of #define parameters (31 per Standard)
 *		Note: we need another one for strings.
 * NBUFF	Input buffer size
 * NWORK	Work buffer size -- the longest macro
 *		must fit here after expansion.
 * NEXP 	The nesting depth of #if expressions
 * NINCLUDE	The number of directories that may be specified
 *		on a per-system basis, or by the -I option.
 * BLK_NEST	The number of nested #if's permitted.
 */

#ifndef PAR_MAC
#define PAR_MAC 	   (31 + 1)
#endif

#ifndef NBUFF
#define NBUFF			512
#endif

#ifndef NWORK
#define NWORK			512
#endif

#ifndef NEXP
#define NEXP			128
#endif

#ifndef NINCLUDE
#define NINCLUDE		  20
#endif

#ifndef NPARMWORK
#define NPARMWORK		(NWORK * 2)
#endif

#ifndef BLK_NEST
#define BLK_NEST		32
#endif


/*
 * Some special constants.  These may need to be changed if cpp
 * is ported to a wierd machine.
 *
 * NOTE: if cpp is run on a non-ascii machine, ALERT and VT may
 * need to be changed.	They are used to implement the proposed
 * ANSI standard C control characters '\a' and '\v' only.
 * DEL is used to tag macro tokens to prevent #define foo foo
 * from looping.  Note that we don't try to prevent more elaborate
 * #define loops from occurring.
 */

#ifndef ALERT
#define ALERT			'\007'          /* '\a' is "Bell"       */
#endif

#ifndef VT
#define VT			'\013'          /* Vertical Tab CTRL/K  */
#endif

/*
 * Functions can be declared/defined static to only become in the
 * scope for functions of the same source file.
 */

#ifndef FILE_LOCAL
#define FILE_LOCAL		static		/* file-unique globals */
#endif


/*
 * SBSIZE defines the number of hash-table slots for the symbol table.
 */
#ifndef SBSIZE
#define SBSIZE  64
#endif

#define VERSION_TEXT                               \
"Ginkgo C Preprocessor v0.0.1 "                    \
"Copyright (C) by AinsleySnow 2023 - present\n"    \
"based on Frexx C Preprocessor v1.5.1\n"           \
"Copyright (C) by FrexxWare 1993 - 2002.\n"        \
"Compiled " __DATE__ "\n"
