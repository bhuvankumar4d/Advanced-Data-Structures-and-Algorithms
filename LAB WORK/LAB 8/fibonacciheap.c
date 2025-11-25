#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int degree;
    struct node* parent;
    struct node* child;
    struct node* left;
    struct node* right;
    int mark;
    int c;
};

struct node* mini = NULL;
int no_of_nodes = 0;

void insertion(int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = val;
    new_node->degree = 0;
    new_node->mark = 0;
    new_node->c = 0;
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->left = new_node;
    new_node->right = new_node;
    if (mini != NULL) {
        (mini->left)->right = new_node;
        new_node->right = mini;
        new_node->left = mini->left;
        mini->left = new_node;
        if (new_node->key < mini->key)
            mini = new_node;
    } else {
        mini = new_node;
    }
    no_of_nodes++;
}

void fib_heap_link(struct node* y, struct node* x) {
    (y->left)->right = y->right;
    (y->right)->left = y->left;
    if (x->right == x)
        mini = x;
    y->left = y;
    y->right = y;
    y->parent = x;
    if (x->child == NULL)
        x->child = y;
    y->right = x->child;
    y->left = (x->child)->left;
    ((x->child)->left)->right = y;
    (x->child)->left = y;
    if (y->key < (x->child)->key)
        x->child = y;
    x->degree++;
}

void consolidation() {
    int D, i, d;
    struct node* x;
    struct node* y;
    struct node* temp;
    struct node** A; 
    float f = (log(no_of_nodes)) / (log(1.618));
    D = (int)f;
    A = (struct node**)calloc(D + 5, sizeof(struct node*));
    
    struct node* start = mini;
    struct node* ptr = start;
    struct node* next_node;
    
    do {
        next_node = ptr->right;
        x = ptr;
        d = x->degree;
        while (A[d] != NULL) {
            y = A[d];
            if (x->key > y->key) {
                temp = x;
                x = y;
                y = temp;
            }
            if (y == start) start = start->right;
            if (y == next_node) next_node = next_node->right;
            fib_heap_link(y, x);
            if (x->right == x) mini = x;
            A[d] = NULL;
            d++;
        }
        A[d] = x;
        ptr = next_node;
    } while (ptr != start && ptr != mini); 

    mini = NULL;
    for (i = 0; i <= D + 4; i++) {
        if (A[i] != NULL) {
            if (mini == NULL) {
                mini = A[i];
                mini->left = mini;
                mini->right = mini;
            } else {
                (mini->left)->right = A[i];
                A[i]->right = mini;
                A[i]->left = mini->left;
                mini->left = A[i];
                if (A[i]->key < mini->key)
                    mini = A[i];
            }
        }
    }
    free(A);
}

void extract_min() {
    if (mini == NULL) {
        printf("Heap is empty\n");
        return;
    }
    struct node* temp = mini;
    struct node* pntr;
    struct node* ptr = temp;
    struct node* x = NULL;
    if (temp->child != NULL) {
        x = temp->child;
        do {
            pntr = x->right;
            (mini->left)->right = x;
            x->right = mini;
            x->left = mini->left;
            mini->left = x;
            if (x->key < mini->key)
                mini = x;
            x->parent = NULL;
            x = pntr;
        } while (pntr != temp->child);
    }
    (temp->left)->right = temp->right;
    (temp->right)->left = temp->left;
    mini = temp->right;
    if (temp == temp->right && temp->child == NULL)
        mini = NULL;
    else {
        mini = temp->right;
        consolidation();
    }
    no_of_nodes--;
    free(temp);
}

void cut(struct node* found, struct node* temp) {
    if (found == found->right)
        temp->child = NULL;
    (found->left)->right = found->right;
    (found->right)->left = found->left;
    if (found == temp->child)
        temp->child = found->right;
    temp->degree = temp->degree - 1;
    found->right = found;
    found->left = found;
    (mini->left)->right = found;
    found->right = mini;
    found->left = mini->left;
    mini->left = found;
    found->parent = NULL;
    found->mark = 0;
}

void cascading_cut(struct node* temp) {
    struct node* ptr = temp->parent;
    if (ptr != NULL) {
        if (temp->mark == 0) {
            temp->mark = 1;
        } else {
            cut(temp, ptr);
            cascading_cut(ptr);
        }
    }
}

struct node* find_node(struct node* mini, int key) {
    struct node* found = NULL;
    struct node* f = mini;
    f->c = 1;
    struct node* ptr = f;
    if (ptr->key == key) {
        ptr->c = 0;
        return ptr;
    }
    if (ptr->child != NULL)
        if ((found = find_node(ptr->child, key)) != NULL) {
            ptr->c = 0;
            return found;
        }
    if ((ptr->right)->c != 1)
        if ((found = find_node(ptr->right, key)) != NULL) {
            ptr->c = 0;
            return found;
        }
    ptr->c = 0;
    return found;
}

void decrease_key(struct node* found, int val) {
    if (mini == NULL) {
        printf("Heap is empty\n");
        return;
    }
    if (found == NULL) {
        printf("Node not found\n");
        return;
    }
    found->key = val;
    struct node* temp = found->parent;
    if (temp != NULL && found->key < temp->key) {
        cut(found, temp);
        cascading_cut(temp);
    }
    if (found->key < mini->key)
        mini = found;
}

void fib_node_delete(int val) {
    if (mini == NULL) {
        printf("Heap is empty\n");
        return;
    }
    struct node* found = find_node(mini, val);
    if (found == NULL) {
        printf("Key not found\n");
        return;
    }
    decrease_key(found, -5000);
    extract_min();
    printf("Key Deleted\n");
}

void display(struct node* mini) {
    struct node* ptr = mini;
    if (ptr == NULL) {
        printf("Heap is empty\n");
        return;
    }
    printf("Root Nodes: \n");
    do {
        printf("%d ", ptr->key);
        ptr = ptr->right;
        if (ptr != mini) {
            printf("--> ");
        }
    } while (ptr != mini && ptr->right != NULL);
    printf("\n");
}

int main() {
    int choice, val, old_val;
    while (1) {
        printf("\n--- Fibonacci Heap Menu ---\n");
        printf("1. Insert\n");
        printf("2. Find Min\n");
        printf("3. Extract Min\n");
        printf("4. Decrease Key\n");
        printf("5. Delete Key\n");
        printf("6. Display Roots\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insertion(val);
            printf("Inserted %d\n", val);
            break;
        case 2:
            if (mini != NULL)
                printf("Min value is %d\n", mini->key);
            else
                printf("Heap is empty\n");
            break;
        case 3:
            extract_min();
            printf("Min extracted\n");
            break;
        case 4:
            printf("Enter old value: ");
            scanf("%d", &old_val);
            printf("Enter new value: ");
            scanf("%d", &val);
            decrease_key(find_node(mini, old_val), val);
            printf("Key decreased\n");
            break;
        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            fib_node_delete(val);
            break;
        case 6:
            display(mini);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}