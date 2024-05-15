package ru.korshun.kursachv5.Service;

import java.util.Locale;

public class PolynomialService {
    public static String convertToLaTeX(float[] coefficients) {
        StringBuilder sb = new StringBuilder();
        sb.append("y = ");

        boolean first = true;
        int degree = coefficients.length - 1;

        for (int i = 0; i < coefficients.length; i++) {
            float coeff = coefficients[i];
            int exp = degree - i;

            if (coeff == 0.0f) {
                continue;
            }

            if (!first && coeff > 0.0f) {
                sb.append(" + ");
            } else if (coeff < 0.0f) {
                sb.append(" - ");
                coeff = -coeff;
            }

            String formattedCoeff;
            if (coeff == (int) coeff) {
                formattedCoeff = String.format(Locale.forLanguageTag("ru"), "%d", (int) coeff);
            } else {
                formattedCoeff = String.format(Locale.forLanguageTag("ru"), "%.2f", coeff)
                        .replaceAll("\\.?0+$", "");
            }

            if (!(coeff == 1.0f && exp > 0)) {
                sb.append(formattedCoeff);
            }

            if (exp > 0) {
                sb.append("x");
                if (exp > 1) {
                    sb.append("^{" + exp + "}");
                }
            }

            first = false;
        }

        return sb.toString();
    }
}
