//Dictionary.h header file

#ifndef DICTIONARY_H_ 							//protect against double define
#define DICTIONARY_H_

struct dict {
    char *key;
    char *value;

    struct dict *last;                                                 //pointer to last and next dictionary object
    struct dict *next;
}

struct *dict dictionary_init(); 					//Initialize dictionary object and return ptr to first key-value pair

struct *dict dictionary_add(struct dict *first, char *key, char *value);//Add new key-value pair to dictionary, returns ptr

char* dictionary_value(struct dict *first, char *key); 		//Return value from given key

struct *dict dictionary_remove(struct dict *first, char *key); 		//Remove value and key from given key

struct *dict dictionary_destroy(struct dict *first);			//Deallocate memory held by dictionary object

void dictionary_print(struct dict *first); 				//print dictionary with linked list pointers

#endif
