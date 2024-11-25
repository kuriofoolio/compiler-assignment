#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"


ASTNode *createBinaryNode(const char *type, ASTNode *left, ASTNode *right) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->nodeType = strdup(type);
    node->left = left;
    node->right = right;
    return node;
}

ASTNode *createTerminalNode(const char *type, int value) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->nodeType = strdup(type);
    node->num = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

ASTNode *createIdentifierNode(const char *id) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->nodeType = strdup("identifier");
    node->id = strdup(id);
    node->left = NULL;
    node->right = NULL;
    return node;
}

ASTNode *createIfElseNode(ASTNode *condition, ASTNode *thenBranch, ASTNode *elseBranch) {
    ASTNode *node = createBinaryNode("if_else", condition, thenBranch);
    node->right = elseBranch; // Link the else branch
    return node;
}


void printAST(ASTNode *node, int depth) {
    if (node == NULL) return;

    for (int i = 0; i < depth; i++) {
        printf("\t");
    }

    printf("%s", node->nodeType);

    if (strcmp(node->nodeType, "number") == 0) {
        printf(":%d\n", node->num);
    } else if (strcmp(node->nodeType, "identifier") == 0) {
        printf(":%s\n", node->id);
    } else {
        printf("\n");
        printAST(node->left, depth + 1);
        printAST(node->right, depth + 1);
    }
}








