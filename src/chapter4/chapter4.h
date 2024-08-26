#ifndef CHAPTER_4_INTERNAL_H
#define CHAPTER_4_INTERNAL_H

#define BUFSIZE 100
#define MAXVAL 100

extern char buffer[BUFSIZE];
extern int buffer_pos;
extern int sp;
extern double stack[MAXVAL];
extern double variables[26];
extern int variables_p;
extern char var;

int get_line(char line[], int max_line_len);

// Reverse Polish calculator
int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void view_head(void);
void duplicate_head(void);
void swap(void);
void clear(void);
void retrieve_var(char c);
float peek();
int getop_vars(char s[]);
void store_var();

void exercise_4_1();
void exercise_4_2();
void exercise_4_3();
void exercise_4_4();
void exercise_4_5();
void exercise_4_6();
void exercise_4_7();
void exercise_4_8();
void exercise_4_9();
void exercise_4_10();
void exercise_4_11();
void exercise_4_12();
void exercise_4_13();
void exercise_4_14();

#endif