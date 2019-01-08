#pragma once
#include <iostream>
#include "Virus.h"
#include <vector>

using namespace std;


class FluVirus : public Virus
{

private:
	int m_Color;

public:
	FluVirus();
	virtual ~FluVirus();
	
	FluVirus(const FluVirus *);

	void set_m_Color(int);
	int get_m_Color();

	void DoBorn() override;
	std::vector<Virus*> FluVirus::DoClone() override;
	void DoDie() override;
	void InitResistance() override;

	void printDNA();
};