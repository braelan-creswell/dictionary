#ifndef DICTIONARY_H_ 						//protect against double define
#define DICTIONARY_H_

char* dictionary_init(); 					//Initialize dictionary object and return ptr to first key-value pair

char* dictionary_add(char *dictobj, char *key, char *value); 	//Add new key-value pair to dictionary, returns ptr

char* dictionary_value(char *dictobj, char *key); 		//Return value from given key

char* dictionary_remove(char *dictobj, char *key); 		//Remove value and key from given key

char* dictionary_destroy(char *dictobj);			//Deallocate memory held by dictionary object

void dictionary_print(char *dictobj); 				//print dictionary with linked list pointers

#endif
