#ifndef INTVECTOR_C
#define INTVECTOR_C

typedef struct {
    size_t *ptr;
    size_t size;
    size_t used;
} IntVector;


IntVector *int_vector_new ( size_t initial_capacity );
IntVector *int_vector_copy ( const IntVector *v );
void int_vector_free ( IntVector *v );
size_t int_vector_get_size ( const IntVector *v );
size_t int_vector_get_capacity ( const IntVector *v );

#endif
