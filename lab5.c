// intarr.c
// the functions i have written for LAB5
// test with main.c

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "intarr.h"

// task 1

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len ) {

  intarr_t* newint;

  // set newint to NULL
  newint = NULL;

  // malloc the size of the new int
  newint = malloc(sizeof(intarr_t));

  // if memory allocation succeeds and newint does not still equal NULL then
  if (newint != NULL) {

    (*newint).data = malloc(len * sizeof(int));

    if ( ((*newint).data ) == NULL) {
      free(newint);
    } else {
      ((*newint).len) = len;
    }
  }

  return newint;
}




// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ) {

  // if the pointer is null then do nothing, so if ia != NULL then
  if (ia != NULL) {
    // if the contents of ia are not NULL then free it
    if (ia->data != NULL) {
      free(ia->data);
    }
  }

}




// task 2

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.

intarr_result_t intarr_set( intarr_t* ia,
			    unsigned int index,
			    int val ) {


    // if the index is valid
    if ( index >= 0 && index <= ia->len ) {
      // set the value at ia->data[index] to val
      ia->data[index] = val;
      // return arr is ok
      return INTARR_OK;
    }

    // if array ia index is invalid then also return INTARR_BADARRAY
    // determine if the array is invalid by if the index is less than 0 or the index is greater than the array length ( ie out of bounds )
    if ( index < 0  || index >= ia->len ) {
      return INTARR_BADARRAY;
    }

    // if array ia is NULL
    if ( ia == NULL ) {
      return INTARR_BADARRAY;
    }



}


// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia,
			    unsigned int index,
			    int* i ) {

    // if the index is valid
    if ( index >= 0 && index < ia->len ) {
      // and if i is non-null
      if ( i != NULL ) {
        // set *i
        *i = ia->data[index];
        // and return arr ok
        return INTARR_OK;

      // otherwise dont modify *i and return arr bad index
      } else {
        return INTARR_BADINDEX;
      }

      // if index is invalid
      return INTARR_BADINDEX;
    }

    // if ia is NULL return bad array
    if ( ia == NULL ) {
      return INTARR_BADARRAY;
    }

}



// task 3

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer.
intarr_t* intarr_copy( const intarr_t* ia ) {

    intarr_t* ia_duplicate = intarr_create(ia->len);

    // make some room
    ia_duplicate->data = malloc(ia->len * sizeof(int));

    // copy stuff from og array to duplicate array
    ia_duplicate->len = ia->len;
    memcpy(ia_duplicate->data, ia->data, ia->len * sizeof(int));

    return ia_duplicate;

}


// task 4

// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ) {

    // if ia is NULL return bad array
    if ( ia == NULL ) {

      return INTARR_BADARRAY;

    // otherwise if ia is not null then
    } else {

    // set vars
    int n = (ia->len);
    int i;
    int j;

    // loop thru and move boundary
    for (i = 0; i < n-1; i++) {

      // find smallest element so far in array
      int smallest_so_far = i;

      for (j = i + 1; j < n; j++) {

        if ((ia->data[j]) < (ia->data[smallest_so_far])) {
          smallest_so_far = j;

        }

      }


        // if i is not the smallest then swap it with j
        if (smallest_so_far != i) {
        printf("swapping %d and %d\n", (ia->data[i]), (ia->data[smallest_so_far]));

        // swap the smallest so far with the first element
        int temp = (ia->data[i]);
        (ia->data[i]) = (ia->data[smallest_so_far]);
        (ia->data[smallest_so_far]) = temp;

       }

      }

    return INTARR_OK;

  }

}



// task 5

// Find the first occurence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ) {

    // ia is null return bad array
    if ( ia == NULL ) {
      return INTARR_BADARRAY;

    // otherwise if ia is not null then
    } else {

      // set vars
      int n = (ia->len);
      int j;

      // implement linear search
      for (j = 0; j < n; j++) {
        // the target is found and i is non-null
        if (ia->data[j] == target && i!= NULL) {
          // then set *i to the location index and return arr ok
          *i = j;
          return INTARR_OK;
        }

      }
      // if target does not occur then return arr not found
      return INTARR_NOTFOUND;

    }

}

// task 6

// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
// Take a look at TASK 7 below and see if it might be helpful
intarr_result_t intarr_push( intarr_t* ia, int val ) {

      // if array ia is NULL return bad arr
      if ( ia == NULL ) {
        return INTARR_BADARRAY;
      }

      // set vars
      int n = (ia->len);

      // make some room
      // ia->data = malloc( (ia->data) * (sizeof(int)*(n+1)) );
      ia->data = malloc(*ia->data * sizeof(int));

      // if malloc was successful and data isnt null
      if( ia->data != NULL) {
        // add val to the end of the array and return arr okay
        ia->data[n] = val;

        return INTARR_OK;
      }

      // if it is not then return bad alloc
      return INTARR_BADALLOC;

}



// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
// Take a look at TASK 7 below and see if it might be helpful
intarr_result_t intarr_pop( intarr_t* ia, int* i ) {

      // if array ia is NULL return bad arr
      if ( ia == NULL ) {
        return INTARR_BADARRAY;
      }

      // set vars
      int n = (ia->len);

      // if array isnt empty(ie = 0)
      if( n > 0 && i != NULL) {
        // then make some room
        // ia->data = malloc( (ia->data) * (sizeof(int)*(n)) );
        ia->data = malloc(*ia->data * sizeof(int));
        // remove last element/index from the arr and set *i to the removed value
        *i = ia->data[n-1];

        // then return arr ok
        return INTARR_OK;
      }

      // otherwise if array is empty return bad alloc
      return INTARR_BADALLOC;

}


// task 7

// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, intialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ) {

    // if array ia is NULL return bad arr
    if ( ia == NULL ) {
      return INTARR_BADARRAY;
    }

    // allocate so space for the new length of the array
    ia->len = malloc(ia->len * sizeof(newlen));
    // if newlen is greater than 0 aka malloc was successful
    if ( newlen > 0 ) {

      if ( newlen < ia->len ) {
        ia->len = newlen;
        return INTARR_OK;
      }
      if (newlen > ia->len ) {
        for (int i = (ia->len); i < newlen; i++) {
          // the elements in the newlen of the array get initialized to 0
          ia->data[i] = 0;
        }

      }

    } else {
      return INTARR_BADALLOC;
    }

}




// task 8

// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia,
				unsigned int first,
				unsigned int last );






/* LAB 5 ENDS HERE */
