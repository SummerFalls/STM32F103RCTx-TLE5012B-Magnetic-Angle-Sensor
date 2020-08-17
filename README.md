# :beers: F103RCTx_TLE5012B

```c
/*
 *                  ___           ___                     ___           ___           ___           ___
 *    ___          /__/\         /  /\      ___          /__/\         /  /\         /  /\         /__/\
 *   /  /\         \  \:\       /  /:/_    /  /\         \  \:\       /  /:/_       /  /::\        \  \:\
 *  /  /:/          \  \:\     /  /:/ /\  /  /:/          \  \:\     /  /:/ /\     /  /:/\:\        \  \:\
 * /__/::\      _____\__\:\   /  /:/ /:/ /__/::\      _____\__\:\   /  /:/ /:/_   /  /:/  \:\   _____\__\:\
 * \__\/\:\__  /__/::::::::\ /__/:/ /:/  \__\/\:\__  /__/::::::::\ /__/:/ /:/ /\ /__/:/ \__\:\ /__/::::::::\
 *    \  \:\/\ \  \:\~~\~~\/ \  \:\/:/      \  \:\/\ \  \:\~~\~~\/ \  \:\/:/ /:/ \  \:\ /  /:/ \  \:\~~\~~\/
 *     \__\::/  \  \:\  ~~~   \  \::/        \__\::/  \  \:\  ~~~   \  \::/ /:/   \  \:\  /:/   \  \:\  ~~~
 *     /__/:/    \  \:\        \  \:\        /__/:/    \  \:\        \  \:\/:/     \  \:\/:/     \  \:\
 *     \__\/      \  \:\        \  \:\       \__\/      \  \:\        \  \::/       \  \::/       \  \:\
 *                 \__\/         \__\/                   \__\/         \__\/         \__\/         \__\/
 */
```

## :book: 简介

<div style = "text-align: center; margin: auto; width: 100%;">

![Infineon_Logo][Infineon_Logo]

</div>

这是英飞凌 360° 磁角度传感器 `TLE5012B` 的测试验证工程，移植了英飞凌 TLE5012B [官方 Github 仓库][TLE5012-Magnetic-Angle-Sensor-Github] 上的 C++ 代码到 STM32 平台，具体涉及到的文件为以下两个，其它文件为使用 `3-Wire` 方式进行通讯时才需要：

