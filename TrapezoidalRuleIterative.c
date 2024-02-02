// Trapezoidal rule implementation iteratively
#include <stdio.h>
#include <math.h>

double trapezoidalRule(double (*f)(double), double a, double b, int n);

double f1(double x) {
    return x * x; // f(x) = x^2
}

double f2(double x) {
    return sin(x); // f(x) = sin(x)
}

double f3(double x) {
    return exp(x); // f(x) = e^x
}

int main() {
    printf("Integral of x^2 from 0 to 1: %f\n", trapezoidalRule(f1, 0, 1, 100));
    printf("Integral of sin(x) from 0 to PI: %f\n", trapezoidalRule(f2, 0, M_PI, 100));
    printf("Integral of e^x from 1 to 2: %f\n", trapezoidalRule(f3, 1, 2, 100));

    return 0;
}

double trapezoidalRule(double (*f)(double), double a, double b, int n) {
    double delta_x = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        double x_i = a + i * delta_x;
        sum += f(x_i);
    }
    return sum * delta_x;
}
