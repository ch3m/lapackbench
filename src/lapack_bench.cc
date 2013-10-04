#include "axpy.h"
int main(){
  axpy<double,long int> axpy_bench;

  axpy_bench.set_maxIter(100);
  axpy_bench.set_data_gb(20);
  axpy_bench.MallocMemory();
  axpy_bench.fill();
  // axpy_bench.print_vector();  
  axpy_bench.axpy_bench();
  // axpy_bench.print_vector(); 
  axpy_bench.check();
  axpy_bench.DeallocMemory();
  axpy_bench.resultados();	
}
