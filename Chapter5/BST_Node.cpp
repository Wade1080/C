//
// Created by Wade1080 on 2023/2/9.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode, *BSTree;

BSTree createNode(int key) {
    BSTree node = (BSTree) malloc(sizeof(BSTNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

BSTree insert(BSTree root, int key) {
    if (root == NULL) return createNode(key);
    BSTree cur = root;
    BSTree pre = NULL;//父结点
    while (cur != NULL) {
        pre = cur;
        if (key < cur->key) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    if (key < pre->key) {
        pre->left = createNode(key);
    } else {
        pre->right = createNode(key);
    }
    return root;
}

int main() {
    BSTree root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 7);
    return 0;
}
