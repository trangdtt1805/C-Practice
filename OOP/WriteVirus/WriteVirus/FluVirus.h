#pragma once
#include "Virus.h"
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
	void DoDie() override;
	void InitResistance() override;

}

