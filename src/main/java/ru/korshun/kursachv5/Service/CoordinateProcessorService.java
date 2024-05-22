package ru.korshun.kursachv5.Service;

import java.io.File;
import java.io.IOException;
import java.util.Arrays;

import org.json.JSONArray;
import org.json.JSONObject;


public class CoordinateProcessorService {
    public float[] processPoints(String json) {
        try {
            JSONObject jsonObject = new JSONObject(json);
            JSONObject dataObject = jsonObject.getJSONObject("data");
            JSONArray shapesArray = dataObject.getJSONArray("shapes");
            String selectedFunction = dataObject.getString("selectedFunction");

            double[] points = new double[0];
            if (shapesArray.length() > 0) {
                String path = shapesArray.getJSONObject(0).getString("path");

                points = Arrays.stream(path.replaceAll("M", "")
                        .split("[L,]")).mapToDouble(Double::parseDouble).toArray();

            }

            int numPoints = points.length;

            float[] inputArray = new float[numPoints];

            for (int i = 0; i < numPoints; i++) {
                inputArray[i] = (float) points[i];
            }

            PointsService writer = new PointsService();
            String inputFilename = "input.txt";
            String outputFilename = "output.txt";

            try {
                writer.writePointsToFile(inputArray, selectedFunction, inputFilename);

                Process process = Runtime.getRuntime().exec("./a.out");
                process.waitFor();

                float[] result = writer.readResultFromFile(outputFilename);

                new File(inputFilename).delete();
                new File(outputFilename).delete();

                return result;
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
                return new float[0];
            }

        } catch (Exception e) {
            e.printStackTrace();
            return new float[0];
        }
    }
}
