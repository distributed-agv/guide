#ifndef GUIDEPY_H
#define GUIDEPY_H

#include <python2.7/Python.h>

extern PyMethodDef guidepy_methods[];

PyMODINIT_FUNC initguidepy();
PyAPI_FUNC(PyObject *) guidepy_make_guide(PyObject *, PyObject *);
PyAPI_FUNC(PyObject *) guidepy_get_next_step(PyObject *, PyObject *);

#endif
