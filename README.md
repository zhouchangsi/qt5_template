## 如何启动项目

**需要安装以下软件**
- Qt5.12.12
- CMake

**设置Qt5_DIR环境变量，指向Qt5的安装目录下的lib/cmake/Qt5目录，例如：**

```bat
# 假设Qt安装目录为 C:\Qt\Qt5.12.0\5.12.0, 设置Qt5_DIR环境变量：
# 64位的Qt5
set Qt5_DIR=C:\Qt\Qt5.12.0\5.12.0\msvc2017_64\lib\cmake\Qt5
# 32位的Qt5
set Qt5_DIR=C:\Qt\Qt5.12.0\5.12.0\msvc2017\lib\cmake\Qt5

# 设置成功后通过下面的命令查看Qt5_DIR的值
echo %Qt5_DIR%
# 或者(powershell)
$env:Qt5_DIR
```

**执行以下命令，生成项目**

```bat
# 生成项目
cmake -B build `
-DQt5_DIR=C:/apps/QT/5.14.2/msvc2017_64/lib/cmake/Qt5 `
-DCMAKE_TOOLCHAIN_FILE=C:/apps/vcpkg/scripts/buildsystems/vcpkg.cmake `
-DCMAKE_EXPORT_COMPILE_COMMANDS=ON `
-DCMAKE_C_COMPILER=clang `
-DCMAKE_CXX_COMPILER=clang `
-G Ninja `
--fresh 

# build
cmake --build build --target install

```
exe 文件在build/bin目录下