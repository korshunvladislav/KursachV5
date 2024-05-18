package ru.korshun.kursachv5.Service;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class PointsService {

    public void writePointsToFile(float[] points, String selectedFunction, String filename) throws IllegalArgumentException, IOException {
        if (points.length % 2 != 0) {
            throw new IllegalArgumentException("Размер массива должен быть чётным числом.");
        }

        try (FileWriter writer = new FileWriter(filename)) {
            writer.write(selectedFunction + System.lineSeparator());
            for (int i = 0; i < points.length; i += 2) {
                writer.write(points[i] + " " + points[i + 1] + System.lineSeparator());
            }
        }
    }

    public float[] readResultFromFile(String filename) throws IOException {
        StringBuilder result = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                result.append(line);
            }
        }

        String[] resultStrings = result.toString().trim().split("\\s+");
        float[] resultFloats = new float[resultStrings.length];
        for (int i = 0; i < resultStrings.length; i++) {
            resultFloats[i] = Float.parseFloat(resultStrings[i]);
        }

        return resultFloats;
    }

}
