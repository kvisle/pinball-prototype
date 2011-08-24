#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([r], [0.1], [trygve.vea@gmail.com])
AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([config.h])


AM_INIT_AUTOMAKE(r, 0.1, [-Wall -Werror foreign])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_RANLIB
AM_PROG_CC_C_O
AC_PROG_INSTALL
AC_PROG_LN_S


# Checks for libraries.
# FIXME: Replace `main' with a function in `-lGL':
PKG_CHECK_MODULES([GL],[gl])
PKG_CHECK_MODULES([SDL],[sdl])
PKG_CHECK_MODULES([OPENAL],[openal])

AC_CHECK_LIB([GL], [main])
# FIXME: Replace `main' with a function in `-lm':
AC_CHECK_LIB([m], [main])

# Checks for header files.
AC_CHECK_HEADERS([stdint.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UINT32_T

# Checks for library functions.
AC_CHECK_FUNCS([memmove memset sqrt])

AC_CONFIG_FILES([Makefile
				 src/Makefile
                 lib/Makefile
				 lib/Box2D/Makefile
                 lib/lib_json/Makefile])
AC_OUTPUT
