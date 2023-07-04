#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Platforms.h"
#include "Traps.h"
#include "Coins.h"
using namespace sf;

void Restart(Player* gracz, vector<Coins>* coins) {
    if (gracz == nullptr) return;
    gracz->Restart();

    for (int i = 0; i < coins->size(); i++) {
       coins->at(i).isAlive = true; //po restarcie monety pojawiaj¹ siê na nowo
    }

    gracz->points = 0; //zerowanie punktów
}

Vector2f getCenter(Player* gracz) {
    return gracz->GetPosition() + Vector2f(350, -150);
}

int main()
{
    RenderWindow gameWindow(VideoMode(960, 540), "PlatformGame"); //g³ówne okno gry, tworzone na starcie
    gameWindow.setVerticalSyncEnabled(true);//Wlaczenie synchronizacji pionowej
    View view(Vector2f(480,270), Vector2f(960, 540));

    //------------------------TEXTURES-------------------------------
    Texture backgroundTexture, platformTexture, spikesTexture, playerTexture, coinTexture, cactusTexture; 
    backgroundTexture.loadFromFile("Images/Backgrounds/Layer_0.png");
    platformTexture.loadFromFile("Images/Platforms/Platform_Wood.png");
    spikesTexture.loadFromFile("Images/Traps/Spikes.png");
    playerTexture.loadFromFile("Images/Characters/Player.png");
    coinTexture.loadFromFile("Images/Coin.png");
    cactusTexture.loadFromFile("Images/Backgrounds/Layer_4.png");
    
    //------------------------SPRITES---------------------------------
    Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setScale(float(gameWindow.getSize().x / 4320.0f), float(gameWindow.getSize().y / 2160.0f));
    backgroundSprite.setOrigin(4320.0f / 2, 2160.0f / 2);
    Sprite cactusSprite(cactusTexture);
    cactusSprite.setScale(float(gameWindow.getSize().x / 4320.0f), float(gameWindow.getSize().y / 2160.0f));
    cactusSprite.setPosition(200.0f,0.0f);

    //------------------------GAMEOBJECTS----------------------------
    vector<Platforms> platfromsVector;
    platfromsVector.push_back(Platforms(Vector2f(200.0f, 420.0f), &platformTexture));
    platfromsVector.push_back(Platforms(Vector2f(420.0f, 370.0f), &platformTexture));
    platfromsVector.push_back(Platforms(Vector2f(675.0f, 300.0f), &platformTexture));

    vector<Traps> spikesVector;
    spikesVector.push_back(Traps(Vector2f(600.0f, 490.0f), &spikesTexture));

    vector<Coins> coinsVector;
    coinsVector.push_back(Coins(Vector2f(235.0f, 379.0f), &coinTexture));
    coinsVector.push_back(Coins(Vector2f(455.0f, 329.0f), &coinTexture));
    coinsVector.push_back(Coins(Vector2f(710.0f, 260.0f), &coinTexture));

    Player gracz(&playerTexture);
    
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
        gracz.Jump();
        gracz.Move(deltaTime);

        for (int i = 0; i < spikesVector.size(); i++) {
            if (gracz.body.getGlobalBounds().intersects(spikesVector[i].body.getGlobalBounds())) {
                Restart(&gracz, &coinsVector);
            }
        }

        gracz.Collide(&platfromsVector, &spikesVector, &coinsVector);
        gameWindow.clear();
        view.setCenter(getCenter(&gracz));
        gameWindow.setView(view);
        backgroundSprite.setPosition(getCenter(&gracz));
        gameWindow.draw(backgroundSprite);
        gameWindow.draw(cactusSprite);
        gracz.Draw(gameWindow);
        for (int i{ 0 }; i < platfromsVector.size(); i++) {
            platfromsVector[i].Draw(gameWindow);
        }
        for (int i{ 0 }; i < spikesVector.size(); i++) {
            spikesVector[i].Draw(gameWindow);
        }
        for (int i{ 0 }; i < coinsVector.size(); i++) {
            coinsVector[i].Draw(gameWindow);
        }
        gameWindow.display();
    }
   

}
