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

![Sphere_example](/screenshots/example.ppm?raw=true "Spheres")

## CFG configuration:

### Camera

```
camera : 
{
  camera_position : 
  {
    x = 0.0;
    y = 5.0;
    z = -60.0;
  };
  fov : 
  {
    fov = 60.0;
  };
};
```

### Primitives

```c
primitives : 
 {
```

#### Sphere

```c
  spheres = (
    {
      name = "my_sphere"; // name
      center :            // position
        {
          x = -30.0;
          y = 5.0;
          z = 0.0;
        };
      rotation :          // rotation (it's useless for a sphere)
        {
          x = 0.0;
          y = 0.0;
          z = 0.0;
        };
      double = 5.0;       // radius
      color :             // color
        {
          r = 0;
          g = 250;
          b = 0;
        };
    }
    );
```

#### Plane

```c

```

#### Cylinder

```c

```

#### Cone

```c

```

#### Triangle

```c

```

```
 };
```

### Lights

```c
lights : 
 {
```

#### Ambient Light

```c
  ambientlights = ( 
    {
      name = "my_light"; // name
      center :           // position
        {
          x = -17.0;
          y = 6.0;
          z = 2.0;
        };
      double = 0.6;      // physical size, 0.0 if invisible
      color :            // color of the physical light
        {
          r = 255;
          g = 255;
          b = 255;
        }
    });
```

#### Directional Light

```c
  directionallights = ( 
    {
      name = "my_light"; // name
      rotation :         // direction of the light
        {
          x = 0.0;
          y = 1.0;
          z = 0.0;
        };
      double = 0.6;      // physical size, 0.0 if invisible
      color :            // color of the physical light
        {
          r = 255;
          g = 255;
          b = 255;
        }
    });
```

#### Spot Light

```c
  spotlights = ( 
    {
      name = "my_light"; // name
      center :           // position
        {
          x = -17.0;
          y = 6.0;
          z = 2.0;
        };
      rotation :         // direction of the spot
        {
          x = 0.0;
          y = 1.0;
          z = 0.0;
        };
      double = 0.6;      // physical size, 0.0 if invisible
      double2 = 45.0;    // angle of the light
      color :            // color of the physical light
        {
          r = 255;
          g = 255;
          b = 255;
        }
    });
```

```c
 };
```

### Options

```c
options : 
  {
    resolution : 
    {
      x = 1920;
      y = 1080;
    };
  };
```
