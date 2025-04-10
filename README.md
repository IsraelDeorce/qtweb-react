# Qt + React UI Integration Example

This is a simple app demonstrating how to set up a `QWebChannel` flow—making a C++ object available for use inside a React-based UI.

---

## 🧩 Dependencies

### Qt (for the C++ application)

To build and run the C++ portion of this app, you'll need the Qt libraries installed on your system.

Install the required packages:

```bash
sudo apt update
sudo apt install qtbase5-dev qtwebengine5-dev libqt5webchannel5-dev
```

### Node.js & npm (for the React UI)

To build the React UI, you need Node.js and npm installed.

Install Node.js and npm via NodeSource (recommended):

```bash
curl -fsSL https://deb.nodesource.com/setup_20.x | sudo -E bash -
sudo apt install -y nodejs
```

> Make sure Node.js and npm were installed correctly:

```bash
node -v
npm -v
```

---

## 🛠️ Build Instructions

To build the entire application (React UI + C++ app), simply run the provided build script:

```bash
cd scripts
./build.sh
```

This script will:

1. Build the React app in the `ui/` folder  
2. Run the `generate_qrc.py` script to generate Qt resources  
3. Build the C++ application using CMake  

---

## ▶️ Running the App

After the build completes, navigate to the `build/` folder and run the application:

```bash
cd ../build
./QtWebEngineExample
```
