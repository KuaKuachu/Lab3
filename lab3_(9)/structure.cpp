#include "convert.h"
#include "sdt.h"
Temperature::Temperature()
{
    this->value = 0;
    this->scale = 'K';
}

Temperature::Temperature(double value, char scale)
{
    this->scale = scale;
    this->value = value;
}
istream& operator>>(istream& input,Temperature& data)
{ input >>data.value >>data.scale;
 return input;
}
