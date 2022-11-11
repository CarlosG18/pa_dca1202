#include <stdlib.h>

int main(void) {
  int nz, ny, nx, i, j, k, plano;
  int centrox,centroz,centroy;
  int rz,rx,ry;
  char ***m;

  //recebendo valores do usuario para a matriz 3d
  printf("informe os valores das seguintes variaveis:\nnz (numero de planos) = ");
  scanf("%d", &nz);
  printf("ny (numero de linhas) = ");
  scanf("%d", &ny);
  printf("nx (numero de colunas) = ");
  scanf("%d", &nx);
  
  centrox = (float) nx/2;
  centroy = (float) ny/2;
  centroz = (float) nz/2;
  
  printf("\n\ncentro do elipsoide = (%d, %d, %d) \n", centrox,centroy,centroz);
  printf("escolha o plano que será apresentado = ");
  scanf("%d", &plano);
  printf("tamanho do raio em x = ");
  scanf("%d", &rx);
  printf("tamanho do raio em y = ");
  scanf("%d", &ry);
  printf("tamanho do raio em z = ");
  scanf("%d", &rz);

  
  //alocando a matriz 3d na memoria
  m = (char***) malloc(nz*sizeof(char**));
  m[0] = (char**) malloc(nz*ny*sizeof(char*));
  m[0][0] = (char*) malloc(nz*ny*nx*sizeof(char));

//ajustando os endereços
  for(i=1; i<nz; i++){
    m[i] = m[i-1] + ny;
  }

  for(i=0; i<nz; i++){
    for(j=0; j<ny; j++){
      if(i == 0 && j == 0){
        j++;
        m[i][j] = m[i][j-1] + nx;
      }else{
        if(j == 0){
          m[i][j] = m[i-1][ny-1] + nx;
        }else{
          m[i][j] = m[i][j-1] + nx;
        }
      }
    }
  }

  //colocando 1 dentro da elipse e 0 fora

  //equação de um elipsoide: [(x - i)/a]^2 + [(y - j)/b]^2 + [(z - k)/c]^2 --> i centro em x, j centro em y e k centro em z.
  
 //liberando a matriz
 free(m[0][0]);
 free(m[0]);
 free(m);

  return 0;
}
