#include "os2stuff.h"

#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

/**/
#ifdef __IBMC__
#define _O_CREAT	O_CREAT
#define _O_EXCL		O_EXCL
#define _S_IWRITE	S_IWRITE
#define _S_IREAD	S_IREAD
#endif

#define DirEntryKind	int
/* The Windows API sets this value to 260 */
#ifndef _MAX_PATH
#define _MAX_PATH 1024
#endif

#ifdef CCHMAXPATH
#undef _MAX_PATH
#define _MAX_PATH CCHMAXPATH
#endif

#define OS2

char* dtempnam( char* nix, char* prefix )
{
/*    char *ret_val;*/
    size_t i;

/*    // dertermine Directory, Prefix and Extension*/
    char pfx[6] = "";
    char ext[5] = "";
    char dir[2000] = "";
	char sBuf[_MAX_PATH];

	char ret_val[_MAX_PATH];
	static unsigned long u;
	unsigned long nOld;
	unsigned nTemp;
	FILE *pFile;
	int nhandle;
	char* pRet = 0L;
	int n = 0;

	const int TempVarianten = 2;
	char *TempPath[] = { "tmp", "temp" };

    strcpy( pfx, prefix );
    if ( nix )
		strncpy( dir, nix, sizeof(dir) -1 );

/* wurde kein Dir angegeben, dann nehmen wir ein passendes TEMP-Verz. */


/*    if ( eFlag == FSYS_FLAG_CURRENT || ( !pParent && pWild ) )*/
/*        dir = TempDirImpl(sBuf);*/

	while ( dir[0] == '\0' && n < TempVarianten)
	{
		char *EnvTempPath = getenv(TempPath[n]);
		if ( EnvTempPath != NULL )
			strncpy( dir, EnvTempPath, sizeof(dir)-1 );
		n++;
	}
	if ( dir[0] == '\0' )
#if defined(UNX)
		strcpy( dir, "/tmp" );
#else
		strcpy( dir, "c:\\tmp" );
#endif

/*    // ab hier leicht modifizierter Code von VB*/
    i = strlen(dir);
/*    ret_val = new char[i+2 /* '\0' & '\\' *//* + 8 /*root*//* + 4 /*.ext*//*];*/
    if (ret_val)
    {
        strncpy(ret_val,dir, sizeof(ret_val)-1);

        /* Make sure directory ends with a separator    */
#if defined(DOS) || defined(PM2) || defined(WIN) || defined(WNT)
        if ( i>0 && ret_val[i-1] != '\\' && ret_val[i-1] != '/' &&
             ret_val[i-1] != ':')
            ret_val[i++] = '\\';
#elif defined(OS2)
        if ( i>0 && ret_val[i-1] != '\\' && ret_val[i-1] != '/' &&
             ret_val[i-1] != ':')
            ret_val[i++] = '/';
#elif (UNX)
        if (i>0 && ret_val[i-1] != '/')
            ret_val[i++] = '/';
#elif (MAC)
        if (i>0 && ret_val[i-1] != ':')
            ret_val[i++] = ':';
#else
#error unknown operating system
#endif

        strncpy(ret_val + i, pfx, 5);
        ret_val[i + 5] = '\0';      /* strncpy doesn't put a 0 if more  */
        i = strlen(ret_val);        /* than 'n' chars.          */

        /* Prefix can have 5 chars, leaving 3 for numbers.
           26 ** 3 == 17576
         */
#if (defined (MSC) || defined (BLC) || defined(ICC) ) && ( defined (WIN) || defined (WNT))
    	u = GetTickCount();
#else
		u = clock();
#endif

        for ( nOld = u; ++u != nOld; )
        {
             u %= (26*26*26);
             nTemp = (unsigned)u;
#if defined(OS2) || defined(WIN) || defined(WNT) || defined(DOS)
            itoa(nTemp,ret_val + i,26);
#else
            snprintf(ret_val+i, sizeof(ret_val) + i, "%03u", nTemp);
#endif
            strcat(ret_val,ext);
			nhandle = _open( ret_val, _O_CREAT | _O_EXCL, _S_IWRITE | _S_IREAD );
			if ( nhandle != -1 )
			{
				_lseek( nhandle, 0, SEEK_END);
				if ( 0 == _tell( nhandle ) )
				{
					_close( nhandle );
					pRet = malloc( strlen( ret_val ) );
					strcpy(pRet, ret_val );
					break;
				}
				_close( nhandle );
			}
        }
    }
	if ( pRet == 0L )
		fprintf(stderr,"ERROR - could not open tempfile\n");
#if FALSE
	else
		fprintf(stderr,"tempfile name %s\n",pRet);
#endif
	return pRet;
}
