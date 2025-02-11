#ifndef NINE_CC_H
#define NINE_CC_H

#include <stdbool.h>

// トークンの種類
typedef enum {
    TK_RESERVED,
    TK_NUM,
    TK_EOF,
} TokenKind;

typedef struct Token Token;

struct Token {
    TokenKind kind;
    Token *next;
    int val;
    char *str;
    int len;
};

typedef enum {
    ND_ADD, ND_SUB, ND_MUL, ND_DIV, ND_NUM,
    ND_EQ, ND_NE, ND_LT, ND_LE
} NodeKind;

typedef struct Node Node;

struct Node {
    NodeKind kind;
    Node *lhs;
    Node *rhs;
    int val;
};

// グローバル変数
extern Token *token;
extern char *user_input;

// 関数プロトタイプ
void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);
bool consume(char *op);
void expect(char *op);
int expect_number();
bool at_eof();
Token *tokenize(char *p);
Node *expr();
Node *equality();
Node *relational();
Node *add();
Node *mul();
Node *unary();
Node *primary();
void gen(Node *node);

#endif // NINE_CC_H
