#include <iostream>
#include <string>
#include <fstream>

void write_image(int WIDTH, int HEIGHT) {
    std::string path("my_image.ppm");
    std::ofstream os(path);

    os << "P3\n" << WIDTH << ' ' << HEIGHT << "\n255\n";

    for (int j = 0; j < HEIGHT; j++)
    {
        std::clog << "\rScanlines remaining: " << (HEIGHT - j) << ' ' << std::flush;
        for (int i = 0; i < WIDTH; i++)
        {
            // transform [0, 1] to rgb color channels
            auto r = double(i) / (WIDTH - 1);
            auto g = double(j) / (HEIGHT - 1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);
            // end of transform

            os << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}