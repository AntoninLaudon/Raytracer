/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Generation
*/

#pragma once

#include <fstream>
#include <iostream>
#include <cmath>

namespace PPM {
    struct RBG {
        unsigned char r;
        unsigned char g;
        unsigned char b;
    };
    class PPM {
        public:
            PPM(int width, int height);
            ~PPM();
            void setVersion(std::string version);
            void setPixel(int x, int y, RBG color);
            void save(const char *filename);
            void clear();
            void fill(RBG color);
        protected:
        private:
            int _width;
            int _height;
            std::string _version;
            RBG *_pixels;
    };
}
