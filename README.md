# Integrated-Injury-Prediction-System-using-IoT-and-Machine-Learning
An advanced injury prediction system that enhances workplace safety by using wearable IoT sensors to monitor real-time data and employing machine learning to detect and prevent potential injuries before they occur.




Key Features
Feature	Description
📈 Real-Time Monitoring	Continuously monitors physiological and environmental data
🧠 ML-Based Prediction	Uses machine learning to detect early signs of potential injuries
🌐 IoT Integration	Wearable sensors stream data to a central edge/cloud system
🚨 Smart Alerts	Notifies workers or supervisors of risky conditions
🔋 Low Power Design	Optimized for battery-powered wearable deployment

🔧 Hardware Components & Pinouts
Component	Module/Device	Pin Connections (ESP32 Example)	Purpose
Heart Rate Sensor	MAX30100/MAX30102	SDA - GPIO21, SCL - GPIO22	Heart rate & SpO2 monitoring
Motion Sensor	MPU6050	SDA - GPIO21, SCL - GPIO22	Fall detection, lack of motion
Environmental Sensor	DHT11/DHT22 or BME280	GPIO4 (DHT), I2C (BME280)	Temperature, humidity, pressure
Vibration Sensor	SW-420	GPIO32	Detects abnormal body vibration
Buzzer	Passive Buzzer	GPIO26	Alert signal output
OLED Display (Optional)	SSD1306	SDA - GPIO21, SCL - GPIO22	Real-time display of data
Wi-Fi Module	ESP32 Built-in	--	Cloud/Data server communication

📝 Use I2C pull-up resistors (4.7kΩ) if needed for reliable communication.

🧠 AI Model Overview
Model Type	Algorithm Used	Input Features	Output
Injury Classifier	Random Forest / SVM	HR, motion data, temp, humidity, vibration, time	Injury Risk (Low / Med / High)

📊 Data Pipeline
Stage	Description	Output
Data Collection	Real-time sensor data via ESP32	JSON data packets
Preprocessing	Clean data, remove outliers, normalize	Formatted input for model
Feature Extraction	Mean HR, motion index, environment delta, vibration count	Feature vector
Model Inference	Trained model classifies input	Risk level prediction
Notification	Sends alert if medium/high risk detected	Buzzer, App, or Cloud Notification



🔁 Model Inputs & Outputs
Input Parameter	Source	Range/Unit
Heart Rate (HR)	MAX30100/MAX30102	bpm
Body Motion Index	MPU6050	numeric threshold
Temperature	DHT/BME280	°C
Humidity	DHT/BME280	% RH
Vibration Detected	SW-420	Binary (0/1)
Time Duration	Timer	Seconds

Output	Description
0	Low Injury Risk
1	Medium Risk – Trigger Warning
2	High Risk – Alert & Notify
