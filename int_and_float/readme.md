# INT, FLOAT, CHAR e DOUBLE

## Introdução

No C, os tipos de dados primitivos são usados para armazenar diferentes tipos de valores na memória. Eles são essenciais para a programação em baixo nível, já que nos permitem entender como os dados são representados e manipulados diretamente na memória do computador.

### INT

O tipo `int` é usado para armazenar valores inteiros, ou seja, valores sem casas decimais. Um `int` geralmente ocupa 4 bytes (32 bites), embora isso possa variar dependendo do compilador e arquitetura do OS. Esses 32 bits representam números inteiros em complemento de dois, permitindo armazenar tanto números postitivos quanto negativos.

```C
#include <stdio.h>

int main() {
    int num;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);  // Lê um número inteiro

    printf("Voce digitou: %d\n", num);  // Imprime o número inteiro

    return 0;
}
```
Quando declaramos uma variável do tipo int, o compilador aloca 4 bytes de memória para armazenar esse valor. Se o valor de `int num` for, por exemplo, 10, ele será armazenado na memória em sua representação binária de 32 bits.

### FLOAT

O tipo `float` é usado para armazenar números em ponto flutuante (valores decimais). Em sistemas que seguem o padrão IEEE 754, um floar ocupa 4 bytes (32 bits). A precisão de um float é de aproximadamente 6-7 dígitos

```C
#include <stdio.h>

int main() {
    float num;

    printf("Digite um numero de ponto flutuante: ");
    scanf("%f", &num);  // Lê um número float

    printf("Voce digitou: %f\n", num);  // Imprime o número float

    return 0;
}
```
Um floar é representado na memória de acordo com o padrão IEEE 754, que divide os 32 bites em três partes:

- 1 bit para o sinal (positivo ou negativo)
- 8 bits para o expoente
- 23 bits para a mantissa (fração)


| Atributo                 | `int`                         | `float`                         |
|--------------------------|-------------------------------|---------------------------------|
| Tamanho na memória       | 4 bytes (32 bits)             | 4 bytes (32 bits)               |
| Representação            | Complemento de dois           | IEEE 754                        |
| Partes na memória        | Apenas valor                  | Sinal (1 bit), Expoente (8 bits), Mantissa (23 bits) |
| Exemplo de valor armazenado | `10` → `00000000 00000000 00000000 00001010` | `5.75` → `0 10000001 01110000000000000000000` |
| Faixa de valores         | -2,147,483,648 a 2,147,483,647| Aproximadamente 3.4e−38 a 3.4e+38 |
| Precisão                 | Exata (inteiros)              | Aproximadamente 6-7 dígitos decimais |
| Operações aritméticas    | Mais rápidas                  | Mais lentas devido à normalização |
| Arredondamento           | Não ocorre                    | Pode ocorrer devido à representação em ponto flutuante |

- int:

    - Um int usa uma representação de complemento de dois para armazenar números inteiros.
    - Nos 32 bits alocados, ele representa diretamente o valor, permitindo armazenar números inteiros positivos e negativos.
    - Exemplos de bits para 10: 00000000 00000000 00000000 00001010.

- float:

    - Um float usa a representação IEEE 754 para números em ponto flutuante, dividindo os 32 bits em três partes:
        - Sinal (1 bit): Determina se o número é positivo ou negativo.
        - Expoente (8 bits): Armazena a potência da base 2, com um deslocamento (bias) de 127.
        - Mantissa (23 bits): Representa a parte fracionária do número, com uma "vírgula" implícita.
    - Exemplo de bits para 5.75: 0 10000001 01110000000000000000000.
