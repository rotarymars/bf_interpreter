#include <cstdio>
#include <string>
#include <fstream>
class bf {
  public:
  bf(std::size_t size) {
    mem = new char[size];
    ptr = mem;
  }
  ~bf() {
    delete[] mem;
  }
  private:
  char *ptr;
  char *mem;
};
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  bf interpreter(10000);
  std::ifstream file(argv[1]);
  std::string line;
  std::string code;
  while (std::getline(file, line)) {
    for (const char &c : line) {
      if (c == '+' || c == '-' || c == '>' || c == '<' || c == '[' || c == ']' || c == '.' || c == ',') {
        code += c;
      }
    }
  }
}