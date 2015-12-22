#include "sdt.h"
#include "convert.h"

int main()
{
    vector<double> temp;
    vector<char> name;

    double t;
    char s;
    Scale s1;
    cout << "What is the scale of the temperature you need:Kelvin(10K),Celsius(10C) or Fahrenheit(10F)?: ";
    while (cin>>t>>s)
    {   try
        { s1=to_scale(s);
          temp.push_back(convert(t,s1,Celsius));
          temp.push_back(convert(t,s1,Kelvin));
          temp.push_back(convert(t,s1,Fahrenheit));
        }
     catch (const invalid_argument& e)
			{
				cerr << e.what() << "\n";
			}
     catch (const logic_error& le)
			{
				cerr << le.what() << "\n";
			}
    catch (const invalid_argument& le)
			{
				cerr << le.what() << "\n";
			}
     catch (...)
			{
				cerr << "Unknown error! Try again! \n";
			}
            cout << "What is the scale of the temperature you need:Kelvin(10K),Celsius(10C) or Fahrenheit(10F)? ";
        }

    cout <<"C \t" <<"K \t" <<"F \t \n";
    for (int i = 0; i < temp.size(); ++i)
    {
        printf("%4.2f\t", temp[i]);
        if ((i+1)%3==0) cout <<"\n";
    }
}
