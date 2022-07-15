//C# 5.10.1.20 25/08/2020
using System;

class MainClass {
  public static void Main (string[] args) {
    double A = Convert.ToDouble(Console.ReadLine()) * 3.5;
    double B = Convert.ToDouble(Console.ReadLine()) * 7.5;
    Console.WriteLine($"MEDIA = {((A+B)/11):N5}");
  }
}