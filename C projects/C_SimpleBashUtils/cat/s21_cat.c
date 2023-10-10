#include "./s21_cat.h"

int main(int argc, char *argv[]) {
  int len;
  if (argc < 2) {
    printf("Error command\n");
  }
  if (argc >= 2) {
    if (check(argv)) {
      len = 2;
    } else {
      len = 1;
    }
    start(len, argc, argv);
  }
  return 0;
}

void start(int i, int argc, char **argv) {
  FILE *fp;
  char *str, *new_str;
  int flag = 0;
  if (i == 2) {
    flag = 1;
  }
  for (; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (fp != NULL) {
      str = read_file(fp);
      new_str = str;
      if (flag) {
        is_flag(argv[1], strlen(new_str), new_str);
      } else {
        simple_output(strlen(new_str), new_str);
      }
      fclose(fp);
      free(str);
    } else {
      printf("%s: No such file or directory\n", argv[i]);
    }
  }
}

char *read_file(FILE *fp) {
  int i = 0;
  char *str = malloc(sizeof(char));
  fscanf(fp, "%c", &str[i]);
  while (!feof(fp)) {
    str = realloc(str, (i + 1) * sizeof(char) + 1);
    i++;
    fscanf(fp, "%c", &str[i]);
  }
  str[i] = '\0';
  return str;
}

int check(char **argv) {
  int flag = 0;
  if ((strcmp(argv[1], "-b") == 0) || (strcmp(argv[1], "-e") == 0) ||
      (strcmp(argv[1], "--number-nonblank") == 0) ||
      (strcmp(argv[1], "-E") == 0) || (strcmp(argv[1], "--number") == 0) ||
      (strcmp(argv[1], "--squeeze-blank") == 0) ||
      (strcmp(argv[1], "-T") == 0) || (strcmp(argv[1], "-n") == 0) ||
      (strcmp(argv[1], "-s") == 0) || (strcmp(argv[1], "-t") == 0)) {
    flag = 1;
  }
  return flag;
}

void is_flag(char *argv, int i, char *str) {
  if (strcmp(argv, "-b") == 0 || strcmp(argv, "--number-nonblank") == 0) {
    non_empty(i, str);
  }
  if (strcmp(argv, "-e") == 0 || strcmp(argv, "-E") == 0) {
    display_dol(i, str);
  }
  if (strcmp(argv, "-n") == 0 || strcmp(argv, "--number") == 0) {
    number_line(i, str);
  }
  if (strcmp(argv, "-s") == 0 || strcmp(argv, "--squeeze-blank") == 0) {
    empty_str(i, str);
  }
  if (strcmp(argv, "-t") == 0 || strcmp(argv, "-T") == 0) {
    tabs(i, str);
  }
}

void simple_output(int i, char *str) {
  for (int j = 0; j < i; j++) {
    printf("%c", str[j]);
  }
}

void non_empty(int i, char *str) {
  int j = 0, k = 1;
  if (str[j] != '\n' && str[j] != '\0') {
    printf("%6d\t%c", k, str[j]);
    k++;
    j++;
  }
  for (; j < i; j++) {
    if (str[j] != '\n' && str[j - 1] == '\n') {
      printf("%6d\t%c", k, str[j]);
      k++;
    } else {
      printf("%c", str[j]);
    }
  }
}

void display_dol(int i, char *str) {
  for (int j = 0; j < i; j++) {
    if (str[j] == '\n') {
      if (str[j] >= 0 && str[j] != 9 && str[j] != 10 && str[j] <= 31) {
        printf("^%c", str[j] + 64);
      } else {
        if (str[j] == 127) {
          printf("^?");
        } else {
          printf("$%c", str[j]);
        }
      }
    } else {
      if (str[j] >= 0 && str[j] != 9 && str[j] != 10 && str[j] <= 31) {
        printf("^%c", str[j] + 64);
      } else {
        if (str[j] == 127) {
          printf("^?");
        } else {
          printf("%c", str[j]);
        }
      }
    }
  }
}

void number_line(int i, char *str) {
  int k = 1;
  if (str[0] != '\0') {
    printf("%6d\t", k);
    k++;
  }
  for (int j = 0; j < i; j++) {
    if (str[j] == '\n' && j != i - 1) {
      printf("%c%6d\t", str[j], k);
      k++;
    } else {
      printf("%c", str[j]);
    }
  }
}

void empty_str(int i, char *str) {
  int j = 0;
  if (str[j] == '\n' && str[j + 1] == '\n') {
    printf("%c", str[j]);
    j = j + 2;
  }
  for (; j < i; j++) {
    if (str[j] == '\n' && str[j - 1] == '\n' && str[j - 2] == '\n') {
    } else {
      printf("%c", str[j]);
    }
  }
}

void tabs(int i, char *str) {
  for (int j = 0; j < i; j++) {
    if (str[j] == '\t') {
      printf("^I");
    } else {
      if (str[j] >= 0 && str[j] != 9 && str[j] != 10 && str[j] <= 31) {
        printf("^%c", str[j] + 64);
      } else {
        if (str[j] == 127) {
          printf("^?");
        } else {
          printf("%c", str[j]);
        }
      }
    }
  }
}
