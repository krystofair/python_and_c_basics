// should be first include in file when something else is included too.
#define PY_SSIZE_T_CLEAN
#include <Python.h>


// This is protocol to create python functions in module or classes in module.
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

// watch out that all other functions or definitions have static keyword
// but this one does not, this one used btw a special MACRO.
PyMODINIT_FUNC
PyInit_kudio(void) {
    return PyModule_Create(&kudiomodule);
}
