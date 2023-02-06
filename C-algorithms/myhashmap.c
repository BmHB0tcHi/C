#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLESIZE 30
#define MAX_NAME_SIZE 20


typedef struct {
    int age;
    const char *name;
} entry;

entry *hastable[TABLESIZE];


unsigned int hash(const char * value){

    unsigned int key = 0;
    int i = 0;
    for (i=0; i<strlen(value); i++){
        key = key * 22 + value[i];
    }
    key = key % TABLESIZE;
    return key;

}


void init_hashtable(){
    int i = 0;
    for (i=0; i< TABLESIZE; i++){
        hastable[i] = NULL;
    }
}

int add_entry(entry * p) {
    if (p == NULL)
    return 1;

    unsigned int key = hash(p->name);

    if (hastable[key] == NULL){
        // Free slot
        hastable[key] = p;
        return 0;
    }
    else{
        return 1;
    }
    
}

void print_hashtable(){
    int i = 0;
    for (i = 0; i<TABLESIZE; i++){
        if (hastable[i] == NULL){
            printf ("\t%d ----\n", i);
        }
        else{
            printf ("\t%d %s \n", i, hastable[i]->name);
        }
    }

}

entry * find_entry(const char * name){
    unsigned int key = hash(name);
    if (hastable[key] == NULL){
        return NULL;
    }
    else{
        return hastable[key];
    }
}

int main(void){

    init_hashtable();
    
    entry john = {
        .name = "John",
        .age = 22
    };

    entry geo = {
        .name = "George",
        .age = 42
    };
    entry moh = {
        .name = "Mohammad",
        .age = 37
    };

    //print_hashtable();
    int sucess  =  add_entry(&john);
    if(sucess!= 0){
        printf ("Failed to add enrty [Location taken]\n");
        return 1;
    }
    
    sucess  =  add_entry(&moh);
    if(sucess!= 0){
        printf ("Failed to add enrty [Location taken]\n");
        return 1;
    }
    
    sucess  =  add_entry(&geo);
    if(sucess!= 0){
        printf ("Failed to add enrty [Location taken]\n");
        return 1;
    }
    print_hashtable();

    //moh = find_entry(&moh.name);
    entry * mohammad = find_entry("moh");
    if (mohammad == NULL){
        printf("Not Found!\n");
    } else {
        printf("Entry Found!\n");
    }
    
    return 0;
}