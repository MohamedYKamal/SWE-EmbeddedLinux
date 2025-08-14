#include <iostream>
#include <string>

constexpr int MaxAllowedAge = 150;
constexpr int MinAllowedAge = 0;

int main() 
{

   std::string UserAge;
   std::string UserName;

   do 
   {
      std::cout << "Please Enter a valid Name" << std::endl;

      UserName.clear();
      std::getline(std::cin, UserName);

      for(auto c:UserName) if (isdigit(c))
      {
         UserName.clear();
         break;
      }
   }while (UserName.empty());

   decltype(std::stoi("")) UserAgeNum;

   do
   {
      std::cout << "Please Enter a valid Age" << std::endl;

      UserAge.clear();
      std::getline(std::cin, UserAge);


      for(auto c:UserAge) if (!isdigit(c))
      {
         UserAge.clear();
         break;
      }

      if(!UserAge.empty())
      {
         UserAgeNum = std::stoi(UserAge);
      }

   }while ((UserAgeNum >= MaxAllowedAge) || (UserAgeNum <= MinAllowedAge));

   std::cout << "Hello " << UserName << ", you're " << UserAgeNum << " years old?" << std::endl;
   return 0;
}
