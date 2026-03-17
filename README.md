# Wireless Arduino Programming via ESP32

**Phone (Termux + Debian) → ESP32 (WiFi) → Arduino UNO**  
**Course:** Scientific Programming

---

> Replace `YOUR_SSID` and `YOUR_PASSWORD` with SSID and Password of the network your phone is on
> Replace `ESP_IP` with your ESP32's IP address.

---
## After compiling code on ESP-32
## 1. Create Project

```bash
mkdir ~/arduino_code && cd ~/arduino_code
pio init --board uno
nano src/main.cpp   # write your sketch
```

---

## 2. Build and Upload

```bash
pio run --target upload
```

With 100µF capacitor on RST button press needed.

---



