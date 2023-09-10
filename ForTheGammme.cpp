#include "ForTheGammme.hpp"


void ForTheGame()
{

    //Здесь находятся первичные координаты
    //Просто рисуется сама змейка
    for (int i = tailY; i > 0; i--)
    {
        s[i].snakeX = s[i - 1].snakeX;
        s[i].snakeY = s[i - 1].snakeY; 

    }

    //движение змеи
    if (tailX == 0)
    {
        s[0].snakeY += 1; //вниз
    }
    if (tailX == 1)
    {
        s[0].snakeX -= 1; //влево
    }
    if (tailX == 2)
    {
        s[0].snakeX += 1; //право
    }
    if (tailX == 3)
    {
        s[0].snakeY -= 1; //вверх
    }

    //чтобы змея не исчезала за картой
    if (s[0].snakeX > hight)
    {
        s[0].snakeX = 0;
    }
    if (s[0].snakeX < 0)
    {
        s[0].snakeX = hight;
    }
    if (s[0].snakeY > width)
    {
        s[0].snakeY = 0;
    }
    if (s[0].snakeY < 0)
    {
        s[0].snakeY = width;
    }

    //манипуляции с яблоком 
    if ((s[0].snakeX == f.fruitX) && (s[0].snakeY == f.fruitY))
    {
        tailY++;

        //рандомно распологаем фрукт
        f.fruitX = rand() % hight;
        f.fruitY = rand() % width;

    }

    //условие проигрыша
    for (int i = 1; i < tailY; i++)
    {
        if ((s[0].snakeX == s[i].snakeX) && (s[0].snakeY == s[i].snakeY))
        {
            endOfGame = false;
        }
    }

}

void ForTheGame2()
{
    //Здесь находятся первичные координаты
    //Просто рисуется сама змейка
    for (int i = tailY; i > 0; i--)
    {
        s[i].snakeX = s[i - 1].snakeX;
        s[i].snakeY = s[i - 1].snakeY;

    }

    //движение змеи
    if (tailX == 0)
    {
        s[0].snakeY += 1; //вниз
    }
    if (tailX == 1)
    {
        s[0].snakeX -= 1; //влево
    }
    if (tailX == 2)
    {
        s[0].snakeX += 1; //право
    }
    if (tailX == 3)
    {
        s[0].snakeY -= 1; //вверх
    }

    //чтобы за стеной не исчезала
    if (s[0].snakeX > hight2)
    {
        s[0].snakeX = 0;
    }
    if (s[0].snakeX < 0)
    {
        s[0].snakeX = hight2;
    }
    if (s[0].snakeY > width2)
    {
        s[0].snakeY = 0;
    }
    if (s[0].snakeY < 0)
    {
        s[0].snakeY = width2;
    }


    //манипуляции со злыми змеями 
    if ((s[0].snakeX == v.villianX) && (s[0].snakeY == v.villianY))
    {
        counterOfLives -= 1;

        //рандомно распологаем змеяя
        v.villianX = rand() % hight2;
        v.villianY = rand() % width2;


        //рандомно распологаем змеяя
        v2.villianX2 = rand() % hight2;
        v2.villianY2 = rand() % width2;

        //рандомно распологаем фрукт
        f.fruitX = rand() % hight2;
        f.fruitY = rand() % width2;

    }

    //манипуляции со злыми змеями 
    if ((s[0].snakeX == v2.villianX2) && (s[0].snakeY == v2.villianY2))
    {
        counterOfLives -= 1;

        //рандомно распологаем змеяя
        v.villianX = rand() % hight2;
        v.villianY = rand() % width2;


        //рандомно распологаем змеяя
        v2.villianX2 = rand() % hight2;
        v2.villianY2 = rand() % width2;

        //рандомно распологаем фрукт
        f.fruitX = rand() % hight2;
        f.fruitY = rand() % width2;

    }


    //манипуляции с яблоком 
    if ((s[0].snakeX == f.fruitX) && (s[0].snakeY == f.fruitY))
    {
        tailY++;

        //рандомно распологаем фрукт
        f.fruitX = rand() % hight2;
        f.fruitY = rand() % width2;

        //рандомно распологаем змеяя
        v.villianX = rand() % hight2;
        v.villianY = rand() % width2;

        //рандомно распологаем змеяя
        v2.villianX2 = rand() % hight2;
        v2.villianY2 = rand() % width2;

    }

    if (counterOfLives == 0)
    {
        endOfGame = false;
    }

    //условие проигрыша
    for (int i = 1; i < tailY; i++)
    {
        if ((s[0].snakeX == s[i].snakeX) && (s[0].snakeY == s[i].snakeY) || (counterOfLives == 0))
        {
            endOfGame = false;
        }
    }

}


