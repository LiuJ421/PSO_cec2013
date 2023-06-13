#include <iostream>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "PSO.h"
#include "FitnessFunction.h"

#include <time.h>				// time()
int count1 = 497;
time_t now ;
tm* curr_tm;
float temp;
int main()
{
	// 粒子群优化器参数：2为变量维度，true表示有搜索上下限
	int whole = 1000;
	int dimension = 2;
	double result_all=-20;
	/*int epoch = whole / dimension;*/ //F2
	int epoch = 500;
	time_t time1 = time(NULL);
	time1 = time1 - 29400;
	int lizigeshu = 12;

	for(int iiii=497;iiii<epoch;iiii++)
	{
		PSOPara psopara(dimension, true);
		psopara.particle_num_ = lizigeshu;		// 粒子个数
		psopara.max_iter_num_ = 4500;	// 最大迭代次数
		for (int iii = 0;iii < dimension;iii++)
		{
			psopara.dt_[iii] = 1.0;			// 第一维度上的时间步长
			psopara.wstart_[iii] = 0.9;		// 第一维度上的起始权重系数
			psopara.wend_[iii] = 0.3;			// 第一维度上的终止权重系数
			psopara.C1_[iii] = 1.49445;		// 第一维度上的加速度因子
			psopara.C2_[iii] = 1.49445;		// 第二维度上的加速度因子
			psopara.lower_bound_[iii] = -350.0;	// 第一维度搜索下限
			psopara.upper_bound_[iii] = 350.0;	// 第一维度搜索上限
		}

		PSOOptimizer psooptimizer(&psopara, FitnessFunction);

		std::srand((unsigned int)time(0));
		psooptimizer.InitialAllParticles();
		
		double fitness = psooptimizer.all_best_fitness_;
		double* result = new double[psooptimizer.max_iter_num_];

		if (count1 != 0) 
		{
			for (int iiiii = 0;iiiii < lizigeshu;iiiii++)
			{
			psooptimizer.particles_[iiiii].position_[0] = temp;
			}
		}

		for (int i = 0; i < psooptimizer.max_iter_num_; i++)
		{
			psooptimizer.UpdateAllParticles();
			result[i] = psooptimizer.all_best_fitness_;
			if (i % 100 == 0) {
				std::cout <<count1<< " 第" << i << "次迭代结果：";
				std::cout << "x = " << psooptimizer.all_best_position_[0] << ", " << "y = " << psooptimizer.all_best_position_[1];
				std::cout << ", fitness = " << result[i] << std::endl;
				now = time(nullptr);
				curr_tm = localtime(&now);

				ofstream OutFile("K:/PSO-master - 副本/test_f12_logs.txt", ios::app); //利用构造函数创建txt文本，并且打开该文本
				
				OutFile << count1 << " 第" << i << "次迭代结果：";
				OutFile << "x = " << psooptimizer.all_best_position_[0] << ", " << "y = " << psooptimizer.all_best_position_[1];
				OutFile << ", fitness = " << result[i] ;
				
				OutFile << "Time:  " << curr_tm->tm_hour<<curr_tm->tm_min<<curr_tm->tm_sec << std::endl; //把字符串内容"This is a Test!"，写入Test.txt文件
				OutFile.close(); //关闭Test.txt文件
				if (psooptimizer.all_best_fitness_ > -0.01)
				{
					break;
				}
			}
		}
		
		result_all += psooptimizer.all_best_fitness_;
		ofstream OutFile("K:/PSO-master - 副本/X_posi/X_posi.txt", ios::app); //利用构造函数创建txt文本，并且打开该文本
		
		if (count1 == 0) {
			for (int ktj = 0;ktj < dimension;ktj++)
				OutFile << psooptimizer.all_best_position_[ktj] << "\n"; //把字符串内容"This is a Test!"，写入Test.txt文件
		}
		else {
			for (int ktj = 1;ktj < dimension;ktj++)
				OutFile << psooptimizer.all_best_position_[ktj]-1 << "\n"; //把字符串内容"This is a Test!"，写入Test.txt文件
		}
		count1++;
		OutFile.close(); //关闭Test.txt文件
		temp = psooptimizer.all_best_position_[1];
	}


	time_t time2=time(NULL);
	float time3 = time2 - time1;
	printf("Distributed Fitness Sum : %f\n", result_all);
	printf("Used time  : %f\n", time3);
	ofstream OutFile("K:/PSO-master - 副本/Test.txt", ios::app); //利用构造函数创建txt文本，并且打开该文本
	OutFile << "Fitness of all:  "<<result_all << "\nused time: "<<time3; //把字符串内容"This is a Test!"，写入Test.txt文件
	OutFile.close(); //关闭Test.txt文件


}