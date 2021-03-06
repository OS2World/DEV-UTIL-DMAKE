/* RCS  $Id: sysintf.h,v 1.1.1.1 2000/09/22 15:33:30 hr Exp $
--
-- SYNOPSIS
--      Interfaces for sysintf.c
--
-- DESCRIPTION
--      Abstractions of functions in sysintf.c
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

#define DMSTAT stat
#define VOID_LCACHE(l,m)
#define Hook_std_writes(A)
#define GETPID getpid()
#define DMSTRLWR(A,B)

/*
** standard C items
*/

/*
** DOS interface standard items
*/
#define	getswitchar()	'-'

/*
** make parameters
*/
