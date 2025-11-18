#ifndef TTKVERSION_H
#define TTKVERSION_H

//update time 2023.01.11
#define TTK_MAJOR_VERSION 0
#define TTK_MINOR_VERSION 8
#define TTK_PATCH_VERSION 5

#define TTK_VERSION             TTK_VERSION_CHECK(TTK_MAJOR_VERSION, TTK_MINOR_VERSION, TTK_PATCH_VERSION, 0)
#define TTK_VERSION_STR         TTK_VERSION_CHECK_STR(TTK_MAJOR_VERSION, TTK_MINOR_VERSION, TTK_PATCH_VERSION, 0)
#define TTK_VERSION_TIME_STR    "(2023/01/011)"

#define TTK_RC_FILEVERSION      TTK_MAJOR_VERSION, TTK_MINOR_VERSION, TTK_PATCH_VERSION, 0
#define TTK_RC_PRODUCTVERSION   TTK_VERSION_STR
#define TTK_RC_COMPANY          "Greedysky Studio"
#define TTK_RC_COPYRIGHT        "Copyright (C) 2025 Greedysky Studio"

#define TTK_VERSION_CHECK(major, middle, minor, patch)        ((major<<12)|(middle<<8)|(minor<<4)|(patch))
#define TTK_VERSION_CHECK_STR(major, middle, minor, patch)    TTK_VERSION_CHECK_STR_I(major, middle, minor, patch)
#define TTK_VERSION_CHECK_STR_I(major, middle, minor, patch)  #major "." #middle "." #minor "." #patch

#endif // TTKVERSION_H
