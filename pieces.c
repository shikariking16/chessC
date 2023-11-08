#include <stdio.h>
#include <stdbool.h>

struct piece{

    char name;
    char position[2];
    bool onBoard;
    
};



int main(){

    struct piece rook = {'K', "e5", true};

    printf("%c\n", rook.name);

    return 0;
}