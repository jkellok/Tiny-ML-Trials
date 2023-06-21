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