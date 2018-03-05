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
		  
void int_vector_free(IntVector *v)
{
	free (v->ptr);
	v->size = v->used = 0;
}

size_t int_vector_get_size(const IntVector *v)
{
	return v->used;
}

size_t int_vector_get_capacity(const IntVector *v)
{
	return v->size;
} 

int int_vector_resize(IntVector *v, size_t new_size) 
{
	if ( v->used + new) // realloc Нужен
}
