#include <iostream>
#include <dlfcn.h> // https://pubs.opengroup.org/onlinepubs/7908799/xsh/dlfcn.h.html
// #include "shared.h"

int main() {
    // declaration (template) of add function
    // function typedef: http://www.iso-9899.info/wiki/Typedef_Function_Type
    typedef int add_t(int, int);

    // load shared library
    // https://pubs.opengroup.org/onlinepubs/7908799/xsh/dlopen.html
    void *handler = dlopen("./shared.so", RTLD_LAZY);

    if(handler == NULL){
      std::cout << "handler is NULL" << std::endl;
      return 0;
    }

    // extract `add` symbol (pointer) and convert it to function pointer
    // https://pubs.opengroup.org/onlinepubs/7908799/xsh/dlsym.html
    add_t *add = (add_t*) dlsym( handler, "add" );
    std::cout << add << std::endl;
    std::cout << "haha 3" << std::endl;
    // execute function
    std::cout << (*add)(5, 2) << std::endl;
}
