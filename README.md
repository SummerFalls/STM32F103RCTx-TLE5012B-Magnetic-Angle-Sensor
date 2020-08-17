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

## :book: ���

<div style = "text-align: center; margin: auto; width: 100%;">

![Infineon_Logo][Infineon_Logo]

</div>

����Ӣ���� 360�� �ŽǶȴ����� `TLE5012B` �Ĳ�����֤���̣���ֲ��Ӣ���� TLE5012B [�ٷ� Github �ֿ�][TLE5012-Magnetic-Angle-Sensor-Github] �ϵ� C++ ���뵽 STM32 ƽ̨�������漰�����ļ�Ϊ���������������ļ�Ϊʹ�� `3-Wire` ��ʽ����ͨѶʱ����Ҫ��

- [Tle5012b_4wire.h](https://github.com/Infineon/TLE5012-Magnetic-Angle-Sensor/blob/master/src/Tle5012b_4wire.h)
- [Tle5012b_4wire.cpp](https://github.com/Infineon/TLE5012-Magnetic-Angle-Sensor/blob/master/src/Tle5012b_4wire.cpp)

������֤�ô���������ʱ��ʹ���˹ٷ��� [Angle Sensor 2GO Kit][Angle-Sensor-2GO-Kit] ϵ���׼��� [TLE5012B_E1000_MS2GO][TLE5012B_E1000_MS2GO]����ϸ�������λ����������˲��ԡ�

<div style = "text-align: center; margin: auto; width: 80%;">

| ![TLE5012B_BulkSensor][TLE5012B_BulkSensor] | ![TLE5012B_E1000_MS2GO_Pic][TLE5012B_E1000_MS2GO_Pic] |
|:-------------------------------------------:|:-----------------------------------------------------:|
|             *Bulk Sensor ɢƬ*              |                    *Sensor2Go kit*                    |

</div>

## :pushpin: Angle-Sensor-2GO-Kit Pin Out

![TLE5012B_E1000_MS2GO_PIN_OUT][TLE5012B_E1000_MS2GO_PIN_OUT]

## :pushpin: MCU ���ŷ���ͼ

![���ŷ���][���ŷ���]

## :warning: ע��

���߷�ʽѡ���˹ٷ��ֲᵱ�е� `�������` ��ʽ���� 8 MBits/s���� `��©���` ��ʽ�Ľ��߲�һ����������ҲΪ 2 MBits/s��

���չٷ��ֿ��� `README.md �ĵ�` �Լ��òֿ��µ� [#1 Issue: Example connection scheme for tle5012be1000 chip and microcontorller][TLE5012-Magnetic-Angle-Sensor-Github-Issue]������ [STM32 ��̳][STM32 ��̳] ��˵���������� MOSI �Ŵ�����һ�� `4.7K` ���裬����ͼ����������ͨѶ��������������һ����֤���ԡ�

![Ӳ������ͼ][Ӳ������ͼ]

���ѡ���� [#1 Issue: Example connection scheme for tle5012be1000 chip and microcontorller][TLE5012-Magnetic-Angle-Sensor-Github-Issue] �еĲ����ӵ��裬ͨ��������� MOSI �Ŷ�Ӧ�� GPIO �ڵ�״̬ʵ�������ݵ�����ͨѶ��`SPI ���� Command ������֮�󣬽� MOSI �ŵ� GPIO �л�Ϊ����̬���������룩���ٽ��н��������ֺͰ�ȫ�֣�������Ϻ����л��ظ����������`��

����Ϊ���� Issue ��Ӣ����ٷ��ֿ�ά����Ա [`MorganSandercock` ��ԭ��][TLE5012-Magnetic-Angle-Sensor-Github-Issue-issuecomment]��

> Yes...
connect CSQ(3) to any convenient uC pin to use as chip-select
connect DATA(4) to MISO
connect SCK(2) to SCK
connect DATA(4) to MOSI via a resistor. Use anything between 3.3K and 10K.
>
> If you don't use a resistor between DATA and MOSI then it is possible to modify the library to put MOSI into a high-impedance state after writing the command word and before reading the response. Setting it back to SPI output mode depends on the specific microcontroller, so this is not a simple one-line change to the library.

## :gear: Ӳ�� & ��� ����

### Ӳ������

- STM32F103RCT6 PCB Board
- J-Link V9

### �������

- Keil uVision5.27 ������
- STM32CubeMX 5.6.1 ������

## �ο�����

1. [TLE5012B �ŽǶȴ�������������ҳ��][TLE5012B-Overview]
2. [TLE5012B �û��ֲ�][TLE5012-User-Manual]
3. [Angle Sensor 2GO Kit ϵ���׼�][Angle-Sensor-2GO-Kit]
4. [TLE5012B_E1000_MS2GO ������][TLE5012B_E1000_MS2GO]
5. [�ٷ� TLE5012B Github ����ֿ�][TLE5012-Magnetic-Angle-Sensor-Github]
6. [�ٷ� TLE5012B Github ����ֿ����MOSI�Ŵ��ӵ���� Issue][TLE5012-Magnetic-Angle-Sensor-Github-Issue]

[���ŷ���]: ./PinOut.jpg
[Ӳ������ͼ]: ./ConnectionScheme.png
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
[STM32 ��̳]: http://www.stmcu.org.cn/module/forum/thread-621043-1-1.html
