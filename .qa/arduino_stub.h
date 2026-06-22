#include <cstddef>

#define OUTPUT 1
#define HIGH 1
#define LOW 0

inline void pinMode(int, int) {}
inline void digitalWrite(int, int) {}
inline void analogWrite(int, int) {}
inline void delay(int) {}

struct SerialStub {
  void begin(int) {}
  void println(const char*) {}
  int available() { return 0; }
  char read() { return 0; }
};

inline SerialStub Serial;
