#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity) //Создает массив нулевого размера.
{ 
	    IntVector *array = malloc (sizeof (IntVector));
				       
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
            printf ("\n Vector is ready\n");		       
            return array;
}
		  
void int_vector_free(IntVector *v) //Освобождает память, выделенную для вектора v.
{
		free (v -> ptr);
		v -> size = 0;
		v -> used = 0;
		printf ("\nVector is free\n");
}

size_t int_vector_get_size (const IntVector *v) //	Размер вектора
{
		return v -> used;
}

size_t int_vector_get_capacity (const IntVector *v) //	Eмкость вектора
{
		return v -> size;
} 

				       
IntVector *int_vector_copy ( const IntVector *v ) // Указатель на копию вектора v.
{
		IntVector *array = malloc ( sizeof ( IntVector ) );
	
		if ( array == NULL ) {
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
	
		array -> used = v -> used;
	
		return array;
}
				       
int int_vector_get_item ( const IntVector *v, size_t index ) // элемент под номером index
{
		if (index > v -> size - 1) {
			printf ("Out of Vector\n");
			return 0;
		}
	
		return v -> ptr [index];
}

void int_vector_set_item ( IntVector *v, size_t index, int item ) // Присваивает элементу под номером index значение item.
{
		if (index > v -> size - 1) {
			printf ("Out of the vector\n");
			return;
        }
		v -> ptr [index] = item;
}

int int_vector_shrink_to_fit(IntVector *v) // Уменьшает емкость массива до его размера
{     
		
		v -> size = v -> used;
        v -> ptr = realloc( v -> ptr, (v -> used) * sizeof(int));

		if (v == NULL ) {
			printf("\nError\n");
            return -1;
        }
		else
        return 0;
}

		
