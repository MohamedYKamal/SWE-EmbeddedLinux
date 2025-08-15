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

      for (auto c : Number)
      {
         if (!(isdigit(c) || c == '.'))
         {
            Number.clear();
            break;
         }
      }

      if (!Number.empty())
      {
         break;
      }
   } while (Number.empty());

   return std::stof(Number);
}


auto GetOperationFromUser(std::string msg)
{
   std::string Operation;

   do
   {
      std::cout << msg << std::endl;

      Operation.clear();
      std::getline(std::cin, Operation);

   } while ((Operation != "+" && Operation != "-" && Operation != "*" && Operation != "/"));

   return Operation;
}

int main()
{
   auto FirstNumberNum  = GetNumberFromUser("Please Enter the 1st number");
   auto SecondNumberNum = GetNumberFromUser("Please Enter the 2nd number");

   auto Operation = GetOperationFromUser("Please Enter the operation (+, -, *, /)");
   if (Operation == "+")
   {
      std::cout << "The sum is: " << (FirstNumberNum + SecondNumberNum) << std::endl;
   }
   else if (Operation == "-")
   {
      std::cout << "The difference is: " << (FirstNumberNum - SecondNumberNum) << std::endl;
   }
   else if (Operation == "*")
   {
      std::cout << "The product is: " << (FirstNumberNum * SecondNumberNum) << std::endl;
   }
   else if (Operation == "/")
   {
      while (SecondNumberNum == 0)
      {
         SecondNumberNum = GetNumberFromUser("Please Enter the 2nd number AGAIN");
      }

      std::cout << "The quotient is: " << static_cast<double>(FirstNumberNum) / SecondNumberNum << std::endl;
   }
   return 0;
}
