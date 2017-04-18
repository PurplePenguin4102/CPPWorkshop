#include "Cube.h"

using namespace std;

namespace Rubix
{ 
  Cube::Cube()
  { 
    cout << "hello, Cube constructed" << endl;
  } 

  void Cube::RowLeft(unsigned int row)
  {
    cout << "Cube row " << to_string(row + 1) << " rotated left" << endl;
    unsigned int rowMod = row * 3;
    vector<int> tempRow = vector<int>{FaceOne[rowMod], FaceOne[rowMod + 1], FaceOne[rowMod + 2]};
    for (unsigned int i = rowMod; i < rowMod + 3; ++i)
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

  void Cube::RowRight(unsigned int row)
  {
    cout << "Cube row " << to_string(row + 1) << " rotated right" << endl;
    unsigned int rowMod = row * 3;
    vector<int> tempRow = vector<int>{FaceOne[rowMod], FaceOne[rowMod + 1], FaceOne[rowMod + 2]};
    for (unsigned int i = rowMod; i < rowMod + 3; ++i)
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
  
  void Cube::ColUp(unsigned int col)
  {
    cout << "Cube col " << to_string(col + 1) <<  " rotated up" << endl;
    vector<int> tempCol = vector<int>{FaceOne[col], FaceOne[col + 3], FaceOne[col + 6]};
    for (unsigned int i = col, j = 8 - col; i < 9; i += 3, j -= 3)
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
  
  void Cube::ColDown(unsigned int col)
  {
    cout << "Cube col " << to_string(col + 1) <<  " rotated down" << endl;
    vector<int> tempCol = vector<int>{FaceOne[col], FaceOne[col + 3], FaceOne[col + 6]};
    for (unsigned int i = col, j = 8 - col; i < 9; i += 3, j -= 3)
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
  
  void Cube::SliceClock(unsigned int slice)
  {
    cout << "Slice no " << to_string(slice + 1) << " rotated down" << endl;
	
    vector<int> tempSlice = vector<int>{FaceFour[slice], FaceFour[slice + 3], FaceFour[slice + 6]};
    for (unsigned int i = 0; i < 3; i++)
    {
      FaceFour[slice + i * 3] = FaceFive[6 - slice * 3 + i];
      FaceFive[6 - slice * 3 + i] = FaceTwo[8 - slice - 3 * i];
      FaceTwo[8 - slice - 3 * i] = FaceSix[slice * 3 + 2 - i];
      FaceSix[slice * 3 + 2 - i] = tempSlice[i];
    }

    if (slice == 0)
      RotateClock(FaceOne);
    else if (slice == 2)
      RotateCClock(FaceThree);
  }
  
  void Cube::SliceCClock(unsigned int slice)
  {
    cout << "Slice no " << to_string(slice + 1) << " rotated down" << endl;
    vector<int> tempSlice = vector<int>{FaceFour[slice], FaceFour[slice + 3], FaceFour[slice + 6]};
    for (unsigned int i = 0; i < 3; i++)
    {
      FaceFour[slice + i * 3] = FaceSix[slice * 3 + 2 - i]; //FaceFive[6 - slice * 3 + i];
      FaceSix[slice * 3 + 2 - i] = FaceTwo[8 - slice - 3 * i];
      FaceTwo[8 - slice - 3 * i] = FaceFive[6 - slice * 3 + i];
      FaceFive[6 - slice * 3 + i] = tempSlice[i];
    }

    if (slice == 0)
      RotateCClock(FaceOne);
    else if (slice == 2)
      RotateClock(FaceThree);
  }

  bool Cube::IsSolved()
  {
    cout << "hello, Cube constructed" << endl;
    return false;
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

  std::ostream& operator<<(std::ostream& out, const std::vector<int>& v)
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
