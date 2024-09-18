A versão 2 de `main.c` é muito parecida com a v1, exceto que deckaramos `celsius` e `farh` como `float` e a fórmula de conversão é escrita de uma forma mais natural.
a primeira versão não conseguimos usar `5/9` porque a divisão de inteiros poderia trucar o resultad para zero. Um ponto decimal em um constante indica que é um float. então
`5.0/9.0` não é truncado porque tem o range de mais casas decimais.

Se um operador aritimético está operando um inteiro, a operação de inteiros é performada. Se um operador aritmético tem um operando float e um inteiro, o inteiro irá ser convertido
em float antes da operação ser concluída.

Se nós tivéssemos escrito `(fahr-32)`, o `32` iria ser automaticamente convertido em float. Não menos importante, escrever constantes do tipo float com decimais explícitos mesmo que eles tenham valores integrais enfatiza que eles são floats para leitores humanos.

# Exemplo de Divisão de Inteiros Truncada em C
Aqui está um exemplo simples em C que demonstra a divisão de inteiros sendo truncada:

#include <stdio.h>

```C
int main() {
    int a = 5;
    int b = 9;
    int result;

    // Divisão de inteiros
    result = a / b;

    printf("Resultado da divisão de inteiros 5 / 9: %d\n", result);

    return 0;
}
```
## Explicação do Código

1. Divisão de Inteiros (a / b):
Neste código, tanto a quanto b são declarados como int. A expressão a / b realiza uma divisão de inteiros. Em C, quando você divide dois inteiros, o resultado também é um inteiro, e qualquer parte fracionária é truncada (não arredondada, mas simplesmente descartada).

2. Operação:
Aqui, 5 / 9 deve resultar em 0.555.... Porém, como ambos os números são inteiros, o resultado é truncado para 0.

Saída Esperada
A saída do programa será:
`Resultado da divisão de inteiros 5 / 9: 0`


## Explicação da Saída
A parte decimal (0.555...) é descartada porque estamos usando divisão de inteiros. O resultado é truncado para 0.

# Evitando o Truncamento
Se você quisesse evitar esse truncamento e obter um resultado de ponto flutuante, você precisaria converter um ou ambos os operandos para `float` ou `double`. Por exemplo:

```C
#include <stdio.h>

int main() {
    int a = 5;
    int b = 9;
    float result;

    // Divisão com ponto flutuante
    result = (float)a / b; // Converte 'a' para float antes da divisão

    printf("Resultado da divisão com ponto flutuante 5 / 9: %.2f\n", result);

    return 0;
}
```
## Saída Esperada para o Segundo Exemplo
A saída do programa agora será:
`Resultado da divisão com ponto flutuante 5 / 9: 0.56`

# SYMBOLIC CONSTANTS

É uma má prática deixar números "mágicos" como 300, 20, etc; além de dar pouca informação, eles restrigem a manutenção e o uso do código por outras pessoas. A maneira ideal de lidar com esses valores é dá-los nomes simbólicos.

A diretiva `#define` é usada no pré-processador do C para definir uma constante simbólica ou realizar macros. O pré-processador substitui todas as ocorrências da constante definida por seu valor antes da compilação, ou seja, é uma substituição textual direta no código.

```C
#define NOME valor
```

Na versão 3, o #define está criando constantes simbólicas:

- LOWER será substituído por 0.
- UPPER será substituído por 300.
- STEP será substituído por 20.

Isso significa que, em qualquer lugar do código onde aparece LOWER, UPPER ou STEP, o compilador vai substituir esses identificadores pelos seus respectivos valores antes de compilar o código.

## O que são Symbolic Constants?
Constantes simbólicas são nomes que representam valores fixos no código. Ao usar constantes simbólicas:

- Facilitamos a manutenção do código, pois se o valor de uma constante mudar, podemos alterá-lo apenas no #define em vez de procurar por todos os lugares no código onde ele aparece.
- Aumentamos a legibilidade do código, já que o nome da constante pode ser mais descritivo do que o valor literal.

## Diferença entre #define e const
Uma diferença importante entre o uso de #define e a palavra-chave const é que #define não ocupa memória, pois a substituição é feita no pré-processamento (antes da compilação). Em contraste, quando usamos const, a variável é tratada como uma variável normal que ocupa espaço na memória, mas que não pode ser modificada.

Exemplo de uso de const:

```C
const int LOWER = 0;
const int UPPER = 300;
const int STEP = 20;
```

| Característica            | `#define`                                    | `const`                             |
|---------------------------|----------------------------------------------|-------------------------------------|
| Etapa de substituição     | Feita no pré-processador (substituição textual) | Feita em tempo de execução          |
| Uso de memória            | Não ocupa memória                            | Ocupa memória, como qualquer variável |
| Tipo de dados             | Não tem tipo, apenas substituição de texto   | Tem tipo definido (`int`, `float`, etc.) |
| Escopo                    | Global (substituição no arquivo inteiro)     | Pode ser local ou global, dependendo da declaração |
| Depuração                 | Mais difícil, pois o valor é substituído diretamente | Mais fácil, pois o valor está vinculado a uma variável |
| Segurança de tipo         | Não oferece segurança de tipo                | Oferece segurança de tipo           |
| Capacidade de ser alterado| Imutável (não pode ser alterado)             | Imutável após a inicialização       |
| Avaliação                 | Substituição é feita em todo o arquivo       | Avaliada apenas quando usada        |
| Exemplo de uso            | `#define LOWER 0`                            | `const int LOWER = 0;`              |

Vantagens do #define:
- Melhor legibilidade: Usar nomes simbólicos (LOWER, UPPER, STEP) torna o código mais fácil de entender.
- Facilidade de manutenção: Se quisermos mudar os limites de temperatura, basta alterar os valores no #define e todo o código refletirá essa mudança.
- Não ocupa memória: Diferente de variáveis const, que ocupam memória, o #define faz substituições diretas sem alocação de espaço.