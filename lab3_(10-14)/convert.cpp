#include "sdt.h"
#include "convert.h"
Temperature convert(Temperature t, Scale to)
 {  double K;
    Scale from=t.scale;
    Temperature result;
    if (to==from)
    {result.value=t.value;
     result.scale=to;
    }
    switch (from)
    {
    case Kelvin: K=t.value; break;
    case Celsius: K=t.value+273.15; break;
    case Fahrenheit: K=(5*(t.value-32))/9+273.15; break;
    default: throw invalid_argument("There isn't such scale!\n");
    }
    if (K<0) throw logic_error("Error, the temperature is low!\n");

    if (K>=0)
    {  switch (to)
      {
        case Celsius:
             result.value=(K-273.15);
             result.scale=to;
             break;
        case Fahrenheit:
              result.value=(9*(K-273.15))/5+32;
              result.scale=to;
              break;
        case Kelvin:
              result.value=K;
              result.scale=to;
              break;
        default: throw invalid_argument("There isn't such scale!\n");
      }
    }
    return result;
    throw exception();
}
