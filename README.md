# HDF5 Build/Install/Use on Windows 10 with MinGW

This repo describes our recent experience with [HDF5 library](https://www.hdfgroup.org/downloads/hdf5) for C++ on Windows 10 built with [MinGW](https://mingw-w64.org/doku.php). To make the use of HDF5 library with C/C++ more convenient, we selected the [HighFive - Header-only C++ HDF5 interface](https://github.com/BlueBrain/HighFive). 

We assume that MinGW and CMake have been installed and (bin directories) added to the PATH environment, because the their installations are GUI-based, thus quite straightforward.

## Install HDF5 library

+ Download the source code: [CMake-hdf5-1.10.5.zip](https://www.hdfgroup.org/package/cmake-hdf5-1-10-5-zip-2/?wpdmdl=13528&refresh=5cb6874e559431555466062)
+ Decompress it 
+ Goto the root directory (`CMake-hdf5-1.10.5` if you do not change the name) and then open PowerShell there tying the following commends (**DONOT TRY THEM BEFORE READING KNOWN ISSUES IN THE NEXT SECTION**):
    ```bash
    md build
    cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE:STRING=Release -DHDF5_BUILD_FORTRAN:BOOL=OFF -DHDF5_BUILD_JAVA:BOOL=OFF -DCMAKE_INSTALL_PREFIX:PATH=\path\to\install\HDF5 DHDF5_ENABLE_SZIP_SUPPORT:BOOL=OFF -DHDF5_ENABLE_Z_LIB_SUPPORT:BOOL=OFF  -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON ..\hdf5-1.10.5
    mingw32-make
    mingw32-make test
    mingw32-make install
    ```
   
   
 The following gives a summary of our test results. Unfortunately, we have 6 tests failed. In the future, we will try to find the reason(s) and fix them.
    ```bash
    99% tests passed, 8 tests failed out of 2562
    
    Total Test time (real) = 857.96 sec
    
    The following tests FAILED:
             68 - H5TEST-shared-cache_api (Failed)
             84 - H5TEST-shared-dt_arith (Failed)
            143 - H5TEST-shared-err_compat (Failed)
            145 - H5TEST-shared-error_test (Failed)
            313 - H5DIFF-h5diff_101 (Failed)
            315 - H5DIFF-h5diff_102 (Failed)
            317 - H5DIFF-h5diff_103 (Failed)
            319 - H5DIFF-h5diff_104 (Failed)
    ```
    
### Known Issues

+ [The well-known problem with empty args for variadic macros in C99](https://stackoverflow.com/questions/5588855/standard-alternative-to-gccs-va-args-trick/5589364)
    - GCC's \#\# trick: Change `__VA_ARGS__` to `##__VA_ARGS__` in `Make-hdf5-1.10.5\hdf5-1.10.5\src\H5win32defs.h`
  
## Use HDF5 library with Highfive Interface

We also provide you a sample code for using HDF5 library with Highfive Interface, the course codes for the example are copied from [HighFive](https://github.com/BlueBrain/HighFive). Although HDF5 provides cmake module for enabling `find_package` to work with it, we failed to figure out how to make it work correctly. It either finds the wrong libraries (when not providing COMPONENTS) or can not find the libraries (when providing COMPONENTS).




## Notice

If you have `visual studio` then you are highly suggested to use it. Of course, you can also download the pre-built binary to avoid the building process. 
   