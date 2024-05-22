FROM maven:3.8.5-openjdk-17-slim AS build

WORKDIR /app

COPY pom.xml .
RUN mvn dependency:go-offline

COPY src ./src
RUN mvn clean package -DskipTests

COPY cpp/Approximation.cpp ./Approximation.cpp
RUN apt-get update && apt-get install -y g++
RUN g++ -o a.out Approximation.cpp

FROM openjdk:17-jdk-slim

WORKDIR /app

COPY --from=build /app/target/KursachV5-0.0.1-SNAPSHOT.jar ./app.jar

COPY --from=build /app/a.out ./a.out

EXPOSE 8080

ENTRYPOINT ["java", "-jar", "/app/app.jar"]