#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "prog2.h"



/**
* 
*  Function "stubs" for Assignment 2 exercises.
*
*  See prog2.h for specifications of function behavior.
*
*/



/***********************************************
*                                             **
*   MATRIX FUNCTIONS                          **
*                                             **
*   NOTE:  parameter n ALWAYS expresses the   **
*     dimensions of the square matrix in      **
*     question.                               **
*                                             **
***********************************************/
char ** alloc_square_mtx(int n) {
  char** arr = (char**)malloc(n*sizeof(char*));
  for(int i = 0; i < n; i++){
    arr[i] = (char*)malloc(n*sizeof(char));
  }
  
  return arr; 
}

void free_square_mtx(char **m, int n) {
  for(int i = 0; i<n; i++){
    free(m[i]);
  }
  free(m);
}

void pop_mtx_alpha(char **m, int n){
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      m[i][j] = (char)('a'+rand()%('z'-'a'+1));
    }
  }
}


void display_mtx(char **m, int n){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      printf("%c ", m[i][j]);
    }
    printf("\n");
  }
}

void swap_rows(char **m, int n, int r1, int r2){
  for(int i = 0;i<n;i++){
    char temp = m[r1-1][i];
    m[r1-1][i] = m[r2-1][i];
    m[r2-1][i] = temp;
  }
}

void swap_cols(char **m, int n, int c1, int c2){
  for(int i = 0;i<n;i++){
    char temp = m[i][c1-1];
    m[i][c1-1] = m[i][c2-1];
    m[i][c2-1] = temp;
  }
}


void rotate_right(char **m, int n){
  for(int i = 0; i<n; i++){
    for(int j = i; j < n-i-1; j++){
      char temp = m[i][j];
      m[i][j]=m[n-j-1][i];
      m[n-j-1][i]=m[n-i-1][n-j-1];
      m[n-i-1][n-j-1] = m[j][n-i-1];
      m[j][n-i-1] = temp;
    }
  }
}


void floating_boulders(char **m, int n, int nb){
  int count = 0;
  for(int i = 0; i<n;i++){
    for(int j = 0; j<n;j++){
      m[i][j] = '.';
    }
  }
  while(count<nb){
    int randrow = rand()%n;
    int randcol = rand()%n;
    if(m[randrow][randcol]=='.')
      m[randrow][randcol]='#';
    else
      continue;
    count++;
  }
}


void mountains(char **m, int n){
  int row = 7;
  int colnum = 0;
  for(int i = 0; i<n;i++){
    for(int j = 0; j<n;j++){
      m[i][j] = '.';
    }
  }
  while(colnum<7){
    int randrow = rand()%n;
    for(int i = row; i>randrow;i--){
      m[i][colnum] = '#';
    }
    colnum++;
  }
}


void sink(char **m, int n){
  for(int i = n-1; i>0;i--){
    for(int j=0;j<n;j++){
      m[i][j]=m[i-1][j];
    }
  }
  for(int j=0;j<n;j++)
    m[0][j]='.';
}


void gravity(char **m, int n){
  for(int i = 0; i < n; i++)
    for(int j = n - 1; j; j--)
      if(m[j][i] == '.')
        for(int k = j - 1; k >= 0; k--)
          if (m [k][i] != '.'){
            char temp = m[k][i];
            m[k][i] = m[j][i];
            m[j][i] = temp;
            break;
          }
}



/***********************************************
*                                             **
*   STRING FUNCTIONS                          **
*                                             **
***********************************************/


void str_trim(char *s) {
  int start = 0;
  int end = strlen(s)-1;

  while(isspace(s[start]))
    start++;

  while((end>= start)&&isspace(s[end]))
    end--;

  for(int i = start; i<=end; i++)
    s[i-start] = s[i];
  s[end-start+1]= '\0';
}


int str_search(char *s, char *pattern) {
  int longstr = strlen(s);
  int shortstr = strlen(pattern);
  for (int i = 0; i <= longstr - shortstr; i++) {
    int j;
    for (j = 0; j < shortstr; j++)
      if (s[i + j] != pattern[j])
        break;

    if (j == shortstr)
      return i;
  }
}





#ifndef _LIB  // DO NOT REMOVE THIS LINE!!!
              // IT DOESN"T CHANGE HOW YOUR PROGRAM
              // WORKS, BUT IT GIVES US A WAY TO CALL
              // YOUR FUNCTIONS FROM OUR CODE FOR
              // TESTING

/**
* Write a test driver in main below to exercise and
*   your function implementations.
*
* Think carefully about your test cases!
*/
int main(){
  srand(1);
  
  char **m;

  m = alloc_square_mtx(8);

  pop_mtx_alpha(m, 8);
  
  display_mtx(m, 8);

  printf("\n");

  swap_rows(m, 8, 4, 5);

  display_mtx(m, 8);

  printf("\n");

  swap_cols(m, 8, 4, 5);

  display_mtx(m, 8);

  printf("\n");

  rotate_right(m, 8);

  display_mtx(m, 8);

  printf("\n");

  floating_boulders(m, 8, 20);

  display_mtx(m, 8);

  printf("\n");

  mountains(m, 8);

  display_mtx(m, 8);

  printf("\n");

  sink(m, 8);

  display_mtx(m, 8);

  printf("\n");

  floating_boulders(m, 8, 20);

  display_mtx(m, 8);

  printf("\n");

  gravity(m,8);

  display_mtx(m, 8);

  printf("\n");

  char s[] = "abracadabra";
  char pattern[] = "dab";

  str_trim(s);

  printf("%s\n",s);
  
  int res = str_search(s, pattern);
  printf("\n%i",res);

  free_square_mtx(m, 8);

  return 0;
}


#endif        // DO NOT REMOVE THIS LINE!!!
