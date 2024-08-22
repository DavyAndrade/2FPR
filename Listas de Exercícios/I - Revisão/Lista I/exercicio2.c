/*
QUESTÃO 02:
Implementar uma função que converta
determinada temperatura em graus Celsius
para graus Fahrenheit.
*/

#include <stdio.h>

float celsiusToFahrenheit(int celsius);

int main()
{
    int celsius;
    float fahrenheit;

    printf("Informe a temperatura (C): ");
    scanf("%d", &celsius);

    fahrenheit = celsiusToFahrenheit(celsius);

    printf("\nTemperatura em Celsius: %d C", celsius);
    printf("\nTemperatura em Fahrenheit: %.1f F", fahrenheit);
}

float celsiusToFahrenheit(int celsius)
{
    float fahrenheit = (celsius * 1.8) + 32;

    return fahrenheit;
}