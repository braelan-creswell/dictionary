//dictionary.c
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>

//Initialize dictionary object
struct *dict dictionary_init() { 
    //Initialize first dictionary entry
    struct dict *first = (struct dict*)malloc(sizeof(struct dict));
    if(first == NULL) {
        fprintf(stderr, "Malloc Error");
        return NULL;
    }
    //Pass initial (empty) values to first object
    first->key   = '';
    first->value = '';
    first->last  = NULL;
    first->next  = NULL;

    return first;
}

struct *dict dictionary_add(struct dict *first, char *key, char *value) {

}

struct *dict dictionary_value(struct dict *first,, char *key) {

}

struct *dict dictionary_remove(struct dict *first,, char *key) {

}

struct *dict dictionary_destroy(struct dict *first,) {

}

void dictionary_print(struct dict *first,) {

}
