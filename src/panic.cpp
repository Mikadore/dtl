#include <dtl/panic.hpp>

#include <stdlib.h>
#include <stdio.h>
#include <execinfo.h>

namespace dtl {
    void (*user_panic_handler)(char const* msg) = nullptr;

    auto set_panic_handler(void (*panic_handler)(char const* msg)) -> void {
        // TODO: mutex
        user_panic_handler = panic_handler;
    }

    namespace impl
    {
        // deliberately bare-bones as the panic could have originated
        // from anywhere, possibly corrupting any required library state
        // in order to function correctly
        auto panic(const char* FILE, int LINE, const char* msg) -> void {
            if (user_panic_handler != nullptr) {
                user_panic_handler(msg);
            } else {
                fprintf(stderr, "Exiting program due to a call to dtl_panic\n");
                void* buffer[1024];
                auto n = backtrace(buffer, 1024);
                backtrace_symbols_fd(buffer, n, 2);
                fprintf(stderr, "Panicked at %s:%d:\n%s", FILE, LINE, msg);
                exit(EXIT_FAILURE);
            }   
        }
    }
}