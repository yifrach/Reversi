#include "../include/Point.h"

Point::Point(int x, int y) : x(x), y(y), grade(0) {
}

// Getter for our points row
int Point::getX() {
  return x;
}


// Getter for our points colum
int Point::getY() {
  return y;
}

// Getter for our points grade - number of flips it will make
int Point::getGrade() {
  return grade;
}

// Increasing our points graded by num
void Point::increaseGrade(int num) {
  grade += num;
}


// Print the point in (x,y) format
void Point::print() {
  cout << "(" << x << "," << y << ")";
}
