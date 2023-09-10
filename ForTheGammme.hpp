#ifndef FORTHEGAMMMEHPP
#define FORTHEGAMMMEHPP

#include "HeadFile.hpp"

using namespace sf;


static struct SnakeTheGame
{
    int snakeX;
    int snakeY;

}s[600];

static struct Fruit
{
    int fruitX, fruitY;
}f;

static struct Villian
{
    int villianX, villianY;
}v;

static struct Villian2
{
    int villianX2, villianY2;
}v2;


//длина и ширина плиток
static int hight = 35, width = 20;
static int hight2 = 35, width2 = 10;
static int cube = 35; //размер плиток

//для хвоста змеи
static int tailX, tailY;
static int tailsCount = 0;

static int counterOfLives = 3;

static bool endOfGame = true;

void ForTheGame();
void ForTheGame2();
void StartGame01();
void StartGame02();

void StartGame01();
void StartGame02();




#endif 
