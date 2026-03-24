# ESP-Flasher

**Darsh Gajare – EE25BTECH11020 | Nishid Khandagre – EE25BTECH11043**

---

## Chapter 1: Upload Code to Arduino via ESP32

> Replace `YOUR_SSID`, `YOUR_PASSWORD` with your network credentials.  
> Replace `ESP_IP` with your ESP32's IP address (e.g. `192.168.43.100`).

### Create project

```bash
mkdir arduino_code && cd arduino_code
pio init --board uno
nvim src/main.cpp
```

### Build and upload

```bash
cd arduino_code
pio run --target upload
```

---

## Chapter 2: ESP32-to-ESP32 OTA

> Connect phone to WiFi: `ESP32-OTA-Net` | Password: `12345678`

### Verify both boards

```bash
curl http://192.168.4.1/status
curl http://192.168.4.2:8080/status
```

### Step 1 — Compile

```bash
pio run
```

### Step 2 — Upload binary to ESP32 #1

```bash
curl -F "firmware=@.pio/build/esp2/firmware.bin" http://192.168.4.1/upload
curl http://192.168.4.1/status
```

### Step 3 — Trigger OTA push

```bash
curl http://192.168.4.1/trigger
```

### Step 4 — Verify ESP32 #2

```bash
curl http://192.168.4.2:8080/status
```
