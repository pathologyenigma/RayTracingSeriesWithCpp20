export module Renderer;
import Renderer.Vec3;
import <iostream>;

namespace renderer {

    export inline constexpr int IMAGE_WIDTH = 256;

    export inline constexpr int IMAGE_HEIGHT = 256;

    export void render();

    void render()
    {
        std::cerr << "Render Start!" << std::endl;
        std::cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n255\n";
        for (int i = IMAGE_HEIGHT - 1; i >= 0; --i) {
            std::cerr << "\rRendering: " << static_cast<double>((IMAGE_HEIGHT - i) * 100) / static_cast<double>(IMAGE_HEIGHT) << '%' << ' ' << std::flush;
            for (int j = 0; j < IMAGE_WIDTH; ++j) {
                auto r = double(j) / (IMAGE_HEIGHT - 1);
                auto g = double(i) / (IMAGE_WIDTH - 1);
                auto b = 0.25;

                int ir = static_cast<int>(255.999 * r);
                int ig = static_cast<int>(255.999 * g);
                int ib = static_cast<int>(255.999 * b);

                std::cout << ir << ' ' << ig << ' ' << ib << '\n';
            }
        }
        std::cerr << "\rRendering: 100.0000%\nRendering Completed!" << std::flush;
    }
    export using vec = vec3;
};