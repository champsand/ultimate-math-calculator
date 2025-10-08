#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void basicCalculator();
void trigCalculator();
void algebraCalculator();
void matrixCalculator();
void statisticsCalculator();
void equationCalculator();
void conversionCalculator();

void basicCalculator() {
    int choice;
    double a, b;
    do {
        system("cls");
        printf("=====================================\n");
        printf("          BASIC CALCULATOR\n");
        printf("=====================================\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Back to Main Menu\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6) {
            printf("Enter first number: ");
            scanf("%lf", &a);
            printf("Enter second number: ");
            scanf("%lf", &b);
        }

        switch(choice) {
            case 1: printf("Result: %.2lf\n", a + b); break;
            case 2: printf("Result: %.2lf\n", a - b); break;
            case 3: printf("Result: %.2lf\n", a * b); break;
            case 4: if(b != 0) printf("Result: %.2lf\n", a / b); else printf("Cannot divide by zero.\n"); break;
            case 5: printf("Result: %d\n", (int)a % (int)b); break;
            case 6: printf("Result: %.2lf\n", pow(a, b)); break;
        }

        if (choice != 7) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }

    } while (choice != 7);
}

void trigCalculator() {
    int choice;
    double x, rad;
    do {
        system("cls");
        printf("=====================================\n");
        printf("      TRIGONOMETRIC CALCULATOR\n");
        printf("=====================================\n");
        printf("(Input angle in degrees)\n");
        printf("-------------------------------------\n");
        printf("1. sin(x)\n");
        printf("2. cos(x)\n");
        printf("3. tan(x)\n");
        printf("4. cot(x)\n");
        printf("5. sec(x)\n");
        printf("6. csc(x)\n");
        printf("7. Back to Main Menu\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6) {
            printf("Enter angle: ");
            scanf("%lf", &x);
            rad = x * (M_PI / 180.0);
        }

        switch(choice) {
            case 1: printf("sin(%.2lf) = %.4lf\n", x, sin(rad)); break;
            case 2: printf("cos(%.2lf) = %.4lf\n", x, cos(rad)); break;
            case 3: printf("tan(%.2lf) = %.4lf\n", x, tan(rad)); break;
            case 4: if(tan(rad)!=0) printf("cot(%.2lf) = %.4lf\n", x, 1/tan(rad)); else printf("Undefined.\n"); break;
            case 5: if(cos(rad)!=0) printf("sec(%.2lf) = %.4lf\n", x, 1/cos(rad)); else printf("Undefined.\n"); break;
            case 6: if(sin(rad)!=0) printf("csc(%.2lf) = %.4lf\n", x, 1/sin(rad)); else printf("Undefined.\n"); break;
        }

        if (choice != 7) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }

    } while (choice != 7);
}

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void algebraCalculator() {
    int choice, n, r;
    double a;
    do {
        system("cls");
        printf("=====================================\n");
        printf("          ALGEBRA CALCULATOR\n");
        printf("=====================================\n");
        printf("1. Factorial\n");
        printf("2. Combination (nCr)\n");
        printf("3. Permutation (nPr)\n");
        printf("4. Square Root\n");
        printf("5. Back to Main Menu\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("Result: %lld\n", factorial(n));
                break;
            case 2:
                printf("Enter n and r: ");
                scanf("%d %d", &n, &r);
                if (r > n) printf("Invalid input.\n");
                else printf("Result: %lld\n", factorial(n)/(factorial(r)*factorial(n-r)));
                break;
            case 3:
                printf("Enter n and r: ");
                scanf("%d %d", &n, &r);
                if (r > n) printf("Invalid input.\n");
                else printf("Result: %lld\n", factorial(n)/factorial(n-r));
                break;
            case 4:
                printf("Enter number: ");
                scanf("%lf", &a);
                printf("Result: %.4lf\n", sqrt(a));
                break;
        }

        if (choice != 5) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }

    } while (choice != 5);
}

