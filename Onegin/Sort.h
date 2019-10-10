#pragma once

#include "String.h"

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

//! function for qsort, that sort in straight order
int compare(const void* lhs, const void* rhs);

//!
//! \param strings - array of structures String of original text
//! \param strings_sorted - array of structures String of sorted in straight order text
//! \param strings_count - number of lines in text
//! \return array of structures String of sorted in straight order text
String * sort_text(String *strings, String *strings_sorted, int strings_count);

//! function for qsort, that sort in back order
int compare_back(const void *lhs, const void *rhs);

//!
//! \param strings - array of structures String of original text
//! \param strings_sorted_back - array of structures String of sorted in back order text
//! \param strings_count - number of lines in text
//! \return - array of structures String of sorted in back order text
String * sort_text_back(String *strings, String *strings_sorted_back, int strings_count);