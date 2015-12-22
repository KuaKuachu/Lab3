//------------------------------------------------------------------------------
//convert.h
//------------------------------------------------------------------------------
#pragma once
enum Scale
 {
   Kelvin='K',
   Celsius='C',
   Fahrenheit='F'
 };

struct Temperature //Описание структуры
{ Temperature(double value,char scale);
   Temperature();
  double value;
  char scale;
};
Temperature convert(Temperature t,char to);

