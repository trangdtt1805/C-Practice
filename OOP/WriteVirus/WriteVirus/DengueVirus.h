#pragma once
#include "Virus.h"
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class DengueVirus : public Virus
{
private:
	string m_protein;
public:
	DengueVirus();
	~DengueVirus();

	//DengueVirus(const DengueVirus &Virus);

	void set_m_protein(string);
	string get_m_protein();

	void DoBorn() override;
	std::vector<Virus*> Virus::DoClone() override;
	void DoDie() override;
	void InitResistance() override;
};

