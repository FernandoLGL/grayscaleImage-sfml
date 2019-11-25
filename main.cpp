#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    int height{};
    int width{};
    sf::Image img;
    sf::Color pixel;
    int gray{};
    sf::Vector2u imgSize;

    for (int i = 1; i < argc; ++i){
        if(img.loadFromFile(argv[i])){
            imgSize = img.getSize();
            height = imgSize.y;
            width = imgSize.x;

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

            if(img.saveToFile("gray" + std::string(argv[i]))){
                std::cout << "grayscaled " << argv[i] << " saved at: gray" << argv[i] << "\n";
                continue;
            }

            std::cout << "failed to save grayscaled image for" << argv[i] << "\n";
            continue;

        }

        std::cout << "failed to read image file provided: " << argv[i] << "\n";

    }
    return 0;
}
