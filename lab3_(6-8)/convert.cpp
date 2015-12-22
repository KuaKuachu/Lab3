#include "sdt.h"
#include "convert.h"
Scale to_scale(char s)
{   switch (s)
      {case 'c':
       case 'C': return Celsius; break;
       case 'F':
       case 'f': return Fahrenheit; break;
       case 'K':
       case 'k': return Kelvin; break;
       default: throw invalid_argument("There isn't such scale!\n");
       }
}
double convert(double t, Scale from, Scale to)
 {  double K;

    if (to==from) return t;
    switch (from)
    {
    case Kelvin: K=t; break;
    case Celsius: K=t+273.15; break;
    case Fahrenheit: K=(5*(t-32))/9+273.15; break;
    default: throw invalid_argument("There isn't such scale!\n");
    }
    if (K<0) throw logic_error("Error, the temperature is low!\n");

    if (K>=0)
    {  switch (to)
      {
        case Celsius: return (K-273.15); break;
        case Fahrenheit: return ((9*(K-273.15))/5+32); break;
        case Kelvin: return K; break;
        default: throw invalid_argument("There isn't such scale!\n");
      }
    }
    throw exception();
}
