#pragma once
namespace dtl
{
    extern void (*user_panic_handler)(char const* msg);

    auto set_panic_handler(void (*panic_handler)(char const* msg)) -> void;

    namespace impl 
    {
        auto panic(const char* FILE, int LINE, const char* message) -> void;
    }
}

#define dtl_panic(message) \
    dtl::impl::panic(__FILE__, __LINE__, message);

    
