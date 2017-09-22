#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

template <typename T>
struct Vector3 {
  T x;
  T y;
  T z;
};
//typedef Vector3<float> Vector3f;
//typedef Vector3<int> Vector3i;

inline void split1(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
}

template<typename VertexT, typename PolygonT>
int parse_ply(std::vector<VertexT>& vertices, std::vector<PolygonT>& polygons, const char * filename){

  std::ifstream f;
  f.open(filename);
  if(!f.is_open()) {
    std::cerr << "Failed to open the file: " << filename << std::endl;
    return 0;
  }

  std::string line;
  size_t num_vertices, num_polygons;

  std::cout << "Parsing header.." << std::endl;
  while(std::getline(f, line) && line.compare(std::string("end_header")) != 0) {
    std::vector<std::string> tokens;
    split1(line, ' ', tokens);
    if(tokens[0].compare(std::string("element")) == 0 && tokens[1].compare(std::string("vertex")) == 0){
      num_vertices = std::stoi(tokens[2]);
    }

    if(tokens[0].compare(std::string("element")) == 0 && tokens[1].compare(std::string("face")) == 0){
      num_polygons = std::stoi(tokens[2]);
    }
  }

  vertices.resize(num_vertices);
  polygons.resize(num_polygons);
  std::cout << "Parsing vertices.." << std::endl;
  for(int i = 0; getline(f, line) && i < num_vertices; ++i) {
    std::vector<std::string> tokens;
    split1(line, ' ', tokens);
    Vector3f v = {std::stof(tokens[0]), std::stof(tokens[1]), std::stof(tokens[2])};
    vertices[i] = v;
  }

  std::cout << "Parsing polygons.." << std::endl;
  for(int i = 0; getline(f, line) && i < num_polygons; ++i) {
    std::vector<std::string> tokens;
    split1(line, ' ', tokens);
    Vector3i t = {std::stoi(tokens[1]), std::stoi(tokens[2]), std::stoi(tokens[3])};
    polygons[i] = t;
  }

  return 1;
}

//int main(int argc, char* argv[]) {
//  if(argc < 2) {
//    std::cerr << "Please provide a .ply file to load." << std::endl;
//  }
//
//  std::vector<Vector3f> vertices;
//  std::vector<Vector3i> polygons;
//  /* First argument is the filename */
//  char * filename = argv[1];
//  parse_ply(vertices, polygons, filename);
//  std::cout << "Parsed " << vertices.size() << " vertices and " << polygons.size() << " polygons" << std::endl;
//  return(0);
//}