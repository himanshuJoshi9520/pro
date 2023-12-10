#include <stdio.h>
#include <stdlib.h>
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;   return newTerm;
}void insertTerm(struct Term** poly, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* current = *poly;
        while (current->next != NULL)
	 {
            current = current->next;      }
        current->next = newTerm;    }}
void displayPolynomial(struct Term* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf(" + ");
        }        poly = poly->next;    }printf("\n");}
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* current1 = poly1;
    struct Term* current2 = poly2;
    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent > current2->exponent) {
            insertTerm(&result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else if (current1->exponent < current2->exponent) {
          
		    insertTerm(&result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        } else {
            insertTerm(&result, current1->coefficient + current2->coefficient, current1->exponent);
            current1 = current1->next;
            current2 = current2->next;        }    }
    while (current1 != NULL) {
        insertTerm(&result, current1->coefficient, current1->exponent);
        current1 = current1->next;
   }   while (current2 != NULL) {
       insertTerm(&result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }    return result;}
int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* result = NULL;
    int n, coefficient, exponent;
    printf("Enter the degree of the polynomials: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents for the first polynomial:\n");
    for (int i = n; i >= 0; --i) {
        scanf("%d", &coefficient);
        insertTerm(&poly1, coefficient, i);  }
 printf("Enter the coefficients and exponents for thesecond polynomial:\n");
    for (int i = n; i >= 0; --i) {
        scanf("%d", &coefficient);
        insertTerm(&poly2, coefficient, i);   }
    printf("First polynomial: ");
    displayPolynomial(poly1);
    printf("Second polynomial: ");
    displayPolynomial(poly2);
    result = addPolynomials(poly1, poly2);
    printf("Resultant polynomial (Sum of p1 and p2): ");
    displayPolynomial(result);
    return 0;
}

