# Babel

1. Fluentd: a HTTP server listens for new messages and it writes them to the Kafka topic `babel_input`. The expected input is a JSON with the following fields:
	- "message": contains the plain text message
	- "author": contains the author's name
	- "lang": contains the algorithm name
2. Kafka (`babel_input`): topic containing the messages to be translated. The key is the lang and the value is the JSON (excluding the lang field).
3. Kafka Streams: based on the key, it translates the messages and it write them to the Kafka topic `babel_output`. The currently available algorithms are `farfallino` and `spongebob`.
4. Kafka (`babel_output`): topic containing the translated messages. Same format as `babel_input`.
5. Logstash: listens for new messages from babel_output and logs them in a file with the following format: `<author>: <message>`

---

To send messages to Fluentd:
- `curl -d 'json={"message": "Tanti auguri, Kevin!", "author": "Matteo", "lang": "farfallino"}' "http://127.0.0.1:9880/"`
- `curl -d 'json={"message": "Grazie", "author": "Kevin", "lang": "farfallino"}' "http://127.0.0.1:9880/"`

To subscribe to `babel_input`: `docker exec -it kafkaServer /opt/kafka/bin/kafka-console-consumer.sh --topic babel-input --bootstrap-server http://127.0.0.1:9092 --property print.key=true`

To subscribe to `babel_output`: `docker exec -it kafkaServer /opt/kafka/bin/kafka-console-consumer.sh --topic babel-output --bootstrap-server http://127.0.0.1:9092 --property print.key=true`

