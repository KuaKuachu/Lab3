#include "sdt.h"
enum Error {     //перечисление для ошибок
	NoError,    //Нет ошибок
	ErrTemp,   //Ошибка в значении температуры
	ErrScale   // Неизвестная шкала
};

Error last_error = NoError;
Error get_last_error()
{
    return last_error;
}
double convert(double t, char from, char to)
{   double K,t1;
    if (to==from) return t;
    switch (from)
    {
    case 'k':
    case 'K': K=t; last_error=NoError; break;
    case 'C':
    case 'c': K=t+273.15; last_error=NoError; break;
    case 'F':
    case 'f': K=(5*(t-32))/9+273.15; last_error=NoError; break;
    default: last_error=ErrScale;
    }
    if (K<0) last_error=ErrTemp;

    if (K>=0)
    {  switch (to)
      {
        case 'C':
        case 'c': return (K-273.15); last_error=NoError; break;

        case 'F':
        case 'f': return ((9*(K-273.15))/5+32); last_error=NoError; break;

        case 'K':
        case 'k': return K; last_error=NoError; break;
        default: last_error=ErrScale ;
      }
    }
}

int main()
{
    double t,C,K,F;
    char s;
    vector<double> temp;
    vector<char> name;
    cout << "What is the scale of the temperature you need:Kelvin(10K),Celsius(10C) or Fahrenheit(10F)?";
    while (cin>>t>>s)
    {   C=convert(t,s,'C');
        F=convert(t,s,'F');
        K=convert(t,s,'K');
     switch (get_last_error())
        { case ErrScale: cerr <<"There isn't such scale!  \n";
                  break;
          case ErrTemp: cerr <<"Error, the temperature is low!\n";
                  break;
          default:
            temp.push_back(C);
            temp.push_back(K);
            temp.push_back(F);
        }
      cout << "What is the scale of the temperature you need:Kelvin(10K),Celsius(10C) or Fahrenheit(10F)? ";
    }
    cout <<"C \t" <<"K \t" <<"F \t \n";
    for (int i = 0; i < temp.size(); ++i)
    {
        printf("%4.2f\t", temp[i]);
        if ((i+1)%3==0) cout <<"\n";
    }
}
