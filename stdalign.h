#ifndef __STDALIGN_H
#define __STDALIGN_H

#ifdef _MSC_VER

#define alignof             _Alignof
#define alignas(nBytes)     __declspec(align(nBytes))

#endif // _MSC_VER

#endif

