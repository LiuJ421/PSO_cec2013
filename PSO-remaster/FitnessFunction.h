#pragma once
#include "PSO.h"
#include <math.h>
#define PI 3.1415926
#include "Benchmarks.h"
#include "F1.h"
#include "F2.h"
#include "F12.h"

double FitnessFunction(Particle& particle);

//double FitnessFunction(Particle& particle)
//{
//	F1 f1 = F1();
//	double fitness = -f1.compute(particle.position_);
//	return fitness;
//}

//double FitnessFunction(Particle& particle)
//{
//	F2 f2 = F2();
//	double fitness = -f2.compute(particle.position_);
//	return fitness;
//}

double FitnessFunction(Particle& particle)
{
	F12 f12 = F12();
	double fitness = -f12.compute(particle.position_);
	return fitness;
}


//double FitnessFunction(Particle& particle)
//{
//	double x = particle.position_[0];
//	double y = particle.position_[1];
//	double temp = sqrt(x * x + y * y);
//	double fitness = sin(temp) / temp + exp(0.5* cos(2 * PI * x) + 0.5  * cos(2 * PI * y)) - 2.71289;
//	return fitness;
//}