#ifndef __CUBE_H_INCLUDED__
#define __CUBE_H_INCLUDED__

#include <vector>
#include <iostream>

namespace Rubix
{
  class Cube
  {
  public:
    Cube();
    void RowLeft(int row);
    void RowRight(int row);
    void ColUp(int col);
    void ColDown(int col);
    void SliceClock(int slice);
    void SliceCClock(int slice);
    bool IsSolved();
    friend std::ostream& Rubix::operator<<(std::ostream& os, const Cube& cube);
    ~Cube();
    
  private:
    std::vector<int> FaceOne = std::vector<int>(9, 1);
    std::vector<int> FaceTwo = std::vector<int>(9, 2);
    std::vector<int> FaceThree = std::vector<int>(9, 3);
    std::vector<int> FaceFour = std::vector<int>(9, 4);
    std::vector<int> FaceFive = std::vector<int>(9, 5);
    std::vector<int> FaceSix = std::vector<int>(9, 6);

    void RotateClock(std::vector<int> face);
    void RotateCClock(std::vector<int> face);
  };
}

#endif
