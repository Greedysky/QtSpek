#pragma once

#define PACKAGE_NAME    "spek"
#define PACKAGE_VERSION "0.8.5"

#if QT_VERSION >= QT_VERSION_CHECK(5,11,0)
#  define QtFontWidth(p, t) p.horizontalAdvance(t)
#else
#  define QtFontWidth(p, t) p.width(t)
#endif

#if QT_VERSION >= QT_VERSION_CHECK(6,3,0)
#  define QtAddAction(p, a, b, c, d) p->addAction(a, d, b, c)
#else
#  define QtAddAction(p, a, b, c, d) p->addAction(a, b, c, d)
#endif
