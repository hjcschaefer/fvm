
typedef void (*word)(void);

extern long *stack;
extern long* stptr;
extern word* mem;
extern word* ip;
extern word* w;

long pop();
void lit();
word* compile(int n, word* words);

void fvm_init();
void fvm_reset();

void fvm_inner(word* ip_end);

