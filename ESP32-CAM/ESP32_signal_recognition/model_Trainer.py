import numpy as np
import tensorflow as tf
from tensorflow import keras
from keras import layers


inputs = keras.Input(shape=(100,))
dense = layers.Dense(64, activation="relu")
x = dense(inputs)

x = layers.Dense(64, activation="relu")(x)
outputs = layers.Dense(4)(x)

model = keras.Model(inputs=inputs, outputs=outputs, name="signal_model")
print(inputs.dtype)
model.summary()


train_x = np.loadtxt("train_x.csv",
                 delimiter=",", dtype=np.float32)
val_x = np.loadtxt("val_x.csv",
                 delimiter=",", dtype=np.float32)

train_y = np.loadtxt("train_y.csv",
                 delimiter=",", dtype=np.int8)

val_y = np.loadtxt("val_y.csv",
                 delimiter=",", dtype=np.int8)


""""
print(type(test))
test = test.reshape(2, 3)
train_x = train_x.reshape(10000, 100).astype("float32") 
val_x = val_x.reshape(200, 100).astype("float32") 

train_y = train_y.reshape(10000, 100).astype("int8") 
val_y = val_y.reshape(200, 100).astype("int8") 
"""


training_padded = np.array(train_x, dtype=np.float32)
training_labels = np.array(train_y, dtype=np.int8)

val_x = np.array(val_x, dtype=np.float32)
val_y = np.array(val_y, dtype=np.int8)
#testing_padded = np.array(test_x, dtype=np.float32)
#testing_labels = np.array(yt, dtype=np.int8)


model.compile(
    loss=keras.losses.SparseCategoricalCrossentropy(from_logits=True),
    optimizer=keras.optimizers.RMSprop(),
    metrics=["accuracy"],
)

print("Fit model on training data")
history = model.fit(
    training_padded,
    training_labels,
    batch_size=100,
    epochs=100,
    # We pass some validation for
    # monitoring validation loss and metrics
    # at the end of each epoch
    validation_data=(val_x, val_y),
)

print(history.history)

model.save("signal_reg_model")

test = np.loadtxt("exa_x.csv",
                 delimiter=",", dtype=np.float32)

probability_model = tf.keras.Sequential([model, 
                                         tf.keras.layers.Softmax()])

predictions = probability_model.predict(test)

np.argmax(predictions[0])
np.argmax(predictions[1])
np.argmax(predictions[2])
np.argmax(predictions[3])
