#ifndef GREP_FUNCS
#define GREP_FUNCS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file(FILE *fp);
void simple_output(char *argv, char *new_str, char *arg, int k);
void ignore_sens(char *argv, char *new_str, int k, char *arg);
int check(char *argv);
void count_str_file(char *argv, char *new_str, char *arg, int k);
void counter_str(char *argv, char *new_str, char *arg, int k);
void match_file(char *argv, char *new_str, char *arg);
void is_flag(char **argv, char *str, char *arg, int k);
void start(int i, int argc, char **argv);
char *unsens_prep(char *new_str);
void invert_output(char *argv, char *new_str, char *arg, int k);
char *prepar_str(char *new_str, int *count, int *i);
void without_namefile(char *argv, char *new_str);
void only_pattern(char *argv, char *new_str, char *arg, int k);
void pattern_is_file(char *argv, char *new_str, char *arg, int k);
char **str_to_mass(char *new_str, int count);
int number_of_line(char *new_str);
void print_only_pat(char **db, char *argv, char *arg, int n, int k, int i);

#endif