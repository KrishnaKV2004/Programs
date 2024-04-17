#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20
#define MAX_LENGTH (WIDTH * HEIGHT)

int snakeX[MAX_LENGTH], snakeY[MAX_LENGTH];
int length, direction;
int fruitX, fruitY;
int gameOver;

void setup() {
    length = 1;
    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;
    direction = 1;
    gameOver = 0;
    srand(time(NULL));
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
}

void draw() {
    system("cls"); // Clear screen
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1)
                printf("#"); // Draw walls
            else if (x == fruitX && y == fruitY)
                printf("*"); // Draw fruit
            else {
                int printSnake = 0;
                for (int i = 0; i < length; i++) {
                    if (snakeX[i] == x && snakeY[i] == y) {
                        printf("O"); // Draw snake
                        printSnake = 1;
                    }
                }
                if (!printSnake)
                    printf(" ");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", length - 1);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                direction = 0;
                break;
            case 'd':
                direction = 1;
                break;
            case 'w':
                direction = 2;
                break;
            case 's':
                direction = 3;
                break;
            case 'x':
                gameOver = 1;
                break;
        }
    }
}

void logic() {
    int prevX = snakeX[0];
    int prevY = snakeY[0];
    int prev2X, prev2Y;
    snakeX[0] = snakeX[0] + (direction == 1 ? 1 : direction == 0 ? -1 : 0);
    snakeY[0] = snakeY[0] + (direction == 3 ? 1 : direction == 2 ? -1 : 0);
    for (int i = 1; i < length; i++) {
        prev2X = snakeX[i];
        prev2Y = snakeY[i];
        snakeX[i] = prevX;
        snakeY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    if (snakeX[0] == fruitX && snakeY[0] == fruitY) {
        length++;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    }
    for (int i = 1; i < length; i++) {
        if (snakeX[i] == snakeX[0] && snakeY[i] == snakeY[0])
            gameOver = 1;
    }
    if (snakeX[0] <= 0 || snakeX[0] >= WIDTH - 1 || snakeY[0] <= 0 || snakeY[0] >= HEIGHT - 1)
        gameOver = 1;
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        // Change the speed of the game by adjusting the sleep duration
        // Sleep duration is in milliseconds
        // For slower speed, increase the sleep duration
        // For faster speed, decrease the sleep duration
        Sleep(100); // Sleep for 100 milliseconds
    }
    printf("Game Over! Your score was: %d\n", length - 1);
    return 0;
}   