/* RCS  $Id: switchar.c,v 1.1.1.1 2000/09/22 15:33:30 hr Exp $
--
-- SYNOPSIS
--      switch char query.
--
-- DESCRIPTION
--      Get the current value of the command line switch char.  Only useful
--      in a DOS environment, otherwise we #define it to be '-'.
--
-- AUTHOR
--      Dennis Vadura, dvadura@dmake.wticorp.com
--
-- WWW
--      http://dmake.wticorp.com/
--
-- COPYRIGHT
--      Copyright (c) 1996,1997 by WTI Corp.  All rights reserved.
--
--      This program is NOT free software; you can redistribute it and/or
--      modify it under the terms of the Software License Agreement Provided
--      in the file <distribution-root>/readme/license.txt.
--
-- LOG
--      Use cvs log to obtain detailed change logs.
*/
#include <stdlib.h>
#include <stdio.h>
#include "stdmacs.h"

getswitchar()/*
===============
   Try the environment first.  If you don't find SWITCHAR there, then use
   the DOS call.  The call is undocumented, and doesn't work for DOS versions
   4.0 and up, so the check of the environment will fix that. */
{
   static char *_env_switchar = NIL(char);

   if( _env_switchar != NIL(char) ||
       (_env_switchar = (char *)getenv("SWITCHAR")) != NIL(char) )
      return(*_env_switchar);

/*
   This was modified by Jon Saxton on 9 Mar 2004 to make the default switch
   character a - instead of a / when using gcc.  Most likely it can be set
   to - for all compilers.

   A side-effect of having the switch character set to / is that the directory
   separator is set to \.  Now it just so happens that - and / work just as
   well as / and \ but have the advantage of being consistent with UNIX
   and work-alike systems.  This makes it easier to have source code and
   makefiles portable across OS/2, Windows and UNIX without resorting to
   unreadable macros.

#ifdef __GNUC__
   return '-';
#else
   return '/';
#endif

   Note that the lines above are commented out. */

   return '-';
}
