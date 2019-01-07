#include "DengueVirus.h"
#include <string>
#include <iostream>
#include "Virus.h"

using namespace std;

DengueVirus::DengueVirus(){
	this->DoBorn();
	this->InitResistance();
}


DengueVirus::~DengueVirus(){}

void DengueVirus::set_m_protein(string c)
{
	this->m_protein = c;
}
string DengueVirus::get_m_protein()
{
	return this->m_protein;
}

void DengueVirus::DoBorn()
{
	this->LoadADNInformation​();
	int random_protein = rand() % 3 + 1;
	if (random_protein == 1)
	{
		this->m_protein = "NS3";
	}
	else if (random_protein == 2)
	{
		this->m_protein = "NS5";
	}
	else
	{
		this->m_protein = "E";
	}
}

std::vector<Virus*> DengueVirus::DoClone()
{
	vector<Virus*> listVirus;
	DengueVirus *dengue_virus = new DengueVirus(*this);
	listVirus.push_back(dengue_virus);
	return listVirus;
}

void DengueVirus::DoDie()
{
	delete this;
}

void DengueVirus::InitResistance()
{
	if (this->m_protein == "NS3")
	{
		int random = rand() % 10 + 1;
		this->set_m_resistance(random);
	}
	if (this->m_protein == "NS5")
	{
		int random = rand() % 10 + 11;
		this->set_m_resistance(random);
	}
	if (this->m_protein == "E")
	{
		int random = rand() % 10 + 21;
		this->set_m_resistance(random);
	}
}