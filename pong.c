#include <stdio.h>
#define MAP_SIZE_X 80
#define MAP_SIZE_Y 25

void printMap(int xPong, int yPong, int firstPlayer, int secondPlayer);
int movePlayers(int player, char symbol);
int movePongX(int pongX, int direction);
int movePongY(int pongY, int direction);
int switchDirection(int direction, int xPong, int yPong);
int checkLose(int xPong, int yPong, int player, int temp);


int main() {

    int xPong = 40;
    int yPong = 12;
    int firstPlayer = 12;
    int secondPlayer = 12;
    int scoreFirstPlayer = 0;
    int scoreSecondPlayer = 0;
    int direction = -1;
    int temp1 = 0;
    int temp2 = 0;

    while(1) {
        char symbol = getchar();
        if (symbol == '\n')
            continue;
        printf("SCORE ----- firstPlayer: %d : %d secondPlay\n", scoreFirstPlayer, scoreSecondPlayer);
        direction = switchDirection(direction, xPong, yPong);
        xPong = movePongX(xPong, direction);
        yPong = movePongY(yPong, direction);
        if (symbol == 'a' || symbol == 'z') {
            firstPlayer += movePlayers(firstPlayer, symbol);
        } else if (symbol == 'k' || symbol == 'm') {
            secondPlayer += movePlayers(secondPlayer, symbol);
        }
        printMap(xPong, yPong, firstPlayer, secondPlayer);
        // if ((temp1 = checkLose(xPong, yPong, firstPlayer, 1) == -1))
        scoreSecondPlayer -= checkLose(xPong, yPong, firstPlayer, 1);
        scoreFirstPlayer -= checkLose(xPong, yPong, firstPlayer, 80);
        printf(" %d\n", direction);
    }
    return 0;
}

void printMap(int xPong, int yPong, int firstPlayer, int secondPlayer) {
    for (int y = 0; y <= MAP_SIZE_Y + 1; y++) {
        for (int x = 0; x <= MAP_SIZE_X; x++) {
            if (y == 0 || y == MAP_SIZE_Y + 1) {
                printf("-");
            } else if (x == 0 && (y - 1 == firstPlayer || y == firstPlayer || y + 1 == firstPlayer)) {
                printf("|");
            } else if (x == MAP_SIZE_X && (y - 1 == secondPlayer || y == secondPlayer || y + 1 == secondPlayer)) {
                printf("|");
            } else if (x == xPong && y == yPong) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n%d %d\n", xPong, yPong);
}

int movePlayers(int player, char symbol) {
    int moveTo = 0;
    if (player != 2 && (symbol == 'a' || symbol == 'k')){
        moveTo = -1;
    } else if (player != 24 && (symbol == 'z' || symbol == 'm')) {
        moveTo = 1;
    }
    return moveTo;
}

int movePongX(int pongX, int direction) {
    if (direction > 0) {
        pongX++;
    } else if (direction < 0) {
        pongX--;
    }
    return pongX;
}

int movePongY(int pongY, int direction) {
    if (direction < 0) {
        direction *= -1;
    }
    if (direction == 1) {
        pongY--;
    } else if (direction == 2) {
        pongY++;
    }
    return pongY;
}

int switchDirection(int direction, int xPong, int yPong) {
    if (yPong == 1) {
        if (direction < 0)
            direction = -2;
        else 
            direction = 2;
    } else if (yPong == 25) {
        if (direction < 0)
            direction = -1;
        else 
            direction = 1;
    } else if (xPong == 1 || xPong == 79) {
        direction = -direction;
    }
    return direction;
}

int checkLose(int xPong, int yPong, int player, int temp) {
    int lose;
    if (xPong == temp && player - 1 && yPong && player != yPong && player + 1 != yPong) {
        lose = -1;
    } else {
        lose = 0;
    }
    return lose;
}