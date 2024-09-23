#include "memory_operations.h"
#include "utils_tests.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    init(argv[1]);
    affiche_test("Truc bizarre : %x\n", reverse_endianess(0x01234567));
    shutdown(0);
}
