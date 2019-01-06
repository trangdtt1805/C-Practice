#include "Virus.h"
#include <string>

using namespace std;

Virus::Virus(){}

Virus::~Virus(){}

void Virus::LoadADNInformation​()
{

}
void Virus::ReduceResistance​(int medicine_resistance)
{

}
void Virus::set_m_dna(char* m_dna)
{
	this->m_dna = m_dna;
}
char* Virus::get_m_dna()
{
	return m_dna;
}
void Virus::set_m_resistance(int m_resistance)
{
	this->m_resistance = m_resistance;
}
int Virus::get_m_resistance()
{
	return m_resistance;
}
