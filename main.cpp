#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char* argv[]){
    int height{};
    int width{};
    sf::Image img;
    sf::Color pixel;
    if(img.loadFromFile(argv[1])){
    sf::Vector2u imgSize = img.getSize();
    height = imgSize.y;
    width = imgSize.x;
    int gray{};

    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            pixel = img.getPixel(j, i);
            gray = (pixel.r * 0.3 + pixel.g * 0.59 + pixel.b * 0.11);
            pixel.r = gray;
            pixel.g = gray;
            pixel.b = gray;
            img.setPixel(j,i,pixel);
        }
    }

    if(img.saveToFile("imgGray.png")){
        std::cout << "grayscaled image saved at 'imgGray.png'\n";
        return 0;
    }

    std::cout << "failed to save grayscaled image\n";

    return 1;

    }

    std::cout << "failed to read image file provided\n";
    return 1;
}
