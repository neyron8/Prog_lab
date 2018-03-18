#include <stdio.h>
#include "IntVector.h"

int main ()
{
	int flag;
	printf ("\tVector with 4 elements(empty)\n");
	IntVector *mass = int_vector_new ( 4 );

	int_vector_print ( mass );


	int_vector_set_item ( mass, 0, 1 );
    int_vector_set_item ( mass, 1, 2 );
    int_vector_set_item ( mass, 2, 3 );
    printf ("\nVector with 4 elements(1 of them empty)\n");

	int_vector_print ( mass );


	printf ("\nCopy\n");

	IntVector *copy = int_vector_copy ( mass );
	int_vector_print ( copy );


	printf("\nPush back\n");

	int_vector_push_back ( mass, 5 );
	printf("\nNew element is 5\n");
	int_vector_print ( mass );

	printf("\nPush back with new capacity\n");

	int_vector_push_back ( mass, 6 );
	printf("\nNew element is 6\n");
	int_vector_print ( mass );
	
    printf("%d",int_vector_get_item ( mass, 0 ));
    printf("%d",int_vector_get_item ( mass, 1 ));
    printf("%d",int_vector_get_item ( mass, 2 ));
    printf("%d",int_vector_get_item ( mass, 3 ));
	printf("%d",int_vector_get_item ( mass, 4 ));
	printf("%d",int_vector_get_item ( mass, 5 ));
	
	printf ("\tFREE\n");

	int_vector_free ( &mass );
	int_vector_free ( &copy );


	

	return 0;
  }
