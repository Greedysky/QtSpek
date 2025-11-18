#pragma once

#define PACKAGE_NAME    "spek"
#define PACKAGE_VERSION "0.8.5"

#if QT_VERSION >= QT_VERSION_CHECK(5,11,0)
#  define QtFontWidth(p, t) p.horizontalAdvance(t)
#else
#  define QtFontWidth(p, t) p.width(t)
#endif
