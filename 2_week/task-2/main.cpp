#include <iostream>
#include "utils.h"

#ifndef WIDTH
#define WIDTH 480
#endif

#ifndef HEIGHT
#define HEIGHT 320
#endif

int main() {
    std::string path("my_image.ppm");
    write_image(path, WIDTH, HEIGHT);
    return 0;
}
