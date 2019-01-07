#pragma once
#include <iostream>
#include "Virus.h"
#include<iostream>
#include <vector>

using namespace std;

class Patient
{
private:
	int m_resistance;
	vector<Virus*> m_virusList;
	int m_state;
public:
	Patient();
	~Patient();

	void set_m_resistance(int);
	int get_m_resistance();

	int get_m_state();


	void InitResistance();
	void DoStart();
	void TakeMedicine(int);
	void DoDie();

	void DeleteListVirus();

};

