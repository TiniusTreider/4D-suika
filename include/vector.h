#ifndef VECTOR_H
#define VECTOR_H

#include "fixed.h"
#include "vec4.h"

#include <stddef.h>

struct ball {
        struct vec4 pos;
        struct vec4 vel;
        fixed d;
};

struct ball_vec;

struct ball_vec *init_vec(void);
void clean_vec(struct ball_vec*);

size_t vec_size(struct ball_vec*);
struct ball *index_vec(struct ball_vec*, size_t);

void vec_add(struct ball_vec*, struct ball);
void vec_remove(struct ball_vec*, size_t);

#endif

