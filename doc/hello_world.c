#include <stdio.h>

void manipulate_pwm(int value)
{
    value++;
}

int main() 
{
    int num = 5;

    manipulate_pwm(num);
    printf("Value: %d\n", num);

    printf("Hello, World!\n");
    return 0;
}
