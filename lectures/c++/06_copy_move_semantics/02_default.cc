<<<<<<< HEAD
#include <initializer_list>
#include <iostream>

struct X {
  int a = 5;  // in-class initialization
  double b = 3.3;
  char c = 'a';
  // X() = default;  // in-class initializers are used by the constructors
};

struct Y {
  int a = 77;
  double b;
  char c = 'a';
  Y() : a{5} {}  // what it is written here wins the in-class initialization
  // Y() = default;
};

int main() {
  X x1;    // default ctor
  X x2{};  // default ctor
  std::cout << x1.a << "--" << x1.b << "--" << x1.c << "\n";
  std::cout << x2.a << "--" << x2.b << "--" << x2.c << "\n\n";

  Y y1;    // default ctor
  Y y2{};  // default ctor calls {} on uninitialized vars
  std::cout << y1.a << "--" << y1.b << "--" << y1.c << "\n";
  std::cout << y2.a << "--" << y2.b << "--" << y2.c << "\n";

  // what if I want X x3 with custom values?
#if __cplusplus > 201103L

  X x3{1, 2.3, 't'};  // compiler error until c++11
  // see https://en.cppreference.com/w/cpp/language/aggregate_initialization

#else

  X x3;
  x3.a = 1;
  x3.b = 2.3;
  x3.c = 't';

#endif

  std::cout << x3.a << "--" << x3.b << "--" << x3.c << "\n\n";
=======
#include <iostream>
#include <string>

struct S {
  int a;
  double b;
  std::string s;  // default ctor of string set s to empty string
  S() = default;
  S(const S&) = delete;  // cannot use a copy ctor
};

int main() {
  S s1;  // calls default constructor

  S s2{1, 2.3, "alberto"};  // if there are no custom ctors I can
                            // directly initialize the members. Note
                            // that I need access (i.e. they must be
                            // public)
  // it is called aggregate initialization (see
  // https://en.cppreference.com/w/cpp/language/aggregate_initialization)

  S s3{};  // calls {} on each member: S s3 { {}, {}, {} };

  std::cout << s1.a << "--" << s1.b << "--" << s1.s << "\n";
  std::cout << s2.a << "--" << s2.b << "--" << s2.s << "\n";
  std::cout << s3.a << "--" << s3.b << "--" << s3.s << "\n";

  // S s4(s2); // compiler error
>>>>>>> upstream/master

  return 0;
}
