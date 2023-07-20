#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platforms.h"
#include "Traps.h"
#include "Coins.h"
#include "CactusClass.h"
#include "Buttons.h"
using namespace sf;

void Restart(Player* gracz) {
   
    if (gracz == nullptr) return;
    gracz->lives = gracz->lives - 1; 
    gracz->Restart(); 

}

float getCenter(Player* gracz) {
    if (gracz == nullptr) return 0;
    return gracz->body.getPosition().x + 350.0f;
}

int main()
{
    int sceneNumber = 0; //Do zmieniania scen
    string scoreString, lifeString; //Teksty do wyœwietlania scoreString - pokazuje ile mamy punktów, lifeString - do pokazywania ile mamy ¿yæ
    RenderWindow gameWindow(VideoMode(960, 540), "PlatformGame"); //g³ówne okno gry, tworzone na starcie
    gameWindow.setVerticalSyncEnabled(true);//Wlaczenie synchronizacji pionowej
    gameWindow.setFramerateLimit(100);
    View view(Vector2f(480,270), Vector2f(960, 540)); //Ustaw widok na œrodek ekranu o wielkoœci ekranu

    //------------------------TEXTURES-------------------------------
    Texture backgroundTexture, platformTexture, spikesTexture, playerTexture, coinTexture, cactusTexture, buttonTexture, finishflagTexture; 

    if (!backgroundTexture.loadFromFile("Images/Backgrounds/Layer_0.png")) cout<<"Background image loading error"<<endl;  //T³o ze s³oñcem
    if (!platformTexture.loadFromFile("Images/Platforms/Platform_Wood.png")) cout << "Platform Image loading error"<<endl; //Drewniana platforma
    if (!spikesTexture.loadFromFile("Images/Traps/Spikes.png")) cout << "Spikes image loading error" << endl; //Kolce
    if (!playerTexture.loadFromFile("Images/Characters/Player.png")) cout << "Player image loading error" << endl; //Gracz
    if (!coinTexture.loadFromFile("Images/Coin.png")) cout << "Coin image loading error" << endl; //Pieni¹dze
    if (!cactusTexture.loadFromFile("Images/Backgrounds/Layer_4.png")) cout << "Cactus image loading error" << endl; //Kaktusy w tle poziomu 1
    if (!buttonTexture.loadFromFile("Images/Buttons/Button.png")) cout << "Button image loading error" << endl; //Przycisk
    if (!finishflagTexture.loadFromFile("Images/FinishFlag.png")) cout << "FinishFlag image loading error" << endl; //Flaga sygnalizuj¹ca koniec poziomu

    //------------------------SPRITES---------------------------------
    Sprite backgroundSprite(backgroundTexture), finishflagSprite(finishflagTexture);

    backgroundSprite.setScale(float(gameWindow.getSize().x / 4320.0f), float(gameWindow.getSize().y / 2160.0f));
    backgroundSprite.setOrigin(4320.0f / 2, 2160.0f / 2);
    finishflagSprite.setPosition(5100.0f, 340.0f);
    finishflagSprite.setScale(0.3, 0.3);

    //------------------------GAMEOBJECTS----------------------------
    vector<Platforms> platformsVector; //vector - dynamicznie rozszerzaj¹ca siê tablica 
    platformsVector.push_back(Platforms(Vector2f(200.0f, 370.0f), &platformTexture, 0)); //push_back - dodanie elementu na koniec wektora
    platformsVector.push_back(Platforms(Vector2f(420.0f, 320.0f), &platformTexture, 0));
    platformsVector.push_back(Platforms(Vector2f(675.0f, 250.0f), &platformTexture, 0));
    platformsVector.push_back(Platforms(Vector2f(950.0f, 300.0f), &platformTexture, 0));
    platformsVector.push_back(Platforms(Vector2f(1200.0f, 300.0f), &platformTexture, 0));
    platformsVector.push_back(Platforms(Vector2f(1400.0f, 170.0f), &platformTexture, 0));
    platformsVector.push_back(Platforms(Vector2f(1750.0f, 320.0f), &platformTexture, 0));
    platformsVector.push_back(Platforms(Vector2f(2300.0f, 320.0f), &platformTexture, true));
    platformsVector.push_back(Platforms(Vector2f(2480.0f, 400.0f), &platformTexture, 0));
    platformsVector.push_back(Platforms(Vector2f(2745.0f, 400.0f), &platformTexture, 0));
    platformsVector.push_back(Platforms(Vector2f(2900.0f, 300.0f), &platformTexture, 0));
    platformsVector.push_back(Platforms(Vector2f(4000.0f, 400.0f), &platformTexture, 0));
    platformsVector.push_back(Platforms(Vector2f(-135.0f, 470.0f), (Vector2f(1035.0f, 30.0f))));
    platformsVector.push_back(Platforms(Vector2f(1200.0f, 470.0f), (Vector2f(500.0f, 30.0f))));
    platformsVector.push_back(Platforms(Vector2f(3050.0f, 470.0f), (Vector2f(300.0f, 30.0f))));
    platformsVector.push_back(Platforms(Vector2f(3550.0f, 470.0f), (Vector2f(200.0f, 30.0f))));
    platformsVector.push_back(Platforms(Vector2f(4400.0f, 470.0f), (Vector2f(1000.0f, 30.0f))));

 
    vector<Traps> spikesVector;
    spikesVector.push_back(Traps(Vector2f(600.0f, 420.0f), &spikesTexture));
    spikesVector.push_back(Traps(Vector2f(1320.0f, 270.0f), &spikesTexture));
    spikesVector.push_back(Traps(Vector2f(2600.0f, 370.0f), &spikesTexture));
    spikesVector[2].body.setScale(0.45, 1);

    vector<Coins> coinsVector;
    coinsVector.push_back(Coins(Vector2f(235.0f, 329.0f), &coinTexture));
    coinsVector.push_back(Coins(Vector2f(455.0f, 280.0f), &coinTexture));
    coinsVector.push_back(Coins(Vector2f(710.0f, 210.0f), &coinTexture));
    coinsVector.push_back(Coins(Vector2f(1435.0f, 130.0f), &coinTexture));
    coinsVector.push_back(Coins(Vector2f(2625.0f, 280.0f), &coinTexture));
    coinsVector.push_back(Coins(Vector2f(4035.0f, 355.0f), &coinTexture));
    coinsVector.push_back(Coins(Vector2f(4500.0f, 420.0f), &coinTexture));
    coinsVector.push_back(Coins(Vector2f(4600.0f, 420.0f), &coinTexture));
    coinsVector.push_back(Coins(Vector2f(4700.0f, 420.0f), &coinTexture));

    vector<CactusClass> cactusVector;
    cactusVector.push_back(CactusClass(&cactusTexture, gameWindow, 0));
    cactusVector.push_back(CactusClass(&cactusTexture, gameWindow, 1));
    cactusVector.push_back(CactusClass(&cactusTexture, gameWindow, 2));
    cactusVector.push_back(CactusClass(&cactusTexture, gameWindow, 3));
    cactusVector.push_back(CactusClass(&cactusTexture, gameWindow, 4));
    cactusVector.push_back(CactusClass(&cactusTexture, gameWindow, 5));

    Player gracz(&playerTexture);

    Buttons playButton(Vector2f(-85, -150), &buttonTexture, "Play", Vector2f(-43, -140));

    //---------------------TEXT--------------------------------------

    Font gameFont;
    gameFont.loadFromFile("Fonts/consola.ttf");
    Text scoreText("Points: ", gameFont, 30);
    Text livesText("Lives: ", gameFont, 30);
    Text endText("You lost. Press Enter to try again.", gameFont, 30);
    Text wonText("You won! Press Enter to play again.", gameFont, 30);
    
    //-----------------------ANOTHERS--------------------------------

    float deltaTime = 0.0f;
    Clock clock;
    float lastFrame{ 0 };//czas kiedy pojawila sie poprzednia klatka

    //kod, który bêdzie siê wykonywa³ zawsze, gdy okno bêdzie w³¹czone
    while (gameWindow.isOpen()) {               
        float deltaTime = clock.getElapsedTime().asMilliseconds() - lastFrame; //czas jaki minal miedzy dwoma klatkami animacji
        lastFrame = clock.getElapsedTime().asMilliseconds();

        Event event;
        while (gameWindow.pollEvent(event)) {
            if (event.type == Event::Closed) {
                gameWindow.close();
            }
        }

     

        switch (sceneNumber) {
            case 0: //MENU GRY
                gameWindow.clear();
                gameWindow.draw(backgroundSprite);
                playButton.Draw(gameWindow);
                if(playButton.clickOnButton(gameWindow, 480, 270)) sceneNumber = 1;;
                gameWindow.setView(view);
                view.setCenter(0, 0);
                gameWindow.display();
                break;
            case 1: //POZIOM 1
                gracz.Jump(); //Wykonuj funkcjê Jump ca³y czas kiedy okno jest otwarte 
                gracz.Move(deltaTime, gameWindow); //Wykonuj funkcjê Move ca³y czas kiedy okno jest otwarte 
                platformsVector[7].MovingPlatform(deltaTime);
                for (int i = 0; i < spikesVector.size(); i++) {
                    if (gracz.body.getGlobalBounds().intersects(spikesVector[i].body.getGlobalBounds())) {
                        Restart(&gracz);
                    }
                }

                scoreString = "Points: " + to_string(gracz.points);
                lifeString = "Lives: " + to_string(gracz.lives);
                scoreText.setString(scoreString);
                livesText.setString(lifeString);

                if (gracz.body.getPosition().y > gameWindow.getSize().y + 200.0f) Restart(&gracz);
                if (gracz.lives == 0) sceneNumber = 2;
                if (gracz.body.getPosition().x > 5135.f) sceneNumber = 3;

                gracz.Collide(&platformsVector, &spikesVector, &coinsVector);
                gameWindow.clear();
                if (gracz.body.getPosition().x < 4530.5f) {
                    view.setCenter(getCenter(&gracz), 270.0f);
                    gameWindow.setView(view);
                    backgroundSprite.setPosition(getCenter(&gracz), 270.0f);
                    scoreText.setPosition(getCenter(&gracz) - 475.0f, 0); //Dziêki temu text przesuwa siê wraz z graczem, a nie zostaje na pocz¹tku
                    livesText.setPosition(getCenter(&gracz) - 475.0f, 30.0f); //To samo co wy¿ej, ale obni¿one o 30
                }
                else {
                    view.setCenter(4880.5f, 270.0f);
                    gameWindow.setView(view);
                    backgroundSprite.setPosition(4880.5f, 270.0f);
                    scoreText.setPosition(4880.5f - 475.0f, 0); //Dziêki temu text przesuwa siê wraz z graczem, a nie zostaje na pocz¹tku
                    livesText.setPosition(4880.5f - 475.0f, 30.0f); //To samo co wy¿ej, ale obni¿one o 30
                }
                livesText.setFillColor(Color(0,0,0));
                gameWindow.draw(backgroundSprite);
                for (int i{ 0 }; i < cactusVector.size(); i++) {
                    cactusVector[i].Draw(gameWindow);
                }
                gameWindow.draw(scoreText);
                gameWindow.draw(livesText);
                gameWindow.draw(finishflagSprite);
                gracz.Draw(gameWindow);
                for (int i{ 0 }; i < platformsVector.size(); i++) {
                    platformsVector[i].Draw(gameWindow);
                }

                for (int i{ 0 }; i < spikesVector.size(); i++) {
                    spikesVector[i].Draw(gameWindow);
                }
                for (int i{ 0 }; i < coinsVector.size(); i++) {
                    coinsVector[i].Draw(gameWindow);
                }
                gameWindow.display();
                break;
            case 2: 
                gameWindow.clear();
                endText.setPosition(100,250);
                gameWindow.draw(backgroundSprite);
                gameWindow.draw(endText);
                gameWindow.setView(view);
                gameWindow.display();
                if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                    for (int i = 0; i < coinsVector.size(); i++) {
                        coinsVector[i].isAlive = true; //po restarcie monety pojawiaj¹ siê na nowo
                    }
                    gracz.points = 0;
                    sceneNumber = 1;
                    gracz.lives = 3;
                }
                break;
            case 3:
                gameWindow.clear();
                wonText.setPosition(-300, 0);
                View view2(Vector2f(480, 270), Vector2f(960, 540));
                view2.setCenter(0, 0);
                gameWindow.draw(backgroundSprite);
                backgroundSprite.setPosition(0, 0);
                gameWindow.draw(wonText);
                gameWindow.setView(view2);
                gameWindow.display();
                if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                    for (int i = 0; i < coinsVector.size(); i++) {
                        coinsVector[i].isAlive = true; //po restarcie monety pojawiaj¹ siê na nowo
                    }
                    gracz.Restart();
                    gracz.points = 0;
                    sceneNumber = 1;
                    gracz.lives = 3;
                }
                break;
        }
    }
}