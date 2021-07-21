
#include "Buttom.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;


int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window");
    //zmienne
    sf::RectangleShape pasek;
    pasek.setSize({1000, 100});
    pasek.setPosition(100, 900);


    //obrazy
    sf::Image zdj1;
    sf::Image zdj2;
    sf::Image zdjExport;
    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture textureExport;
    sf::Sprite sprite1;
    sf::Sprite sprite2;
    sf::Sprite spriteExport;
    bool sprite1Shown = false, sprite2Shown = false;
    bool flagaText = false;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    Buttom button1("Wczytaj", font);
    button1.setPosition({20, 900});
    Buttom button2("Przytnij", font);
    button2.setPosition({200, 900});
    Buttom button3("Podglad", font);
    button3.setPosition({400, 900});
    Buttom button4("Blend", font);
    button4.setPosition({600, 900});
    Buttom button5("Zapisz", font);
    button5.setPosition({900, 900});

    zdj2.loadFromFile("zdj2.jpg");
    texture2.loadFromImage(zdj2);
    sprite2.setTexture(texture2);

    string input;
    sf::Text inputText("yes", font, 30);
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                //button1 - > Załaduj plik do okna

                if (button1.isMouseOver(window) == true) {
                    //minipasek
                    //wpisywanie
                    //enter = ok
                    //sprite1 wczytujemy
                    flagaText = true;
                }
                //button2 -> Przytnij pliczek załadowany

                if (button2.isMouseOver(window) == true) {

                    //zmienne a,b,c,d;
                    int poczx, poczy, szer, wys;
//                    cout << "w pocz x" << endl;
//                    cin >> poczx;
//                    cout << "w pocz y" << endl;
//                    cin >> poczy;
                    cout << "szer" << endl;
                    cin >> szer;
                    cout << "wys" << endl;
                    cin >> wys;
                    if (szer < zdj1.getSize().x || wys < zdj1.getSize().y) {

                        textureExport.loadFromImage(zdj1, sf::IntRect(poczx, poczy, szer, wys));

                        sf::Image ZdjecieEdit3;
                        ZdjecieEdit3.create(szer, wys, sf::Color::Black);
                        for (int i = 0; i < szer; i++) {
                            for (int j = 0; j < wys; j++) {
                                    if (i < szer && j < wys) {
                                        sf::Color org = zdj1.getPixel(i, j);
                                        ZdjecieEdit3.setPixel(i, j, org);
                                    }
                            }
                        }
                        zdj1 = ZdjecieEdit3;

                    }else
                        cout<<"Podano zły zakres przyciecia zdjecia ,wychodza poza x i y obrazu"<<endl;
                }
                //button3  - > Podglad przycietego
                if (button3.isMouseOver(window) == true) {
                    sf::Texture texture2;
                    texture2.loadFromImage(zdj1);
                    texture2.setRepeated(true);
                    sf::Sprite spriteTexture;
                    spriteTexture.setTexture(texture2);

                    spriteExport.setTexture(textureExport);
                    sf::RenderWindow exportWindow(sf::VideoMode(1920, 1080), "Export");

                    while (exportWindow.isOpen()) {
                        sf::Event event1;
                        while (exportWindow.pollEvent(event1)) {
                            if (event1.type == sf::Event::Closed)
                                exportWindow.close();

                        }


                        // clear the window with black color
                        exportWindow.clear(sf::Color::Black);
                        exportWindow.draw(spriteTexture);
                        // end the current frame
                        exportWindow.display();
                    }


                }
                //button4 - > Blend
                if (button4.isMouseOver(window) == true) {
                    sf::Color color = sf::Color(0, 0, 55, 55);
                    string sciezka2;
                    cout << "podaj sciezke do obrazu nr dwa\n";
                    cin >> sciezka2;
                    cout << "podaj wartosc przeswitu\n";
                    int alfa;
                    cin >> alfa;

                    sf::Image zdjecie2;
                    sf::Image ZdjecieEdit2;
                    zdjecie2.loadFromFile(sciezka2);
                    int xx, yy;

                    if (zdj1.getSize().x > zdjecie2.getSize().x)
                        xx = zdjecie2.getSize().x;
                    else
                        xx = zdj1.getSize().x;
                    if (zdj1.getSize().y > zdjecie2.getSize().y)
                        yy = zdjecie2.getSize().y;
                    else
                        yy = zdj1.getSize().y;

                    ZdjecieEdit2.create(xx, yy, color);
                    sf::Color color1;
                    sf::Color color2;
                    sf::Color docelowy;



                    for (int i = 0; i < xx; i++) {
                        for (int j = 0; j < yy; j++) {
                            if(j%2==0){
                                color1=zdj1.getPixel(i,j);
                                docelowy=sf::Color(color1.r,color1.g,color1.b,alfa);
                                ZdjecieEdit2.setPixel(i,j,docelowy);

                            }

                            else {
                                color2 = zdjecie2.getPixel(i, j);
                                docelowy = sf::Color(color2.r, color2.g, color2.b, alfa);
                                ZdjecieEdit2.setPixel(i, j, docelowy);
                            }

                        }
                    }
                    zdj1 = ZdjecieEdit2;
                }
                //button5   -> Zapisz
                if (button5.isMouseOver(window) == true) {
                    string scieszka;
                    cout << "scieszka" << endl;
                    cin >> scieszka;
                    zdjExport = textureExport.copyToImage();
                    zdjExport.saveToFile(scieszka);
                }

            }
            if (event.type == sf::Event::TextEntered && flagaText == true) {
                if (event.text.unicode == 8) {
                    input = input.substr(0, input.length() - 1);
                    inputText.setString(input);
                } else if (event.text.unicode == 13) {

                    zdj1.loadFromFile(input);
                    texture1.loadFromImage(zdj1);
                    sprite1.setTexture(texture1);
                    flagaText = false;
                    sprite1Shown = true;
                    input = "";
                    break;
                } else if (event.text.unicode < 128 && event.text.unicode != 13 && event.text.unicode != 8) {
                    cout << input << endl;
                    cout << static_cast<char>(event.text.unicode) << endl;
                    input += static_cast<char>(event.text.unicode);
                    inputText.setFillColor(sf::Color::White);
                    inputText.setString(input);
                }
            }
            //buttomy


        }

        // clear the window with black color
        window.clear(sf::Color::Black);

//        if (guzik.hover(window) == true)
//            guzik.body.setFillColor
//                    (sf::Color(180, 180, 180));
//        else guzik.body.setFillColor(sf::Color(200, 200, 200));
        //rysowanie

        if (sprite1Shown == true) window.draw(sprite1);
        if (sprite2Shown == true) window.draw(sprite2);
        window.draw(pasek);
        button1.drawTo(window);
        button2.drawTo(window);
        button3.drawTo(window);
        button4.drawTo(window);
        button5.drawTo(window);
        window.draw(inputText);
        // end the current frame
        window.display();


    }
    return 0;
}