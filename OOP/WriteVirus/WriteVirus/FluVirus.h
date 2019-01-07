#pragma once
#include "Virus.h"
#include <list>


class FluVirus : public Virus
{

private:
	int m_Color;

public:
	FluVirus();
	~FluVirus();
	
	void set_m_Color(int);
	int get_m_Color();

	void DoBorn() override;
	std::list<Virus*> FluVirus::DoClone() override;
	void DoDie() override;
	void InitResistance() override;

}