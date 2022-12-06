#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct empleado {
  string nombre;
  double tarifa;
  int horas;
};
int main() {
  empleado emp[4];
  double pagoRegular[4], pagoTiempoExtra[4], pagoBruto[4];
  string nuevoarchivo = "trabajador.txt";
  ifstream archivo(nuevoarchivo);
  for (int i = 0; i < 4; i++) {
    archivo >> emp[i].nombre;
    archivo >> emp[i].tarifa;
    archivo >> emp[i].horas;

    pagoRegular[i] = emp[i].tarifa * emp[i].horas;
    if (emp[i].horas > 40) {
      pagoTiempoExtra[i] = (emp[i].horas - 40) * (emp[i].tarifa * 1.5);
    } else if (emp[i].horas <= 40) {
      pagoTiempoExtra[i] = 0;
    }
    pagoBruto[i] = pagoRegular[i] + pagoTiempoExtra[i];
  }
  cout << "Nombre\t\t"
       << "Tarifa Horas\t"
       << "Pago Regular\t"
       << "Pago de tiempo extra\t"
       << "Pago Bruto\n";
  for (int i = 0; i < 4; i++) {
    if(!(i==2)){
    cout << emp[i].nombre << "\t\t";
    cout << emp[i].tarifa << "\t\t\t\t";
    cout << pagoRegular[i] << "\t\t\t\t\t";
    cout << pagoTiempoExtra[i] << "\t\t\t\t\t";
    cout << pagoBruto[i] << "\n";
      }else if(i==2){
      cout << emp[i].nombre << "   \t";
    cout << emp[i].tarifa << "\t\t\t\t";
    cout << pagoRegular[i] << "\t\t\t\t";
    cout << pagoTiempoExtra[i] << "\t\t\t\t\t";
    cout << pagoBruto[i] << "\n";
    }
  }
}