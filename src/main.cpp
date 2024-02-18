#include "ApplicationConfig.hpp"
#include "cmake_git_version/version.hpp"
#include "kvasir/Util/StaticVector.hpp"
#include "kvasir/Util/using_literals.hpp"
#include "remote_fmt/remote_fmt.hpp"

int main() {
    UC_LOG_D("{}", CMakeGitVersion::FullVersion);
/* 
    apply(set(HW::Pin::led_1{}));
    apply(set(HW::Pin::led_2{}));
    apply(set(HW::Pin::led_3{}));
    apply(set(HW::Pin::led_4{}));
    apply(set(HW::Pin::led_5{}));
    apply(set(HW::Pin::led_6{}));

    apply(clear(HW::Pin::led_1{}));
    apply(clear(HW::Pin::led_2{}));
    apply(clear(HW::Pin::led_3{}));
    apply(clear(HW::Pin::led_4{}));
    apply(clear(HW::Pin::led_5{}));
    apply(clear(HW::Pin::led_6{}));
*/
    auto next = Clock::now();
    int  count{1};
    while(true) {
        auto const now = Clock::now();
        if(now > next) {
            UC_LOG_D("count: {}", count);
            if(count == 1) {
                apply(clear(HW::Pin::led_6{}));
                apply(set(HW::Pin::led_1{}));
                ++count;
            }
            else if(count == 2) {
                apply(clear(HW::Pin::led_1{}));
                apply(set(HW::Pin::led_2{}));
                ++count;
            }
            else if(count == 3) {
                apply(clear(HW::Pin::led_2{}));
                apply(set(HW::Pin::led_3{}));
                ++count;
            }
            else if(count == 4) {
                apply(clear(HW::Pin::led_3{}));
                apply(set(HW::Pin::led_4{}));
                ++count;
            }
            else if(count == 5) {
                apply(clear(HW::Pin::led_4{}));
                apply(set(HW::Pin::led_5{}));
                ++count;
            }
            else if(count == 6) {
                apply(clear(HW::Pin::led_5{}));
                apply(set(HW::Pin::led_6{}));
                count = 1;
            }
            next = Clock::now();
            UC_LOG_D("foo");
            next += 1s;
        }
    }
}

KVASIR_START(Startup)
