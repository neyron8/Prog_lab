#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int binary(int num) {

	int j,bin = 0, base = 1;
	while (num > 0) {

		j = num % 2;
		bin = bin + base * j;
		num = num / 2;
		base = base * 10;	
	
	}

	return bin;
}

