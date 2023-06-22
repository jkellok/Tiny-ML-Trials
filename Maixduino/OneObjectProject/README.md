# Object Detection and Image Classification From Scratch

## Prerequisites
- Images of the object
	- for classification, you need images without the object or another object (here: bottle vs no bottle)
	- the more images, the better, but preparing data can take a lot of time
- Image annotation tool for object detection (or use Maixhub)
- Training in Maixhub or with Tensorflow Keras + conversion with nncase
- For Maixduino: minimum firmware (with IDE support)

## Instruction video
![detection instructions video](ObjectDetection/demo/object_detection_instructions.mp4)

Here is a simple video of the steps taken. The video is about object detection. For image classification annotations are not needed. The file explorer was not screen captured in some parts of the video.

## Tools used
- Maixhub: https://maixhub.com/home
- VoTT: https://github.com/microsoft/VoTT
- MaixPy firmware: https://dl.sipeed.com/MAIX/MaixPy/release/master/
- MaixPy IDE: https://wiki.sipeed.com/soft/maixpy/en/get_started/env_maixpyide.html
- kflash_gui: https://github.com/sipeed/kflash_gui
- (nncase kmodel converter: https://github.com/kendryte/nncase)

## How it works
Object Detection classifies an object and also locates it in the image. It can be used to count objects or keep track of their locations. For example it can be used for face detection, video surveillance and anomaly detection. Image classification labels an image but does not locate or count the object.

Object detection model has an encoder that takes an image as an input and runs it through layers that learn to extract statistical features, which are used to locate and label objects. Outputs are passed to a decoder, which will predict the labels and bounding boxes for each object.

KPU uses YOLO V2 object detection. YOLO (You Only Look Once) is a real-time object detection system. A single neural network is applied to the image. The network divides the image into regions and it will predict bounding boxes and their probabilities for each region. The bounding boxes are weighted by the predicted possibilities. Since it only uses a single network evaluation, it is a lot faster than other systems. It's a good choice for mobile and embedded devices.

## Links
Deep Neural Network: https://wiki.sipeed.com/soft/maixpy/en/course/ai/basic/dnn_basic.html
About kmodel and KPU: https://wiki.sipeed.com/soft/maixpy/en/course/ai/basic/maixpy_hardware_ai_basic.html
Object Detection with aXelerate: https://www.hackster.io/dmitrywat/object-detection-with-sipeed-maix-boards-kendryte-k210-421d55
Object Detection with 20 classes model: https://www.edgemicrotech.com/maixpy-9-maixduino-object-detection-ai-micropython/

### Further reading

ANN (Artificial Neural Network): https://heartbeat.comet.ml/introduction-to-deep-learning-with-keras-c7c3d14e1527
CNN (Convolutional Neural Network): https://heartbeat.comet.ml/a-beginners-guide-to-convolutional-neural-networks-cnn-cf26c5ee17ed
Object detection: https://www.fritz.ai/object-detection/
Yolo: https://pjreddie.com/darknet/yolo/
Tensorflow (image classification): https://www.tensorflow.org/hub/tutorials/image_feature_vector
Keras: https://keras.io/getting_started/intro_to_keras_for_engineers/