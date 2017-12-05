#ifndef EX2_POINT_H
#define EX2_POINT_H

#include <iostream>
using namespace std;

class Point {
 public:
  Point(int x, int y);

  //getter for our points x row
  int getX();

  //getter for our points y row
  int getY();

  //print the point to the screen
  void print();

  //Getting the number od the disks that will flip in this point
  int getGrade();

  //The method get an Integer and increase the grade member with his value
  void increaseGrade(int num);
 private:
  int x;
  int y;
  int grade;
};

#endif //EX2_POINT_H
