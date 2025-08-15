#include <cmath>
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

   return std::stod(Number);
}
namespace SavingsAccount
{
   double CurrentBalance = nan("");

   void createAccount(double initialBalance)
   {
      CurrentBalance = initialBalance;
   }

   void addInterest(double rate)
   {
      if (!isnan(CurrentBalance))
      {
         CurrentBalance *= (1 + rate);
      }
   }

   auto getBalance()
   {
      return CurrentBalance;
   }
}

namespace CheckingAccount
{
   double CurrentBalance = nan("");

   void createAccount(double initialBalance)
   {
      CurrentBalance = initialBalance;
   }

   void applyFee(double fee)
   {
      if (!isnan(CurrentBalance))
      {
         CurrentBalance -= fee;
      }
   }

   auto getBalance()
   {
      return CurrentBalance;
   }
}

int main()
{
   auto SavingAccountVal   = (GetNumberFromUser("Enter the saving account initial balance"));
   auto CheckingAccountVal = (GetNumberFromUser("Enter the checking account initial balance"));


   SavingsAccount::createAccount(SavingAccountVal);
   SavingsAccount::addInterest(0.05);
   SavingAccountVal = SavingsAccount::getBalance();


   CheckingAccount::createAccount(CheckingAccountVal);
   CheckingAccount::applyFee(50);
   CheckingAccountVal = CheckingAccount::getBalance();


   std::cout << "Saving account now has " << SavingAccountVal << std::endl;
   std::cout << "Checking account now has " << CheckingAccountVal << std::endl;
   return 0;
}
