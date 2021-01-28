#include <SFML/Graphics.hpp>
#include <iostream>

std :: size_t testMouse1(int posx, int posy)
{
    if(posx >= 5 && posx <= 313)
    {
        if(posy >= 660 && posy <= 790)
            {
                return 1;
            }
    }
    if(posx >= 880 && posx <= 1190)
    {
        if(posy >= 660 && posy <= 795)
        {
            return 2;
        }
    }
    return 0;
}

std :: size_t testMouse2(int posx, int posy)
{
    if(posx >= 530 && posx <= 645)
    {
        if(posy >= 590 && posy <= 705)
            {
                return 3;
            }
    }
    if(posx >= 880 && posx <= 1190)
    {
        if(posy >= 660 && posy <= 795)
        {
            return 4;
        }
    }
    return 0;
}


int main()
{
    std :: size_t recup = 0;
    std :: size_t nbPage = 0;
    bool start = false;
    bool page1 = false;


    sf :: RenderWindow window(sf::VideoMode(1200, 800), "L'arene des Singes");
    sf :: Texture image;
    sf :: Texture image2;
    sf :: Sprite background;
    sf :: Sprite nouveau;


    if (!image.loadFromFile("Images/Page_1.jpg")) // Si le chargement du fichier a échoué
    {
        std :: cout << "Erreur durant le chargement de l'image"<< std :: endl;
        return EXIT_FAILURE; // On ferme le programme
    }
    else // Si le chargement de l'image a réussi
    {
        background.setTexture(image); 
    }

    if (!image2.loadFromFile("Images/Page_2.png")) // Si le chargement du fichier a échoué
    {
        std :: cout << "Erreur durant le chargement de l'image"<< std :: endl;
        return EXIT_FAILURE; // On ferme le programme
    }
    else // Si le chargement de l'image a réussi
    {
        nouveau.setTexture(image2); 
    }
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    switch(nbPage)
                    {
                        case 0:
                            recup = testMouse1(event.mouseButton.x, event.mouseButton.y);
                            break;
                        case 1:
                            recup = testMouse2(event.mouseButton.x, event.mouseButton.y);
                            break;
                    }    
                    std :: cout << "recup : " << recup << std :: endl; 
                    std :: cout << "nbPage: " << nbPage << std :: endl;                 
                }
            }

        }

        if(recup == 1)
        {
            window.close();
            break;
        }
        if(recup == 2 && !page1)
        {
            window.clear();
            window.draw(nouveau);
            window.display();
            start = true;
            nbPage = 1;
        }
        if(recup == 3)
        {
            window.clear();
            // window.draw(nouveau);
            window.display();
            page1 = true;
            nbPage = 2;
        }
        if(!recup && !start)
        {
            window.clear();
            window.draw(background);
            window.display();
        }

    }

    return 0;
}


