#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

//generador de ejemplos para el problema de la suma de dos elementos. Simplemente, para rellenar el vector de tama�o n genera n enteros aleatorios entre 0 y 2*n-1, y adem�s genera un entero (la posible suma) entre 0 y 3*n-1

double uniforme() //Genera un n�mero uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}

int main(int argc, char * argv[])
{

  if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

  int n = atoi(argv[1]);

  int * T = new int[n];
  assert(T);

srand(time(0));
//para generar un vector que pueda tener elementos repetidos
for (int j=0; j<n; j++) {
  double u=uniforme();
  int k=(int)(2*n*u);
  T[j]=k;
}
double u=uniforme();
int k=(int)(3*n*u);

for (int j=0; j<n; j++) {cout << T[j] << " ";}
cout << endl;
cout << k;
cout << endl;
} 
