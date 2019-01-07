#include "FluVirus.h"
#include "Virus.h"
#include <vector>
#include <iostream>

FluVirus::FluVirus(){
	this->DoBorn();
	this->InitResistance();
}

FluVirus::~FluVirus(){}

void FluVirus::set_m_Color(int color)
{
	this->m_Color = color;
}
int FluVirus::get_m_Color()
{
	return m_Color;
}

enum color
{
	Blue = 1,
	Red = 2
};

void FluVirus::DoBorn()
{
	this->LoadADNInformation​();
	int random = rand() % 2 + 1;
	if (random == 1)
	{
		this->m_Color = Blue;
	}
	else
	{
		this->m_Color = Red;
	}
}

vector<Virus*> FluVirus::DoClone()
{
	vector<Virus*> listVirus;
	FluVirus *virus = new FluVirus(*this);
	listVirus.push_back(virus);
	return listVirus;

}

void FluVirus::DoDie()
{
	delete this;
}

void FluVirus::InitResistance()
{
	if (m_Color == 1)
	{
		int random = rand() % 6 + 10;
		this->set_m_resistance(random);
	}
	if (m_Color == 2)
	{
		int random = rand() % 11 + 10;
		this->set_m_resistance(random);
	}
}