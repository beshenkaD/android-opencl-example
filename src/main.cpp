#include <CL/opencl.hpp>

#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

extern "C" __attribute__((used)) const char *test_opencl()
{
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);

    if (platforms.empty()) {
        return "No OpenCL platforms found.";
    }

    std::stringstream ss;

    // Iterate over platforms and list devices
    for (const auto &platform : platforms) {
        ss << "Platform: " << platform.getInfo<CL_PLATFORM_NAME>() << std::endl;

        // Get devices for the current platform
        std::vector<cl::Device> devices;
        platform.getDevices(CL_DEVICE_TYPE_ALL, &devices);

        if (devices.empty()) {
            ss << "  No devices found on this platform." << std::endl;
            continue;
        }

        // List devices
        for (const auto &device : devices) {
            ss << "  Device: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
            ss << "    Type: ";
            cl_device_type deviceType = device.getInfo<CL_DEVICE_TYPE>();
            if (deviceType & CL_DEVICE_TYPE_CPU) {
                ss << "CPU ";
            }
            if (deviceType & CL_DEVICE_TYPE_GPU) {
                ss << "GPU ";
            }
            if (deviceType & CL_DEVICE_TYPE_ACCELERATOR) {
                ss << "Accelerator ";
            }
            ss << std::endl;
        }
    }

    auto result = new std::string(ss.str());
    return result->c_str();
}

extern "C" __attribute__((used)) void delete_ptr(void *ptr)
{
    delete ptr;
}
