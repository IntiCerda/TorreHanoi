#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

void torreHanoi(int n, stack<int>& origen, stack<int>& destino, stack<int>& auxiliar) {
    if (n == 1) {
        destino.push(origen.top());
        origen.pop();
        return;
    }
    torreHanoi(n - 1, origen, auxiliar, destino);
    destino.push(origen.top());
    origen.pop();
    torreHanoi(n - 1, auxiliar, destino, origen);
}

int main() {
    int n;
    cout << "Ingrese la cantidad de discos: ";
    cin >> n;
    stack<int> origen, destino, auxiliar;
    for (int i = n; i >= 1; i--) {
        origen.push(i);
    }
    torreHanoi(n, origen, destino, auxiliar);
    cout << "Los discos se han movido de la torre A a la torre C." << endl;
    return 0;
}