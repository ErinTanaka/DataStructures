#ifndef __DYNARRAY_H
#define __DYNARRAY_H

/*
 * Structure used to represent a dynamic array.
 */
struct dynarray;

/*
 * Create a new dynamic array with a specified capacity.
 *
 * @param capacity the initial capacity of the array.  Must be greater than 0.
 */
struct dynarray* dynarray_create(int capacity);

/*
 * Free the memory associated with a dynamic array.
 */
void dynarray_free(struct dynarray* da);

/*
 * Returns the size (i.e. the number of elements) of a dynamic array.
 */
int dynarray_size(struct dynarray* da);

/*
 * Returns the value of an existing element a dynamic array array.
 *
 * @param idx the index of the element whose value should be returned.  Must
 *   be between 0 and the size of the array.  The special value -1 may also be
 *   passed to return the element at the end of the array.
 */
void* dynarray_get(struct dynarray* da, int idx);

/*
 * Sets an existing element in a dynamic array array to a new value.
 *
 * @param idx the index of the element whose value is to be set.  Must be
 *   between 0 and the size of the array.  The special value -1 may also be
 *   passed to set the element at the end of the array.
 * @param val the new value to be set.
 */
void dynarray_set(struct dynarray* da, int idx, void* val);

/*
 * Inserts a new element to a dynamic array at a specified index.  All existing
 * elements following the specified index are moved back to make room for the
 * new element.
 *
 * @param idx the index in the array at which to insert the new element.  The
 *   special value -1 may be passed to insert at the end of the array.
 * @param val the value to be inserted.
 */
void dynarray_insert(struct dynarray* da, int idx, void* val);

/*
 * Removes an element at a specified index from a dynamic array.  All existing
 * elements following the specified index are moved forward to fill in the
 * gap left by the removed element.
 *
 * @param idx the index of the element to be removed.  The special value -1 may
 *   be passed to remove the element at the end of the array.
 */
void dynarray_remove(struct dynarray* da, int idx);

#endif
