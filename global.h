#ifndef GLOBAL_H
#define GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(APP_LIBRARY)
#  define APP_SHARED_EXPORT Q_DECL_EXPORT
#else
#  define APP_SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GLOBAL_H
