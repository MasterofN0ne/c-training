#include <stdio.h>
/*
    Functions represented as question number then option 
    like first question option a -> represented as 'void q1_a()'
*/

void q1_a(){
    int i = 3; // initial value of i is 3
    while(i--){ // Loop will be terminated while i > 0
        static int a = 8; // a will change its last value by the end of the loop 
        char b = 20; // i's value changed to 20 and it will be 20 as soon as loop is being terminated
        a += 3;
        b--;
        printf("%d %d\n", a, b);
    }
    // first output a = 11 b = 19
    // second output a = 14 b = 19
    // first output a = 17 b = 19
}

// -------------------------------------------------------

void q1_b(){
    int i, j;
    double x = 0;

    for (i = 0, j = 7; j > 0; i++, j--){
        if (i < j) continue; // Nothing happens until i > j
        x += i / j; // int with int division result int value
        printf("i=%d, j=%d, x=%3.1f\n", i, j, x);
        if (i == j) break; // When i == j programs stops executing
    }
    printf("\n i=%d j=%d\n", i, j);
    /*
    ----- OUTPUTS -----
    i=4, j=3, x=1.0
    i=5, j=2, x=3.0
    i=6, j=1, x=9.0
    */
}

// -------------------------------------------------------


int q1__f(int a) {return a % 2 ? ++a : a--;}


/*
    Function above uses ternary c operators
    a % 2 ? ++a : a-- -> expression is where ternary operator used
    We can recreate this expression with if else statements or switch 
    ----------------------
    Using if else:
        int a;
        if (a % 2 == 0)
            a--;
        else
            ++a
    -----------------------
    Using switch:
        int a;

        switch(a%2){
            case 0:
                a--;
                printf("a: %d\n", a);
                break;
            case 1:
                ++a;
                printf("a: %d\n", a);
                break;
            default:
                printf("Something wrong just happened..\n");
                break;
        }
*/


void q1_c(){
    int i, a = 2;
    for (i = 0; i < 5; i++){ // 0, 1, 2, 3, 4
        a += i;
        printf("Value of q1_f(a): %d Value of a: %d \n", q1__f(a), a);
        printf("(%d,%d)\n", i , q1__f(a));
    }
    /* 
        --------OUTPUT---------
            Value of q1_f(a): 2 Value of a: 2
                (0,2)
            Value of q1_f(a): 4 Value of a: 3
                (1,4)
            Value of q1_f(a): 6 Value of a: 5
                (2,6)
            Value of q1_f(a): 8 Value of a: 8
                (3,8)
            Value of q1_f(a): 12 Value of a: 12
                (4,12)
    */
}

// -------------------------------------------------------

void q1_d(){
    int sum = 0;
    int i;
    for (i = 0; i < 50; i++); // Loop terminates until i = 50
    for (int j = 0; j < 5; j++) sum = i*j; // j's values are 0, 1, 2, 3, 4
    // sum Values are -> (0 * 50) + (1 * 50) + (2 * 50) + (3 * 50) + (4 * 50) = 500
    /* 
        Well If you thought why for loop with j didn't terminate one more time because in the upper loop 
        i evaluated to 50 because of ++ operator after i made i 50 after exited loop and just like that j became 5 after exiting the loop
    */
    printf("%d\n", sum);
}

// -------------------------------------------------------

void fun(int, int);
/* 
    There is nothing wrong with this declaration of a function
    It shows what the function get as parameters which is two
    integer values
*/

void q1_e(){
    int x = 5, y = 11;
    fun(x+7, y); // Useless
    printf("%d %d\n", x, y); // Prints out the original values
}

void fun(int r, int s)
{
   r /= 2;  s /= 3; // But this function doesn't return anything so it's just a jebait :(
}	

// -------------------------------------------------------

void f(float x, float y[], int n){
    int i;
    for (i = 0; i < n; i++){ // 0, 1, 2, 3, 4
        x++; // 9, 10, 11, 12, 13
        printf("x = %.1lf\n", x);
        y[i] = y[i] + i; // 2 + 0 = 2, 4 + 1 = 5, 8 + 2 = 10, 16 + 3 = 19, 32 + 4 = 36 
        printf("y = %.1lf, i = %d\n", y[i], i);
        //printf(“I=%d  and Y = %.2f   X =  %.2f \n”, i , y[i] , x);
    }
    /*
    ------OUTPUT-------
        x = 9.0
        y = 2.0, i = 0, old_y = 2.0
        x = 10.0
        y = 4.0, i = 1, old_y = 3.0
        x = 11.0
        y = 10.0, i = 2, old_y = 8.0
        x = 12.0
        y = 19.0, i = 3, old_y = 16.0
        x = 13.0
        y = 36.0, i = 4, old_y = 32.0

        float y[5] = {2.0, 4.0, 10.0, 19.0, 36.0};
        y[2] = 10.0;
        y[3] = 19.0;
    */
}


void q1_f(){
    int m = 5;
    float x[] = {2,3,8,16,32};
    f(x[2], x, m);
    printf("The Result is =%.2f and %.2f\n",x[2],x[3]);
}

// -------------------------------------------------------

int k, x;
void g_f(int x){
    int z=0;
    static int y = 0;
    printf("%d %d %d %d\n", x , y , z , k);
    if (x > (y+z)) {      
        y+=2;
        z++; // Changes will effect after exiting if structure but since these are not static typed values it will remain same when function is called 
        x--;
        k += z;
    }
    //printf("%d\n", x); -> you will see x's value decreased by one
}

void q1_g(){
    x = 10;
    k = 8;

    while (x>=k)
        g_f(x);
    printf("%d %d\n", x, k); // 10 11

    /* ------------OUTPUT------------
        10 0 0 8
        10 2 0 9
        10 4 0 10
        10 11
    */ 
}
// -------------------------------------------------------

void q1_i(){
    int a = 6, b = 1, c = 3;

    while(a<b<c){ // a=6 < b= 1 => evaluates to 0(False) and 0 < c=3 => evaluates to 1(True)
        switch(a<b<c){ // evaluates to 1
            default: ++a;
                printf("Default: %d, %d, %d\n", a, b, c);
                continue;
            case 1: --a; --c; printf("Case 1: %d, %d, %d\n", a, b, c);
            case 0: ++b; printf("Case 0: %d, %d, %d\n", a, b, c);
                break;
        }
        printf("%d %d %d\n", a, b, c);
    } 
    /*
    -------OUTPUT-------
        Case 1: 5, 1, 2
        Case 0: 5, 2, 2
        5 2 2
        Case 1: 4, 2, 1
        Case 0: 4, 3, 1
        4 3 1
        Case 1: 3, 3, 0
        Case 0: 3, 4, 0
        3 4 0
    */
}

// -------------------------------------------------------

void q1_j(){
    int a = 0; b = 0; c = 15;

    do{
        printf("res=%d\n", a+b+c);
    } while(++a,b=a+1,c-=a+b);

    /*
        ---------OUTPUT----------
        
        0, 0, 15, res = 15 -> starting point
        1, 2, 12, res = 15 -> true
        2, 3, 7, res = 12 -> true
        3, 4, 0, res = 7 -> false
    */
}

// -------------------------------------------------------

int main(){
        
    q1_i();
        
    return 0;
}