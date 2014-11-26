#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;
/* echt rekursive Implementierung -> ab ca. n > 40 zu langsam
double phi_rec( int n )
{
	if ( n == 1 )
	  return 0.618003398;
	else if ( n == 0 )
	  return 1;
	else if ( n < 0 )
	  exit ( 1 ) ;
	else
	  return phi_rec( n - 2 ) - phi_rec( n - 1) ;
}
*/


double phi_rec( int m )
{

	double nM1 = 1;
	double n =  0.618003398;
	double nP1 = nM1 - n;

	if ( m  == 0 )
		return 1;
	else if ( m == 1 )
		return  0.618003398;
	else if ( m > 1 )
	{

		for (int i = 1 ; i <= m  ; i++ )
		{
			nP1 = nM1 - n;
			nM1 = n;
			n   = nP1;
		}

		return nP1;
	}
	else if ( m < 0)
	{
		for (int i = -1 ; i >= m ; i--)
		{
			nM1 = nP1 + n;
			nP1 = n;
			n = nM1 ;
		}

		return nM1;
	}

}





double phi_dir( int n )
{
	double phi = .5 * (sqrt(5) - 1) ;
	return pow(phi, n);
}

int main ()
{
	ofstream file ( "golden.dat" , ios::trunc ) ;

	for ( int n = -100 ; n < 100; n++)
		file << n << '\t' << phi_rec(n) << '\t' << phi_dir(n) << endl;


	file.close();

}
