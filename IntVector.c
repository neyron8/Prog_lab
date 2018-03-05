#include <stdio.h>
#include <stlib.h>

IntVector *int_vector_new(size_t initial_capacity)
{ 
	IntVector *array = malloc (sizeof (IntVector);
    if (array == NULL) {
    	printf ("\nError");
        return NULL;
	array->size = initial_capacity;
    array->ptr = malloc(initial_capacity * sizeof(size_t));
	if (array->ptr == NULL) {
		printf("Error\n");
        return -1;
	}
    array->used = 0;   
    return 0;
}
		  
