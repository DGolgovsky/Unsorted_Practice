#include <stdio.h>

typedef struct node_t_ {
    int value;
    struct node_t_ *next;
} node_t;

void traverse(
        int  (*is_end)(void *),
        void (*shift)(void *),
        void (*action)(
                void *src,
                void *state),
        void *src,
        void *state
) {
    while (!is_end(src)) {
        action(src, state);
        shift(src);
    }
}

typedef struct list_t_ {
    node_t *curr;
} list_t;

int lst_end(void *p) {
    list_t *t = (list_t *) p;
    return NULL == t->curr;
}

void lst_shift(void *p) {
    list_t *t = (list_t *) p;
    t->curr = t->curr->next;
}

void lst_sum(void *p, void *q) {
    list_t *t = (list_t *) p;
    int *s = (int *) q;
    *s += t->curr->value;
}

typedef struct arr_t_ {
    int *data;
    size_t len;
    size_t idx;
} arr_t;

int arr_end(void *p) {
    arr_t *t = (arr_t *) p;
    return t->idx == t->len;
}

void arr_shift(void *p) {
    arr_t *t = (arr_t *) p;
    ++t->idx;
}

void arr_sum(void *p, void *q) {
    arr_t *t = (arr_t *) p;
    int *s = (int *) q;
    *s += t->data[t->idx];
}

typedef struct even_t {
    void *src;

    int (*is_end)(void *);

    void (*shift)(void *);

    void (*act)(void *, void *);
} even_t;

int even_end(void *p) {
    even_t *t = (even_t *) p;
    return t->is_end(t->src);
}

void even_shift(void *p) {
    even_t *t = (even_t *) p;
    t->shift(t->src);
    if (!t->is_end(t->src))
        t->shift(t->src);
}

void even_act(void *p, void *q) {
    even_t *t = (even_t *) p;
    t->act(t->src, q);
}

int main(int argc, char **argv) {
    node_t c = {30, NULL};
    node_t b = {20, &c};
    node_t a = {10, &b};

    list_t list = {&a};
    int s1 = 0;

    traverse(
            lst_end,
            lst_shift,
            lst_sum,
            &list,
            &s1);

    printf("s1 = %d\n", s1);

    int m[4] = {3, 4, 5, 6};

    arr_t arr = {
            m, /* data */
            4, /* len */
            0  /* idx */
    };
    int s2 = 0;

    traverse(
            arr_end,
            arr_shift,
            arr_sum,
            &arr,
            &s2);

    printf("s2 = %d\n", s2);

    even_t even = {
            &arr,
            arr_end,
            arr_shift,
            arr_sum
    };
    int s3 = 0;

    traverse(
            even_end,
            even_shift,
            even_act,
            &even,
            &s3);

    printf("s3 = %d\n", s3);

    return 0;
}
