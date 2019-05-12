#ifndef __MSVC_THREADS_H
#define __MSVC_THREADS_H

#ifdef _MSC_VER

#define thread_local    __declspec(thread)

#endif

#endif

