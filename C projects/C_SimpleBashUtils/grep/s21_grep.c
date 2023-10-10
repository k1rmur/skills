#include "./s21_grep.h"

int main(int argc, char *argv[]) {
  int len;
  if (argc <= 2) {
    printf("Error command\n");
  }
  if (argc >= 3) {
    if (check(argv[1])) {
      len = 3;
    } else {
      len = 2;
    }
    start(len, argc, argv);
  }
  return 0;
}

void start(int i, int argc, char **argv) {
  FILE *fp;
  char *str, *new_str;
  int flag = 0, k;
  if (i == 3) {
    flag = 1;
  }
  k = argc - i - 1;
  for (; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (fp != NULL) {
      str = read_file(fp);
      new_str = str;
      if (flag) {
        is_flag(argv, new_str, argv[i], k);
      } else {
        simple_output(argv[1], new_str, argv[i], k);
      }
      fclose(fp);
      free(str);
    } else {
      if (strcmp(argv[1], "-s") != 0) printf("%s:Error path\n", argv[i]);
    }
  }
}

char *read_file(FILE *fp) {
  int i = 0, counter = 1;
  char *str = malloc(100 * sizeof(char));
  if (str != NULL) {
    fscanf(fp, "%c", &str[i]);
    while (!feof(fp)) {
      if (i % 100 == 0) {
        counter++;
        char *temp = realloc(str, counter * 100);
        if (temp == NULL) {
          exit(0);
        } else {
          str = temp;
        }
      }
      i++;
      fscanf(fp, "%c", &str[i]);
    }
    str[i] = '\0';
  } else {
    exit(0);
  }
  return str;
}

int check(char *argv) {
  int flag = 0;
  if ((strcmp(argv, "-e") == 0) || (strcmp(argv, "-i") == 0) ||
      (strcmp(argv, "-v") == 0) || (strcmp(argv, "-c") == 0) ||
      (strcmp(argv, "-n") == 0) || (strcmp(argv, "-l") == 0) ||
      (strcmp(argv, "-h") == 0) || (strcmp(argv, "-s") == 0) ||
      (strcmp(argv, "-o") == 0) || (strcmp(argv, "-f") == 0)) {
    flag = 1;
  }
  return flag;
}

void is_flag(char **argv, char *str, char *arg, int k) {
  if (strcmp(argv[1], "-e") == 0 || strcmp(argv[1], "-s") == 0)
    simple_output(argv[2], str, arg, k);
  if (strcmp(argv[1], "-i") == 0) ignore_sens(argv[2], str, k, arg);
  if (strcmp(argv[1], "-v") == 0) invert_output(argv[2], str, arg, k);
  if (strcmp(argv[1], "-c") == 0) count_str_file(argv[2], str, arg, k);
  if (strcmp(argv[1], "-n") == 0) counter_str(argv[2], str, arg, k);
  if (strcmp(argv[1], "-l") == 0) match_file(argv[2], str, arg);
  if (strcmp(argv[1], "-h") == 0) without_namefile(argv[2], str);
  if (strcmp(argv[1], "-o") == 0) only_pattern(argv[2], str, arg, k);
  if (strcmp(argv[1], "-f") == 0) pattern_is_file(argv[2], str, arg, k);
}

void simple_output(char *argv, char *new_str, char *arg, int k) {
  char *istr;
  istr = strtok(new_str, "\n");
  while (istr != NULL) {
    if (strstr(istr, argv) != NULL && k != 0) {
      printf("%s:%s\n", arg, istr);
    } else {
      if (strstr(istr, argv) != NULL && k == 0) {
        printf("%s\n", istr);
      }
    }
    istr = strtok(NULL, "\n");
  }
}

void ignore_sens(char *argv, char *new_str, int k, char *arg) {
  char *istr, *istr2, *last;
  char *old_str = unsens_prep(new_str);
  int j = strlen(argv);
  for (int i = 0; i < j; i++) {
    if (argv[i] >= 65 && argv[i] <= 90) {
      argv[i] = argv[i] + 32;
    }
  }
  istr2 = strtok_r(new_str, "\n", &last);
  istr = strtok(old_str, "\n");
  while (istr != NULL) {
    if (strstr(istr, argv) != NULL && k != 0) {
      printf("%s:%s\n", arg, istr2);
    } else {
      if (strstr(istr, argv) != NULL && k == 0) {
        printf("%s\n", istr2);
      }
    }
    istr2 = strtok_r(NULL, "\n", &last);
    istr = strtok(NULL, "\n");
  }
  free(old_str);
}

char *unsens_prep(char *new_str) {
  char *old_str = malloc(100 * sizeof(char));
  if (old_str == NULL) {
    exit(0);
  }
  int j = strlen(new_str), counter = 1;
  for (int i = 0; i < j; i++) {
    if (i % 100 == 0) {
      counter++;
      char *tmp = realloc(old_str, counter * 100);
      if (tmp == NULL) {
        free(old_str);
        exit(0);
      } else {
        old_str = tmp;
      }
    }
    if (new_str[i] >= 65 && new_str[i] <= 90) {
      old_str[i] = new_str[i] + 32;
    } else {
      old_str[i] = new_str[i];
    }
  }
  old_str[j] = '\0';
  return old_str;
}

void invert_output(char *argv, char *new_str, char *arg, int k) {
  char *istr;
  istr = strtok(new_str, "\n");
  while (istr != NULL) {
    if (strstr(istr, argv) == NULL && k != 0) {
      printf("%s:%s\n", arg, istr);
    } else {
      if (strstr(istr, argv) == NULL && k == 0) {
        printf("%s\n", istr);
      }
    }
    istr = strtok(NULL, "\n");
  }
}

