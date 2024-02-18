# Welcome to this example blinky repo

In this repo is an example project for an blinky led project using different hardware and firmware components.

## Hardware [Edgy Boards](https://github.com/skunkforce/edgy_boards)
- RP2040 Microcontroller Dev Board [C003 Edgy](https://github.com/skunkforce/c003_usb-c_to_minimal_rp2040)
- 6 Led`s [b150 Edgy](https://github.com/skunkforce/b150_6x_LED_GPIO)

## Firmware [Kvasir](https://github.com/kvasir-io)
- Chip specific code for the [RP2040](https://github.com/kvasir-io/chip_rp2040/tree/52ebcb757ada99ce338e49f0c3e64644b00c5925)
- [Kvasir SDK](https://github.com/kvasir-io/Kvasir_SDK/tree/197d4dde63574e684959d59cf24454e10391fb63)
- optional J-Link for reading debug messages

## Get the project started
If you want to compile the project there are some prerequisites to install before compiling:
```shell
llvm cmake lld git make gcc fmt
nlohmann-json pugixml clang python
python-intelhex boost base-devel inja
jlink-software-and-documentation
```
A second approach is to use the Dockerfile which is included in the [Kvasir Dockerfile](https://github.com/kvasir-io/Kvasir_SDK/blob/197d4dde63574e684959d59cf24454e10391fb63/Dockerfile) submodule Folder.

## Building with cmake
```shell
mkdir build
cd build
cmake ..
make
```

## Flashing via J Link
Using a JLink:
- Using the WSL and a USB connection just use JLink Remote Server
  > dont forget to configure the WSL IP with `ccmake .` 
```shell
make flash_blinky
```

To make use of the debug log
```shell
make flash_debug
make log_debug
```
## Flashing via USB and filebrowser
- connect the dev board while holding the push button
- take the `blinky_flash.uf2` and copy it into the `rpi-rp2` drive
- now the pi should automatically restart and the board is flashed
