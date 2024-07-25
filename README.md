## Standard Extended C++ Library

## 🎯 Purpose of this project
This project is made more for fun and for the community than for use in real production.
Here you can find useful functionality and use it in your projects.
Contributors are also very welcome!

## 🖥 Supported OS
- [X] Linux
- [ ] Windows (not verified)

## 📜 Supported Compilers
- clang++ (verified on 18.1.8)
- g++ (verified on 13.1.0)

## ⚙️ Tech Stack
- C++ >= 20
- CMake >= 3.14

## 🛠 Build
Build options:
```
-DCMAKE_BUILD_TYPE -> Debug, Release, RelWithDebInfo, MinSizeRel
-DBUILD_STATIC=ON -> static library build is enabled 
-DBUILD_STATIC=OFF -> static library build is disabled, dynamic library building is enabled 
```
How to build:
```bash
git clone https://github.com/TBF-L/standard-extended-cpp-lib
cd standard-extended-cpp-lib
mkdir build && cd build 
cmake -G Ninja -DBUILD_STATIC=ON -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Debug ..
ninja -j4 
```

## 📄 Docs
Click [here](https://tbf-l.github.io/standard-extended-cpp-lib/html/index.html).