void StartGame01()
{
    RenderWindow window(VideoMode(hight * cube, width * cube), "ANIMAL_CANNIBAL");

    Texture ground;
    ground.loadFromFile("C:/Users/ЛЕРА/Desktop/tiles.png"); //открываем файл
    Sprite tiles(ground);

    Texture snake;
    snake.loadFromFile("C:/Users/ЛЕРА/Desktop/snake.png"); //открываем файл
    Sprite snakesss(snake);

    Texture apple;
    apple.loadFromFile("C:/Users/ЛЕРА/Desktop/Eggs.png"); //открываем файл
    Sprite applesss(apple);

    Texture gg;
    gg.loadFromFile("C:/Users/ЛЕРА/Desktop/gg.png"); //открываем файл
    Sprite gameOver(gg);
    gameOver.setPosition(-20, 0);

    Clock clock; //отвечает за игровое время
    float timer = 0, delay = 0.2;


    while (window.isOpen())
    {
        for (int i = 0; i < hight; i++)
        {
            for (int j = 0; j < width; j++)
            {
                tiles.setPosition(i * cube, j * cube); //позиция расположения клеток
                window.draw(tiles); //рисуем 
            }
        }

        //Игровое время
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;


        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }


        //Управление змейкой через клавиатуру
        if (Keyboard::isKeyPressed(Keyboard::A)) //Если стрелка влево нажата
        {
            tailX = 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) //Если стрелка вправо нажата
        {
            tailX = 2;
        }
        if (Keyboard::isKeyPressed(Keyboard::W)) //Если стрелка вверх нажата
        {
            tailX = 3;
        }
        if (Keyboard::isKeyPressed(Keyboard::S))  //Если стрелка вниз нажата
        {
            tailX = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::X))  //Если стрелка вниз нажата
        {
            endOfGame = false;
            window.draw(gameOver);
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                window.close();
            }
        }


        if (timer > delay && endOfGame)
        {
            timer = 0;
            ForTheGame();
        }


        window.clear();


        //двумерный массив 
        for (int i = 0; i < hight; i++)
        {
            for (int j = 0; j < width; j++)
            {
                tiles.setPosition(i * cube, j * cube); //позиция расположения клеток
                window.draw(tiles); //рисуем 
            }
        }


        //ресуем змею
        for (int i = 0; i < tailY; i++)
        {

            if (i != 0)
            {
                snakesss.setTextureRect(IntRect(0, 0, cube, cube));
            }
            else
            {
                snakesss.setTextureRect(IntRect(tailX * cube, cube, cube, cube));
            }

            snakesss.setPosition(s[i].snakeX * cube, s[i].snakeY * cube);
            window.draw(snakesss);


        }

        //рисуем яблоко
        applesss.setPosition(f.fruitX * cube, f.fruitY * cube);
        window.draw(applesss);

        //gg
        if (!endOfGame)
        {
            window.draw(gameOver);
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                window.close();
            }
        }

        window.display();
    }

}

