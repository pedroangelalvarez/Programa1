#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "Pelota.h"
#include "Jugador.h"

int definirDireccionX();
int definirDireccionY();
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Atari");

    Pelota p = Pelota(398,298,10,'a',10,10,1,1);
    sf::CircleShape ballon(p.get_radio());
    ballon.setFillColor(sf::Color::Yellow);
    ballon.setPosition(p.get_x(),p.get_y());

    Jugador jugador1(10,250,50,10);
    sf::RectangleShape player1 (sf::Vector2f(jugador1.get_ancho(),jugador1.get_largo()));
    player1.setFillColor(sf::Color::White);
    player1.setPosition(jugador1.get_x(),jugador1.get_y());

    Jugador jugador2(780,250,50,10);
    sf::RectangleShape player2 (sf::Vector2f(jugador2.get_ancho(),jugador2.get_largo()));
    player2.setFillColor(sf::Color::White);
    player2.setPosition(jugador2.get_x(),jugador2.get_y());

    p.direccionarX(definirDireccionX());
    p.direccionarY(definirDireccionY());
    while (window.isOpen())
    {   std::this_thread::sleep_for (std::chrono::milliseconds(100));
        p.moverse();
        ballon.setPosition(p.get_x(),p.get_y());
        if (p.get_x()<1) {
            p.moverX(398);
            p.moverY(298);
            p.direccionarX(definirDireccionX());
            p.direccionarY(definirDireccionY());
        }
        else if( p.get_x() >= 790){
            p.moverX(398);
            p.moverY(298);
            p.direccionarX(definirDireccionX());
            p.direccionarY(definirDireccionY());
        }
        if (p.get_y()<1) {
            p.direccionarY(1);
        }
        else if( p.get_y() >= 590){
            p.direccionarY(0);
        }

        if (ballon.getGlobalBounds().intersects(player1.getGlobalBounds())){
            p.colision();
        }
        if (ballon.getGlobalBounds().intersects(player2.getGlobalBounds())){
            p.colision();
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::KeyPressed){
                if (event.key.code == sf::Keyboard::Up){
                    jugador1.mover(1);
                }
                if (event.key.code == sf::Keyboard::Down){
                    jugador1.mover(0);
                }
                if (event.key.code == sf::Keyboard::W){
                    jugador2.mover(1);
                }
                if (event.key.code == sf::Keyboard::S){
                    jugador2.mover(0);
                }
                player1.setPosition(jugador1.get_x(),jugador1.get_y());
                player2.setPosition(jugador2.get_x(),jugador2.get_y());
            }
            if (event.type == sf::Event::Closed)
                window.close();

        }

        window.clear();
        window.draw(ballon);
        window.draw(player1);
        window.draw(player2);
        window.display();
    }

    return 0;
}

int definirDireccionX(){
    int initialX = rand() % 10 + 1;

    if (initialX%2==0){
        return 0;
    }
    else{
        return 1;
    }
    return 0;
}

int definirDireccionY(){
    int initialY = rand() % 10 + 1;
    if (initialY%2==0){
        return 0;
    }
    else{
        return 1;
    }
    return 0;
}