#include "s21_calc.h"

char *parse(char *str, double x) {
  int parse_count = -1;
  int i = 0;
  int check_count = -1;
  int brack_counter = 0;
  int lenght = strlen(str);
  int error_flag = 0;
  char *answer = NULL;
  stack *parse_stack = NULL;
  for (; i < lenght; i++) {
    if (i != lenght - 1 && str[i] == '(' && str[i + 1] != ')') {
      brack_counter++;
      push(&parse_stack, '(', 0, -1);
      parse_count++;
    } else if (i != 0 && i != lenght - 1 && (str[i] == '*' || str[i] == '/') &&
               (str[i - 1] == ')' || (str[i - 1] > 47 && str[i - 1] < 58) ||
                str[i - 1] == 'x')) {
      push(&parse_stack, str[i], 0, 1);
      parse_count++;
    } else if (str[i] == 'l' || str[i] == 'c' || str[i] == 't' ||
               str[i] == 'a' || str[i] == 's' || str[i] == 'm') {
      if (isfunc(&parse_stack, str, &i) == 1) {
        parse_count++;
      }
    } else if (str[i] == ')') {
      brack_counter--;
      parse_count++;
      push(&parse_stack, ')', 0, -1);
    } else if (str[i] > 47 && str[i] < 58) {
      if (isnum(&parse_stack, str, &i, &parse_count) == 404) {
        i = lenght;
        error_flag = 1;
      }
    } else if (str[i] == 'x') {
      push(&parse_stack, str[i], 0, -2);
      parse_count++;
    } else if (str[i] == '+') {
      if (i == 0 || (i != 0 && str[i - 1] == '(')) {
        push(&parse_stack, 'P', 0, 0);
        parse_count++;
      } else if (i != 0 && i != lenght - 1 && str[i + 1] != ')') {
        push(&parse_stack, str[i], 0, 0);
        parse_count++;
      }
    } else if (str[i] == '-') {
      if (i == 0 || (i != 0 && str[i - 1] == '(')) {
        push(&parse_stack, 'M', 0, 0);
        parse_count++;
      } else if (i != 0 && i != lenght - 1 && str[i + 1] != ')') {
        push(&parse_stack, str[i], 0, 0);
        parse_count++;
      }
    } else if (str[i] == '^') {
      if (i != 0 && i != lenght - 1 &&
          (str[i - 1] == ')' || (str[i - 1] > 47 && str[i - 1] < 58) ||
           str[i - 1] == 'x')) {
        push(&parse_stack, str[i], 0, 2);
        parse_count++;
      }
    }
    check_count++;
  }
  if (brack_counter != 0 || check_count != parse_count || error_flag == 1) {
    answer = (char *)calloc(300, sizeof(char));
    strcpy(answer, "Wrong");
    delete_stack(parse_stack);
  } else {
    if (error_flag != 1) {
      stack *new_stack = reverse(parse_stack, &parse_count);
      delete_stack(parse_stack);
      answer = polish_not(new_stack, parse_count, x);
      delete_stack(new_stack);
    }
  }
  return answer;
}

void delete_stack(stack *node) {
  while (node != NULL) {
    stack *tmp = node;
    node = node->next;
    free(tmp);
  }
}

char *polish_not(stack *tmp, int count, double x) {
  stack *polish_stack = NULL;
  stack *node = tmp;
  stack *clean_tmp = NULL;
  int flag = 0;
  int c = 0;
  stack *output_struct = NULL;
  for (int i = 0; i <= count; i++) {
    if (node->sym == 'n' || node->sym == 'x') {
      push(&output_struct, node->sym, node->data, node->prior);
    } else if (node->sym == '(') {
      push(&polish_stack, node->sym, node->data, node->prior);
      c++;
    } else if (node->sym == ')') {
      while (polish_stack->sym != '(') {
        push(&output_struct, polish_stack->sym, polish_stack->data,
             polish_stack->prior);
        clean_tmp = polish_stack;
        polish_stack = polish_stack->next;
        free(clean_tmp);
      }
      c++;
      clean_tmp = polish_stack;
      polish_stack = polish_stack->next;
      free(clean_tmp);
    } else {
      if (polish_stack == NULL || polish_stack->prior < node->prior) {
        push(&polish_stack, node->sym, node->data, node->prior);
      } else if (node->prior <= polish_stack->prior) {
        while (polish_stack != NULL && flag == 0) {
          if (node->prior <= polish_stack->prior) {
            push(&output_struct, polish_stack->sym, polish_stack->data,
                 polish_stack->prior);
            clean_tmp = polish_stack;
            polish_stack = polish_stack->next;
            free(clean_tmp);
          } else {
            flag = 1;
          }
        }
        if (polish_stack == NULL || polish_stack->prior < node->prior) {
          push(&polish_stack, node->sym, node->data, node->prior);
        }
      }
    }
    flag = 0;
    node = node->next;
  }
  while (polish_stack != NULL) {
    push(&output_struct, polish_stack->sym, polish_stack->data,
         polish_stack->prior);
    clean_tmp = polish_stack;
    polish_stack = polish_stack->next;
    free(clean_tmp);
  }
  count = count - c;
  stack *calc_struct = reverse(output_struct, &count);
  delete_stack(output_struct);
  char *str = calc(calc_struct, x);
  delete_stack(calc_struct);
  return str;
}

