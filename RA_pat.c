#include <stdio.h>
 /*
pattern 1 -> left skewed right angle triangle
pattern 2 -> right skewed right angle triangle
pattern 3 -> inverted left skewed right angle triangle
pattern 4 -> inverted right skewed right angle triangle
pattern 5 -> pyramid
pattern 6 -> inverted pyramid
pattern 7 -> right rotated pyramid
pattern 8 -> left rotated pyramid
pattern 9 -> diamond / rhombus
pattern 10 - > hollow square
pattern 11 -> hollow diamond
pattern 12 -> Simple increasing number triangle
pattern 13 -> Simple inverted increasing number triangle
pattern 14 -> Floyd's triangle
pattern 15 -> pascal triangle
pattern 16 -> palindromic pattern
pattern 17 -> character pattern
pattern 18 -> X star pattern
pattern 19 -> hourglass star pattern
pattern 20 -> butterfly star pattern
 */
int fact(int n){
    int res = 1;
    for(int i =1;i<=n;i++)   res *= i;
    return res;
}
int ncr(int i,int j){
    return fact(i)/(fact(i-j)*fact(j));
}

int main()
{
    /* pattern 1 */

    int n = 5;
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 2 */
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n-i;j++){
            printf("  ");
        }
        for(int k = 1;k<=i;k++){
            printf(" *");
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 3 */
    for(int i=1;i<=n;i++){
        for(int j = n;j>=i;j--){
            printf("* ");
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 4 */
    for(int i=1;i<=n;i++){
        for(int j = 1;j<i;j++){
            printf("  ");
        }
        for(int j = n;j>=i;j--){
            printf(" *");
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 5 */
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n-i;j++){
            printf(" ");
        }
        for(int j = 1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 6 */
        for(int i=1;i<=n;i++){
        for(int j = 1;j<i;j++){
            printf(" ");
        }
        for(int j = i;j<=n;j++){
            printf("* ");
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 7 */
    for(int i=1;i<=(2*n)-1;i++){
        if(i<=n){
            for(int j = 1;j<=i;j++){
                printf("* ");
            }
        }
        else{
            for(int j = 1;j<=n-(i%n);j++){
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 8 */
    for(int i=1;i<=(2*n)-1;i++){
        if(i<=n){
            for(int k = 1;k <=n-i; k++){
                printf("  ");
            }
            for(int j = 1;j<=i;j++){
                printf(" *");
            }
        }
        else{
            for(int k = 1;k <= (i%n); k++){
                printf("  ");
            }
            for(int j = 1;j<=n-(i%n);j++){
                printf(" *");
            }
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 9 */
    for(int i=1;i<=(2*n)-1;i++){
        if(i<=n){
            for(int k = 1;k <=n-i; k++){
                printf(" ");
            }
            for(int j = 1;j<=i;j++){
                printf("* ");
            }
        }
        else{
            for(int k = 1;k <= (i%n); k++){
                printf(" ");
            }
            for(int j = 1;j<=n-(i%n);j++){
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 10 */
    for(int i=1;i<=n;i++){
            for(int k = 1;k <=n; k++){
                if(k == 1 || k == n || i == 1 || i == n) printf("* ");
                else printf("  ");
            }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 11 */
    for(int i=1;i<=(2*n)-1;i++){
        if(i<=n){
            for(int k = 1;k <=n-i; k++){
                printf(" ");
            }
            for(int j = 1;j<=i;j++){
                if(j == 1 || j == i) printf("* ");
                else printf("  ");
            }
        }
        else{
            for(int k = 1;k <= (i%n); k++){
                printf(" ");
            }
            for(int j = 1;j<=n-(i%n);j++){
                if(j == 1 || j == n-(i%n)) printf("* ");
                else printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 12*/
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 13*/
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n-i+1;j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 14*/
    int cnt =1;
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            printf("%d ",cnt++);
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 15*/
    for(int i = 1; i <= n; i++){
        for(int k = 1;k<=n-i;k++) printf(" ");
        for(int j = 1; j <= i; j++){
            printf(" %d",ncr(i-1,j-1));
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 16*/
    for(int i = 1; i <= n; i++){
        for(int k = 1;k<=n-i;k++) printf("  ");
        for(int j = 1; j <= i; j++) printf(" %d",j);
        for(int j = i-1;j>=1;j--) printf(" %d",j);
        printf("\n");
    }
    printf("\n\n");
    /*pattern 17*/
    for(int i=0;i<n;i++){
        for(int j = 0;j<=i;j++){
            printf("%c ",'A'+j);
        }
        printf("\n");
    }
    printf("\n\n");
    /*pattern 18*/
        for(int i=1;i<=n;i++){
        for(int j = 1;j<=n;j++){
           if((i == j) || (i+j) == (n+1)) printf("*");
           else printf(" ");
        }
        printf("\n");
    }
    printf("\n\n");
    /* pattern 19*/
        for(int i=1;i<=n;i++){
        for(int j = 1;j<=i-1;j++) printf("  ");
        for(int j = 1;j<=2*(n-i)+1;j++) printf("* ");
         printf("\n");
    }
    for(int i=2;i<=n;i++){
        for(int j = 1;j<=n-i;j++) printf("  ");
        for(int j = 1;j<=2*i-1;j++) printf("* ");
        printf("\n");
    }
    printf("\n\n");
    /* pattern 20*/
    for(int i=1; i<=n;i++) {
        for(int j = 1;j <= i;j++) printf("*");
        for(int j = 1;j <= 2*(n - i);j++) printf(" ");
        for(int j = 1;j <= i;j++) printf("*");

        printf("\n");
    }

    for(int i = n; i >= 1; i--) {
        for(int j = 1;j <= i;j++) printf("*");
        for(int j = 1;j <= 2*(n - i);j++) printf(" ");
        for(int j = 1;j <= i;j++) printf("*");

        printf("\n");
    }
    return 0;
}