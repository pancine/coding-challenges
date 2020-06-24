Python = 15
C = 52
SQL = 4
Total = Python + C + SQL

pfile = open("README.md", "r")
list = pfile.readlines()

"""
O cálculo é feito baseado no peso(nível das questões) dividido pelo 
total de pontos.
Ex: Uma questão de nível 9 + uma de nível 5 geram 14 pontos no total.
"""

list[4] = "* Python = %.2f%c\n"%(Python*100/Total, "%")
list[5] = "* C = %.2f%c\n"%(C*100/Total,"%")
list[6] = "* SQL = %.2f%c\n"%(SQL*100/Total,"%")

pfile = open("README.md", "w")
pfile.writelines(list)
pfile.close()