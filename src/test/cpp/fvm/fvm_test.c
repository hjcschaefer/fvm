#include <fvm/fvm.h>

#include <assert.h>



void testlit() {
    fvm_init();

    word tst[2] = {&lit, (word)123};
    word* ip_end = compile(2, tst);
    fvm_reset();
    fvm_inner(ip_end);
    assert(123 == pop());
    assert(stptr==stack);
    assert(ip==ip_end);
}


//void testplus() {


int main()  {
    testlit();

    /*
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
    */
    return(0);
}

