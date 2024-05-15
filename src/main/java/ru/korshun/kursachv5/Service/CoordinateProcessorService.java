package ru.korshun.kursachv5.Service;

import java.util.Arrays;
import org.json.JSONObject;

import ru.korshun.kursachv5.JNI.CoordinateProcessorJNI;


public class CoordinateProcessorService {
    public float[] processPoints(String json) {
        try {
            double[] points = Arrays.stream(new JSONObject(json).getJSONArray("shapes").getJSONObject(0)
                            .getString("path").replaceAll("M", "").split("[L,]"))
                    .mapToDouble(Double::parseDouble).toArray();

            int numPoints = points.length;
            float[] inputArray = new float[numPoints];
            for (int i = 0; i < numPoints; i++) {
                inputArray[i] = (float) points[i];
            }

            CoordinateProcessorJNI processorJNI = new CoordinateProcessorJNI();
            return processorJNI.processCoordinates(inputArray);
        } catch (Exception e) {
            e.printStackTrace();
            return new float[0];
        }
    }
}
