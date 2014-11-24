#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double phi_rec( int n )
{
	if ( n == 1 )
		return 0.618003398;
	else if ( n  == 0 )
		return 1 ;
	else
		return phi_rec( n - 2 ) - phi_rec( n - 1) ;
}


double phi_dir( int n )
{
	double phi = .5 * (sqrt(5) - 1) ;
	return pow(phi, n);
}

int main ()
{
	ofstream file ( "golden.dat" , ios::trunc ) ;


	for ( int n = 1 ; n < 101; n++)
		file << n << '\t' << phi_rec(n) << '\t' << phi_dir(n) << endl;


	file.close();

}
