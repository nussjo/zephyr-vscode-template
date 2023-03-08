#include <foo/hello.hpp>

#include <sys/printk.h>

namespace foo
{

    int sayHello() noexcept
    {
        printk("Hello from Foo!\n");
        return 0;
    }

}