char *calc(stack *general_stack, double x) {
  stack *calc_struct = general_stack;
  double *str = (double *)calloc(300, sizeof(double));
  char *anwer = (char *)calloc(300, sizeof(char));
  char err[50] = "Wrong";
  int error_flag = 0;
  int i = 0;
  while (calc_struct != NULL && error_flag == 0) {
    if (calc_struct->sym == 'n' || calc_struct->sym == 'x') {
      if (calc_struct->sym == 'n') {
        str[i] = calc_struct->data;
        i++;
        calc_struct = calc_struct->next;
      } else {
        str[i] = x;
        i++;
        calc_struct = calc_struct->next;
      }
    } else {
      if (calc_struct->sym == 'M' && i != 0) {
        str[i - 1] *= -1;
        calc_struct = calc_struct->next;
      } else if (calc_struct->sym == 'P' && i != 0) {
        str[i - 1] = str[i - 1];
        calc_struct = calc_struct->next;
      } else if (calc_struct->sym == '+' && i != 0) {
        str[i - 2] = str[i - 2] + str[i - 1];
        calc_struct = calc_struct->next;
        i--;
      } else if (calc_struct->sym == '-' && i != 0) {
        str[i - 2] = str[i - 2] - str[i - 1];
        calc_struct = calc_struct->next;
        i--;
      } else if (calc_struct->sym == '/' && i != 0) {
        if (str[i - 1] != 0) {
          str[i - 2] = str[i - 2] / str[i - 1];
          calc_struct = calc_struct->next;
          i--;
        } else {
          error_flag = 1;
          strcpy(anwer, err);
        }
      } else if (calc_struct->sym == '*' && i != 0) {
        str[i - 2] = str[i - 2] * str[i - 1];
        calc_struct = calc_struct->next;
        i--;
      } else if (calc_struct->sym == '^' && i != 0) {
        str[i - 2] = pow(str[i - 2], str[i - 1]);
        calc_struct = calc_struct->next;
        i--;
      } else if (calc_struct->sym == 'c' && i != 0) {
        str[i - 1] = cos(str[i - 1]);
        calc_struct = calc_struct->next;
      } else if (calc_struct->sym == 'C' && i != 0) {
        str[i - 1] = acos(str[i - 1]);
        calc_struct = calc_struct->next;
      } else if (calc_struct->sym == 's' && i != 0) {
        str[i - 1] = sin(str[i - 1]);
        calc_struct = calc_struct->next;
      } else if (calc_struct->sym == 'S' && i != 0) {
        str[i - 1] = asin(str[i - 1]);
        calc_struct = calc_struct->next;
      } else if (calc_struct->sym == 't' && i != 0) {
        str[i - 1] = tan(str[i - 1]);
        calc_struct = calc_struct->next;
      } else if (calc_struct->sym == 'T' && i != 0) {
        str[i - 1] = atan(str[i - 1]);
        calc_struct = calc_struct->next;
      } else if (calc_struct->sym == 'g' && i != 0) {
        str[i - 1] = log(str[i - 1]);
        calc_struct = calc_struct->next;
      } else if (calc_struct->sym == 'l' && i != 0) {
        str[i - 1] = log10f(str[i - 1]);
        calc_struct = calc_struct->next;
      } else if (calc_struct->sym == 'q' && i != 0) {
        str[i - 1] = sqrt(str[i - 1]);
        calc_struct = calc_struct->next;
      } else if (calc_struct->sym == 'm' && i != 0) {
        str[i - 2] = fmod(str[i - 2], str[i - 1]);
        calc_struct = calc_struct->next;
      } else {
        error_flag = 1;
        calc_struct = calc_struct->next;
        strcpy(anwer, err);
      }
    }
  }
  if (isfinite(str[0]) == 0) {
    strcpy(anwer, err);
  } else {
    if (error_flag != 1) {
      sprintf(anwer, "%f", str[0]);
    }
  }
  free(str);
  return anwer;
}

stack *reverse(stack *old_struct, int *count) {
  stack *tmp_struct = old_struct;
  stack *new_struct = NULL;
  int c = *count;
  for (int i = 0; i <= c; i++) {
    tmp_struct = peek_struct(old_struct, i);
    push(&new_struct, tmp_struct->sym, tmp_struct->data, tmp_struct->prior);
  }
  (*count) = c;
  return new_struct;
}

