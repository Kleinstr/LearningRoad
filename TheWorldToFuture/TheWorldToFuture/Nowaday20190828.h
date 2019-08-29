#pragma once
#include <iostream>
#include <time.h>
using namespace std;
void	GetLocalTimeAndDate()
{
	
	char temptime[128], tempdate[128];
	_strtime_s(temptime, 128);
	_strdate_s(tempdate, 128);
	cout << temptime << endl;
	cout << tempdate << endl;

}
int SwitchTest( char grade)
{
	
	switch (grade)
	{
	case 'A':
		cout << "Excellent" << endl;
		cout<<"Your Final Grade is "<<grade <<endl;
		break;
	case 'B':
		cout << "Not Bad " << endl;
		cout << "Your Final Grade is " << grade << endl;
		break;
	case 'C':
		cout << "Pass" << endl;
		cout << "Your Final Grade is " << grade << endl;
		break;
	case'D':
		cout << "Not Pass" << endl;
		cout << "Your Final Grade is " << grade << endl;
		break;
	default:
			cout << "Your grade is invalid" << endl;
	}
	return grade;
}