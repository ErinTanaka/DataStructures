/*
 * This file contains the implementation of a priority queue.
 *
 * You must complete the implementations of these functions:
 *   pq_insert()
 *   pq_first()
 *   pq_remove_first()
 */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "dynarray.h"
#include "pq.h"

// This is the initial capacity that will be allocated for the heap.
#define INITIAL_HEAP_CAPACITY 16

/*
 * This is the definition of the structure we will use to represent the
 * priority queue.  It contains only a dynamic array, which will be used to
 * store the heap underlying the priority queue.
 */
struct pq {
	struct dynarray* heap;
};


/*
 * This is an auxiliary structure that we'll use to represent a single element
 * in the priority queue.  It contains two fields:
 *
 *   priority - the priority value assigned to the item
 *   item - the pointer to the data item represented by this element
 *
 * Both of these will come directly from the corresponding values passed to
 * pq_insert().
 */
struct pq_elem {
	int priority;
	void* item;
};


/*
 * This function allocates and initializes a new priority queue.
 *
 * You should not modify this function.
 */
struct pq* pq_create() {
	struct pq* pq = malloc(sizeof(struct pq));
	assert(pq);
	pq->heap = dynarray_create(INITIAL_HEAP_CAPACITY);
	return pq;
}


/*
 * This function frees the memory associated with a priority queue.
 *
 * You should not modify this function.
 */
void pq_free(struct pq* pq) {
	assert(pq);
	dynarray_free(pq->heap);
	free(pq);
}

/*
 * This function returns 1 if the given priority queue is empty or 0
 * otherwise.
 *
 * You should not mofidy this function.
 */
int pq_isempty(struct pq* pq) {
	assert(pq);
	return dynarray_size(pq->heap) > 0;
}


/*
 * This function inserts a new item with a specified priority into a priority
 * queue.
 *
 * You should complete the implementation of this function.  The first part
 * is done for, where a new element is created to be placed into the dynamic
 * array underlying the priority queue.
 */
void pq_insert(struct pq* pq, void* item, int priority) {
	assert(pq);

	/*
	 * Allocate space for the new element to be placed into the priority queue
	 * and initialize it with the provided values.
	 */
	struct pq_elem* new_elem = malloc(sizeof(struct pq_elem));
	new_elem->item = item;
	new_elem->priority = priority;

	/*
	 * Figure out where in the heap array to insert the new element represented
	 * by new_elem and insert it.
	 */
	dynarray_insert(pq->heap, dynarray_size(pq->heap), new_elem); //place new elem innext open sopt of heap aka end of dyn array

	/*
	 * Restore the heap so that it has the property that every node's priority
	 * value is less than the priority values of its children.  This can be
	 * done by "percolating" the newly added element up in the heap array.  To
	 * perform the percolation, you will have to compare the priority values of
	 * the struct pq_elems in the heap array (i.e. by comparing the
	 * elem->priority values).
	 */
	int c_index = (dynarray_size(pq->heap) - 1); //current element's index in array
	int p_index = (dynarray_size(pq->heap) - 2) / 2; //parent's index in array
	struct pq_elem * c = dynarray_get(pq->heap, c_index); //pointer to current element
	struct pq_elem * p = dynarray_get(pq->heap, p_index); //pointer to parent of current element
	struct pq_elem * temp; // temporary pointer for swapping purposes
	while (c->priority < p->priority) {	//current's priority is less than parent's priority
		temp = c;//make swap
		dynarray_set(pq->heap, c_index, p); //make swap  
		dynarray_set(pq->heap, p_index, c); //make swap

		c_index = p_index; //reset curr index
		p_index = (p_index - 1) / 2; //claculate and reset parent index

		c = dynarray_get(pq->heap, c_index); //update current
		p = dynarray_get(pq->heap, p_index); //update current's parent
		if (c_index == 0) break; //current is in the highest spot possible
	}
}


/*
 * This function returns the first (highest-priority) item from a priority
 * queue without removing it.
 *
 * You should complete the implementation of this function.
 */
void* pq_first(struct pq* pq) {
  assert(pq);
  assert(dynarray_size(pq->heap) > 0);

  struct pq_elem* first_elem = NULL;

  /*
   * Determine what index in the heap array corresponds to the highest-priority
   * element (i.e. the one with the lowest priority value), and store the
   * value there in first_elem.
   */

  first_elem = dynarray_get(pq->heap, 0); //retrieve first element in dynamic array, this element is the top of the "heap" and will have the highest priority(lowest val)

  /*
   * Return the extracted item, if the element taken out of the priority
   * queue is not NULL.
   */
  if (first_elem != NULL) {
    return first_elem->item;
  } else {
    return NULL;
  }
}


/*
 * This function removes the first (highest-priority) element from a priority
 * queue and returns its value.
 *
 * You should complete this function.
 */
