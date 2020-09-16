"""
O cálculo é feito baseado no peso(nível das questões) dividido pelo 
total de pontos.
Ex: Uma questão de nível 9 + uma de nível 5 geram 14 pontos no total.
"""

Python = 30
C = 242
Cs = 6
SQL = 4
Total = Python + C + Cs + SQL

pfile = open("README.md", "r")
list = pfile.readlines()

list[1] = "* Python = %.2f%c\n" % (Python * 100 / Total, "%")
list[2] = "* C = %.2f%c\n" % (C * 100 / Total, "%")
list[3] = "* C# = %.2f%c\n" % (Cs * 100 / Total, "%")
list[4] = "* SQL = %.2f%c\n" % (SQL * 100 / Total, "%")

pfile = open("README.md", "w")
pfile.writelines(list)
pfile.close()
