#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <experimental/random>
#include <list>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
   list<string> lineas;
   fstream imagen;
   imagen.open(/*link de la imagen ascci*/);
   
   string linea;
   while (getline(imagen,linea))
   {
      textos.push_back(linea);
   }
   imagen.close();


  int fotograma = 0;

  string reset;
  int posX = 0;
  int posY = 6;
  while (true)
  {
   fotograma++;

   int r = std::experimental::randint(0, 255);
   int g = std::experimental::randint(0, 255);
   int b = std::experimental::randint(0, 255);

   Element personaje = spinner(21,fotograma);
   Decorator colorFondo = bgcolor(Color::RGB(r,g,b));
   Decorator colorTexto = color(Color::RGB(b,g,r));
   Element dibujo = border({
      hbox(personaje)
   })| colorFondo | colorTexto;

   Dimensions Alto = Dimension::Fixed(10);
   Dimensions Ancho = Dimension::Full();
   
   Screen pantalla = Screen::Create(Ancho, Alto);
   Render(pantalla,dibujo);
   

   int l = 0;
   for (auto &&texto : textos)
   {
      int i = 0;
      for (auto &&letra : textos)
      {
         pantalla.PixelAt(posX + i, posY + l).character = letra;
         i++;
      }
      l++;
   }
   posX++;

   string texto = "Hola";
   int iteracion = 0;

   pantalla.Print();
   reset = pantalla.ResetPosition();
   cout << reset;
   this_thread::sleep_for(0.1s);
  }
  
   return 0;
  

}