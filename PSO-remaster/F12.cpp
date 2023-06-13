#include "F12.h"
#include <stdio.h>
extern int count1;
extern int dimension;
F12::F12():Benchmarks(){
  Ovector = NULL;
  minX = -100;
  maxX = 100;
  ID = 12;
  anotherz = new double[dimension];
}

F12::~F12(){
  delete[] Ovector;
  delete[] anotherz;
}

double F12::compute(double*x){
  int i;
  double result=0.0;

  if(Ovector==NULL)
    {
      Ovector = readOvector();
    }

  for (i = dimension - 1; i >= 0; i--) {
      anotherz[i] = x[i] - Ovector[i + count1 ];
  }

  result=rosenbrock(anotherz, dimension);
  return(result);
}

