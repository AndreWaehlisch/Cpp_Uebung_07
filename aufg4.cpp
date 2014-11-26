#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;
typedef unsigned long long int Ullong;


class myrandom
{
		Ullong a  ;
		Ullong a1 ;
		Ullong a2 ;
		Ullong a3 ;
		Ullong v ;

	public:

		Ullong x;

		myrandom ( const Ullong x0 = 0)
		{

			a  = 2685821657736338717LL;
			a1 = 21;
			a2 = 35;
			a3 = 4;
			v = 4101842887655102017LL;

			x =  x0 ^ v;
			nextrand();
		}


		void operator () ( const Ullong x0 )
		{
			x =  x0 ^ v;
			nextrand();
		}

		void xorshift ( )
		{
			x ^= ( x >> a1 ) ;
			x ^= ( x << a2 ) ;
			x ^= ( x >> a3 ) ;
		}

		void mlcg ( )
		{
			x = a * x; // c = 0 ,   x = mod 2^64 ( x ) , da  ( Ullong ) x < 2^64 für alle x
		}

		Ullong nextrand ()
		{
			xorshift();
			mlcg();
			return x;
		}

		void interval()
		{
			double alpha, beta, gamma;


			cout << "\nBitte Intervallgrenzen [a,b] eingeben. \na = ";
			cin >> alpha ;
			cout << "b = ";
			cin >> beta ;
			nextrand();

			gamma = (double) x ;
			gamma /= pow(2, 64) ;

			cout << "Interval: [" << alpha << " , " << beta << " ]" << endl;
			cout <<  alpha + gamma * ( beta - alpha)  << "\n"  << endl;
		}

};



int main ()
{
	Ullong x0;
	myrandom r;


	cout << "Bitte einen Anfangswert eingeben." << endl;
	cin  >> x0;
	r(x0);
	cout << r.x << endl;

	r.interval();


	ofstream file1("aufg4_spektral.3d", ios::trunc) ;

	for ( int i = 0 ; i < 30000 / 3; i++)
	{
		file1 << r.nextrand() << '\t' << r.nextrand() << '\t' << r.nextrand() <<  endl;

	}

	file1.close();

	ofstream file2("aufg4_spektral.2d", ios::trunc) ;

	for ( int i = 0 ; i < 30000 / 2; i++)
	{
		file2 << r.nextrand() << '\t' << r.nextrand() <<  endl;
	}

	file2.close();

	// In diesem Fall sind die Punkte homogen im Raum verteilt und keine (diskreten) Flächen erkennbar.

}
