#include "../include/Point.h"

/**
 * Constructor for our Point class
 * @param x - the points row position
 * @param y - the points colum position
 */
Point::Point(int x, int y) : x(x), y(y), grade(0) {
}

/**
 * Getter for our points row
 * @return - the points x position
 */
int Point::getX() {
  return x;
}

/**
 * Getter for our points colum
 * @return - the points y position
 */
int Point::getY() {
  return y;
}

/**
 * The method return the grade of this point that represent
 * the number of disks that will flip
 * @return - an Integer, the member grade
 */
int Point::getGrade() {
  return grade;
}

/**
 * The method get an Integer and increase the member grade.
 * @param num - an Integer.
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
