#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

int main()
{
    char buffer[4];
    const char PNG[4] = { -119, 80, 78, 71 };

    std::string filePath;
    std::cout << "Please, input a way to your your file: " << std::endl;
    std::getline(std::cin, filePath);
    std::ifstream readPath;
    readPath.open(filePath, std::ios::binary);

    if (!readPath.is_open())
    {
        std::cerr << "Fail to open file or mistake in a path to it" << std::endl;
        return 1;
    }
    else {
        readPath.read(buffer, sizeof(buffer));
    }

    bool isPng = true;
    for (int i = 0; i < 4; ++i) {
        if (buffer[i] != PNG[i]) {
            isPng = false;
            break;
        }
    }

    if (!isPng) {
        std::cout << "It is not png file!" << std::endl;
    }
    else {
        std::cout << "It is a PNG file." << std::endl;
    }

    return  0;
}
