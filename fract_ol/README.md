# 42seoul-fract_ol

## Summary
This project is meant to create graphically beautiful fractal.

## Objectives
Now that you took over your first graphical library: the <b>miniLibX</b>,\
it's time for you to light all the pixels of your screen at the same time!\
\
This new project will be the opportunity for you to hone your <b>miniLibX</b> skills, to\
make you discover/use the mathematical notion of <b>complex numbers</b> and to take a peek\
at the concept of <b>optimization</b> in computer graphics.

## General Instructions
- This project will be corrected by humans only. So, feel free to organize and name\
  your files as you wish, but within the constraints listed here.
- You cannot use global variables.
- You must code in <b>C</b>.
- Your project must follow <b>the Norm</b>.
- You have to handel errors carefully. In no way can your program quit unexpectely\
  (Segmentation falut, bus error, double free, etc).
- Your program cannot have memory leaks.
- You must use the <b>miniLibX</b>. Either in the version that is available on the system,\
  or from its sources. If you choose to work with the sources, you will need to apply\
  the same rules for your <b>libft</b> as those written above.
  
## Mandetory part - fractol
![image](https://user-images.githubusercontent.com/74703501/149436693-24fce2e6-9159-470b-ba4b-df7664be6ae8.png)\
\
This project's goal is to create a small fractal exploration program. Start by seeing\
what a fractal is.\
\
The constraints are as follows:
- Your software should offer the Julia set and Mandelbrot set.
- The mouse wheel zooms in and out, almost infinitely (within the limits of the\
  computer). This is the very principle of fractals.
- You must use at least a few colors to show the depth of each fractal. It's even better\
  if you hack away on psychedelic effects.
- A parameter is passed on the command line to define what type of fractal will be\
  viewed. If no parameter is provided, or if the parameter is invalid, the program\
  displays a list of available parameters and exits properly.
- More parameters must be used for fractal parameters or ignored.
- You must be able to create differenet Julia set with the parameters of the program.
\
As for the graphic representation:
- ESC will exit the program.
- The use of images of the minilibX is strongly recommended.

## Bonus part
Here are some interesting ideas for the bonuses.
- One more different fractal (there are more than a hundred different types of fractals\
  referenced online).
- The zoom follows the actual mouse position.
- In addition to the zoom: moving with the arrows.
- Make the color range shift.

## What I Learned
- Computer graphics
- Complex numbers, Complex plane
- Optimization
- miniLibX 사용법
- Fractal

### General Reviews
fract_ol 과제는 computer graphics 기술을 사용하여 fractal 모형을 화면에 보이게 하는 것이 목표이다.\
computer graphics란 기술을 처음 접해서 공부해야 할 내용이 많았다.\
가장 기본적인 pixel의 개념과 pixel을 다루는 법, 색을 표현하는 방법 등 많은 것을 공부했다.\
그리고 화면에 나타내는 fractal 모형에 대한 공부도 필요했다.\
fractal 모형이란 모형의 전체가 부분과 완전히 똑같거나 비슷한 모양으로 반복되는 모형을 이야기한다.\
fractal 모형을 이해하기 위해서는 복소수에 대해서 공부해야 됐고, 각각의 fractal 모형을 그리기 위한 식도 이해해야 됐다.\
이 많은 것을 공부해서 프로그램을 완성하니 정말 뿌듯했다.\
computer graphics 과제 중에 수학적인 개념이 필요한 과제라 가장 어렵다고 들어서, 이에 도전했는데 하길 잘했다고 생각했다.\
내가 모르는 것이 많을수록 많이 배울 수 있다는 것을 머릿속에 심고 이후 과제도 열심히 해야겠다.
