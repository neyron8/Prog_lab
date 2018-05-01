#ifndef FUNC_H
#define FUNC_C

void double_rem (char *s, char sim);
void tolow (char *s, int i);
int scat(char *s1, char *s2);
int process(char *str);
int sstr(char txt[], char p[]);
void plus(char *k);
int input(char *str);
int output(char *str, int end);
int check(char *str);
int sspn(char *s, char *dop);
int scmp(char *s1, char *s2);
int scopy(char *first, char *second);
int slen(char *str);
int suntok(char str[], char delim, char *ptr[], int cnt);
int stok(char str[], char delim, char *ptr[]);
int change(char *s, char sim, char zam);
int sch(char str[], char sim);
void remove_sim(char *s);
int window (char *s);
int scspn(char str[], char nsym[]);

#endif
