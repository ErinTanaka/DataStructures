/* CS261- Assignment 1 - Q. 0*/
/* Name: Erin Tanaka
 * Date: 9/25/16
 * Solution description: Use splat/star and ampersand to print values and addrsses of pointers and change values.
 */
 
#include <stdio.h>
#include <stdlib.h>

int fooB(int* a, int* b, int c){
        c = *a + *b;  /*c gets value of a + the value of b*/
	*a = *b;  /*a gets the value b contains*/
	*b = *b * 2;  /*b gets double the current value of b*/
	return c;
}


void fooA(int* iptr){
	printf("Value of int pointed to by iptr: %d \n", *iptr);  /*print val contained in what iptr points to*/
	printf("Address iptr points to: %p \n", iptr);  /*print address iptr contains/points to*/
	printf("Address of iptr: %p \n", &iptr);  /*print address of iptr*/
}

int main(){
    
	int x;  /*declare an integer x*/

	printf("address of x: %p \n", &x);  /*print the address of x*/
    
	fooA(&x);  /*Call fooA() with the address of x*/
    
        printf("Value of x: %d \n", x);  /*print the value of x*/

    return 0;
}
