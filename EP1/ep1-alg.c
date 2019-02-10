/* *******************************************************/
/*                                                       */
/*        Bárbara de Castro Fernandes - 7577351          */
/*        Erika Midori Akabane - 7557032                 */
/*        Joana Oliveira de Melo Silva - 7577473         */
/*        Taís Aparecida Pereira Pinheiro - 7580421      */
/*                                                       */
/* ***************************************************** */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAMANHO 100
#define TRUE 1
#define FALSE 0


/* ** Lista de comandos válidos ** */
char *comandos[] = {"LDA", "STA", "ADD", "SUB", "MUL", "DIV", "REM", "INN", "PRN",
                    "JMP", "JLE", "JDZ", "JGT", "JEQ", "JLT", "JGE", "REV", "STP", "NOP"
                   };

/* ** Recebe uma string e o seu tamanho e devolve a string limpa ** */
char *limpaString(char *string, int tamanho)
{
    int i = 0;
    while(i < tamanho)
        string[i++] = '\0';
    return string;
}

/* ** Recebe uma string com uma instrução, identifica-a e devolve uma outra string com
    o valor correspondente ** */
char *traduzComando(char *instrucao)
{
    int i = 0, j = 0;
    /* ** A string alocada é da forma "+IIEE", onde I representa a instrução e E o endereço ** */
    char *string = malloc(5 * sizeof(char));
    string[j++] = '+';
    while(i < 19)
    {
        /* Identifica a instrução na lista */
        if(strcmp(comandos[i], instrucao) == 0)
        {
            switch(i)
            {
                /*LDA*/
            case 0:
                strncpy(&string[j], "11", 2);
                j += 2;
                break;

                /*STA*/
            case 1:
                strncpy(&string[j], "12", 2);
                j += 2;
                break;

                /*ADD*/
            case 2:
                strncpy(&string[j], "21", 2);
                j += 2;
                break;

                /*SUB*/
            case 3:
                strncpy(&string[j], "22", 2);
                j += 2;
                break;

                /*MUL*/
            case 4:
                strncpy(&string[j], "23", 2);
                j += 2;
                break;

                /*DIV*/
            case 5:
                strncpy(&string[j], "24", 2);
                j += 2;
                break;

                /*REM*/
            case 6:
                strncpy(&string[j], "25", 2);
                j += 2;
                break;

                /*INN*/
            case 7:
                strncpy(&string[j], "31", 2);
                j += 2;
                break;

                /*PRN*/
            case 8:
                strncpy(&string[j], "41", 2);
                j += 2;
                break;

                /*JMP*/
            case 9:
                strncpy(&string[j], "51", 2);
                j += 2;
                break;

                /*JLE*/
            case 10:
                strncpy(&string[j], "52", 2);
                j += 2;
                break;

                /*JDZ*/
            case 11:
                strncpy(&string[j], "53", 2);
                j += 2;
                break;

                /*JGT*/
            case 12:
                strncpy(&string[j], "54", 2);
                j += 2;
                break;

                /*JEQ*/
            case 13:
                strncpy(&string[j], "55", 2);
                j += 2;
                break;

                /*JLT*/
            case 14:
                strncpy(&string[j], "56", 2);
                j += 2;
                break;

                /*JGE*/
            case 15:
                strncpy(&string[j], "57", 2);
                j += 2;
                break;

                /*REV*/
            case 16:
                strncpy(&string[j], "29", 2);
                j += 2;
                break;

                /*STP*/
            case 17:
                strncpy(&string[j], "7000", 4);
                j += 4;
                break;

                /*NOP*/
            case 18:
                strncpy(&string[j], "5000", 4);
                j += 4;
                break;
            }
            return string;
        }
        else
            i++;
    }
    return string;
}

/* ** Recebe uma string com instrução e verifica se a instrução existe na lista de comandos válidos.
    Caso exista devolve TRUE; senão, FALSE ** */

int verificaComando(char *entrada)
{
    int i = 0, tamanhoComandos = 19;
    while(i < tamanhoComandos)
    {
        if(strcmp(comandos[i], entrada) == 0)
            return TRUE;
        else
            i++;
    }

    return FALSE;
}

/* ** Verifica se a string lida só tem o número da linha ou o número da linha e espaços ** */
int verificaLinha(char *string)
{
    int i = 2, tamanho = strlen(string);
    while(i < tamanho)
    {
        if(string[i] != ' ' && string[i] != '\n')
            return FALSE;
        i++;
    }
    return TRUE;
}