void count_str_file(char *argv, char *new_str, char *arg, int k) {
  int count = 0;
  char *istr;
  istr = strtok(new_str, "\n");
  while (istr != NULL) {
    if (strstr(istr, argv) != NULL) {
      count++;
    }
    istr = strtok(NULL, "\n");
  }
  if (k == 0) {
    printf("%d\n", count);
  } else {
    printf("%s:%d\n", arg, count);
  }
}

void counter_str(char *argv, char *new_str, char *arg, int k) {
  int len = strlen(new_str), count = 1, j = 0;
  for (int i = 0; i < len; i++) {
    if (new_str[i] != '\0' && new_str[i] == '\n') count++;
  }
  char **db = malloc(count * len * sizeof(char) + count * sizeof(char *));
  char *ptr = (char *)(db + count);
  for (int i = 0; i < count; i++) {
    db[i] = ptr + len * i;
    int n = 0;
    for (; new_str[j] != '\0' && new_str[j] != '\n'; j++) {
      db[i][n] = new_str[j];
      n++;
    }
    db[i][n] = '\0';
    j++;
    if (strstr(db[i], argv) != NULL && k != 0) {
      printf("%s:%d:%s\n", arg, i + 1, db[i]);
    } else {
      if (strstr(db[i], argv) != NULL && k == 0) {
        printf("%d:%s\n", i + 1, db[i]);
      }
    }
  }
  free(db);
}

void match_file(char *argv, char *new_str, char *arg) {
  char *istr;
  istr = strtok(new_str, "\n");
  while (istr != NULL) {
    if (strstr(istr, argv) != NULL) {
      printf("%s\n", arg);
      break;
    }
    istr = strtok(NULL, "\n");
  }
}

void without_namefile(char *argv, char *new_str) {
  char *istr;
  istr = strtok(new_str, "\n");
  while (istr != NULL) {
    if (strstr(istr, argv) != NULL) {
      printf("%s\n", istr);
    }
    istr = strtok(NULL, "\n");
  }
}

void only_pattern(char *argv, char *new_str, char *arg, int k) {
  int len = strlen(new_str), count = 1, j = 0;
  for (int i = 0; i < len; i++) {
    if (new_str[i] != '\0' && new_str[i] == '\n') count++;
  }
  char **db = malloc(count * len * sizeof(char) + count * sizeof(char *));
  char *ptr = (char *)(db + count);
  for (int i = 0; i < count; i++) {
    db[i] = ptr + len * i;
    int n = 0;
    for (; new_str[j] != '\0' && new_str[j] != '\n'; j++) {
      db[i][n] = new_str[j];
      n++;
    }
    db[i][n] = '\0';
    j++;
    print_only_pat(db, argv, arg, n, k, i);
  }
  free(db);
}

void print_only_pat(char **db, char *argv, char *arg, int n, int k, int i) {
  int len_pat_str = 0;
  int y = 0, flag = 0;
  int ll = strlen(argv);
  for (int l = 0; l < n; l++) {
    if (db[i][l] == argv[y]) {
      y++;
      len_pat_str++;
      if (y > ll - 1) {
        y = 0;
      }
      if (len_pat_str != 0 && len_pat_str % ll == 0 && k == 0) {
        printf("%s\n", argv);
      } else {
        if (len_pat_str % ll == 0 && k != 0 && len_pat_str != 0 && flag == 0) {
          printf("%s:%s\n", arg, argv);
          flag = 1;
        } else {
          if (len_pat_str % ll == 0 && k != 0 && len_pat_str != 0 &&
              flag == 1) {
            printf("%s\n", argv);
          }
        }
      }
    } else {
      if (db[i][l] != argv[y]) {
        y = 0;
        len_pat_str = 0;
      }
    }
  }
}

void pattern_is_file(char *argv, char *new_str, char *arg, int k) {
  FILE *fp_pat;
  char *str1 = NULL, **str_file = NULL, **db = NULL;
  fp_pat = fopen(argv, "r");
  if (fp_pat != NULL) {
    str1 = read_file(fp_pat);
    fclose(fp_pat);
    char *str = str1;
    int count2 = number_of_line(str);
    str_file = str_to_mass(str, count2);
    int count = number_of_line(new_str);
    db = str_to_mass(new_str, count);
    char repeat_str[count];
    for (int i = 0; i < count; i++) {
      repeat_str[i] = 0;
    }
    for (int i = 0; i < count; i++) {
      for (int f = 0; f < count2; f++) {
        if (strstr(db[i], str_file[f]) != NULL && k == 0) {
          if (repeat_str[i] == 0) {
            printf("%s\n", db[i]);
            repeat_str[i] = 1;
          }
        } else {
          if (strstr(db[i], str_file[f]) != NULL && k != 0) {
            if (repeat_str[i] == 0) {
              printf("%s:%s\n", arg, db[i]);
              repeat_str[i] = 1;
            }
          }
        }
      }
    }
    free(str1);
    free(str_file);
    free(db);
  } else {
    printf("Error pattern file%s", arg);
  }
}

int number_of_line(char *new_str) {
  int len = strlen(new_str), count = 1;
  for (int i = 0; i < len; i++) {
    if (new_str[i] != '\0' && new_str[i] == '\n') count++;
  }
  return count;
}

char **str_to_mass(char *new_str, int count) {
  int j = 0, len = strlen(new_str);
  char **db = malloc(count * len * sizeof(char) + count * sizeof(char *));
  char *ptr = (char *)(db + count);
  for (int i = 0; i < count; i++) {
    db[i] = ptr + len * i;
    int n = 0;
    for (; new_str[j] != '\0' && new_str[j] != '\n'; j++) {
      db[i][n] = new_str[j];
      n++;
    }
    db[i][n] = '\0';
    j++;
  }
  return db;
}
