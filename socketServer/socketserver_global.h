#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SOCKETSERVER_LIB)
#  define SOCKETSERVER_EXPORT Q_DECL_EXPORT
# else
#  define SOCKETSERVER_EXPORT Q_DECL_IMPORT
# endif
#else
# define SOCKETSERVER_EXPORT
#endif
