#pragma once

#ifdef OSDEV
#define NULL 0
#define nullptr (void*)
#endif
#ifndef __cplusplus
#define null NULL
#endif
#ifdef __cplusplus
#define null nullptr
#endif