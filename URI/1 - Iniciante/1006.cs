//C# 5.10.1.20 25/08/2020
using System;

class MainClass {
  public static void Main (string[] args) {
    double A = Convert.ToDouble(Console.ReadLine()) * 2;
    double B = Convert.ToDouble(Console.ReadLine()) * 3;
    double C = Convert.ToDouble(Console.ReadLine()) * 5;

    Console.WriteLine($"MEDIA = {((A+B+C)/10):N1}");
  }
}