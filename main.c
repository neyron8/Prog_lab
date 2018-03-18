#include <stdio.h>
#include "IntVector.h"

int main ()
{
	int flag;
	IntVector *mass = int_vector_new ( 4 );
  
	printf ("\tVector with 4 elements(empty)\n");
	
	int_vector_print ( mass );
	
	int_vector_set_item ( mass, 0, 1 );
        int_vector_set_item ( mass, 1, 2 );
        int_vector_set_item ( mass, 2, 3 );
 
	
	int_vector_print ( mass );
		
	printf ("\tError block\n");
	
	printf("%d",int_vector_get_item ( mass, 0 ));
        printf("%d",int_vector_get_item ( mass, 1 ));
        printf("%d",int_vector_get_item ( mass, 2 ));
        printf("%d",int_vector_get_item ( mass, 3 ));
	
	int_vector_set_item ( mass, 42, 25 );
	
	
	
	printf ("\tCopy\n");
	
	IntVector *copy = int_vector_copy ( mass );
	int_vector_print ( copy );
	

	printf ("Size of mass vector %lu\n", int_vector_get_capacity ( mass ));
	
	printf ("Used in mass vector %lu\n",int_vector_get_size ( mass ));
		
	printf ("\tFREE\n");
	
	int_vector_free ( &mass );
	int_vector_free ( &copy );
		
	
	int_vector_print ( mass );
	int_vector_print ( copy );
	
	
	
	
	printf ("\tAdding an element to the end of the vector\n");
	
	mass = int_vector_new ( 2 );
	
	flag = int_vector_push_back ( mass, 3 );
	
	if ( flag == 0 ) {
		printf ("Success !\n");
	}else{
		printf ("NOt Succesful\n");
	}
	
	int_vector_print ( mass);
	
	int_vector_free ( &mass );
	
	//Push back with expand
	mass = int_vector_new ( 3 );
	
	flag = int_vector_push_back ( mass, 7 );
	flag = int_vector_push_back ( mass, 6 );
	flag = int_vector_push_back ( mass, 5 );
	flag = int_vector_push_back ( mass, 4 );
	
	if ( flag == 0 ) {
		printf ("Success\n");
	}else{
		printf ("No\n");
	}
	
	int_vector_print ( mass );
	
	int_vector_free ( &mass );
	
	
	
	printf ("\tDelete end of vector\n");
	
	mass = int_vector_new ( 2 );
		
	int_vector_print ( mass );

	int_vector_pop_back ( mass );
	
	int_vector_print ( mass );
	
	
	int_vector_free ( &mass );
	
	
	printf ("\tShrink vector\n");
	
	mass = int_vector_new ( 2 );
	
	answer = int_vector_push_back ( mass, 1 );
	answer = int_vector_push_back ( mass, 2 );
	
	int_vector_print ( mass );
	
	answer = int_vector_shrink_to_fit ( mass );
	
	if ( answer == 0 ) {
		printf ("OK !\n");
	}else{
		printf ("NOT OK !!!\n");
	}
	
	int_vector_print ( mass, "mass" );
	
	int_vector_free ( &mass );
	
	printf ("\tEnd of operation\n\n");
	printf ("\tNext ->");
	
	
	printf ("\tResize\n");
	
	//New size bigger then start size
	mass = int_vector_new ( 3 );
	
	answer = int_vector_push_back ( mass, 1 );
	answer = int_vector_push_back ( mass, 2 );
	
	int_vector_print ( mass );
	
	answer = int_vector_resize ( mass, 5);
	
	if ( answer == 0 ) {
		printf ("OK !\n");
	}else{
		printf ("NOT OK !!!\n");
	}
	
	int_vector_print ( mass);
	
	
	
	int_vector_print ( mass );
	
	int_vector_free ( &mass );
	

	return 0;
  }
