# Raytracer
Epitech Raytracer

Raytracer is a EPITECH 2nd year project. The purpose of our project is to render scenes using raytracing. In our project you can use .cfg file to configure scenes and create plugins.

You can generate one image or open a SFML Window and fast rerender a new screenshot by applying commands or editing the cfg file.

## Organization

The .cfg file must be written like the example.cfg.

The plugins must be in the /plugins folder and generated as .so.

The images are saved in /screenshots folder.

## Commands

You can use commands in the SFML Window:

- "help" to print the commands.
- "exit" to quit the program.
- "translate" {name} {x} {y} {z} to translate an object.
- "rotate" {name} {x} {y} {z} to rotate an object.
- "list" to print the objects.
- "resolution" {x} {y} to change the resolution.

## How to use ?

Build with CMake. ( You must have SFML library. )

./raytracer                   | Launch with SFML the example.cfg file.

./raytracer [scene]           | Launch with SFML the given .cfg file.

./raytracer -render [scene]   | Generate in /screenshots the render of the .cfg file given without open SFML.

./raytracer -h or --help      | Print informations.

## Some examples

![Sphere_example](/screenshots/example.ppm?raw=true "Spheres")

![Sphere_example](/screenshots/example1.png?raw=true "Spheres")

![SolarSystem_example](/screenshots/solarsystem.png?raw=true "SolarSystem")

![Cylinders](/screenshots/cylinders.png?raw=true "Cylinders")

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
      rotation :          // rotation
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
  planes = (
    {
      name = "plane1";  // name
      center :          // position
      {
        x = 0.0;
        y = 0.0;
        z = 0.0;
      };
      direction :       // direction
      {
        x = 1.0;
        y = 0.0;
        z = 0.0;
      };
      direction2 :      // direction2
      {
        x = 0.0;
        y = 0.0;
        z = 1.0;
      };
      rotation :        // rotation
      {
        x = 0.0;
        y = 0.0;
        z = 0.0;
      };
      color :           // color
      {
        r = 0;
        g = 0;
        b = 255;
      };
    } );
```

#### Cylinder

```c
  cylinders = ( 
    {
      name = "cylinder";    // name
      center :              // position
      {
        x = -16.0;
        y = 12.0;
        z = 8.0;
      };
      direction :           // direction
      {
        x = 0.0;
        y = 0.0;
        z = 0.0;
      };
      rotation :            // rotation
      {
        x = 0.0;
        y = 1.0;
        z = 0.0;
      };
      double = 2.0;         // radius
      color :               // color
      {
        r = 0;
        g = 0;
        b = 255;
      };
    } );
```

#### Cone

```c
  cones = ( 
    {
      name = "cone";    // name
      center :          // position
      {
        x = 0.0;
        y = 0.0;
        z = 0.0;
      };
      double = 0.8;     // half the opening angle
      direction :       // direction
      {
        x = 0.0;
        y = 0.0;
        z = 0.0;
      };
      rotation :        // rotation
      {
        x = 1.0;
        y = 1.0;
        z = 1.0;
      };
      color :           // color
      {
        r = 255;
        g = 0;
        b = 255;
      };
    } );
```

#### Triangle

```c
  triangles = ( 
    {
      name = "triangle1";   // name
      center :              // position
      {
        x = 5.0;
        y = 6.0;
        z = 3.6;
      };
      rotation :            // rotation
      {
        x = 0.1;
        y = 0.1;
        z = 3.1;
      };
      direction :           // direction1
      {
        x = 6.0;
        y = 0.0;
        z = 0.0;
      };
      direction2 :          // direction2
      {
        x = 0.0;
        y = 6.0;
        z = 0.0;
      };
      color :               // color
      {
        r = 255;
        g = 64;
        b = 64;
      };
    } );
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
