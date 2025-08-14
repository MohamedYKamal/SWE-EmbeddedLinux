#include <cmath>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>



auto GetInputFromUser(std::string msg, std::function<bool(std::string)> func)
{
   std::string Input;

   do
   {
      std::cout << msg << std::endl;

      Input.clear();
      std::getline(std::cin, Input);

   }while (!func(Input));

   return Input;
}

auto GetDoubleFromUser(std::string msg, std::function<bool(double)> LimitsFunct = nullptr)
{
   double numberConverted;

   do 
   {
      std::string Number = GetInputFromUser(msg, [](const std::string& s) {
                                                                                       for (char c : s) {
                                                                                          if (!(isdigit(c) || c == '.')) return false;
                                                                                       }
      return true;
      });

      numberConverted = std::stod(Number);
   }while ((LimitsFunct != nullptr) && (LimitsFunct(numberConverted) == false));

   return numberConverted;
}





auto ShapesInputVerification(std::string x)
{
   return (( x == "R") ||
           ( x == "T") ||
           ( x == "C") 
         ) ;
}

int main()
{
   auto InputShapeMsg = std::string("Enter the shape \n")
                                    + "    1- (R)ectangle\n"
                                    + "    2- (T)riangle\n"
                                    + "    3- (C)ircle\n";

   auto Shape = GetInputFromUser(InputShapeMsg, ShapesInputVerification);
   
   double Area;
   std::string msg;

   if(Shape == "R")
   {
      auto Width = GetDoubleFromUser("Input Width (double)");
      auto Hight = GetDoubleFromUser("Input Hight (double)");
      Area = Width * Hight;
      msg = "Rectangle";
   }
   else if (Shape == "T")
   {
      auto SideA = GetDoubleFromUser("Input SideA (double)");
      auto SideB = GetDoubleFromUser("Input SideB (double)");
      auto Angle = GetDoubleFromUser("Input Angle (double)", [](double x){
         if ((x <= 180) && (x >= 0))
         {
            return true;
         }
         else
         {
            return false;
         }
      });
      double angle_radians = Angle * M_PI / 180.0;
      Area = 0.5 * SideA * SideB * sin(angle_radians);
      msg = "Triangle";
   }
   else 
   {
      auto Diameter = GetDoubleFromUser("Input Diameter (double)");
      msg = "Circle";
      Area = Diameter * Diameter / 4 * M_PI;
   }
   std::cout << "The Area of "<< msg << " is: " << Area << std::endl;
   return 0;
}
