#include <stdio.h>
#include "test.h"

int main() {
	
	int l,u;
	printf("Type your decimal number:");
	scanf("%d\n",&l);
	u = binary(l);
	printf("%d", u);

	return 0;
}
