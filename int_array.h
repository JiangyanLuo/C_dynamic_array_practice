struct int_array{
    int len;
    int capacity; 
    int* data;
};

struct int_array* create_array(int initial_capacity);
void destroy_array(struct int_array*);
void array_append(struct int_array*, int value);
void array_pop(struct int_array*);
void array_sort(struct int_array*);
void array_clear(struct int_array*);
void array_set(struct int_array*, int index, int value);
int array_get(struct int_array*, int index);
void array_print(struct int_array*);
