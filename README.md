# QtSpek
基于Qt的频谱分析器

修改于Spek[官网地址](http://spek.cc), [Github仓库地址](https://github.com/alexkay/spek)

![0](https://github.com/Greedysky/qt-spek/blob/master/resource/demo.jpg?raw=true)
![1](https://github.com/Greedysky/qt-spek/blob/master/resource/demo2.jpg?raw=true)

## CI Status
 * Qt stable version be tested on Qt4.8.7 for windows-mingw 32bit
 * Qt stable version be tested on Qt4.8.7 for ubuntu-linux-gcc 64bit
 * Qt stable version be tested on Qt5.9.9 for ubuntu-linux-gcc 64bit
 * Qt stable version be tested on Qt5.x for windows-mingw 32bit

| Platform | Qt & Compiler           | Status                                                                 |
| :---:    | :---:                   | :---:                                                                  |
| Linux    | 4.8.7 GCC & 5.9.9 GCC   | ![Linux](https://img.shields.io/badge/build-passing-brightgreen.svg)   |
| Windows  | 4.8.7 GCC & 5.x GCC     | ![Windows](https://img.shields.io/badge/build-passing-brightgreen.svg) |
| Windows  | MSVC                    | ![Windows](https://img.shields.io/badge/build-unknown-lightgrey.svg)   |
| OS X     | Clang                   | ![OSX](https://img.shields.io/badge/build-unknown-lightgrey.svg)       |

## Spectrogram

`c`, `C`
:   Change the audio channel.

`f`, `F`
:   Change the DFT window function.

`l`, `L`
:   Change the lower limit of the dynamic range in dBFS.

`p`, `P`
:   Change the palette.

`s`, `S`
:   Change the audio stream.

`u`, `U`
:   Change the upper limit of the dynamic range in dBFS.

`w`, `W`
:   Change the DFT window size.
