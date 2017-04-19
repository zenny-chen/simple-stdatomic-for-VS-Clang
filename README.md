# simple-stdatomic-for-VS-Clang
Simple <stdatomic.h> library implementation for Clang in Visual Studio 2017.

Clang in Visual Studio 2017 is really smart. However the MS-CodeGen backend does not support atomic operation functions. Here is a simple implementation of the atomic operation via intrinsic functions on x64 platform. 
