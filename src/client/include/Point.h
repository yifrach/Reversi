#ifndef EX2_POINT_H
#define EX2_POINT_H
#include <iostream>
using namespace std;

class Point {
 public:
  Point(int x, int y);
  int getX();
  int getY();
  void print();
  int getGrade();
  void increaseGrade(int num);

 private:
  int x;
  int y;
  int grade;
};

#endif //EX2_POINT_H
