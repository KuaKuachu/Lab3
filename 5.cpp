#include "sdt.h"
double convert(double t, char from, char to)
{   double K,t1;
    if (to==from) return t;
    switch (from)
    {
    case 'k':
    case 'K': K=t;
              break;
    case 'C':
    case 'c': K=t+273.15;
              break;
    case 'F':
    case 'f': K=(5*(t-32))/9+273.15;
              break;
    default: throw invalid_argument("There isn't such scale!\n");
    }
    if (K<0) throw logic_error("Error, the temperature is low!\n");

    if (K>=0)
    {  switch (to)-K
      {
        case 'C':
        case 'c': return (K-273.15); break;

        case 'F':
        case 'f': return ((9*(K-273.15))/5+32); break;

        case 'K':
        case 'k': return K; break;
        default: throw invalid_argument("There isn't such scale!\n");
      }
    }
    throw exception();
}

int main()
{
    double t;
    char s;
    vector<double> temp;
    vector<char> name;
    cout << "What is the scale of the temperature you need:Kelvin(10K),Celsius(10C) or Fahrenheit(10F)?";
    while (cin>>t>>s)
    {   try
        {
          temp.push_back(convert(t,s,'C'));
          temp.push_back(convert(t,s,'F'));
          temp.push_back(convert(t,s,'K'));
        }
     catch (const invalid_argument& e)
			{
				cerr << e.what() << "\n";
			}
     catch (const logic_error& le)
			{
				cerr << le.what() << "\n";
			}
     catch (...)
			{
				cerr << "Unknown error! Try again! \n";
			}
            cout << "What is the scale of the temperature you need:Kelvin(10K),Celsius(10C) or Fahrenheit(10F)?";
        }

    cout <<"C \t" <<"K \t" <<"F \t \n";
    for (int i = 0; i < temp.size(); ++i)
    {
        printf("%4.2f\t", temp[i]);
        if ((i+1)%3==0) cout <<"\n";
    }
}
