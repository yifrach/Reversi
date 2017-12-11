#ifndef EX2_POINT_H
#define EX2_POINT_H
#include <iostream>
using namespace std;

class Point {
 public:
  //constructor
  Point(int x, int y);
  //Getter for our points row
  int getX();
  //Getter for our points col
  int getY();
  //Print the point in (x,y) format
  void print();
  //Getter for our points grade - number of flips it will make
  int getGrade();
  //Increasing our points graded by num
  void increaseGrade(int num);

 private:
  int x;
  int y;
  int grade;
};

#endif //EX2_POINT_H
