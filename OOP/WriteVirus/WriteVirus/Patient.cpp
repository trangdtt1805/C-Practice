#include "Patient.h"
#include <iostream>
#include <vector>
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"


Patient::Patient(){
	this->InitResistance();
	this->DoStart();
}

Patient::~Patient(){}

enum virus {
	Flu = 1,
	Dengue = 2
};
enum state
{
	DIE = 0,
	ALIVE = 1
};

//set/get m_resistance
void Patient::set_m_resistance(int m_resistance)
{
	this->m_resistance = m_resistance;
}

int Patient::get_m_resistance() 
{
	return m_resistance;
}

int Patient::get_m_state() 
{
	return m_state;
}

void Patient::InitResistance() 
{
	int random = rand() % 8001 + 1000;
	this->m_resistance = random;
}

void Patient::DoStart() 
{
	this->m_state = 1;
	int rd_numvirus = rand() % 11 + 10;
	for (int i = 0; i <= rd_numvirus; i++)
	{
		int rd_virus = rand() % 2 + 1;
		if (rd_virus == 1)
		{
			FluVirus *flu_virus = new FluVirus();
			this->m_virusList.push_back(flu_virus);
		}
		if (rd_virus == 2)
		{
			DengueVirus *dengue_virus = new DengueVirus();
			this->m_virusList.push_back(dengue_virus);
		}
	}
}

void Patient::TakeMedicine() {
	
}
void Patient::DoDie() {
	this->m_state = 0;
	cout << "Patient die";
}

