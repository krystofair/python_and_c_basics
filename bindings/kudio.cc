#define PY_SSIZE_T_CLEAN
#include <Python.h>
// define audio library I want to use in my module.

static PyObject* maslanka(PyObject* self, PyObject* args) {
    int zmienna = -1;
    if (!PyArg_ParseTuple(args, "i", &zmienna)) {
        return NULL;
    }
    zmienna += (int)100;
    return PyLong_FromLong(zmienna);
}

static PyMethodDef KudioMethods[] = {
    {"maslanka", maslanka, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static PyModuleDef kudiomodule = {
    PyModuleDef_HEAD_INIT,
    "kudio",
    NULL,
    -1,
    KudioMethods
};


PyMODINIT_FUNC
PyInit_kudio(void) {
    return PyModule_Create(&kudiomodule);
}
