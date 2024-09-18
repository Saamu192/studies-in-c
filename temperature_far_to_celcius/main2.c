/*
O problema mais serio é porque nós usamos em main.c aritmética de inteiros. A temperatura em Celscius
não é severamente acurada. Por instância, 0F é na verdade por volta de -17.8C, não -17.

Para deixar o programa com mais acuracidade, nós devemos usar ponteiros do tipo float na nossa aritmética ao invés de inteiros.
Isso requer algumas mudanças em detrimento do main.c
*/

#include <stdio.h>

void main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    };

    return;
}