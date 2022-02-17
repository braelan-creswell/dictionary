//main.c, operation of dictionary
#include <stdio.h>
#include "dictionary.h"



int main(void) {

    struct dict *data;
    data = dictionary_init();

    dictionary_print(data);

    dictionary_add(data, "one", "uno");
    dictionary_add(data, "two", "dos");
    dictionary_add(data, "three", "tres");
    dictionary_add(data, "four", "cuatro");

    dictionary_print(data);
    char *val = dictionary_value(data, "three");
    printf("Value of three is: %s\n", val);

    dictionary_remove(data, "two");

    dictionary_print(data);
    
    data = dictionary_destroy(data);

    dictionary_print(data);
    
    return 0;
}
