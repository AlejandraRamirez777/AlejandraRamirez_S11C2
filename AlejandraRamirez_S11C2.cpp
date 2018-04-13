#include <iostream>

using namespace std;

//Constantes
const float G = 1.0;

//Funciones
double func1(double v);
double func2(double m1, double m2,double d);


//Clase Planeta
class Planeta{
   public:
    double m;
    double x;
    double Vx;
};

int main () {
   //inicializa objetos de clase Planeta
    Planeta P1;
    P1.m = 100.0;
    P1.x = 5.0;
    P1.Vx = 0.0;

    Planeta P2;
    P2.m = 1.0;
    P2.x =-5.0;
    P2.Vx = 0.0;

    double h=0.01;
    double min_x = 0.0;
    double max_x = 6.0;
    int N = int((max_x-min_x)/h);
    double x[N];
    //double y_1[N];
    double y_2[N];

    //Condiciones iniciales
    x[0] = min_x;
    y_1[0] = 1.0;
    y_2[0] = 0.0;


     for (int i = 0; i < N; i++) {
    //primeras derivadas
    //double y_p1 = func1(x[i-1], y_1[i-1], y_2[i-1]);
    double y_p2 = func2(x[i-1], y_1[i-1], y_2[i-1]);
    

    x[i] = x[i-1] + h;
    //y_1[i] = y_1[i-1] + h * func1(x[i-1], y_1[i-1], y_2[i-1]);
    y_2[i] = y_2[i-1] + h * func2(x[i-1], y_1[i-1], y_2[i-1]);
    }

   return 0;
}

double func1(double v){
   double sol = v;
   return sol;
}

double func2(double m1, double m2,double d){
   double sol = (-G*m1*m2)/(d*m1);
   return sol;
}

