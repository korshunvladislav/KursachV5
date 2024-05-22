package ru.korshun.kursachv5.Service;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONObject;


public class CoordinateProcessorService {
    public float[] processPoints(String json) {
        try {
            JSONObject jsonObject = new JSONObject(json);
            JSONObject dataObject = jsonObject.getJSONObject("data");
            JSONArray shapesArray = dataObject.getJSONArray("shapes");
            String selectedFunction = dataObject.getString("selectedFunction");

            List<Double> pointsList = new ArrayList<>();
            if (shapesArray.length() > 0) {
                String path = shapesArray.getJSONObject(0).getString("path");

                double[] points = Arrays.stream(path.replaceAll("M", "")
                        .split("[L,]")).mapToDouble(Double::parseDouble).toArray();

                for (double point : points) {
                    pointsList.add(point);
                }
            }

            List<Double> interpolatedPoints = interpolatePoints(pointsList, 0.25);

            int numPoints = interpolatedPoints.size();
            float[] inputArray = new float[numPoints];

            for (int i = 0; i < numPoints; i++) {
                inputArray[i] = interpolatedPoints.get(i).floatValue();
            }

            PointsService writer = new PointsService();
            String inputFilename = "input.txt";
            String outputFilename = "output.txt";

            try {
                writer.writePointsToFile(inputArray, selectedFunction, inputFilename);

                Process process = Runtime.getRuntime().exec("./cpp/a.out");
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

    private List<Double> interpolatePoints(List<Double> points, double step) {
        List<Double> interpolatedPoints = new ArrayList<>();

        for (int i = 0; i < points.size() - 2; i += 2) {
            double x1 = points.get(i);
            double y1 = points.get(i + 1);
            double x2 = points.get(i + 2);
            double y2 = points.get(i + 3);

            interpolatedPoints.add(x1);
            interpolatedPoints.add(y1);

            for (double x = x1 + step; x < x2; x += step) {
                double t = (x - x1) / (x2 - x1);
                double y = y1 + t * (y2 -y1);
                interpolatedPoints.add(x);
                interpolatedPoints.add(y);
            }
        }

        interpolatedPoints.add(points.get(points.size() - 2));
        interpolatedPoints.add(points.get(points.size() - 1));

        return interpolatedPoints;
    }
}
