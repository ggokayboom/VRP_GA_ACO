#pragma once
#include <vector>
#include "Graph.h"
#include "Vehicle.h"

class Gene
{
public:
	static double minFitness;	// ��С��Ӧ��
	static double minUnDiveryRate;
	static vector< vector<int> > BestVehicleGroup;	// ������ͷ���
	int *geneSequence;			// ��������
	static int num;				// ��������
	static int bitNum;			// ���г���
	double unDeliveryRate;		// ������
	double fitness;				// ������
	double posibility;			// ѡ��ĸ���
	vector<Vehicle> vehicleGroup;	// �����ͻ�������
	static double upBond;		// �����Ժ����Ͻ�
	static double lowBond;		// �����Ժ����½�
	
	Gene(void);
	~Gene(void);

	// ������ɳ�ʼ����������
	void init();

	// ����
	void variation(); 
	// ��ĳ�ڵ㿪ʼ�����������У����Ƶ��µĸ���
	static void swapGene(const Gene &gene0, const Gene &gene1, Gene &gene2, Gene &gene3);
	
	 // �������������
	void fitnessFunction(const Graph &graph);
	
	// ���ѡ�񽻻�
	static void randSwap(Gene *&gene);

	// ���ѡ�񽻻�����
	static void randSelect(Gene *gene,int &oder0 ,int &oder1);

	// ��������Ϊ����n��0-1�������
	static void get_rand(double &x, double &y);
};
