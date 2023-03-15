#include <foo/hello.hpp>

#include <zephyr/sys/printk.h>

namespace foo
{

    int sayHello() noexcept
    {
        printk("Hello from Foo!\n");
        return 0;
    }

}
