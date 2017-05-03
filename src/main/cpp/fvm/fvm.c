#include <fvm/fvm.h>

#include <stdio.h>
#include <stdlib.h>
/*
 *
#include <string.h>
 */

long *stack;
long* stptr;

// array of function pointers void*
word* mem;
word* ip;
word* w;

long pop() {
    stptr--;
    return *stptr;
}

void push(long a) {
    *stptr = a;
    stptr++;
}

void plus() {
    printf("plus called\n");
    long tmp = pop();
    long tmp2 = pop();
    push(tmp+tmp2);
}

void lit() {
    printf("lit called\n");
    push((long)(*ip));
    ++ip;
}

void addlit(long a) {
    *ip = &lit;
    ip++;
    *ip = (word)a;
    ip++;
}

/*
void exit() {
    free(mem);
    free(stack);
}
*/

void fvm_init() {
    stack = (long*)malloc(100*sizeof(long));
    mem = (word*)malloc(1000*sizeof(word));
    w = (word*)malloc(sizeof(word));
    stptr = stack;
    ip = mem;
}



/*
int main()  {
    stack = (long*)malloc(100*sizeof(long));
    mem = (word*)malloc(1000*sizeof(word));
    w = (word*)malloc(sizeof(word));
    stptr = stack;
    ip = mem;

    addlit(100);
    addlit(200);
    *ip = &plus;
    ip++;
    void* ip_end = ip;

    ip = mem;
    
    // inner interpreter
    do {
        printf("start inner\n");
        *w = *ip;
        ip++;
        printf("call now\n");
        (*w)();
    } while (ip!=ip_end);

    printf("---->%ld\n", pop());
}
*/

