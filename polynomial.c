#include<stdio.h>

struct polynomial
{
int coefficient;
int exponent;
};

struct polynomial p1[10],p2[10],p3[10];

int read(struct polynomial p[]);
int add(struct polynomial p1[], struct polynomial p2[], int t1, int t2, struct polynomial p3[]);
void display(struct polynomial p[], int terms);

int main() 
{
    int t1, t2, t3;

    t1 = read(p1);
    printf("\nFirst Polynomial: ");
    display(p1, t1);

    t2 = read(p2);
    printf("\nSecond Polynomial: ");
    display(p2, t2);

    t3 = add(p1, p2, t1, t2, p3);
    printf("\nResulting Polynomial: ");
    display(p3, t3);

    return 0;
}

int read(struct polynomial p[]) 
{
    int t1, i;
    printf("\n Enter the total number of terms : ");
    scanf("%d", &t1);
   
    for (i = 0; i < t1; i++) {
        printf("Enter the coefficient(%d): ", i + 1);
        scanf("%d", &p[i].coefficient);
        printf("Enter the exponent(%d): ", i + 1);
        scanf("%d", &p[i].exponent);
    }
    return t1;
}

int add(struct polynomial p1[], struct polynomial p2[], int t1, int t2, struct polynomial p3[]) 
{
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) 
    {
        if (p1[i].exponent == p2[j].exponent) 
        {
            p3[k].coefficient = p1[i].coefficient + p2[j].coefficient;
            p3[k].exponent = p1[i].exponent;
            i++;
            j++;
        }
         else if (p1[i].exponent > p2[j].exponent) 
         {
            p3[k].coefficient = p1[i].coefficient;
            p3[k].exponent = p1[i].exponent;
            i++;
        } 
        else 
        {
            p3[k].coefficient = p2[j].coefficient;
            p3[k].exponent = p2[j].exponent;
            j++;
        }
        k++;
    }
while (i < t1)
 {
        p3[k].coefficient = p1[i].coefficient;
        p3[k].exponent = p1[i].exponent;
        i++;
        k++;
    }

    while (j < t2)
     {
        p3[k].coefficient = p2[j].coefficient;
        p3[k].exponent = p2[j].exponent;
        j++;
        k++;
    }

    return k;
}
void display(struct polynomial p[], int terms) 
{
    int k;
    for (k = 0; k < terms - 1; k++) 
    {
        printf("%d(x^%d) + ", p[k].coefficient, p[k].exponent);
    }
    printf("%d(x^%d)", p[terms - 1].coefficient, p[terms - 1].exponent);
}