void matrixCalculator() {
    double A[3][3], B[3][3], C[3][3];
    int i, j, k, choice;
    do {
        system("cls");
        printf("=====================================\n");
        printf("          MATRIX CALCULATOR\n");
        printf("=====================================\n");
        printf("All matrix operations use 3x3 matrices.\n");
        printf("You can leave unused elements as 0.\n");
        printf("-------------------------------------\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Determinant\n");
        printf("5. Back to Main Menu\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            printf("\nEnter Matrix A (row by row):\n");
            for (i = 0; i < 3; i++) {
                printf("Row %d (3 values separated by space): ", i + 1);
                for (j = 0; j < 3; j++) scanf("%lf", &A[i][j]);
            }
        }
        if (choice <= 3) {
            printf("\nEnter Matrix B (row by row):\n");
            for (i = 0; i < 3; i++) {
                printf("Row %d (3 values separated by space): ", i + 1);
                for (j = 0; j < 3; j++) scanf("%lf", &B[i][j]);
            }
        }

        system("cls");
        printf("=====================================\n");
        printf("               RESULT\n");
        printf("=====================================\n");

        switch (choice) {
            case 1:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 3; j++)
                        C[i][j] = A[i][j] + B[i][j];
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++)
                        printf("%.2lf ", C[i][j]);
                    printf("\n");
                }
                break;
            case 2:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 3; j++)
                        C[i][j] = A[i][j] - B[i][j];
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++)
                        printf("%.2lf ", C[i][j]);
                    printf("\n");
                }
                break;
            case 3:
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 3; j++) {
                        C[i][j] = 0;
                        for (k = 0; k < 3; k++)
                            C[i][j] += A[i][k] * B[k][j];
                    }
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++)
                        printf("%.2lf ", C[i][j]);
                    printf("\n");
                }
                break;
            case 4:
                printf("Determinant: %.2lf\n",
                       A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
                       A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
                       A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]));
                break;
        }

        if (choice != 5) {
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
        }

    } while (choice != 5);
}

void statisticsCalculator() {
    int n, i, j;
    double arr[100], sum=0, mean, median, mode, temp, stddev=0;
    do {
        system("cls");
        printf("=====================================\n");
        printf("         STATISTICS CALCULATOR\n");
        printf("=====================================\n");
        printf("Enter number of data points (max 100, 0 to exit): ");
        scanf("%d", &n);
        if(n==0) break;

        for(i=0;i<n;i++){printf("Data %d: ",i+1);scanf("%lf",&arr[i]);sum+=arr[i];}
        mean=sum/n;
        for(i=0;i<n-1;i++) for(j=i+1;j<n;j++) if(arr[i]>arr[j]){temp=arr[i];arr[i]=arr[j];arr[j]=temp;}
        median=(n%2)?arr[n/2]:(arr[(n-1)/2]+arr[n/2])/2;
        int count,maxCount=0;
        for(i=0;i<n;i++){count=0;for(j=0;j<n;j++) if(arr[j]==arr[i]) count++;if(count>maxCount){maxCount=count;mode=arr[i];}}
        for(i=0;i<n;i++) stddev+=pow(arr[i]-mean,2);
        stddev=sqrt(stddev/n);

        printf("\nMean = %.2lf\nMedian = %.2lf\nMode = %.2lf\nStandard Deviation = %.2lf\n",mean,median,mode,stddev);
        printf("\nPress Enter to continue...");
        getchar(); getchar();
    } while(n!=0);
}

void equationCalculator() {
    int choice;
    double a,b,c,d;
    do {
        system("cls");
        printf("=====================================\n");
        printf("          EQUATION CALCULATOR\n");
        printf("=====================================\n");
        printf("1. Linear Equation (ax + b = 0)\n");
        printf("2. Quadratic Equation (ax^2 + bx + c = 0)\n");
        printf("3. Cubic Equation (ax^3 + bx^2 + cx + d = 0)\n");
        printf("4. Back to Main Menu\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter a and b: "); scanf("%lf %lf",&a,&b);
                if(a!=0) printf("x = %.4lf\n",-b/a);
                else printf("No valid solution.\n");
                break;
            case 2:
                printf("Enter a, b, c: "); scanf("%lf %lf %lf",&a,&b,&c);
                d=b*b-4*a*c;
                if(d>0) printf("x1=%.4lf, x2=%.4lf\n",(-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a));
                else if(d==0) printf("x=%.4lf\n",-b/(2*a));
                else printf("No real roots.\n");
                break;
            case 3:
                printf("Enter a, b, c, d: "); scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
                printf("Approximate roots may require numeric methods.\n");
                break;
        }

        if(choice!=4){printf("\nPress Enter to continue..."); getchar(); getchar();}
    } while(choice!=4);
}

