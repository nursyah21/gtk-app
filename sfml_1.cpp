#include <SFML/Graphics.hpp>

const int WIDTH = 640, HEIGHT = 480;

int main(){
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Ping pong");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color(255,255,255));
  shape.setPosition((float)WIDTH/2-100, (float)HEIGHT/2-100);

  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed){
        window.close();
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}