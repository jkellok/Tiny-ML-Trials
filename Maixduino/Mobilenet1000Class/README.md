# 1000 Object Classification

Used Mobilenet model that recognises 1000 objects, in Maixduino.

Some instructions from here: https://wiki.sipeed.com/soft/maixpy/en/course/ai/image/1000_type_classifier.html

Because the model is big (~4MB), you have to use minimum firmware (~700kB). Firmware from: https://dl.sipeed.com/shareURL/MAIX/MaixPy/release/master/maixpy_v0.6.2_84_g8fcd84a58

SD card was formatted to FAT16. Model file mobilenet_0x300000.kfpkg was downloaded and extracted. The m.kmodel and labels.txt was placed in the SD card. SD card was placed in the Maixduino board.

UPyLoader was used to transfer the .py file to Maixduino. If you don't have an SD card, you can use kflash to flash the kmodel to 0x300000 and use UPyLoader to transfer labels.txt to board also.

The terminal was opened and the next code was run to reduce GC heap size. Otherwise there would not be enough memory.

```
from Maix import utils
import machine

utils.gc_heap_size(256*1024)
machine.reset()
```

Then the .py file was executed to run the script.
