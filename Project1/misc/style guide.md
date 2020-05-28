# Naming Convention and Comment Convention

Yifan Zhang

Sara Nelson

Yiwen Xu

Brendan Ritchie

## Commenting

* Using [Doxygen](<http://www.doxygen.nl/>)
* [wiki of Doxygen](<https://github.com/alexarmstrongvi/Tutorial-Doxygen/wiki>)
* **example**:

```pseudocode
/** This filtered pixel calculation method uses its stored kernel to
   determine the new ColorData for a specified pixel in a PixelBuffer
   @param buffer a pointer to a PixelBuffer argument
   @param x the x position of the specified pixel within buffer
   @param y the y position of the specified pixel within buffer */
```

* for classes:

```pseudocode
/** @brief This convolution filter class provides the methods necessary to
 create a convolution kernel for filtering an image. It also stores the
 convolution kernel used to calculate a pixel's new value after filtering. */
```

* Single Line Comments
  * before line of code
* tags comments:
  * to do tage

## Naming Convention

* source file
  * .cc
* head file
  * .h
* indention:
  * 2 spaces
* parameters for functions:
  * snake case
* member variable:
  * camel case
  * with an underscore at the end
* function names:
  * camel case
* class names:
  * pascal case
* 180 characters for each line

 