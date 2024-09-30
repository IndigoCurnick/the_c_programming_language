#ifndef CHAPTER_5_INTERNAL_H
#define CHAPTER_5_INTERNAL_H

int getch(void);
void ungetch(int);
int get_line(char line[], int max_line_len);
int str_len(char *s);

void exercise_5_1();
void exercise_5_2();
void exercise_5_3();
void exercise_5_4();
void exercise_5_5();
void exercise_5_6();
void exercise_5_7();
void exercise_5_8();
void exercise_5_9();
void exercise_5_10(int argc, char *argv[]);
void exercise_5_11(int argc, char *argv[]);

#endif