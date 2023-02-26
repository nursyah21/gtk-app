#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <stdlib.h>

const int WIDTH = 640, HEIGHT = 480;

static const GLfloat g_vertex_buffer_data[] = {
    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};

int main(){
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Ping pong");
  sf::Image icon;
  if(!icon.loadFromFile("res/icon.png")) return EXIT_FAILURE;

  window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
  

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color(255,255,255));
  shape.setPosition((float)WIDTH/2-100, (float)HEIGHT/2-100);


  sf::SoundBuffer buffer;
  if(!buffer.loadFromFile("res/bg.ogg")) return EXIT_FAILURE;
  sf::Sound sound;
  sound.setBuffer(buffer);
  sound.setLoop(true);
  sound.play();

  window.setVerticalSyncEnabled(true);

  glDrawArrays(GL_TRIANGLES, 0, 12*3);
  
  constexpr std::array<GLfloat, 180> cube =
  {
      // positions    // texture coordinates
      -20, -20, -20,  0, 0,
      -20,  20, -20,  1, 0,
      -20, -20,  20,  0, 1,
      -20, -20,  20,  0, 1,
      -20,  20, -20,  1, 0,
      -20,  20,  20,  1, 1,

        20, -20, -20,  0, 0,
        20,  20, -20,  1, 0,
        20, -20,  20,  0, 1,
        20, -20,  20,  0, 1,
        20,  20, -20,  1, 0,
        20,  20,  20,  1, 1,

      -20, -20, -20,  0, 0,
        20, -20, -20,  1, 0,
      -20, -20,  20,  0, 1,
      -20, -20,  20,  0, 1,
        20, -20, -20,  1, 0,
        20, -20,  20,  1, 1,

      -20,  20, -20,  0, 0,
        20,  20, -20,  1, 0,
      -20,  20,  20,  0, 1,
      -20,  20,  20,  0, 1,
        20,  20, -20,  1, 0,
        20,  20,  20,  1, 1,

      -20, -20, -20,  0, 0,
        20, -20, -20,  1, 0,
      -20,  20, -20,  0, 1,
      -20,  20, -20,  0, 1,
        20, -20, -20,  1, 0,
        20,  20, -20,  1, 1,

      -20, -20,  20,  0, 0,
        20, -20,  20,  1, 0,
      -20,  20,  20,  0, 1,
      -20,  20,  20,  0, 1,
        20, -20,  20,  1, 0,
        20,  20,  20,  1, 1
  };

  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed){
        window.close();
      }
    }

    glClear(GL_COLOR_BUFFER_BIT);
    window.display();
  }

  // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // window.display();

  // uses sfml
  // while(window.isOpen()){
  //   sf::Event event;
  //   while(window.pollEvent(event)){
  //     if(event.type == sf::Event::Closed){
  //       window.close();
  //     }
  //   }

  //   window.clear();
  //   window.draw(shape);
  //   window.display();
  // }

  return EXIT_SUCCESS;
}