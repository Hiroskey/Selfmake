#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
    if (argc != 2){
        fprintf(stderr, "argument error: the number of arguments are not correct\n");
        return 1;
    }

    char *p = argv[1];

    printf(".intel_syntax noprefix\n");
    printf(".global main\n");
    printf("main:\n");
    printf("    mov rax, %ld\n", strtol(p, &p, 10));

    while (*p){

        if(*p == '+'){
            p++;
            printf("    add rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        if(*p == '-'){
            p++;
            printf("    sub rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        fprintf(stderr, "unexpected words: '%c'\n", *p);
        return 1;
    }

    printf("    ret\n\n");
    return 0;
}