stack *peek_struct(stack *top, int count) {
  stack *tale = top;
  for (int i = 0; i < count; i++) {
    tale = tale->next;
  }
  return tale;
}

int isnum(stack **node, char *str, int *i, int *parse_count) {
  int dot_flag = 0;
  double num = 0;
  int count = 2;
  int len = strlen(str);
  if (str[*i] != '0' || (*i != len && str[*i + 1] == '.')) {
    num += str[*i] - '0';
    (*i)++;
    while ((str[*i] > 47 && str[*i] < 58) || (str[*i] == '.')) {
      if (dot_flag == 0 && str[*i] == '.' && str[*i + 1] > 47 &&
          str[*i + 1] < 58) {
        (*i)++;
        num = (num * 10 + (str[*i] - '0')) / 10;
        dot_flag++;
        (*i)++;
      } else if (dot_flag == 1 && str[*i] > 47 && str[*i] < 58) {
        num = (num * pow(10, count) + str[*i] - '0') / pow(10, count);
        count++;
        (*i)++;
      } else if (*i != len && str[*i] > 47 && str[*i] < 58) {
        num = num * 10 + str[*i] - '0';
        (*i)++;
      } else {
        (*parse_count) = -1;
        (*i) = len;
        dot_flag = 404;
      }
    }
    push(node, 'n', num, -2);
    (*parse_count)++;
  } else if (*i != len && str[*i] == '0') {
    num = 0;
    push(node, 'n', num, -2);
    (*parse_count)++;
    (*i)++;
  } else {
    dot_flag = 404;
  }
  (*i)--;
  return dot_flag;
}
// ln = l  log = g cos = c
int isfunc(stack **node, char *str, int *i) {
  int len = strlen(str);
  int res = 1;
  if (str[*i] == 'l') {
    if (*i != len - 2 && str[*i + 1] == 'n' && str[*i + 2] == '(') {
      (*i) += 1;
      push(node, 'l', 0, 3);
    } else if (*i != len - 3 && str[*i + 1] == 'o' && str[*i + 2] == 'g' &&
               str[*i + 3] == '(') {
      (*i) += 2;
      push(node, 'g', 0, 3);
    }
  } else if (str[*i] == 'c') {
    if (*i != len - 4 && str[*i + 1] == 'o' && str[*i + 2] == 's' &&
        str[*i + 3] == '(') {
      (*i) += 2;
      push(node, 'c', 0, 3);
    }
  } else if (str[*i] == 'a') {
    if (*i != len - 5) {
      if (str[*i + 1] == 'c' && str[*i + 2] == 'o' && str[*i + 3] == 's' &&
          str[*i + 4] == '(') {
        (*i) += 3;
        push(node, 'C', 0, 3);
      } else if (str[*i + 1] == 's' && str[*i + 2] == 'i' &&
                 str[*i + 3] == 'n' && str[*i + 4] == '(') {
        (*i) += 3;
        push(node, 'S', 0, 3);
      } else if (str[*i + 1] == 't' && str[*i + 2] == 'a' &&
                 str[*i + 3] == 'n' && str[*i + 4] == '(') {
        (*i) += 3;
        push(node, 'T', 0, 3);
      }
    } else {
      (*i) = len;
    }
  } else if (str[*i] == 's') {
    if (*i != len - 5) {
      if (str[*i + 1] == 'q' && str[*i + 2] == 'r' && str[*i + 3] == 't' &&
          str[*i + 4] == '(') {
        (*i) += 3;
        push(node, 'q', 0, 3);
      } else if (str[*i + 1] == 'i' && str[*i + 2] == 'n' &&
                 str[*i + 3] == '(') {
        (*i) += 2;
        push(node, 's', 0, 3);
      } else {
        (*i) = len;
      }
    } else {
      (*i) = len;
    }
  } else if (str[*i] == 't') {
    if (*i != len - 4 && str[*i + 1] == 'a' && str[*i + 2] == 'n' &&
        str[*i + 3] == '(') {
      (*i) += 2;
      push(node, 't', 0, 3);
    } else {
      (*i) = len;
    }
  } else if (str[*i] == 'm') {
    if (*i != 0 && *i != len - 3 && str[*i + 1] == 'o' && str[*i + 2] == 'd') {
      (*i) += 2;
      push(node, 'm', 0, 2);
    } else {
      (*i) = len;
    }
  } else {
    (*i) = len;
  }
  if ((*i) == len) {
    res = 0;
  }
  return res;
}

void push(stack **top, char c, double x, int prior) {
  stack *node = NULL;
  node = (stack *)malloc(sizeof(stack));
  node->sym = c;
  node->data = x;
  node->prior = prior;
  node->next = *top;
  *top = node;
}
