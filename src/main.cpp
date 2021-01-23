#include "TupleSplitterTester.h"
#include "FunctorInputSetterTester.h"
#include "SuperFunctorTester.h"

int main() {
    TupleSplitterTester::testTupleSplitter();
    FunctorInputSetterTester::testFunctorInputSetter();
    SuperFunctorTester::testSuperFunctorWithSubstring();
    SuperFunctorTester::testSuperFunctorWithConcat();

    return 0;
}

