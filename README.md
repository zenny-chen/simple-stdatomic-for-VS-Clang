# Implement several missing C11 standard libraries for MSVC in Visual Studio 2019
Simple <stdatomic.h>, <stdalign.h> and <threads.h> implementation for MSVC in Visual Studio 2019.

MSVC in Visual Studio 2019 has already support part of C11 standard features such as unicode, `_Alignof`, etc. However, there are some language features supported in MSVC but not as standard libraries. Here encapsulate some useful features and export as C11 standard libraries.
