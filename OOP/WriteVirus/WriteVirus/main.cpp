#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include "Patient.h"

using namespace std;

int main()
{
	//srand(time(0));

	Patient *p = new Patient;
	char t = '1';
	while (p->get_m_state() == 1)
	{
		printf("Take Medicine (0 = NO, 1 = YES) : ");
		cin >> t;
		if (t == '1')
		{
			p->TakeMedicine();
			
		}
		if ( t == '0' )
		{
			delete p;
			break;
		}
	}


	system("pause");
	return 0;
}