#include "convert.h"
#include "sdt.h"
Temperature::Temperature()
{
    this->value = 0;
    this->scale = Kelvin;
}

Temperature::Temperature(double value, Scale scale)
{
    this->scale = scale;
    this->value = value;
}
//------------------------------------------------------------------------------
istream& operator>>(istream& in, Scale& s)
{   char value;
    in >> value;
    switch (value)
    {
    case 'K':
    case 'k': s = Kelvin; break;
    case 'C':
    case 'c': s = Celsius; break;
    case 'F':
    case 'f': s = Fahrenheit; break;
    default: in.setstate(ios_base::failbit);//сообщаем об ошибке
             //throw invalid_argument("Incorrect nomination of scale! Try again!\n");
     }
    return in;
}
ostream& operator<<(ostream& out, const Scale& s)
{   switch (s)
    {
    case Fahrenheit: out << 'F'; break;
    case Celsius: out << 'C'; break;
    case Kelvin: out << 'K'; break;
    }
    return out;
}
//------------------------------------------------------------------------------
istream& operator>>(istream& in, Temperature& t)
{
    in >> t.value >> t.scale;
    return in;
}
ostream& operator<<(ostream& out, const Temperature& t)
{
    out << t.value << t.scale;
    return out;
}
//------------------------------------------------------------------------------
Temperature& Temperature::operator+=(const Temperature& scale1)
{
    if (this->scale == scale1.scale)
    {
        this->value += scale1.value;
    }
    else
    {
        Temperature temp = convert(scale1, this->scale);
        this->value += temp.value;
    }
    return *this;
}

Temperature& Temperature::operator/=(int d)
{
    this->value /= d;
    return *this;
}
//------------------------------------------------------------------------------
const Temperature& Temperature::operator+(const Temperature& scale1) const
{
    return (Temperature)(*this) += scale1;
}

const Temperature& Temperature::operator/(int d) const
{
    return (Temperature)(*this) /= d;

}
//------------------------------------------------------------------------------
bool Temperature::operator<(const Temperature &scale1) const
{
    if (this->scale == scale1.scale)
    {
        return this->value < scale1.value;
    }
    else
    {
        Temperature temp = convert(scale1, this->scale);
        return this->value < temp.value;
    }
}
//------------------------------------------------------------------------------
Temperature max_temp(vector<Temperature> temp)
{
    Temperature max_t = Temperature(0, Scale::Kelvin);
    for (int i = 0; i < temp.size(); i++)
    {
        if (max_t.value < temp[i].value)
        {
            max_t = temp[i];
        }
    }
    return max_t;
}
//------------------------------------------------------------------------------
Temperature mid_temp(vector<Temperature> temp)
{  Temperature mean = Temperature(0, Scale::Kelvin);

    for (int i = 0; i < temp.size(); i++)
    {
        mean += temp[i];
    }

    mean /= temp.size();
   return mean;
}


