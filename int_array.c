#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "int_array.h"

#define max(a,b) a > b ? a : b 


struct int_array* create_array(int initial_capacity){
    struct int_array* array = malloc(sizeof(struct int_array));
    array->len = 0;
    array->capacity = initial_capacity;
    if(initial_capacity < 1) {
        array->data = NULL;
    } else {
        array->data = malloc(initial_capacity * sizeof(int));
    }

    return array;

}

void destroy_array(struct int_array* array){
    //don't need to free NULL 
    if(array->data != NULL) {
        free(array->data); 
    }
    
    free(array);
}


void array_append(struct int_array* array, int value){
    int newlen = (*array).len + 1;
    if(newlen > array->capacity) {
        int newcapacity = max(1, array->capacity * 2);
        puts("reallocating...");
        int* newdata = malloc(sizeof(int) * newcapacity);
        if(array->data != NULL) { 
            //copy old data into new allocation
            memcpy(newdata, array->data, array->len * sizeof(int));
            //free old allocation
            free(array->data);
        }
        //assign the new allocated address in the array
        array->data = newdata;
        array->capacity = newcapacity;
    }
    array->len = newlen;

    //assign the appended value
    array->data[newlen-1] = value;
}


void array_pop(struct int_array* array){
    if(array->len < 1) {
        puts("can't pop, empty array");
    } else {
        array->len --;
    }

}
void array_sort(struct int_array* array){
    int flag;
    do {
        flag = 0;
        for(int i = 0; i < array->len-1; i++ ) {
            if(array->data[i] > array->data[i+1]){
                int temp = array->data[i+1];
                array->data[i+1] = array->data[i];
                array->data[i] = temp;

                flag = 1;
            }
        }

    }while(flag);

}

void array_clear(struct int_array* array){
    array->len = 0;
}

void array_set(struct int_array* array, int index, int value){
    if(array->len > index){
        array->data[index] = value;
    }else{
        puts("out of bounds.");
    }

}

int array_get(struct int_array* array, int index){
    if(array->len <= index){
        puts("Error, out of bounds");
        return 0;
    }
    return array->data[index];

}


void array_print(struct int_array* array){
    if(array->len < 1){
        puts("Empty array.");
    }
    for(int i = 0; i < array->len; i++){
        printf("%d ", array->data[i]);
    }
    putchar('\n');

}