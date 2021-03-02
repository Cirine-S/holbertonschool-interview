# Menger Sponge
<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/d/de/Menger_sponge_%28Level_0-3%29.jpg" />
</p>
<p align="center">An illustration of the iterative construction of a Menger sponge up to M3, the third iteration</p>



* In mathematics, the Menger sponge (also known as the Menger cube, Menger universal curve, Sierpinski cube, or Sierpinski sponge) is a fractal curve. It is a three-dimensional generalization of the one-dimensional Cantor set and two-dimensional Sierpinski carpet. It was first described by Karl Menger in 1926, in his studies of the concept of topological dimension.


<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/a/a7/Mengersponge.gif" />
</p>
<p align="center">Menger sponge animation through (4) recursion steps</p>



* In this project, the purpose is to draw a 2D version of the Menger Sponge, which level is indicated by the user.
* A level N sponge is a 3x3 square of level N-1 sponges, except for the center one, which is left empty
* A level 0 sponge is represented by the # character
- Examples:
	A level 0 sponge is a simple 1x1 square
A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty
A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty
…
