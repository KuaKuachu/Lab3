//------------------------------------------------------------------------------
//convert.h
// «аголовочный файл с объ€влени€ми.
//------------------------------------------------------------------------------
#include "sdt.h"
enum Scale //ќписание перечислени€
 {
   Kelvin='K',
   Celsius='C',
   Fahrenheit='F'
 };

struct Temperature //ќписание структуры
{  Temperature(double value,Scale scale);
   Temperature();
   const Temperature& operator+(const Temperature& scale1) const;
   const Temperature& operator/(int d) const;
   bool operator<(const Temperature &scale1) const;
   Temperature& operator+=(const Temperature& scale1);
   Temperature& operator/=(int d);
   double value;
   Scale scale;
};
Temperature convert(Temperature t,Scale to); //объ€вление функции конвертации

istream& operator>>(istream& in, Temperature& t);//объ€влени€ функции польз.ввода
ostream& operator<<(ostream& out, const Temperature& t); //объ€влени€ функции польз.вывода

istream& operator>>(istream& in, Scale& s);
ostream& operator<<(ostream& out, const Scale& s);

Temperature max_temp(vector<Temperature> temp);
Temperature mid_temp(vector<Temperature> temp);