void conversionCalculator() {
    int choice, sub;
    double val;
    do {
        system("cls");
        printf("=====================================\n");
        printf("          CONVERSION CALCULATOR\n");
        printf("=====================================\n");
        printf("1. Temperature (C <-> F <-> K)\n");
        printf("2. Length (m <-> cm <-> km)\n");
        printf("3. Weight (kg <-> g <-> lb)\n");
        printf("4. Back to Main Menu\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                system("cls");
                printf("Temperature Conversion:\n");
                printf("1. From Celsius\n");
                printf("2. From Fahrenheit\n");
                printf("3. From Kelvin\n");
                printf("Enter your choice: ");
                scanf("%d",&sub);
                printf("Enter value: ");
                scanf("%lf",&val);
                if(sub==1){
                    printf("Fahrenheit = %.2lf\n", (val*9/5)+32);
                    printf("Kelvin = %.2lf\n", val+273.15);
                } else if(sub==2){
                    printf("Celsius = %.2lf\n", (val-32)*5/9);
                    printf("Kelvin = %.2lf\n", ((val-32)*5/9)+273.15);
                } else if(sub==3){
                    printf("Celsius = %.2lf\n", val-273.15);
                    printf("Fahrenheit = %.2lf\n", ((val-273.15)*9/5)+32);
                } else {
                    printf("Invalid choice.\n");
                }
                break;

            case 2:
                system("cls");
                printf("Length Conversion:\n");
                printf("1. From Meters\n");
                printf("2. From Centimeters\n");
                printf("3. From Kilometers\n");
                printf("Enter your choice: ");
                scanf("%d",&sub);
                printf("Enter value: ");
                scanf("%lf",&val);
                if(sub==1){
                    printf("Centimeters = %.2lf\n", val*100);
                    printf("Kilometers = %.6lf\n", val/1000);
                } else if(sub==2){
                    printf("Meters = %.2lf\n", val/100);
                    printf("Kilometers = %.6lf\n", val/100000);
                } else if(sub==3){
                    printf("Meters = %.2lf\n", val*1000);
                    printf("Centimeters = %.2lf\n", val*100000);
                } else {
                    printf("Invalid choice.\n");
                }
                break;

            case 3:
                system("cls");
                printf("Weight Conversion:\n");
                printf("1. From Kilograms\n");
                printf("2. From Grams\n");
                printf("3. From Pounds\n");
                printf("Enter your choice: ");
                scanf("%d",&sub);
                printf("Enter value: ");
                scanf("%lf",&val);
                if(sub==1){
                    printf("Grams = %.2lf\n", val*1000);
                    printf("Pounds = %.4lf\n", val*2.20462);
                } else if(sub==2){
                    printf("Kilograms = %.2lf\n", val/1000);
                    printf("Pounds = %.4lf\n", (val/1000)*2.20462);
                } else if(sub==3){
                    printf("Kilograms = %.2lf\n", val/2.20462);
                    printf("Grams = %.2lf\n", (val/2.20462)*1000);
                } else {
                    printf("Invalid choice.\n");
                }
                break;
        }

        if(choice!=4){
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
        }
    } while(choice!=4);
}

int main() {
    int choice;
    do {
        system("cls");
        printf("=====================================\n");
        printf("             MATHLAB PRO\n");
        printf("=====================================\n");
        printf("1. Basic Calculator\n");
        printf("2. Trigonometric Calculator\n");
        printf("3. Algebra Calculator\n");
        printf("4. Matrix Calculator\n");
        printf("5. Statistics Calculator\n");
        printf("6. Equation Calculator\n");
        printf("7. Conversion Calculator\n");
        printf("8. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        system("cls");
        switch(choice){
            case 1: basicCalculator(); break;
            case 2: trigCalculator(); break;
            case 3: algebraCalculator(); break;
            case 4: matrixCalculator(); break;
            case 5: statisticsCalculator(); break;
            case 6: equationCalculator(); break;
            case 7: conversionCalculator(); break;
            case 8: printf("Exiting MathLab Pro... Goodbye!\n"); break;
            default: printf("Invalid choice.\n"); break;
        }

        if(choice!=8){printf("\nPress Enter to return to main menu..."); getchar(); getchar();}
    } while(choice!=8);

    return 0;
}