#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void geraMatriz(int **x){
  // gerando valores aleatorios entre 0 e 1 e colocando na matriz
  for(int i = 0; i<8; i++){
    for(int j = 0; j<8; j++){
      x[i][j] = rand() % 2;
    }
  }
}

void showMatriz(int **x, int nl, int nc){
  //printando a matriz x
  printf("matriz 8x8: \n\n");
  for(int i = 0; i<nl; i++){
    printf("| ");
    for(int j = 0; j<nc; j++){
      printf("%d", x[i][j]);
    }
    printf(" |\n");
  }
  printf("\n");
}

void printBits(unsigned char c){
   unsigned char bit;
  for(bit=128; bit !=0 ;bit>>=1){
    if(c & bit)  printf("1");
    else  printf("0");
  }
  printf(" ");
}

void printAllBits(unsigned char *py, int bytes){
  //imprimindo todos os bytes da variavel
  printf("bites da variavel y: \n");
  for(int i=0; i<bytes; i++){
    printf("\nbyte %d = ", i);
    printBits(*(py + i));
  }
}

void joinBits(int **x, unsigned char *py){
  //colocando os bites da matriz nos bytes da variavel
  int num = 0;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      if(x[i][j] == 1){
        num += pow(2,7-j);
      }
    }
    *(py + i) = num;
    num = 0;
  }
}

int main(void) {
  unsigned long int y;
  unsigned char *py = &y;
  int **x;
  int nc = 8, nl = 8, i, bytes = sizeof(unsigned long int);
  
  //alocando a matriz na memoria
  x = (int**) malloc(nl*sizeof(int*));
  x[0] = (int*) malloc(nc*nl*sizeof(int));
  for(i=1; i<nl; i++){
    x[i] = x[i-1] + nc; 
  }

  geraMatriz(x);
  showMatriz(x, nl, nc);

  joinBits(x, py);
  printAllBits(py,bytes);

  //liberando a matriz x da memoria
  free(x[0]);
  free(x);
  return 0;
}
