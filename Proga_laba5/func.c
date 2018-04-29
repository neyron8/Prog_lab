#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void remove_sim(char *s)
{
    char res[200];
    int i = 0, k = 0;

    for (i = 0; i < slen(s); i++) {
        if (s[i] != ' ') {
            res[k] = s[i];
            k++;
        }
    }
    scopy(res, s);
}

int sch(char str[], char sim)
{
    int i, idx = -1;
    for (i = 0; (str[i] != '\0') && (str[i] != sim); i++);

    if (str[i] == sim) {
        idx = i;
    }
    return idx;
}

int change(char *s, char sim, char zam)
{
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == sim) {
            s[i] = zam;
        }
    }
    for (i = 0; s[i] != '\0'; i++) {
        if ((s[i] == zam) && (s[i + 1] == zam)) {
            s[i] = ' ';
        }
    }

    return 0;
}

int stok(char str[], char delim, char *ptr[])
{
    char *suf = str;
    ptr[0] = str;
    int i, j = 1;
    while ((i = sch(suf, delim)) >= 0) {
        suf[i] = '\0';
        suf = suf + i + 1;
        ptr[j] = suf;
        j++;
    }
    return j;
}

int suntok(char str[], char delim, char *ptr[], int cnt)
{ // cnt dlina ptr
    int i;
    for (i = 1; i < cnt; i++) {
        *(ptr[i] - 1) = delim;
    }
    return 0;
}

int slen(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);

    int len = i;
    return len;
}

int scopy(char *first, char *second) {
    int i;
    for (i = 0; first[i] != '\0'; i++) {
        second[i] = first[i];
    }
    second[i] = '\0';
    return 0;
}

int scmp(char *s1, char *s2) {
    int i, flag = 0;
    for (i = 0; (s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '/0'; i++);
        if (s1[i] < s2[i]) {
            flag = -1;
        } else if (s1[i] > s2[i]) {
            flag = 1;
        }
    return flag;
}

int sspn(char *s, char *dop) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (sch(dop, s[i]) < 0) {
            break;
        }
    }
    return i;
}

int check(char *str) {
    int flag = 0;
    if (slen(str) > 260) {
        return 1;
    }
    return 0;
}

int output(char *str, int end) {
    if (end == 1) {
    printf("Too large string\n");
        exit(2);
    }
    printf("Result:\n");
    printf("%s\n", str);
    return 0;
}

int input(char *str) {
    int flag = 0;
    flag = check(str);
    if (flag == 1 || flag == 2) {
        printf("String is not correct\n");
        exit(1);
    }
    printf("String is correct\n");
    return 0;
}

void plus(char *k) {
    k[slen(k) + 1] = '\0';
    k[slen(k)] = '+';
}

int sstr(char txt[], char p[])
{
    char *suf = txt;
    int len = slen(p);
    int i, pos = -1;
    while( ( ( i = sch(suf,p[0]) ) >= 0) && (pos < 0) ){
        char tmp;
        suf = suf + i;
        tmp = suf[len];
        suf[len] = '\0';
        if( scmp(suf, p) ){
            pos = suf - txt;
        }
        suf[len] = tmp;
        suf++;
    }
    return pos;
}

int process(char *str) {
    int flag = 0;
    char *po[260];
    char syg1[200] = {"/cygdrive/"};
    char syg2[200] = {"+/cygdrive/"};
    input(str);
    change(str, '\\', '/');
    change(str, ':', '/');
    remove_sim(str);
    stok(str, '+', po);
    tolow(*(po + 1),0);
    tolow(*po,0);
    scat(syg1, *po);
    scat(syg2, *(po + 1));
    scat(syg1, syg2);
    plus(syg1);
    scat(syg1, *(po + 2));
    output(syg1, 0);
    return 0;
}

int scat(char *s1, char *s2) {
    int len = slen(s1);
    char *suf = s1 + len;
    scopy(s2, suf);
    return 0;
}

void tolow (char *s, int i)
{
    s[i] = s[i] + ('a' - 'A');
}
