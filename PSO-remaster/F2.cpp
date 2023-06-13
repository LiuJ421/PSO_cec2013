#include "F2.h"

extern int count1;
extern int dimension;

F2::F2():Benchmarks(){
  Ovector = NULL;
  minX = -5;
  maxX = 5;
  ID = 2;
  anotherz = new double[dimension];
}

F2::~F2(){
  delete[] Ovector;
  delete[] anotherz;
}

double F2::compute(double* x){
  int    i;
  double result;

  if(Ovector == NULL) {
    // Ovector = createShiftVector(dimension,minX,maxX);
    Ovector = readOvector();
  }

  for (i = dimension - 1; i >= 0; i--) {
      anotherz[i] = x[i] - Ovector[i + count1 * dimension];
  }
  
  // // T_{osz}
  // transform_osz(anotherz, dimension);
  
  // // T_{asy}^{0.2}
  // transform_asy(anotherz, 0.2);

  // // lambda
  // Lambda(anotherz, 10);

  result = rastrigin(anotherz,dimension);
  return(result);
}
