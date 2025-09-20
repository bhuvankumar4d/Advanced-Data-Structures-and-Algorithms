#include <stdio.h>
#include <stdlib.h>

#define T 3  

typedef struct BTreeNode {
    int keys[2*T-1];
    struct BTreeNode *children[2*T];
    int n;
    int leaf;
} BTreeNode;

BTreeNode* createNode(int leaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    for(int i=0;i<2*T;i++) 
        node->children[i]=NULL;
    return node;
}

void traverse(BTreeNode* root) {
    int i;
    for(i=0;i<root->n;i++) {
        if(!root->leaf) 
            traverse(root->children[i]);
        printf("%d ", root->keys[i]);
    }
    if(!root->leaf) 
        traverse(root->children[i]);
}

BTreeNode* search(BTreeNode* root, int k) {
    int i=0;
    while(i<root->n && k>root->keys[i]) i++;
    if(i<root->n && root->keys[i]==k) return root;
    if(root->leaf) return NULL;
    return search(root->children[i], k);
}

void splitChild(BTreeNode* x, int i, BTreeNode* y) {
    BTreeNode* z=createNode(y->leaf);
    z->n=T-1;
    for(int j=0;j<T-1;j++) z->keys[j]=y->keys[j+T];
    if(!y->leaf) for(int j=0;j<T;j++) z->children[j]=y->children[j+T];
    y->n=T-1;
    for(int j=x->n;j>=i+1;j--) x->children[j+1]=x->children[j];
    x->children[i+1]=z;
    for(int j=x->n-1;j>=i;j--) x->keys[j+1]=x->keys[j];
    x->keys[i]=y->keys[T-1];
    x->n++;
}

void insertNonFull(BTreeNode* x, int k) {
    int i=x->n-1;
    if(x->leaf) {
        while(i>=0 && k<x->keys[i]) {
            x->keys[i+1]=x->keys[i];
            i--;
        }
        x->keys[i+1]=k;
        x->n++;
    } else {
        while(i>=0 && k<x->keys[i]) i--;
        i++;
        if(x->children[i]->n==2*T-1) {
            splitChild(x,i,x->children[i]);
            if(k>x->keys[i]) i++;
        }
        insertNonFull(x->children[i],k);
    }
}

BTreeNode* insert(BTreeNode* root, int k) {
    if(root->n==2*T-1) {
        BTreeNode* s=createNode(0);
        s->children[0]=root;
        splitChild(s,0,root);
        int i=0;
        if(s->keys[0]<k) i++;
        insertNonFull(s->children[i],k);
        return s;
    } else {
        insertNonFull(root,k);
        return root;
    }
}

int getPred(BTreeNode* x) {
    BTreeNode* cur=x;
    while(!cur->leaf) cur=cur->children[cur->n];
    return cur->keys[cur->n-1];
}

int getSucc(BTreeNode* x) {
    BTreeNode* cur=x;
    while(!cur->leaf) cur=cur->children[0];
    return cur->keys[0];
}

void merge(BTreeNode* x,int idx) {
    BTreeNode* c=x->children[idx];
    BTreeNode* s=x->children[idx+1];
    c->keys[T-1]=x->keys[idx];
    for(int i=0;i<s->n;i++) c->keys[i+T]=s->keys[i];
    if(!c->leaf) for(int i=0;i<=s->n;i++) c->children[i+T]=s->children[i];
    for(int i=idx+1;i<x->n;i++) x->keys[i-1]=x->keys[i];
    for(int i=idx+2;i<=x->n;i++) x->children[i-1]=x->children[i];
    c->n+=s->n+1;
    x->n--;
    free(s);
}

void fill(BTreeNode* x,int idx);

void removeFromNode(BTreeNode* x,int k) {
    int idx=0;
    while(idx<x->n && x->keys[idx]<k) idx++;
    if(idx<x->n && x->keys[idx]==k) {
        if(x->leaf) {
            for(int i=idx+1;i<x->n;i++) x->keys[i-1]=x->keys[i];
            x->n--;
        } else {
            if(x->children[idx]->n>=T) {
                int pred=getPred(x->children[idx]);
                x->keys[idx]=pred;
                removeFromNode(x->children[idx],pred);
            } else if(x->children[idx+1]->n>=T) {
                int succ=getSucc(x->children[idx+1]);
                x->keys[idx]=succ;
                removeFromNode(x->children[idx+1],succ);
            } else {
                merge(x,idx);
                removeFromNode(x->children[idx],k);
            }
        }
    } else {
        if(x->leaf) return;
        int flag=(idx==x->n);
        if(x->children[idx]->n<T) fill(x,idx);
        if(flag && idx>x->n) removeFromNode(x->children[idx-1],k);
        else removeFromNode(x->children[idx],k);
    }
}

void borrowFromPrev(BTreeNode* x,int idx) {
    BTreeNode* c=x->children[idx];
    BTreeNode* s=x->children[idx-1];
    for(int i=c->n-1;i>=0;i--) c->keys[i+1]=c->keys[i];
    if(!c->leaf) for(int i=c->n;i>=0;i--) c->children[i+1]=c->children[i];
    c->keys[0]=x->keys[idx-1];
    if(!c->leaf) c->children[0]=s->children[s->n];
    x->keys[idx-1]=s->keys[s->n-1];
    c->n+=1;
    s->n-=1;
}

void borrowFromNext(BTreeNode* x,int idx) {
    BTreeNode* c=x->children[idx];
    BTreeNode* s=x->children[idx+1];
    c->keys[c->n]=x->keys[idx];
    if(!c->leaf) c->children[c->n+1]=s->children[0];
    x->keys[idx]=s->keys[0];
    for(int i=1;i<s->n;i++) s->keys[i-1]=s->keys[i];
    if(!s->leaf) for(int i=1;i<=s->n;i++) s->children[i-1]=s->children[i];
    c->n+=1;
    s->n-=1;
}

void fill(BTreeNode* x,int idx) {
    if(idx!=0 && x->children[idx-1]->n>=T) borrowFromPrev(x,idx);
    else if(idx!=x->n && x->children[idx+1]->n>=T) borrowFromNext(x,idx);
    else {
        if(idx!=x->n) merge(x,idx);
        else merge(x,idx-1);
    }
}

BTreeNode* deleteKey(BTreeNode* root,int k) {
    if(!root) return root;
    removeFromNode(root,k);
    if(root->n==0) {
        BTreeNode* tmp=root;
        if(root->leaf) root=NULL;
        else root=root->children[0];
        free(tmp);
    }
    return root;
}

int main() {
    BTreeNode* root=createNode(1);
    int choice,val;
    while(1) {
        printf("\n1.Insert\n2.Delete\n3.Traverse\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d",&val); root=insert(root,val); break;
            case 2: printf("Enter value: "); scanf("%d",&val); root=deleteKey(root,val); break;
            case 3: traverse(root); printf("\n"); break;
            case 4: exit(0);
        }
    }
}