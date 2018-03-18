#include <stdio.h>
#include <stdlib.h>
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
		  
void int_vector_free(IntVector **v) //Освобождает память, выделенную для вектора v.
{
		free ((*v) -> ptr);
	        free (*v);
	        *v = NULL;
		
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
	
		array -> ptr = malloc ( v -> size * sizeof ( int ) );
	
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
	      
	        v -> used ++;
}

int int_vector_shrink_to_fit(IntVector *v) // Уменьшает емкость массива до его размера
{     	
                v -> ptr = realloc( v -> ptr, (v -> used) * sizeof(int));

		if (v  == NULL ) {
			printf("\nError\n");
                        return -1;
                }
		
	        v -> size = v -> used;
	
                return 0;
		
}

int int_vector_reserve ( IntVector *v, size_t new_capacity ) // Изменить емкость массива.
{
	if ( new_capacity > v -> size ) {
	
		v -> ptr = realloc ( v -> ptr, new_capacity * sizeof ( int ) );
		if ( v == NULL ) {
			printf ("Error of reallocation\n");
			return -1;
		}
		
		v -> size = new_capacity;
		
		return 0;
		
	} 
	else
	    {
			
		printf ("New size smaller\n");	
		return 0;
		
	    }
	
	return -1;
}
		

void int_vector_pop_back ( IntVector *v ) // Удаляет последний элемент из массива.
{
	if ( v -> used == 0 ) {
		printf ("Error\n");
		return;
	}

	v -> ptr [ v -> used - 1] = 0;
	v -> used --;
}

void int_vector_print ( IntVector *v ) //  Печатает массив
{

	if ( v == NULL) {
		printf ("Error: There is no array\n");
		return;
	}
	
	
	for (size_t i = 0; i < v -> used; i++ ) {
		printf (" %d", v -> ptr [i] );
	}
	
}

int int_vector_resize ( IntVector *v, size_t new_size ) // Изменяет размер массива.
{	
	if ( new_size > v -> size ) {
	
		v -> ptr = realloc ( v -> ptr, new_size * sizeof ( int ) );
		if ( v == NULL ) {
			printf ("Error\n");
			return -1;
		}
		
		v -> size = new_size;
		
		for ( size_t i = v -> used; i < v -> size; i++ ) {
			v -> ptr [ i ] = 0;
		}
		
		v -> used = new_size;
		
		return 0;	
	}
	
	if ( new_size > v -> used && new_size <= v -> size ) {
		
		for ( size_t i = v -> used; i < new_size; i++ ) {
			v -> ptr [ i ] = 0;
		}
		
		v -> used = new_size;
	
	}
	
	if ( new_size < v -> used ) {
	
		return int_vector_shrink_to_fit ( v );
		
	}
	
	return -1;
}

int int_vector_push_back ( IntVector *v, int item )
{
	if ( v -> used + 1 < v -> size ) {
		v -> ptr [ v -> used ] = item;
		v -> used ++;
		return 0;
	}else{
		printf ("Expanding vector from %lu to %lu\n", v -> size, v -> size * 2 );
		
		v -> ptr = realloc ( v -> ptr, v -> size * 2 * sizeof ( int ) );
		if ( v == NULL ) {
			printf ("Error of reallocation\n");
			return -1;
		}
		
		v -> size = v -> size * 2;
		v -> ptr [ v -> used ] = item;
		v -> used ++;
		return 0;
	}
	return -1;
}
