#include "example.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>
#include <cstdio>
//#include "size.h"


const int FPS = 60.0f;

inline void SetOriginToCenter(sf::Shape &object){
    auto rec = object.getGlobalBounds();
    object.setOrigin(rec.width/2., rec.height/2.);
} 

inline void SetOriginToCenterSprite(sf::Sprite &object){
    auto rec = object.getGlobalBounds();
    object.setOrigin(rec.width/2., rec.height/2.);
} 


//------------------------A mettre dans un .h -----------------------------
// Set a sprite object to Max or Min size
void scaleToMaxSize(sf::Sprite &object){
    float xmax = 1920;
    float ymax = 1080;
    auto rec = object.getGlobalBounds();

    object.setScale(sf::Vector2f(xmax/rec.width, ymax/rec.height));
}

void scaleToMinSize(sf::Sprite &object){
    float xmin = 150;
    float ymin = 150;
    auto rec = object.getGlobalBounds();
    float x = rec.width;
    float y = rec.height;
    float e = y/x;
    float new_x = xmin/x; float new_y = ymin/x;


    if(x<y){
    e = new_x;
    //object.setScale(sf::Vector2f(new_x, e*new_x));
    object.setScale(sf::Vector2f(e, e));
    
    }

    else{
        e = new_y;
        //object.setScale(sf::Vector2f(new_y/e, new_y));
        object.setScale(sf::Vector2f(e, e));
    }
}

void scaleByRadius(sf::Sprite &object){
    auto rec = object.getGlobalBounds();
    float radius = 50;
    float x = rec.width; float y = rec.height;
    float e = y/x;
    object.setScale(sf::Vector2f((2*radius)/(1+e), (2*e*radius)/(1+e)));
}
//---------------------------------------------------------------------------------

int main()
{   
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //Set up of the window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "El cerclo", sf::Style::Default, settings);

    //Set up of the texture
    sf::Texture land_texture;
    land_texture.loadFromFile("/home/ensta/IN104/repository/Images/background.png");
    //Landscape
    sf::Sprite landscape;
    landscape.setTexture(land_texture);
    scaleToMaxSize(landscape);

//////////////////////////////////////////////////////////////////////////////////
    //Set up of the Cylon
    sf::Texture texture_Cylon;
    texture_Cylon.loadFromFile("/home/ensta/IN104/repository/Images/BSGCylon.png");
    sf::Sprite Cylon;
    Cylon.setTexture(texture_Cylon);
    //Scape of the Cylon
    scaleToMinSize(Cylon);
    SetOriginToCenterSprite(Cylon);
    Cylon.setPosition(1920/2,1080/2); 
//--------------------------------------------------------------------------------------
    //Set up of the Viper
    sf::Texture texture_Viper;
    texture_Viper.loadFromFile("/home/ensta/IN104/repository/Images/BSGViper.png");
    sf::Sprite Viper;
    Viper.setTexture(texture_Viper);
    //Scape of the Viper
    //Viper.setScale(sf::Vector2f(0.2f, 0.2f));
    scaleToMinSize(Viper);
    SetOriginToCenterSprite(Viper);
    Viper.setPosition(1920/3,1080/4);

///////////////////////////////////////////////////////////////////////////////////////

   /*  sf::RectangleShape rectangle(sf::Vector2f(500.f, 90.f));
    rectangle.setFillColor(sf::Color(0,0,255));
    SetOriginToCenter(rectangle);
    rectangle.setPosition(540, 360);
 */

    //Set time
    sf::Clock clock;
    float fps = 0;
    //sf::Time time;
    float time;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
        }
        }

        //Time passed since the last restart
       // time = clock.getElapsedTime();

        while((time = clock.getElapsedTime().asSeconds())<=1.0f/FPS){
            continue;
        }
        fps = 1.0f/time;
        printf("fps : %f\n", fps);
        clock.restart();


       /*  if(time.asSeconds() >= 1.0f / FPS){
            //Cylon.rotate(1);
            clock.restart();

            fps = 1.0f/time.asSeconds();
            printf("fps : %f\n", fps);
        }
 */

        window.clear();
        window.draw(landscape);
       window.draw(Cylon);
        window.draw(Viper);
        window.display();
    }

    return 0;
}