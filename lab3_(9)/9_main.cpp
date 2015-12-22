#include "sdt.h"
#include "convert.h"
int main()
{ vector<Temperature> temp;
  Temperature input;
  input=Temperature();
  cout << "What is the scale of the temperature you need:Kelvin(10K),Celsius(10C) or Fahrenheit(10F)?";
    while (cin >>input.value >>input.scale)
    {   if (!cin) break;
        cout << "What is the scale of the temperature you need:Kelvin(10K),Celsius(10C) or Fahrenheit(10F)?";
        try
        {
          temp.push_back(convert(input,'C'));
          temp.push_back(convert(input,'K'));
          temp.push_back(convert(input,'F'));
        }
     catch (const invalid_argument& e)
			{
				cerr << e.what() << "\n";
			}
     catch (const logic_error& e)
			{
				cerr << e.what() << "\n";
			}
     catch (...)
			{
				cerr << "Unknown error! Try again! \n";
			}
        }


    cout <<"C \t" <<"K \t" <<"F \t \n";
    for (int i = 0; i < (temp.size()); ++i)
    {
        printf("%4.2f\t", temp[i]);
        if ((i+1)%3==0) cout <<"\n";
    }
}
