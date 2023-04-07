//create dynamic array, like vector in c++
//create, append, pop, sort, clear, destroy an array
//get, set a value at a specific index

#include <stdio.h>
#include "int_array.h"


int main() {
    struct int_array* myarray = create_array(7);

    array_append(myarray,1);
    array_append(myarray,6);
    array_append(myarray,4);
    array_append(myarray,2);
    array_append(myarray,5);
    array_append(myarray,3);
    array_append(myarray,12);

    array_sort(myarray);

    array_print(myarray);

    array_pop(myarray);
   
    array_print(myarray);

    array_set(myarray,0,100);

    array_print(myarray);

    printf("%d\n", array_get(myarray,0));

    array_clear(myarray);

    array_print(myarray);

    destroy_array(myarray);

    return 0;
}

