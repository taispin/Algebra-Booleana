00 {INN} 33
01 {LDA} 33
02 {STA} 48
03 {JLE} 50
04 {SUB} 34
05 {JGT} 50
06 {LDA} 33
07 {JLE} 22
08 {INN} 36
09 {LDA} 47
10 {ADD} 36
11 {STA} 47
12 {LDA} 36
13 {SUB} 37
14 {JGT} 40
15 {LDA} 36
16 {SUB} 38
17 {JLT} 43
18 {LDA} 33
19 {SUB} 35
20 {STA} 33
21 {JMP} 06
22 {PRN} 37
23 {PRN} 38
24 {LDA} 47
25 {DIV} 48
26 {STA} 46
27 {PRN} 46
28 {JMP} 50
29
30
31
32
33 +0005    ; Aqui fica K, o numero de inteiros que deve ser lido
34 +0010    ; Subtrai-se 10 do valor contido no acumulador (k)
35 +0001    ;Contador
36 +0000    ;Aqui fica o numero que foi recebido como entrada
37 -5000    ;Aqui fica o maior numero recebido
38 +5000    ;Aqui fica o menor numero recebido
39 {LDA} 30
40 {LDA} 36
41 {STA} 37
42 {JMP} 15
43 {LDA} 36
44 {STA} 38
45 {JMP} 17
46 +0000   ;Aqui fica a media aritmetica dos valores
47 +0000   ;Aqui fica a soma dos numeros recebidos como entrada
48 +0000   ;Aqui fica uma copia de k, para auxiliar no calculo da media aritmetica
49
50 {STP}










