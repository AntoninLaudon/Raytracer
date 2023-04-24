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
    struct RGB {
        unsigned char r;
        unsigned char g;
        unsigned char b;
    };
    class PPM {
        public:
            /**
             * @brief Construct a new PPM object
             * 
             * @param width 
             * @param height 
             */
            PPM(int width, int height);
            /**
             * @brief Destroy the PPM object
             * 
             */
            ~PPM();
            /**
             * @brief Set the Version object
             * 
             * @param version 
             */
            void setVersion(std::string version);
            /**
             * @brief Set the Pixel object
             * 
             * @param x 
             * @param y 
             * @param color 
             */
            void setPixel(int x, int y, RGB color);
            /**
             * @brief Transform a buffer of RGB into an in _pixels.
             * 
             * @param pixels 
             */
            void bufferToImage(const RGB **pixels);
            /**
             * @brief Save the image in _pixels into a file.
             * 
             * @param filename 
             */
            void save(const char *filename);
            /**
             * @brief clear the _pixels buffer.
             * 
             */
            void clear();
            /**
             * @brief Fill the _pixels buffer with a color.
             * 
             * @param color 
             */
            void fill(RGB color);
        protected:
        private:
            /**
             * @brief Width of the image.
             * 
             */
            int _width;
            /**
             * @brief Height of the image.
             * 
             */
            int _height;
            /**
             * @brief Version of the PPM file.
             * 
             */
            std::string _version;
            /**
             * @brief The pixels of the final image.
             * 
             */
            RGB *_pixels;
    };
}
