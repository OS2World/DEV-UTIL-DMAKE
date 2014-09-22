#ifndef OS2STUFF_H
#define OS2STUFF_H

#ifndef OS2
#define OS2
#endif

#include <sys/types.h>

#define far
#define itoa _itoa
#define DosSelectDisk   DosSetDefaultDisk

#define _O_ACCMODE      O_ACCMODE
#define _O_RDONLY       O_RDONLY
#define _O_WRONLY       O_WRONLY
#define _O_RDWR         O_RDWR
#define _O_NONBLOCK     O_NONBLOCK
#define _O_APPEND       O_APPEND
#define _O_TEXT         O_TEXT

#define _O_BINARY       O_BINARY
#define _O_CREAT        O_CREAT
#define _O_TRUNC        O_TRUNC
#define _O_EXCL         O_EXCL
#define _O_SYNC         O_SYNC
#define _O_NOCTTY       O_NOCTTY
#define _O_SIZE         O_SIZE

#define _O_NDELAY       O_NDELAY
#define _O_NOINHERIT    O_NOINHERIT

#define _S_IREAD		S_IREAD
#define _S_IWRITE		S_IWRITE
#define _S_IEXEC		S_IEXEC

#endif
