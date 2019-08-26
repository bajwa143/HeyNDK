# The Android.mk file resides in a subdirectory of your project's jni/ directory, and describes your sources and shared libraries to the build system
# An Android.mk file must begin by defining the LOCAL_PATH variable
LOCAL_PATH := $(call my-dir)
# This variable indicates the location of the source files in the development tree. Here, the macro function my-dir, provided by the build system, returns the path of the current directory (the directory containing the Android.mk file itself).

# The next line declares the CLEAR_VARS variable, whose value the build system provides.
include $(CLEAR_VARS)
# The CLEAR_VARS variable points to a special GNU Makefile that clears many LOCAL_XXX variables for you, such as LOCAL_MODULE, LOCAL_SRC_FILES, and LOCAL_STATIC_LIBRARIES. Note that it does not clear LOCAL_PATH. This variable must retain its value because the system parses all build control files in a single GNU Make execution context where all variables are global. You must (re-)declare this variable before describing each module.

# Next, the LOCAL_MODULE variable stores the name of the module that you wish to build. Use this variable once per module in your application.
LOCAL_MODULE := hey-ndk
# Each module name must be unique and not contain any spaces. The build system, when it generates the final shared-library file, automatically adds the proper prefix and suffix to the name that you assign to LOCAL_MODULE. For example, the example that appears above results in generation of a library called libhey-ndk.so.

# The next line enumerates the source files, with spaces delimiting multiple files:
LOCAL_SRC_FILES := hello.c hellocpp.cpp
# The LOCAL_SRC_FILES variable must contain a list of C and/or C++ source files to build into a module.

# The last line helps the system tie everything together:
include $(BUILD_SHARED_LIBRARY)
# The BUILD_SHARED_LIBRARY variable points to a GNU Makefile script that collects all the information you defined in LOCAL_XXX variables since the most recent include. This script determines what to build, and how to do it.
