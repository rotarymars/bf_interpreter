#include <cstdio>
#include <string>
#include <fstream>
#include <memory>
#include <stack>
#include <utility>
class bf {
  public:
  bf(std::size_t size) {
    mem = std::shared_ptr<char[]>(new char[size]);
    ptr = mem.get();
  }
  void run(const std::string &code) {
    it = code.begin();
    while (it != code.end()) {
      if (mem.get() > ptr) {
        printf("Error: Pointer out of bounds\n");
        return;
      }
      switch (*it) {
        case '+':
          ++(*ptr);
          break;
        case '-':
          --(*ptr);
          break;
        case '>':
          ++ptr;
          break;
        case '<':
          --ptr;
          break;
        case '.':
          putchar(*ptr);
          break;
        case ',':
          *ptr = getchar();
          break;
        case '[':
          loop.push(it);
          break;
        case ']':
          if (*ptr) {
            it = loop.top();
          }
          else {
            loop.pop();
          }
          break;
        default:
          std::unreachable();
      }
      ++it;
    }
  }
  private:
  char* ptr;
  std::string::const_iterator it;
  std::shared_ptr<char[]> mem;
  std::stack<std::string::const_iterator> loop;
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
  printf("%s\n", code.c_str());
  interpreter.run(code);
}