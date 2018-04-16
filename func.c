#include <stdio.h>


int sum_array (int *mas, int count, int sum, int pl)
{
	if (mas == NULL) {
		return sum;
	}
	
	if (count == 0) {
		return NULL;
	}
	if (pl < count){
		sum = sum + mas[pl];
	}
	else {

		return sum;
	}
	pl = pl + 1;

	return sum_array(mas, count , sum, pl) + sum;
}		
