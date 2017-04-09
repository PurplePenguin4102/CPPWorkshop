#ifndef __CUBE_H_INCLUDED__
#define __CUBE_H_INCLUDED__

#include <vector>
#include <iostream>

namespace Rubix
{
  std::ostream& operator<<(std::ostream& out, const std::vector<int>& v);
  
  class Cube
  {
  public:
    Cube();
    void RowLeft(unsigned int row);
    void RowRight(unsigned int row);
    void ColUp(unsigned int col);
    void ColDown(unsigned int col);
    void SliceClock(unsigned int slice);
    void SliceCClock(unsigned int slice);
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
