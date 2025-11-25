#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* newNode(int k){
    Node* n = malloc(sizeof(Node));
    n->key = k;
    n->left = n->right = NULL;
    return n;
}

Node* rightRotate(Node* x){
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node* splay(Node* root, int key){
    if (!root || root->key == key) return root;
    if (key < root->key){
        if (!root->left) return root;
        if (key < root->left->key){
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (key > root->left->key){
            root->left->right = splay(root->left->right, key);
            if (root->left->right) root->left = leftRotate(root->left);
        }
        return root->left ? rightRotate(root) : root;
    } else {
        if (!root->right) return root;
        if (key > root->right->key){
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        } else if (key < root->right->key){
            root->right->left = splay(root->right->left, key);
            if (root->right->left) root->right = rightRotate(root->right);
        }
        return root->right ? leftRotate(root) : root;
    }
}

Node* findMax(Node* root){
    while (root->right) root = root->right;
    return root;
}

Node* insert(Node* root, int key){
    if (!root) return newNode(key);
    root = splay(root, key);
    if (root->key == key) return root;
    Node* n = newNode(key);
    if (key < root->key){
        n->right = root;
        n->left = root->left;
        root->left = NULL;
    } else {
        n->left = root;
        n->right = root->right;
        root->right = NULL;
    }
    return n;
}

Node* deleteNode(Node* root, int key){
    if (!root) return NULL;
    root = splay(root, key);
    if (root->key != key) return root;
    Node* l = root->left;
    Node* r = root->right;
    free(root);
    if (!l) return r;
    l = splay(l, findMax(l)->key);
    l->right = r;
    return l;
}

Node* search(Node* root, int key){
    return splay(root, key);
}

void inorder(Node* root){
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main(){
    Node* root = NULL;
    int ch, x;
    while (1){
        printf("\n1 Insert\n2 Delete\n3 Search\n4 Inorder\n5 Exit\nEnter: ");
        scanf("%d", &ch);
        if (ch == 1){
            scanf("%d", &x);
            root = insert(root, x);
        } else if (ch == 2){
            scanf("%d", &x);
            root = deleteNode(root, x);
        } else if (ch == 3){
            scanf("%d", &x);
            root = search(root, x);
            if (root && root->key == x) printf("Found\n"); 
            else printf("Not Found\n");
        } else if (ch == 4){
            inorder(root);
            printf("\n");
        } else if (ch == 5){
            break;
        }
    }
    return 0;
}
