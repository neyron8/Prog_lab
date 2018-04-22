#include <math.h>
#include <stdio.h>

int fibonachi (int num)
{
	if (num == 2 || num == 1 ) {
		return 1;
	}
	return fibonachi (num - 1) + fibonachi (num - 2);
}

int sum_array (int *mas, int count)
{
	if (count == 0){
		return 0;
	}
	return *mas + sum_array(mas + 1, count - 1);	
}

int fibonachi_iter (int first, int second, int num, int tmp, int count )
{
	if (count > num){
		return tmp;
	}
	if (num == 1 || num == 2){
		return 1;
	}
	tmp = first + second;
	first = second;
	second = tmp;
	count ++;
	return fibonachi_iter(first,second,num,tmp,count );
}

int sum_array_iter (int *mas, int count,int sum)
{
	if (count == 0){
		return sum;
	}
	sum = sum + *mas;
	mas = mas + 1;
	count = count - 1;
	return sum_array_iter(mas, count, sum);	
}

int string(char *str, int sum) {
  if (*str == '\0') {
    return sum;
  }
  sum = sum + (*str - 48) * pow(10, strlen(str) - 1);
  str = str + 1;
  return string(str, sum);
}

int main() {
  char h[] = {"1234"};
  int sum = 0;
  printf("%d\n", string(h, sum));
  int l = 5;
	int k;
	k = fibonachi (l);
	printf ("%d\n", k);
	int arr [] = {1,2,3,4};
	printf("%d\n", sum_array(arr, 4)); 
	int f = 1,s = 1,count = 3, t = 0, res ;
	res = fibonachi_iter(1,1,5,t,count );
	printf("%d\n", res);
	int summa;
	summa = sum_array_iter (arr,4,summa);
	printf("%d", summa);
  return 0;
}
