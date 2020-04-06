/* Includes */
#include "_C.h"
#include "structmember.h"
#include "benzina/benzina.h"




static void BenzinaViewObject_alloc            (PyTypeObject*      self,
                                                Py_ssize_t         nitems){
    
}

static int  BenzinaViewObject_new              (PyTypeObject*      self,
                                                PyObject*          args,
                                                PyObject*          kwargs){
    return 0;
}

static int  BenzinaViewObject_init             (BenzinaViewObject* self,
                                                PyObject*          args,
                                                PyObject*          kwargs){
    return 0;
}

static void BenzinaViewObject_dealloc          (BenzinaViewObject* self){
    
}

static int  BenzinaViewObject_getbufferproc    (BenzinaViewObject* exporter,
                                                Py_buffer*         view,
                                                int                flags){
    return PyBuffer_FillInfo(view, (PyObject*)exporter, (void*)exporter->data,
                             exporter->length, 1, flags);
}

static void BenzinaViewObject_releasebufferproc(BenzinaViewObject* exporter,
                                                Py_buffer*         view){
    
}

static int  BenzinaViewObject_traverse         (BenzinaViewObject* self,
                                                visitproc          visit,
                                                void*              arg){
    Py_VISIT(self->child);
    Py_VISIT(self->next);
    return 0;
}

static int  BenzinaViewObject_clear            (BenzinaViewObject* self){
    Py_CLEAR(self->child);
    Py_CLEAR(self->next);
    return 0;
}

static PyObject* BenzinaViewObject_get_ll_next      (BenzinaViewObject* self, void* closure){
    return NULL;
}

static PyObject* BenzinaViewObject_set_ll_next      (BenzinaViewObject* self, PyObject* value, void* closure){
    return NULL;
}

/*
PyMemberDef

    Structure which describes an attribute of a type which corresponds to a C struct member. Its fields are:
    Field 	C Type 	Meaning
    name 	char * 	name of the member
    type 	int 	the type of the member in the C struct
    offset 	Py_ssize_t 	the offset in bytes that the member is located on the type’s object struct
    flags 	int 	flag bits indicating if the field should be read-only or writable
    doc 	char * 	points to the contents of the docstring

    type can be one of many T_ macros corresponding to various C types. When the member is accessed in Python, it will be converted to the equivalent Python type.
    Macro name 	C type
    T_SHORT 	short
    T_INT 	int
    T_LONG 	long
    T_FLOAT 	float
    T_DOUBLE 	double
    T_STRING 	char *
    T_OBJECT 	PyObject *
    T_OBJECT_EX 	PyObject *
    T_CHAR 	char
    T_BYTE 	char
    T_UBYTE 	unsigned char
    T_UINT 	unsigned int
    T_USHORT 	unsigned short
    T_ULONG 	unsigned long
    T_BOOL 	char
    T_LONGLONG 	long long
    T_ULONGLONG 	unsigned long long
    T_PYSSIZET 	Py_ssize_t

    T_OBJECT and T_OBJECT_EX differ in that T_OBJECT returns None if the member is NULL and T_OBJECT_EX raises an AttributeError. Try to use T_OBJECT_EX over T_OBJECT because T_OBJECT_EX handles use of the del statement on that attribute more correctly than T_OBJECT.

    flags can be 0 for write and read access or READONLY for read-only access. Using T_STRING for type implies READONLY. Only T_OBJECT and T_OBJECT_EX members can be deleted. (They are set to NULL).
*/

static PyMemberDef BenzinaViewObject_members[] = {
    {"ref_cnt",      T_PYSSIZET,  0,                                     READONLY, "Reference count of object."},
    {"box_data_ptr", T_ULONGLONG, offsetof(BenzinaViewObject, data),     READONLY, "Raw pointer to box data."},
    {"box_length",   T_PYSSIZET,  offsetof(BenzinaViewObject, length),   READONLY, "Box length, in bytes."},
    {"box_type",     T_UINT,      offsetof(BenzinaViewObject, type),     READONLY, "Box type, as 32-bit unsigned native-endian integer type code."},
    {"box_flagver",  T_UINT,      offsetof(BenzinaViewObject, flagver),  READONLY, "Box flags and version, as packed 32-bit unsigned native-endian integer."},
    {"ll_raw_next",  T_OBJECT_EX, offsetof(BenzinaViewObject, next),     READONLY, "Link to next sibling object, or None."},
    {"ll_child",     T_OBJECT_EX, offsetof(BenzinaViewObject, child),    READONLY, "Link to first child, or None."},
    {"ll_parent",    T_OBJECT_EX, offsetof(BenzinaViewObject, parent),   READONLY, "Link to parent, or None."},
    {NULL},
};

static PyMethodDef BenzinaViewObject_methods[] = {
    {NULL},
};

/**
 * typedef struct PyGetSetDef {
 *     char *name;
 *     getter get;
 *     setter set;
 *     char *doc;
 *     void *closure;
 * } PyGetSetDef;
 */

static PyGetSetDef BenzinaViewObject_getset[] = {
    {"ll_next", (getter)BenzinaViewObject_get_ll_next, (setter)BenzinaViewObject_set_ll_next, "Link to next sibling object, or None.", NULL},
    {NULL},
};

static PyBufferProcs BenzinaViewObject_bufferprocs = {
    (getbufferproc)    BenzinaViewObject_getbufferproc,
    (releasebufferproc)BenzinaViewObject_releasebufferproc,
};

BENZINA_ATTRIBUTE_HIDDEN PyTypeObject BenzinaViewType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name         = "benzina._native._C.View",
    .tp_doc          = "View object documentation",
    .tp_basicsize    = sizeof(BenzinaViewObject),
    .tp_flags        = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC|Py_TPFLAGS_BASETYPE,
    
    .tp_alloc        =    (allocfunc)BenzinaViewObject_alloc,
    .tp_new          =      (newfunc)BenzinaViewObject_new,
    .tp_init         =     (initproc)BenzinaViewObject_init,
    .tp_dealloc      =   (destructor)BenzinaViewObject_dealloc,
    .tp_as_buffer    =              &BenzinaViewObject_bufferprocs,
    .tp_methods      =               BenzinaViewObject_methods,
    .tp_members      =               BenzinaViewObject_members,
    .tp_getset       =               BenzinaViewObject_getset,
    .tp_traverse     = (traverseproc)BenzinaViewObject_traverse,
    .tp_clear        =      (inquiry)BenzinaViewObject_clear,
};
