#include <iomanip>
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

int main()
{
   auto NumberOfInputs = static_cast<int>(GetNumberFromUser("Please Enter the Number of inputs"));
   decltype(GetNumberFromUser(std::string())) MaxInputVal = 0;
   for (auto i = 0; i < NumberOfInputs; ++i)
   {
      std::string TempMsg;
      switch (i + 1)
      {
      case 1:
         TempMsg = "1st";
         break;
      case 2:
         TempMsg = "2nd";
         break;
      case 3:
         TempMsg = "3rd";
         break;
      default:
         TempMsg = std::to_string(i + 1) + "th";
         break;
      }

      auto TempNumber = GetNumberFromUser("Please Enter the " + TempMsg + " number");

      if (MaxInputVal < TempNumber)
      {
         MaxInputVal = TempNumber;
      }
   }

   std::cout << "The maximum input value is: " << std::fixed << std::setprecision(15) << MaxInputVal << std::endl;
   return 0;
}
