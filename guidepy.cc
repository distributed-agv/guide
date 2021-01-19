#include <python2.7/Python.h>
#include "guidepy.h"
#include "guide.h"
#include <cstdlib>
#include <string>

static void delete_guide(void *);

PyMethodDef guidepy_methods[] = {
  {"make_guide", guidepy_make_guide, METH_VARARGS, ""},
  {"get_next_step", guidepy_get_next_step, METH_VARARGS, ""},
  {NULL, NULL, 0, NULL},
};

PyMODINIT_FUNC initguidepy() {
  Py_InitModule("guidepy", guidepy_methods);
}

PyAPI_FUNC(PyObject *) guidepy_make_guide(PyObject *self, PyObject *args) {
  int car_num = 0;
  int row_num = 0;
  int col_num = 0;
  int redis_port = 0;
  char *redis_host = NULL;
  char *get_lock_sha = NULL;
  char *commit_sha = NULL;
  char *recover_sha = NULL;
  Guide *guide = NULL;

  if (!PyArg_ParseTuple(args, "iiisisss", &car_num, &row_num, &col_num, &redis_host, &redis_port,
                        &get_lock_sha, &commit_sha, &recover_sha))
    return PyErr_Format(PyExc_ValueError, "Bad arguments");
  
  guide = new Guide;
  guide->car_num = car_num;
  guide->row_num = row_num;
  guide->col_num = col_num;
  guide->redis_host = redis_host;
  guide->redis_port = redis_port;
  guide->get_lock_sha = get_lock_sha;
  guide->commit_sha = commit_sha;
  guide->recover_sha = recover_sha;

  return PyCObject_FromVoidPtr(guide, delete_guide);
}

PyAPI_FUNC(PyObject *) guidepy_get_next_step(PyObject *self, PyObject *args) {
  PyObject *py_object = NULL;
  Guide *guide = NULL;
  int car_id = 0;
  int seq = 0;
  int cur_row_idx = 0;
  int cur_col_idx = 0;
  int last_row_idx = 0;
  int last_col_idx = 0;
  int dst_row_idx = 0;
  int dst_col_idx = 0;
  Guide::CarState car_state;
  Guide::StepCode step_code = Guide::StepCode::STOP;

  if (!PyArg_ParseTuple(args, "Oiiiiiiii", &py_object, &car_id, &seq,
                        &cur_row_idx, &cur_col_idx, &last_row_idx, &last_col_idx, &dst_row_idx, &dst_col_idx))
    return PyErr_Format(PyExc_ValueError, "Bad arguments");
  if (PyCObject_Check(py_object))
    guide = (Guide *) ((PyCObject *) py_object)->cobject;
  else
    return PyErr_Format(PyExc_ValueError, "Bad arguments");

  car_state.car_id = car_id;
  car_state.seq = seq;
  car_state.cur_pos.row_idx = cur_row_idx;
  car_state.cur_pos.col_idx = cur_col_idx;
  car_state.last_pos.row_idx = last_row_idx;
  car_state.last_pos.col_idx = last_col_idx;
  car_state.dst_pos.row_idx = dst_row_idx;
  car_state.dst_pos.col_idx = dst_col_idx;

  step_code = guide->GetNextStep(car_state);
  if (step_code == Guide::StepCode::ERROR)
    return PyErr_Format(PyExc_RuntimeError, "Failed to get next step");

  return PyInt_FromLong(step_code);
}

static void delete_guide(void *guide) {
  delete (Guide *) guide;
}
