#include <cstdio>
#include <string>
#include <fstream>
#include <memory>
class bf {
  public:
  bf(std::size_t size) {
    mem = std::make_shared<char[]>(size);
    ptr = &mem[0];
  }
  private:
  char* ptr;
  std::shared_ptr<char[]> mem;
};
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  bf interpreter(10000);
  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    printf("Error: Could not open file %s\n", argv[1]);
    return 1;
  }
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