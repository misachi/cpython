#include <Python.h>

static PyObject *write_to_file(PyObject *self, PyObject *args){
    const char *str, *filename = NULL;
    int bytes;
    if (!PyArg_ParseTuple(args, "ss", &filename, &str))
        return NULL;

    FILE *f = fopen(filename, "w");
    bytes = fputs(str, f);
    fclose(f);

    return PyLong_FromLong(bytes);
}

static PyMethodDef wtfmethods [] = {
    {"fputs", write_to_file, METH_VARARGS, "Write string to file"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef wtfmodule = {
    PyModuleDef_HEAD_INIT,
    "wtf",
    "String contents copy to file",
    -1,
    wtfmethods
};

PyMODINIT_FUNC PyInit_wtf(void) {
    return PyModule_Create(&wtfmodule);
}
