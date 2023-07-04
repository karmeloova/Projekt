#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platforms.h"
#include "Traps.h"
using namespace sf;

int main()
{
    RenderWindow gameWindow(VideoMode(960, 540), "PlatformGame"); //g³ówne okno gry, tworzone na starcie

    //------------------------TEXTURES-------------------------------
    Texture backgroundTexture, platformTexture, spikesTexture, playerTexture;
    backgroundTexture.loadFromFile("Images/Backgrounds/Level1.png");
    platformTexture.loadFromFile("Images/Platforms/Platform_Wood.png");
    spikesTexture.loadFromFile("Images/Traps/Spikes.png");
    playerTexture.loadFromFile("Images/Characters/Player.png");
    
    //------------------------SPRITES---------------------------------
    Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setScale(0.23, 0.25);

    //------------------------GAMEOBJECTS----------------------------
    Platforms platform1(Vector2f(200.0f, 420.0f), &platformTexture);
    Platforms platform2(Vector2f(420.0f, 370.0f), &platformTexture);
    Platforms platform3(Vector2f(675.0f, 300.0f), &platformTexture);

    Traps spikes1(Vector2f(600.0f, 490.0f), &spikesTexture);

    Player gracz(&playerTexture);
    
    //-----------------------ANOTHERS--------------------------------

    float deltaTime = 0.0f;
    Clock clock;

    //kod, który bêdzie siê wykonywa³ zawsze, gdy okno bêdzie w³¹czone
    while (gameWindow.isOpen()) {

        deltaTime = clock.restart().asSeconds();

        Event event;
        while (gameWindow.pollEvent(event)) {
            if (event.type == Event::Closed) {
                gameWindow.close();
            }
        }
        gracz.Jump();
        gracz.Move(deltaTime);
        gracz.Collide();
        gameWindow.clear();
        gameWindow.draw(backgroundSprite);
        gracz.Draw(gameWindow);
        platform1.Draw(gameWindow);
        platform2.Draw(gameWindow);
        platform3.Draw(gameWindow);
        spikes1.Draw(gameWindow);
        gameWindow.display();
    }

}

