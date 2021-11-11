/*
На вход программе подаются координаты вершин треугольника ABC (сначала координаты вершины A, затем B, затем C).

Выведите координаты пересечения биссектрисы ∠ACB со стороной AB, затем координаты точки пересечения биссектрисы ∠BAC со стороной BC, затем координаты точки пересечения биссектрисы ∠ABC со стороной AC. Все координаты выводите с точностью до 5 знаков после запятой.

*/

#include<math.h>
#include<stdio.h>
double sqr(double x) {
    return x*x;
}
double dist(const double *a, const double *b) {
    return sqrt(sqr(a[0]-b[0])+sqr(a[1]-b[1])); 
}
void make_mid_point(double *p, const double *a, const double *b, double ac, double bc) {
    for (int i=0;i<2;i++)
	p[i]=(a[i]*bc+b[i]*ac)/(ac+bc);
}
void input_point(double *a) {
    scanf("%lf%lf", &a[0], &a[1]);
}
void print_point(double *a) {
    printf("%.5lf %.5lf\n",a[0],a[1]);
}
int main(void) {
    double A[2],B[2],C[2],PA[2],PB[2],PC[2];
    double AB,BC,CA;
    input_point(A);
    input_point(B);
    input_point(C);
    AB = dist(A,B);
    BC = dist(B,C);
    CA = dist(C,A);
    make_mid_point(PC,A,B,CA,BC);
    make_mid_point(PB,C,A,BC,AB);
    make_mid_point(PA,B,C,AB,CA);
    print_point(PC);
    print_point(PA);
    print_point(PB);
    return 0;
