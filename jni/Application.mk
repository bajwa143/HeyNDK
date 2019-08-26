# The Application.mk specifies project-wide settings for ndk-build. By default, it is located at jni/Application.mk, in your application's project directory

# By default, the NDK build system generates code for all non-deprecated ABIs. You can use the APP_ABI setting to generate code for specific ABIs
APP_ABI := all  # All supported ABIs (default)