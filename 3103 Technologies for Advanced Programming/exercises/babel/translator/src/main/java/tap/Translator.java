/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements. See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package tap;

import org.apache.kafka.common.serialization.Deserializer;
import org.apache.kafka.common.serialization.Serde;
import org.apache.kafka.common.serialization.Serdes;
import org.apache.kafka.common.serialization.Serializer;
import org.apache.kafka.common.utils.Bytes;
import org.apache.kafka.streams.KafkaStreams;
import org.apache.kafka.streams.StreamsBuilder;
import org.apache.kafka.streams.StreamsConfig;
import org.apache.kafka.streams.Topology;
import org.apache.kafka.streams.kstream.Consumed;
import org.apache.kafka.streams.kstream.KeyValueMapper;
import org.apache.kafka.streams.kstream.Materialized;
import org.apache.kafka.streams.kstream.Produced;
import org.apache.kafka.streams.kstream.ValueMapper;
import org.apache.kafka.streams.state.KeyValueStore;

import java.util.stream.IntStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;
import java.util.Locale;
import java.util.Properties;
import java.util.concurrent.CountDownLatch;

import tap.Message;
import tap.JsonPOJOSerializer;
import tap.JsonPOJODeserializer;
import tap.ITranslator;

class FarfallinoTranslator implements ITranslator {
    public String translate(String s) {
        return s
            .replaceAll("a", "afa")
            .replaceAll("e", "efe")
            .replaceAll("i", "ifi")
            .replaceAll("o", "ofo")
            .replaceAll("u", "ufu");
    }
}

class SpongebobTranslator implements ITranslator {
    public String translate(String s) {
        StringBuilder result = new StringBuilder();
        
        // Use IntStream to process each character with its index
        IntStream.range(0, s.length())
            .forEach(i -> {
                char currentChar = s.charAt(i);
                
                // If the character is a letter, alternate between upper and lower case based on index
                if (Character.isLetter(currentChar)) {
                    if (i % 2 == 0) { // Even index (0, 2, 4, ...)
                        result.append(Character.toLowerCase(currentChar));
                    } else { // Odd index (1, 3, 5, ...)
                        result.append(Character.toUpperCase(currentChar));
                    }
                } else {
                    // Non-letter characters remain unchanged
                    result.append(currentChar);
                }
            });
        
        return result.toString();
    }
}

class CopyTranslator implements ITranslator {
    public String translate(String s) {
        return s.toLowerCase(Locale.getDefault());
    }
}

public class Translator {

    public static void main(String[] args) {
        Properties props = new Properties();
        props.put(StreamsConfig.APPLICATION_ID_CONFIG, "babel-translator");
        props.put(StreamsConfig.BOOTSTRAP_SERVERS_CONFIG, "kafkaServer:9092");
        
        Map<String, Object> serdeProps = new HashMap<>();
        final Serializer<Message> messageSerializer = new JsonPOJOSerializer<>();
        serdeProps.put("JsonPOJOClass", Message.class);
        messageSerializer.configure(serdeProps, false);
        final Deserializer<Message> messageDeserializer = new JsonPOJODeserializer<>();
        serdeProps.put("JsonPOJOClass", Message.class);
        messageDeserializer.configure(serdeProps, false);
        final Serde<Message> messageSerde = Serdes.serdeFrom(messageSerializer, messageDeserializer);

        final StreamsBuilder builder = new StreamsBuilder();

        builder.<String, Message>stream("babel-input", Consumed.with(Serdes.String(), messageSerde))
               .mapValues((key, msg) -> {

                   ITranslator translator;
                   if (key.equals("farfallino")) translator = new FarfallinoTranslator();
                   else if (key.equals("spongebob")) translator = new SpongebobTranslator();
                   else translator = new CopyTranslator();

                    Message newMessage = new Message();
                    newMessage.setAuthor(msg.getAuthor());
                    newMessage.setMessage(translator.translate(msg.getMessage()));
                    return newMessage;
               })
               .to("babel-output", Produced.with(Serdes.String(), messageSerde));

        final Topology topology = builder.build();
        final KafkaStreams streams = new KafkaStreams(topology, props);
        final CountDownLatch latch = new CountDownLatch(1);

        // attach shutdown handler to catch control-c
        Runtime.getRuntime().addShutdownHook(new Thread("streams-shutdown-hook") {
            @Override
            public void run() {
                streams.close();
                latch.countDown();
            }
        });

        try {
            streams.start();
            latch.await();
        } catch (Throwable e) {
            System.exit(1);
        }
        System.exit(0);
    }
}
