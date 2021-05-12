//
// Created by garroakion on 10/5/21.
//

#include "PuzzleWindow.h"

PuzzleWindow::PuzzleWindow() {}
int PuzzleWindow::row=0;
int PuzzleWindow::col=0;
void PuzzleWindow::show() {
    RenderWindow window(sf::VideoMode(1200, 1400), "GENETIC PUZZLE");

    char *file =new char[100];
    FILE *image=popen("zenity --file-selection", "r");
    fgets(file,100,image);
    string fileDir(file);
    delete file;
    std::cout<<fileDir;

    sf::Image CompleteImage;
    if(!CompleteImage.loadFromFile("Genetic Puzzle.png")){
        std::cout<<"Error opening the image";
    }
    sf::Texture subImages[row*col];
    sf::Sprite Frames[row*col];
    int length_x=CompleteImage.getSize().x/col;
    int length_y=CompleteImage.getSize().y/row;
    int id=0;
    for(int x=0;x<row;x++){
        for (int i = 0; i < col ; ++i) {
            subImages[id]=sf::Texture();
            subImages[id].create(length_x,length_y);
            subImages[id].loadFromImage(CompleteImage, sf::IntRect(0+length_x*i,0+length_y*x,length_x,length_y));
            Frames[id]=sf::Sprite();
            Frames[id].setTexture(subImages[id]);
            Frames[id].setPosition(140+length_x*i,140+length_y*x);
            id++;
        }
    }

Frames[0].setPosition(55,87);
    while (window.isOpen()) {
        Event event;
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear(Color(120, 215, 215));
        for (const sf::Sprite& x:Frames) {
            window.draw(x);
        }
        window.draw(Frames[2]);
        window.draw(Frames[2]);
        window.display();
    }
}
