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
	// ����Ⱥ�Ż���������2Ϊ����ά�ȣ�true��ʾ������������
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
		psopara.particle_num_ = lizigeshu;		// ���Ӹ���
		psopara.max_iter_num_ = 4500;	// ����������
		for (int iii = 0;iii < dimension;iii++)
		{
			psopara.dt_[iii] = 1.0;			// ��һά���ϵ�ʱ�䲽��
			psopara.wstart_[iii] = 0.9;		// ��һά���ϵ���ʼȨ��ϵ��
			psopara.wend_[iii] = 0.3;			// ��һά���ϵ���ֹȨ��ϵ��
			psopara.C1_[iii] = 1.49445;		// ��һά���ϵļ��ٶ�����
			psopara.C2_[iii] = 1.49445;		// �ڶ�ά���ϵļ��ٶ�����
			psopara.lower_bound_[iii] = -350.0;	// ��һά����������
			psopara.upper_bound_[iii] = 350.0;	// ��һά����������
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
				std::cout <<count1<< " ��" << i << "�ε��������";
				std::cout << "x = " << psooptimizer.all_best_position_[0] << ", " << "y = " << psooptimizer.all_best_position_[1];
				std::cout << ", fitness = " << result[i] << std::endl;
				now = time(nullptr);
				curr_tm = localtime(&now);

				ofstream OutFile("K:/PSO-master - ����/test_f12_logs.txt", ios::app); //���ù��캯������txt�ı������Ҵ򿪸��ı�
				
				OutFile << count1 << " ��" << i << "�ε��������";
				OutFile << "x = " << psooptimizer.all_best_position_[0] << ", " << "y = " << psooptimizer.all_best_position_[1];
				OutFile << ", fitness = " << result[i] ;
				
				OutFile << "Time:  " << curr_tm->tm_hour<<curr_tm->tm_min<<curr_tm->tm_sec << std::endl; //���ַ�������"This is a Test!"��д��Test.txt�ļ�
				OutFile.close(); //�ر�Test.txt�ļ�
				if (psooptimizer.all_best_fitness_ > -0.01)
				{
					break;
				}
			}
		}
		
		result_all += psooptimizer.all_best_fitness_;
		ofstream OutFile("K:/PSO-master - ����/X_posi/X_posi.txt", ios::app); //���ù��캯������txt�ı������Ҵ򿪸��ı�
		
		if (count1 == 0) {
			for (int ktj = 0;ktj < dimension;ktj++)
				OutFile << psooptimizer.all_best_position_[ktj] << "\n"; //���ַ�������"This is a Test!"��д��Test.txt�ļ�
		}
		else {
			for (int ktj = 1;ktj < dimension;ktj++)
				OutFile << psooptimizer.all_best_position_[ktj]-1 << "\n"; //���ַ�������"This is a Test!"��д��Test.txt�ļ�
		}
		count1++;
		OutFile.close(); //�ر�Test.txt�ļ�
		temp = psooptimizer.all_best_position_[1];
	}


	time_t time2=time(NULL);
	float time3 = time2 - time1;
	printf("Distributed Fitness Sum : %f\n", result_all);
	printf("Used time  : %f\n", time3);
	ofstream OutFile("K:/PSO-master - ����/Test.txt", ios::app); //���ù��캯������txt�ı������Ҵ򿪸��ı�
	OutFile << "Fitness of all:  "<<result_all << "\nused time: "<<time3; //���ַ�������"This is a Test!"��д��Test.txt�ļ�
	OutFile.close(); //�ر�Test.txt�ļ�


}