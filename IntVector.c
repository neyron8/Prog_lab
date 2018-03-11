#include <stdio.h>
#include <stlib.h>
#include <string.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity)
{ 
	    IntVector *array = malloc (sizeof (IntVector);
				       
   	    if (array == NULL) {
    	        printf ("\nError");
                return NULL;
	    }
	    array -> size = initial_capacity;
				   
            array -> ptr = calloc (array -> size , sizeof ( int ));
				   
	    if (array -> ptr == NULL) {
	        printf ("Error\n");
                return NULL;
	    }
            array -> used = 0;   
            printf ("\n Vector is ready\n")		       
            return array;
}
		  
void int_vector_free(IntVector *v)
{
	free (v -> ptr);
	v -> size = v -> used = 0;
	*v = NULL;
	printf ("\nVector is free\n");
}

size_t int_vector_get_size (const IntVector *v)
{
	return v -> used;
}

size_t int_vector_get_capacity (const IntVector *v)
{
	return v -> size;
} 

int int_vector_resize (IntVector *v, size_t new_size) 
{
	if ( v -> used + new) // realloc
		
}
				       
IntVector *int_vector_copy ( const IntVector *v )
{
	IntVector *array = malloc ( sizeof ( IntVector ) );
	
	if ( mass == NULL ) {
		printf ("\nError\n");
		return NULL;
	}
	
	array -> size = v -> size;
	
	array -> ptr = calloc ( v -> size , sizeof ( int ) );
	
	if ( array -> ptr == NULL ) {
		printf ("\nError\n");
		return NULL;
	}
	
	for ( size_t i = 0; i < (v -> size); i++ ) {
		array -> ptr [i] = v -> ptr [i];
	}
	
	mass -> used = v -> used;
	
	return mass;
}
				       
int int_vector_get_item ( const IntVector *v, size_t index )
{
	if (index > v -> size - 1) {
		printf ("Out of Vector\n");
		return 0;
	}
	
	return v -> ptr [index];
}
