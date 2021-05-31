#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(VISIONMODULE_LIB)
#  define VISIONMODULE_EXPORT Q_DECL_EXPORT
# else
#  define VISIONMODULE_EXPORT Q_DECL_IMPORT
# endif
#else
# define VISIONMODULE_EXPORT
#endif
