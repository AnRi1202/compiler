#include <stdio.h>
#include "9cc.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        error("引数の個数が正しくありません");
        return 1;
    }

    user_input = argv[1];
    token = tokenize(user_input);
    Node *node = expr();

    printf(".intel_syntax noprefix\n.globl main\nmain:\n");
    gen(node);
    printf("  pop rax\n  ret\n");
    return 0;
}