/* ** Faz a conversão da linha para a linguagem entendida pelo HIPO ** */
char *converteLinha(char *linha)
{
    /* ** i começa com 2 para pular a numeração das linhas ** */
    int i = 2, j = 0, c = 0, k = 0, recebeuInstrucao = FALSE;
    /* ** As strings contém seis caracteres: um para o sinal, dois para a instrução,
    dois para o endereço e um para o '\0' ** */
    char *aux = malloc(6 * sizeof(char)), *convertida = malloc(6 * sizeof(char));
    while(linha[i] != '\0' && linha[i] != '\n')
    {
        switch(linha[i])
        {
        case ' ':
            i++;
            break;

        case ';':
            return convertida;
            break;

        case '{':
            for(++i, j = 0; linha[i] != '}' && linha[i] != '\0' && j < 3; i++, j++)
                aux[j] = linha[i];
            /* ** Se o comando recebido não tiver três caracteres, ele é inválido ** */
            if(j != 3)
            {
                printf("Erro de sintaxe.\n");
                exit(EXIT_FAILURE);
            }
            if(verificaComando(aux) == TRUE)
            {
                aux = traduzComando(aux);
                c = strlen(aux);
                strncpy(&convertida[k], aux, c);
                k += c;
            }
            else
            {
                printf("Erro de sintaxe.\n");
                exit(EXIT_FAILURE);
            }
            i++;
            recebeuInstrucao = TRUE;
            break;

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            if(recebeuInstrucao == FALSE)
            {
                printf("Erro de sintaxe.\n");
                exit(EXIT_FAILURE);
            }
            j = 0;
            while(((c = linha[i]) <= '9' && c >= '0') && j < 2)
                aux[j++] = linha[i++];
            /* ** Se o endereço recebido não tiver dois caracteres, ele é inválido ** */
            if(j != 2)
            {
                printf("Erro de sintaxe.\n");
                exit(EXIT_FAILURE);
            }
            c = strlen(aux);
            strncpy(&convertida[k], aux, c);
            k += c;
            convertida[k] = '\0';
            break;

        case '+':
        case '-':
            j = 0;
            aux[j++] = linha[i++];
            while(((c = linha[i]) <= '9' && c >= '0') && j < 5)
                aux[j++] = linha[i++];
            /* ** Se o número recebido não tiver cinco caracteres (um para o sinal e os outros,
            quatro para o número), ele é inválido ** */
            if(j != 5)
            {
                printf("Erro de sintaxe.\n");
                exit(EXIT_FAILURE);
            }
            c = strlen(aux);
            strncpy(&convertida[k], aux, c);
            k += c;
            break;

        default:
            printf("Erro de sintaxe.\n");
            exit(EXIT_FAILURE);
            break;
        }
        aux = limpaString(aux, strlen(aux));
    }
    /* ** Se o resultado final da conversão da linha não tiver cinco caracteres (um para o sinal,
        dois para o comando e mais dois para o endereço), ele é inválido ** */
    /*printf("linha: %s\n", linha);*/
    if(strlen(convertida) != 5 && recebeuInstrucao != FALSE)
    {
        printf("Erro de sintaxe.\n");
        exit(EXIT_FAILURE);
    }
    printf("%s ", linha);
    printf("%d\n", verificaLinha(linha));
    if(verificaLinha(linha) == TRUE)
         convertida = limpaString(convertida, 6);
    return convertida;
}

/* ** Salva o texto convertido em um arquivo com extensão ".hip" ** */
char *salvaHipo(char *nomeArquivo, char **texto)
{
    int i = 0, tamanho;
    FILE *p;
    tamanho = strlen(nomeArquivo);
    /* ** Escrevemos o nome do arquivo sobrescrevendo o nome da extensão antiga (".asm")
    e acrescentamos a nova (".hip") ** */
    strcpy(&nomeArquivo[tamanho - 4], ".hip");
    p = fopen(nomeArquivo, "w");
    while(texto[i] != NULL)
    {
        fputs(texto[i], p);
        fputc('\n', p);
        i++;
    }
    fclose(p);
    return nomeArquivo;
}

int main(int argc, char *argv[])
{
    int i = 0, contaLinha = 0;
    FILE *arquivo = fopen(argv[1], "r");
    char linha[MAX_TAMANHO], *nomeArquivo;
    char **convertida;
    convertida = malloc(MAX_TAMANHO * sizeof(char*));
    if(arquivo == NULL)
    {
        printf("Erro! Falha ao abrir o arquivo!\n");
        return EXIT_FAILURE;
    }
    while(fgets(linha, MAX_TAMANHO, arquivo) != NULL)
    {
        contaLinha++;
        /* ** Aloca-se 6 caracteres: um para o sinal, dois para o comando, dois para o endereço
        e mais um para o '\0' ** */
        convertida[i] = malloc(6 * sizeof(char));
        convertida[i++] = converteLinha(linha);
    }
    convertida[i] = NULL;
    nomeArquivo = salvaHipo(argv[1], convertida);
    printf("Arquivo convertido: %s\n", nomeArquivo);
    return EXIT_SUCCESS;
}
