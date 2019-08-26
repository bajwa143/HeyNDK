#include<jni.h>
#include <string.h>

jstring JNICALL

Java_com_heyndk_MainActivity_getMessage(JNIEnv *env, jobject obj) {

    const char *message = "hello from c language";
    return (*env)->NewStringUTF(env, message);
}
