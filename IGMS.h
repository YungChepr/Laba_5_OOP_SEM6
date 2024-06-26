#pragma once

#include <chrono>
#include <thread>
#include "IDynamicDatabase.h"
#include "ProxyDatabase.h"
#include "IAO.h"
#include "IIS.h"
#include "DecoratorMin.h"
#include "DecoratorMax.h"
#include "Composite.h"
#include "Humus.h"
#include "Peat.h"
#include "Iterator.h"

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;

//����� ���������� ��������
class IGMS
{
private:
	int CurrentValue; //���� �������� ������� �������� ���������
	int Counter;	  //���� �������� ������� ������� ��������� ����������� �������
	bool Working;	  //���� �������� ���������� �������� �� ������� ��� ���
public:
	IGMS()
	{
		Working = true;
	}
	IGMS(int count)
	{
		Working = true;
		Counter = count;
	}
	//����� �������� �� ������ ������ �������
	void Management(IDynamicDatabase* DinBase, ProxyDatabase* Database, ISensor* Sensors[NSensors], IAO* Objects[NObjects], IIS* Systems[NSystem], Decorator* Decorators[NDecorators]);
};

