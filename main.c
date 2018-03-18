#include <stdio.h>
#include "IntVector.h"

int main ()
{
	int flag;
	printf ("Vector with 4 elements(empty)\n");
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
        printf("\n");

	printf("Size of vector=%d\n",int_vector_get_size (mass)); 
        printf("Capacity of vector=%d\n",int_vector_get_capacity (mass));


        int_vector_shrink_to_fit(mass);


        printf("Size of vector after shrink=%d\n",int_vector_get_size (mass)); 
        printf("Capacity of vector after shrink=%d\n",int_vector_get_capacity (mass)); 


        int_vector_free(&mass);

        mass = int_vector_new ( 4 );
	int_vector_set_item ( mass, 0, 1 );
        int_vector_set_item ( mass, 1, 2 );
        int_vector_set_item ( mass, 2, 3 );


        int_vector_print ( mass );
	printf("\nDeleting last element of array\n");
	int_vector_pop_back ( mass );
	printf("\nArray after deleting\n");	
        int_vector_print ( mass );


	printf("\n");


        int_vector_get_item ( mass , 0);
        int_vector_get_item ( mass , 1);
        int_vector_get_item ( mass , 2);


        printf("Resizing t0 6\n");
	int_vector_resize ( mass, 6 );
	printf("Array after resizing t0 6\n");
        int_vector_print ( mass );


	printf("\n");


	printf("Capacity   %d\n",mass -> size);
	printf("Size of array  %d\n",mass -> used)

;
	printf("\n");


	int_vector_push_back ( mass, 12);
	int_vector_print ( mass );

	printf("\n");

        printf("Capacity  %d\n",mass->size);
	printf("Size  %d\n",mass->used);

	printf ("%d ",int_vector_get_item ( mass, 0  ));
	printf ("%d ",int_vector_get_item ( mass, 1  ));
	printf ("%d ",int_vector_get_item ( mass, 2  ));

	

	return 0;
}
