//dictionary.c
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>

//Initialize dictionary object
struct dict* dictionary_init() { 
    //Initialize first dictionary entry
    struct dict *first = (struct dict*)malloc(sizeof(struct dict));
    if(first == NULL) {
        //print error to stderr if pointer null
        fprintf(stderr, "dictionary_init: Malloc Error");
        return NULL;
    }
    //Pass initial (empty) values to first object
    first->key   = "";
    first->value = "";
    first->last  = NULL;
    first->next  = NULL;

    return first;
}

struct dict* dictionary_add(struct dict *first, char *key, char *value) {
    //Error Checking
    if(first && key && value) {
        //Initialize new dictionary entry
        struct dict *new = (struct dict*)malloc(sizeof(struct dict));
        if(new == NULL) {
        fprintf(stderr, "dictionary_add: Malloc Error");
        return NULL;
        }
        //Add input value to new dictionary entry
        new->key   = key;
        new->value = value;

        int add = 1; //add variable controls if new key-value pair is added
	struct dict *t = first; //temporary pointer to first object
        //check if key exists
        while(t->next != NULL) {
            if(!strcmp(t->key, key)) {
                t->value = value;
                add = 0;
                break;   
            }
            t = t->next;
        }
        //add object to dictionary if key doesn't exits
        if(add) {
            t->next   = new;
            new->next = NULL;
            new->last = t;
        }
        else {
            //free memory if nothing added.
            free(new);
        }
        
        return first;
    }
    else {
        fprintf(stderr, "dictionary_add: insufficient arguments");
        return NULL;
    }
}

char* dictionary_value(struct dict *first, char *key) {
    //Error Checking
    if(first) {
        //create temporary pointer to first object
        struct dict *t = first;
        //loop if last object is not empty
        while(t->next != NULL) {
            if(!strcmp(t->key, key)) {
                return t->value;
            }
            t = t->next; //itterate to next object
        }
        //error if no key-pair found
        fprintf(stderr, "dictionary_value: No key-pair found");
        return NULL;
    }
    else {
        fprintf(stderr, "dictionary_value: insufficient arguments");
        return NULL;
    }
}

struct dict* dictionary_remove(struct dict *first, char *key) {
    if(first && key) {
        struct dict *t = first;
        int found = 0;
        //check for matches
        while(t->next != NULL) {
            if(!strcmp(t->key, key)) {
                found = 1;
                break;
            }
        }
        //no entry found
        if(found == 0) {
            fprintf(stderr, "dictionary_remove: No entry found");
            return NULL;
        }
        //remove entry
        if(t->next != NULL) {
            t->next->last = t->last; //set proper address in next object
        }
        if(t->last != NULL) {
            t->last->next = t->next; //set proper address in last object 
        }
        //free(t); //clear memory of object

        return first;
    }
    else {
        fprintf(stderr, "dictionary_remove: insufficient arguments");
        return NULL;
    }
}

struct dict* dictionary_destroy(struct dict *first) {
    if(first) {
        struct dict *t = first;
        //while dictionary objects exist, DESTROY
        while(t != NULL) {
            struct dict *nxt = t->next;
            free(t);
            t = nxt;
        }
        //Return null pointer
        return t; 
    }
    else {
        fprintf(stderr, "dictionary_destroy: insufficient arguments");
        return NULL;
    }

}

void dictionary_print(struct dict *first) {
    if(first) {
        struct dict *t = first;
        while(t != NULL) {
           printf("Dictionary Object %p:  Key: %s, Value: %s, Next addr: %p, Last addr: %p\n", t, t->key, t->value, t->next, t->last);
           t = t->next;
        }
    }
    else {
        fprintf(stderr, "dictionary_print: insufficient arguments");
    }
}
