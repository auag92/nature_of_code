#include <stdio.h>
#include <stdlib.h>

#define cells 1000     // no. of cells
#define gens 500       // no. of generations

int CELL[cells*gens];

void init(int *c);
void write2file(int *c, int t);

main() {

    init(CELL);

    int i, j, indx, indx_lft, indx_rght, sum;

    for (i=1; i < gens; i++){
      for (j = 0; j < cells; j++){

        indx      =  i*cells      + j;
        indx_lft  = (i-1)*(cells) + j - 1;
        indx_rght = (i-1)*(cells) + j + 1;

        if( j==0){
          sum = CELL[indx_rght];
          if(sum == 1){
            CELL[indx] = 1;
          }else{
            CELL[indx] = 0;

          }
        }else if( j == (cells -1)){
          sum = CELL[indx_lft];
          if(sum == 1){
            CELL[indx] = 1;
          }else{
            CELL[indx] = 0;

          }
        }else {
          sum   = CELL[indx_rght]  + CELL[indx_lft];
          if(sum == 1){
            CELL[indx] = 1;
          }else{
            CELL[indx] = 0;

          }
        }
      }
      write2file(CELL, i);
    }
    printf("Yay! we are done! \n");
}

void init(int *c){
  int i, j, indx;
  for (i=0; i < gens; i++){
    for (j = 0; j < cells; j++){
      indx  = i*cells + j;
      c[indx] = 0;
    }
  }
  indx  = cells/2;
  c[indx] = 1;
}

void write2file (int *c, int t) {
  int i,j,z;
  FILE *fp;
  char filename[1000];

  sprintf(filename,"./datafiles/CELLS_%d.dat",t);
  fp = fopen(filename,"w");
  for ( i = 0; i < gens; i++)
  {
    for ( j=0; j < cells; j++)
    {

      z= i*cells + j;
      fprintf(fp,"%d ",c[z]);

    }
    fprintf(fp,"\n");
  }
  fclose(fp);
}
