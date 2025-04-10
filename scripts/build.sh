#!/bin/bash

# Exit immediately if any command fails
set -e

echo "🔧 Step 1: Building React UI..."
cd ../ui

# Install dependencies if node_modules doesn't exist
if [ ! -d "node_modules" ]; then
  echo "📦 Installing npm dependencies..."
  npm install
fi

echo "🏗️  Building React app..."
npm run build

echo "📦 Step 2: Generating Qt resource file..."
cd ..
python3 generate_qrc.py

echo "🛠️ Step 3: Building C++ app with CMake..."
mkdir -p build
cd build
cmake ..
cmake --build .

echo "✅ Build complete. Run the app with:"
echo "./QtWebEngineExample"
