package ru.korshun.kursachv5.JNI;

public class CoordinateProcessorJNI {

    static {
        System.loadLibrary("CoordinateProcessorLib");
    }

    public native float[] processCoordinates(float[] inputArray);
}
