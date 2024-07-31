# Android OpenCL example
This example shows how to use OpenCL inside android environment.

## Explanation

1. Your `AndroidManifest.xml` should contain this entry:
```xml
<uses-native-library
    android:name="libOpenCL.so"
    android:required="false"/>
```
2. Use [libopencl-stub](https://github.com/krrishnarraj/libopencl-stub.git).
This will find OpenCL library and load it. Also this great repository provides
us all required headers. Check `CMakeLists.txt` to understand how to use it 
in your project.

That's it.
