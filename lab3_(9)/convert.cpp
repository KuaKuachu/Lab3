#include "sdt.h"
#include "convert.h"
Temperature convert(Temperature t, char to)
 {  double K;
    char from=t.scale;
    Temperature result;
    if (to==from)
    {result.value=t.value;
     result.scale=to;
    }
    switch (from)
    {
    case 'K':
    case 'k': K=t.value; break;
    case 'C':
    case 'c': K=t.value+273.15; break;
    case 'F':
    case 'f': K=(5*(t.value-32))/9+273.15; break;
    default: throw invalid_argument("There isn't such scale!\n");
    }
    if (K<0) throw logic_error("Error, the temperature is low!\n");

    if (K>=0)
    {  switch (to)
      {
        case 'C':
        case 'c':
             result.value=(K-273.15);
             result.scale=to;
             break;
        case 'F':
        case 'f':
              result.value=(9*(K-273.15))/5+32;
              result.scale=to;
              break;
        case 'K':
        case 'k':
              result.value=K;
              result.scale=to;
              break;
        default: throw invalid_argument("There isn't such scale!\n");
      }
    }
    return result;
    throw exception();
}