- [Tle5012b_4wire.h](https://github.com/Infineon/TLE5012-Magnetic-Angle-Sensor/blob/master/src/Tle5012b_4wire.h)
- [Tle5012b_4wire.cpp](https://github.com/Infineon/TLE5012-Magnetic-Angle-Sensor/blob/master/src/Tle5012b_4wire.cpp)

初次验证该传感器功能时，使用了官方的 [Angle Sensor 2GO Kit][Angle-Sensor-2GO-Kit] 系列套件的 [TLE5012B_E1000_MS2GO][TLE5012B_E1000_MS2GO]，配合附带的上位机程序进行了测试。

<div style = "text-align: center; margin: auto; width: 80%;">

| ![TLE5012B_BulkSensor][TLE5012B_BulkSensor] | ![TLE5012B_E1000_MS2GO_Pic][TLE5012B_E1000_MS2GO_Pic] |
|:-------------------------------------------:|:-----------------------------------------------------:|
|             *Bulk Sensor 散片*              |                    *Sensor2Go kit*                    |

</div>

## :pushpin: Angle-Sensor-2GO-Kit Pin Out

![TLE5012B_E1000_MS2GO_PIN_OUT][TLE5012B_E1000_MS2GO_PIN_OUT]

## :pushpin: MCU 引脚分配图

![引脚分配][引脚分配]

## :warning: 注意

接线方式选择了官方手册当中的 `推挽输出` 方式，达 8 MBits/s，而 `开漏输出` 方式的接线不一样，且速率也为 2 MBits/s。

按照官方仓库中 `README.md 文档` 以及该仓库下的 [#1 Issue: Example connection scheme for tle5012be1000 chip and microcontorller][TLE5012-Magnetic-Angle-Sensor-Github-Issue]，还有 [STM32 论坛][STM32 论坛] 的说法测试了在 MOSI 脚串接了一个 `4.7K` 电阻，如下图，发现数据通讯并不正常，待进一步验证测试。

![硬件接线图][硬件接线图]

最后选择了 [#1 Issue: Example connection scheme for tle5012be1000 chip and microcontorller][TLE5012-Magnetic-Angle-Sensor-Github-Issue] 中的不串接电阻，通过代码控制 MOSI 脚对应的 GPIO 口的状态实现了数据的正常通讯（`SPI 发送 Command 命令字之后，将 MOSI 脚的 GPIO 切换为高阻态（浮空输入），再进行接收数据字和安全字，接收完毕后再切换回复用推挽输出`）

以下为以上 Issue 中英飞凌官方仓库维护人员 [`MorganSandercock` 的原话][TLE5012-Magnetic-Angle-Sensor-Github-Issue-issuecomment]：

> Yes...
connect CSQ(3) to any convenient uC pin to use as chip-select
connect DATA(4) to MISO
connect SCK(2) to SCK
connect DATA(4) to MOSI via a resistor. Use anything between 3.3K and 10K.
>
> If you don't use a resistor between DATA and MOSI then it is possible to modify the library to put MOSI into a high-impedance state after writing the command word and before reading the response. Setting it back to SPI output mode depends on the specific microcontroller, so this is not a simple one-line change to the library.

## :gear: 硬件 & 软件 需求

### 硬件需求

- STM32F103RCT6 PCB Board
- J-Link V9

### 软件需求

- Keil uVision5.27 及以上
- STM32CubeMX 5.6.1 及以上

## 参考资料

1. [TLE5012B 磁角度传感器官网介绍页面][TLE5012B-Overview]
2. [TLE5012B 用户手册][TLE5012-User-Manual]
3. [Angle Sensor 2GO Kit 系列套件][Angle-Sensor-2GO-Kit]
4. [TLE5012B_E1000_MS2GO 评估板][TLE5012B_E1000_MS2GO]
5. [官方 TLE5012B Github 代码仓库][TLE5012-Magnetic-Angle-Sensor-Github]
6. [官方 TLE5012B Github 代码仓库关于MOSI脚串接电阻的 Issue][TLE5012-Magnetic-Angle-Sensor-Github-Issue]

[引脚分配]: ./PinOut.jpg
[硬件接线图]: ./ConnectionScheme.png
[Infineon_Logo]: ./img/ifx_logo.png
[TLE5012B_E1000_MS2GO_PIN_OUT]: ./img/TLE5012B_Sensor_2Go_Pin_out.png
[TLE5012B_E1000_MS2GO_Pic]: ./img/TLE5012B_horizontal.png
[TLE5012B_BulkSensor]: ./img/TLE_5012B_DSO-8-16_plain.jpg

[TLE5012B-Overview]: https://www.infineon.com/cms/en/product/sensor/magnetic-sensors/magnetic-position-sensors/angle-sensors/
[TLE5012-User-Manual]: https://www.infineon.com/dgdl/Infineon-Angle_Sensor_TLE5012B-UM-v01_02-en-UM-v01_02-EN.pdf?fileId=5546d46146d18cb40146ec2eeae4633b
[Angle-Sensor-2GO-Kit]: https://www.infineon.com/cms/en/product/promopages/sensors-2go/#angle-sensor-2go
[TLE5012B_E1000_MS2GO]: https://www.infineon.com/cms/en/product/evaluation-boards/tle5012b_e1000_ms2go/
[TLE5012-Magnetic-Angle-Sensor-Github]: https://github.com/Infineon/TLE5012-Magnetic-Angle-Sensor
[TLE5012-Magnetic-Angle-Sensor-Github-Issue]: https://github.com/Infineon/TLE5012-Magnetic-Angle-Sensor/issues/1
[TLE5012-Magnetic-Angle-Sensor-Github-Issue-issuecomment]: https://github.com/Infineon/TLE5012-Magnetic-Angle-Sensor/issues/1#issuecomment-460507553
[STM32 论坛]: http://www.stmcu.org.cn/module/forum/thread-621043-1-1.html
