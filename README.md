# Raytracer
Epitech Raytracer

Raytracer is a EPITECH 2nd year project. The purpose of our project is to render scenes using raytracing. In our project you can use .cfg file to configure scenes and create plugins.

You can generate one image or open a SFML Window and rerender fast a new screenshot by applying commands or editing the cfg file.

## Organization

The .cfg file must be written like the example.cfg.

The plugins must be in the /plugins folder and generated as .so.

The images are saved in /screenshots folder.

## How to use ?

Build with CMake. ( You must have SFML library. )

./raytracer                   | Launch with SFML the example.cfg file.

./raytracer [scene]           | Launch with SFML the given .cfg file.

./raytracer -render [scene]   | Generate in /screenshots the render of the .cfg file given.

./raytracer -h or --help      | Print informations.

## Some examples

![Sphere_example](/screenshots/example1.png?raw=true "Spheres")

![SolarSystem_example](/screenshots/solarsystem.png?raw=true "SolarSystem")

![Cylinders](/screenshots/cylinders.png?raw=true "Cylinders")