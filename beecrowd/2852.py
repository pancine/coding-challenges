# Python 3.4.3 31/08/2020
chave = input()
maximo = len(chave)
num_entradas = int(input())
vogais = ['a','e','i','o','u']
alfabeto = ['a','b','c','d','e','f','g','h','i','j',
            'k','l','m','n','o','p','q','r','s','t',
            'u','v','w','x','y','z']

for x in range(num_entradas):
    mensagem = input().split()
    i, j = 0, 0
    for palavra in mensagem:
        if palavra[0] in vogais:
            pass
        else:
            new = ''
            for x in range(len(palavra)):
                new += alfabeto[(ord(palavra[x]) - 97 + ord(chave[i]) - 97)%26]
                i += 1
                if i == maximo:
                    i = 0
            mensagem[j] = new
        j += 1
    for k in range(len(mensagem)-1):
        print(mensagem[k], end = " ")
    print(mensagem[len(mensagem)-1])
