# Longan Nano 用 Wire ライブラリもどき（I2C 送信専用） #

Longan Nano 用の Arduino Wire 風 I2C 送信専用ライブラリです。本家のように高機能ではないですが、「今すぐ I2C 機器を設定したい！」というようなときにどうぞ（いずれ読み込みも追加したい）。

なお、基本のコードは [GD32VF103 Firmware Library](https://github.com/riscv-mcu/GD32VF103_Firmware_Library/blob/master/Examples/I2C/Master_transmitter/main.c)を参考にしました。

This is a quasi Wire library to support I2C (send only) for Longan Nano. 

## 使い方 USAGE ##

Arduino と同じです。``Wire.h`` を ``#include`` して、以下のように使用します。PB6 が SCL、PB7 が SDA です。

Same as Arduino, just include Wire.h and use as below. BE SURE TO CONNECT A PULLUP REGISTOR!

```
Wire.begin(); // 初期化
Wire.beginTransmission( 0x2F ); // 送信処理開始 引数 I2C アドレス（7ビット）
Wire.write(cnt); // データ送信キュー追加
Wire.endTransmission(); // 送信完了
```

**注意:**  Arduino と違い、プルアップ抵抗が必要です。

## サンプルファイルの説明 ##
VSCode の PlatformIO 用のコード ``src/Blick.cpp`` では、I2C で設定を行う可変抵抗器 MCP4018T （[秋月電子のページ](http://akizukidenshi.com/catalog/g/gI-07610/)）を制御しています。

![92e5825ff9a8ca4d4d6d019f12e2cdcf](https://user-images.githubusercontent.com/13434151/87855379-c4887580-c952-11ea-9473-914f825e82a2.png)

- I2C アドレスは ``0101111`` 固定
- Vdd は 3.3V でも 5V でも動作
- Vss は GND 
- I2C で 0 を送ると 2 - 5 ピン間が 0Ω、127 を送ると 10kΩ の 128 段階に設定

左上 LED の明るさが可変抵抗によって変わります。

![IMG_6171](https://user-images.githubusercontent.com/13434151/87855746-4c6f7f00-c955-11ea-8b0a-ca3e9376853a.JPG)


ロジアナで I2C の信号を確認したところ。

![107867410_934892293589253_8121548138348444461_n](https://user-images.githubusercontent.com/13434151/87855801-a07a6380-c955-11ea-814c-f23f70ee8fc4.png)
