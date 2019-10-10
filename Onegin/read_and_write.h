#pragma once

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "String.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define bufsize 10240

//!
//! \param buf - storage buffer
//! \param filename - input file name
void input_text(char *buf, char *filename);

//!
//! \param strings - array of structures String (text)
//! \param strings_count - number of lines in text
//! \param filename - output file name
void print_text_in_file(String *strings, int strings_count, char *filename);

//!
//! \param buf - storage buffer
//! \return number of lines in text
int count_strings(char *buf);

//! makes array of structures String of text and replaces "\n" with "\0"
//! \param - strings array of structures String (text)
//! \param - buf storage buffer
//! \return - strings array of structures String (text)
String * make_index(String *strings, char *buf);