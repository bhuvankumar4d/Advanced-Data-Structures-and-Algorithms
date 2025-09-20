#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup(const char *s){
    size_t n = strlen(s) + 1;
    char *d = malloc(n);
    if(!d) return NULL;
    memcpy(d, s, n);
    return d;
}

typedef struct {
    char *name;
    int *nbr;
    int ncount;
    int ncap;
} Node;

int find_or_add(Node **nodes, int *n_nodes, const char *name){
    for(int i=0;i<*n_nodes;i++){
        if(strcmp((*nodes)[i].name, name)==0) return i;
    }
    int idx = *n_nodes;
    *nodes = realloc(*nodes, sizeof(Node)*(idx+1));
    (*nodes)[idx].name = my_strdup(name);
    (*nodes)[idx].nbr = NULL;
    (*nodes)[idx].ncount = 0;
    (*nodes)[idx].ncap = 0;
    (*n_nodes)++;
    return idx;
}

void add_edge(Node *nodes, int u, int v){
    if(nodes[u].ncount == nodes[u].ncap){
        nodes[u].ncap = nodes[u].ncap? nodes[u].ncap*2 : 4;
        nodes[u].nbr = realloc(nodes[u].nbr, sizeof(int)*nodes[u].ncap);
    }
    nodes[u].nbr[nodes[u].ncount++] = v;
}

int main(int argc, char **argv){
    char buf[4096];
    Node *nodes = NULL;
    int n_nodes = 0;
    FILE *in = stdin;
    if(argc>1){
        in = fopen(argv[1],"r");
        if(!in){ perror("fopen"); return 1; }
    }
    while(fgets(buf, sizeof(buf), in)){
        char *p = buf;
        while(*p==' '||*p=='\t') p++;
        if(*p=='\n' || *p=='\0') continue;
        char *tok = strtok(p, " \t\r\n");
        if(!tok) continue;
        char *src = tok;
        char *interaction = strtok(NULL, " \t\r\n");
        if(!interaction) continue;
        int si = find_or_add(&nodes, &n_nodes, src);
        char *t;
        while((t = strtok(NULL, " \t\r\n"))){
            int ti = find_or_add(&nodes, &n_nodes, t);
            add_edge(nodes, si, ti);
        }
    }
    if(in!=stdin) fclose(in);
    for(int i=0;i<n_nodes;i++){
        printf("%s:", nodes[i].name);
        for(int j=0;j<nodes[i].ncount;j++){
            printf(" %s", nodes[nodes[i].nbr[j]].name);
            if(j+1<nodes[i].ncount) printf(",");
        }
        printf("\n");
    }
    for(int i=0;i<n_nodes;i++){
        free(nodes[i].name);
        free(nodes[i].nbr);
    }
    free(nodes);
    return 0;
}