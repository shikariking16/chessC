#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <ctype.h>



struct piece{
    int type;
    int position;
};

    // int board[64] = {
    //     4, 3, 2, 5, 6, 2, 3, 4,
    //     1, 1, 1, 1, 1, 1, 1, 1,
    //     0, 0, 0, 0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0, 0, 0, 0,
    //     -1, -1, -1, -1, -1, -1, -1, -1,
    //     -4, -3, -2, -5, -6, -2, -3, -4
    // };

char* intToChessCoordinate(int number) {
    // Turn the ints 0,1,3 etc and translate it to the correct position on the board

    char* coordinate = (char*)malloc(3 * sizeof(char)); // Allocate memory for the coordinate
    if (coordinate != NULL) {
        coordinate[0] = 'a' + (number % 8);   // Calculate the file (a-h)
        coordinate[1] = '1' + (number / 8);   // Calculate the rank (1-8)
        coordinate[2] = '\0'; // Null-terminate the string
    }
    return coordinate;
}

char typeToString(int type){
    // Convert the type (int) into a char which I can read
    char stringType;
    bool isNegative = false;

     if (type < 0){
            isNegative = true;
            type *= -1;
        }

    switch(type){
        case 6:
            stringType = 'k';
            break;
        case 5:
            stringType = 'q';
            break;
        case 4:
            stringType = 'r';
            break;
        case 3:
            stringType = 'n';
            break;
        case 2:
            stringType = 'b';
            break;
        case 1:
            stringType = 'p';
            break;
        case 0:
            stringType = 'x';
            break;
    }
    
    if (isNegative){
        return toupper(stringType);
    }else{
        return stringType;
    }

}

int* fenToBoard(const char fen[]) {
    //rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR the starting order for FEN

    int* board = (int*)malloc(64 * sizeof(int)); // Allocate memory for the board

    int x = 0;
    for (int i = 0; fen[i] != '\0'; i++) {
        char curDigit = fen[i];
        int tmpValue = 0;
        bool isBlack = false;

        if (isupper(curDigit)){
            isBlack = true;
            curDigit = tolower(curDigit);
        }

        if (isdigit(curDigit)) {
            x += (int)(curDigit - '0') - 1; // Convert character digit to integer
        } else {
            switch (curDigit) {
                case 'k':
                    tmpValue = 6;
                    break;
                case 'q':
                    tmpValue = 5;
                    break;
                case 'r':
                    tmpValue = 4;
                    break;
                case 'n':
                    tmpValue = 3;
                    break;
                case 'b':
                    tmpValue = 2;
                    break;
                case 'p':
                    tmpValue = 1;
                    break;
                case ' ':
                    tmpValue = 0;
                    break;
                case '/':

                    break;
                    
            }
            if (isBlack){
                tmpValue = tmpValue * -1;
            }
            board[x] = tmpValue;
        }
        if (curDigit != '/'){
            x++;
        }
    }

    return board;
}

void printBoard(const char fen[]){
    // Enter the fen of the game you want and it will position the pieces as so.
    int* newBoard = fenToBoard(fen);

    int row = 8;
    for (int i = 0; i < 64; i++){
        if (i % 8 == 0){
            printf("\n%d|", row);
            row--;
        }
        printf(" %c ", typeToString(newBoard[i]));
    }
    printf("\n");
    char col = 'A';
    printf("  ");
    for (int i = 0; i < 8; i++){
        printf(" %c ", col);
        col++;
    }
    printf("\n");
    const char* whiteKing = "\xE2\x99\x94";

    // Print the white king character
    printf("%s\n", whiteKing);
}

int main(){
    // Using the intToChessCoordinate function to map the values to coordinates
    // char* result = intToChessCoordinate(chessBoard[0]);
    // printf("%s\n", result);
    // free(result); 

    // Create an array of structures to represent the pieces
    // struct piece whitePieces[16];
    // struct piece blackPieces[16];

    // Initialize the Pieces array with the positions and types 
    // int whitePieceCount = 0;
    // int blackPieceCount = 0;

    // for (int i = 0; i < 64; i++) {
    //     if (board[i] > 0) {
    //         whitePieces[whitePieceCount].type = board[i];
    //         whitePieces[whitePieceCount].position = i;
    //         whitePieceCount++;
    //     } else if (board[i] < 0) {
    //         blackPieces[blackPieceCount].type = board[i];
    //         blackPieces[blackPieceCount].position = i;
    //         blackPieceCount++;
    //     }
    // }

    // Print the positions and types of the pieces
    // for (int i = 0; i < whitePieceCount; i++) {
    //     //printf("Piece: %c, Position: %s\n", typeToString(whitePieces[i].type), intToChessCoordinate(whitePieces[i].position));
    // }
    // for (int i = 0; i < blackPieceCount; i++) {
    //     //printf("Piece: %c, Position: %s\n", typeToString(blackPieces[i].type), intToChessCoordinate(blackPieces[i].position));
    // }


    // char board2[64] = {  'r','n','b','q','k','b','n','r', 
    //                      'P','P','P','P','P','P','P','P', 
    //                      '8','8','8','8','8','8','8','8',
    //                      '8','8','8','8','8','8','8','8', 
    //                      '8','8','8','8','8','8','8','8', 
    //                      '8','8','8','8','8','8','8','8',
    //                      'p','p','p','p','p','p','p','p',
    //                      'R','N','B','Q','K','B','N','R',
    //                    };

    // Testing the fen function
    printBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    //printBoard("r1bk3r/p2pBpNp/n4n2/1p1NP2P/6P1/3P4/P1P1K3/q5b1");
    //rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR the starting order for FEN


    return 0;
}