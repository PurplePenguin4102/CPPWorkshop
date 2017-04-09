#include "Cube.h"

using namespace std;

namespace Rubix
{
  Cube::Cube()
  {
    cout << "hello, Cube constructed" << endl;
  }

  void Cube::RowLeft(int row)
  {
    cout << "Cube row " << row + 1 << " rotated left" << endl;
    int rowMod = row * 3;
    vector<int> tempRow = vector<int>{FaceOne[rowMod], FaceOne[rowMod + 1], FaceOne[rowMod + 2]};
    for (int i = rowMod; i < rowMod + 3; ++i)
    {
      FaceOne[i] = FaceFour[i];
      FaceFour[i] = FaceThree[i];
      FaceThree[i] = FaceTwo[i];
      FaceTwo[i] = tempRow[i];
    }
    if (row == 0)
      RotateClock(FaceFive);
    else if (row == 2)
      RotateCClock(FaceSix);
  }

  void Cube::RowRight(int row)
  {
    cout << "Cube row " << row + 1 << " rotated right" << endl;
    int rowMod = row * 3;
    vector<int> tempRow = vector<int>{FaceOne[rowMod], FaceOne[rowMod + 1], FaceOne[rowMod + 2]};
    for (int i = rowMod; i < rowMod + 3; ++i)
    {
      FaceOne[i] = FaceTwo[i];
      FaceTwo[i] = FaceThree[i];
      FaceThree[i] = FaceFour[i];
      FaceFour[i] = tempRow[i];
    }
    if (row == 0)
      RotateCClock(FaceFive);
    else if (row == 2)
      RotateClock(FaceSix);
  }
  
  void Cube::ColUp(int col)
  {
    cout << "Cube col " << col + 1 <<  " rotated up" << endl;
    vector<int> tempCol = vector<int>{FaceOne[col], FaceOne[col + 3], FaceOne[col + 6]};
    for (int i = col, j = 8 - col; i < 9; i += 3, j -= 3)
    {
      FaceOne[i] = FaceSix[i];
      FaceSix[i] = FaceThree[j];
      FaceThree[j] = FaceFive[i];
      FaceFive[i] = tempCol[i / 3];
    }
    if (col == 0)
      RotateCClock(FaceTwo);
    else if (col == 2)
      RotateClock(FaceFour);
  }  
  
  void Cube::ColDown(int col)
  {
    cout << "Cube col " << col + 1 <<  " rotated down" << endl;
    vector<int> tempCol = vector<int>{FaceOne[col], FaceOne[col + 3], FaceOne[col + 6]};
    for (int i = col, j = 8 - col; i < 9; i += 3, j -= 3)
    {
      FaceOne[i] = FaceFive[i];
      FaceFive[i] = FaceThree[j];
      FaceThree[j] = FaceSix[i];
      FaceSix[i] = tempCol[i / 3];
    }
    if (col == 0)
      RotateClock(FaceTwo);
    else if (col == 2)
      RotateCClock(FaceFour);
  }
  
  void Cube::FaceClock(int face)
  {
    cout << "hello, Cube constructed" << endl;
  }
  
  void Cube::FaceCClock(int face)
  {
    cout << "hello, Cube constructed" << endl;
  }

  bool Cube::IsSolved()
  {
    cout << "hello, Cube constructed" << endl;
  }

  void Cube::RotateClock(vector<int> face)
  {
    vector<int> oldFace = vector<int>(face);
    face[0] = oldFace[6];
    face[1] = oldFace[3];
    face[2] = oldFace[0];
    face[3] = oldFace[7];
    face[5] = oldFace[1];
    face[6] = oldFace[8];
    face[7] = oldFace[5];
    face[8] = oldFace[3];
  }

  void Cube::RotateCClock(vector<int> face)
  {
    vector<int> oldFace = vector<int>(face);
    face[0] = oldFace[2];
    face[1] = oldFace[5];
    face[2] = oldFace[8];
    face[3] = oldFace[1];
    face[5] = oldFace[7];
    face[6] = oldFace[0];
    face[7] = oldFace[3];
    face[8] = oldFace[6];
  }
  
  Cube::~Cube()
  {
    cout << "cube all gone :(" << endl;
  }

  std::ostream& operator<< (std::ostream& out, const std::vector<int>& v)
  {
    if ( !v.empty() )
    {
      for (auto i: v)
        out << i << ' ';
    }
    return out;
  }
  
  std::ostream& operator<<(std::ostream& os, const Cube& cube)
  {
    os << cube.FaceOne << std::endl;
    os << cube.FaceTwo << std::endl;
    os << cube.FaceThree << std::endl;
    os << cube.FaceFour << std::endl;
    os << cube.FaceFive << std::endl;
    os << cube.FaceSix << std::endl;
    
    return os;
  }
}
