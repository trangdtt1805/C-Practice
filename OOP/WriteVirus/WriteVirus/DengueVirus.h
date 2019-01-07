#pragma once
#include "Virus.h"
#include <list>


class DengueVirus : public Virus
{
private:
	char m_protein;
public:
	DengueVirus();
	~DengueVirus();

	void set_m_protein(char);
	char get_m_protein();

	void DoBorn() override;
	std::list<Virus*> Virus::DoClone() override;
	void DoDie() override;
	void InitResistance() override;
};

