#include "axpy.h"
int main(){
  axpy<double,long int> axpy_bench;

  axpy_bench.MallocMemory(4294967296,100,1.0);
  axpy_bench.fill();
  // axpy_bench.print_vector();  
  axpy_bench.axpy_bench();
  // axpy_bench.print_vector(); 
  axpy_bench.check();
  axpy_bench.DeallocMemory();
  axpy_bench.resultados();	
}
