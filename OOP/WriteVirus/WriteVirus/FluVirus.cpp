#include "FluVirus.h"
#include "Virus.h"
#include <iostream>

using namespace std;

FluVirus::FluVirus(){}

FluVirus::~FluVirus(){}

enum color
{
	RED = 1,
	BLUE = 2
};

void FluVirus::DoBorn()
{
	this->LoadADNInformation​();
}
void FluVirus::DoDie()
{
}
void FluVirus::InitResistance()
{
}