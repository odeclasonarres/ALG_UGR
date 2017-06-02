#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>



double uniforme() //Genera un n�mero uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}

int main(int argc, char * argv[]){
/*  int * V=new int[argc-1];
  int x;
  bool retorno=false;
std::cout << argc << '\n';
  for(int i=0;i<argc;i++){
    if(i==argc-2){
      x=atoi(argv[i]);
      cout << x << endl;
    }else{
      V[i]=atoi(argv[i]);
    }
  }
//std::cout << "X=" << x<< '\n';
*/

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
bool encontrado=false;
/*
for (int j=0; j<n; j++) {cout << T[j] << " ";}
cout << endl;
cout << k;
cout << endl;*/

  for (int i = 0; i < n; i++){
    for(int j=i+1;j<n;j++){
        if (T[j]+T[i]==k) {
          std::cout << "Encontrado:"<<T[i]<<"+"<<T[j]<<endl;
          j=n;
          i=n;
          encontrado=true;
        }
       }
    }

  if(encontrado==false){
    std::cout << "No encontrado"<<endl;
  }


}
