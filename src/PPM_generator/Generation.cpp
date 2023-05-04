/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Generation
*/

#include "Generation.hpp"

PPM::PPM::PPM(int width, int height)
{
    _width = width;
    _height = height;
    _version = "P3";
}

PPM::PPM::~PPM()
{
}

void PPM::PPM::setVersion(std::string version)
{
    _version = version;
}

void PPM::PPM::setPixel(int x, int y, RGB color)
{
    if (x < 0 || x >= _width || y < 0 || y >= _height)
        return;
    _pixels[y * _width + x] = color;
}

void PPM::PPM::bufferToImage(std::vector<RGB> pixels)
{
    for (auto pixel : pixels) {
        _pixels.push_back(pixel);
    }
}

void PPM::PPM::save(const char *filename)
{
    std::ofstream output(filename, std::ios::binary);

    if (output.is_open()) {
        output << _version << std::endl;
        output << _width << std::endl;
        output << _height << std::endl;
        output << "255" << std::endl;

        if (_version == "P3") {
            for (int i = 0; i < _height; i++) {
                for (int j = 0; j < _width; j++) {
                    output << (int)_pixels[i * _width + j].r << " ";
                    output << (int)_pixels[i * _width + j].g << " ";
                    output << (int)_pixels[i * _width + j].b << "\n";
                }
            }
        } else {
            for (int i = 0; i < _height; i++) {
                for (int j = 0; j < _width; j++)
                    output.write((char *)&_pixels[i * _width + j], sizeof(RGB));
            }
        }
    }
    output.close();
}

void PPM::PPM::clear()
{
    fill({0, 0, 0});
}

void PPM::PPM::fill(RGB color)
{
    for (int i = 0; i < _width * _height; i++)
        _pixels.push_back(color);
}

PPM::RGB PPM::operator*(const RGB &color, const double &coef)
{
    double r = color.r;
    double g = color.g;
    double b = color.b;

    RGB newcolor = {(unsigned char)(std::min(r * coef, 255.0)), (unsigned char)(std::min(g * coef, 255.0)), (unsigned char)(std::min(b * coef, 255.0))};

    return newcolor;
}

PPM::RGB PPM::operator*(const double &coef, const RGB &color)
{
    return color * coef;
}

std::ostream &PPM::operator<<(std::ostream &os, const RGB &color)
{
    os << "(" << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ")";
    return os;
}