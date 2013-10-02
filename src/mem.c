#include <stdlib.h>
#include <time.h>
main (){
  double *V;
  long int N,i;
  N=2*3000000000;
  int j,iter = 40;
  clock_t start = clock();
  V = (double*)malloc ( N*sizeof(double) );
  clock_t end = clock();
  double seconds = (end - start) / CLOCKS_PER_SEC;
  double size_gb = N/1024/1024/1024*8;
  printf("Tiempo: %f seg de alojar %.3f GB\n", seconds/60, size_gb);
 
  start = clock();
  for(j=0; j<iter; j++)
#ifdef _OPENMP
#pragma omp parallel for
#endif
        for(i=0; i<N; i++)
                V[i]=0;
  end = clock();
  seconds = (end - start) / CLOCKS_PER_SEC;
  printf("Tiempo: %f seg en recorrer %d veces %.3f GB", seconds/60, iter, size_gb);
  free(V);
}
