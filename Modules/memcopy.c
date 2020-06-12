#include <Python.h>

static PyObject *memcopy(PyObject *self, PyObject *args) {
    int count;
    char *str1, str2;

    if(!PyArg_ParseTuple(self, "ssi", &str1, &str2, &count))
        return NULL;
    
    memcpy(str1, str2, count);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyMethodDef MemCpyMethods [] = {
    {"memcpy", memcopy, METH_VARARGS, "Copy contents of a string(src) into another(dest)"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef memcpymodule = {
    PyModuleDef_HEAD_INIT,
    "memcopy",
    "String contents copy",
    -1,
    MemCpyMethods
};

PyMODINIT_FUNC PyInit_memcopy(void) {
    return PyModule_Create(&memcpymodule);
}
