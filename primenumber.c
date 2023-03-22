#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int product, a, res, temp, rt, g;
    printf("Enter the product of any 2 prime numbers: ");
    scanf("%d", &product);
    g = 2;
    while (1) {
        int count = 1;
        for (int i = 0; ((g ^ i) % product) != 1; i++) {
            count += 1;
        }
        a = count / 2;
        double result = pow(g, a);
        res = ((int)result) + 1;
        temp = product;
        rt = res;
        while (rt % temp != 0) {
            int t = temp;
            temp = rt % temp;
            rt = t;
        }
        if (isPrime(temp) && isPrime(product / temp)) {
            printf("***************\n");
            printf("* %d = %d * %d *\n", product, temp, product / temp);
            printf("***************\n");
            break;
        }
        g++;
        if (g >= product) {
            printf("Enter a valid number (product of 2 prime numbers): ");
            scanf("%d", &product);
            g = 2;
        }
    }
    return 0;
}
