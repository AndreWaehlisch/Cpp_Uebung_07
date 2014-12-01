#include <iostream>
#include <cmath>
using namespace std;

int goodNumber(const double in)
{
	if ( isinf(in) )
	{
		return 0;
	}

	if ( isnan(in) )
	{
		return 0;
	}

	return 1;
}

int isEplus(const double input)
{
	if ( (1 + input) - 1 == 0 )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int isEminus(const double input)
{
	if ( (1 - input) - 1 == 0 )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	cout.precision(20);

	cout << "Good number?" << endl;
	cout << "7: " << goodNumber(7) << endl;	// ja
	cout << "Sqrt(-1): " << goodNumber(sqrt(-1)) << endl; // nein
	cout << "Ln(+0.): " << goodNumber(log(+0.)) << endl; // nein
	cout << "Ln(-0.): " << goodNumber(log(-0.)) << endl; // nein
	cout << "1./0.: " << goodNumber(1. / 0.) << endl; // nein
	cout << "Tan(Pi/2): " << goodNumber(tan(M_PI / 2.)) << endl; // (wegen numerischem Fehler, hier fälschlicherweise:) ja

	////////////////////////////

	if ( sqrt(-1) == sqrt(-1) )
	{
		cout << "nan ist gleich nan!" << endl;
	}
	else
	{
		cout << "nan ist NICHT gleich nan!" << endl;
	}

	if ( 1. / 0. == 1. / 0. )
	{
		cout << "inf ist gleich inf!" << endl;
	}
	else
	{
		cout << "inf ist NICHT gleich inf!" << endl;
	}

	// nan ist NICHT gleich nan, aber inf ist gleich inf für den obigen Test

	////////////////////////////

	double eplus = pow(2, -60);

	while ( 1 )
	{
		if ( isEplus(eplus) )
		{
			cout << "Eplus gefunden:  " << eplus << endl;
			break;
		}
		else
		{
			eplus *= 2;
		}
	}

	double eminus = pow(2, -60);

	while ( 1 )
	{
		if ( isEminus(eminus) )
		{
			cout << "Eminus gefunden: " << eminus << endl;
			break;
		}
		else
		{
			eminus *= 2;
		}
	}

	// Eplus  ~ 2.22*10^(-16)
	// Eminus ~ 1.11*10^(-16)
	// Die beiden Werte unterscheiden sich um den Faktor 2. Für den Test mit Eminus ist das Ergebnis demnach numerisch besser.
}
