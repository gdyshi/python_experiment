//
// Created by Administrator on 2018-7-25.
//

#ifndef LIBTEST_H
#define LIBTEST_H
typedef struct {
    int a;
    float b;
    char c[5];
} test_t;

typedef int (*CALLBACK)(int in);

int parm_int(int in);

int parm_void(void);

int parm_float(float in);

int parm_point(void *in);

int parm_struct_p(test_t *in);

int return_int();

void return_void();

float return_float();

void *return_point();

test_t *return_struct_p();

int reg_callback(CALLBACK fun);

int call_callback(int in);

#endif //LIBTEST_H
