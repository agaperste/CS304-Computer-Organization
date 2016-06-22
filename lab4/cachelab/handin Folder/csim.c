/*
 * Yingzhu Zhang
 * loginID: yzhang21
 * cache lab
 */

#include "cachelab.h"
#include "cachelab.c"
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>
#define MAX 200

void get_opt(int argc, char **argv);
void do_malloc();
void do_free();
void load(void *addr, int size);
void modify(void *addr, int size);
void store(void *addr, int size);
int  getset(void *addr);
long gettag(void *addr);


//data structure of one set entry
struct set{
    int *v;
    clock_t *access_time;
    long *tag;
};

int hits, misses, evictions;
struct set *setptr; 
int s = 0, E = 0, b = 0;
char *file = NULL;
long clocktime = 0;

int main(int argc, char **argv){
    //read the command line arguments
    get_opt(argc, argv);
    do_malloc();

    //read the trace file
    FILE *fp = fopen(file, "r");
    if (fp == NULL){
        fprintf(stderr, "Error: cannot opten the file.\n");
        exit(0);
    }
    char opt[MAX];
    void *addr;
    int size;
    char buf[MAX];
    while (fgets(buf, MAX, fp) != NULL){
        sscanf(buf, "%s %p,%d", opt, &addr, &size);
        if (*opt == 'L'){
            load(addr, size);
        }
        else if (*opt == 'M'){
            modify(addr, size);
        }
        else if (*opt == 'S'){
            store(addr, size);
        }
    }
    do_free();
    printSummary(hits, misses, evictions);
    return 0;
}

//get the command line argument using getoptt library
void get_opt(int argc, char **argv){
    int c;

    while ((c = getopt(argc, argv, "s:E:b:t:")) != -1){
        switch (c){
            case 's':
                s = atoi(optarg);
                break;
            case 'E':
                E = atoi(optarg);
                break;
            case 'b':
                b = atoi(optarg);
                break;
            case 't':
                file = optarg;
                break;
            default:
                printf("illegal opt\n");
                exit(0);
        }
    }
}

//using malloc to initialize data structure
void do_malloc(){
    int S = (1 << s);
    if ( S <= 0){
        fprintf(stderr, "S should not be nonpositive\n");
        exit(0);
    }
    setptr = (struct set*)malloc(sizeof(struct set) * S);

    for (int ind = 0; ind < S; ++ind){
        setptr[ind].v = (int *)malloc(sizeof(int) * E);
        setptr[ind].access_time = (clock_t *)malloc(sizeof(clock_t) * E);
        setptr[ind].tag = (long *)malloc(sizeof(long) * E);

        for(int Eind = 0 ; Eind < E; Eind++){
            setptr[ind].v[Eind] = 0;
            setptr[ind].access_time[Eind] = 0;
            setptr[ind].tag[Eind] = 0;
        }
    }
}

//explicitly return the space back to heap to free malloc
void do_free(){
    int S = (1 << s);

    setptr = (struct set*)malloc(sizeof(struct set) * S);
    for (int ind = 0; ind < S; ++ind){
        free(setptr[ind].v);
        free(setptr[ind].access_time);
        free(setptr[ind].tag);
    }

    free(setptr);
}

// do a LOAD opteration
void load(void *addr, int size){
    int setnum = getset(addr);
    struct set *this_set = &setptr[setnum];

    int index;
    int full = 1;
    int empty_item = 0; //if not full, keep track of the empty item
    int last_item = 0; //if full, keep track of the evict item
    int last_time = this_set->access_time[0];

    for (index = 0; index < E; index++){
        //find, update the access time
        if (this_set->v[index] == 1 && gettag(addr) == this_set->tag[index]){
            this_set->access_time[index] = ++clocktime;
            break;
        }
        //not valid, then this entry is considered empty, cache is not full
        else if (this_set->v[index] == 0){
            full = 0;
            empty_item = index;
        }
        //valid but tag not equal
        else{
            //keep track of the LRU item, ready for eviction
            if (this_set->access_time[index] < last_time){
                last_item = index;
                last_time = this_set->access_time[index];
            }
        }
    }

    //if miss
    if (index == E) {
        misses++;
        //if eviction
        if (full) {
            this_set->tag[last_item] = gettag(addr);
            this_set->access_time[last_item] = ++clocktime;
            evictions++;
        }
        else{
            this_set->v[empty_item] = 1;
            this_set->tag[empty_item] = gettag(addr);
            this_set->access_time[empty_item] = ++clocktime;
        }
    }
    //if hit
    else {
        hits++;
    }

}

//do a STORE operation
//store only load when miss, while modify always load first then store
void store(void *addr, int size)
{
    int setnum = getset(addr);
    struct set *this_set = &setptr[setnum];

    int index;
    for (index = 0; index < E; ++index){
        //find
        if (this_set->v[index] == 1 && gettag(addr) == this_set->tag[index]) {
            this_set->access_time[index] = ++clocktime;
            break;
        }
    }

    //store miss
    if (index == E){
        //if miss, then load
        load(addr, size); 
    }
    //store hit
    else{
        hits++;
    }
}

//do a MODIFY opteration
void modify(void *addr, int size){
    load(addr, size);
    store(addr, size);
}

//get the tag number from the address
long gettag(void *addr){
    return (long)((long)addr >> (s + b));
}
//get the set number from the address
int getset(void *addr){
    return (int)( ((long)addr >> b) & ((1 << s) - 1) );
}



