#include<jni.h>
#include <string.h>

extern "C" JNIEXPORT jstring JNICALL

Java_com_heyndk_MainActivity_getMessage(JNIEnv *env, jobject obj) {

    const char *message = "hello from cpp language";
    // Now in C++ file, we don't need (*env)->, but we can simplify it as
    return env->NewStringUTF(message);
}
