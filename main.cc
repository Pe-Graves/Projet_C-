#include <iostream>
//#include <SFML/Graphics.hpp>
#include "Singes.hh"
#include "Gorille.hh"
#include "GorilleUp.hh"
#include "Gibon.hh"
#include "GibonUp.hh"
#include "Macaque.hh"
#include "MacaqueUp.hh"


using namespace std;

int main()
{
    /*sf::RenderWindow window(sf::VideoMode(1000, 1000), "Planète des singes");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }*/

    Gorille a;
    cout << a << endl;

    GorilleUp b;
    cout << b << endl;

    Gibon c;
    cout << c << endl;

    GibonUp d;
    cout << d << endl;

    Macaque e;
    cout << e << endl;

    MacaqueUp f;
    cout << f << endl;

    return 0;
}
