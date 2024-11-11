# Creating first container to compile Java code and create jar file
FROM maven:3-openjdk-8 AS build
WORKDIR /app

# Copying pom.xml file to container
COPY pom.xml .

# Downloading dependencies
RUN mvn -f ./pom.xml clean package

COPY src src

RUN mvn -f ./pom.xml package
FROM openjdk:8-slim
ENV BUILD="kafka-streams.examples-0.1-jar-with-dependencies.jar"
WORKDIR /app
COPY --from=build /app/target/${BUILD} app.jar  
# ENTRYPOINT java -cp /app/app.jar
CMD echo Usage: java -cp /app/app.jar
#java -cp target/kafka-streams.examples-0.1-jar-with-dependencies.jar tap.Pipe
#CMD ls
