#ifndef _DEBUG_H
#define _DEBUG_H

#include <stdio.h>

#ifdef DEBUG

#define INFO(format) fprintf(stderr, "File: %s. Line: %d. Function: %s. Error message: " format "\n", __FILE__, __LINE__, __func__)
#define LOG(format) fprintf(stderr, "File: %s. Line: %d. Function: %s. Error message: " format "\n", __FILE__, __LINE__, __func__, __VA_ARGS__)

#else

#define INFO(...)
#define LOG(...)

#endif /* DEBUG */

#endif /* end of include guard: _DEBUG_H */
