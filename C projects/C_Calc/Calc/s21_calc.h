#ifndef S21_CALC_H
#define S21_CALC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
  char sym;
  double data;
  int prior;
  struct stack *next;
} stack;

void push(stack **top, char c, double x, int prior);
char *parse(char *str, double x);
char *calc(stack *general_stack, double x);
char *polish_not(stack *tmp, int count, double x);
int isfunc(stack **node, char *str, int *i);
int isnum(stack **node, char *str, int *i, int *parse_count);
stack *peek_struct(stack *top, int count);
stack *reverse(stack *old_struct, int *count);
void delete_stack(stack *node);

#endif