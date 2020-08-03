#include <emscripten/bind.h>

using namespace emscripten;

class Adder {
    public:
        Adder(double a_, double b_) : a(a_), b(b_) {}
        double a, b;
        double get() {return a + b + 1;}
};

double add(double a, double b) {
    return Adder(a, b).get();
}

std::string exclaim(std::string message) {
    return message + "!";
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("add", &add);
    function("exclaim", &exclaim);
}
