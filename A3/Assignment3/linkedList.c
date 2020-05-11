#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>


struct Link* listInsertionSort(struct Link* head) {

  /*
   * This function should perform an insertion sort on the list whose head is
   * provided as the function's argument, so that the values in the list are
   * sorted in ascending order, starting at the head.
   *
   * The sort should be done without allocating any new Link structs or any
   * other auxiliary data structures.
   *
   * Return a pointer to the new head of the list.
   */
	
	struct Link * current; //element to be inserted
	struct Link * unsorted; //beginning of unsorted potion of list
	struct Link * sorted; //track end of sorted portion of list
	struct Link * track; //iterator to index through sorted portion of list

	if (head==NULL || head->next==NULL) return head; //head is null pointer(no actual list) or only one element in list

	current = head->next; //current points to second link
	unsorted = current->next; //unsorted portion starts on second element
	sorted = head; //1st element counts a sorted
    track = head; //1st element to look at for comparison   

	while (current != NULL) { //continue until all elements have been sorted
	   if (current->value <= track->value) { //if current number is less than or equal to number to be inserted in list insert there
		   int e = 0; //keep track of whether element was inserted at very end of list
		   if (track == head) { //inserting element at very beginning of list
			   head = current;
			   current->next = track;
			   sorted->next = unsorted;
		   }
		   else if (track == current || (track->next==current && track->value == current->value)) { //"insert" at very end of list
			   sorted = current;
			   current = unsorted;
			   e = 1;
		   }
		   else { //element goes somewhere in the middle
			   struct Link * i = head;
			   while (i->next != track) {
				   i = i->next;
			   }
			   current->next = track;
			   i->next = current;
		   }
		   //setting up pointers for next iteration
		   if (e == 0) { //didn't insert at very end
			   sorted->next = unsorted;
			   current = unsorted;
		   }
		   if (unsorted != NULL) { //still have unsorted portion of list to sort   
			   unsorted = unsorted->next;   
		   }
		   track = head; //reset iterator
	   }
	   else { //track needs to be moved to next element or element needs to be the new end of the list;][-
		   if (track->next==current && track->value < current->value){ //number needs to be placed at end of sorted list and is greater than last val of sorted portion
			   sorted = current;
			   current = unsorted;
			   if (unsorted != NULL) unsorted = unsorted->next;
			   track = head;
		   }
		   else track = track->next; //continue iterating
	   }
	}
  return head;

}


struct Link* reverseList(struct Link* head) {

  /*
   * This function should iteratively reverse the list whose head is provided
   * as the function's argument.
   *
   * The reversal must be done totally in place, i.e. you may not allocate any
   * new Link structs or any other auxiliary data structures.
   *
   * Return a pointer to the new head of the list.
   */

	struct Link* new_head = NULL;
	struct Link* track = NULL;

	
	while (head != NULL) { //continue until no more elements to be reversed
		track = head->next; //track gets next element to be added to reversed list
		head->next = new_head; // make pointer of new 1st element of reversed portion point to current 1st element(willbe second) of reversed portion
		new_head = head; //pointer for begining of reversed list points to new 1st element of reversed list
		head = track; //head of unreversed list points to new 1st element of unreversed list
	}

  return new_head;

}


struct Link* reverseListRecursive(struct Link* head){

  /*
   * Write this function for extra credit.  It should do the exact same thing
   * as reverseList() above, except it should do it recursively instead of
   * iteratively (i.e. no loops allowed).
   *
   * Again, you may not allocate any new Link structs or any other auxiliary
   * data structures.  You may, however, define an auxiliary function to help
   * you do the recursion.
   *
   * Return a pointer to the new head of the list.
   */
	//struct Link* new_head;
	//struct Link* track;

	//while (current->next != NULL) {


	//}
  return head;

}