void StartGame02()
{

    RenderWindow window(VideoMode(hight2 * cube, width2 * cube), "ANIMAL_CANNIBAL");

    Texture ground;
    ground.loadFromFile("C:/Users/ЛЕРА/Desktop/tiles.png"); //открываем файл
    Sprite tiles(ground);

    Texture snake;
    snake.loadFromFile("C:/Users/ЛЕРА/Desktop/snake.png"); //открываем файл
    Sprite snakesss(snake);

    Texture apple;
    apple.loadFromFile("C:/Users/ЛЕРА/Desktop/Eggs.png"); //открываем файл
    Sprite applesss(apple);

    Texture vil;
    vil.loadFromFile("C:/Users/ЛЕРА/Desktop/villian.png"); //открываем файл
    Sprite villian(vil);
    villian.setPosition(-20, 0);

    Texture gg;
    gg.loadFromFile("C:/Users/ЛЕРА/Desktop/gg.png"); //открываем файл
    Sprite gameOver(gg);
    gameOver.setPosition(-20, 0);

    Clock clock; //отвечает за игровое время
    float timer = 0, delay = 0.2;

    //рандомно распологаем змея
    v.villianX = rand() % hight2;
    v.villianY = rand() % width2;

    v2.villianX2 = rand() % hight2;
    v2.villianY2 = rand() % width2;


    while (window.isOpen())
    {
        for (int i = 0; i < hight2; i++)
        {
            for (int j = 0; j < width2; j++)
            {
                tiles.setPosition(i * cube, j * cube); //позиция расположения клеток
                window.draw(tiles); //рисуем 
            }
        }

        //Игровое время
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;


        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }


        //Управление змейкой через клавиатуру
        if (Keyboard::isKeyPressed(Keyboard::A)) //Если стрелка влево нажата
        {
            tailX = 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) //Если стрелка вправо нажата
        {
            tailX = 2;
        }
        if (Keyboard::isKeyPressed(Keyboard::W)) //Если стрелка вверх нажата
        {
            tailX = 3;
        }
        if (Keyboard::isKeyPressed(Keyboard::S))  //Если стрелка вниз нажата
        {
            tailX = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::X))  //Если стрелка вниз нажата
        {
            window.close();

            RenderWindow window(VideoMode(hight * cube, width * cube), "ANIMAL_CANNIBAL");

            Texture gg;
            gg.loadFromFile("C:/Users/ЛЕРА/Desktop/gg.png"); //открываем файл
            Sprite gameOver(gg);
            gameOver.setPosition(-20, 0);

            while (window.isOpen())
            {
                endOfGame = false;
                window.draw(gameOver);
                if (Keyboard::isKeyPressed(Keyboard::A))
                {
                    window.close();
                }

                window.display();
            }
        }

        if (timer > delay && endOfGame)
        {
            timer = 0;
            ForTheGame2();
        }

        window.clear();


        //двумерный массив 
        for (int i = 0; i < hight2; i++)
        {
            for (int j = 0; j < width2; j++)
            {
                tiles.setPosition(i * cube, j * cube); //позиция расположения клеток
                window.draw(tiles); //рисуем 
            }
        }

        //ресуем змею
        for (int i = 0; i < tailY; i++)
        {
            if (i != 0)
            {
                snakesss.setTextureRect(IntRect(0, 0, cube, cube));
            }
            else
            {
                snakesss.setTextureRect(IntRect(tailX * cube, cube, cube, cube));
            }

            snakesss.setPosition(s[i].snakeX * cube, s[i].snakeY * cube);
            window.draw(snakesss);
        }

        //рисуем яблоко
        applesss.setPosition(f.fruitX * cube, f.fruitY * cube);
        window.draw(applesss);

        //рисуем змею
        villian.setPosition(v.villianX * cube, v.villianY * cube);
        window.draw(villian);

        //рисуем змею
        villian.setPosition(v2.villianX2 * cube, v2.villianY2 * cube);
        window.draw(villian);

        //gg
        if (!endOfGame)
        {
            window.close();

            RenderWindow window(VideoMode(hight * cube, width * cube), "ANIMAL_CANNIBAL");

            Texture gg;
            gg.loadFromFile("C:/Users/ЛЕРА/Desktop/gg.png"); //открываем файл
            Sprite gameOver(gg);
            gameOver.setPosition(-20, 0);

            while (window.isOpen())
            {
                window.draw(gameOver);
                if (Keyboard::isKeyPressed(Keyboard::A))
                {
                    window.close();
                }
                window.display();
            }

        }

        window.display();
    }
}
