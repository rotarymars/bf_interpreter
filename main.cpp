#include <cstdio>
#include <string>
#include <fstream>
#include <memory>
#include <stack>
#include <utility>
class bf {
  public:
  bf(std::size_t initial_size = 30000) : size(initial_size) {
    mem = std::shared_ptr<char[]>(new char[size]());
    middle = mem.get() + (size / 2);
    ptr = middle;
  }

  void expand_memory(bool forward) {
    std::size_t new_size = size * 2;
    auto new_mem = std::shared_ptr<char[]>(new char[new_size]());
    char* new_middle = new_mem.get() + (new_size / 2);
    
    if (forward) {
      // Copy data to the beginning of new memory
      std::copy(mem.get(), mem.get() + size, new_mem.get());
      ptr = new_mem.get() + (ptr - mem.get());
    } else {
      // Copy data to the end of new memory
      std::copy(mem.get(), mem.get() + size, new_mem.get() + (new_size - size));
      ptr = new_mem.get() + (new_size - size) + (ptr - mem.get());
    }
    
    mem = new_mem;
    middle = new_middle;
    size = new_size;
  }

  void run(const std::string &code) {
    it = code.cbegin();
    while (it != code.end()) {
      if (ptr < mem.get()) {
        expand_memory(false);
      } else if (ptr >= mem.get() + size) {
        expand_memory(true);
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
  char* middle;
  std::string::const_iterator it;
  std::shared_ptr<char[]> mem;
  std::stack<std::string::const_iterator> loop;
  std::size_t size;
};
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  bf interpreter(1);
  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    printf("Error: Could not open file %s\n", argv[1]);
    return 1;
  }
  std::string line;
  std::string code = "";
  while (std::getline(file, line)) {
    for (const char &c : line) {
      if (c == '+' || c == '-' || c == '>' || c == '<' || c == '[' || c == ']' || c == '.' || c == ',') {
        code += c;
      }
    }
  }
  interpreter.run(code);
  return 0;
}