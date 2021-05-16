//
// Created by garroakion on 10/5/21.
//

#include <nlohmann/json.hpp>
#include <iterator>
#include "PuzzleWindow.h"
#include "../../Socket_Client.h"


PuzzleWindow::PuzzleWindow() {}
int PuzzleWindow::row=0;
int PuzzleWindow::col=0;
int PuzzleWindow::length_x=0;
int PuzzleWindow::length_y=0;
void PuzzleWindow::show() {
    Socket_Client * socket = Socket_Client::self;

    RenderWindow window(sf::VideoMode(1200, 1400), "GENETIC PUZZLE");

    char *file =new char[150];
    FILE *image=popen("zenity --file-selection", "r");
    fgets(file,150,image);
    string fileDir(file);
    delete file;
    fileDir.pop_back();
    sf::Image CompleteImage;
    if(!CompleteImage.loadFromFile(fileDir.data())){
        std::cout<<"Error opening the image";
    }

    sf::Texture subImages[row*col];
    sf::Sprite Frames[row*col];
    vector<int> RGBFIT(row*3);
    vector<int>  redFrames(row*col);
    vector<int>  greenFrames(row*col);
    vector<int>  blueFrames(row*col);
    length_x=CompleteImage.getSize().x/col;
    length_y=CompleteImage.getSize().y/row;
    int id=0;
    int id_RGB=0;
    for(int x=0;x<row;x++){
        int r=0;
        int g=0;
        int b=0;
        for (int i = 0; i < col ; ++i) {
            int colorR=0;
            int colorG=0;
            int colorB=0;
            subImages[id]=sf::Texture();
            subImages[id].create(length_x,length_y);
            subImages[id].loadFromImage(CompleteImage, sf::IntRect(0+length_x*i,0+length_y*x,length_x,length_y));
            colorR=(CompleteImage.getPixel(1 + length_x * i, 1 + length_y * x).r);
            colorG=(CompleteImage.getPixel(1 + length_x * i, 1 + length_y * x).g);
            colorB=(CompleteImage.getPixel(1 + length_x * i, 1 + length_y * x).b);
            r+= colorR;
            g+= colorG;
            b+= colorB;
            redFrames[id]= colorR;
            greenFrames[id]= colorG;
            blueFrames[id]= colorB;
            Frames[id]=sf::Sprite();
            Frames[id].setTexture(subImages[id]);
            Frames[id].setPosition(140+length_x*i,140+length_y*x);
            id++;
        }
        RGBFIT[id_RGB]=r;
        RGBFIT[id_RGB+1]=g;
        RGBFIT[id_RGB+2]=b;
        id_RGB+=3;
    }

    nlohmann::basic_json<> data;
    data["Objective"]= RGBFIT;
    data["Red"]= redFrames;
    data["Blue"]= blueFrames;
    data["Green"]= greenFrames;
    data["Rows"]= row;
    data["Columns"]= col;
    std::cout<<data;
    std::string startOrder=socket->comunicatte(to_string(data));

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
        window.display();
    }
}

void PuzzleWindow::order(Sprite *subimages, int *order) {
    int id=0;
    for(int x=0;x<row;x++){
        for (int i = 0; i < col ; ++i) {
            subimages[order[id]].setPosition(140+length_x*i,140+length_y*x);
            id++;
        }
    }

}



