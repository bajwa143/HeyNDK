#include<jni.h>

/*
About JNIEXPORT and JNICALL
 Source: https://stackoverflow.com/questions/19422660/when-to-use-jniexport-and-jnicall-in-android-ndk

 JNIEXPORT is used to make native functions appear in the dynamic table of the built binary (*.so file). They can be set to "hidden" or "default" (more info here). If these functions are not in the dynamic table, JNI will not be able to find the functions to call them so the RegisterNatives call will fail at runtime.
 It is worth noting that all functions end up in the dynamic table by default, so anyone could decompile your native code quite easily. Every function call is built into the binary just in case JNI needs to find it. This can be changed using the compiler option -fvisibility. I would recommend everyone sets this to -fvisibility=hidden to keep your code secure, and then use JNIEXPORT to flag functions as having external visibility.
 Using the strip command just removes the debug symbols, the dynamic table is separate. Have a play with objdump to see how much a person could get out of your .so files.

 You can find the definition of those macros in the machine-dependent portion of your JNI includes (usually in $JAVA_HOME/include/<arch>/jni-md.h).
 In short, JNIEXPORT contains any compiler directives required to ensure that the given function is exported properly. On android (and other linux-based systems), that'll be empty.
 JNICALL contains any compiler directives required to ensure that the given function is treated with the proper calling convention. Probably empty on android as well (it's __stdcall on w32).

 JNICALL is not empty on some architectures on Android. JNICALL should always be used. JNIEXPORT should be used if you aren't using registerNatives family of functions

 JNIEXPORT ensures function is visible in the symbols table. JNICALL ensures function uses the correct calling convention. On Android JNICALL has a different value based on architecture. ARM is empty which might trick you to not include it. But you must use JNICALL.
 registerNatives allows you to link the function up programatically on JNI_onLoad or sometime in the future too. registerNatives allows for catching wrong function names earlier and I recommend this route.
 */

/*
 * The macros JNIEXPORT and JNICALL are defined in the header file jni.h. They
 * denote compiler-dependent specifiers for exported functions that come from
 * a dynamically loaded library
 */

/*
jstring JNICALL
Java_com_heyndk_MainActivity_getMessage(JNIEnv *env, jobject obj) {

    const char *message = "hello from c language";
    return (*env)->NewStringUTF(env, message);
}
*/
