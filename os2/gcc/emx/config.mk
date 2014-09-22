# Definition of macros for library, and C startup code.
osedir     = $(osrdir)$(DIRSEPSTR)$(OSENVIRONMENT)

.IMPORT .IGNORE : GCC_VER
GCC_VER      *= 3.2

CFLAGS       += -I$(osedir)

NDB_CFLAGS   += -O
NDB_LDFLAGS  +=
NDB_LDLIBS   +=
