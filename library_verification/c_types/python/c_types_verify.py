from ctypes import *
from ctypes.util import *
import os


def init():
    pwd = os.path.dirname(__file__)
    print(find_library(os.path.join(pwd, 'libtestlib.dll')))
    libtest = cdll.LoadLibrary(os.path.join(pwd, 'libtestlib.dll'))
    libtest.parm_int.restype = c_int
    libtest.parm_void.restype = c_int
    libtest.parm_float.restype = c_int
    libtest.parm_point.restype = c_int
    libtest.parm_struct_p.restype = c_int
    libtest.return_int.restype = c_int
    libtest.return_int.restype = None
    libtest.return_float.restype = c_float
    libtest.return_point.restype = c_void_p
    libtest.return_struct_p.restype = POINTER(DemoStruct)
    libtest.reg_callback.restype = c_int
    libtest.call_callback.restype = c_int
    return libtest


class DemoStruct(Structure):
    _fields_ = [("a", c_int), ("b", c_float), ("c", c_char * 5)]


def call_parm_int(lib, parm):
    ret = lib.parm_int(c_int(parm))
    return ret


def call_parm_void(lib):
    ret = lib.parm_void()
    return ret


def call_parm_float(lib, parm):
    ret = lib.parm_float(c_float(parm))
    return ret


def call_parm_point(lib, parm):
    par = c_char_p(parm)
    ret = lib.parm_point(par)
    return ret


def call_parm_struct_p(lib, parma, parmb, parmc):
    ret = lib.parm_struct_p(DemoStruct(parma, parmb, parmc))
    return ret


def call_return_int(lib):
    ret = lib.return_int()
    print(ret)
    return ret


def call_return_void(lib):
    ret = lib.return_void()
    print(ret)
    return ret


def call_return_float(lib):
    ret = lib.return_float()
    print(ret)
    return ret


def call_return_point(lib):
    ret = lib.return_point()
    print(ret)
    return ret


def call_return_struct_p(lib):
    ret = lib.return_struct_p()
    print(ret.contents.a)
    print(ret.contents.b)
    print(ret.contents.c)
    return ret


@CFUNCTYPE(c_int, c_int)
def py_cb_func(a):
    print("py_cb_func", str(a))
    return a + 1


def call_reg_callback(lib, func):
    ret = lib.reg_callback(func)
    print(ret)
    return ret


def call_call_callback(lib):
    ret = lib.call_callback(5)
    print(ret)
    return ret


libtest = init()
call_parm_int(libtest, 1)
call_parm_void(libtest)
call_parm_float(libtest, 2.0)
call_parm_point(libtest, b'ddddd')
call_parm_struct_p(libtest, 3, 4.5, b'qw')

call_return_int(libtest)
call_return_void(libtest)
call_return_float(libtest)
call_return_point(libtest)
call_return_struct_p(libtest)

call_reg_callback(libtest, py_cb_func)
call_call_callback(libtest)
