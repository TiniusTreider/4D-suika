#include "error.h"
#include "memory.h"
#include "vector.h"

#include <stdlib.h>
#include <string.h>

struct ball_vec {
        struct ball *data;
        size_t size;
        size_t fill;
};

#define START_SIZE 4
#define GROW_SIZE 4

struct ball_vec *init_vec(void)
{
        struct ball_vec *vec = smalloc(sizeof(struct ball_vec));
        vec->data = smalloc(START_SIZE * sizeof(struct ball));
        vec->size = START_SIZE;
        vec->fill = 0;

        return vec;
}

void clean_vec(struct ball_vec *vec)
{
        free(vec->data);
        free(vec);
}

size_t vec_size(struct ball_vec *vec)
{
        return vec->fill;
}

struct ball *index_vec(struct ball_vec *vec, size_t i)
{
        erroriff(
                i >= vec->fill,
                "tried to index %d in vector of size %d",
                i, vec->fill
        );

        return vec->data + i;
}

static inline void grow_vec(struct ball_vec *vec)
{
        if (vec->fill >= vec->size) {
                vec->size += GROW_SIZE;
                vec->data = srealloc(vec, vec->size);
        }
}

void vec_add(struct ball_vec *vec, struct ball ball)
{
        grow_vec(vec);

        vec->fill++;
        vec->data[vec->fill] = ball;
}

static inline void shrink_vec(struct ball_vec *vec)
{
        if (vec->size - vec->fill >= GROW_SIZE) {
                vec->size -= GROW_SIZE;
                vec->data = srealloc(vec, vec->size);
        }
}

void vec_remove(struct ball_vec *vec, size_t i)
{
        vec->fill--;
        memmove(vec + i, vec + i + 1, vec->fill - i);

        shrink_vec(vec);
}

