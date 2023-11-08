#include <stdio.h>

struct Square {
    char piece;
    char colour;
};


void printBoard(){

    int board[8][8];
    for (int x = 0; x < 8; x++){
    for (int y = 0; y < 8; y++){
        board[x][y] = 0;
    }
    }

    for (int x = 0; x < 8; x++){
    for (int y = 0; y < 8; y++){
        
        if (x == 0 && y == 0){
            printf("WR ");

        }else if(y == 7){
            printf("%d  \n", board[x][y]);

        }else{
            printf("%d  ", board[x][y]);
        }

    }
    }
}

void pieces(){
    /*
        W-K



    */
}

int main(){
    printBoard();
    return 0;
}

