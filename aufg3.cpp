#include <iostream>
#include <fstream>
using namespace std;

class Rand
{
		int a, m, c;

	public:

		Rand(const int a_in = 4, const long m_in = 200L, const int c_in = 0)
		{
			a = a_in;
			m = m_in;
			c = c_in;
		}

		inline long operator() (const long x_in)
		{
			return (( a * x_in ) + c) % m;
		}
};

int main()
{
	Rand RNG;

	int x = 1;

	for ( int i = 0; i < 35; i++ )
	{
		x = RNG(x);
		cout << "i=" << i << " x_i=" << x << endl;
	}

	// Die Werte x_1 bis x_10 wiederholen sich periodisch für die gewählten Parameter (sodass also x_1 = x_11 etc.).

	cout << "-----" << endl;

	Rand RANDU(65539, (1L << 31));

	x = 1;

	ofstream file ("RANDU.txt", ios::trunc);

	for ( int i = 0; i < 30000; i++ )
	{
		x = RANDU(x);

		if ( i < 34 )
		{
			cout << "i=" << i << " x_i=" << x << endl;
		}

		switch (i % 3)
		{
			case 2:
				file << x << '\n';
				break;

			default:
				file << x << '\t';
				break;
		}
	}

	file.close();

	cout << "RANDU output in 'RANDU.txt' geschrieben." << endl;

	// Nein, die Punkte sind nicht "zufällig" im 3dim Raum verteilt! Es bilden sich die in der Vorlesung erwähnten Flächen eindeutig aus.
}
