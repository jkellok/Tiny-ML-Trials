import math
import numpy as np
import tensorflow as tf
from tensorflow import keras
from everywhereml.code_generators.tensorflow import tf_porter

model = keras.models.load_model('signal_reg_model')

test_x = np.loadtxt("test_x.csv",
                 delimiter=",", dtype=np.float32)
test_y = np.loadtxt("test_y.csv",
                 delimiter=",", dtype=np.int8)

porter = tf_porter(model, test_x, test_y)
cpp_code = porter.to_cpp(instance_name='signal_R', arena_size=4096)

print(cpp_code)