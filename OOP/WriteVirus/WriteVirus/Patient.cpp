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

Patient::~Patient(){
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

void Patient::TakeMedicine(int medicine_resistance) 
{
	int sumVirusResistance = 0;
	int countVirus = 0;
	int i = 0;

	if (m_state == 1)
	{
		int virusResistance = 0;
		while ( i != this->m_virusList.size() - 1)
		{
			virusResistance = m_virusList[i]->ReduceResistance​(medicine_resistance);
			if (virusResistance < 1)
			{
				m_virusList.erase(m_virusList.begin() + i);
				i--;
			}
			i++;
		}
		i = 0;
		int size = this->m_virusList.size() - 1;
		while (i != size)
		{
			int j = 0;
			std::vector<Virus*> list;
			list = m_virusList[i]->DoClone();
			while (j != list.size())
			{
				m_virusList.push_back(list[j]);
				j++;
			}
			i++;
		}
		i = 0;

		while (i != this->m_virusList.size())
		{
			sumVirusResistance += m_virusList[i]->get_m_resistance();
			if (this->m_resistance < sumVirusResistance)
			{
				DoDie();
				break;
			}
			i++;
		}
		std::cout << "Sum virus resistance: " << sumVirusResistance << endl;
	}


}
void Patient::DoDie() 
{
	for (int i = 0; i < m_virusList.size(); i++)
	{
		delete m_virusList[i];
	}
	this->m_virusList.clear();
	this->m_state = 0;

	cout << "Patient died " << endl;
}

void Patient::DeleteListVirus()
{
	for (int i = 0; i < m_virusList.size(); i++)
	{
		delete m_virusList[i];
	}
	this->m_virusList.clear();
	cout << "Delete virus" << endl;
}