void* pq_remove_first(struct pq* pq) {
  assert(pq);
  assert(dynarray_size(pq->heap) > 0);

  struct pq_elem* first_elem = NULL;

  /*
   * Determine what index in the heap array corresponds to the highest-priority
   * element (i.e. the one with the lowest priority value), and store the
   * value there in first_elem.
   */

  first_elem = dynarray_get(pq->heap, 0); //retrieve first element in dynamic array, this element is the top of the "heap" and will have the highest priority(lowest val)
  
  /*
   * Replace the highest-priority element with the appropriate one from within
   * the heap array.  Remove that replacement element from the array after
   * copying its value to the location of the old highest-priority element..
   */
 
	//  dynarray_set(pq->heap, 0, dynarray_get(pq->heap, -1)); //copy last element of heap up to top/becomes new top element (note it currently is in 2 places at once)
	//  dynarray_remove(pq->heap, -1); //remove last element from heap (fixing the two places ate once issue)
  int index = dynarray_size(pq->heap) - 1;
  struct pq_elem *element = dynarray_get(pq->heap, index);
  dynarray_set(pq->heap, 0, element);
  dynarray_set(pq->heap, index, first_elem);
  dynarray_remove(pq->heap, index);
  /*
   * Restore the heap so that it has the property that every node's priority
   * value is less than the priority values of its children.  This can be
   * done by "percolating" the element that replaced the highest-priority
   * element down in the heap array.  To perform the percolation, you will
   * have to compare the priority values of the struct pq_elems in the heap
   * array (i.e. by comparing the elem->priority values).  It may be helpful
   * to write a helper function to accomplish this percolation down.
   */
  /*
  if (dynarray_size(pq->heap) != 0) { //there is at least one element in the heap
     struct pq_elem * curr=dynarray_get(pq->heap, 0); //element to percolate down if needed
     struct pq_elem *left; //pointer for curr's left child
     struct pq_elem *right; //pointer for curr's right child
     struct pq_elem *min; //pointer for curr's child with min priority
	 int curr_index=0; //to curr's index initiallized to 0to start at top of heap
	 int min_index; //index of curr's min child
  
	  while (curr_index < dynarray_size(pq->heap)) { //continue until curr is at bottom of heap
		  if ((2 * curr_index + 1) < dynarray_size(pq->heap)) { // left child exists
			  if (2 * curr_index + 2 < dynarray_size(pq->heap)) { //right child exists
				  left = dynarray_get(pq->heap, 2 * curr_index + 1); //set pointer to left child
				  right = dynarray_get(pq->heap, 2 * curr_index + 2); //set pointer to right child
				  if (left->priority < right->priority) { //finding min: left has lower priority than right
					  min = left; //set pointer to minimum of children
					  min_index = 2 * curr_index + 1; //save index of min of children
				  }
				  else { //finding min: right has lower priority than left
					  min = right; //set pointer to min of children
					  min_index = 2 * curr_index + 2; //save index of min of children
				  }
			  }
			  else { //left child exists but no right child
				  left = dynarray_get(pq->heap, 2 * curr_index + 1); //set pointer to left child
				  min = left; //set pointer to "min"/only child
				  min_index = 2 * curr_index + 1; //save index of "min"/only child
			  }
			  if (min->priority < curr->priority) { //swap needs to be made:current element has lower priority than its lowest priority child
				  struct pq_elem * temp; //temporary pointer for swapping purposes
				  temp = curr; //temp points to current element
				  dynarray_set(pq->heap, curr_index, min); //set array[current's index] to point to the child
				  dynarray_set(pq->heap, min_index, temp); //set array[child's index] to point to current/temp
				  curr_index = min_index; //update current's index
				  curr = dynarray_get(pq->heap, curr_index); //update pointer for current
			  }
			  else break; //swap doesn't need to be made and we no longer need to percolate 
		  }
		  else break; //element has reached the lowest place it can in the tree and we no longer need to percolate
	  }
  }
*/
  int left_index;
  int right_index;
  int min_index;
  struct pq_elem *left_child;
  struct pq_elem *right_child;
  struct pq_elem *min_child;
  while ((index < dynarray_size(pq->heap)) && (dynarray_size(pq->heap)>0)) {
	  left_index = 2 * index + 1; // calc set left ind
	  right_index = 2 * index + 2; //calc and set right ind
	  if (dynarray_get(pq->heap, left_index) != NULL) { //if left exists: the main issue here is that theis may not actually be null; aka when stuff gets removed it isn't actually freed or set to NULL we just shrink the int telling us the size of the array
		  left_child = dynarray_get(pq->heap, left_index); //setting pointer to left child
	  }
	  if (dynarray_get(pq->heap, right_index) != NULL) { //if right child exists same issue as before with the null now this may not be the problem specifically but it may im not really sure yet
		  right_child = dynarray_get(pq->heap, right_index); //set pointer to right child
	  }

	  if (left_child->priority < right_child->priority) { // one issue here is if there is no right child to compare to, this means its gonna use whatever was last put in there whether or not its actally the right child of our "current" element
		  min_child = left_child;
		  min_index = left_index;
	  }
	  else {
		  min_child = right_child;
		  min_index = right_index;
	  }

	  if (min_index<dynarray_size(pq->heap) && min_child->priority < element->priority) { //this looks okay
		  dynarray_set(pq->heap, min_index, element);//these look fine
		  dynarray_set(pq->heap, index, min_child);
		  index = min_index; //reset index of current element
		  element = dynarray_get(pq->heap, index); //reset pointer to current element
	  }
	  else {
		  break;
	  }
  }
  //thing i added to check what array looks like after each remove you'll need to #include <stdio.h> temporarily but when i run it with this 2 ges removed but 96 never percolates down
  int i;
  printf("array:");
  for (i = 0; i < 16; i++) {
	  struct pq_elem * p = dynarray_get(pq->heap, i);
	  printf("%d ", p->priority);
  }
  printf("\n");

  /*
   * Return the extracted item, if the element taken out of the priority
   * queue is not NULL.
   */
  if (first_elem != NULL) {
    return first_elem->item;
  } else {
    return NULL;
  }
}
