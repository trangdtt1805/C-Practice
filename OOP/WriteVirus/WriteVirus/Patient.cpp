#include "Patient.h"
#include <iostream>
#include <vector>
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"


Patient::Patient() {
	this->InitResistance();
	this->DoStart();
}

Patient::~Patient() {
	DoDie();
}

enum virus {
	Flu = 1,
	Dengue = 2
};

enum state
{
	DIE = 0,
	ALIVE = 1
};

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
	int random = rand() % (9000 - 1000 + 1) + 1000;
	this->m_resistance = random;
}

void Patient::DoStart()
{
	this->m_state = 1;
	int rd_numberVirus = rand() % (20 - 10 + 1) + 10;

	for (int i = 0; i <= rd_numberVirus; i++)
	{
		int rd_virus = rand() % 2 + 1;
		if (rd_virus == 1)
		{
			Virus* flu_virus = new FluVirus();
			this->m_virusList.push_back(flu_virus);
		}
		else if (rd_virus == 2)
		{
			Virus* dengue_virus = new DengueVirus();
			this->m_virusList.push_back(dengue_virus);
		}
	}
}

void Patient::TakeMedicine()
{
	int  medicine_resistance = rand() % 30 + 1;
	int i = this->m_virusList.size() - 1;

	int count_virus = 0;

	cout << "medicine_resistance: " << medicine_resistance << endl;
	cout << "Virus list size: " << this->m_virusList.size() << endl;

	while (i >= 0)
	{
		this->m_virusList[i]->ReduceResistance​(medicine_resistance);
		if (this->m_virusList[i]->get_m_resistance() > 0)
		{
			for (auto virus_clone : this->m_virusList[i]->DoClone())
			{
				this->m_virusList.push_back(virus_clone);
			}
		}
		else
		{
			this->m_virusList.erase(this->m_virusList.begin() + i);

		}
		i--;
	}

	int sumResistanceVirus = 0;
	for each (auto var in m_virusList)
	{
		sumResistanceVirus += var->get_m_resistance();
	}

	if (sumResistanceVirus > this->get_m_resistance())
	{
		cout << "Patient die";
		this->m_state = 0;
	}
}


void Patient::DoDie()
{

	this->m_state = 0;

	cout << "Patient died " << endl;
}

//void Patient::DeleteListVirus()
//{
//	for (int i = 0; i < m_virusList.size(); i++)
//	{
//		delete m_virusList[i];
//	}
//	this->m_virusList.clear();
//	cout << "Delete virus" << endl;
//}
