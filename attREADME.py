Python = 5
C = 15
SQL = 2
Total = Python + C + SQL

pfile = open("README.md", "r")
list = pfile.readlines()

list[4] = "* Python = %.2f%c\n"%(Python*100/Total, "%")
list[5] = "* C = %.2f%c\n"%(C*100/Total,"%")
list[6] = "* SQL = %.2f%c\n"%(SQL*100/Total,"%")

pfile = open("README.md", "w")
pfile.writelines(list)
pfile.close()