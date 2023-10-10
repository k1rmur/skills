#ifndef CAT_FUNCS
#define CAT_FUNCS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file(FILE *fp);
void start(int i, int argc, char **argv);
void simple_output(int i, char *str);
void is_flag(char *argv, int i, char *str);
void non_empty(int i, char *str);
void number_line(int i, char *str);
void display_dol(int i, char *str);
void empty_str(int i, char *str);
void tabs(int i, char *str);
int check(char **argv);

#endif