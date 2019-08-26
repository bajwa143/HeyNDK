## HeyNDK  
  
This project use `ndk-build` tool to build NDK project. For creating project using cmake see [HelloNDK](https://github.com/bajwa143/HelloNDK)  repo.      
First of all, to include ndk-build projects in your Gradle build, you need to use **Android Studio 2.2** and higher with Android plugin for **Gradle 2.2.0 and higher**.        
Below are some steps we need to perform for making project using `ndk-build`:      
1. Create a simple default Java project in Android Studio.      
2. After project successfully created, make a folder named **jni** in project root directory.      
3. In this folder create two files named **`Android.mk`** (*The `Android.mk` file resides in a subdirectory of your project's `jni/` directory, and describes your sources and shared libraries to the build system*) and **`Application.mk`** (*The `Application.mk` specifies project-wide settings for ndk-build. By default, it is located at `jni/Application.mk`, in your application's project directory*) also. `Android.mk` and `Application.mk` build files are used by `ndk-build` to make project.      
      
> Detail about commands used in both project is commented in these two > files of this project. 4. Add C/C++ file which must include jni.h header file.  Method signature  defined in native C/C++ code must match to the JNI naming convention for the C function is Java_{package_and_classname}_{function_name}(JNI_arguments) // The dot in package name is replaced by underscore    
5. Then in module level `build.gradle` file add **externalNativeBuild** configuration block in `android{}` configuration block.      
6. In Next step provide relative path in externalNativeBuild configuration block as
  
```  
android{    
......    
externalNativeBuild {  
 ndkBuild {  
           // Specifies the relative path to your `Android.mk` build script               
           path "../jni/Android.mk"  
        }           
   }
            
  ```  

7. Now at this stage compiling project will result in changing project from normal java project to Android NDK project.    
8. Run the project :+1:     

---

### Adding C++ files
    
We can use C++ to implement native methods. However, we must      
then declare the functions that implement the native methods as extern "C". (This stops the C++ compiler from “mangling” the method name.) For example,      
``` cpp
extern "C"      
JNIEXPORT jstring JNICALL  
	Java_com_heyndk_MainActivity_getMessage(JNIEnv *env, jobject obj) {        
          const char *message = "hello from cpp language";   
          return env->NewStringUTF(message);  
}  

```

Missing extern "C" in code will give following error    
 
```
java.lang.UnsatisfiedLinkError: No implementation found for java.lang.String com.heyndk.MainActivity.getMessage() (tried Java_com_heyndk_MainActivity_getMessage and Java_com_heyndk_MainActivity_getMessage__)
```
There  are a few advantages of using C++ over C, type checking is slightly stricter, and accessing the JNI functions is a bit more convenient. However, JNI does not support any mapping between Java and C++ classes