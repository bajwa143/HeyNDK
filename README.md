
## HeyNDK  
This project use `ndk-build` tool to build NDK project. For creating project using cmake see [HelloNDK](https://github.com/bajwa143/HelloNDK)  repo.
First of all, to include ndk-build projects in your Gradle build, you need to use **Android Studio 2.2** and higher with Android plugin for **Gradle 2.2.0 and higher**.  
Below are some steps we need to perform for making project using `ndk-build`:
1. Create a simple default Java project in Android Studio.
2. After project successfully created, make a folder named **jni** in project root directory.
3. In this folder create two files named **`Android.mk`** (*The `Android.mk` file resides in a subdirectory of your project's `jni/` directory, and describes your sources and shared libraries to the build system*) and **`Application.mk`** (*The `Application.mk` specifies project-wide settings for ndk-build. By default, it is located at `jni/Application.mk`, in your application's project directory*) also. `Android.mk` and `Application.mk` build files are used by `ndk-build` to make project.

> Detail about commands used in both project is commented in these two
> files of this project.
4. Add C/C++ file which must include jni.h header file.
5. Then in module level `build.gradle` file add **externalNativeBuild** configuration block in `android{}` configuration block.
6. In Next step provide relative path in externalNativeBuild configuration block as  

 <pre>
externalNativeBuild {  
    ndkBuild {  
        // Specifies the relative path to your `Android.mk` build script
        path "../jni/Android.mk"  
        }   
	}   
  </pre>
7. Now at this stage compiling project will result in changing project from normal java project to Android NDK project.