# Python 3.4.3 30/06/2019
valor = int(input())
i = 0
while valor > 0:
	i += 1
	cinq, valor = valor//50, valor%50
	dez, valor = valor//10, valor%10
	cinco, valor = valor//5, valor%5
	um = valor//1
	print("Teste {:d}\n{:d} {:d} {:d} {:d}\n".format(i, cinq, dez, cinco, um))
	valor = int(input())