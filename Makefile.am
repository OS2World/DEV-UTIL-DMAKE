#*************************************************************************
#
#   $RCSfile: Makefile.am,v $
#
#   $Revision: 1.7.20.1 $
#
#   last change: $Author: vg $ $Date: 2004/02/13 14:06:35 $
#
#   The Contents of this file are made available subject to the terms of
#   either of the following licenses
#
#          - GNU Lesser General Public License Version 2.1
#          - Sun Industry Standards Source License Version 1.1
#
#   Sun Microsystems Inc., October, 2000
#
#   GNU Lesser General Public License Version 2.1
#   =============================================
#   Copyright 2000 by Sun Microsystems, Inc.
#   901 San Antonio Road, Palo Alto, CA 94303, USA
#
#   This library is free software; you can redistribute it and/or
#   modify it under the terms of the GNU Lesser General Public
#   License version 2.1, as published by the Free Software Foundation.
#
#   This library is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#   Lesser General Public License for more details.
#
#   You should have received a copy of the GNU Lesser General Public
#   License along with this library; if not, write to the Free Software
#   Foundation, Inc., 59 Temple Place, Suite 330, Boston,
#   MA  02111-1307  USA
#
#
#   Sun Industry Standards Source License Version 1.1
#   =================================================
#   The contents of this file are subject to the Sun Industry Standards
#   Source License Version 1.1 (the "License"); You may not use this file
#   except in compliance with the License. You may obtain a copy of the
#   License at http://www.openoffice.org/license.html.
#
#   Software provided under this License is provided on an "AS IS" basis,
#   WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING,
#   WITHOUT LIMITATION, WARRANTIES THAT THE SOFTWARE IS FREE OF DEFECTS,
#   MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE, OR NON-INFRINGING.
#   See the License for the specific provisions governing your rights and
#   obligations concerning the Software.
#
#   The Initial Developer of the Original Code is: Sun Microsystems, Inc.
#
#   Copyright: 2000 by Sun Microsystems, Inc.
#
#   All Rights Reserved.
#
#   Contributor(s): _______________________________________
#
#
#
#*************************************************************************

# require "new" automake >= 1.7
AUTOMAKE_OPTIONS = 1.7 foreign



bin_PROGRAMS = dmake
dmake_SOURCES = \
	infer.c make.c stat.c expand.c dmstring.c hash.c dag.c dmake.c\
	path.c imacs.c sysintf.c parse.c getinp.c quit.c state.c\
	dmdump.c macparse.c rulparse.c percent.c function.c

#dmake_LDADD   = unix/libunix.a
#dmake_LDADD   = win95/libwin95.a msdos/libmsdos.a win95/microsft/libmsft.a
dmake_LDADD   = $(OS_LIBRARY)

DIST_SUBDIRS = unix startup win95 msdos
SUBDIRS = $(OS_SUBDIRS)

EXTRA_DIST = make.c 

# set the include path found by configure
INCLUDES = -I$(top_srcdir) -I$(top_builddir) -I$(top_srcdir)/@OS_TYPE@/@OS_VERSION@ -I$(top_srcdir)/@OS_TYPE@ -I$(top_srcdir)/@OS_TYPE@/@OS_VERSION@/gnu 
