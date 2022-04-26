#include <stdio.h>




void q__10_b(){
    int x = 0, z = -7;
    do{						
    z++;
    printf("z = %d\n", z);						  
    if(x){							  
        printf("How \n");
        if(z == x) printf("z = x = %d\n", z); break;
        printf("Are you \n");
    }
    x -= 2;
    printf("x = %d\n", x);
    printf("Today ? \n");
    }while(z < -3);

}

int main(){
    q__10_b();
    return 0;
}