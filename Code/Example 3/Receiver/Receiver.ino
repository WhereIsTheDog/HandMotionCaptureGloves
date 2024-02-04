#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN); // 创建一个射频模块对象

char dataToSend[1] = "!";

const int ackDataSize = 8;
char data_right[ackDataSize] = {0, 0, 0, 0, 0, 0, 0, 0}; // 用于保存来自右手套控制器的确认数据
char data_left[ackDataSize] = {0, 0, 0, 0, 0, 0, 0, 0}; // 用于保存来自左手套控制器的确认数据

const byte controllerAddress_Right[5] = {'R','x','A','A','B'}; // 右手套控制器的地址
const byte controllerAddress_Left[5] = {'R','x','A','A','A'}; // 左手套控制器的地址

bool newData = false;

void setup() {
    Serial.begin(115200);

    radio.begin(); // 初始化射频模块
    radio.setDataRate( RF24_1MBPS ); // 设置数据传输速率为1Mbps
    radio.setPALevel(RF24_PA_HIGH); // 设置射频功率为高级别
    
    radio.enableAckPayload(); // 启用应答有效载荷功能
}

void loop() {
    // sendForAck(controllerAddress_Right, data_right);
    sendForAck(controllerAddress_Left, data_left);
    writeData();
    delay(100);
}

void sendForAck(byte *controllerAddress, char *buff) {
    radio.openWritingPipe(controllerAddress); // 设置写入管道为指定的套控制器地址

    bool rslt = radio.write( &dataToSend, sizeof(dataToSend) ); // 发送数据

    if (rslt) {
        if ( radio.isAckPayloadAvailable()) { // 检查是否有应答有效载荷可用
            radio.read(buff, ackDataSize); // 读取应答有效载荷数据
            newData = true; // 设置新数据标志为true
        }
    }
}

void writeData() {
    if (newData == true) {
        Serial.write(data_right, 8); // 将右手套控制器的确认数据发送到串口
        Serial.write(data_left, 8); // 将左手套控制器的确认数据发送到串口
        Serial.println(""); // 打印换行符
        newData = false; // 重置新数据标志为false
    }
}
