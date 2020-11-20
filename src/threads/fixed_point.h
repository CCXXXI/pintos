#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

/* Fixed-point real arithmetic used by the mlfqs (multilevel feedback queue scheduler). */

#include <stdint.h>
#include <debug.h>

typedef int32_t fp_t;
#define fp_size 32

/* Suppose that we are using a p.q fixed-point format. */
#define fp_p 17
#define fp_q 14

#if fp_p + fp_q + 1 != fp_size
#error fp_p + fp_q + 1 != fp_size
#endif

#define fp_f (1 << fp_q)

/* x and y are fixed-point numbers, n is an integer. */

/* Convert n to fixed point. */
#define i_to_fp(n) ((n)*fp_f)

/* Convert x to integer (rounding toward zero). */
#define fp_to_i_0(x) ((x) / fp_f)

/* Convert x to integer (rounding to nearest). */
#define fp_to_i(x) (((x) > 0) ? (fp_to_i_0((x) + fp_f / 2)) : (fp_to_i_0((x)-fp_f / 2)))

/* Add x and y. */
#define fp_add_fp(x, y) ((x) + (y))

/* Subtract y from x. */
#define fp_sub_fp(x, y) ((x) - (y))

/* Add x and n. */
#define fp_add_i(x, n) (fp_add_fp((x), i_to_fp(n)))

/* Subtract n from x. */
#define fp_sub_i(x, n) (fp_sub_fp((x), i_to_fp(n)))

/* Multiply x by y. */
#define fp_mul_fp(x, y) ((fp_t)(((intmax_t)(x)) * (y) / fp_f))

/* Multiply x by n. */
#define fp_mul_i(x, n) ((x) * (n))

/* Divide x by y. */
#define fp_div_fp(x, y) ((fp_t)(((intmax_t)(x)) * fp_f / (y)))

/* Divide x by n. */
#define fp_div_i(x, n) ((x) / (n))

#endif /* threads/fixed_point.h */
