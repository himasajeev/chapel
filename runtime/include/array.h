#ifndef _array_H_
#define _array_H_

#include "chpltypes.h" // only needed while _DECL_ARRAY is instantiated here
#include "domain.h"

typedef struct __arr_perdim {
  int off;
  int blk;
} _arr_perdim;

#define _INIT_ARRAY(arr, dom, elemtype) \
  { \
    int d; \
    const int rank = 1; \
    arr.elemsize = sizeof(elemtype); \
    arr.domain = &dom; \
    arr.dim_info[rank-1].off = dom.dim_info[rank-1].lo; \
    arr.dim_info[rank-1].blk = 1; \
    for (d=rank-2; d>=0; d--) { \
      arr.dim_info[d].off = dom.dim_info[d].lo; \
      arr.dim_info[d].blk = arr.dim_info[d+1].blk \
	* ((dom.dim_info[d+1].hi - dom.dim_info[d+1].lo + 1)  \
	   / dom.dim_info[d+1].str); \
    } \
    arr.size = arr.dim_info[0].blk \
      * ((dom.dim_info[d+1].hi - dom.dim_info[d+1].lo + 1) \
	 / dom.dim_info[d+1].str); \
    arr.base = (elemtype*)malloc(arr.size * sizeof(elemtype)); \
    if (arr.base == NULL) { \
      fprintf(stderr, "ERROR: out of memory"); \
    } \
  }

#define _ACC1(arr, i0) \
  arr.base[((i0)-arr.dim_info[0].off)*arr.dim_info[0].blk]

#define _ACC2(arr, i0, i1) \
  arr.base[((i0)-arr.dim_info[0].off)*arr.dim_info[0].blk + \
           ((i1)-arr.dim_info[1].off)*arr.dim_info[1].blk]

#define _ACC3(arr, i0, i1, i2) \
  arr.base[((i0)-arr.dim_info[0].off)*arr.dim_info[0].blk + \
           ((i1)-arr.dim_info[1].off)*arr.dim_info[1].blk + \
           ((i2)-arr.dim_info[2].off)*arr.dim_info[2].blk]

/*** OLD ***/
#define _DECL_ARRAY(elemtype, rank) \
  typedef struct __array##rank##elemtype { \
    int elemsize; \
    int size; \
    elemtype* base; \
    elemtype* origin; \
    _domain##rank* domain; \
    _arr_perdim dim[rank]; \
  } _array##rank##elemtype

/*** OLD ***/
_DECL_ARRAY(_integer64, 1);
_DECL_ARRAY(_float64, 2);
void _init_array1_integer64(_array1_integer64* newarr, _domain1* dom);
void _init_array2_float64(_array2_float64* newarr, _domain2* dom);

#endif

