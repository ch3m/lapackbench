// #include <boost/python.hpp>
// #include "boost/python/extract.hpp"
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include "rlutil/rlutil.h"

// using namespace boost::python;
using namespace std;

// Class contains methods to interface with Python
template<class elemT,class nT>
class axpy {
  nT MemElem;
  nT maxIter;
  elemT *X;
  elemT *Y;
  elemT alpha;
  double allocate_time_sec;
  double deallocate_time_sec;
  double bench_time_sec;
  nT i;

	// Demonstrate extracting a derived object type that is built-in to Boost
	public: 
    void MallocMemory( nT N, nT iter, elemT a) {
      rlutil::setColor(15);
      cout << "Alojando memoria ..." << endl;
      clock_t start = clock();
      alpha   = a;
      MemElem = N;
      maxIter = iter;
      X = (elemT*)malloc ( MemElem*sizeof(elemT) );
      Y = (elemT*)malloc ( MemElem*sizeof(elemT) );
      clock_t end = clock();
      allocate_time_sec = (double)(end - start) / CLOCKS_PER_SEC;
      cout << "Alojando memoria exitosamente..." << endl;
    }

    void fill(){
      for ( i = 0; i < MemElem; i++) {
        X[i] = 1.0f;
        Y[i] = 2.0f;
      }
    }

    void axpy_bench(){
      cout << "Corriendo benchmark..." << endl;
      clock_t start = clock();
      for(nT iter = 0; iter < maxIter; iter++ )
#ifdef _OPENMP
#pragma omp parallel for
#endif
        for ( i=0; i<MemElem;i++){
          Y[i] = alpha*X[i] + Y[i];
        }
      clock_t end = clock();
      bench_time_sec = (double)(end - start) / CLOCKS_PER_SEC;
      cout << "Corriendo benchmark exitosamente...." <<  endl;
    }

    void check(){
      for ( i = 0; i < MemElem; i++){
        double test = (2.0f * maxIter)/Y[i];
        if( test < 0.0000001){
          rlutil::setColor(12);
          cout << "Error en el elmento : " << i  << " con Y[i]: " << Y[i] << " error: " << test << endl;
          break;
        }
      }
    }

    void print_vector(){
      for ( i = 0; i < MemElem; i++)
            cout << "pos: " << i << " Y: " << Y[i] << " X: " << X[i]<< endl; 
    }

    void DeallocMemory() {
      cout << "Desalojando memoria..." << endl;
      clock_t start = clock();
      free(X);
      free(Y);
      clock_t end = clock();
      deallocate_time_sec = (double)(end - start) / CLOCKS_PER_SEC;
      cout << "Desalojando memoria exitosamente... " << endl;
    }

    void resultados(){
      rlutil::setColor(10);
      cout.precision(4);
      cout << "Alojamiento (time[min],bytes): \t\t\t" << allocate_time_sec << "," << MemElem*sizeof(float) << endl;
      cout << "Desalojamiento (time[min],bytes): \t\t" << deallocate_time_sec << "," << MemElem*sizeof(float) << endl;
      cout << "AXPY benchmark (time[min], elementos,iteraciones): " << bench_time_sec << "," << MemElem << "," << maxIter << endl;
    }
};

// Expose classes and methods to Python
// BOOST_PYTHON_MODULE(axpy) {
// 	class_<axpy> ("axpy")
// 		.def("MallocMemoryBytes", &axpy::MallocMemoryBytes)
// 		.def("axpy_bench", &axpy::axpy_bench)
// 	;	
// }
  