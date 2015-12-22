#include "sdt.h"
#include "convert.h"
int main()
{ vector<Temperature> temp, temp_K;
  Temperature input;
  cout << "What is the scale of the temperature you need:Kelvin(10K),Celsius(10C) or Fahrenheit(10F)?  ";
    while (cin >>input)
    {   if (!cin) break;
        try
        {
          temp.push_back(convert(input,Celsius));
          temp.push_back(convert(input,Kelvin));
          temp.push_back(convert(input,Fahrenheit));
          temp_K.push_back(convert(input,Kelvin));
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
     cout << "What is the scale of the temperature you need:Kelvin(10K),Celsius(10C) or Fahrenheit(10F)?  ";
        }

    cout <<"C \t" <<"K \t" <<"F \t \n";
    ofstream out("convert_temp.txt", ios_base::trunc); //перед записью файл очищается
    out <<"C \t" <<"K \t" <<"F \t \n";
    for (int i = 0; i < (temp.size()); ++i)
    {
        printf("%4.2f\t", temp[i]);
        out <<temp[i]<<"\t";
        if ((i+1)%3==0)
        {
            cout <<"\n";
            out <<"\n";
        }

    }
 out <<"\nMaximum temperature is: " << max_temp(temp_K) <<"\n";
 out << "Mid temperature is: " << mid_temp(temp_K)<<"\n";
 out.close();
 cout <<"\nMaximum temperature is: " << max_temp(temp_K) <<"\n";
 cout << "Mid temperature is: " << mid_temp(temp_K)<<"\n";
}
