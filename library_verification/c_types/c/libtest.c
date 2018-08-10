//
// Created by Administrator on 2018-7-25.
//
#include <stdio.h>
#include "libtest.h"

CALLBACK s_func = NULL;

int parm_int(int in) {
    printf("func:%s  parm:%d\n", __FUNCTION__, in);
    return 0;
}

int parm_void(void) {
    printf("func:%s\n", __FUNCTION__);
    return 0;
}

int parm_float(float in) {
    printf("func:%s  parm:%f\n", __FUNCTION__, in);
    return 0;
}

int parm_point(void *in) {
    printf("func:%s  parm:0x%x\n", __FUNCTION__, in);
    return 0;
}

int parm_struct_p(test_t *in) {
    printf("func:%s  parm:\n", __FUNCTION__);
    printf("\ta:%d\n", in->a);
    printf("\tb:%f\n", in->b);
    printf("\tc:%s\n", in->c);
    return 0;
}

int return_int() {
    int ret = 3;
    printf("func:%s  ret:%d\n", __FUNCTION__, ret);
    return ret;
}

void return_void() {
    printf("func:%s\n", __FUNCTION__);
    return;
}

float return_float() {
    float ret = 5;
    printf("func:%s  ret:%f\n", __FUNCTION__, ret);
    return ret;
}

void *return_point() {
    static int a = 5;
    void *ret = &a;
    printf("func:%s  ret:0x%x\n", __FUNCTION__, ret);
    return ret;
}

static test_t s_test_in = {1, 2.0, "12"};
test_t *return_struct_p() {
    s_test_in.a=1;
    s_test_in.b=2;
    s_test_in.c[0]='1';
    s_test_in.c[1]='2';
    s_test_in.c[3]=0;
    test_t *ret = &s_test_in;
    printf("func:%s  ret:\n", __FUNCTION__);
    printf("\ta:%d\n", ret->a);
    printf("\tb:%f\n", ret->b);
    printf("\tc:%s\n", ret->c);
    return ret;
}

int reg_callback(CALLBACK fun) {
    printf("func:%s  parm:0x%x\n", __FUNCTION__, fun);
    s_func = fun;
    return 0;
}

int call_callback(int in) {
    int out = s_func(in);
    printf("func:%s  parm:%d\n", __FUNCTION__, in);
    printf("func:%s  ret:%d\n", __FUNCTION__, out);
    return out;
}
