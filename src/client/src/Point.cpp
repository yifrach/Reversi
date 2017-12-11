#include "../include/Point.h"

/**
 * The constructor of the class
 * @param x - an Integer that reopresent the X position
 * @param y - an Integer that reopresent the Y position
 */
Point::Point(int x, int y) : x(x), y(y), grade(0) {
}

/**
 * Getter for our points row
 * @return - an Integer, the row position
 */
int Point::getX() {
  return x;
}


/**
 * Getter for our points col
 * @return - an Integer, the col position
 */int Point::getY() {
  return y;
}

/**
 * Getter for our points grade - number of flips it will make
 * @return - an Integer, number of flips it will make
 */
int Point::getGrade() {
  return grade;
}

/**
 * Increasing our points graded by num
 * @param num - an Integer that we increse the points grade with
 */
void Point::increaseGrade(int num) {
  grade += num;
}

/**
 * Print the point in (x,y) format
 */
void Point::print() {
  cout << "(" << x << "," << y << ")";
}
