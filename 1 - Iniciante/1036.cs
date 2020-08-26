//C# 5.10.1.20 25/08/2020
using System;

class MainClass {
   public static void Main (string[] args) {
      string[] numbers = (Console.ReadLine()).Split();
      double[] A = new double[3];
      
      for(int i = 0; i < 3; i++) {
         A[i] = Convert.ToDouble(numbers[i]);
      }

      double delta = Math.Sqrt(Math.Pow(A[1],2) - (4*A[0]*A[2]));

      if (Double.IsNaN((-A[1] + delta)/(2*A[0]))) {
         Console.WriteLine("Impossivel calcular");
      }
      else {
         Console.WriteLine($"R1 = {((-A[1] + delta)/(2*A[0])):N5}");
         Console.WriteLine($"R2 = {((-A[1] - delta)/(2*A[0])):N5}");
      }
   }
}
