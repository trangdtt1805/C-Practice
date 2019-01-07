#pragma once

#include <vector>

class Virus
{

private:
	char* m_dna;
	int m_resistance;

public:
	Virus();
	~Virus();

	Virus(const Virus *);

	void LoadADNInformation​();
	int ReduceResistance​(int);

	virtual void DoBorn() = 0;
	virtual std::vector<Virus*> Virus::DoClone() = 0;	
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;

	void set_m_dna(char*);
	char* get_m_dna();
	void set_m_resistance(int);
	int get_m_resistance();

};

