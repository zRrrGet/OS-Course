#include <stdio.h>
#include <stdlib.h>

struct node {
        struct node *p;
        int v;
};

struct linked_list {
        struct node *head;
};

void print_list(struct linked_list *l) {
        struct node *c = l->head;
        for (; c; c = c->p)
                printf("%d ", c->v);
        printf("\n");
}

void insert_node(struct linked_list *l, struct node *n) {
        struct node *c = l->head;
        for (; c && c->p; c = c->p);
        if (c)
            c->p = n;
        else
            l->head = n;
}

void delete_node(struct linked_list *l, int ind) {
        struct node *c = l->head;
        for (int i = 0; c; c = c->p)
                if (i+1 == ind)
                {
                          c->p = c->p->p;
                          break;
                }
}

int main() {
        struct linked_list *l = malloc(sizeof(struct linked_list*));
        struct node* n1 = malloc(sizeof(struct node*));
        n1->v = 1;
        struct node* n2 = malloc(sizeof(struct node*));
        n2->v = 2;
        struct node* n3 = malloc(sizeof(struct node*));
        n3->v = 3;
        n3->p = 0;
        insert_node(l, n1);
        insert_node(l, n2);
        insert_node(l, n3);
        print_list(l);
        delete_node(l, 1);
        print_list(l);
}
