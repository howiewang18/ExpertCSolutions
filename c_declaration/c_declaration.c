#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 64

enum TypeTag { IDENTIFIER, QUALIFIER, TYPE };

struct Token {
  char type;
  char string[MAX_TOKEN_LEN];
};
struct Token this;

int top = -1;
struct Token stack[MAX_TOKENS];

#define pop stack[top--]
#define push(s) stack[++top] = s

/*Figure out the identifier type.*/
enum TypeTag classify_string(void) {
  char *s = this.string;
  if (!strcmp(s, "const")) {
    strcpy(s, "read-only");
    return QUALIFIER;
  }
  if (!strcmp(s, "volatile")) {
    return QUALIFIER;
  }
  if (!strcmp(s, "volatile") || !strcmp(s, "void") || !strcmp(s, "char") ||
      !strcmp(s, "signed") || !strcmp(s, "unsigned") || !strcmp(s, "short") ||
      !strcmp(s, "int") || !strcmp(s, "long") || !strcmp(s, "float") ||
      !strcmp(s, "double") || !strcmp(s, "struct") || !strcmp(s, "union") ||
      !strcmp(s, "enum"))
    return TYPE;
  return IDENTIFIER;
}

/* Read next token into "this"*/
void get_token(void) {
  char *p = this.string;
  while ((*p = getchar()) == ' ')
    ;
  if (isalnum(*p)) {
    while (isalnum(*++p = getchar()))
      ;
    ungetc(*p, stdin);
    *p = '\0';
    this.type = classify_string();
    return;
  }
  if (*p == '*') {
    strcpy(this.string, "pointer to ");
    this.type = '*';
    return;
  }
  this.string[1] = '\0';
  this.type = *p;
}

void read_to_first_identifier() {
  get_token();
  while (this.type != IDENTIFIER) {
    push(this);
    get_token();
  }
  printf("%s is ", this.string);
  get_token();
}

void deal_with_arrays() {
  while (this.type == '[') {
    printf("array ");
    /* A number or ']'*/
    get_token();
    if (isdigit(this.string[0])) {
      printf("0..%d ", atoi(this.string) - 1);
      get_token(); /* Read the ']'*/
    }
    get_token(); /* Read past ']'*/
    printf("of ");
  }
}

void deal_with_function_args() {
  int level = 0;
  while (1) {
    if (this.type == ')') {
      if (level == 1) {
        break;
      }
      level -= 1;
    } else if (this.type == '(') {
      level += 1;
    }
    get_token();
  }
  get_token();
  printf("function returning ");
}

void deal_with_pointers() {
  while (stack[top].type == '*') {
    printf("%s", pop.string);
  }
}

void deal_with_declarator() {
  /* Deal with possible array/function following the identifier*/
  switch (this.type) {
    case '[':
      deal_with_arrays();
      break;
    case '(':
      deal_with_function_args();
      break;
    default:;
  }
  deal_with_pointers();
  /* Process tokens that we stacked while reading to the identifier. */
  while (top >= 0) {
    if (stack[top].type == '(') {
      pop;
      get_token(); /*  Read past ')'*/
      deal_with_declarator();
    } else {
      printf("%s ", pop.string);
    }
  }
}

int main() {
  read_to_first_identifier();
  deal_with_declarator();
  printf("\n");
  return 0;
}
