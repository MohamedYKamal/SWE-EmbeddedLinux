#include <iostream>
#include <string>

auto GetNumberFromUser(std::string msg)
{
   std::string Number;

   do
   {
      std::cout << msg << std::endl;

      Number.clear();
      std::getline(std::cin, Number);


      for(auto c:Number) if (!isdigit(c))
      {
         Number.clear();
         break;
      }

      if(!Number.empty())
      {
         break;
      }
   }while (Number.empty());

   return std::stoi(Number);
}

auto Factorial(int n)
{
   if (n <= 1) return 1;

   return n * Factorial(n - 1);
}


int main()
{
   auto Input = static_cast<int>(GetNumberFromUser("Inter the Integer Positive Number"));


   auto FactorialValue = Factorial(Input);

   std::cout << "Factorial of " <<  Input << " is: " << FactorialValue << std::endl;
   return 0;
}
