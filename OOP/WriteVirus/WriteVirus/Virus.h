#pragma once
class Virus
{
private:
	char* m_dna;
	int m_resistance;
public:
	Virus();
	~Virus();

	void LoadADNInformation​();
	void ReduceResistance​(int medicine_resistance);

	virtual void DoBorn() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;

	void set_m_dna(char*);
	char* get_m_dna();
	void set_m_resistance(int);
	int get_m_resistance();

};

