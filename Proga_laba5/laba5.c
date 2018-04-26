#include <stdio.h>
#include <string.h>

int sch (char str[], char sim){
	int i, idx =  -1;
	for (i = 0; (str[i] != '\0') && (str [i] != sim); i++);
	if (str[i] == sim){
		idx = i;
	}
    return idx;
}
int stok (char str[], char delim , char *ptr[]){
	char *suf = str;
	ptr[0] = str;
	int i, j = 1;
	while (( i = sch(suf, delim)) >= 0) {
		suf [i] = '\0';
	   	suf = suf + i + 1;
		ptr[j] = suf;
	    j++;
	}
	return j;
}

int suntok (char str[], char delim, char *ptr[], int cnt ){ // cnt dlina ptr

	int i;
	for(i = 1; i < cnt; i++){
		*(ptr[i] - 1) = delim;
	}
	return 0;
}



int main()
{
	char k[] = {"abd+asd+adddddd"};
	char *po[19];
	int i = stok (k, '+', po);
	printf("%d",i );
	printf("%s\n", *(po));
	printf("%s\n", *(po +1));
	printf("%s\n", *(po + 2));
	suntok(k,'+',po,i);
	printf("%s", k);
	return 0;
}
