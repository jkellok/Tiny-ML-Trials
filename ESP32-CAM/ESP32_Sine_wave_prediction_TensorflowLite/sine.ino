// replace with your actual file
#include "convert.h"

void setup() {
    Serial.begin(115200);

    while (!sineNN.begin()) {
        Serial.print("Error in NN initialization: ");
        Serial.println(sineNN.getErrorMessage());
    }
}

void loop() {
    for (int i = 0; i < 20; i++) {
        // pick x from 0 to PI
        float x = 3.14f * i / 20.0f;
        // even if the input vector is made of a single value
        // you ALWAYS need to create an array
        float input[1] = { x };

        float y_true = sin(x);
        // to run the network, call `predict()`
        float y_pred = sineNN.predict(input);

        Serial.print("sin(");
        Serial.print(x);
        Serial.print(") = ");
        Serial.print(y_true);
        Serial.print("\t predicted: ");
        Serial.println(y_pred);
        delay(1000);
    }
}
