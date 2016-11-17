// GA_VRP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Graph.h"
#include "Gene.h"
#include "Grefenstette.h"
#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <time.h>


const int iterTimes = 1000;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	time_t tm;
	time(&tm);
	unsigned int nSeed=(unsigned int)tm;
	srand(nSeed);

	Graph graph;
	graph.nodeCount = 51;
	graph.readGraph("./graph.txt");
	graph.readDemand("./demand.txt");
	Gene::num = 16;
	Gene::bitNum = graph.nodeCount - 1;

	Vehicle::capacity = 10;

	
	Gene *geneArray = new Gene[Gene::num];
	for (int i = 0; i < Gene::num; i++)
	{
		geneArray[i].init();
	}

	for (int i = 0; i < iterTimes; i++)
	{	
		for (int j = 0; j < Gene::num; j++)
		{
			geneArray[j].fitnessFunction(graph);
			Grefenstette::coding(geneArray[j].geneSequence, Gene::bitNum);
		}

		Gene::randSwap(geneArray);

		for (int j = 0; j < Gene::num; j++)
		{
			geneArray[j].variation();
		}

		for (int j = 0; j < Gene::num; j++)
		{
			Grefenstette::Decoding(geneArray[j].geneSequence, Gene::bitNum);
		}

		cout << "[" << i << "] " << "Gene::minFitness = " << Gene::minFitness  << endl;
	}
	cout << endl;
	cout << "������Ϊ�� " << Gene::minUnDiveryRate << endl;
	cout << "����ʻ·��Ϊ��  " << Gene::minFitness << endl;
	cout << "������ͷ���Ϊ: " << endl;
	for (int j = 0; j < Gene::BestVehicleGroup.size(); j++)
	{
		cout << "�� " << j + 1 << " :	";
		for (int k = 0; k < Gene::BestVehicleGroup[j].size(); k++)
		{
			cout << Gene::BestVehicleGroup[j][k] << " ";
		}
		cout << endl;
	}
	return 0;
}

