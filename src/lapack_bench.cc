#include "axpy.h"
int main(){
  axpy axpy_bench;

  axpy_bench.MallocMemory(100000000,100000,1.0);
  axpy_bench.fill();
  // axpy_bench.print_vector();  
  axpy_bench.axpy_bench();
  // axpy_bench.print_vector(); 
  axpy_bench.check();
  axpy_bench.DeallocMemory();
  axpy_bench.resultados();	
}
