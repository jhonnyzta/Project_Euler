
#include <Python.h>
#include "../include/mylib.h"

extern long long solve(long long up_bound, long long multiple1, long long multiple2);

static PyObject* MyMod_solve(PyObject* self, PyObject* args){
    long long up_bound, multiple1, multiple2;
    if (!PyArg_ParseTuple(args, "lll", &up_bound, &multiple1, &multiple2)){
        return NULL;
    }
    long long resultado = solve(up_bound, multiple1, multiple2);
    return PyLong_FromLongLong(resultado);
}

static PyMethodDef MyMod_methods[] = {
    {"solve", MyMod_solve, METH_VARARGS, "Solvea"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef MyMod = {
    PyModuleDef_HEAD_INIT,
    "mymod", 
    NULL,
    -1,
    MyMod_methods
};

PyMODINIT_FUNC PyInit_mymod(void) {
    return PyModule_Create(&MyMod);
}
