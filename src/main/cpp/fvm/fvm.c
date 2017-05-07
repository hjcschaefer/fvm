#include <fvm/fvm.h>

#include <stdio.h>
#include <stdlib.h>

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

word* compile(int n, word* words) {
    int i;
    for(i=0; i<n; i++) {
        *ip = words[i];
        ip++;
    }
    return ip;
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

void fvm_reset() {
    ip = mem;
}


void fvm_inner(word* ip_end) {
    do {
        printf("start inner\n");
        *w = *ip;
        ip++;
        printf("call now\n");
        (*w)();
    } while (ip!=ip_end);
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

