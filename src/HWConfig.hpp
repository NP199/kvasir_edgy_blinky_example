#pragma once
#include "HWConfigCommon.hpp"
namespace HW{
namespace Pin{
    using led_1 = decltype(makePinLocation(Kvasir::Io::port0, Kvasir::Io::pin3));
    using led_2 = decltype(makePinLocation(Kvasir::Io::port0, Kvasir::Io::pin4));
    using led_3 = decltype(makePinLocation(Kvasir::Io::port0, Kvasir::Io::pin2));
    using led_4 = decltype(makePinLocation(Kvasir::Io::port0, Kvasir::Io::pin6));
    using led_5 = decltype(makePinLocation(Kvasir::Io::port0, Kvasir::Io::pin5));
    using led_6 = decltype(makePinLocation(Kvasir::Io::port0, Kvasir::Io::pin7));

}//end namespace Pin
struct Fault_CleanUpAction{
    void operator()(){}
};

struct PinConfig {
    static constexpr auto powerClockEnable = list(
      clear(Kvasir::Peripheral::RESETS::Registers<>::RESET::io_bank0),
      clear(Kvasir::Peripheral::RESETS::Registers<>::RESET::pads_bank0));

    static constexpr auto initStepPinConfig = list(
      makeOutput(HW::Pin::led_1{}),
      makeOutput(HW::Pin::led_2{}),
      makeOutput(HW::Pin::led_3{}),
      makeOutput(HW::Pin::led_4{}),
      makeOutput(HW::Pin::led_5{}),
      makeOutput(HW::Pin::led_6{}));
};
}//end namespace HW
