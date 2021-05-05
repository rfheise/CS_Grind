#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "ImageData.h"
#include <string>
static PyObject * decrypt_to_file(PyObject *self, PyObject *args);
static PyObject * encrypt_file(PyObject *self, PyObject *args);
static PyObject * encrypt_string(PyObject *self, PyObject *args);
static PyObject *decrypt_to_string(PyObject *self, PyObject *args);
static PyMethodDef SteganoMethods[] = {
    {"decrypt_to_file",  decrypt_to_file, METH_VARARGS, "Decrypt BMP to File"},
    {"decrypt_to_string",  decrypt_to_string, METH_VARARGS, "Decrypt BMP to String"},
    {"encrypt_file", encrypt_file, METH_VARARGS, "Encrypt File into BMP"},
    {"encrypt_string", encrypt_string, METH_VARARGS, "Encrypt String into BMP"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};
static struct PyModuleDef steganomodule = {
    PyModuleDef_HEAD_INIT,
    "stegano",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    SteganoMethods
};
PyMODINIT_FUNC PyInit_stegano(void)
{
    return PyModule_Create(&steganomodule);
}
static PyObject * decrypt_to_file(PyObject *self, PyObject *args) {

    const char *filename;
    const char *outfile;
    if (!PyArg_ParseTuple(args, "ss", &filename, &outfile)) {
        return NULL;
    }
    try {
        ImageData decryptor(filename);
        decryptor.decrypt(outfile);
        
    } catch (int) {

    }
    Py_INCREF(Py_None);
    return Py_None;
}
static PyObject *decrypt_to_string(PyObject *self, PyObject *args) {
    const char *filename;
    if (!PyArg_ParseTuple(args, "s", &filename)) {
        return NULL;
    }
    const char *out;
    try {
        ImageData x(filename);
        out = x.decrypt_string();
    } catch(int) {
        out = "";
    }
    PyObject *string = PyUnicode_FromString(out);
    if (string == NULL) {
        Py_DECREF(string);
        return NULL;
    }
    return string;
} 
static PyObject * encrypt_file(PyObject *self, PyObject *args) {
    const char *encryptor_file;
    const char *filename;
    const char *outfile;
    if (!PyArg_ParseTuple(args, "sss", &filename, &encryptor_file, &outfile)) {
        return NULL;
    }
    try {
        ImageData encryptor(filename);
        ifstream in(encryptor_file);
        encryptor.encrypt(in, outfile);
    } catch(int) {

    }
    Py_INCREF(Py_None);
    return Py_None;
}
static PyObject * encrypt_string(PyObject *self, PyObject *args) {
    const char *filename;
    const char *strang; 
    const char *outfile;
    if (!PyArg_ParseTuple(args, "sss", &filename, &strang, &outfile)) {
        return NULL;
    }
    try {
        ImageData encrypt(filename);
        encrypt.encrypt(strang,outfile);
    } catch(int) {

    }
    Py_INCREF(Py_None);
    return Py_None;
}