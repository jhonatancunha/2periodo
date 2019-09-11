def validacao(entrada):
    for x in entrada:
        if x > 1 or x < 0:
            return False


def funcao_OR(*entrada):
    if validacao(entrada) == False:
        return False

    aux = 0
    for x in entrada:
        aux = x or aux
    return aux

def funcao_AND(*entrada):
    if validacao(entrada) == False:
        return False

    aux = 1
    for x in entrada:
        aux = x and aux
    return aux

def funcao_NOT(a):
    if a > 1 or a < 0:
        return False

    if a == 0:
        return 1
    else:
        return 0

def funcao_NAND(*entrada):
    if validacao(entrada) == False:
        return False

    i = funcao_AND(*entrada)
    return funcao_NOT(i)

def funcao_NOR(*entrada):
    if validacao(entrada) == False:
        return False

    i = funcao_OR(*entrada)
    return funcao_NOT(i)

def funcao_XOR(*entrada):
    if validacao(entrada) == False:
        return False

    s = 0
    for x in entrada:
        if s != x:
            s = 1
        else:
            s = 0
    return s

def funcao_XNOR(*entrada):
    if validacao(entrada) == False:
        return False

    s = 1
    for x in entrada:
        if s == x:
            s = 1
        else:
            s = 0
    return s

def main():
    #Exercicio 1
    a1 = 0
    b1 = 1
    c1 = 0
    s00 = funcao_NOR(a1, funcao_NOT(b1), c1)
    s01 = funcao_OR(a1, funcao_NOT(b1), c1)
    s02 = funcao_NAND(s00, s01)
    s1f = funcao_AND(s02, funcao_NOT(a1), b1, funcao_NOT(c1))
    print('Exercicio 1: ', s1f)

    #Exercicio 2
    a2 = 1
    b2 = 1
    c2 = 1
    d2 = 1

    s02 = funcao_NOR(b2,c2)
    s03 = funcao_NOR(funcao_NOT(a2), s02, d2)
    s04 = funcao_AND(funcao_NOT(b2),d2)
    s05 = funcao_NAND(s04, funcao_NOT(d2))
    s6f = funcao_OR(s03, funcao_NOT(d2), s05)
    print('Exercicio 2: ', s6f)

    #Exercicio 5
    a5 = 0
    b5 = 1
    c5 = 1
    d5 = 1

    s055 = funcao_OR(funcao_NOT(a5), funcao_NOT(b5))


    s056 = funcao_NOR(a5, funcao_NOT(d5))
    s057 = funcao_AND(b5, s056)
    s058 = funcao_AND(funcao_NOT(a5), b5, funcao_NOT(c5))
    s059 = funcao_AND(b5, funcao_NOT(c5))
    s0510 = funcao_AND(funcao_NOT(b5), d5)
    s0511 = funcao_NOR(s057, s058, s059, s0510)

    s0512 = funcao_XOR(b5, c5)
    s0513 = funcao_AND(s0511, s0512)

    s0514 = funcao_AND(a5, b5, d5)
    s0515 = funcao_NOR(funcao_NOT(b5), s0513, s0514)
    s05f = funcao_AND(s055, s0515)
    print('Exercicio 5: ', s05f)


    #Exercicio 11
    a11 = 1
    b11 = 1
    c11 = 0
    d11 = 0
    s011 = funcao_AND( funcao_NOT(a11), funcao_NOT(b11), funcao_NOT(c11), funcao_NOT(d11) )
    s0112 = funcao_AND( funcao_NOT(a11), b11, funcao_NOT(c11), funcao_NOT(d11) )
    s0113 = funcao_AND( funcao_NOT(a11), b11, c11, funcao_NOT(d11) )
    s0114 = funcao_AND( a11, b11, funcao_NOT(c11), d11 )
    s0115 = funcao_AND( a11, b11, c11, d11)
    s011f = funcao_OR( s011, s0112, s0113, s0114, s0115 )
    print('Exercicio 11: ', s011f)


    #Exercicio 12
    a12 = 1
    b12 = 0
    c12 = 0
    d12 = 0

    s012 = funcao_AND( funcao_NOT(a12), b12, funcao_NOT(c12), funcao_NOT(d12) )
    s0122 = funcao_AND( funcao_NOT(a12), b12, c12, funcao_NOT(d12) )
    s0123 = funcao_AND( a12, funcao_NOT(b12), funcao_NOT(c12), funcao_NOT(d12) )
    s0124 = funcao_AND( a12, funcao_NOT(b12), c12, d12 )
    s012f = funcao_OR( s012, s0122, s0123, s0124 )
    print('Exercicio 12: ', s012f)



    #Exercicio 26
    a126 = 0
    b126 = 1
    c126 = 1

    s261 = funcao_AND( funcao_NOT(a126), b126, c126 )
    s262 = funcao_AND( a126, b126, funcao_NOT(c126) )
    s263 = funcao_AND( a126, b126, c126 )
    s264 = funcao_AND( a126, funcao_NOT(b126), c126 )
    s26f = funcao_OR(s261, s262, s263, s264)
    print('Exercicio 26: ', s26f)


    #Exercicio 27
    #Ou Exclusivo usando so a porta NOR
    a27 = 1
    b27 = 0

    s271 = funcao_NOR(a27, funcao_NOR(b27, b27))
    s272 = funcao_NOR( funcao_NOR(a27, a27), b27 )
    s273 = funcao_NOR(s271,s272)
    s27f = funcao_NOR(s273, s273)
    print('Exercicio 27: ', s27f)



    #Exercicio 28
    #Ou Exclusivo usando so a porta NAND
    a28 = 0
    b28 = 1

    s281 = funcao_NAND( funcao_NAND(a28,a28), b28 )
    s282 = funcao_NAND( funcao_NAND(b28,b28), a28 )
    s28f = funcao_NAND( s281,s282 )
    print('Exercicio 28: ', s28f)


    #Exercicio 29
    a29 = 0
    b29 = 1
    c29 = 1

    xnor1 = funcao_NOR(b29, funcao_NOT(c29))
    xnor2 = funcao_NOR(funcao_NOT(b29), c29)
    xnor3 = funcao_NOR( xnor1, xnor2)
    xnor4 = funcao_NOR(xnor3)
    xnor5 = funcao_NOR(xnor4)
    xnorFim = funcao_NOR(xnor5)


    um_Um = funcao_NOR(a29, c29)
    um_Dois = funcao_NOR(um_Um, funcao_NOT(b29))

    tres = funcao_NOR(a29, b29, funcao_NOT(c29))

    fAnd = funcao_NOR(tres, xnorFim)

    fAntEnd = funcao_NOR( fAnd, um_Dois, a29)
    fFIm = funcao_NOT(fAntEnd)
    print('Exercicio 29: ', fFIm)


if __name__ == "__main__":
    main()
