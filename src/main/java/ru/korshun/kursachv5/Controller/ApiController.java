package ru.korshun.kursachv5.Controller;

import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import ru.korshun.kursachv5.Service.CoordinateProcessorService;
import ru.korshun.kursachv5.Service.PolynomialService;

@RestController
public class ApiController {

    private final CoordinateProcessorService processorService = new CoordinateProcessorService();

    @CrossOrigin(origins = "*")
    @PostMapping("/send_points")
    public String getPoints(@RequestBody String json) {

        float[] coefficients = processorService.processPoints(json);

        return PolynomialService.convertToLaTeX(coefficients);
    }
}
