/* CS261- Assignment 1 - Q.1*/
/* Name: Erin Tanaka
 * Date: 9/25/16
 * Solution description: Allocate memory for list of ten students, populate members of structs, print id's and scores, sort from highest to lowest re print info, find and print minimum score 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
   int id;
   int score;
};

struct student* allocate(){   
   struct student* s= malloc(10*sizeof(struct student));  /*allocate memory for 10 students*/
   return s;  /*return pointer to array of students*/
}

void generate(struct student* students){
   int x;
   for(x=0; x<10; x++){  /*populating each element of student list*/
      students[x].id=x;  /*id number that correlates to index in array*/
      students[x].score=(10*x)%50;  /*score calculated (10*x)%50 where x= student id*/
   }
              	
}

void output(struct student* students){
     
   int x;
   for (x=0; x<10; x++){  /*iterate through student list*/
      printf("ID%d Score%d \n", students[x].id, students[x].score );  /*print id and score*/
   }
}


int min(struct student* students){
   int x, min;
   min=students[0].score;  /*set initial value for comparison*/
   for (x=1; x<10; x++){  /*iterate through list*/
      if (students[x].score < min) min=students[x].score;  /*if students score is less than min, set min to that value*/
   }
   return min;  /*return lowest value*/
}

float avg(struct student* students){
   int i;
   float temp=0; /*set int to 0 for adding all scores up*/
   for (i=0; i<10; i++){  /*iterate through students*/
      temp=temp+students[i].score;  /*add current student's score to total*/
   }  
   temp=temp/10;  /*divide total of scores by number of students*/
   return temp; /*return avg*/

}
void sort(struct student* students){
   int tempscore;
   int tempid;
   int i, j;
   for (i = 0; i < 9; i++) {  /*iterate through list 10 times*/
      for (j = 0; j < 9; j++) {  /*iterate through list*/
	 if (students[j].score < students[j + 1].score){  /*make swap if next score is higher than current*/
	    tempscore = students[j].score;  /*store current score in temp*/
	    tempid = students[j].id;  /*store current id in temp*/
	    students[j].score = students[j+1].score;  /*current gets next score*/
	    students[j].id = students[j+1].id;  /*current gets next id*/
	    students[j+1].score = tempscore;  /*next gets temp score*/
	    students[j+1].id = tempid;  /*next gets temp id*/	    
	 } 		
      }	
   }
}

void deallocate(struct student* stud){
   if (stud != NULL) free(stud);  /*if list contains elements free them*/
}

int main(){
  struct student* stud = allocate();
  generate(stud);
  output(stud);
  sort(stud);
  for(int i=0;i<10;i++){
    printf("%d %d\n", stud[i].id,stud[i].score);
  }
  printf("Avg: %f \n", avg(stud));
  printf("Min: %d \n", min(stud));
  deallocate(stud);
  return 0;
}
