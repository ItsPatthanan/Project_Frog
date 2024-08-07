int sensorPin = 15; // Pin ที่เชื่อมต่อกับ E18-D80NK
int eled = 2;
int objectCount = 0; // ตัวแปรสำหรับนับจำนวนวัตถุ
bool objectDetected = false; // ตัวแปรสถานะเพื่อบันทึกการตรวจจับวัตถุ

void setup() {
  Serial.begin(115200); // เริ่มต้น Serial Monitor
  pinMode(sensorPin, INPUT); // ตั้งค่า pin เป็น input
  pinMode(eled, OUTPUT); 
}

void loop() {
  int sensorValue = digitalRead(sensorPin); // อ่านค่าสัญญาณจากเซ็นเซอร์

  if (sensorValue == LOW && !objectDetected) { // ถ้าเซ็นเซอร์ตรวจจับวัตถุและยังไม่เคยตรวจจับในรอบนี้
    digitalWrite(eled , HIGH);
    objectCount++; // เพิ่มจำนวนวัตถุที่นับ
    Serial.println("Object detected: " + String(objectCount)); // แสดงจำนวนวัตถุที่ตรวจจับได้
    objectDetected = true; // ตั้งค่าสถานะเป็นตรวจจับวัตถุแล้ว
  } else if (sensorValue == HIGH && objectDetected) { // ถ้าเซ็นเซอร์ไม่ตรวจจับวัตถุและเคยตรวจจับในรอบนี้
    objectDetected = false; // รีเซ็ตสถานะการตรวจจับวัตถุ
    digitalWrite(eled , LOW);
  }

  delay(10); // หน่วงเวลาการอ่านค่าเซ็นเซอร์เล็กน้อยเพื่อเพิ่มความเสถียร
}
