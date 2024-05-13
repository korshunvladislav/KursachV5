package ru.korshun.kursachv5.Controller;

import org.json.JSONObject;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.Arrays;

@RestController
public class ApiController {
    @CrossOrigin(origins = "*")
    @PostMapping("/send_points")
    public String getPoints(@RequestBody String json) {
        try {
            double[] points = Arrays.stream(new JSONObject(json).getJSONArray("shapes").getJSONObject(0)
                    .getString("path").replaceAll("M", "").split("[L,]"))
                    .mapToDouble(Double::parseDouble).toArray();
            return "Количество точек: " + points.length / 2;
        } catch (Exception e) {
            return "Количество точек: 0";
        }
    }
}
