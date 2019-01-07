#pragma once
#include <iostream>
#include "Virus.h"
#include<iostream>
#include <list>

using namespace std;

class Patient
{
private:
	int m_resistance;
	list<Virus*> m_virusList;
	int m_state;
public:
	Patient();
	~Patient();

	void set_m_resistance(int);
	int get_m_resistance();
	void set_m_state(int);
	int get_m_state();


	void InitResistance();
	list<Virus*> Patient::DoStart();
	void TakeMedicine();
	void DoDie();

};

